/*
 * $Id: hr2vlan.c,v 1.17 Broadcom SDK $
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
#include "soc/port.h"
#include "brdimpl/vlan.h"

#ifdef CFG_SWITCH_VLAN_INCLUDED

extern vlan_info_t  vlan_info;

static vlan_type_t hr2_vlan_type = VT_COUNT;
/*
 *  Function : bcm5333x_pvlan_egress_set
 *
 *  Purpose :
 *      Set egr_mask in EGR_VLAN.
 *
 *  Parameters :
 *
 *  Return :
 *
 *  Note :
 *
 */
/**对于基于Port的VLAN的出口数据设置
 * unit为设备单元号
 * lport为设备逻辑端口号
 * lpbmp为参加此VLAN的端口号
*/
sys_error_t bcm5333x_pvlan_egress_set(uint8 unit, uint8 lport, pbmp_t lpbmp)
{
    sys_error_t rv = SYS_OK;
    uint32 entry, all_mask;
#ifdef CFG_SWITCH_LOOPDETECT_INCLUDED
    uint32 redirection_entry[2];
#endif
    all_mask = BCM5333x_ALL_PORTS_MASK;
    //实例的信息
    entry = lpbmp;

#ifdef CFG_SWITCH_LOOPDETECT_INCLUDED
    /* In the same time, update redirect profile for the port */
    /**更新端口的配置文件*/
    bcm5333x_mem_get(0, M_IFP_REDIRECTION_PROFILE(lport), redirection_entry, 2);
    redirection_entry[0] &= (entry & all_mask);
    bcm5333x_mem_set(0, M_IFP_REDIRECTION_PROFILE(lport), redirection_entry, 2);
#endif /* CFG_SWITCH_LOOPDETECT_INCLUDED */

    entry = ~(entry & all_mask);
    //设置对于未知的单播的屏蔽，设置对于未指定的端口进行阻塞
    rv = bcm5333x_mem_set(0, M_EGR_MASK(lport), &entry, 1);

    return rv;
}


/*
 *  Function : bcm5333x_pvlan_egress_get
 *
 *  Purpose :
 *      Get egr_mask in EGR_VLAN.
 *
 *  Parameters :
 *
 *  Return :
 *
 *  Note :
 *
 */
sys_error_t bcm5333x_pvlan_egress_get(uint8 unit, uint8 lport, pbmp_t *lpbmp)
{
    sys_error_t rv = SYS_OK;
    uint32 entry;

    rv = bcm5333x_mem_get(0, M_EGR_MASK(lport), &entry, 1);
    *lpbmp = (~entry);

    return rv;
}

