/*
 * $Id: mdk_phy.c,v 1.20 Broadcom SDK $
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
#include "xgsm_miim.h"

/*
 * phy_addr encoding
 * bit7, 1: internal MDIO bus, 0: external MDIO bus
 * bit6,5, mdio bus number
 * bit4-0,   mdio addresses
 */
#define CDK_CONFIG_MIIM_MAX_POLLS   100000
/**内部PHY掩码*/
#define PHY_INTERNAL_MASK        0x80
/**PHY 总线ID掩码*/
#define PHY_ID_BUS_MASK          0x60
/**PHY 地址掩码*/
#define PHY_ADDR_MASK            0x1f
/**总线的移动位数*/
#define PHY_ID_BUS_SHIFT         5
/**根据PHY的ID获取总线号*/
#define PHY_ID_BUS_NUM(_id)      (((_id) & PHY_ID_BUS_MASK) >> PHY_ID_BUS_SHIFT)
/***/
#define PHY_RESET_POLL_MAX       (20)
/***/
#define MIIM_PARAM_ID_OFFSET     (16)
/***/
#define MIIM_PARAM_BUSID_OFFSET  (22)
/***/
#define MIIM_PARAM_REG_ADDR_OFFSET  24
/***/
#define MIIM_PARAM_INT_OFFSET    (25)



extern phy_bus_t phy_bus_bcm56150_miim_int;
extern phy_bus_t phy_bus_bcm956150k_miim_ext;
/**定义使用的总线驱动*/
static phy_bus_t *bcm5333xmdk_phy_bus[] = {
    &phy_bus_bcm56150_miim_int,
    &phy_bus_bcm956150k_miim_ext,
    NULL
};

extern phy_driver_t bcmi_tsc_xgxs_drv;
#if !CONFIG_GREYHOUND_ROMCODE
extern phy_driver_t bcm54282_drv;
extern phy_driver_t bcm56150_drv;
extern phy_driver_t bcmi_qsgmii_serdes_drv;
extern phy_driver_t bcm54880e_drv;
#endif /* !CONFIG_GREYHOUND_ROMCODE */
/**定义5333x使用的PHY的驱动程序*/
phy_driver_t *phy_drv_list_bcm95333x[] = {
    &bcm56150_drv,
    &bcm54282_drv,
    &bcmi_qsgmii_serdes_drv,
    NULL
};
/**定义*/
phy_driver_t *phy_drv_list_bcm95339x[] = {
    &bcm54880e_drv,
    &bcmi_tsc_xgxs_drv,
    &bcmi_qsgmii_serdes_drv,
    NULL
};

phy_driver_t *phy_drv_list_bcm95334x[] = {
    &bcm56150_drv,
    &bcm54282_drv,
    &bcmi_qsgmii_serdes_drv,
    &bcmi_tsc_xgxs_drv,
    NULL
};
/**定义外部PHY的模式*/
static uint32 phy_external_mode = 0;
//定义PHY为外部模式
#define PHY_EXTERNAL_MODE(lport) (phy_external_mode & (0x1 << lport))
//
static uint32 phy_egphy_mode = 0;
//
#define PHY_EGPHY_MODE(lport) (phy_egphy_mode & (0x1 << lport))

//定义设备信息
bmd_phy_info_t bmd_phy_info[BOARD_NUM_OF_UNITS];
//定义最大的控制PHY的数量为BCM5333X的最大逻辑端口数量的2倍
#define PHY_CTRL_NUM_MAX  (BCM5333X_LPORT_MAX*2)
/*
 * We do not want to rely on dynamic memory allocation,
 * so we allocate phy_ctrl blocks from a static pool.
 * The 'bus' member of the structure indicates whether
 * the block is free or in use.
 */
static phy_ctrl_t _phy_ctrl[PHY_CTRL_NUM_MAX];
/**定义PHY的复位回调函数*/
int (*phy_reset_cb)(phy_ctrl_t *pc);
/**定义PHY的初始化回调函数*/
int (*phy_init_cb)(phy_ctrl_t *pc);

/*
 * Register PHY init callback function
 */
/**初始化注册PHY的回调处理函数*/
int bmd_phy_init_cb_register(int (*init_cb)(phy_ctrl_t *pc))
{
    phy_init_cb = init_cb;

    return CDK_E_NONE;
}

