/*
 * $Id: hr2rxtx.c,v 1.10 Broadcom SDK $
 *
 * $Copyright: Copyright 2016 Broadcom Corporation.
 * This program is the proprietary software of Broadcom Corporation
 * and/or its licensors, and may only be used, duplicated, modified
 * or distributed pursuant to the terms and conditions of a separate,
 * written license agreement executed between you and Broadcom
 * (an "Authorized License").  Except as set forth in an Authorized
 * License, Broadcom grants no license (express or implied), right
 * to use, or waiver of any kind with respect to the Software, and
 * Broadcom expressly reserves all rights in and to the Software
 * and all intellectual property rights therein.  IF YOU HAVE
 * NO AUTHORIZED LICENSE, THEN YOU HAVE NO RIGHT TO USE THIS SOFTWARE
 * IN ANY WAY, AND SHOULD IMMEDIATELY NOTIFY BROADCOM AND DISCONTINUE
 * ALL USE OF THE SOFTWARE.  
 *  
 * Except as expressly set forth in the Authorized License,
 *  
 * 1.     This program, including its structure, sequence and organization,
 * constitutes the valuable trade secrets of Broadcom, and you shall use
 * all reasonable efforts to protect the confidentiality thereof,
 * and to use this information only in connection with your use of
 * Broadcom integrated circuit products.
 *  
 * 2.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS
 * PROVIDED "AS IS" AND WITH ALL FAULTS AND BROADCOM MAKES NO PROMISES,
 * REPRESENTATIONS OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY,
 * OR OTHERWISE, WITH RESPECT TO THE SOFTWARE.  BROADCOM SPECIFICALLY
 * DISCLAIMS ANY AND ALL IMPLIED WARRANTIES OF TITLE, MERCHANTABILITY,
 * NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF VIRUSES,
 * ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. YOU ASSUME THE ENTIRE RISK ARISING
 * OUT OF USE OR PERFORMANCE OF THE SOFTWARE.
 * 
 * 3.     TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT SHALL
 * BROADCOM OR ITS LICENSORS BE LIABLE FOR (i) CONSEQUENTIAL,
 * INCIDENTAL, SPECIAL, INDIRECT, OR EXEMPLARY DAMAGES WHATSOEVER
 * ARISING OUT OF OR IN ANY WAY RELATING TO YOUR USE OF OR INABILITY
 * TO USE THE SOFTWARE EVEN IF BROADCOM HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES; OR (ii) ANY AMOUNT IN EXCESS OF
 * THE AMOUNT ACTUALLY PAID FOR THE SOFTWARE ITSELF OR USD 1.00,
 * WHICHEVER IS GREATER. THESE LIMITATIONS SHALL APPLY NOTWITHSTANDING
 * ANY FAILURE OF ESSENTIAL PURPOSE OF ANY LIMITED REMEDY.$
 *
 */

#include "system.h"
#include "soc/bcm5333x.h"
#include "utils/net.h"

#if CFG_RXTX_SUPPORT_ENABLED
//定义发送和接收数据的debug状态
#define RXTX_DEBUG                  (0)

/* Max number of packet buffers we can accept */
//定义最多能够接收的缓存的数量
#define SOC_MAX_RX_BUF_POSTED       (1)

/* Max time for TX to be done */
//定义发送数据超时时间为500毫秒
#define TX_WAIT_TIMEOUT             (500000UL)     /* in us */

/* Time for RX error detection */
//定义接收数据检测时间间隔值为1秒
#define RX_CHECK_INTERVAL           (1000000UL)    /* in us */

/* Make use of flags for packet state */
#define RX_FLAG_STATE_MASK      (3U << 8)
#define RX_FLAG_STATE_DMA       (1U << 8)
#define RX_FLAG_STATE_RECEIVED  (3U << 8)
#define RX_PKT_RECEIVED(pkt)    \
            (((pkt)->flags & RX_FLAG_STATE_MASK) == RX_FLAG_STATE_RECEIVED)
#define RX_PKT_AVAILABLE(pkt)   \
            (((pkt)->flags & RX_FLAG_STATE_MASK) == 0)