sys_error_t bcm5333x_qvlan_port_set(uint8 unit, uint16  vlan_id, pbmp_t lpbmp, pbmp_t tag_lpbmp)
{
    sys_error_t rv = SYS_OK;

    uint32 entry[4];
    pbmp_t untag_lpbmp;

    /* check if no exists */
    rv = bcm5333x_mem_get(0, M_VLAN(vlan_id), entry, 4);
    if((entry[1] & 0x40) != 0x40) {
        return SYS_ERR;
    }

    entry[0] = lpbmp | (entry[0] & 0xc0000000);
    rv = bcm5333x_mem_set(0, M_VLAN(vlan_id), entry, 4);

    untag_lpbmp = lpbmp & (~tag_lpbmp);
    rv = bcm5333x_mem_get(0, M_EGR_VLAN(vlan_id), entry, 3);
    entry[0] = ((lpbmp & 0x3) << 30) | untag_lpbmp;
    entry[1] &= ~(0xFFFFFFF);
    entry[1] |= lpbmp >> 2;
    rv = bcm5333x_mem_set(0, M_EGR_VLAN(vlan_id), entry, 3);

    return rv;
}


 sys_error_t bcm5333x_vlan_l3_ipmc_set(uint8 unit, uint16 vlan_id, uint16 uc_idx, uint16 umc_idx)
 {
	sys_error_t rv = SYS_OK; 
	uint32 entry[4];
   
	/* check if no exists */
	rv = bcm5333x_mem_get(0, M_VLAN(vlan_id), entry, 4);
	if((entry[1] & 0x40) != 0x40) {
	    return SYS_ERR;
    }
 
	/* bit 89 -100 for bc_idx  */	
	entry[2] |= uc_idx << 25;
 
	/* bit 101-112 for uuc_idx  */	
	entry[3] |= uc_idx << 5;
	 
	/* bit 113 -124 for umc_idx */	
	entry[3] |= umc_idx << 17;
	 
	rv = bcm5333x_mem_set(0, M_VLAN(vlan_id), entry, 4); 
    return rv;
 }

 sys_error_t bcm5333x_vlan_l3_ipmc_get(uint8 unit, uint16 vlan_id, uint16 *uc_idx, uint16 *umc_idx)
 {
	sys_error_t rv = SYS_OK; 
	uint32 entry[4];	
   
	if (uc_idx == NULL || umc_idx == NULL) {
        return SYS_ERR;
	}
 
	/* check if no exists */
	rv = bcm5333x_mem_get(0, M_VLAN(vlan_id), entry, 4);
	if(rv != SYS_OK) {
	    return SYS_ERR_EXISTS;
    }
	if((entry[1] & 0x40) != 0x40) {
	    return SYS_ERR_EXISTS;
    } 
	
 
	/* bit 101-112 for uuc_idx  */	
	*uc_idx = (entry[3] >> 5) & 0xFFF;
	 
	/* bit 113 -124 for umc_idx */	
	*umc_idx = (entry[3] >> 17) & 0xFFF; 
    return SYS_OK;
 }

 sys_error_t bcm5333x_vlan_l3_ipmc_del(uint8 unit, uint16 vlan_id)
 {
	sys_error_t rv = SYS_OK; 
	uint32 entry[4];	
    
	sal_memset(entry, 0, 4 * sizeof(uint32));	 
	rv = bcm5333x_mem_set(0, M_VLAN(vlan_id), entry, 4); 
    return rv;
 }

 sys_error_t bcm5333x_l3_ipmc_set(uint8 unit, uint16 idx, pbmp_t lpbmp)
 {
	sys_error_t rv = SYS_OK; 
	uint32 entry[3];
    pbmp_t pbmp;
   
	sal_memset(entry, 0 , 3 * sizeof(uint32));	
	rv = bcm5333x_mem_get(0, L3_IPMC(idx), entry, 3);

    BCM_PBMP_CLEAR(pbmp);
    BCM_PBMP_OR(pbmp, ((entry[0] >> 23) & 0x1FF));
	BCM_PBMP_OR(pbmp, ((entry[1] & 0x1FFFFF) << 9));
	BCM_PBMP_OR(pbmp, lpbmp);
 
	/* bit 22 valid */
	entry[0] |= 0x400000;

 
	/* bit 23 - 52 for  l2_bitmap */
	entry[0] |= ((pbmp & 0x1FF) << 23);
    entry[1] &= ~(0x1FFFFF);
    entry[1] |= pbmp >> 9;	 

	rv = bcm5333x_mem_set(0, L3_IPMC(idx), entry, 3); 
	return rv;
}

 sys_error_t bcm5333x_l3_ipmc_del(uint8 unit, uint16 idx)
 {
	sys_error_t rv = SYS_OK; 
    uint32 entry[3];
  
    sal_memset(entry, 0, 3 * sizeof(uint32));	
	rv = bcm5333x_mem_set(0, L3_IPMC(idx), entry, 3); 
	return rv;
}

 sys_error_t bcm5333x_l3_ipmc_get(uint8 unit, uint16 idx, pbmp_t *lpbmp)
 {
	sys_error_t rv = SYS_OK; 
    uint32 entry[4];
    pbmp_t pbmp;
	uint16 valid;

    if (lpbmp == NULL) {
        return SYS_ERR_PARAMETER;
    }
    //return SYS_OK;
	sal_memset(entry, 0, 4 * sizeof(uint32));	
	rv = bcm5333x_mem_get(0, L3_IPMC(idx), entry, 3);
   
 
	/* bit 22 valid */
	valid = entry[0] >> 22;
	valid &= 0x1;
	if (!valid)
	{
	    BCM_PBMP_CLEAR(*lpbmp);
        return SYS_ERR_NOT_FOUND;
	}

	BCM_PBMP_CLEAR(pbmp);
    BCM_PBMP_OR(pbmp, ((entry[0] >> 23) & 0x1FF));
	BCM_PBMP_OR(pbmp, ((entry[1] & 0x1FFFFF) << 9));
	BCM_PBMP_ASSIGN(*lpbmp, pbmp);
	return rv;
 }