/*
 * Register PHY reset callback function
 */
/**复位注册的PHY回调函数*/
int bmd_phy_reset_cb_register(int (*reset_cb)(phy_ctrl_t *pc))
{
    phy_reset_cb = reset_cb;

    return CDK_E_NONE;
}

int bmd_phy_add(int unit, int lport, phy_ctrl_t *pc)
{
    pc->next = BMD_PORT_PHY_CTRL(unit, lport);
    BMD_PORT_PHY_CTRL(unit, lport) = pc;
    return CDK_E_NONE;
}
/***/
phy_ctrl_t *bmd_phy_del(int unit, int lport)
{
    phy_ctrl_t *pc;

    if ((pc = BMD_PORT_PHY_CTRL(unit, lport)) != 0) 
    {
        BMD_PORT_PHY_CTRL(unit, lport) = pc->next;
    }
    return pc;
}

static phy_ctrl_t * phy_ctrl_alloc(void)
{
    int idx;
    phy_ctrl_t *pc;

    for (idx = 0, pc = &_phy_ctrl[0]; idx < PHY_CTRL_NUM_MAX; idx++, pc++) 
    {
        if (pc->bus == 0) 
        {
            return pc;
        }
    }
    return NULL;
}
/**释放PHY的控制*/
static void phy_ctrl_free(phy_ctrl_t *pc)
{
    pc->bus = 0;
}

/*
 * Probe all PHY buses associated with BMD device
 */
/**使用默认值键PHY的驱动，传入的端口为逻辑端口*/
int bmd_phy_probe_default(int unit, int lport, phy_driver_t **phy_drv)
{
    phy_bus_t **bus;
    phy_driver_t **drv;
    phy_ctrl_t pc_probe;
    phy_ctrl_t *pc;
    int rv;

    /* Remove any existing PHYs on this lport */
    /**清除所有存在的端口的PHY*/
    while ((pc = bmd_phy_del(unit, lport)) != 0) 
    {
        phy_ctrl_free(pc);
    }

    /* Bail if not PHY driver list is provided */
    /**对于驱动为空的处理*/
    if (phy_drv == NULL) 
    {
        return CDK_E_NONE;
    }

    /* Check that we have PHY bus list */
    /**设置bus的值为总线的驱动程序，对于当前的总线的驱动程序为空的处理*/
    bus = BMD_PORT_PHY_BUS(unit, lport);
    if (bus == NULL) 
    {
        return CDK_E_CONFIG;
    }

    /* Loop over PHY buses for this lport */
    /**对于当前总线的驱动程序不为空的处理*/
    while (*bus != NULL) 
    {
        drv = phy_drv;
        /* Probe all PHY drivers on this bus */
        while (*drv != NULL) 
        {
            /* Initialize PHY control used for probing */
            pc = &pc_probe;
            sal_memset(pc, 0, sizeof(*pc));
            pc->unit = unit;
            pc->port = SOC_PORT_L2P_MAPPING(lport);
            pc->bus = *bus;
            pc->drv = *drv;
            if (CDK_SUCCESS(PHY_PROBE(pc))) 
            {
                /* Found known PHY on bus */
                pc = phy_ctrl_alloc();
                if (pc == NULL) 
                {
                    return CDK_E_MEMORY;
                }
                sal_memcpy(pc, &pc_probe, sizeof(*pc));
                /* Install PHY */
                rv = bmd_phy_add(unit, lport, pc);
                if (CDK_FAILURE(rv)) 
                {
                    return rv;
                }
#ifdef PHY_PROBE_VERBOSE_INCLUDED
                sal_printf("lport %d(%d) found %s driver, next = %d\n", lport, pc->port, pc->drv->drv_name, pc->next ? 1:0);
#endif
                /* Move to next bus */
                break;
            }
            drv++;
        }
        bus++;
    }
    /**设置pc为总线的crtl*/
    pc = BMD_PORT_PHY_CTRL(unit, lport);
    if (pc && pc->next) 
    {
        /* If both external PHY and serdes are attached. */
        phy_external_mode |= (0x1 << lport);
    }

    if (pc && !pc->next && pc->drv && pc->drv->drv_name &&(!sal_strcmp(pc->drv->drv_name, "bcm56150"))) 
    {
        /* If both external PHY and serdes are attached. */
        phy_egphy_mode |= (0x1 << lport);
    }

    return CDK_E_NONE;
}
/***/
int soc_phyctrl_notify(phy_ctrl_t *pc, phy_event_t event, uint32 value)
{
    int rv = CDK_E_NONE;
#if 0
    
    if (auto_cfg[unit][port]) {
        return CDK_E_NONE;
    }
#endif

    PHY_CTRL_CHECK(pc);

    if (!(pc->next)) 
    {
        /* No serdes driver */
        return CDK_E_NONE;
    }

    switch (event) 
    {
        case PhyEvent_Speed:
            rv = PHY_SPEED_SET(pc->next, value);
            break;
        case PhyEvent_Duplex:
            rv = PHY_DUPLEX_SET(pc->next, value);
            break;
        default:
            return CDK_E_NONE;
    }

    return rv;
}
/**读取PHY的寄存器，传入的是逻辑端口寄存器地址返回数据的参数值
 * lport：为逻辑端口号
 * red_addr：为寄存器的地址
 * p_value：为读取值的内存地址
*/
sys_error_t phy_reg_read(uint8 lport, uint16 reg_addr, uint16 *p_value)
{
    int rv = CDK_E_NONE;
    uint32 value;
    phy_ctrl_t *pc;
    /**逻辑端口到物理端口的映射*/
    if ((SOC_PORT_L2P_MAPPING(lport) == -1) || (lport > BCM5333X_LPORT_MAX)) 
    {
        return SYS_ERR;
    }
    //获取对应端口的控制结构
    pc = BMD_PORT_PHY_CTRL(0, lport);

    //读取寄存器的值
    rv = PHY_BUS_READ(pc, (uint32)reg_addr, &value);

    *p_value = (uint16)value;
    //返回读取状态
    if (!rv) 
    {
        return SYS_OK;
    }
    else 
    {
        return SYS_ERR;
    }
}

