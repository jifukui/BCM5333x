/*
 * $Id: tx.c,v 1.4 Broadcom SDK $
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
#pragma userclass (code = krntx)
#endif /* CODE_USERCLASS */
#endif /* __C51__ */

#include "system.h"

#if (CFG_RXTX_SUPPORT_ENABLED && !defined(__BOOTLOADER__))
 
/* Forwards */
void APIFUNC(sys_tx_init)(void) REENTRANT;
APISTATIC void sys_tx_sync_cbk(sys_pkt_t *pkt, sys_error_t status) REENTRANT;
/**系统发送同步回调函数
 * pkt：为数据包
 * status：记录错误状态
*/
APISTATIC void APIFUNC(sys_tx_sync_cbk)(sys_pkt_t *pkt, sys_error_t status) REENTRANT
{
    //校验数据包是否是错误的
    SAL_ASSERT(pkt != NULL);
    if (pkt == NULL) 
    {
        return;
    }

    /* Mark packet as done */  
    //标记数据包已经发送完成  
    pkt->internal0 = (uint32)status;
}
/**系统发送函数‘
 * pkt：
 * cbk：
 * 返回发送状态值
*/
sys_error_t APIFUNC(sys_tx)(sys_pkt_t *pkt, SYS_TX_CALLBACK cbk) REENTRANT
{
    sys_error_t r;
    //对于包的地址没有被分配，包的包数据为空，包的数据包长度为0的处理；返回错误
    if (pkt == NULL || pkt->pkt_data == NULL || pkt->pkt_len == 0) 
    {
        return SYS_ERR_PARAMETER;
    }
    //对于没有回调函数的处理
    if (cbk == NULL) 
    {
        
        /* We make use of this field to mark packet being processing */
        pkt->internal0 = 1;
        
        /**调用实际的数据发送函数*/
        r = board_tx(pkt, sys_tx_sync_cbk);
        //根据返回值进行处理
        if (r == SYS_OK) 
        {
            for(;;) 
            {
                POLL();
                //对于状态值不为1的处理，设置返回值为包的发送状态
                if (pkt->internal0 != 1) 
                {
                    r = (sys_error_t)pkt->internal0;
                    break;
                }
                /* We rely on BOARD-layer tx to timeout if it takes too long */
            }
        }

        return r;

    } 
    //对于有回调函数的处理
    else 
    {
        r = board_tx(pkt, (BOARD_TX_CALLBACK)cbk);
        return r;
    }
}
/**发送初始化函数，没有具体实现*/
void APIFUNC(sys_tx_init)(void) REENTRANT
{
}

#endif /* CFG_RXTX_SUPPORT_ENABLED && !defined(__BOOTLOADER__) */