/**基于协议的VLAN的端口的获取
 * unit：设备单元号
 * vlan_id：VLAN的ID号
 * lpbmp：逻辑端口的位图
 * tag_lpbmp：标记的逻辑端口的位图
*/
 sys_error_t bcm5333x_qvlan_port_get(uint8 unit, uint16  vlan_id, pbmp_t *lpbmp, pbmp_t *tag_lpbmp)
{
    sys_error_t rv = SYS_OK;

    uint32 entry[4];

    /* Check VALID[Bit 38] filed for existence */
    //判断这个VLAN是否是有效的
    //#define M_VLAN(idx)                 10,0x14000000+(idx)
    rv = bcm5333x_mem_get(0, M_VLAN(vlan_id), entry, 4);
    if((entry[1] & 0x40) != 0x40) 
    {
        return SYS_ERR;
    }
    //#define M_EGR_VLAN(idx)             11,0x100C0000+(idx)
    rv = bcm5333x_mem_get(0, M_EGR_VLAN(vlan_id), entry, 3);
    //获取参加这个端口的VLAN
    *lpbmp = (entry[0] >> 30) | ((entry[1] & 0xFFFFFFF) << 2);
    //出端口是带标签的端口
    *tag_lpbmp = (~entry[0] & 0x3fffffff) & (*lpbmp);

    return rv;
}


/**创建VLAN
 * unit：设备单元号
 * type：VLAN类型
 * vlan_id：VLAN的ID号
*/
sys_error_t bcm5333x_vlan_create(uint8 unit, vlan_type_t type, uint16  vlan_id)
{
    sys_error_t rv = SYS_OK;
    uint32 entry[4];
    
    switch (type) 
    {
        //对于创建基于协议的ID的处理
        case VT_DOT1Q:
            /* Create vlan in VLAN_TAB
             * set VALID=1,PBMP=0, VLAN_PROFILE_PTR=0, STG=1
             */
            entry[0] = 0x0;
            entry[1] = 0xc0;
            entry[2] = 0x0;
            entry[3] = 0x0;
            rv = bcm5333x_mem_set(0, M_VLAN(vlan_id), entry, 4);

            /* Create vlan in EGR_VLAN with empty pbmp */
            entry[0] = 0x0;
            entry[1] = (0x1 << 28);
            entry[2] = 0x10;
            rv = bcm5333x_mem_set(0, M_EGR_VLAN(vlan_id), entry, 3);
            break;
        default:
              /* VT_PORT_BASED */
            break;
    }

    return rv;
}


/**销毁VLAN
 * unit：设备单元号
 * vlan_id：VLAN的ID号
*/
sys_error_t bcm5333x_vlan_destroy(uint8 unit, uint16  vlan_id)
{

    sys_error_t rv;
    uint32 entry[4] = { 0x0, 0x0, 0x0, 0x0 };

    /* destroy vlan in VLAN_TAB */
    rv = bcm5333x_mem_set(0, M_VLAN(vlan_id), entry, 4);

    /* destroy vlan in EGR_VLAN */
    rv = bcm5333x_mem_set(0, M_EGR_VLAN(vlan_id), entry, 3);

    return rv;
}