/*
 *  Function : phy_reg_write
 *
 *  Purpose :
 *      Write a value into a MII register.
 *
 *  Parameters :
 *      dev (input) : PHY id
 *      reg_addr (input) : PHY regsiter
 *      value (input) : PHY data to write into register
 *
 *  Return :
 *      SYS_OK : success
 *      SYS_ERR : failed to access the MII register
 *
 */
/**向PHY的寄存器写数据*/
sys_error_t phy_reg_write(uint8 lport, uint16 reg_addr, uint16 value)
{
    int rv = CDK_E_NONE;

    phy_ctrl_t *pc;

    if ((SOC_PORT_L2P_MAPPING(lport) == -1) || (lport > BCM5333X_PORT_MAX)) 
    {
        return SYS_ERR;
    }


    pc = BMD_PORT_PHY_CTRL(0, lport);

    rv = PHY_BUS_WRITE(pc, (uint32)reg_addr, (uint32)value);

    if (!rv) 
    {
        return SYS_OK;
    }
    else 
    {
        return SYS_ERR;
    }
}

/**MIIM管理接口读取数据
 * unit：设备单元号
 * phy_addr：phy地址
 * reg:寄存器地址
 * val：为读取的数据值的缓存区
*/
int cdk_xgsm_miim_read(int unit, uint32_t phy_addr, uint32_t reg, uint32_t *val)
{
    int rv = CDK_E_NONE;
    uint32 polls;
    uint32 data;
    uint32 phy_param;

    /*
     * Use clause 45 access if DEVAD specified.
     * Note that DEVAD 32 (0x20) can be used to access special DEVAD 0.
     */
    //对于寄存器的值与上3f0000的值为真的处理
    if (reg & 0x003f0000) 
    {
        //设置使用规程45
        phy_addr |= CDK_XGSM_MIIM_CLAUSE45;
        //设置寄存器的地址
        reg &= 0x001fffff;
    }
    //
    phy_param = (phy_addr << MIIM_PARAM_ID_OFFSET);

    /**设置编程寄存器，WRITECSR的作用是读取指定内存的值*/
    WRITECSR(CMIC_CMC1_MIIM_PARAM, phy_param);
    /**设置读地址寄存器*/
    WRITECSR(CMIC_CMC1_MIIM_ADDRESS, reg);

    /* Tell CMIC to start */
    /**设置读取数据*/
    WRITECSR(CMIC_CMC1_MIIM_CTRL, CMIC_MIIM_RD_START);

    /* 轮询读取操作状态 */
    for (polls = 0; polls < CDK_CONFIG_MIIM_MAX_POLLS; polls++) 
    {
        data = READCSR(CMIC_CMC1_MIIM_STAT);
        if (data & CMIC_MIIM_OPN_DONE) 
        {
            break;
        }
    }

    /* Check for timeout and error conditions */
    /**判断是否超时*/
    if (polls == CDK_CONFIG_MIIM_MAX_POLLS) 
    {
        rv = -1;
        CDK_DEBUG_MIIM
            (("cdk_xgsm_miim_read[%d]: Timeout at phy_addr=0x%08x"
            "reg_addr=%08x\n",unit, phy_addr, reg));
    }

    WRITECSR(CMIC_CMC1_MIIM_CTRL, 0x0);
    /**对于没有超时的处理*/
    if (rv >= 0) 
    {
        *val = READCSR(CMIC_CMC1_MIIM_READ_DATA);
        CDK_DEBUG_MIIM
            (("cdk_xgsm_miim_read[%d]: phy_addr=0x%08x"
            "reg_addr=%08x data: 0x%08x\n",
              unit, phy_addr, reg, *val));
    }
    return rv;
}

