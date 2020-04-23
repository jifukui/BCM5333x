/*
 * $Id: rx.c,v 1.5 Broadcom SDK $
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

#ifdef __C51__
#ifdef CODE_USERCLASS
#pragma userclass (code = krnrx)
#endif /* CODE_USERCLASS */
#endif /* __C51__ */

#include "system.h"

#if (CFG_RXTX_SUPPORT_ENABLED && !defined(__BOOTLOADER__))
/**定义接收数据回调结构体
 * priority：优先级
 * cbk：回调函数
 * cookie：
 * flags：
 * next：
*/
typedef struct rx_cbk_s {
    uint8 priority;
    SYS_RX_CBK_FUNC cbk;
    void *cookie;
    uint16 flags;
    struct rx_cbk_s *next;
} rx_cbk_t;

STATIC rx_cbk_t   rx_cbks[CFG_MAX_REGISTERED_RX_CBKS];
STATIC uint8      rx_cbk_count;
STATIC rx_cbk_t * rx_cbk_list;
STATIC sys_pkt_t *rx_pkt_pool;

/* Forwards */
void APIFUNC(sys_rx_init)(void) REENTRANT;
APISTATIC void sys_rx_handler(sys_pkt_t *pkt) REENTRANT;
APISTATIC sys_error_t sys_rx_refill(sys_pkt_t *pkt) REENTRANT;
/**注册接收数据回调函数
 * callback：回调处理函数
 * priority：优先级
 * cookie：
 * flags：
*/
sys_error_t  APIFUNC(sys_rx_register)(
    SYS_RX_CBK_FUNC callback, 
    uint8 priority, 
    void *cookie,
    uint16 flags) REENTRANT
{
    uint8 i;
    rx_cbk_t *cbk = NULL;
    //对于回调函数为空的处理
    if (callback == NULL) 
    {
        return SYS_ERR_PARAMETER;
    }
    //寻找空闲的槽位
    for(i=0; i<CFG_MAX_REGISTERED_RX_CBKS; i++) 
    {
        if (rx_cbks[i].cbk == NULL) 
        {
            cbk = &rx_cbks[i];
            break;
        }
    }
    //判断回调函数的空间存在
    SAL_ASSERT(cbk != NULL);
    if (cbk == NULL) 
    {
        return SYS_ERR_FULL;
    }
    //初始化回调函数的参数
    //设置优先级
    cbk->priority = priority;
    //设置回调函数
    cbk->cbk = callback;
    //设置
    cbk->cookie = cookie;
    //设置
    cbk->flags = flags;
    //设置下一个
    cbk->next = NULL;
    
    
    //设置回调函数在回调函数列表中的位置
    //对于接收回调函数列表为空设置回调函数列表为此回调函数
    if (rx_cbk_list == NULL) 
    {
        rx_cbk_list = cbk;
    } 
    //对于回调函数列表不为空的处理，按照优先级进行排序
    else 
    {
        //获取回调函数列表头
        rx_cbk_t *cur = rx_cbk_list;
        //设置当前回调函数列表中的对象的父级
        rx_cbk_t *prev = NULL;
        while(cur != NULL) 
        {
            //对于当前函数的优先级大于此回调函数的优先级的处理
            if (cur->priority >= cbk->priority) 
            {
                cbk->next = cur;
                if (prev == NULL) 
                {
                    rx_cbk_list = cbk;
                } 
                else 
                {
                    prev->next = cbk;
                }
                break;
            }
            prev = cur;
            cur = cur->next;
        }
        if (cur == NULL) 
        {
            prev->next = cbk;
        }
    }
    
    rx_cbk_count++;
    //对于只有一个回调函数的处理
    if (rx_cbk_count == 1) 
    {
        sys_pkt_t *pkt;
        //对于数据包池的空间不为空的处理，
        while(rx_pkt_pool != NULL) 
        {
            pkt = rx_pkt_pool;
            rx_pkt_pool = rx_pkt_pool->next;
            if (board_rx_fill_buffer(pkt) != SYS_OK) 
            {
                SAL_ASSERT(FALSE);
                sal_free(pkt);
            }
        }
    }
    
    return SYS_OK;
}
/**注销接收回调处理函数*/
sys_error_t APIFUNC(sys_rx_unregister)(SYS_RX_CBK_FUNC callback) REENTRANT
{
    rx_cbk_t *cur = rx_cbk_list;
    rx_cbk_t *prev = NULL;
    while(cur != NULL) {
        if (cur->cbk == callback) {
            if (prev == NULL) {
                rx_cbk_list = cur->next;
            } else {
                prev->next = cur->next;
            }
            cur->cbk = NULL;
            rx_cbk_count--;
            return SYS_OK;
        }
        prev = cur;
        cur = cur->next;
    }    
    
    return SYS_ERR_PARAMETER;
}
/**
 * pkt：数据包的结构
*/
APISTATIC sys_error_t APIFUNC(sys_rx_refill)(sys_pkt_t *pkt) REENTRANT
{
    //对于存在接收处理回调函数的处理
    if (rx_cbk_count > 0) 
    {
        //调用板子的接收数据
        return board_rx_fill_buffer(pkt);
    }
    //对于不存在接收处理函数的处理 
    else 
    {
        pkt->next = rx_pkt_pool;
        rx_pkt_pool = pkt;
    }
    
    return SYS_OK;
}
/**接收数据包的回调处理函数
 *pkt:数据包 
*/
APISTATIC void APIFUNC(sys_rx_handler)(sys_pkt_t *pkt) REENTRANT
{
    //获取当前的接收回调函数
    rx_cbk_t *cur = rx_cbk_list;
    uint16 flags;
    sys_rx_t r;
    
    SAL_ASSERT(pkt != NULL);
    //flags为数据表的标记值
    flags = pkt->flags;
    /**对于接收包的处理函数不为空的处理*/
    while(cur != NULL) 
    {
        SAL_ASSERT(cur->cbk != NULL);
        //对于数据标记为被截断状态的处理
        if (flags & SYS_RX_FLAG_TRUNCATED) 
        {  
            //对于当前回调结构体的标记值不是接收截断的数据包的处理，设置cur为下一个回调处理。继续后面的处理
            if (!(cur->flags & SYS_RX_REGISTER_FLAG_ACCEPT_TRUNCATED_PKT)) 
            {
                cur = cur->next;
                continue;
            }
        }
        //对于冗余错误或者是其他错误的处理
        if ((flags & (SYS_RX_FLAG_ERROR_CRC | SYS_RX_FLAG_ERROR_OTHER))) 
        {
            //如果当前回调处理标记不是接收被截断的数据包的处理，设置cur为下一个回调处理，继续后面的处理
            if (!(cur->flags & SYS_RX_REGISTER_FLAG_ACCEPT_TRUNCATED_PKT)) 
            {
                cur = cur->next;
                continue;
            }
        }
        //使用回调函数处理此数据包，并返回值
        r = (*cur->cbk)(pkt, cur->cookie);
        //根据返回值进行处理
        switch(r) 
        {
        //对于数据包被处理过的处理
        case SYS_RX_HANDLED:
            board_rx_fill_buffer(pkt);
            return;

        case SYS_RX_HANDLED_AND_OWNED:
            return;

        default:
            /* Invalid return code */
            SAL_ASSERT(FALSE);
            /* Fall through (if assertion not enabled) */

        case SYS_RX_NOT_HANDLED:
            cur = cur->next;
            continue;
        }
    }    
    
    /* If no one handles it */
    sys_rx_refill(pkt);
}