/**设置VLAN的类型
 * unit：设备单元号
 * type:协议类型
*/
sys_error_t bcm5333x_vlan_type_set(uint8 unit, vlan_type_t type)
{
    int i;
    uint32 entry[4], port_entry[8];
    uint32 val;
    vlan_list_t     *this_vlan;

    sys_error_t rv = SYS_OK;
    //对于类型不是基于协议的实现
    if ((type == VT_NONE) || (type == VT_PORT_BASED))
    {

        /* Don't have to do this again if it was port based vlan */
        //对于当前的VLAN的类型已经不是基于协议的直接返回
        if ((hr2_vlan_type == VT_NONE) || (hr2_vlan_type == VT_PORT_BASED)) 
        {
             hr2_vlan_type = type;
             return SYS_OK;
        }

        /* Enable USE_LEARN_VID and set LEARN_VID as '1' */
        //使用地址映射逻辑表，学习和查询
        bcm5333x_reg_get(0, R_VLAN_CTRL, &val);
        val = (val & 0xffffe000) | 0x00001001;
        bcm5333x_reg_set(0, R_VLAN_CTRL, val);

        /* clear EN_IFILTER in PORT_TAB */
        //清除所有端口的端口信息表
        for (i = BCM5333X_LPORT_MIN; i <= BCM5333X_LPORT_MAX; i++) 
        {
            bcm5333x_mem_get(0, M_PORT(i), port_entry, 8);
            port_entry[0] &= 0xffffffdf;
            bcm5333x_mem_set(0, M_PORT(i), port_entry, 8);
        }

        /* STG=1, VALID=1, PBMP=all except CPU, VLAN_PROFILE_PTR=0 */
        entry[0] = BCM5333x_ALL_PORTS_MASK;
        entry[1] = 0xc0;
        entry[2] = 0x0;
        entry[3] = 0x0;

        /* create 2-4094 vlans */
        for (i = 2; i <= 4094; i++) 
        {
            bcm5333x_mem_set(0, M_VLAN(i), entry, 4);
        }

        /* All ports(exclude cpu) in vlan 2-4094 are tagged, STG=1 */
        entry[0] = 0x0;
        entry[1] = 0x1fffffff;
        entry[2] = 0x10;

        for (i = 2; i <= 4094; i++) 
        {
            /* create vlan in EGR_VLAN */
            bcm5333x_mem_set(0, M_EGR_VLAN(i), entry, 3);
        }
        /**对于基于端口的处理*/
        if (type == VT_PORT_BASED)
        {
            if (VLAN_DEFAULT != 1)
            {
                this_vlan = vlan_info.head;
                if (this_vlan == NULL) 
                {
                    sal_printf("%s..:%s..:this_vlan == NULL. Should not happen after brdimpl_vlan_reset()\n", __FILE__, __func__);
                    return SYS_ERR_OUT_OF_RESOURCE;
                }
                this_vlan->vlan_id = 1;
                            
                /* Re-overwrite the default VLAN to 1 for VT_PORT_BASED */
                /* Setup default vlan */
                /* STG=1, VALID=1, PBMP=all except CPU, VLAN_PROFILE_PTR=0 */
                entry[0] = BCM5333x_ALL_PORTS_MASK;
                entry[1] = 0xc0;
                entry[2] = 0x0;
                entry[3] = 0x0;
                bcm5333x_mem_set(0, M_VLAN(1), entry, 4);
            
                /* Setup EGR_VLAN, all ports untagged(exclude cpu) */
                entry[0] = BCM5333x_ALL_PORTS_MASK;
                entry[1] = 0x1fffffff;
                entry[2] = 0x10;
                bcm5333x_mem_set(0, M_EGR_VLAN(1), entry, 3);
                
                /* Reset PVID to default vlan */
                for (i = BCM5333X_LPORT_MIN; i <= BCM5333X_LPORT_MAX; i++) 
                {
                    bcm5333x_mem_get(0, M_PORT(i), port_entry, 8);
                    port_entry[0] = (port_entry[0] & 0x00ffffff) | (this_vlan->vlan_id << 24);
            		port_entry[1] = (port_entry[1] & 0xfffffff0) | ((this_vlan->vlan_id & 0xf00) >> 8);   
                    
                    rv = bcm5333x_mem_set(0, M_PORT(i), port_entry, 8);
                }
    
            }
        }

    } 
    //对于是基于802.1协议的支持
    else if (type == VT_DOT1Q)
    {

        /* Don't have to do this again if it was 802.1Q vlan */
        if (hr2_vlan_type == VT_DOT1Q) 
        {
             hr2_vlan_type = type;
             return SYS_OK;
        }

        /* Disable USE_LEARN_VID and set LEARN_VID as '0' */
        bcm5333x_reg_get(0, R_VLAN_CTRL, &val);
        val = val & 0xffffe000;
        bcm5333x_reg_set(0, R_VLAN_CTRL, val);

        /* Enable EN_IFILTER to check VLAN membership */
        for (i = BCM5333X_LPORT_MIN; i <= BCM5333X_LPORT_MAX; i++) 
        {
            bcm5333x_mem_get(0, M_PORT(i), port_entry, 8);
            port_entry[0] |= 0x00000020;
            bcm5333x_mem_set(0, M_PORT(i), port_entry, 8);
        }

        /* Clear VLAN and EGR_VLAN tables */
        entry[0] = entry[1] = entry[2] = entry[3] = 0;
        for (i = 1; i <= 4094; i++) 
        {
            if (i==VLAN_DEFAULT)
            {
                continue;
            }
                
            /* destroy vlan in VLAN_TAB */
            rv = bcm5333x_mem_set(0, M_VLAN(i), entry, 4);
            rv = bcm5333x_mem_set(0, M_EGR_VLAN(i), entry, 3);
        }
        /* end of egress_mask change */
    }

    hr2_vlan_type = type;
    return rv;
}