int cdk_xgsm_miim_write(int unit, uint32_t phy_addr, uint32_t reg, uint32_t val)
{
    int rv = CDK_E_NONE;
    uint32 polls, data, phy_param;

    /*
     * Use clause 45 access if DEVAD specified.
     * Note that DEVAD 32 (0x20) can be used to access special DEVAD 0.
     */
    if (reg & 0x003f0000) 
    {
        phy_addr |= CDK_XGSM_MIIM_CLAUSE45;
        reg &= 0x001fffff;
    }

    phy_param = (phy_addr << MIIM_PARAM_ID_OFFSET) | val;

    WRITECSR(CMIC_CMC1_MIIM_PARAM, phy_param);

    WRITECSR(CMIC_CMC1_MIIM_ADDRESS, reg);

    /* Tell CMIC to start */
    WRITECSR(CMIC_CMC1_MIIM_CTRL, CMIC_MIIM_WR_START);

    /* Poll for completion */
    for (polls = 0; polls < CDK_CONFIG_MIIM_MAX_POLLS; polls++) 
    {
        data = READCSR(CMIC_CMC1_MIIM_STAT);
        if (data & CMIC_MIIM_OPN_DONE) 
        {
            break;
        }
    }

    /* Check for timeout and error conditions */
    if (polls == CDK_CONFIG_MIIM_MAX_POLLS) 
    {
        rv = -1;
        CDK_DEBUG_MIIM
            (("cdk_xgsm_miim_read[%d]: Timeout at phy_addr=0x%08x"
              "reg_addr=%08x\n",
              unit, phy_addr, reg));
    }

    WRITECSR(CMIC_CMC1_MIIM_CTRL, 0x0);

    return rv;
}
/**PHY的初始化，设置PHY复位并进行PHY的初始化对于存在初始化回调函数进行调用初始化回调函数*/
int bmd_phy_init(int unit, int lport)
{
    int rv = CDK_E_NONE;

    if (BMD_PORT_PHY_CTRL(unit, lport)) 
    {
        //设置PHY复位
        rv = PHY_RESET(BMD_PORT_PHY_CTRL(unit, lport));
        //复位成功且存在PHY复位回调函数的处理
        if (CDK_SUCCESS(rv) && phy_reset_cb) 
        {
            rv = phy_reset_cb(BMD_PORT_PHY_CTRL(unit, lport));
        }
        //对于成功的处理
        if (CDK_SUCCESS(rv)) 
        {
            rv = PHY_INIT(BMD_PORT_PHY_CTRL(unit, lport));
        }
        if (CDK_SUCCESS(rv) && phy_init_cb) 
        {
            rv = phy_init_cb(BMD_PORT_PHY_CTRL(unit, lport));
        }
    }
    return rv;
}
/**给逻辑端口添加
 * unit:设备单元号
 * lport:逻辑端口
*/
int bmd_phy_attach(int unit, int lport)
{
    int rv;

    CDK_VERB(("bmd_phy_attach: lport=%d\n", lport));
    //给逻辑端口添加总线函数
    BMD_PORT_PHY_BUS(unit, lport) = bcm5333xmdk_phy_bus;
    //添加驱动程序
    rv = bmd_phy_probe_default(unit, lport, bmd_phy_drv_list);
    //对于探测成功进行处理
    if (CDK_SUCCESS(rv)) 
    {
        //调用初始化函数
        rv = bmd_phy_init(unit, lport);
    }

    return rv;
}
/**PHY探测phy
 * 对于53334 unit的值为0
 * lport为逻辑端口号
*/
int bmd_phy_probe(int unit, int lport)
{
    /**设置此端口的总线程序*/
    BMD_PORT_PHY_BUS(unit, lport) = bcm5333xmdk_phy_bus;
    switch (hr2_sw_info.devid) 
    {
        case BCM53333_DEVICE_ID:
        case BCM53334_DEVICE_ID:
            return bmd_phy_probe_default(unit, lport, phy_drv_list_bcm95333x);
        case BCM53393_DEVICE_ID:
        case BCM53394_DEVICE_ID:
            return bmd_phy_probe_default(unit, lport, phy_drv_list_bcm95339x);
        case BCM53344_DEVICE_ID:
        case BCM53346_DEVICE_ID:
            return bmd_phy_probe_default(unit, lport, phy_drv_list_bcm95334x);
        default :
            break;
    }
    return CDK_E_NONE;
}
/**PHY的模式设置*/
int bmd_phy_mode_set(int unit, int lport, char *name, int mode, int enable)
{
    int rv = CDK_E_NONE;

    phy_ctrl_t *pc = BMD_PORT_PHY_CTRL(unit, lport);

    while (pc != NULL) 
    {
        if (name && pc->drv && pc->drv->drv_name &&
            (sal_strcmp(pc->drv->drv_name, name) != 0)) 
        {
            pc = pc->next;
            continue;
        }
        switch (mode) {
        case BMD_PHY_MODE_WAN:
            rv = PHY_CONFIG_SET(pc, PhyConfig_Mode,
                                enable ? PHY_MODE_WAN : PHY_MODE_LAN, NULL);
            if (!enable && rv == CDK_E_UNAVAIL) {
                rv = CDK_E_NONE;
            }
            break;
        case BMD_PHY_MODE_2LANE:
            if (enable) {
                PHY_CTRL_FLAGS(pc) |= PHY_F_2LANE_MODE;
            } else {
                PHY_CTRL_FLAGS(pc) &= ~PHY_F_2LANE_MODE;
            }
            break;
        case BMD_PHY_MODE_SERDES:
            if (enable) {
                PHY_CTRL_FLAGS(pc) |= PHY_F_SERDES_MODE;
            } else {
                PHY_CTRL_FLAGS(pc) &= ~PHY_F_SERDES_MODE;
            }
            break;
        default:
            rv = CDK_E_PARAM;
            break;
        }
        break;
    }
    return rv;
}