/* TX/RX enabled */
//交换机收发初始化状态
static BOOL             rxtx_initialized;

/* RX variables */
//接收数据包相关变量
//接收数据包处理函数
static SOC_RX_HANDLER   rx_handler;
//
static BOOL             rx_handler_in_intr;
//接收数据包数组
static soc_rx_packet_t  *rx_packets[SOC_MAX_RX_BUF_POSTED];
//
static BOOL             rx_pkt_valid[SOC_MAX_RX_BUF_POSTED];
//使用DMA接收数据包
static soc_rx_packet_t  *rx_pkt_in_dma = NULL;

/* TX variables */
//发送数据的相关的变量
static soc_tx_packet_t  *tx_pkt_in_dma;
//发送数据的数据包链表
static soc_tx_packet_t  *tx_pkts_list;
//发送数据的超时时间
static tick_t           tx_timeout_ticks;
//发送数据的开始时间
static tick_t           tx_start_time;

/* Use address range 0x8000-0000~0x8FFF-FFFF to have DMA access through ACP */
#define PCI_TO_PTR(a)   ((uint32)a)
#define PTR_TO_PCI(x)   ((uint32)x)

/*
 * DMA Control Block - Type 26
 * 16 words
 */
/**定义DMA的数据结构*/
typedef struct dcb_s {
    uint32 mem_addr;  /* buffer or chain address */
    uint32 w1;
    uint32 w2;
    uint32 w3;
    uint32 w4;
    uint32 w5;
    uint32 w6;
    uint32 w7;
    uint32 w8;
    uint32 w9;
    uint32 w10;
    uint32 w11;
    uint32 w12;
    uint32 w13;
    uint32 w14;
    uint32 w15;
} dcb_t;


static dcb_t tx_dcb __attribute__ ((section(".packet_buf"), aligned (32)));
static dcb_t rx_dcb __attribute__ ((section(".packet_buf"), aligned (32)));