/**交换机VLAN的复位，这个是整个交换机的VLAN的复位实现
 * unit:设备单元号
*/
sys_error_t bcm5333x_vlan_reset(uint8 unit)
{
    sys_error_t rv = SYS_OK;
    int i;
    uint32 entry[8];
#if defined(CFG_SWITCH_LAG_INCLUDED) || defined(CFG_SWITCH_LOOPDETECT_INCLUDED)
    uint32 all_mask = BCM5333x_ALL_PORTS_MASK;
#endif /* CFG_SWITCH_LAG_INCLUDED || CFG_SWITCH_LOOPDETECT_INCLUDED */    
#ifdef CFG_SWITCH_LAG_INCLUDED
    int j, k;
    uint32 lag_lpbmp[BOARD_MAX_NUM_OF_LAG];
#endif /* CFG_SWITCH_LAG_INCLUDED */

	/* Setup default vlan */
    /* STG=1, VALID=1, PBMP=all except CPU, VLAN_PROFILE_PTR=0 */
    //设置VLAN的关系数据，低位在前

    //设置所有端口参加
    entry[0] = BCM5333x_ALL_PORTS_MASK;
    //设置此表有效，STP组ID为1
    entry[1] = 0xc0;
    entry[2] = 0x0;
    entry[3] = 0x0;
    bcm5333x_mem_set(0, M_VLAN(VLAN_DEFAULT), entry, 4);

    /* Setup EGR_VLAN, all ports untagged(exclude cpu) */
    //设置VLAN输出关系表

    //设置这些端口输出的数据应该是不带标签的,现在改为每个端口都带
    entry[0] = !BCM5333x_ALL_PORTS_MASK;
    //设置属于这个VLAN的端口和STP的组ID为为1
    entry[1] = 0x1fffffff;
    //设置这个表有效
    entry[2] = 0x10;
    bcm5333x_mem_set(0, M_EGR_VLAN(VLAN_DEFAULT), entry, 3);

    /* Set VLAN_STG and EGR_VLAN_STG */
    entry[0] = 0xfffffff0;
    entry[1] = 0x0fffffff;
    //设置生成树组状态表，接收所有的数据
    bcm5333x_mem_set(0, M_VLAN_STG(1), entry, 2);
    //设置输出生成树的状态表为接收所有数据
    bcm5333x_mem_set(0, M_EGR_VLAN_STG(1), entry, 2);

    /* Clear egr_mask for reconstruct */
    entry[0] = 0x0;
    //设置所有端口对于所有端口未知单播的处理为接收,1阻止,0接收
    for (i = BCM5333X_PORT_MIN; i <= BCM5333X_PORT_MAX; i++) 
    {
        rv = bcm5333x_mem_set(0, M_EGR_MASK(i), &entry[0], 1);
    }

    /* Recover egress_mask change in pvlan_port_set */
    for (i = BCM5333X_PORT_MIN; i <= BCM5333X_PORT_MAX; i++) 
    {
#ifdef CFG_SWITCH_LAG_INCLUDED
        /*  Revise the all_mask based on trunk port bitmap */
        all_mask = BCM5333x_ALL_PORTS_MASK;
        for (j = 0; j < BOARD_MAX_NUM_OF_LAG; j++) 
        {
            if (lag_lpbmp[j] != 0) 
            {
                all_mask &= ~(lag_lpbmp[j]);
                if (!(lag_lpbmp[j] & (1 << i))) 
                {
                    for (k = BCM5333X_PORT_MIN; k <= BCM5333X_PORT_MAX; k++) 
                    {
                        if (lag_lpbmp[j] & (1 << k)) 
                        {
                            all_mask |= (1 << k);
                            break;
                        }
                    }
                }
            }
        }
#endif /* CFG_SWITCH_LAG_INCLUDED */

#ifdef CFG_SWITCH_LOOPDETECT_INCLUDED
        bcm5333x_mem_get(0, M_IFP_REDIRECTION_PROFILE(i), entry, 2);
        entry[0] = all_mask;
        bcm5333x_mem_set(0, M_IFP_REDIRECTION_PROFILE(i), entry, 2);
#endif /* CFG_SWITCH_LOOPDETECT_INCLUDED */
    }

    /* Reset PVID to default vlan */
    //设置每个端口的配置表
    for (i = BCM5333X_LPORT_MIN; i <= BCM5333X_LPORT_MAX; i++) 
    {
        bcm5333x_mem_get(0, M_PORT(i), entry, 8);
        entry[0] = (entry[0] & 0x00ffffff) | (VLAN_DEFAULT << 24);
		entry[1] = (entry[1] & 0xfffffff0) | ((VLAN_DEFAULT & 0xf00) >> 8);   
        rv = bcm5333x_mem_set(0, M_PORT(i), entry, 8);
    }
    //bcm5333x_vlan_create(0,VT_DOT1Q,2);
    //bcm5333x_qvlan_port_set(0,2,0x3ffffffc,0x3ffff3fc);
    return rv;
}
#endif /* CFG_SWITCH_VLAN_INCLUDED */