int bmd_phy_fw_base_set(int unit, int lport, char *name, uint32_t fw_base)
{
    int rv = CDK_E_NONE;

    phy_ctrl_t *pc = BMD_PORT_PHY_CTRL(unit, lport);

    while (pc != NULL) {
        if (name && pc->drv && pc->drv->drv_name &&
            (sal_strcmp(pc->drv->drv_name, name) != 0)) {
            pc = pc->next;
            continue;
        }
        rv = PHY_CONFIG_SET(pc, PhyConfig_RamBase, fw_base, NULL);
        if (rv == CDK_E_UNAVAIL) {
            rv = CDK_E_NONE;
        }
        break;
    }
    return rv;
}

int bmd_phy_fw_helper_set(int unit, int lport,
                      int (*fw_helper)(void *, uint32_t, uint32_t, void *))
{
    phy_ctrl_t *pc = BMD_PORT_PHY_CTRL(unit, lport);

    while (pc != NULL) {
        PHY_CTRL_FW_HELPER(pc) = fw_helper;
        pc = pc->next;
    }
    return CDK_E_NONE;
}
/**PHY的接口设置*/
int bmd_phy_line_interface_set(int unit, int lport, int intf)
{
    int pref_intf;

    if (BMD_PORT_PHY_CTRL(unit, lport)) {
        switch (intf) {
        case BMD_PHY_IF_XFI:
            pref_intf = PHY_IF_XFI;
            break;
        case BMD_PHY_IF_SFI:
            pref_intf = PHY_IF_SFI;
            break;
        case BMD_PHY_IF_KR:
            pref_intf = PHY_IF_KR;
            break;
        case BMD_PHY_IF_CR:
            pref_intf = PHY_IF_CR;
            break;
        case BMD_PHY_IF_HIGIG:
            pref_intf = PHY_IF_HIGIG;
            break;
        default:
            pref_intf = 0;
            break;
        }
        PHY_CTRL_LINE_INTF(BMD_PORT_PHY_CTRL(unit, lport)) = pref_intf;
    }
    return CDK_E_NONE;
}
/**PHY的能力设置*/
int bmd_phy_ability_set(int unit, int lport, char *name, int ability)
{
    int rv = CDK_E_NONE;

    phy_ctrl_t *pc = BMD_PORT_PHY_CTRL(unit, lport);
    int phy_abil = 0;
    
    while (pc != NULL) 
    {
        if (name && pc->drv && pc->drv->drv_name &&(sal_strcmp(pc->drv->drv_name, "bcmi_tsc_xgxs") != 0)) 
        {
            pc = pc->next;
            continue;
        }

        /* Add more phy abilities besides those in the initialization */

        if (ability & BMD_PHY_ABIL_10GB)
        {
            phy_abil |= PHY_ABIL_10GB;
        }

        rv = PHY_CONFIG_SET(pc, PhyConfig_AdvLocal, phy_abil, NULL);
        if (rv == CDK_E_UNAVAIL) 
        {
            rv = CDK_E_NONE;
        }
        break;
    }
    return rv;
}