void APIFUNC(sys_rx_free_packet)(sys_pkt_t *pkt) REENTRANT
{
    if (pkt == NULL) {
        return;
    }
    
    sys_rx_refill(pkt);
}
/**
 * buffer：
 * size：
*/
void APIFUNC(sys_rx_add_buffer)(uint8 *buffer, uint16 size) REENTRANT
{
    sys_pkt_t *pkt;
    sys_error_t r;
    //判断buffer是不是不等于空size的值是不是不为0
    SAL_ASSERT(buffer != NULL && size != 0);
    if (buffer == NULL || size == 0) 
    {
        return;
    }
    //申请内存空间
    pkt = (sys_pkt_t *)sal_malloc(sizeof(sys_pkt_t));
    SAL_ASSERT(pkt != NULL);
    if (pkt == NULL) 
    {
        return;
    }
    //设置数据为buffer
    pkt->pkt_data = buffer;
    //设置数据长度
    pkt->buf_len = size;
    //
    r = sys_rx_refill(pkt);
    SAL_ASSERT(r == SYS_OK);
    //对于返回值状态不是正确释放申请的包的空间
    if (r != SYS_OK) 
    {
        sal_free(pkt);
    }
}
/**接收包初始化函数
 * 设置回调函数列表为空
 * 设置接收包数据池为空
 * 设置回调函数的数量为空
 * 清除回调函数数组的回电函数为空
 * 注册接收数据包的回调函数为sys_rx_handler
*/
void APIFUNC(sys_rx_init)(void) REENTRANT
{
    uint8 i;
    
    /* Initialize global variables */
    rx_cbk_list = NULL;
    rx_pkt_pool = NULL;
    rx_cbk_count = 0;
    for(i=0; i<CFG_MAX_REGISTERED_RX_CBKS; i++) {
        rx_cbks[i].cbk = NULL;
    }

    /* Register switch RX callback */
    board_rx_set_handler(sys_rx_handler);
}

#endif /* CFG_RXTX_SUPPORT_ENABLED && !defined(__BOOTLOADER__) */