/* Forwards */
static void bcm5333x_rx_direct(void);
static void bcm5333x_rx_refill(void);
static void bcm5333x_rx_retrieve(soc_rx_packet_t *pkt);
static void bcm5333x_rxtx_task(void *data);
static sys_error_t bcm5333x_tx_internal(soc_tx_packet_t *pkt);
/**通过DMA获取数据包
 * 对于接收数据处理函数存在使用接收处理函数进行数据包的处理
 * 对于没有接收处理函数进行
*/
static void bcm5333x_rx_direct(void)
{
    soc_rx_packet_t *pkt = rx_pkt_in_dma;
    //对于MDA数据结构内存空间被分配的处理
    if (rx_pkt_in_dma != NULL) 
    {
        //对于接收发送数据初始化状态为否的处理，设置DMA结构体的空并返回
        if (rxtx_initialized == FALSE) 
        {
            /* DMA may has been stopped */
            rx_pkt_in_dma = NULL;
            return;
        }

        /* Gather packet information */
        //收集设置包信息
        bcm5333x_rx_retrieve(pkt);

        /* Call packet handler */
        //设置包的标记值
        pkt->flags &= ~RX_FLAG_STATE_MASK;

        /* Call packet handler */
        //对于接收处理函数不为空调用接收处理函数
        if (rx_handler != NULL) 
        {
            /*
             * Assuem we use only one buffer here. Need to change the way to
             * handle it if more than one buffer used.
             */
            //设置第一个接收包的有效状态为否
            rx_pkt_valid[0] = FALSE;
            //设置DMA的空间为空
            rx_pkt_in_dma = NULL;
            //调用接收处理函数，将数据存储在uip_buf中,将有效的数据长度存储在uip_len中
            (*rx_handler)(pkt);
        } 
        else 
        {
            /* Try to restart DMA */
            bcm5333x_rx_refill();
        }
    }
}
/**接收数据的重填充
 * 获取当前有效的数据包
 * 并将数据包通过DMA通道1接收数据通道进行传输
*/
APISTATIC void bcm5333x_rx_refill(void)
{
    uint8 i;
    uint32 val;
    for(i=0; i<SOC_MAX_RX_BUF_POSTED; i++) 
    {
        //对于数据包的有效状态为真的处理
        if (rx_pkt_valid[i]) 
        {
            soc_rx_packet_t *pkt = rx_packets[i];
            //对于包是可用的包的处理
            if (RX_PKT_AVAILABLE(pkt)) 
            {
                //设置包的标记有DMA状态
                pkt->flags |= RX_FLAG_STATE_DMA;
                rx_pkt_in_dma = pkt;
                sal_memset(&rx_dcb, 0, sizeof(dcb_t));
                //设置DMA的地址
                rx_dcb.mem_addr = PTR_TO_PCI(pkt->buffer);
                //设置DMA数据的长度
                rx_dcb.w1 = (V_DCB1_BYTE_COUNT(pkt->buflen)) ;
#if RXTX_DEBUG
                sal_printf("dcb:buf addr = 0x%08x:0x%08x\n", &rx_dcb, PTR_TO_PCI(pkt->buffer));
#endif
                //设置DMA的地址
                SYS_REG_WRITE32(CMIC_CMC1_DMA_DESC(RX_CH1), PTR_TO_PCI(&rx_dcb));
                //设置启动DMA
                val = SYS_REG_READ32(CMIC_CMC1_CH1_DMA_CTRL);
                val |= PKTDMA_ENABLE;
                SYS_REG_WRITE32(CMIC_CMC1_CH1_DMA_CTRL, val);
                return;
            }
        }
    }

    rx_pkt_in_dma = NULL;
}
/**获取接收的数据包的相关的参数
 * pkt：数据包对象
*/
APISTATIC void bcm5333x_rx_retrieve(soc_rx_packet_t *pkt)
{
    /* Gather information for the received packet */
    //获取数据包的相关参数
    //获取包的长度
    pkt->pktlen = G_DCB1_BYTE_COUNT(rx_dcb.w15);
    //设置包的标记
    pkt->flags = 0;
#if RXTX_DEBUG
    sal_printf("\n0x%08x-%08x-%08x-%08x\n", rx_dcb.w2, rx_dcb.w3, rx_dcb.w4, rx_dcb.w5);
#endif
    //获取本地端口号
    pkt->lport = G_DCB1_SRC_PORT(rx_dcb.w3);
    //获取
    pkt->traffic_class = G_DCB1_OUTER_PRI(rx_dcb.w11);
    //获取时间戳
    pkt->timestamp = rx_dcb.w13;
}
/**交换机收发数据包任务*/
APISTATIC void bcm5333x_rxtx_task(void* data)
{
    uint32 irqstat = SYS_REG_READ32(CMIC_CMC1_DMA_STAT);
    uint32 val;

    /* RX polling mode */
    if (rx_pkt_in_dma != NULL) 
    {
        if (irqstat & M_IRQ_CHAIN_DONE(RX_CH1)) {
            /* Clear bits. */
            val = SYS_REG_READ32(CMIC_CMC1_CH1_DMA_CTRL);
            val &= ~PKTDMA_ENABLE; /* clearing enable will also clear CHAIN_DONE */
            SYS_REG_WRITE32(CMIC_CMC1_CH1_DMA_CTRL, val);

            val = SYS_REG_READ32(CMIC_CMC1_DMA_STAT_CLR);
            SYS_REG_WRITE32(CMIC_CMC1_DMA_STAT_CLR, (val | (DS_DESCRD_CMPLT_CLR(RX_CH1))));
            SYS_REG_WRITE32(CMIC_CMC1_DMA_STAT_CLR, val);
            bcm5333x_rx_direct();
        }
    }

    /* TX */
    if (tx_pkt_in_dma != NULL) 
    {
        soc_tx_packet_t *pkt;
        if (irqstat & M_IRQ_CHAIN_DONE(TX_CH)) 
        {
            /* Clear bits. */
            val = SYS_REG_READ32(CMIC_CMC1_CH0_DMA_CTRL);
            val &= ~PKTDMA_ENABLE; /* clearing enable will also clear CHAIN_DONE */
            SYS_REG_WRITE32(CMIC_CMC1_CH0_DMA_CTRL, val);

            val = SYS_REG_READ32(CMIC_CMC1_DMA_STAT_CLR);
            SYS_REG_WRITE32(CMIC_CMC1_DMA_STAT_CLR, (val | (DS_DESCRD_CMPLT_CLR(TX_CH))));
            SYS_REG_WRITE32(CMIC_CMC1_DMA_STAT_CLR, val);

            tx_pkt_in_dma->status = SYS_OK;
        } else if (SAL_TIME_EXPIRED(tx_start_time, tx_timeout_ticks)) {
            /* Timeout, should abort this. */
            tx_pkt_in_dma->status = SYS_ERR_TIMEOUT;
            tx_pkt_in_dma->status = SYS_ERR;

            if (irqstat & DS_CMCx_DMA_ACTIVE(TX_CH)) {
                /* Abort TX DMA since it has something wrong */
                int i;
                uint32 ctrl;
                ctrl = SYS_REG_READ32(CMIC_CMC1_CH0_DMA_CTRL);
                ctrl |= PKTDMA_ENABLE;
                SYS_REG_WRITE32(CMIC_CMC1_CH0_DMA_CTRL, (ctrl | PKTDMA_ABORT));

                val = SYS_REG_READ32(CMIC_CMC1_DMA_STAT);
                /* Check active */
                for (i = 10; i > 0; i--) {
                     if (val & DS_CMCx_DMA_ACTIVE(TX_CH)) {
                         sal_usleep(10);
                     } else {
                         break;
                     }
                     val = SYS_REG_READ32(CMIC_CMC1_DMA_STAT);
                }
                /* Restore value */
                ctrl &= ~PKTDMA_ENABLE;
                SYS_REG_WRITE32(CMIC_CMC1_CH0_DMA_CTRL, ctrl);
                val = SYS_REG_READ32(CMIC_CMC1_DMA_STAT_CLR);
                SYS_REG_WRITE32(CMIC_CMC1_DMA_STAT_CLR, (val | DS_DESCRD_CMPLT_CLR(TX_CH)));
                SYS_REG_WRITE32(CMIC_CMC1_DMA_STAT_CLR, val);
            }
        } else {
            /* Haven't completed */
            return;
        }

        /* Send next in queue (if any) */
        pkt = tx_pkt_in_dma;
        tx_pkt_in_dma = NULL;
        if (tx_pkts_list && rxtx_initialized) {
            soc_tx_packet_t *ppkt = tx_pkts_list;
            tx_pkts_list = ppkt->next;
            bcm5333x_tx_internal(ppkt);
        }

        /* Notify tx caller */
        (*(pkt->callback))(pkt);

    }
}
/**交换机停止收发数据包*/
void bcm5333x_rxtx_stop(void)
{
    uint32 val, ctrl;
    int i, j;
    //设置收发数据的初始化状态为否
    rxtx_initialized = FALSE;
    //获取端口的link状态，并设置端口0的link状态为否
    bcm5333x_reg_get(0, R_EPC_LINK_BMAP_64, &val);
    val &= ~0x1;
    bcm5333x_reg_set(0, R_EPC_LINK_BMAP_64, val);
    //设置清除所有的数据
    SYS_REG_WRITE32(CMIC_RXBUF_EPINTF_RELEASE_ALL_CREDITS, 0);

    /* Poll for the channel 0-1 to become inactive */
    for (i = 0; i < 2; i++) 
    {
        val = SYS_REG_READ32(CMIC_CMC1_DMA_STAT);
        ctrl = SYS_REG_READ32(CMIC_CMC1_CHx_DMA_CTRL(i));
        /* Abort TX/RX DMA */
        if (val & DS_CMCx_DMA_ACTIVE(i)) 
        {
            SYS_REG_WRITE32(CMIC_CMC1_CHx_DMA_CTRL(i), ctrl|PKTDMA_ABORT);
        }

        val = SYS_REG_READ32(CMIC_CMC1_DMA_STAT);
        /* Check active */
        for (j = 10; j > 0; j--) 
        {
            if (val & DS_CMCx_DMA_ACTIVE(i)) 
            {
                sal_usleep(10);
            } 
            else 
            {
                break;
            }
            val = SYS_REG_READ32(CMIC_CMC1_DMA_STAT);
        }

        ctrl &= ~PKTDMA_ENABLE; /* clearing enable will also clear CHAIN_DONE */
        SYS_REG_WRITE32(CMIC_CMC1_CHx_DMA_CTRL(i), ctrl);

        val = SYS_REG_READ32(CMIC_CMC1_DMA_STAT_CLR);
        SYS_REG_WRITE32(CMIC_CMC1_DMA_STAT_CLR, (val | _DD_MAKEMASK1(i)));
        SYS_REG_WRITE32(CMIC_CMC1_DMA_STAT_CLR, val);
    }
}
/**交换机收发数据初始化*/
void bcm5333x_rxtx_init(void)
{
    int i;
    uint32 val;
    /* Lazy initialization */
    //对于RXTX的初始化状态为真直接返回
    if (rxtx_initialized) 
    {
        return;
    }
    //停止RXTX功能
    bcm5333x_rxtx_stop();
    //设置RXTX的初始化状态为真
    rxtx_initialized = TRUE;

    /* Known good state, CH0 for tx and CH1 for rx. */
    //设置DMA的方向
    SYS_REG_WRITE32(CMIC_CMC1_CH0_DMA_CTRL, 0x1);
    SYS_REG_WRITE32(CMIC_CMC1_CH1_DMA_CTRL, 0x0);

    /* Enable CMIC to release available credits to EP */
    //释放
    SYS_REG_WRITE32(CMIC_RXBUF_EPINTF_RELEASE_ALL_CREDITS, 0);
    SYS_REG_WRITE32(CMIC_RXBUF_EPINTF_RELEASE_ALL_CREDITS, 1);

    /* Map all COS queues to default Rx DMA channel (1) */
    //设置通道的消费值
    SYS_REG_WRITE32(CMIC_CMC1_CH1_COS_CTRL_RX_0, 0xff);

    /* Enable CPU port to receive packets. */
    //设置CPU接收端口的数据
    bcm5333x_reg_get(0, R_EPC_LINK_BMAP_64, &val);
    //设置物理端口0的连接状态为连接
    val |= 0x1;
    bcm5333x_reg_set(0, R_EPC_LINK_BMAP_64, val);
    //对端口输出数据的设置，设置为使能
    val = 0x1;
    bcm5333x_mem_set(0, M_EGR_ENABLE(0), &val, 1);

    /*
     * Enable IP to CMIC credit transfer:
     * TRANSFER_ENABLE =1, NUM_OF_CREDITS = 32
     */
    //设置使能IP数据存入到CMIC
    val = (0x1 << 6) | 32;
    bcm5333x_reg_set(0, R_IP_TO_CMICM_CREDIT_TRANSFER, val);

#if CFG_CONSOLE_ENABLED
    sal_printf("TX/RX support enabled.\n");
#endif /* CFG_CONSOLE_ENABLED */

    /* Initialize RX global variables */
    //初始化接收处理函数和接收
    rx_handler = NULL;
    rx_handler_in_intr = FALSE;
    //初始化接收队列
    for(i=0; i<SOC_MAX_RX_BUF_POSTED; i++) 
    {
        rx_pkt_valid[i] = FALSE;
    }
    //初始化接收DMA空间
    rx_pkt_in_dma = NULL;

    /* Register a background task for RX handling */
    //在系统任务中添加收发包任务
    task_add(bcm5333x_rxtx_task, (void *)NULL);

    /* Initialize TX global variables */
    //初始化发送相关的变量
    //设置发送包MDA的空
    tx_pkt_in_dma = NULL;
    //设置发送包列表为空
    tx_pkts_list = NULL;
    //设置延迟时间为当前的时间
    tx_timeout_ticks = SAL_USEC_TO_TICKS(TX_WAIT_TIMEOUT);
}
/**不使用DMA的方式发送数据的实现
 * pkt：为发送的以太网数据包
*/
APISTATIC sys_error_t bcm5333x_tx_internal(soc_tx_packet_t *pkt)
{
    int i;
    //端口号
    uint32 port;
    //以太网数据包的包头
    enet_hdr_t  *th; /* Tagged header pointers */
    //
    uint32 val;
    //设置发送数据DMA控制块的数据为0
    sal_memset(&tx_dcb, 0, sizeof(dcb_t));
    //对于端口位图的值不等于0的处理
    if (pkt->port_bitmap != 0) 
    {
        /* Use SOBMH mode. */
        tx_dcb.w1 = (1 << 19);
        //找到不为0的对应的端口
        for (port = BCM5333X_LPORT_MIN; port <= BCM5333X_LPORT_MAX; port++) 
        {
            if (pkt->port_bitmap & (1 << port)) 
            {
                break;
            }
        }
        //对于端口是大于最大逻辑端口的处理，返回错误
        if (port > BCM5333X_LPORT_MAX) 
        {
            return SYS_ERR_PARAMETER;
        }

        /* SOBMH_FROM_CPU */
        //设置的发送数据的为VLAN的数据
        tx_dcb.w2 = 0x81000000;
        /* Assign LOCAL_DEST_PORT */
        //设置
        tx_dcb.w3 = (port & 0x7F);
        /* Use cosq 3 and enable UNICAST */
        //设置消费值为3且使能单播
        tx_dcb.w4 = 0x40000 | (0x3 << 8);

        /* remove tag for untag members */
        //移除标签
        if (pkt->untag_bitmap != 0) 
        {
            th = (enet_hdr_t *)pkt->buffer;
            if (ENET_TAGGED(th)) 
            {
                pkt->pktlen -= 4;
                for (i = 12 ; i < pkt->pktlen ; i++) 
                {
                    pkt->buffer[i] = pkt->buffer[i + 4];
                }
                sal_memset(&(pkt->buffer[pkt->pktlen]), 0, 4);
            }
        }
    }
    //设置内存地址
    tx_dcb.mem_addr = PTR_TO_PCI(pkt->buffer);
    tx_dcb.w1 |= (V_DCB1_BYTE_COUNT(pkt->pktlen) | (1 << 20));
#if RXTX_DEBUG
    {
        int j;
        uint32 *p = (uint32 *)&tx_dcb;
        sal_printf("\nTX DCB: ");
        for (j = 0; j < 16; j++) {
            sal_printf("0x%08x ", *(p + j));
        }
        sal_printf("\n");
    }
    sal_printf("dcb:buf addr = 0x%08x:0x%08x\n", &tx_dcb, PTR_TO_PCI(pkt->buffer));
#endif /* RXTX_DEBUG */
    SYS_REG_WRITE32(CMIC_CMC1_DMA_DESC(0), PTR_TO_PCI(&tx_dcb));
    val = SYS_REG_READ32(CMIC_CMC1_CH0_DMA_CTRL);
    val |= PKTDMA_ENABLE;
    SYS_REG_WRITE32(CMIC_CMC1_CH0_DMA_CTRL, val);

    tx_start_time = sal_get_ticks();
    tx_pkt_in_dma = pkt;

    return SYS_OK;
}
/**交换机发送数据包的底层实现
 * unit：芯片的单元号
 * pkt：需要发送的数据包
 * 无论情况如何返回的都是成功
*/
sys_error_t bcm5333x_tx(uint8 unit, soc_tx_packet_t *pkt)
{
    SAL_ASSERT(pkt != NULL && pkt->callback != NULL && pkt->buffer != NULL);
    //对于包为空，包的回调函数为空，包数组为空返回错误
    if (pkt == NULL || pkt->callback == NULL || pkt->buffer == NULL) 
    {
        return SYS_ERR_PARAMETER;
    }
    if (pkt->pktlen == 0 || unit > 0) 
    {
        return SYS_ERR_PARAMETER;
    }

    pkt->unit = 0;
    //对于不使用MDA发送数据的处理
    if (tx_pkt_in_dma == NULL) 
    {
        bcm5333x_tx_internal(pkt);
    } 
    else 
    {
        /* DMA in progress, queue this packet */
        pkt->next = tx_pkts_list;
        tx_pkts_list = pkt;
    }
    return SYS_OK;
}
/**设置交换机接收处理函数
 * unit：为设备单元号
 * fn：回调处理函数
 * intr：
*/
sys_error_t bcm5333x_rx_set_handler(uint8 unit, SOC_RX_HANDLER fn, BOOL intr)
{
    //对于回调处理函数和设备单元号错误的处理，返回错误
    if (fn == NULL || unit > 0) 
    {
        /* XXX: should allow to remove current handler (and do RX reset) */
        return SYS_ERR_PARAMETER;
    }
    //对于没有初始化收发包的处理返回错误
    if (rxtx_initialized == FALSE) 
    {
        return SYS_ERR_STATE;
    }

    /* XXX: currently it can only be set once (and can't change) */
    //判断收发包处理函数是否为空，对于不是空的进行错误处理
    SAL_ASSERT(rx_handler == NULL);
    if (rx_handler != NULL) 
    {
        return SYS_ERR_STATE;
    }
    //设置接收处理函数
    rx_handler = fn;
    //设置接收错误处理状态
    rx_handler_in_intr = intr;

    return SYS_OK;
}
/**接收数据包的填充
 * unit：设备单元号
 * pkt：接收的数据包
 * 将收到的数据包放在空闲的数据包队列中。并放在DMA中。
*/
sys_error_t bcm5333x_rx_fill_buffer(uint8 unit, soc_rx_packet_t *pkt)
{
    uint8 i;
    uint32 val;
    //对于数据包为无效的数据包的处理
    if (pkt == NULL || pkt->buffer == NULL || pkt->buflen == 0 || unit > 0) 
    {
        return SYS_ERR_PARAMETER;
    }
    //对于收发数据错误进行处理
    if (rxtx_initialized == FALSE) 
    {
        return SYS_ERR_STATE;
    }
    //对于处理程序为空进行处理
    if (rx_handler == NULL) 
    {
        return SYS_ERR_STATE;
    }
    //对所有的数据包数组进行处理
    for(i=0; i<SOC_MAX_RX_BUF_POSTED; i++) 
    {
        //对于包的有效状态为否的处理
        if (rx_pkt_valid[i] == FALSE) 
        {
            //包的单元号为0
            pkt->unit = 0;
            //包的标记值为0
            pkt->flags = 0;
            //设置此包插入到的位置
            rx_packets[i] = pkt;
            //设置有效状态为真
            rx_pkt_valid[i] = TRUE;
            //对于不使用DMA的处理
            if (rx_pkt_in_dma == NULL) 
            {
                //设置标记值为DMA的状态
                pkt->flags |= RX_FLAG_STATE_DMA;
                //设置DMA的数据为此包
                rx_pkt_in_dma = pkt;
                //清空DMA的内容
                sal_memset(&rx_dcb, 0, sizeof(dcb_t));
                //设置DMA的地址为数据包的位置指针
                rx_dcb.mem_addr = PTR_TO_PCI(pkt->buffer);
                //设置W1的值为有效数据包的长度
                rx_dcb.w1 = V_DCB1_BYTE_COUNT(pkt->buflen);
#if RXTX_DEBUG
                sal_printf("dcb:buf addr = 0x%08x:0x%08x\n", &rx_dcb, PTR_TO_PCI(pkt->buffer));
#endif
                //设置MDA通道1的地址
                SYS_REG_WRITE32(CMIC_CMC1_DMA_DESC(RX_CH1), PTR_TO_PCI(&rx_dcb));
                //读取DMA通道1的状态值
                val = SYS_REG_READ32(CMIC_CMC1_CH1_DMA_CTRL);
                //设置DAM通道的状态值有开始启动DMA
                val |= PKTDMA_ENABLE;
                //设置通道1的DMA控制寄存器的值
                SYS_REG_WRITE32(CMIC_CMC1_CH1_DMA_CTRL, val);
            }
            return SYS_OK;
        }
    }

    return SYS_ERR_FULL;
}

#endif /* CFG_RXTX_SUPPORT_ENABLED */