/**节能以太网的设置*/
int bmd_phy_eee_set(int unit, int lport, int mode)
{
    if (BMD_PORT_PHY_CTRL(unit, lport)) 
    {
        uint32_t eee_mode = PHY_EEE_NONE;
        int rv;
    
        if (!PHY_EXTERNAL_MODE(lport) && !PHY_EGPHY_MODE(lport)) 
        {
            /* serdes, set to no EEE */
            eee_mode = PHY_EEE_NONE;
        } 
        else if (mode == BMD_PHY_M_EEE_802_3) 
        {
            eee_mode = PHY_EEE_802_3;
        } 
        else if (mode == BMD_PHY_M_EEE_AUTO) 
        {
            eee_mode = PHY_EEE_AUTO;
        }
        rv = PHY_CONFIG_SET(BMD_PORT_PHY_CTRL(unit, lport),
                            PhyConfig_EEE, eee_mode, NULL);
        if (mode == PHY_EEE_NONE && rv == CDK_E_UNAVAIL) 
        {
            rv = CDK_E_NONE;
        }
        return rv;
    }
    return CDK_E_NONE;
}
/**获取PHY的节能以太网的状态
 * 
*/
int bmd_phy_eee_get(int unit, int lport, int *mode)
{
    *mode = PHY_EEE_NONE;

    if (BMD_PORT_PHY_CTRL(unit, lport)) {
        uint32_t eee_mode;
        int rv = PHY_CONFIG_GET(BMD_PORT_PHY_CTRL(unit, lport),
                                PhyConfig_EEE, &eee_mode, NULL);
        if (CDK_FAILURE(rv) && rv != CDK_E_UNAVAIL) {
            return rv;
        }
        if (eee_mode == PHY_EEE_802_3) {
            *mode = BMD_PHY_M_EEE_802_3;
        } else if (eee_mode == PHY_EEE_AUTO) {
            *mode = BMD_PHY_M_EEE_AUTO;
        }
    }
    return CDK_E_NONE;
}
/***/
int bmd_phy_laneswap_set(int unit, int lport)
{
    if (BMD_PORT_PHY_CTRL(unit, lport)) 
    {
        int rv;
        rv = PHY_CONFIG_SET(BMD_PORT_PHY_CTRL(unit, lport), PhyConfig_XauiTxLaneRemap, 0x3210, NULL);
        rv = PHY_CONFIG_SET(BMD_PORT_PHY_CTRL(unit, lport), PhyConfig_XauiRxLaneRemap, 0x0123, NULL);
        return rv;
    }
    return CDK_E_NONE;
}


typedef struct _bcast_sig_s {
    const char *drv_name;
    const char *bus_name;
    uint32_t addr;
} _bcast_sig_t;

#define MAX_BCAST_SIG   8
#define MAX_INIT_STAGE  8
/**PHY的状态的初始化*/
int bmd_phy_staged_init(int unit)
{
    int rv = CDK_E_NONE;
    int lport, idx, found;
    phy_ctrl_t *pc;
    uint32_t addr;
    _bcast_sig_t bcast_sig[MAX_BCAST_SIG];
    int num_sig, stage, done;

    num_sig = 0;
    SOC_LPORT_ITER(lport) 
    {
        pc = BMD_PORT_PHY_CTRL(unit, lport);
        for (; pc != NULL; pc = pc->next) 
        {
            /* Let driver know that staged init is being used */
            PHY_CTRL_FLAGS(pc) |= PHY_F_STAGED_INIT;
            /* Mark as broadcast slave by default */
            PHY_CTRL_FLAGS(pc) &= ~PHY_F_BCAST_MSTR;
            /* Get broadcast signature */
            rv = PHY_CONFIG_GET(pc, PhyConfig_BcastAddr, &addr, NULL);
            if (CDK_FAILURE(rv)) 
            {
                continue;
            }
            if (pc->drv == NULL ||  pc->drv->drv_name == NULL) 
            {
                continue;
            }
            if (pc->bus == NULL ||  pc->bus->drv_name == NULL) 
            {
                continue;
            }
            /* Check if broadcast signature exists */
            found = 0;
            for (idx = 0; idx < num_sig; idx++) 
            {
                if (bcast_sig[idx].drv_name == pc->drv->drv_name &&
                    bcast_sig[idx].bus_name == pc->bus->drv_name &&
                    bcast_sig[idx].addr == addr) 
                    {
                    found = 1;
                    break;
                }
            }
            if (found) 
            {
                continue;
            }
            if (idx >= MAX_BCAST_SIG) 
            {
                return CDK_E_FAIL;
            }
            /* Add new broadcast signature */
            bcast_sig[idx].drv_name = pc->drv->drv_name;
            bcast_sig[idx].bus_name = pc->bus->drv_name;
            bcast_sig[idx].addr = addr;
            CDK_VERB(("PHY init: new bcast sig: %s %s 0x%04x\n",
                      bcast_sig[idx].drv_name,
                      bcast_sig[idx].bus_name,
                      bcast_sig[idx].addr));
            num_sig++;
            /* Mark as master for this broadcast domain */
            PHY_CTRL_FLAGS(pc) |= PHY_F_BCAST_MSTR;
        }
    }

    /* Reset all PHYs */
    SOC_LPORT_ITER(lport) {
        pc = BMD_PORT_PHY_CTRL(unit, lport);
        if (pc == NULL) 
        {
            continue;
        }
        rv = PHY_RESET(pc);
        if (CDK_FAILURE(rv)) 
        {
            return rv;
        }
    }

    /* Perform reset callbacks */
    if (phy_reset_cb) {
        SOC_LPORT_ITER(lport) {
            pc = BMD_PORT_PHY_CTRL(unit, lport);
            if (pc == NULL) {
                continue;
            }
            rv = phy_reset_cb(pc);
            if (CDK_FAILURE(rv)) {
                return rv;
            }
        }
    }

    /* Repeat staged initialization until no more work */
    stage = 0;
    do {
        CDK_VERB(("PHY init: stage %d\n", stage));
        done = 1;
        SOC_LPORT_ITER(lport) {
            CDK_VVERB(("PHY init: stage %d, lport %d\n", stage, lport));

            pc = BMD_PORT_PHY_CTRL(unit, lport);
            for (; pc != NULL; pc = pc->next) {
                rv = PHY_CONFIG_SET(pc, PhyConfig_InitStage, stage, NULL);
                if (rv == CDK_E_UNAVAIL) {
                    /* Perform standard init if stage 0 is unsupported */
                    if (stage == 0) {
                        rv = PHY_INIT(pc);
                        if (CDK_FAILURE(rv)) {
                            return rv;
                        }
                        while (pc->next != NULL) {
                            pc = pc->next;
                        }
                    }
                    rv = CDK_E_NONE;
                    continue;
                }
                if (CDK_FAILURE(rv)) {
                    return rv;
                }
                done = 0;
            }
        }
        /* Add safety guard against loops */
        if (++stage > MAX_INIT_STAGE) {
            return CDK_E_INTERNAL;
        }
    } while (!done);

    /* Perform init callbacks */
    if (phy_init_cb) {
        SOC_LPORT_ITER(lport) {
            pc = BMD_PORT_PHY_CTRL(unit, lport);
            if (pc == NULL) {
                continue;
            }
            rv = phy_init_cb(pc);
            if (CDK_FAILURE(rv)) {
                return rv;
            }
        }
    }
    return rv;
}

extern int phy_brcm_xe_read(phy_ctrl_t *pc, uint32_t addr, uint32_t *data);
extern int phy_tsc_iblk_read(phy_ctrl_t *pc, uint32_t addr, uint32_t *data);

#define BCM54282_MII_ANPr             (0x00000005)
#define BCMI_TSC_XGXS_LP_BASE_PAGE1r  (0x0000c198)
#define BCMI_TSC_AN_ABIL_RESOLUTION_STATUSr  (0x0000c1ab)
#define SOC_PA_PAUSE_TX        (1 << 0)       /* TX pause capable */
#define SOC_PA_PAUSE_RX        (1 << 1)       /* RX pause capable */
/**获取PHY是否支持暂停*/
int phy_pause_get(uint8 unit, uint8 lport, BOOL *tx_pause, BOOL *rx_pause)
{
    int rv;
    phy_ctrl_t *pc = BMD_PORT_PHY_CTRL(unit, lport);
    uint32_t anp, remote_advert, local_advert = (SOC_PA_PAUSE_RX | SOC_PA_PAUSE_TX);

    PHY_CTRL_CHECK(pc);

    if (!sal_strcmp(pc->drv->drv_name,"bcmi_tsc_xgxs")) 
    {
        /* Assume CL73 AN Bit[11:10] */
        rv = phy_tsc_iblk_read(pc, BCMI_TSC_AN_ABIL_RESOLUTION_STATUSr, &anp);
    } 
    else 
    {
        rv = PHY_BUS_READ(pc, BCM54282_MII_ANPr, &anp);
    }

    if (CDK_FAILURE(rv)) 
    {
        PHY_WARN(pc, ("read remote ability failed!\n"));
        return rv;
    }

    switch (anp & (MII_ANA_PAUSE | MII_ANA_ASYM_PAUSE)) 
    {
        case MII_ANA_PAUSE:
            remote_advert = SOC_PA_PAUSE_TX | SOC_PA_PAUSE_RX;
            break;
        case MII_ANA_ASYM_PAUSE:
            remote_advert = SOC_PA_PAUSE_TX;
            break;
        case MII_ANA_PAUSE | MII_ANA_ASYM_PAUSE:
            remote_advert = SOC_PA_PAUSE_RX;
            break;
        default:
            remote_advert = 0;
            break;
    }


    /*
     * IEEE 802.3 Flow Control Resolution.
     * Please see $SDK/doc/pause-resolution.txt for more information.
     * Assume local always advertises PASUE and ASYM PAUSE.
     */
    *tx_pause =
            ((remote_advert & SOC_PA_PAUSE_RX) &&
             (local_advert & SOC_PA_PAUSE_RX)) ||
             ((remote_advert & SOC_PA_PAUSE_RX) &&
             !(remote_advert & SOC_PA_PAUSE_TX) &&
             (local_advert & SOC_PA_PAUSE_TX));

    *rx_pause =
             ((remote_advert & SOC_PA_PAUSE_RX) &&
             (local_advert & SOC_PA_PAUSE_RX)) ||
             ((local_advert & SOC_PA_PAUSE_RX) &&
             (remote_advert & SOC_PA_PAUSE_TX) &&
             !(local_advert & SOC_PA_PAUSE_TX));

    return(rv);
}

