#ifndef __BCM54282_DEFS_H__
#define __BCM54282_DEFS_H__
/*
 * $Id: bcm54282_defs.h,v 1.4 Broadcom SDK $
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
 * Definition file for the BCM54282.
 * This file provides all basic definitions required to program the BCM54282.
 *
 */

#include <phy/phy_brcm_rdb.h>
#include <phy/phy_brcm_shadow.h>
#include <phy/phy_brcm_1000x.h>
#include <phy/phy_aer_iblk.h>

/*******************************************************************************
 *
 *                    CHIP DEFINITIONS BEGIN HERE
 *
 ******************************************************************************/



/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_CTRL
 * BLOCKS:   IEEE
 * REGADDR:  0x0000
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T MII Control Register (Addr 00h)
 * SIZE:     32
 * FIELDS:
 *     RESERVED         Reserved..
 *     UNIDIRECTIONAL_EN Enable unidirectional mode.
 *     SPEED_SEL1       Speed selection (MSB).
 *     COLL_TEST_EN     Enable collision test mode.
 *     FULL_DUPLEX      Full duplex operation.
 *     RESTART_AN       Restart auto-negotiation.
 *     ISOLATE          Isolate PHY from GMII/RGMII/RTBI.
 *     POWER_DOWN       Power down.
 *     AUTONEG          Auto-negotiation enabled.
 *     SPEED_SEL0       Speed selection (LSB).
 *     LOOPBACK         Loopback mode.
 *     RESET            PHY reset.
 *	   	IEEE标准的控制寄存器
 ******************************************************************************/
//MII控制寄存器，定义控制寄存器的大小为4个字节
#define BCM54282_MII_CTRLr (0x00000000 | PHY_REG_ACC_RAW)

#define BCM54282_MII_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program MII_CTRL.
 *
 */
typedef union BCM54282_MII_CTRLr_s {
	uint32_t v[1];
	uint32_t mii_ctrl[1];
	uint32_t _mii_ctrl;
} BCM54282_MII_CTRLr_t;
//清除控制寄存器的值
#define BCM54282_MII_CTRLr_CLR(r) (r).mii_ctrl[0] = 0
//设置控制寄存器的值
#define BCM54282_MII_CTRLr_SET(r,d) (r).mii_ctrl[0] = d
//获取控制寄存器的值
#define BCM54282_MII_CTRLr_GET(r) (r).mii_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
//复位状态为
#define BCM54282_MII_CTRLr_RESETf_GET(r) ((((r).mii_ctrl[0]) >> 15) & 0x1)
#define BCM54282_MII_CTRLr_RESETf_SET(r,f) (r).mii_ctrl[0]=(((r).mii_ctrl[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
//内部环回
#define BCM54282_MII_CTRLr_LOOPBACKf_GET(r) ((((r).mii_ctrl[0]) >> 14) & 0x1)
#define BCM54282_MII_CTRLr_LOOPBACKf_SET(r,f) (r).mii_ctrl[0]=(((r).mii_ctrl[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
//速度选择
#define BCM54282_MII_CTRLr_SPEED_SEL0f_GET(r) ((((r).mii_ctrl[0]) >> 13) & 0x1)
#define BCM54282_MII_CTRLr_SPEED_SEL0f_SET(r,f) (r).mii_ctrl[0]=(((r).mii_ctrl[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
//自协商使能状态
#define BCM54282_MII_CTRLr_AUTONEGf_GET(r) ((((r).mii_ctrl[0]) >> 12) & 0x1)
#define BCM54282_MII_CTRLr_AUTONEGf_SET(r,f) (r).mii_ctrl[0]=(((r).mii_ctrl[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
//光口下电状态
#define BCM54282_MII_CTRLr_POWER_DOWNf_GET(r) ((((r).mii_ctrl[0]) >> 11) & 0x1)
#define BCM54282_MII_CTRLr_POWER_DOWNf_SET(r,f) (r).mii_ctrl[0]=(((r).mii_ctrl[0] & ~((uint32_t)0x1 << 11)) | ((((uint32_t)f) & 0x1) << 11))
//隔离状态
#define BCM54282_MII_CTRLr_ISOLATEf_GET(r) ((((r).mii_ctrl[0]) >> 10) & 0x1)
#define BCM54282_MII_CTRLr_ISOLATEf_SET(r,f) (r).mii_ctrl[0]=(((r).mii_ctrl[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))
//端口重新自协商
#define BCM54282_MII_CTRLr_RESTART_ANf_GET(r) ((((r).mii_ctrl[0]) >> 9) & 0x1)
#define BCM54282_MII_CTRLr_RESTART_ANf_SET(r,f) (r).mii_ctrl[0]=(((r).mii_ctrl[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
//双工模式
#define BCM54282_MII_CTRLr_FULL_DUPLEXf_GET(r) ((((r).mii_ctrl[0]) >> 8) & 0x1)
#define BCM54282_MII_CTRLr_FULL_DUPLEXf_SET(r,f) (r).mii_ctrl[0]=(((r).mii_ctrl[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))
//速度选择的高位
#define BCM54282_MII_CTRLr_COLL_TEST_ENf_GET(r) ((((r).mii_ctrl[0]) >> 7) & 0x1)
#define BCM54282_MII_CTRLr_COLL_TEST_ENf_SET(r,f) (r).mii_ctrl[0]=(((r).mii_ctrl[0] & ~((uint32_t)0x1 << 7)) | ((((uint32_t)f) & 0x1) << 7))
//速度选择的高位
#define BCM54282_MII_CTRLr_SPEED_SEL1f_GET(r) ((((r).mii_ctrl[0]) >> 6) & 0x1)
#define BCM54282_MII_CTRLr_SPEED_SEL1f_SET(r,f) (r).mii_ctrl[0]=(((r).mii_ctrl[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))

#define BCM54282_MII_CTRLr_UNIDIRECTIONAL_ENf_GET(r) ((((r).mii_ctrl[0]) >> 5) & 0x1)
#define BCM54282_MII_CTRLr_UNIDIRECTIONAL_ENf_SET(r,f) (r).mii_ctrl[0]=(((r).mii_ctrl[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))

#define BCM54282_MII_CTRLr_RESERVEDf_GET(r) (((r).mii_ctrl[0]) & 0x1f)
#define BCM54282_MII_CTRLr_RESERVEDf_SET(r,f) (r).mii_ctrl[0]=(((r).mii_ctrl[0] & ~((uint32_t)0x1f)) | (((uint32_t)f) & 0x1f))

/*
 * These macros can be used to access MII_CTRL.
 *
 */
//读取寄存器0的值
#define BCM54282_READ_MII_CTRLr(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_CTRLr,_r._mii_ctrl)
//设置寄存器0的值
#define BCM54282_WRITE_MII_CTRLr(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_CTRLr,_r._mii_ctrl)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_CTRLr BCM54282_MII_CTRLr
#define MII_CTRLr_SIZE BCM54282_MII_CTRLr_SIZE
typedef BCM54282_MII_CTRLr_t MII_CTRLr_t;
#define MII_CTRLr_CLR BCM54282_MII_CTRLr_CLR
#define MII_CTRLr_SET BCM54282_MII_CTRLr_SET
#define MII_CTRLr_GET BCM54282_MII_CTRLr_GET
#define MII_CTRLr_RESETf_GET BCM54282_MII_CTRLr_RESETf_GET
#define MII_CTRLr_RESETf_SET BCM54282_MII_CTRLr_RESETf_SET
#define MII_CTRLr_LOOPBACKf_GET BCM54282_MII_CTRLr_LOOPBACKf_GET
#define MII_CTRLr_LOOPBACKf_SET BCM54282_MII_CTRLr_LOOPBACKf_SET
#define MII_CTRLr_SPEED_SEL0f_GET BCM54282_MII_CTRLr_SPEED_SEL0f_GET
#define MII_CTRLr_SPEED_SEL0f_SET BCM54282_MII_CTRLr_SPEED_SEL0f_SET
#define MII_CTRLr_AUTONEGf_GET BCM54282_MII_CTRLr_AUTONEGf_GET
#define MII_CTRLr_AUTONEGf_SET BCM54282_MII_CTRLr_AUTONEGf_SET
#define MII_CTRLr_POWER_DOWNf_GET BCM54282_MII_CTRLr_POWER_DOWNf_GET
#define MII_CTRLr_POWER_DOWNf_SET BCM54282_MII_CTRLr_POWER_DOWNf_SET
#define MII_CTRLr_ISOLATEf_GET BCM54282_MII_CTRLr_ISOLATEf_GET
#define MII_CTRLr_ISOLATEf_SET BCM54282_MII_CTRLr_ISOLATEf_SET
#define MII_CTRLr_RESTART_ANf_GET BCM54282_MII_CTRLr_RESTART_ANf_GET
#define MII_CTRLr_RESTART_ANf_SET BCM54282_MII_CTRLr_RESTART_ANf_SET
#define MII_CTRLr_FULL_DUPLEXf_GET BCM54282_MII_CTRLr_FULL_DUPLEXf_GET
#define MII_CTRLr_FULL_DUPLEXf_SET BCM54282_MII_CTRLr_FULL_DUPLEXf_SET
#define MII_CTRLr_COLL_TEST_ENf_GET BCM54282_MII_CTRLr_COLL_TEST_ENf_GET
#define MII_CTRLr_COLL_TEST_ENf_SET BCM54282_MII_CTRLr_COLL_TEST_ENf_SET
#define MII_CTRLr_SPEED_SEL1f_GET BCM54282_MII_CTRLr_SPEED_SEL1f_GET
#define MII_CTRLr_SPEED_SEL1f_SET BCM54282_MII_CTRLr_SPEED_SEL1f_SET
#define MII_CTRLr_UNIDIRECTIONAL_ENf_GET BCM54282_MII_CTRLr_UNIDIRECTIONAL_ENf_GET
#define MII_CTRLr_UNIDIRECTIONAL_ENf_SET BCM54282_MII_CTRLr_UNIDIRECTIONAL_ENf_SET
#define MII_CTRLr_RESERVEDf_GET BCM54282_MII_CTRLr_RESERVEDf_GET
#define MII_CTRLr_RESERVEDf_SET BCM54282_MII_CTRLr_RESERVEDf_SET
#define READ_MII_CTRLr BCM54282_READ_MII_CTRLr
#define WRITE_MII_CTRLr BCM54282_WRITE_MII_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_STAT
 * BLOCKS:   IEEE
 * REGADDR:  0x0001
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T MII Status Register (Addr 01h)
 * SIZE:     32
 * FIELDS:
 *     EXT_CAPABILITY   Extended register capabilities.
 *     JABBER_DETECT    Jabber condition detected.
 *     LINK             Link is up.
 *     AUTONEG_ABILITY  Auto-negotiation capable.
 *     REMOTE_FAULT     Remote fault detected.
 *     AUTONEG_DONE     Auto-negotiation complete.
 *     MF_PREAMBLE_SUP  Preamble can be suppressed.
 *     CAP_UNIDIRECTIONAL Extended status information in register 0Fh.
 *     EXT_STATUS       Extended status information in register 0Fh.
 *     CAP_100BASE_T2_HD 100BASE-T2 half-duplex capable.
 *     CAP_100BASE_T2_FD 100BASE-T2 full-duplex capable.
 *     CAP_10BASE_T_HD  10BASE-T half-duplex capable.
 *     CAP_10BASE_T_FD  10BASE-T full-duplex capable.
 *     CAP_100BASE_X_HD 100BASE-X half-duplex capable.
 *     CAP_100BASE_X_FD 100BASE-X full-duplex capable.
 *     CAP_100BASE_T4   100BASE-T4 capable.
 *		IEEE标准的状态寄存器
 ******************************************************************************/
//定义MII状态寄存器的值为1
#define BCM54282_MII_STATr (0x00000001 | PHY_REG_ACC_RAW)

#define BCM54282_MII_STATr_SIZE 4

/*
 * This structure should be used to declare and program MII_STAT.
 *
 */
typedef union BCM54282_MII_STATr_s {
	uint32_t v[1];
	uint32_t mii_stat[1];
	uint32_t _mii_stat;
} BCM54282_MII_STATr_t;

#define BCM54282_MII_STATr_CLR(r) (r).mii_stat[0] = 0
#define BCM54282_MII_STATr_SET(r,d) (r).mii_stat[0] = d
#define BCM54282_MII_STATr_GET(r) (r).mii_stat[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_STATr_CAP_100BASE_T4f_GET(r) ((((r).mii_stat[0]) >> 15) & 0x1)
#define BCM54282_MII_STATr_CAP_100BASE_T4f_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_STATr_CAP_100BASE_X_FDf_GET(r) ((((r).mii_stat[0]) >> 14) & 0x1)
#define BCM54282_MII_STATr_CAP_100BASE_X_FDf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_MII_STATr_CAP_100BASE_X_HDf_GET(r) ((((r).mii_stat[0]) >> 13) & 0x1)
#define BCM54282_MII_STATr_CAP_100BASE_X_HDf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_MII_STATr_CAP_10BASE_T_FDf_GET(r) ((((r).mii_stat[0]) >> 12) & 0x1)
#define BCM54282_MII_STATr_CAP_10BASE_T_FDf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_MII_STATr_CAP_10BASE_T_HDf_GET(r) ((((r).mii_stat[0]) >> 11) & 0x1)
#define BCM54282_MII_STATr_CAP_10BASE_T_HDf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 11)) | ((((uint32_t)f) & 0x1) << 11))
#define BCM54282_MII_STATr_CAP_100BASE_T2_FDf_GET(r) ((((r).mii_stat[0]) >> 10) & 0x1)
#define BCM54282_MII_STATr_CAP_100BASE_T2_FDf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))
#define BCM54282_MII_STATr_CAP_100BASE_T2_HDf_GET(r) ((((r).mii_stat[0]) >> 9) & 0x1)
#define BCM54282_MII_STATr_CAP_100BASE_T2_HDf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
#define BCM54282_MII_STATr_EXT_STATUSf_GET(r) ((((r).mii_stat[0]) >> 8) & 0x1)
#define BCM54282_MII_STATr_EXT_STATUSf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))
#define BCM54282_MII_STATr_CAP_UNIDIRECTIONALf_GET(r) ((((r).mii_stat[0]) >> 7) & 0x1)
#define BCM54282_MII_STATr_CAP_UNIDIRECTIONALf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 7)) | ((((uint32_t)f) & 0x1) << 7))
#define BCM54282_MII_STATr_MF_PREAMBLE_SUPf_GET(r) ((((r).mii_stat[0]) >> 6) & 0x1)
#define BCM54282_MII_STATr_MF_PREAMBLE_SUPf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))
#define BCM54282_MII_STATr_AUTONEG_DONEf_GET(r) ((((r).mii_stat[0]) >> 5) & 0x1)
#define BCM54282_MII_STATr_AUTONEG_DONEf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))
#define BCM54282_MII_STATr_REMOTE_FAULTf_GET(r) ((((r).mii_stat[0]) >> 4) & 0x1)
#define BCM54282_MII_STATr_REMOTE_FAULTf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 4)) | ((((uint32_t)f) & 0x1) << 4))
#define BCM54282_MII_STATr_AUTONEG_ABILITYf_GET(r) ((((r).mii_stat[0]) >> 3) & 0x1)
#define BCM54282_MII_STATr_AUTONEG_ABILITYf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 3)) | ((((uint32_t)f) & 0x1) << 3))
#define BCM54282_MII_STATr_LINKf_GET(r) ((((r).mii_stat[0]) >> 2) & 0x1)
#define BCM54282_MII_STATr_LINKf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_STATr_JABBER_DETECTf_GET(r) ((((r).mii_stat[0]) >> 1) & 0x1)
#define BCM54282_MII_STATr_JABBER_DETECTf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1 << 1)) | ((((uint32_t)f) & 0x1) << 1))
#define BCM54282_MII_STATr_EXT_CAPABILITYf_GET(r) (((r).mii_stat[0]) & 0x1)
#define BCM54282_MII_STATr_EXT_CAPABILITYf_SET(r,f) (r).mii_stat[0]=(((r).mii_stat[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_STAT.
 *
 */
#define BCM54282_READ_MII_STATr(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_STATr,_r._mii_stat)
#define BCM54282_WRITE_MII_STATr(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_STATr,_r._mii_stat)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_STATr BCM54282_MII_STATr
#define MII_STATr_SIZE BCM54282_MII_STATr_SIZE
typedef BCM54282_MII_STATr_t MII_STATr_t;
#define MII_STATr_CLR BCM54282_MII_STATr_CLR
#define MII_STATr_SET BCM54282_MII_STATr_SET
#define MII_STATr_GET BCM54282_MII_STATr_GET
#define MII_STATr_CAP_100BASE_T4f_GET BCM54282_MII_STATr_CAP_100BASE_T4f_GET
#define MII_STATr_CAP_100BASE_T4f_SET BCM54282_MII_STATr_CAP_100BASE_T4f_SET
#define MII_STATr_CAP_100BASE_X_FDf_GET BCM54282_MII_STATr_CAP_100BASE_X_FDf_GET
#define MII_STATr_CAP_100BASE_X_FDf_SET BCM54282_MII_STATr_CAP_100BASE_X_FDf_SET
#define MII_STATr_CAP_100BASE_X_HDf_GET BCM54282_MII_STATr_CAP_100BASE_X_HDf_GET
#define MII_STATr_CAP_100BASE_X_HDf_SET BCM54282_MII_STATr_CAP_100BASE_X_HDf_SET
#define MII_STATr_CAP_10BASE_T_FDf_GET BCM54282_MII_STATr_CAP_10BASE_T_FDf_GET
#define MII_STATr_CAP_10BASE_T_FDf_SET BCM54282_MII_STATr_CAP_10BASE_T_FDf_SET
#define MII_STATr_CAP_10BASE_T_HDf_GET BCM54282_MII_STATr_CAP_10BASE_T_HDf_GET
#define MII_STATr_CAP_10BASE_T_HDf_SET BCM54282_MII_STATr_CAP_10BASE_T_HDf_SET
#define MII_STATr_CAP_100BASE_T2_FDf_GET BCM54282_MII_STATr_CAP_100BASE_T2_FDf_GET
#define MII_STATr_CAP_100BASE_T2_FDf_SET BCM54282_MII_STATr_CAP_100BASE_T2_FDf_SET
#define MII_STATr_CAP_100BASE_T2_HDf_GET BCM54282_MII_STATr_CAP_100BASE_T2_HDf_GET
#define MII_STATr_CAP_100BASE_T2_HDf_SET BCM54282_MII_STATr_CAP_100BASE_T2_HDf_SET
#define MII_STATr_EXT_STATUSf_GET BCM54282_MII_STATr_EXT_STATUSf_GET
#define MII_STATr_EXT_STATUSf_SET BCM54282_MII_STATr_EXT_STATUSf_SET
#define MII_STATr_CAP_UNIDIRECTIONALf_GET BCM54282_MII_STATr_CAP_UNIDIRECTIONALf_GET
#define MII_STATr_CAP_UNIDIRECTIONALf_SET BCM54282_MII_STATr_CAP_UNIDIRECTIONALf_SET
#define MII_STATr_MF_PREAMBLE_SUPf_GET BCM54282_MII_STATr_MF_PREAMBLE_SUPf_GET
#define MII_STATr_MF_PREAMBLE_SUPf_SET BCM54282_MII_STATr_MF_PREAMBLE_SUPf_SET
#define MII_STATr_AUTONEG_DONEf_GET BCM54282_MII_STATr_AUTONEG_DONEf_GET
#define MII_STATr_AUTONEG_DONEf_SET BCM54282_MII_STATr_AUTONEG_DONEf_SET
#define MII_STATr_REMOTE_FAULTf_GET BCM54282_MII_STATr_REMOTE_FAULTf_GET
#define MII_STATr_REMOTE_FAULTf_SET BCM54282_MII_STATr_REMOTE_FAULTf_SET
#define MII_STATr_AUTONEG_ABILITYf_GET BCM54282_MII_STATr_AUTONEG_ABILITYf_GET
#define MII_STATr_AUTONEG_ABILITYf_SET BCM54282_MII_STATr_AUTONEG_ABILITYf_SET
#define MII_STATr_LINKf_GET BCM54282_MII_STATr_LINKf_GET
#define MII_STATr_LINKf_SET BCM54282_MII_STATr_LINKf_SET
#define MII_STATr_JABBER_DETECTf_GET BCM54282_MII_STATr_JABBER_DETECTf_GET
#define MII_STATr_JABBER_DETECTf_SET BCM54282_MII_STATr_JABBER_DETECTf_SET
#define MII_STATr_EXT_CAPABILITYf_GET BCM54282_MII_STATr_EXT_CAPABILITYf_GET
#define MII_STATr_EXT_CAPABILITYf_SET BCM54282_MII_STATr_EXT_CAPABILITYf_SET
#define READ_MII_STATr BCM54282_READ_MII_STATr
#define WRITE_MII_STATr BCM54282_WRITE_MII_STATr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_STATr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_PHY_ID0
 * BLOCKS:   IEEE
 * REGADDR:  0x0002
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T PHY Identifier Register (Addr 02h)
 * SIZE:     32
 * FIELDS:
 *     REGID            16 MSBs of PHY identifier.
 * IEEE标准的生产厂商的高位
 ******************************************************************************/
//定义MII寄存器2为芯片OUI高位寄存器
#define BCM54282_MII_PHY_ID0r (0x00000002 | PHY_REG_ACC_RAW)

#define BCM54282_MII_PHY_ID0r_SIZE 4

/*
 * This structure should be used to declare and program MII_PHY_ID0.
 *
 */
typedef union BCM54282_MII_PHY_ID0r_s {
	uint32_t v[1];
	uint32_t mii_phy_id0[1];
	uint32_t _mii_phy_id0;
} BCM54282_MII_PHY_ID0r_t;

#define BCM54282_MII_PHY_ID0r_CLR(r) (r).mii_phy_id0[0] = 0
#define BCM54282_MII_PHY_ID0r_SET(r,d) (r).mii_phy_id0[0] = d
#define BCM54282_MII_PHY_ID0r_GET(r) (r).mii_phy_id0[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_PHY_ID0r_REGIDf_GET(r) (((r).mii_phy_id0[0]) & 0xffff)
#define BCM54282_MII_PHY_ID0r_REGIDf_SET(r,f) (r).mii_phy_id0[0]=(((r).mii_phy_id0[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access MII_PHY_ID0.
 *
 */
#define BCM54282_READ_MII_PHY_ID0r(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_PHY_ID0r,_r._mii_phy_id0)
#define BCM54282_WRITE_MII_PHY_ID0r(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_PHY_ID0r,_r._mii_phy_id0)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_PHY_ID0r BCM54282_MII_PHY_ID0r
#define MII_PHY_ID0r_SIZE BCM54282_MII_PHY_ID0r_SIZE
typedef BCM54282_MII_PHY_ID0r_t MII_PHY_ID0r_t;
#define MII_PHY_ID0r_CLR BCM54282_MII_PHY_ID0r_CLR
#define MII_PHY_ID0r_SET BCM54282_MII_PHY_ID0r_SET
#define MII_PHY_ID0r_GET BCM54282_MII_PHY_ID0r_GET
#define MII_PHY_ID0r_REGIDf_GET BCM54282_MII_PHY_ID0r_REGIDf_GET
#define MII_PHY_ID0r_REGIDf_SET BCM54282_MII_PHY_ID0r_REGIDf_SET
#define READ_MII_PHY_ID0r BCM54282_READ_MII_PHY_ID0r
#define WRITE_MII_PHY_ID0r BCM54282_WRITE_MII_PHY_ID0r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_PHY_ID0r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_PHY_ID1
 * BLOCKS:   IEEE
 * REGADDR:  0x0003
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T PHY Identifier Register (Addr 03h)
 * SIZE:     32
 * FIELDS:
 *     REGID            16 LSBs of PHY identifier.
 *		IEEE标准的生产厂商低位
 ******************************************************************************/
//定义寄存器3位芯片OUI低位
#define BCM54282_MII_PHY_ID1r (0x00000003 | PHY_REG_ACC_RAW)

#define BCM54282_MII_PHY_ID1r_SIZE 4

/*
 * This structure should be used to declare and program MII_PHY_ID1.
 *
 */
typedef union BCM54282_MII_PHY_ID1r_s {
	uint32_t v[1];
	uint32_t mii_phy_id1[1];
	uint32_t _mii_phy_id1;
} BCM54282_MII_PHY_ID1r_t;

#define BCM54282_MII_PHY_ID1r_CLR(r) (r).mii_phy_id1[0] = 0
#define BCM54282_MII_PHY_ID1r_SET(r,d) (r).mii_phy_id1[0] = d
#define BCM54282_MII_PHY_ID1r_GET(r) (r).mii_phy_id1[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_PHY_ID1r_REGIDf_GET(r) (((r).mii_phy_id1[0]) & 0xffff)
#define BCM54282_MII_PHY_ID1r_REGIDf_SET(r,f) (r).mii_phy_id1[0]=(((r).mii_phy_id1[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access MII_PHY_ID1.
 *
 */
#define BCM54282_READ_MII_PHY_ID1r(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_PHY_ID1r,_r._mii_phy_id1)
#define BCM54282_WRITE_MII_PHY_ID1r(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_PHY_ID1r,_r._mii_phy_id1)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_PHY_ID1r BCM54282_MII_PHY_ID1r
#define MII_PHY_ID1r_SIZE BCM54282_MII_PHY_ID1r_SIZE
typedef BCM54282_MII_PHY_ID1r_t MII_PHY_ID1r_t;
#define MII_PHY_ID1r_CLR BCM54282_MII_PHY_ID1r_CLR
#define MII_PHY_ID1r_SET BCM54282_MII_PHY_ID1r_SET
#define MII_PHY_ID1r_GET BCM54282_MII_PHY_ID1r_GET
#define MII_PHY_ID1r_REGIDf_GET BCM54282_MII_PHY_ID1r_REGIDf_GET
#define MII_PHY_ID1r_REGIDf_SET BCM54282_MII_PHY_ID1r_REGIDf_SET
#define READ_MII_PHY_ID1r BCM54282_READ_MII_PHY_ID1r
#define WRITE_MII_PHY_ID1r BCM54282_WRITE_MII_PHY_ID1r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_PHY_ID1r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_ANA
 * BLOCKS:   IEEE
 * REGADDR:  0x0004
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T Auto-Negotiation Advertisment Register (Addr 04h)
 * SIZE:     32
 * FIELDS:
 *     PROTOCOL         Advertise protocol selector field.
 *     CAP_10BASE_T_HD  10BASE-T half-duplex capable.
 *     CAP_10BASE_T_FD  10BASE-T full-duplex capable.
 *     CAP_100BASE_TX_HD 100BASE-TX half-duplex capable.
 *     CAP_100BASE_TX_FD 100BASE-TX full-duplex capable.
 *     CAP_100BASE_T4   100BASE-T4 capable.
 *     PAUSE            Pause capable.
 *     ASYM_PAUSE       Advertise asymmetric pause.
 *     REMOTE_FAULT     Advertise remote fault detected.
 *     NEXT_PAGE        Next Page ability supported.
 *	IEEE标准的自协商宣传寄存器
 ******************************************************************************/
//定义寄存器4，寄存器4位自协商适配寄存器
#define BCM54282_MII_ANAr (0x00000004 | PHY_REG_ACC_RAW)

#define BCM54282_MII_ANAr_SIZE 4

/*
 * This structure should be used to declare and program MII_ANA.
 *
 */
typedef union BCM54282_MII_ANAr_s {
	uint32_t v[1];
	uint32_t mii_ana[1];
	uint32_t _mii_ana;
} BCM54282_MII_ANAr_t;

#define BCM54282_MII_ANAr_CLR(r) (r).mii_ana[0] = 0
#define BCM54282_MII_ANAr_SET(r,d) (r).mii_ana[0] = d
#define BCM54282_MII_ANAr_GET(r) (r).mii_ana[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_ANAr_NEXT_PAGEf_GET(r) ((((r).mii_ana[0]) >> 15) & 0x1)
#define BCM54282_MII_ANAr_NEXT_PAGEf_SET(r,f) (r).mii_ana[0]=(((r).mii_ana[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_ANAr_REMOTE_FAULTf_GET(r) ((((r).mii_ana[0]) >> 13) & 0x1)
#define BCM54282_MII_ANAr_REMOTE_FAULTf_SET(r,f) (r).mii_ana[0]=(((r).mii_ana[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_MII_ANAr_ASYM_PAUSEf_GET(r) ((((r).mii_ana[0]) >> 11) & 0x1)
#define BCM54282_MII_ANAr_ASYM_PAUSEf_SET(r,f) (r).mii_ana[0]=(((r).mii_ana[0] & ~((uint32_t)0x1 << 11)) | ((((uint32_t)f) & 0x1) << 11))
#define BCM54282_MII_ANAr_PAUSEf_GET(r) ((((r).mii_ana[0]) >> 10) & 0x1)
#define BCM54282_MII_ANAr_PAUSEf_SET(r,f) (r).mii_ana[0]=(((r).mii_ana[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))
#define BCM54282_MII_ANAr_CAP_100BASE_T4f_GET(r) ((((r).mii_ana[0]) >> 9) & 0x1)
#define BCM54282_MII_ANAr_CAP_100BASE_T4f_SET(r,f) (r).mii_ana[0]=(((r).mii_ana[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
#define BCM54282_MII_ANAr_CAP_100BASE_TX_FDf_GET(r) ((((r).mii_ana[0]) >> 8) & 0x1)
#define BCM54282_MII_ANAr_CAP_100BASE_TX_FDf_SET(r,f) (r).mii_ana[0]=(((r).mii_ana[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))
#define BCM54282_MII_ANAr_CAP_100BASE_TX_HDf_GET(r) ((((r).mii_ana[0]) >> 7) & 0x1)
#define BCM54282_MII_ANAr_CAP_100BASE_TX_HDf_SET(r,f) (r).mii_ana[0]=(((r).mii_ana[0] & ~((uint32_t)0x1 << 7)) | ((((uint32_t)f) & 0x1) << 7))
#define BCM54282_MII_ANAr_CAP_10BASE_T_FDf_GET(r) ((((r).mii_ana[0]) >> 6) & 0x1)
#define BCM54282_MII_ANAr_CAP_10BASE_T_FDf_SET(r,f) (r).mii_ana[0]=(((r).mii_ana[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))
#define BCM54282_MII_ANAr_CAP_10BASE_T_HDf_GET(r) ((((r).mii_ana[0]) >> 5) & 0x1)
#define BCM54282_MII_ANAr_CAP_10BASE_T_HDf_SET(r,f) (r).mii_ana[0]=(((r).mii_ana[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))
#define BCM54282_MII_ANAr_PROTOCOLf_GET(r) (((r).mii_ana[0]) & 0x1f)
#define BCM54282_MII_ANAr_PROTOCOLf_SET(r,f) (r).mii_ana[0]=(((r).mii_ana[0] & ~((uint32_t)0x1f)) | (((uint32_t)f) & 0x1f))

/*
 * These macros can be used to access MII_ANA.
 *
 */
#define BCM54282_READ_MII_ANAr(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_ANAr,_r._mii_ana)
#define BCM54282_WRITE_MII_ANAr(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_ANAr,_r._mii_ana)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_ANAr BCM54282_MII_ANAr
#define MII_ANAr_SIZE BCM54282_MII_ANAr_SIZE
typedef BCM54282_MII_ANAr_t MII_ANAr_t;
#define MII_ANAr_CLR BCM54282_MII_ANAr_CLR
#define MII_ANAr_SET BCM54282_MII_ANAr_SET
#define MII_ANAr_GET BCM54282_MII_ANAr_GET
#define MII_ANAr_NEXT_PAGEf_GET BCM54282_MII_ANAr_NEXT_PAGEf_GET
#define MII_ANAr_NEXT_PAGEf_SET BCM54282_MII_ANAr_NEXT_PAGEf_SET
#define MII_ANAr_REMOTE_FAULTf_GET BCM54282_MII_ANAr_REMOTE_FAULTf_GET
#define MII_ANAr_REMOTE_FAULTf_SET BCM54282_MII_ANAr_REMOTE_FAULTf_SET
#define MII_ANAr_ASYM_PAUSEf_GET BCM54282_MII_ANAr_ASYM_PAUSEf_GET
#define MII_ANAr_ASYM_PAUSEf_SET BCM54282_MII_ANAr_ASYM_PAUSEf_SET
#define MII_ANAr_PAUSEf_GET BCM54282_MII_ANAr_PAUSEf_GET
#define MII_ANAr_PAUSEf_SET BCM54282_MII_ANAr_PAUSEf_SET
#define MII_ANAr_CAP_100BASE_T4f_GET BCM54282_MII_ANAr_CAP_100BASE_T4f_GET
#define MII_ANAr_CAP_100BASE_T4f_SET BCM54282_MII_ANAr_CAP_100BASE_T4f_SET
#define MII_ANAr_CAP_100BASE_TX_FDf_GET BCM54282_MII_ANAr_CAP_100BASE_TX_FDf_GET
#define MII_ANAr_CAP_100BASE_TX_FDf_SET BCM54282_MII_ANAr_CAP_100BASE_TX_FDf_SET
#define MII_ANAr_CAP_100BASE_TX_HDf_GET BCM54282_MII_ANAr_CAP_100BASE_TX_HDf_GET
#define MII_ANAr_CAP_100BASE_TX_HDf_SET BCM54282_MII_ANAr_CAP_100BASE_TX_HDf_SET
#define MII_ANAr_CAP_10BASE_T_FDf_GET BCM54282_MII_ANAr_CAP_10BASE_T_FDf_GET
#define MII_ANAr_CAP_10BASE_T_FDf_SET BCM54282_MII_ANAr_CAP_10BASE_T_FDf_SET
#define MII_ANAr_CAP_10BASE_T_HDf_GET BCM54282_MII_ANAr_CAP_10BASE_T_HDf_GET
#define MII_ANAr_CAP_10BASE_T_HDf_SET BCM54282_MII_ANAr_CAP_10BASE_T_HDf_SET
#define MII_ANAr_PROTOCOLf_GET BCM54282_MII_ANAr_PROTOCOLf_GET
#define MII_ANAr_PROTOCOLf_SET BCM54282_MII_ANAr_PROTOCOLf_SET
#define READ_MII_ANAr BCM54282_READ_MII_ANAr
#define WRITE_MII_ANAr BCM54282_WRITE_MII_ANAr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_ANAr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_ANP
 * BLOCKS:   IEEE
 * REGADDR:  0x0005
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T Auto-Negotiation Link Partner Ability (Addr 05h)
 * SIZE:     32
 * FIELDS:
 *     PROTOCOL         Link partner is protocol selector field.
 *     CAP_10BASE_T_HD  Link partner is 10BASE-T half-duplex capable.
 *     CAP_10BASE_T_FD  Link partner is 10BASE-T full-duplex capable.
 *     CAP_100BASE_TX_HD Link partner is 100BASE-TX half-duplex capable.
 *     CAP_100BASE_TX_FD Link partner is 100BASE-TX full-duplex capable.
 *     CAP_100BASE_T4   Link partner is 100BASE-T4 capable.
 *     PAUSE            Link partner is capable of pause operation.
 *     ASYM_PAUSE       Link partner wants asymmetric pause.
 *     REMOTE_FAULT     Link partner has detected remote fault.
 *     ACK              Link partner has received link code word.
 *     NEXT_PAGE        Link partner has Next Page ability.
 *		IEEE标准的自协商对端的能力
 ******************************************************************************/
//定义寄存器5 为自适应连接伙伴能力寄存器
#define BCM54282_MII_ANPr (0x00000005 | PHY_REG_ACC_RAW)

#define BCM54282_MII_ANPr_SIZE 4

/*
 * This structure should be used to declare and program MII_ANP.
 *
 */
typedef union BCM54282_MII_ANPr_s {
	uint32_t v[1];
	uint32_t mii_anp[1];
	uint32_t _mii_anp;
} BCM54282_MII_ANPr_t;

#define BCM54282_MII_ANPr_CLR(r) (r).mii_anp[0] = 0
#define BCM54282_MII_ANPr_SET(r,d) (r).mii_anp[0] = d
#define BCM54282_MII_ANPr_GET(r) (r).mii_anp[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_ANPr_NEXT_PAGEf_GET(r) ((((r).mii_anp[0]) >> 15) & 0x1)
#define BCM54282_MII_ANPr_NEXT_PAGEf_SET(r,f) (r).mii_anp[0]=(((r).mii_anp[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_ANPr_ACKf_GET(r) ((((r).mii_anp[0]) >> 14) & 0x1)
#define BCM54282_MII_ANPr_ACKf_SET(r,f) (r).mii_anp[0]=(((r).mii_anp[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_MII_ANPr_REMOTE_FAULTf_GET(r) ((((r).mii_anp[0]) >> 13) & 0x1)
#define BCM54282_MII_ANPr_REMOTE_FAULTf_SET(r,f) (r).mii_anp[0]=(((r).mii_anp[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_MII_ANPr_ASYM_PAUSEf_GET(r) ((((r).mii_anp[0]) >> 11) & 0x1)
#define BCM54282_MII_ANPr_ASYM_PAUSEf_SET(r,f) (r).mii_anp[0]=(((r).mii_anp[0] & ~((uint32_t)0x1 << 11)) | ((((uint32_t)f) & 0x1) << 11))
#define BCM54282_MII_ANPr_PAUSEf_GET(r) ((((r).mii_anp[0]) >> 10) & 0x1)
#define BCM54282_MII_ANPr_PAUSEf_SET(r,f) (r).mii_anp[0]=(((r).mii_anp[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))
#define BCM54282_MII_ANPr_CAP_100BASE_T4f_GET(r) ((((r).mii_anp[0]) >> 9) & 0x1)
#define BCM54282_MII_ANPr_CAP_100BASE_T4f_SET(r,f) (r).mii_anp[0]=(((r).mii_anp[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
#define BCM54282_MII_ANPr_CAP_100BASE_TX_FDf_GET(r) ((((r).mii_anp[0]) >> 8) & 0x1)
#define BCM54282_MII_ANPr_CAP_100BASE_TX_FDf_SET(r,f) (r).mii_anp[0]=(((r).mii_anp[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))
#define BCM54282_MII_ANPr_CAP_100BASE_TX_HDf_GET(r) ((((r).mii_anp[0]) >> 7) & 0x1)
#define BCM54282_MII_ANPr_CAP_100BASE_TX_HDf_SET(r,f) (r).mii_anp[0]=(((r).mii_anp[0] & ~((uint32_t)0x1 << 7)) | ((((uint32_t)f) & 0x1) << 7))
#define BCM54282_MII_ANPr_CAP_10BASE_T_FDf_GET(r) ((((r).mii_anp[0]) >> 6) & 0x1)
#define BCM54282_MII_ANPr_CAP_10BASE_T_FDf_SET(r,f) (r).mii_anp[0]=(((r).mii_anp[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))
#define BCM54282_MII_ANPr_CAP_10BASE_T_HDf_GET(r) ((((r).mii_anp[0]) >> 5) & 0x1)
#define BCM54282_MII_ANPr_CAP_10BASE_T_HDf_SET(r,f) (r).mii_anp[0]=(((r).mii_anp[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))
#define BCM54282_MII_ANPr_PROTOCOLf_GET(r) (((r).mii_anp[0]) & 0x1f)
#define BCM54282_MII_ANPr_PROTOCOLf_SET(r,f) (r).mii_anp[0]=(((r).mii_anp[0] & ~((uint32_t)0x1f)) | (((uint32_t)f) & 0x1f))

/*
 * These macros can be used to access MII_ANP.
 *
 */
#define BCM54282_READ_MII_ANPr(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_ANPr,_r._mii_anp)
#define BCM54282_WRITE_MII_ANPr(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_ANPr,_r._mii_anp)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_ANPr BCM54282_MII_ANPr
#define MII_ANPr_SIZE BCM54282_MII_ANPr_SIZE
typedef BCM54282_MII_ANPr_t MII_ANPr_t;
#define MII_ANPr_CLR BCM54282_MII_ANPr_CLR
#define MII_ANPr_SET BCM54282_MII_ANPr_SET
#define MII_ANPr_GET BCM54282_MII_ANPr_GET
#define MII_ANPr_NEXT_PAGEf_GET BCM54282_MII_ANPr_NEXT_PAGEf_GET
#define MII_ANPr_NEXT_PAGEf_SET BCM54282_MII_ANPr_NEXT_PAGEf_SET
#define MII_ANPr_ACKf_GET BCM54282_MII_ANPr_ACKf_GET
#define MII_ANPr_ACKf_SET BCM54282_MII_ANPr_ACKf_SET
#define MII_ANPr_REMOTE_FAULTf_GET BCM54282_MII_ANPr_REMOTE_FAULTf_GET
#define MII_ANPr_REMOTE_FAULTf_SET BCM54282_MII_ANPr_REMOTE_FAULTf_SET
#define MII_ANPr_ASYM_PAUSEf_GET BCM54282_MII_ANPr_ASYM_PAUSEf_GET
#define MII_ANPr_ASYM_PAUSEf_SET BCM54282_MII_ANPr_ASYM_PAUSEf_SET
#define MII_ANPr_PAUSEf_GET BCM54282_MII_ANPr_PAUSEf_GET
#define MII_ANPr_PAUSEf_SET BCM54282_MII_ANPr_PAUSEf_SET
#define MII_ANPr_CAP_100BASE_T4f_GET BCM54282_MII_ANPr_CAP_100BASE_T4f_GET
#define MII_ANPr_CAP_100BASE_T4f_SET BCM54282_MII_ANPr_CAP_100BASE_T4f_SET
#define MII_ANPr_CAP_100BASE_TX_FDf_GET BCM54282_MII_ANPr_CAP_100BASE_TX_FDf_GET
#define MII_ANPr_CAP_100BASE_TX_FDf_SET BCM54282_MII_ANPr_CAP_100BASE_TX_FDf_SET
#define MII_ANPr_CAP_100BASE_TX_HDf_GET BCM54282_MII_ANPr_CAP_100BASE_TX_HDf_GET
#define MII_ANPr_CAP_100BASE_TX_HDf_SET BCM54282_MII_ANPr_CAP_100BASE_TX_HDf_SET
#define MII_ANPr_CAP_10BASE_T_FDf_GET BCM54282_MII_ANPr_CAP_10BASE_T_FDf_GET
#define MII_ANPr_CAP_10BASE_T_FDf_SET BCM54282_MII_ANPr_CAP_10BASE_T_FDf_SET
#define MII_ANPr_CAP_10BASE_T_HDf_GET BCM54282_MII_ANPr_CAP_10BASE_T_HDf_GET
#define MII_ANPr_CAP_10BASE_T_HDf_SET BCM54282_MII_ANPr_CAP_10BASE_T_HDf_SET
#define MII_ANPr_PROTOCOLf_GET BCM54282_MII_ANPr_PROTOCOLf_GET
#define MII_ANPr_PROTOCOLf_SET BCM54282_MII_ANPr_PROTOCOLf_SET
#define READ_MII_ANPr BCM54282_READ_MII_ANPr
#define WRITE_MII_ANPr BCM54282_WRITE_MII_ANPr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_ANPr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_AN_EXP
 * BLOCKS:   IEEE
 * REGADDR:  0x0006
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T Auto-Negotiation Expansion Register (Addr 06h)
 * SIZE:     32
 * FIELDS:
 *     LP_AN_ABIL       Link partner has auto-negotiation ability.
 *     PAGE_RECEIVED    New page has been receive from link partner.
 *     NEXT_PAGE        Local Next Page capability.
 *     LP_NEXT_PAGE     Link partner has Next Page capability.
 *     PARDET_FAULT     Parallel link fault detected.
 *		IEEE标准的自协商扩展寄存器
 ******************************************************************************/
//寄存器6位自适应扩展寄存器
#define BCM54282_MII_AN_EXPr (0x00000006 | PHY_REG_ACC_RAW)

#define BCM54282_MII_AN_EXPr_SIZE 4

/*
 * This structure should be used to declare and program MII_AN_EXP.
 *
 */
typedef union BCM54282_MII_AN_EXPr_s {
	uint32_t v[1];
	uint32_t mii_an_exp[1];
	uint32_t _mii_an_exp;
} BCM54282_MII_AN_EXPr_t;

#define BCM54282_MII_AN_EXPr_CLR(r) (r).mii_an_exp[0] = 0
#define BCM54282_MII_AN_EXPr_SET(r,d) (r).mii_an_exp[0] = d
#define BCM54282_MII_AN_EXPr_GET(r) (r).mii_an_exp[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_AN_EXPr_PARDET_FAULTf_GET(r) ((((r).mii_an_exp[0]) >> 4) & 0x1)
#define BCM54282_MII_AN_EXPr_PARDET_FAULTf_SET(r,f) (r).mii_an_exp[0]=(((r).mii_an_exp[0] & ~((uint32_t)0x1 << 4)) | ((((uint32_t)f) & 0x1) << 4))
#define BCM54282_MII_AN_EXPr_LP_NEXT_PAGEf_GET(r) ((((r).mii_an_exp[0]) >> 3) & 0x1)
#define BCM54282_MII_AN_EXPr_LP_NEXT_PAGEf_SET(r,f) (r).mii_an_exp[0]=(((r).mii_an_exp[0] & ~((uint32_t)0x1 << 3)) | ((((uint32_t)f) & 0x1) << 3))
#define BCM54282_MII_AN_EXPr_NEXT_PAGEf_GET(r) ((((r).mii_an_exp[0]) >> 2) & 0x1)
#define BCM54282_MII_AN_EXPr_NEXT_PAGEf_SET(r,f) (r).mii_an_exp[0]=(((r).mii_an_exp[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_AN_EXPr_PAGE_RECEIVEDf_GET(r) ((((r).mii_an_exp[0]) >> 1) & 0x1)
#define BCM54282_MII_AN_EXPr_PAGE_RECEIVEDf_SET(r,f) (r).mii_an_exp[0]=(((r).mii_an_exp[0] & ~((uint32_t)0x1 << 1)) | ((((uint32_t)f) & 0x1) << 1))
#define BCM54282_MII_AN_EXPr_LP_AN_ABILf_GET(r) (((r).mii_an_exp[0]) & 0x1)
#define BCM54282_MII_AN_EXPr_LP_AN_ABILf_SET(r,f) (r).mii_an_exp[0]=(((r).mii_an_exp[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_AN_EXP.
 *
 */
#define BCM54282_READ_MII_AN_EXPr(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_AN_EXPr,_r._mii_an_exp)
#define BCM54282_WRITE_MII_AN_EXPr(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_AN_EXPr,_r._mii_an_exp)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_AN_EXPr BCM54282_MII_AN_EXPr
#define MII_AN_EXPr_SIZE BCM54282_MII_AN_EXPr_SIZE
typedef BCM54282_MII_AN_EXPr_t MII_AN_EXPr_t;
#define MII_AN_EXPr_CLR BCM54282_MII_AN_EXPr_CLR
#define MII_AN_EXPr_SET BCM54282_MII_AN_EXPr_SET
#define MII_AN_EXPr_GET BCM54282_MII_AN_EXPr_GET
#define MII_AN_EXPr_PARDET_FAULTf_GET BCM54282_MII_AN_EXPr_PARDET_FAULTf_GET
#define MII_AN_EXPr_PARDET_FAULTf_SET BCM54282_MII_AN_EXPr_PARDET_FAULTf_SET
#define MII_AN_EXPr_LP_NEXT_PAGEf_GET BCM54282_MII_AN_EXPr_LP_NEXT_PAGEf_GET
#define MII_AN_EXPr_LP_NEXT_PAGEf_SET BCM54282_MII_AN_EXPr_LP_NEXT_PAGEf_SET
#define MII_AN_EXPr_NEXT_PAGEf_GET BCM54282_MII_AN_EXPr_NEXT_PAGEf_GET
#define MII_AN_EXPr_NEXT_PAGEf_SET BCM54282_MII_AN_EXPr_NEXT_PAGEf_SET
#define MII_AN_EXPr_PAGE_RECEIVEDf_GET BCM54282_MII_AN_EXPr_PAGE_RECEIVEDf_GET
#define MII_AN_EXPr_PAGE_RECEIVEDf_SET BCM54282_MII_AN_EXPr_PAGE_RECEIVEDf_SET
#define MII_AN_EXPr_LP_AN_ABILf_GET BCM54282_MII_AN_EXPr_LP_AN_ABILf_GET
#define MII_AN_EXPr_LP_AN_ABILf_SET BCM54282_MII_AN_EXPr_LP_AN_ABILf_SET
#define READ_MII_AN_EXPr BCM54282_READ_MII_AN_EXPr
#define WRITE_MII_AN_EXPr BCM54282_WRITE_MII_AN_EXPr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_AN_EXPr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_GB_CTRL
 * BLOCKS:   IEEE
 * REGADDR:  0x0009
 * DESC:     1000BASE-T Control Register (Addr 09h)
 * SIZE:     32
 * FIELDS:
 *     CAP_1000BASE_T_HD Advertise 1000BASE-T half-duplex capability.
 *     CAP_1000BASE_T_FD Advertise 1000BASE-T full-duplex capability.
 *     SWITCH_DEV       Repeater/DTE device mode.
 *     MASTER           Configure PHY as master.
 *     MS_MAN           Enable manual master/slave configuration.
 *     TEST_MODE        Test mode.
 *		IEEE标准的1000BASE-T控制寄存器
 ******************************************************************************/
//寄存器9 为1000BASE-T双工半双工能力寄存器
#define BCM54282_MII_GB_CTRLr (0x00000009 | PHY_REG_ACC_RAW)

#define BCM54282_MII_GB_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program MII_GB_CTRL.
 *
 */
typedef union BCM54282_MII_GB_CTRLr_s {
	uint32_t v[1];
	uint32_t mii_gb_ctrl[1];
	uint32_t _mii_gb_ctrl;
} BCM54282_MII_GB_CTRLr_t;

#define BCM54282_MII_GB_CTRLr_CLR(r) (r).mii_gb_ctrl[0] = 0
#define BCM54282_MII_GB_CTRLr_SET(r,d) (r).mii_gb_ctrl[0] = d
#define BCM54282_MII_GB_CTRLr_GET(r) (r).mii_gb_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_GB_CTRLr_TEST_MODEf_GET(r) ((((r).mii_gb_ctrl[0]) >> 13) & 0x7)
#define BCM54282_MII_GB_CTRLr_TEST_MODEf_SET(r,f) (r).mii_gb_ctrl[0]=(((r).mii_gb_ctrl[0] & ~((uint32_t)0x7 << 13)) | ((((uint32_t)f) & 0x7) << 13))
#define BCM54282_MII_GB_CTRLr_MS_MANf_GET(r) ((((r).mii_gb_ctrl[0]) >> 12) & 0x1)
#define BCM54282_MII_GB_CTRLr_MS_MANf_SET(r,f) (r).mii_gb_ctrl[0]=(((r).mii_gb_ctrl[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_MII_GB_CTRLr_MASTERf_GET(r) ((((r).mii_gb_ctrl[0]) >> 11) & 0x1)
#define BCM54282_MII_GB_CTRLr_MASTERf_SET(r,f) (r).mii_gb_ctrl[0]=(((r).mii_gb_ctrl[0] & ~((uint32_t)0x1 << 11)) | ((((uint32_t)f) & 0x1) << 11))
#define BCM54282_MII_GB_CTRLr_SWITCH_DEVf_GET(r) ((((r).mii_gb_ctrl[0]) >> 10) & 0x1)
#define BCM54282_MII_GB_CTRLr_SWITCH_DEVf_SET(r,f) (r).mii_gb_ctrl[0]=(((r).mii_gb_ctrl[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))
#define BCM54282_MII_GB_CTRLr_CAP_1000BASE_T_FDf_GET(r) ((((r).mii_gb_ctrl[0]) >> 9) & 0x1)
#define BCM54282_MII_GB_CTRLr_CAP_1000BASE_T_FDf_SET(r,f) (r).mii_gb_ctrl[0]=(((r).mii_gb_ctrl[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
#define BCM54282_MII_GB_CTRLr_CAP_1000BASE_T_HDf_GET(r) ((((r).mii_gb_ctrl[0]) >> 8) & 0x1)
#define BCM54282_MII_GB_CTRLr_CAP_1000BASE_T_HDf_SET(r,f) (r).mii_gb_ctrl[0]=(((r).mii_gb_ctrl[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))

/*
 * These macros can be used to access MII_GB_CTRL.
 *
 */
#define BCM54282_READ_MII_GB_CTRLr(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_GB_CTRLr,_r._mii_gb_ctrl)
#define BCM54282_WRITE_MII_GB_CTRLr(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_GB_CTRLr,_r._mii_gb_ctrl)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_GB_CTRLr BCM54282_MII_GB_CTRLr
#define MII_GB_CTRLr_SIZE BCM54282_MII_GB_CTRLr_SIZE
typedef BCM54282_MII_GB_CTRLr_t MII_GB_CTRLr_t;
#define MII_GB_CTRLr_CLR BCM54282_MII_GB_CTRLr_CLR
#define MII_GB_CTRLr_SET BCM54282_MII_GB_CTRLr_SET
#define MII_GB_CTRLr_GET BCM54282_MII_GB_CTRLr_GET
#define MII_GB_CTRLr_TEST_MODEf_GET BCM54282_MII_GB_CTRLr_TEST_MODEf_GET
#define MII_GB_CTRLr_TEST_MODEf_SET BCM54282_MII_GB_CTRLr_TEST_MODEf_SET
#define MII_GB_CTRLr_MS_MANf_GET BCM54282_MII_GB_CTRLr_MS_MANf_GET
#define MII_GB_CTRLr_MS_MANf_SET BCM54282_MII_GB_CTRLr_MS_MANf_SET
#define MII_GB_CTRLr_MASTERf_GET BCM54282_MII_GB_CTRLr_MASTERf_GET
#define MII_GB_CTRLr_MASTERf_SET BCM54282_MII_GB_CTRLr_MASTERf_SET
#define MII_GB_CTRLr_SWITCH_DEVf_GET BCM54282_MII_GB_CTRLr_SWITCH_DEVf_GET
#define MII_GB_CTRLr_SWITCH_DEVf_SET BCM54282_MII_GB_CTRLr_SWITCH_DEVf_SET
#define MII_GB_CTRLr_CAP_1000BASE_T_FDf_GET BCM54282_MII_GB_CTRLr_CAP_1000BASE_T_FDf_GET
#define MII_GB_CTRLr_CAP_1000BASE_T_FDf_SET BCM54282_MII_GB_CTRLr_CAP_1000BASE_T_FDf_SET
#define MII_GB_CTRLr_CAP_1000BASE_T_HDf_GET BCM54282_MII_GB_CTRLr_CAP_1000BASE_T_HDf_GET
#define MII_GB_CTRLr_CAP_1000BASE_T_HDf_SET BCM54282_MII_GB_CTRLr_CAP_1000BASE_T_HDf_SET
#define READ_MII_GB_CTRLr BCM54282_READ_MII_GB_CTRLr
#define WRITE_MII_GB_CTRLr BCM54282_WRITE_MII_GB_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_GB_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_GB_STAT
 * BLOCKS:   IEEE
 * REGADDR:  0x000a
 * DESC:     1000BASE-T Status Register (Addr 0Ah)
 * SIZE:     32
 * FIELDS:
 *     IDLE_ERRORS      Number of idle errors since last read.
 *     LP_1000BASE_T_HD Link partner is 1000BASE-T half-duplex capable.
 *     LP_1000BASE_T_FD Link partner is 1000BASE-T full-duplex capable.
 *     REMOTE_RCV_OK    Remote receiver OK.
 *     LOCAL_RCV_OK     Local receiver OK.
 *     LOCAL_MASTER     Local transmitter is master.
 *     MS_CFG_FAULT     Master/slave configuration fault detected.
 *		IEEE标准的1000BASE-T状态寄存器
 ******************************************************************************/
//寄存器10位
#define BCM54282_MII_GB_STATr (0x0000000a | PHY_REG_ACC_RAW)

#define BCM54282_MII_GB_STATr_SIZE 4

/*
 * This structure should be used to declare and program MII_GB_STAT.
 *
 */
typedef union BCM54282_MII_GB_STATr_s {
	uint32_t v[1];
	uint32_t mii_gb_stat[1];
	uint32_t _mii_gb_stat;
} BCM54282_MII_GB_STATr_t;

#define BCM54282_MII_GB_STATr_CLR(r) (r).mii_gb_stat[0] = 0
#define BCM54282_MII_GB_STATr_SET(r,d) (r).mii_gb_stat[0] = d
#define BCM54282_MII_GB_STATr_GET(r) (r).mii_gb_stat[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_GB_STATr_MS_CFG_FAULTf_GET(r) ((((r).mii_gb_stat[0]) >> 15) & 0x1)
#define BCM54282_MII_GB_STATr_MS_CFG_FAULTf_SET(r,f) (r).mii_gb_stat[0]=(((r).mii_gb_stat[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_GB_STATr_LOCAL_MASTERf_GET(r) ((((r).mii_gb_stat[0]) >> 14) & 0x1)
#define BCM54282_MII_GB_STATr_LOCAL_MASTERf_SET(r,f) (r).mii_gb_stat[0]=(((r).mii_gb_stat[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_MII_GB_STATr_LOCAL_RCV_OKf_GET(r) ((((r).mii_gb_stat[0]) >> 13) & 0x1)
#define BCM54282_MII_GB_STATr_LOCAL_RCV_OKf_SET(r,f) (r).mii_gb_stat[0]=(((r).mii_gb_stat[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_MII_GB_STATr_REMOTE_RCV_OKf_GET(r) ((((r).mii_gb_stat[0]) >> 12) & 0x1)
#define BCM54282_MII_GB_STATr_REMOTE_RCV_OKf_SET(r,f) (r).mii_gb_stat[0]=(((r).mii_gb_stat[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_MII_GB_STATr_LP_1000BASE_T_FDf_GET(r) ((((r).mii_gb_stat[0]) >> 11) & 0x1)
#define BCM54282_MII_GB_STATr_LP_1000BASE_T_FDf_SET(r,f) (r).mii_gb_stat[0]=(((r).mii_gb_stat[0] & ~((uint32_t)0x1 << 11)) | ((((uint32_t)f) & 0x1) << 11))
#define BCM54282_MII_GB_STATr_LP_1000BASE_T_HDf_GET(r) ((((r).mii_gb_stat[0]) >> 10) & 0x1)
#define BCM54282_MII_GB_STATr_LP_1000BASE_T_HDf_SET(r,f) (r).mii_gb_stat[0]=(((r).mii_gb_stat[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))
#define BCM54282_MII_GB_STATr_IDLE_ERRORSf_GET(r) (((r).mii_gb_stat[0]) & 0xff)
#define BCM54282_MII_GB_STATr_IDLE_ERRORSf_SET(r,f) (r).mii_gb_stat[0]=(((r).mii_gb_stat[0] & ~((uint32_t)0xff)) | (((uint32_t)f) & 0xff))

/*
 * These macros can be used to access MII_GB_STAT.
 *
 */
#define BCM54282_READ_MII_GB_STATr(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_GB_STATr,_r._mii_gb_stat)
#define BCM54282_WRITE_MII_GB_STATr(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_GB_STATr,_r._mii_gb_stat)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_GB_STATr BCM54282_MII_GB_STATr
#define MII_GB_STATr_SIZE BCM54282_MII_GB_STATr_SIZE
typedef BCM54282_MII_GB_STATr_t MII_GB_STATr_t;
#define MII_GB_STATr_CLR BCM54282_MII_GB_STATr_CLR
#define MII_GB_STATr_SET BCM54282_MII_GB_STATr_SET
#define MII_GB_STATr_GET BCM54282_MII_GB_STATr_GET
#define MII_GB_STATr_MS_CFG_FAULTf_GET BCM54282_MII_GB_STATr_MS_CFG_FAULTf_GET
#define MII_GB_STATr_MS_CFG_FAULTf_SET BCM54282_MII_GB_STATr_MS_CFG_FAULTf_SET
#define MII_GB_STATr_LOCAL_MASTERf_GET BCM54282_MII_GB_STATr_LOCAL_MASTERf_GET
#define MII_GB_STATr_LOCAL_MASTERf_SET BCM54282_MII_GB_STATr_LOCAL_MASTERf_SET
#define MII_GB_STATr_LOCAL_RCV_OKf_GET BCM54282_MII_GB_STATr_LOCAL_RCV_OKf_GET
#define MII_GB_STATr_LOCAL_RCV_OKf_SET BCM54282_MII_GB_STATr_LOCAL_RCV_OKf_SET
#define MII_GB_STATr_REMOTE_RCV_OKf_GET BCM54282_MII_GB_STATr_REMOTE_RCV_OKf_GET
#define MII_GB_STATr_REMOTE_RCV_OKf_SET BCM54282_MII_GB_STATr_REMOTE_RCV_OKf_SET
#define MII_GB_STATr_LP_1000BASE_T_FDf_GET BCM54282_MII_GB_STATr_LP_1000BASE_T_FDf_GET
#define MII_GB_STATr_LP_1000BASE_T_FDf_SET BCM54282_MII_GB_STATr_LP_1000BASE_T_FDf_SET
#define MII_GB_STATr_LP_1000BASE_T_HDf_GET BCM54282_MII_GB_STATr_LP_1000BASE_T_HDf_GET
#define MII_GB_STATr_LP_1000BASE_T_HDf_SET BCM54282_MII_GB_STATr_LP_1000BASE_T_HDf_SET
#define MII_GB_STATr_IDLE_ERRORSf_GET BCM54282_MII_GB_STATr_IDLE_ERRORSf_GET
#define MII_GB_STATr_IDLE_ERRORSf_SET BCM54282_MII_GB_STATr_IDLE_ERRORSf_SET
#define READ_MII_GB_STATr BCM54282_READ_MII_GB_STATr
#define WRITE_MII_GB_STATr BCM54282_WRITE_MII_GB_STATr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_GB_STATr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  TEST_1
 * BLOCKS:   RDB
 * REGADDR:  0x000e
 * DESC:     TEST_1 Register (RDB_Register, offset 0x00E)
 * SIZE:     32
 * FIELDS:
 *     MANUAL_SWAP_MDI  Manual Swap MDI state.
 *     FORCE_LINK       Force Link 10/100/1000BASE-T.
 *     TX_ERR_CODE      Transmit Error Code visibility.
 *     CRC_ERR_CNT      CRC Error Counter Selector.
 *		测试寄存器1
 ******************************************************************************/
#define BCM54282_TEST_1r (0x0000000e | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_TEST_1r_SIZE 4

/*
 * This structure should be used to declare and program TEST_1.
 *
 */
typedef union BCM54282_TEST_1r_s {
	uint32_t v[1];
	uint32_t test_1[1];
	uint32_t _test_1;
} BCM54282_TEST_1r_t;

#define BCM54282_TEST_1r_CLR(r) (r).test_1[0] = 0
#define BCM54282_TEST_1r_SET(r,d) (r).test_1[0] = d
#define BCM54282_TEST_1r_GET(r) (r).test_1[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_TEST_1r_CRC_ERR_CNTf_GET(r) ((((r).test_1[0]) >> 15) & 0x1)
#define BCM54282_TEST_1r_CRC_ERR_CNTf_SET(r,f) (r).test_1[0]=(((r).test_1[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_TEST_1r_TX_ERR_CODEf_GET(r) ((((r).test_1[0]) >> 14) & 0x1)
#define BCM54282_TEST_1r_TX_ERR_CODEf_SET(r,f) (r).test_1[0]=(((r).test_1[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_TEST_1r_FORCE_LINKf_GET(r) ((((r).test_1[0]) >> 12) & 0x1)
#define BCM54282_TEST_1r_FORCE_LINKf_SET(r,f) (r).test_1[0]=(((r).test_1[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_TEST_1r_MANUAL_SWAP_MDIf_GET(r) ((((r).test_1[0]) >> 7) & 0x1)
#define BCM54282_TEST_1r_MANUAL_SWAP_MDIf_SET(r,f) (r).test_1[0]=(((r).test_1[0] & ~((uint32_t)0x1 << 7)) | ((((uint32_t)f) & 0x1) << 7))

/*
 * These macros can be used to access TEST_1.
 *
 */
#define BCM54282_READ_TEST_1r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_TEST_1r,(_r._test_1))
#define BCM54282_WRITE_TEST_1r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_TEST_1r,(_r._test_1))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define TEST_1r BCM54282_TEST_1r
#define TEST_1r_SIZE BCM54282_TEST_1r_SIZE
typedef BCM54282_TEST_1r_t TEST_1r_t;
#define TEST_1r_CLR BCM54282_TEST_1r_CLR
#define TEST_1r_SET BCM54282_TEST_1r_SET
#define TEST_1r_GET BCM54282_TEST_1r_GET
#define TEST_1r_CRC_ERR_CNTf_GET BCM54282_TEST_1r_CRC_ERR_CNTf_GET
#define TEST_1r_CRC_ERR_CNTf_SET BCM54282_TEST_1r_CRC_ERR_CNTf_SET
#define TEST_1r_TX_ERR_CODEf_GET BCM54282_TEST_1r_TX_ERR_CODEf_GET
#define TEST_1r_TX_ERR_CODEf_SET BCM54282_TEST_1r_TX_ERR_CODEf_SET
#define TEST_1r_FORCE_LINKf_GET BCM54282_TEST_1r_FORCE_LINKf_GET
#define TEST_1r_FORCE_LINKf_SET BCM54282_TEST_1r_FORCE_LINKf_SET
#define TEST_1r_MANUAL_SWAP_MDIf_GET BCM54282_TEST_1r_MANUAL_SWAP_MDIf_GET
#define TEST_1r_MANUAL_SWAP_MDIf_SET BCM54282_TEST_1r_MANUAL_SWAP_MDIf_SET
#define READ_TEST_1r BCM54282_READ_TEST_1r
#define WRITE_TEST_1r BCM54282_WRITE_TEST_1r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_TEST_1r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_ESR
 * BLOCKS:   IEEE
 * REGADDR:  0x000f
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T IEEE Extended Status Register (Addr 0Fh)
 * SIZE:     32
 * FIELDS:
 *     CAP_1000BASE_T_HD 1000BASE-T half-duplex capable.
 *     CAP_1000BASE_T_FD 1000BASE-T full-duplex capable.
 *     CAP_1000BASE_X_HD 1000BASE-X half-duplex capable.
 *     CAP_1000BASE_X_FD 1000BASE-X full-duplex capable.
 *		IEEE标准扩展状态寄存器
 ******************************************************************************/
#define BCM54282_MII_ESRr (0x0000000f | PHY_REG_ACC_RAW)

#define BCM54282_MII_ESRr_SIZE 4

/*
 * This structure should be used to declare and program MII_ESR.
 *
 */
typedef union BCM54282_MII_ESRr_s {
	uint32_t v[1];
	uint32_t mii_esr[1];
	uint32_t _mii_esr;
} BCM54282_MII_ESRr_t;

#define BCM54282_MII_ESRr_CLR(r) (r).mii_esr[0] = 0
#define BCM54282_MII_ESRr_SET(r,d) (r).mii_esr[0] = d
#define BCM54282_MII_ESRr_GET(r) (r).mii_esr[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_ESRr_CAP_1000BASE_X_FDf_GET(r) ((((r).mii_esr[0]) >> 15) & 0x1)
#define BCM54282_MII_ESRr_CAP_1000BASE_X_FDf_SET(r,f) (r).mii_esr[0]=(((r).mii_esr[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_ESRr_CAP_1000BASE_X_HDf_GET(r) ((((r).mii_esr[0]) >> 14) & 0x1)
#define BCM54282_MII_ESRr_CAP_1000BASE_X_HDf_SET(r,f) (r).mii_esr[0]=(((r).mii_esr[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_MII_ESRr_CAP_1000BASE_T_FDf_GET(r) ((((r).mii_esr[0]) >> 13) & 0x1)
#define BCM54282_MII_ESRr_CAP_1000BASE_T_FDf_SET(r,f) (r).mii_esr[0]=(((r).mii_esr[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_MII_ESRr_CAP_1000BASE_T_HDf_GET(r) ((((r).mii_esr[0]) >> 12) & 0x1)
#define BCM54282_MII_ESRr_CAP_1000BASE_T_HDf_SET(r,f) (r).mii_esr[0]=(((r).mii_esr[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))

/*
 * These macros can be used to access MII_ESR.
 *
 */
#define BCM54282_READ_MII_ESRr(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_ESRr,_r._mii_esr)
#define BCM54282_WRITE_MII_ESRr(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_ESRr,_r._mii_esr)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_ESRr BCM54282_MII_ESRr
#define MII_ESRr_SIZE BCM54282_MII_ESRr_SIZE
typedef BCM54282_MII_ESRr_t MII_ESRr_t;
#define MII_ESRr_CLR BCM54282_MII_ESRr_CLR
#define MII_ESRr_SET BCM54282_MII_ESRr_SET
#define MII_ESRr_GET BCM54282_MII_ESRr_GET
#define MII_ESRr_CAP_1000BASE_X_FDf_GET BCM54282_MII_ESRr_CAP_1000BASE_X_FDf_GET
#define MII_ESRr_CAP_1000BASE_X_FDf_SET BCM54282_MII_ESRr_CAP_1000BASE_X_FDf_SET
#define MII_ESRr_CAP_1000BASE_X_HDf_GET BCM54282_MII_ESRr_CAP_1000BASE_X_HDf_GET
#define MII_ESRr_CAP_1000BASE_X_HDf_SET BCM54282_MII_ESRr_CAP_1000BASE_X_HDf_SET
#define MII_ESRr_CAP_1000BASE_T_FDf_GET BCM54282_MII_ESRr_CAP_1000BASE_T_FDf_GET
#define MII_ESRr_CAP_1000BASE_T_FDf_SET BCM54282_MII_ESRr_CAP_1000BASE_T_FDf_SET
#define MII_ESRr_CAP_1000BASE_T_HDf_GET BCM54282_MII_ESRr_CAP_1000BASE_T_HDf_GET
#define MII_ESRr_CAP_1000BASE_T_HDf_SET BCM54282_MII_ESRr_CAP_1000BASE_T_HDf_SET
#define READ_MII_ESRr BCM54282_READ_MII_ESRr
#define WRITE_MII_ESRr BCM54282_WRITE_MII_ESRr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_ESRr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_PHY_ECR
 * BLOCKS:   USER
 * REGADDR:  0x0010
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T PHY Extended Control Register (Addr 10h)
 * SIZE:     32
 * FIELDS:
 *     RESERVED         Reserved.
 *     PCS_TX_FIFO_ELAST Reserved.
 *     FORCE_LEDS_OFF   Force LEDs off.
 *     FORCE_LEDS_ON    Force LEDs on.
 *     LED_TRAFFIC_EN   Enable LED traffic mode.
 *     RESET_SCRAMBLER  Reset 100BASE-TX scrambler.
 *     BYPASS_ALIGNMENT Bypass 100BASE-TX receive symbol alignment.
 *     BYPASS_NRZI_MLT3 Bypass 100BASE-TX NRZI/MLT3.
 *     BYPASS_SCRAMBLER Bypass 100BASE-TX scrambler.
 *     BYPASS_ENCODER   Bypass 100BASE-TX 4B/5B encoder/decoder
 *     FORCE_INT        Force INTR output low.
 *     INT_DIS          INTR disable.
 *     TX_DIS           Copper transmitter disable.
 *     AUTO_MDIX_DIS    Automatic MDI crossover disable.
 *		扩展控制寄存器
 ******************************************************************************/
#define BCM54282_MII_PHY_ECRr (0x00000010 | PHY_REG_ACC_RAW)

#define BCM54282_MII_PHY_ECRr_SIZE 4

/*
 * This structure should be used to declare and program MII_PHY_ECR.
 *
 */
typedef union BCM54282_MII_PHY_ECRr_s {
	uint32_t v[1];
	uint32_t mii_phy_ecr[1];
	uint32_t _mii_phy_ecr;
} BCM54282_MII_PHY_ECRr_t;

#define BCM54282_MII_PHY_ECRr_CLR(r) (r).mii_phy_ecr[0] = 0
#define BCM54282_MII_PHY_ECRr_SET(r,d) (r).mii_phy_ecr[0] = d
#define BCM54282_MII_PHY_ECRr_GET(r) (r).mii_phy_ecr[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_PHY_ECRr_AUTO_MDIX_DISf_GET(r) ((((r).mii_phy_ecr[0]) >> 14) & 0x1)
#define BCM54282_MII_PHY_ECRr_AUTO_MDIX_DISf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_MII_PHY_ECRr_TX_DISf_GET(r) ((((r).mii_phy_ecr[0]) >> 13) & 0x1)
#define BCM54282_MII_PHY_ECRr_TX_DISf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_MII_PHY_ECRr_INT_DISf_GET(r) ((((r).mii_phy_ecr[0]) >> 12) & 0x1)
#define BCM54282_MII_PHY_ECRr_INT_DISf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_MII_PHY_ECRr_FORCE_INTf_GET(r) ((((r).mii_phy_ecr[0]) >> 11) & 0x1)
#define BCM54282_MII_PHY_ECRr_FORCE_INTf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x1 << 11)) | ((((uint32_t)f) & 0x1) << 11))
#define BCM54282_MII_PHY_ECRr_BYPASS_ENCODERf_GET(r) ((((r).mii_phy_ecr[0]) >> 10) & 0x1)
#define BCM54282_MII_PHY_ECRr_BYPASS_ENCODERf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))
#define BCM54282_MII_PHY_ECRr_BYPASS_SCRAMBLERf_GET(r) ((((r).mii_phy_ecr[0]) >> 9) & 0x1)
#define BCM54282_MII_PHY_ECRr_BYPASS_SCRAMBLERf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
#define BCM54282_MII_PHY_ECRr_BYPASS_NRZI_MLT3f_GET(r) ((((r).mii_phy_ecr[0]) >> 8) & 0x1)
#define BCM54282_MII_PHY_ECRr_BYPASS_NRZI_MLT3f_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))
#define BCM54282_MII_PHY_ECRr_BYPASS_ALIGNMENTf_GET(r) ((((r).mii_phy_ecr[0]) >> 7) & 0x1)
#define BCM54282_MII_PHY_ECRr_BYPASS_ALIGNMENTf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x1 << 7)) | ((((uint32_t)f) & 0x1) << 7))
#define BCM54282_MII_PHY_ECRr_RESET_SCRAMBLERf_GET(r) ((((r).mii_phy_ecr[0]) >> 6) & 0x1)
#define BCM54282_MII_PHY_ECRr_RESET_SCRAMBLERf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))
#define BCM54282_MII_PHY_ECRr_LED_TRAFFIC_ENf_GET(r) ((((r).mii_phy_ecr[0]) >> 5) & 0x1)
#define BCM54282_MII_PHY_ECRr_LED_TRAFFIC_ENf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))
#define BCM54282_MII_PHY_ECRr_FORCE_LEDS_ONf_GET(r) ((((r).mii_phy_ecr[0]) >> 4) & 0x1)
#define BCM54282_MII_PHY_ECRr_FORCE_LEDS_ONf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x1 << 4)) | ((((uint32_t)f) & 0x1) << 4))
#define BCM54282_MII_PHY_ECRr_FORCE_LEDS_OFFf_GET(r) ((((r).mii_phy_ecr[0]) >> 3) & 0x1)
#define BCM54282_MII_PHY_ECRr_FORCE_LEDS_OFFf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x1 << 3)) | ((((uint32_t)f) & 0x1) << 3))
#define BCM54282_MII_PHY_ECRr_RESERVEDf_GET(r) ((((r).mii_phy_ecr[0]) >> 1) & 0x3)
#define BCM54282_MII_PHY_ECRr_RESERVEDf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x3 << 1)) | ((((uint32_t)f) & 0x3) << 1))
#define BCM54282_MII_PHY_ECRr_PCS_TX_FIFO_ELASTf_GET(r) ((((r).mii_phy_ecr[0]) >> 1) & 0x3)
#define BCM54282_MII_PHY_ECRr_PCS_TX_FIFO_ELASTf_SET(r,f) (r).mii_phy_ecr[0]=(((r).mii_phy_ecr[0] & ~((uint32_t)0x3 << 1)) | ((((uint32_t)f) & 0x3) << 1))

/*
 * These macros can be used to access MII_PHY_ECR.
 *
 */
#define BCM54282_READ_MII_PHY_ECRr(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_PHY_ECRr,_r._mii_phy_ecr)
#define BCM54282_WRITE_MII_PHY_ECRr(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_PHY_ECRr,_r._mii_phy_ecr)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_PHY_ECRr BCM54282_MII_PHY_ECRr
#define MII_PHY_ECRr_SIZE BCM54282_MII_PHY_ECRr_SIZE
typedef BCM54282_MII_PHY_ECRr_t MII_PHY_ECRr_t;
#define MII_PHY_ECRr_CLR BCM54282_MII_PHY_ECRr_CLR
#define MII_PHY_ECRr_SET BCM54282_MII_PHY_ECRr_SET
#define MII_PHY_ECRr_GET BCM54282_MII_PHY_ECRr_GET
#define MII_PHY_ECRr_AUTO_MDIX_DISf_GET BCM54282_MII_PHY_ECRr_AUTO_MDIX_DISf_GET
#define MII_PHY_ECRr_AUTO_MDIX_DISf_SET BCM54282_MII_PHY_ECRr_AUTO_MDIX_DISf_SET
#define MII_PHY_ECRr_TX_DISf_GET BCM54282_MII_PHY_ECRr_TX_DISf_GET
#define MII_PHY_ECRr_TX_DISf_SET BCM54282_MII_PHY_ECRr_TX_DISf_SET
#define MII_PHY_ECRr_INT_DISf_GET BCM54282_MII_PHY_ECRr_INT_DISf_GET
#define MII_PHY_ECRr_INT_DISf_SET BCM54282_MII_PHY_ECRr_INT_DISf_SET
#define MII_PHY_ECRr_FORCE_INTf_GET BCM54282_MII_PHY_ECRr_FORCE_INTf_GET
#define MII_PHY_ECRr_FORCE_INTf_SET BCM54282_MII_PHY_ECRr_FORCE_INTf_SET
#define MII_PHY_ECRr_BYPASS_ENCODERf_GET BCM54282_MII_PHY_ECRr_BYPASS_ENCODERf_GET
#define MII_PHY_ECRr_BYPASS_ENCODERf_SET BCM54282_MII_PHY_ECRr_BYPASS_ENCODERf_SET
#define MII_PHY_ECRr_BYPASS_SCRAMBLERf_GET BCM54282_MII_PHY_ECRr_BYPASS_SCRAMBLERf_GET
#define MII_PHY_ECRr_BYPASS_SCRAMBLERf_SET BCM54282_MII_PHY_ECRr_BYPASS_SCRAMBLERf_SET
#define MII_PHY_ECRr_BYPASS_NRZI_MLT3f_GET BCM54282_MII_PHY_ECRr_BYPASS_NRZI_MLT3f_GET
#define MII_PHY_ECRr_BYPASS_NRZI_MLT3f_SET BCM54282_MII_PHY_ECRr_BYPASS_NRZI_MLT3f_SET
#define MII_PHY_ECRr_BYPASS_ALIGNMENTf_GET BCM54282_MII_PHY_ECRr_BYPASS_ALIGNMENTf_GET
#define MII_PHY_ECRr_BYPASS_ALIGNMENTf_SET BCM54282_MII_PHY_ECRr_BYPASS_ALIGNMENTf_SET
#define MII_PHY_ECRr_RESET_SCRAMBLERf_GET BCM54282_MII_PHY_ECRr_RESET_SCRAMBLERf_GET
#define MII_PHY_ECRr_RESET_SCRAMBLERf_SET BCM54282_MII_PHY_ECRr_RESET_SCRAMBLERf_SET
#define MII_PHY_ECRr_LED_TRAFFIC_ENf_GET BCM54282_MII_PHY_ECRr_LED_TRAFFIC_ENf_GET
#define MII_PHY_ECRr_LED_TRAFFIC_ENf_SET BCM54282_MII_PHY_ECRr_LED_TRAFFIC_ENf_SET
#define MII_PHY_ECRr_FORCE_LEDS_ONf_GET BCM54282_MII_PHY_ECRr_FORCE_LEDS_ONf_GET
#define MII_PHY_ECRr_FORCE_LEDS_ONf_SET BCM54282_MII_PHY_ECRr_FORCE_LEDS_ONf_SET
#define MII_PHY_ECRr_FORCE_LEDS_OFFf_GET BCM54282_MII_PHY_ECRr_FORCE_LEDS_OFFf_GET
#define MII_PHY_ECRr_FORCE_LEDS_OFFf_SET BCM54282_MII_PHY_ECRr_FORCE_LEDS_OFFf_SET
#define MII_PHY_ECRr_RESERVEDf_GET BCM54282_MII_PHY_ECRr_RESERVEDf_GET
#define MII_PHY_ECRr_RESERVEDf_SET BCM54282_MII_PHY_ECRr_RESERVEDf_SET
#define MII_PHY_ECRr_PCS_TX_FIFO_ELASTf_GET BCM54282_MII_PHY_ECRr_PCS_TX_FIFO_ELASTf_GET
#define MII_PHY_ECRr_PCS_TX_FIFO_ELASTf_SET BCM54282_MII_PHY_ECRr_PCS_TX_FIFO_ELASTf_SET
#define READ_MII_PHY_ECRr BCM54282_READ_MII_PHY_ECRr
#define WRITE_MII_PHY_ECRr BCM54282_WRITE_MII_PHY_ECRr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_PHY_ECRr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_PHY_ESR
 * BLOCKS:   USER
 * REGADDR:  0x0011
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T PHY Extended Status Register (Addr 11h)
 * SIZE:     32
 * FIELDS:
 *     MII_PHY_ESR      MII_PHY_ESR
 * 		扩展的状态寄存器
 *
 ******************************************************************************/
#define BCM54282_MII_PHY_ESRr (0x00000011 | PHY_REG_ACC_RAW)

#define BCM54282_MII_PHY_ESRr_SIZE 4

/*
 * This structure should be used to declare and program MII_PHY_ESR.
 *
 */
typedef union BCM54282_MII_PHY_ESRr_s {
	uint32_t v[1];
	uint32_t mii_phy_esr[1];
	uint32_t _mii_phy_esr;
} BCM54282_MII_PHY_ESRr_t;

#define BCM54282_MII_PHY_ESRr_CLR(r) (r).mii_phy_esr[0] = 0
#define BCM54282_MII_PHY_ESRr_SET(r,d) (r).mii_phy_esr[0] = d
#define BCM54282_MII_PHY_ESRr_GET(r) (r).mii_phy_esr[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_PHY_ESRr_MII_PHY_ESRf_GET(r) (((r).mii_phy_esr[0]) & 0xffff)
#define BCM54282_MII_PHY_ESRr_MII_PHY_ESRf_SET(r,f) (r).mii_phy_esr[0]=(((r).mii_phy_esr[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access MII_PHY_ESR.
 *
 */
#define BCM54282_READ_MII_PHY_ESRr(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_PHY_ESRr,_r._mii_phy_esr)
#define BCM54282_WRITE_MII_PHY_ESRr(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_PHY_ESRr,_r._mii_phy_esr)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_PHY_ESRr BCM54282_MII_PHY_ESRr
#define MII_PHY_ESRr_SIZE BCM54282_MII_PHY_ESRr_SIZE
typedef BCM54282_MII_PHY_ESRr_t MII_PHY_ESRr_t;
#define MII_PHY_ESRr_CLR BCM54282_MII_PHY_ESRr_CLR
#define MII_PHY_ESRr_SET BCM54282_MII_PHY_ESRr_SET
#define MII_PHY_ESRr_GET BCM54282_MII_PHY_ESRr_GET
#define MII_PHY_ESRr_MII_PHY_ESRf_GET BCM54282_MII_PHY_ESRr_MII_PHY_ESRf_GET
#define MII_PHY_ESRr_MII_PHY_ESRf_SET BCM54282_MII_PHY_ESRr_MII_PHY_ESRf_SET
#define READ_MII_PHY_ESRr BCM54282_READ_MII_PHY_ESRr
#define WRITE_MII_PHY_ESRr BCM54282_WRITE_MII_PHY_ESRr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_PHY_ESRr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_AUX_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x0018
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T Auxiliary Control Reg (Addr 18h Shadow 000b)
 * SIZE:     32
 * FIELDS:
 *     RESERVED         Reserved.
 *     ENABLE_DSP_CLOCK Enable state machine DSP clock.
 *     EXT_PKT_LEN      Receive extended packets.
 *     EXT_LPBK         External copper loopback enable.
 *		辅助状态控制器
 ******************************************************************************/
#define BCM54282_MII_AUX_CTRLr (0x00000018 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_MII_AUX_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program MII_AUX_CTRL.
 *
 */
typedef union BCM54282_MII_AUX_CTRLr_s {
	uint32_t v[1];
	uint32_t mii_aux_ctrl[1];
	uint32_t _mii_aux_ctrl;
} BCM54282_MII_AUX_CTRLr_t;

#define BCM54282_MII_AUX_CTRLr_CLR(r) (r).mii_aux_ctrl[0] = 0
#define BCM54282_MII_AUX_CTRLr_SET(r,d) (r).mii_aux_ctrl[0] = d
#define BCM54282_MII_AUX_CTRLr_GET(r) (r).mii_aux_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_AUX_CTRLr_EXT_LPBKf_GET(r) ((((r).mii_aux_ctrl[0]) >> 15) & 0x1)
#define BCM54282_MII_AUX_CTRLr_EXT_LPBKf_SET(r,f) (r).mii_aux_ctrl[0]=(((r).mii_aux_ctrl[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_AUX_CTRLr_EXT_PKT_LENf_GET(r) ((((r).mii_aux_ctrl[0]) >> 14) & 0x1)
#define BCM54282_MII_AUX_CTRLr_EXT_PKT_LENf_SET(r,f) (r).mii_aux_ctrl[0]=(((r).mii_aux_ctrl[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_MII_AUX_CTRLr_ENABLE_DSP_CLOCKf_GET(r) ((((r).mii_aux_ctrl[0]) >> 11) & 0x1)
#define BCM54282_MII_AUX_CTRLr_ENABLE_DSP_CLOCKf_SET(r,f) (r).mii_aux_ctrl[0]=(((r).mii_aux_ctrl[0] & ~((uint32_t)0x1 << 11)) | ((((uint32_t)f) & 0x1) << 11))
#define BCM54282_MII_AUX_CTRLr_RESERVEDf_GET(r) ((((r).mii_aux_ctrl[0]) >> 10) & 0x1)
#define BCM54282_MII_AUX_CTRLr_RESERVEDf_SET(r,f) (r).mii_aux_ctrl[0]=(((r).mii_aux_ctrl[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))

/*
 * These macros can be used to access MII_AUX_CTRL.
 *
 */
#define BCM54282_READ_MII_AUX_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_MII_AUX_CTRLr,(_r._mii_aux_ctrl))
#define BCM54282_WRITE_MII_AUX_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_MII_AUX_CTRLr,(_r._mii_aux_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_AUX_CTRLr BCM54282_MII_AUX_CTRLr
#define MII_AUX_CTRLr_SIZE BCM54282_MII_AUX_CTRLr_SIZE
typedef BCM54282_MII_AUX_CTRLr_t MII_AUX_CTRLr_t;
#define MII_AUX_CTRLr_CLR BCM54282_MII_AUX_CTRLr_CLR
#define MII_AUX_CTRLr_SET BCM54282_MII_AUX_CTRLr_SET
#define MII_AUX_CTRLr_GET BCM54282_MII_AUX_CTRLr_GET
#define MII_AUX_CTRLr_EXT_LPBKf_GET BCM54282_MII_AUX_CTRLr_EXT_LPBKf_GET
#define MII_AUX_CTRLr_EXT_LPBKf_SET BCM54282_MII_AUX_CTRLr_EXT_LPBKf_SET
#define MII_AUX_CTRLr_EXT_PKT_LENf_GET BCM54282_MII_AUX_CTRLr_EXT_PKT_LENf_GET
#define MII_AUX_CTRLr_EXT_PKT_LENf_SET BCM54282_MII_AUX_CTRLr_EXT_PKT_LENf_SET
#define MII_AUX_CTRLr_ENABLE_DSP_CLOCKf_GET BCM54282_MII_AUX_CTRLr_ENABLE_DSP_CLOCKf_GET
#define MII_AUX_CTRLr_ENABLE_DSP_CLOCKf_SET BCM54282_MII_AUX_CTRLr_ENABLE_DSP_CLOCKf_SET
#define MII_AUX_CTRLr_RESERVEDf_GET BCM54282_MII_AUX_CTRLr_RESERVEDf_GET
#define MII_AUX_CTRLr_RESERVEDf_SET BCM54282_MII_AUX_CTRLr_RESERVEDf_SET
#define READ_MII_AUX_CTRLr BCM54282_READ_MII_AUX_CTRLr
#define WRITE_MII_AUX_CTRLr BCM54282_WRITE_MII_AUX_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_AUX_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_10BASE_T
 * BLOCKS:   USER
 * REGADDR:  0x0018
 * DESC:     10BASE-T Register (Addr 18h Shadow 001b)
 * SIZE:     32
 * FIELDS:
 *     MII_10BASE_T     MII_10BASE_T
 *	10BASE_T寄存器
 ******************************************************************************/
#define BCM54282_MII_10BASE_Tr (0x00000118 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_MII_10BASE_Tr_SIZE 4

/*
 * This structure should be used to declare and program MII_10BASE_T.
 *
 */
typedef union BCM54282_MII_10BASE_Tr_s {
	uint32_t v[1];
	uint32_t mii_10base_t[1];
	uint32_t _mii_10base_t;
} BCM54282_MII_10BASE_Tr_t;

#define BCM54282_MII_10BASE_Tr_CLR(r) (r).mii_10base_t[0] = 0
#define BCM54282_MII_10BASE_Tr_SET(r,d) (r).mii_10base_t[0] = d
#define BCM54282_MII_10BASE_Tr_GET(r) (r).mii_10base_t[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_10BASE_Tr_MII_10BASE_Tf_GET(r) (((r).mii_10base_t[0]) & 0xffff)
#define BCM54282_MII_10BASE_Tr_MII_10BASE_Tf_SET(r,f) (r).mii_10base_t[0]=(((r).mii_10base_t[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access MII_10BASE_T.
 *
 */
#define BCM54282_READ_MII_10BASE_Tr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_MII_10BASE_Tr,(_r._mii_10base_t))
#define BCM54282_WRITE_MII_10BASE_Tr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_MII_10BASE_Tr,(_r._mii_10base_t))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_10BASE_Tr BCM54282_MII_10BASE_Tr
#define MII_10BASE_Tr_SIZE BCM54282_MII_10BASE_Tr_SIZE
typedef BCM54282_MII_10BASE_Tr_t MII_10BASE_Tr_t;
#define MII_10BASE_Tr_CLR BCM54282_MII_10BASE_Tr_CLR
#define MII_10BASE_Tr_SET BCM54282_MII_10BASE_Tr_SET
#define MII_10BASE_Tr_GET BCM54282_MII_10BASE_Tr_GET
#define MII_10BASE_Tr_MII_10BASE_Tf_GET BCM54282_MII_10BASE_Tr_MII_10BASE_Tf_GET
#define MII_10BASE_Tr_MII_10BASE_Tf_SET BCM54282_MII_10BASE_Tr_MII_10BASE_Tf_SET
#define READ_MII_10BASE_Tr BCM54282_READ_MII_10BASE_Tr
#define WRITE_MII_10BASE_Tr BCM54282_WRITE_MII_10BASE_Tr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_10BASE_Tr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_POWER_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x0018
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T Power/MII Control Reg (Addr 18h Shadow 010b)
 * SIZE:     32
 * FIELDS:
 *     MII_POWER_CTRL   MII_POWER_CTRL
 *		MII控制寄存器
 ******************************************************************************/
#define BCM54282_MII_POWER_CTRLr (0x00000218 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_MII_POWER_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program MII_POWER_CTRL.
 *
 */
typedef union BCM54282_MII_POWER_CTRLr_s {
	uint32_t v[1];
	uint32_t mii_power_ctrl[1];
	uint32_t _mii_power_ctrl;
} BCM54282_MII_POWER_CTRLr_t;

#define BCM54282_MII_POWER_CTRLr_CLR(r) (r).mii_power_ctrl[0] = 0
#define BCM54282_MII_POWER_CTRLr_SET(r,d) (r).mii_power_ctrl[0] = d
#define BCM54282_MII_POWER_CTRLr_GET(r) (r).mii_power_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_POWER_CTRLr_MII_POWER_CTRLf_GET(r) (((r).mii_power_ctrl[0]) & 0xffff)
#define BCM54282_MII_POWER_CTRLr_MII_POWER_CTRLf_SET(r,f) (r).mii_power_ctrl[0]=(((r).mii_power_ctrl[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access MII_POWER_CTRL.
 *
 */
#define BCM54282_READ_MII_POWER_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_MII_POWER_CTRLr,(_r._mii_power_ctrl))
#define BCM54282_WRITE_MII_POWER_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_MII_POWER_CTRLr,(_r._mii_power_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_POWER_CTRLr BCM54282_MII_POWER_CTRLr
#define MII_POWER_CTRLr_SIZE BCM54282_MII_POWER_CTRLr_SIZE
typedef BCM54282_MII_POWER_CTRLr_t MII_POWER_CTRLr_t;
#define MII_POWER_CTRLr_CLR BCM54282_MII_POWER_CTRLr_CLR
#define MII_POWER_CTRLr_SET BCM54282_MII_POWER_CTRLr_SET
#define MII_POWER_CTRLr_GET BCM54282_MII_POWER_CTRLr_GET
#define MII_POWER_CTRLr_MII_POWER_CTRLf_GET BCM54282_MII_POWER_CTRLr_MII_POWER_CTRLf_GET
#define MII_POWER_CTRLr_MII_POWER_CTRLf_SET BCM54282_MII_POWER_CTRLr_MII_POWER_CTRLf_SET
#define READ_MII_POWER_CTRLr BCM54282_READ_MII_POWER_CTRLr
#define WRITE_MII_POWER_CTRLr BCM54282_WRITE_MII_POWER_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_POWER_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_MISC_TEST
 * BLOCKS:   USER
 * REGADDR:  0x0018
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T Misc Test Register (Addr 18h Shadow 100b)
 * SIZE:     32
 * FIELDS:
 *     MII_MISC_TEST    MII_MISC_TEST
 *
 ******************************************************************************/
#define BCM54282_MII_MISC_TESTr (0x00000418 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_MII_MISC_TESTr_SIZE 4

/*
 * This structure should be used to declare and program MII_MISC_TEST.
 *
 */
typedef union BCM54282_MII_MISC_TESTr_s {
	uint32_t v[1];
	uint32_t mii_misc_test[1];
	uint32_t _mii_misc_test;
} BCM54282_MII_MISC_TESTr_t;

#define BCM54282_MII_MISC_TESTr_CLR(r) (r).mii_misc_test[0] = 0
#define BCM54282_MII_MISC_TESTr_SET(r,d) (r).mii_misc_test[0] = d
#define BCM54282_MII_MISC_TESTr_GET(r) (r).mii_misc_test[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_MISC_TESTr_MII_MISC_TESTf_GET(r) (((r).mii_misc_test[0]) & 0xffff)
#define BCM54282_MII_MISC_TESTr_MII_MISC_TESTf_SET(r,f) (r).mii_misc_test[0]=(((r).mii_misc_test[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access MII_MISC_TEST.
 *
 */
#define BCM54282_READ_MII_MISC_TESTr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_MII_MISC_TESTr,(_r._mii_misc_test))
#define BCM54282_WRITE_MII_MISC_TESTr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_MII_MISC_TESTr,(_r._mii_misc_test))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_MISC_TESTr BCM54282_MII_MISC_TESTr
#define MII_MISC_TESTr_SIZE BCM54282_MII_MISC_TESTr_SIZE
typedef BCM54282_MII_MISC_TESTr_t MII_MISC_TESTr_t;
#define MII_MISC_TESTr_CLR BCM54282_MII_MISC_TESTr_CLR
#define MII_MISC_TESTr_SET BCM54282_MII_MISC_TESTr_SET
#define MII_MISC_TESTr_GET BCM54282_MII_MISC_TESTr_GET
#define MII_MISC_TESTr_MII_MISC_TESTf_GET BCM54282_MII_MISC_TESTr_MII_MISC_TESTf_GET
#define MII_MISC_TESTr_MII_MISC_TESTf_SET BCM54282_MII_MISC_TESTr_MII_MISC_TESTf_SET
#define READ_MII_MISC_TESTr BCM54282_READ_MII_MISC_TESTr
#define WRITE_MII_MISC_TESTr BCM54282_WRITE_MII_MISC_TESTr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_MISC_TESTr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_MISC_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x0018
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T Misc Control Register (Addr 18h Shadow 111b)
 * SIZE:     32
 * FIELDS:
 *     MII_MISC_CTRL    MII_MISC_CTRL
 *
 ******************************************************************************/
#define BCM54282_MII_MISC_CTRLr (0x00000718 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_MII_MISC_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program MII_MISC_CTRL.
 *
 */
typedef union BCM54282_MII_MISC_CTRLr_s {
	uint32_t v[1];
	uint32_t mii_misc_ctrl[1];
	uint32_t _mii_misc_ctrl;
} BCM54282_MII_MISC_CTRLr_t;

#define BCM54282_MII_MISC_CTRLr_CLR(r) (r).mii_misc_ctrl[0] = 0
#define BCM54282_MII_MISC_CTRLr_SET(r,d) (r).mii_misc_ctrl[0] = d
#define BCM54282_MII_MISC_CTRLr_GET(r) (r).mii_misc_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_MISC_CTRLr_MII_MISC_CTRLf_GET(r) (((r).mii_misc_ctrl[0]) & 0xffff)
#define BCM54282_MII_MISC_CTRLr_MII_MISC_CTRLf_SET(r,f) (r).mii_misc_ctrl[0]=(((r).mii_misc_ctrl[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access MII_MISC_CTRL.
 *
 */
#define BCM54282_READ_MII_MISC_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_MII_MISC_CTRLr,(_r._mii_misc_ctrl))
#define BCM54282_WRITE_MII_MISC_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_MII_MISC_CTRLr,(_r._mii_misc_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_MISC_CTRLr BCM54282_MII_MISC_CTRLr
#define MII_MISC_CTRLr_SIZE BCM54282_MII_MISC_CTRLr_SIZE
typedef BCM54282_MII_MISC_CTRLr_t MII_MISC_CTRLr_t;
#define MII_MISC_CTRLr_CLR BCM54282_MII_MISC_CTRLr_CLR
#define MII_MISC_CTRLr_SET BCM54282_MII_MISC_CTRLr_SET
#define MII_MISC_CTRLr_GET BCM54282_MII_MISC_CTRLr_GET
#define MII_MISC_CTRLr_MII_MISC_CTRLf_GET BCM54282_MII_MISC_CTRLr_MII_MISC_CTRLf_GET
#define MII_MISC_CTRLr_MII_MISC_CTRLf_SET BCM54282_MII_MISC_CTRLr_MII_MISC_CTRLf_SET
#define READ_MII_MISC_CTRLr BCM54282_READ_MII_MISC_CTRLr
#define WRITE_MII_MISC_CTRLr BCM54282_WRITE_MII_MISC_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_MISC_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_AUX_STATUS
 * BLOCKS:   USER
 * REGADDR:  0x0019
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T MII AUX STATUS SUMMARY Reg (Addr 19h)
 * SIZE:     32
 * FIELDS:
 *     PRTD             Pause resolution/XMIT direction.
 *     PRRD             Pause resolution/RCV direction.
 *     LS               Link Status (1 == link up).
 *     LPNPA            Link partner next page cap.
 *     LPANA            Link Partner AN capable.
 *     ANPR             Autoneg page received.
 *     RF               Remote Fault.
 *     PDF              Parallel detection fault.
 *     HCD              Current operating speed.
 *     ANNPW            Auto-neg next page wait.
 *     ANABD            Auto-neg Ability detected.
 *     ANAD             Auto-neg ACK detect.
 *     ANCA             Auto-neg complete ACK.
 *     ANC              Auto-neg complete.
 *
 ******************************************************************************/
#define BCM54282_MII_AUX_STATUSr (0x00000019 | PHY_REG_ACC_RAW)

#define BCM54282_MII_AUX_STATUSr_SIZE 4

/*
 * This structure should be used to declare and program MII_AUX_STATUS.
 *
 */
typedef union BCM54282_MII_AUX_STATUSr_s {
	uint32_t v[1];
	uint32_t mii_aux_status[1];
	uint32_t _mii_aux_status;
} BCM54282_MII_AUX_STATUSr_t;

#define BCM54282_MII_AUX_STATUSr_CLR(r) (r).mii_aux_status[0] = 0
#define BCM54282_MII_AUX_STATUSr_SET(r,d) (r).mii_aux_status[0] = d
#define BCM54282_MII_AUX_STATUSr_GET(r) (r).mii_aux_status[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_AUX_STATUSr_ANCf_GET(r) ((((r).mii_aux_status[0]) >> 15) & 0x1)
#define BCM54282_MII_AUX_STATUSr_ANCf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_AUX_STATUSr_ANCAf_GET(r) ((((r).mii_aux_status[0]) >> 14) & 0x1)
#define BCM54282_MII_AUX_STATUSr_ANCAf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_MII_AUX_STATUSr_ANADf_GET(r) ((((r).mii_aux_status[0]) >> 13) & 0x1)
#define BCM54282_MII_AUX_STATUSr_ANADf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_MII_AUX_STATUSr_ANABDf_GET(r) ((((r).mii_aux_status[0]) >> 12) & 0x1)
#define BCM54282_MII_AUX_STATUSr_ANABDf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_MII_AUX_STATUSr_ANNPWf_GET(r) ((((r).mii_aux_status[0]) >> 11) & 0x1)
#define BCM54282_MII_AUX_STATUSr_ANNPWf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1 << 11)) | ((((uint32_t)f) & 0x1) << 11))
#define BCM54282_MII_AUX_STATUSr_HCDf_GET(r) ((((r).mii_aux_status[0]) >> 8) & 0x7)
#define BCM54282_MII_AUX_STATUSr_HCDf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x7 << 8)) | ((((uint32_t)f) & 0x7) << 8))
#define BCM54282_MII_AUX_STATUSr_PDFf_GET(r) ((((r).mii_aux_status[0]) >> 7) & 0x1)
#define BCM54282_MII_AUX_STATUSr_PDFf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1 << 7)) | ((((uint32_t)f) & 0x1) << 7))
#define BCM54282_MII_AUX_STATUSr_RFf_GET(r) ((((r).mii_aux_status[0]) >> 6) & 0x1)
#define BCM54282_MII_AUX_STATUSr_RFf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))
#define BCM54282_MII_AUX_STATUSr_ANPRf_GET(r) ((((r).mii_aux_status[0]) >> 5) & 0x1)
#define BCM54282_MII_AUX_STATUSr_ANPRf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))
#define BCM54282_MII_AUX_STATUSr_LPANAf_GET(r) ((((r).mii_aux_status[0]) >> 4) & 0x1)
#define BCM54282_MII_AUX_STATUSr_LPANAf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1 << 4)) | ((((uint32_t)f) & 0x1) << 4))
#define BCM54282_MII_AUX_STATUSr_LPNPAf_GET(r) ((((r).mii_aux_status[0]) >> 3) & 0x1)
#define BCM54282_MII_AUX_STATUSr_LPNPAf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1 << 3)) | ((((uint32_t)f) & 0x1) << 3))
#define BCM54282_MII_AUX_STATUSr_LSf_GET(r) ((((r).mii_aux_status[0]) >> 2) & 0x1)
#define BCM54282_MII_AUX_STATUSr_LSf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_AUX_STATUSr_PRRDf_GET(r) ((((r).mii_aux_status[0]) >> 1) & 0x1)
#define BCM54282_MII_AUX_STATUSr_PRRDf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1 << 1)) | ((((uint32_t)f) & 0x1) << 1))
#define BCM54282_MII_AUX_STATUSr_PRTDf_GET(r) (((r).mii_aux_status[0]) & 0x1)
#define BCM54282_MII_AUX_STATUSr_PRTDf_SET(r,f) (r).mii_aux_status[0]=(((r).mii_aux_status[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_AUX_STATUS.
 *
 */
#define BCM54282_READ_MII_AUX_STATUSr(_pc,_r) PHY_BUS_READ(_pc,BCM54282_MII_AUX_STATUSr,_r._mii_aux_status)
#define BCM54282_WRITE_MII_AUX_STATUSr(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_MII_AUX_STATUSr,_r._mii_aux_status)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_AUX_STATUSr BCM54282_MII_AUX_STATUSr
#define MII_AUX_STATUSr_SIZE BCM54282_MII_AUX_STATUSr_SIZE
typedef BCM54282_MII_AUX_STATUSr_t MII_AUX_STATUSr_t;
#define MII_AUX_STATUSr_CLR BCM54282_MII_AUX_STATUSr_CLR
#define MII_AUX_STATUSr_SET BCM54282_MII_AUX_STATUSr_SET
#define MII_AUX_STATUSr_GET BCM54282_MII_AUX_STATUSr_GET
#define MII_AUX_STATUSr_ANCf_GET BCM54282_MII_AUX_STATUSr_ANCf_GET
#define MII_AUX_STATUSr_ANCf_SET BCM54282_MII_AUX_STATUSr_ANCf_SET
#define MII_AUX_STATUSr_ANCAf_GET BCM54282_MII_AUX_STATUSr_ANCAf_GET
#define MII_AUX_STATUSr_ANCAf_SET BCM54282_MII_AUX_STATUSr_ANCAf_SET
#define MII_AUX_STATUSr_ANADf_GET BCM54282_MII_AUX_STATUSr_ANADf_GET
#define MII_AUX_STATUSr_ANADf_SET BCM54282_MII_AUX_STATUSr_ANADf_SET
#define MII_AUX_STATUSr_ANABDf_GET BCM54282_MII_AUX_STATUSr_ANABDf_GET
#define MII_AUX_STATUSr_ANABDf_SET BCM54282_MII_AUX_STATUSr_ANABDf_SET
#define MII_AUX_STATUSr_ANNPWf_GET BCM54282_MII_AUX_STATUSr_ANNPWf_GET
#define MII_AUX_STATUSr_ANNPWf_SET BCM54282_MII_AUX_STATUSr_ANNPWf_SET
#define MII_AUX_STATUSr_HCDf_GET BCM54282_MII_AUX_STATUSr_HCDf_GET
#define MII_AUX_STATUSr_HCDf_SET BCM54282_MII_AUX_STATUSr_HCDf_SET
#define MII_AUX_STATUSr_PDFf_GET BCM54282_MII_AUX_STATUSr_PDFf_GET
#define MII_AUX_STATUSr_PDFf_SET BCM54282_MII_AUX_STATUSr_PDFf_SET
#define MII_AUX_STATUSr_RFf_GET BCM54282_MII_AUX_STATUSr_RFf_GET
#define MII_AUX_STATUSr_RFf_SET BCM54282_MII_AUX_STATUSr_RFf_SET
#define MII_AUX_STATUSr_ANPRf_GET BCM54282_MII_AUX_STATUSr_ANPRf_GET
#define MII_AUX_STATUSr_ANPRf_SET BCM54282_MII_AUX_STATUSr_ANPRf_SET
#define MII_AUX_STATUSr_LPANAf_GET BCM54282_MII_AUX_STATUSr_LPANAf_GET
#define MII_AUX_STATUSr_LPANAf_SET BCM54282_MII_AUX_STATUSr_LPANAf_SET
#define MII_AUX_STATUSr_LPNPAf_GET BCM54282_MII_AUX_STATUSr_LPNPAf_GET
#define MII_AUX_STATUSr_LPNPAf_SET BCM54282_MII_AUX_STATUSr_LPNPAf_SET
#define MII_AUX_STATUSr_LSf_GET BCM54282_MII_AUX_STATUSr_LSf_GET
#define MII_AUX_STATUSr_LSf_SET BCM54282_MII_AUX_STATUSr_LSf_SET
#define MII_AUX_STATUSr_PRRDf_GET BCM54282_MII_AUX_STATUSr_PRRDf_GET
#define MII_AUX_STATUSr_PRRDf_SET BCM54282_MII_AUX_STATUSr_PRRDf_SET
#define MII_AUX_STATUSr_PRTDf_GET BCM54282_MII_AUX_STATUSr_PRTDf_GET
#define MII_AUX_STATUSr_PRTDf_SET BCM54282_MII_AUX_STATUSr_PRTDf_SET
#define READ_MII_AUX_STATUSr BCM54282_READ_MII_AUX_STATUSr
#define WRITE_MII_AUX_STATUSr BCM54282_WRITE_MII_AUX_STATUSr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_AUX_STATUSr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  SPARE_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T Spare Ctrl Reg (Addr 1Ch shadow 00010b)
 * SIZE:     32
 * FIELDS:
 *     LINK_LED_MODE    Link LED mode.
 *     LINK_SPEED_LED_MODE Link speed mode.
 *
 ******************************************************************************/
#define BCM54282_SPARE_CTRLr (0x0000021c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_SPARE_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program SPARE_CTRL.
 *
 */
typedef union BCM54282_SPARE_CTRLr_s {
	uint32_t v[1];
	uint32_t spare_ctrl[1];
	uint32_t _spare_ctrl;
} BCM54282_SPARE_CTRLr_t;

#define BCM54282_SPARE_CTRLr_CLR(r) (r).spare_ctrl[0] = 0
#define BCM54282_SPARE_CTRLr_SET(r,d) (r).spare_ctrl[0] = d
#define BCM54282_SPARE_CTRLr_GET(r) (r).spare_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_SPARE_CTRLr_LINK_SPEED_LED_MODEf_GET(r) ((((r).spare_ctrl[0]) >> 2) & 0x1)
#define BCM54282_SPARE_CTRLr_LINK_SPEED_LED_MODEf_SET(r,f) (r).spare_ctrl[0]=(((r).spare_ctrl[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_SPARE_CTRLr_LINK_LED_MODEf_GET(r) (((r).spare_ctrl[0]) & 0x1)
#define BCM54282_SPARE_CTRLr_LINK_LED_MODEf_SET(r,f) (r).spare_ctrl[0]=(((r).spare_ctrl[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access SPARE_CTRL.
 *
 */
#define BCM54282_READ_SPARE_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_SPARE_CTRLr,(_r._spare_ctrl))
#define BCM54282_WRITE_SPARE_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_SPARE_CTRLr,(_r._spare_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define SPARE_CTRLr BCM54282_SPARE_CTRLr
#define SPARE_CTRLr_SIZE BCM54282_SPARE_CTRLr_SIZE
typedef BCM54282_SPARE_CTRLr_t SPARE_CTRLr_t;
#define SPARE_CTRLr_CLR BCM54282_SPARE_CTRLr_CLR
#define SPARE_CTRLr_SET BCM54282_SPARE_CTRLr_SET
#define SPARE_CTRLr_GET BCM54282_SPARE_CTRLr_GET
#define SPARE_CTRLr_LINK_SPEED_LED_MODEf_GET BCM54282_SPARE_CTRLr_LINK_SPEED_LED_MODEf_GET
#define SPARE_CTRLr_LINK_SPEED_LED_MODEf_SET BCM54282_SPARE_CTRLr_LINK_SPEED_LED_MODEf_SET
#define SPARE_CTRLr_LINK_LED_MODEf_GET BCM54282_SPARE_CTRLr_LINK_LED_MODEf_GET
#define SPARE_CTRLr_LINK_LED_MODEf_SET BCM54282_SPARE_CTRLr_LINK_LED_MODEf_SET
#define READ_SPARE_CTRLr BCM54282_READ_SPARE_CTRLr
#define WRITE_SPARE_CTRLr BCM54282_WRITE_SPARE_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_SPARE_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  SPARE_CTRL_2
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T Spare Ctrl 2 Reg (Addr 1Ch shadow 00100b)
 * SIZE:     32
 * FIELDS:
 *     SPARE_CTRL_2     SPARE_CTRL_2
 *
 ******************************************************************************/
#define BCM54282_SPARE_CTRL_2r (0x0000041c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_SPARE_CTRL_2r_SIZE 4

/*
 * This structure should be used to declare and program SPARE_CTRL_2.
 *
 */
typedef union BCM54282_SPARE_CTRL_2r_s {
	uint32_t v[1];
	uint32_t spare_ctrl_2[1];
	uint32_t _spare_ctrl_2;
} BCM54282_SPARE_CTRL_2r_t;

#define BCM54282_SPARE_CTRL_2r_CLR(r) (r).spare_ctrl_2[0] = 0
#define BCM54282_SPARE_CTRL_2r_SET(r,d) (r).spare_ctrl_2[0] = d
#define BCM54282_SPARE_CTRL_2r_GET(r) (r).spare_ctrl_2[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_SPARE_CTRL_2r_SPARE_CTRL_2f_GET(r) (((r).spare_ctrl_2[0]) & 0xffff)
#define BCM54282_SPARE_CTRL_2r_SPARE_CTRL_2f_SET(r,f) (r).spare_ctrl_2[0]=(((r).spare_ctrl_2[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access SPARE_CTRL_2.
 *
 */
#define BCM54282_READ_SPARE_CTRL_2r(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_SPARE_CTRL_2r,(_r._spare_ctrl_2))
#define BCM54282_WRITE_SPARE_CTRL_2r(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_SPARE_CTRL_2r,(_r._spare_ctrl_2))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define SPARE_CTRL_2r BCM54282_SPARE_CTRL_2r
#define SPARE_CTRL_2r_SIZE BCM54282_SPARE_CTRL_2r_SIZE
typedef BCM54282_SPARE_CTRL_2r_t SPARE_CTRL_2r_t;
#define SPARE_CTRL_2r_CLR BCM54282_SPARE_CTRL_2r_CLR
#define SPARE_CTRL_2r_SET BCM54282_SPARE_CTRL_2r_SET
#define SPARE_CTRL_2r_GET BCM54282_SPARE_CTRL_2r_GET
#define SPARE_CTRL_2r_SPARE_CTRL_2f_GET BCM54282_SPARE_CTRL_2r_SPARE_CTRL_2f_GET
#define SPARE_CTRL_2r_SPARE_CTRL_2f_SET BCM54282_SPARE_CTRL_2r_SPARE_CTRL_2f_SET
#define READ_SPARE_CTRL_2r BCM54282_READ_SPARE_CTRL_2r
#define WRITE_SPARE_CTRL_2r BCM54282_WRITE_SPARE_CTRL_2r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_SPARE_CTRL_2r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  SPARE_CTRL_3
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T Spare Ctrl 3 Reg (Addr 1Ch shadow 00101b)
 * SIZE:     32
 * FIELDS:
 *     SPARE_CTRL_3     SPARE_CTRL_3
 *
 ******************************************************************************/
#define BCM54282_SPARE_CTRL_3r (0x0000051c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_SPARE_CTRL_3r_SIZE 4

/*
 * This structure should be used to declare and program SPARE_CTRL_3.
 *
 */
typedef union BCM54282_SPARE_CTRL_3r_s {
	uint32_t v[1];
	uint32_t spare_ctrl_3[1];
	uint32_t _spare_ctrl_3;
} BCM54282_SPARE_CTRL_3r_t;

#define BCM54282_SPARE_CTRL_3r_CLR(r) (r).spare_ctrl_3[0] = 0
#define BCM54282_SPARE_CTRL_3r_SET(r,d) (r).spare_ctrl_3[0] = d
#define BCM54282_SPARE_CTRL_3r_GET(r) (r).spare_ctrl_3[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_SPARE_CTRL_3r_SPARE_CTRL_3f_GET(r) (((r).spare_ctrl_3[0]) & 0xffff)
#define BCM54282_SPARE_CTRL_3r_SPARE_CTRL_3f_SET(r,f) (r).spare_ctrl_3[0]=(((r).spare_ctrl_3[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access SPARE_CTRL_3.
 *
 */
#define BCM54282_READ_SPARE_CTRL_3r(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_SPARE_CTRL_3r,(_r._spare_ctrl_3))
#define BCM54282_WRITE_SPARE_CTRL_3r(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_SPARE_CTRL_3r,(_r._spare_ctrl_3))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define SPARE_CTRL_3r BCM54282_SPARE_CTRL_3r
#define SPARE_CTRL_3r_SIZE BCM54282_SPARE_CTRL_3r_SIZE
typedef BCM54282_SPARE_CTRL_3r_t SPARE_CTRL_3r_t;
#define SPARE_CTRL_3r_CLR BCM54282_SPARE_CTRL_3r_CLR
#define SPARE_CTRL_3r_SET BCM54282_SPARE_CTRL_3r_SET
#define SPARE_CTRL_3r_GET BCM54282_SPARE_CTRL_3r_GET
#define SPARE_CTRL_3r_SPARE_CTRL_3f_GET BCM54282_SPARE_CTRL_3r_SPARE_CTRL_3f_GET
#define SPARE_CTRL_3r_SPARE_CTRL_3f_SET BCM54282_SPARE_CTRL_3r_SPARE_CTRL_3f_SET
#define READ_SPARE_CTRL_3r BCM54282_READ_SPARE_CTRL_3r
#define WRITE_SPARE_CTRL_3r BCM54282_WRITE_SPARE_CTRL_3r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_SPARE_CTRL_3r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  LED_STAT
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T LED Status Reg (Addr 1Ch shadow 01000b)
 * SIZE:     32
 * FIELDS:
 *     LED_STAT         LED_STAT
 *
 ******************************************************************************/
#define BCM54282_LED_STATr (0x0000081c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_LED_STATr_SIZE 4

/*
 * This structure should be used to declare and program LED_STAT.
 *
 */
typedef union BCM54282_LED_STATr_s {
	uint32_t v[1];
	uint32_t led_stat[1];
	uint32_t _led_stat;
} BCM54282_LED_STATr_t;

#define BCM54282_LED_STATr_CLR(r) (r).led_stat[0] = 0
#define BCM54282_LED_STATr_SET(r,d) (r).led_stat[0] = d
#define BCM54282_LED_STATr_GET(r) (r).led_stat[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_LED_STATr_LED_STATf_GET(r) (((r).led_stat[0]) & 0xffff)
#define BCM54282_LED_STATr_LED_STATf_SET(r,f) (r).led_stat[0]=(((r).led_stat[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access LED_STAT.
 *
 */
#define BCM54282_READ_LED_STATr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_LED_STATr,(_r._led_stat))
#define BCM54282_WRITE_LED_STATr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_LED_STATr,(_r._led_stat))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define LED_STATr BCM54282_LED_STATr
#define LED_STATr_SIZE BCM54282_LED_STATr_SIZE
typedef BCM54282_LED_STATr_t LED_STATr_t;
#define LED_STATr_CLR BCM54282_LED_STATr_CLR
#define LED_STATr_SET BCM54282_LED_STATr_SET
#define LED_STATr_GET BCM54282_LED_STATr_GET
#define LED_STATr_LED_STATf_GET BCM54282_LED_STATr_LED_STATf_GET
#define LED_STATr_LED_STATf_SET BCM54282_LED_STATr_LED_STATf_SET
#define READ_LED_STATr BCM54282_READ_LED_STATr
#define WRITE_LED_STATr BCM54282_WRITE_LED_STATr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_LED_STATr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  LED_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T LED Ctrl Reg (Addr 1Ch shadow 01001b)
 * SIZE:     32
 * FIELDS:
 *     LED_CTRL         LED_CTRL
 *
 ******************************************************************************/
#define BCM54282_LED_CTRLr (0x0000091c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_LED_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program LED_CTRL.
 *
 */
typedef union BCM54282_LED_CTRLr_s {
	uint32_t v[1];
	uint32_t led_ctrl[1];
	uint32_t _led_ctrl;
} BCM54282_LED_CTRLr_t;

#define BCM54282_LED_CTRLr_CLR(r) (r).led_ctrl[0] = 0
#define BCM54282_LED_CTRLr_SET(r,d) (r).led_ctrl[0] = d
#define BCM54282_LED_CTRLr_GET(r) (r).led_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_LED_CTRLr_LED_CTRLf_GET(r) (((r).led_ctrl[0]) & 0xffff)
#define BCM54282_LED_CTRLr_LED_CTRLf_SET(r,f) (r).led_ctrl[0]=(((r).led_ctrl[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access LED_CTRL.
 *
 */
#define BCM54282_READ_LED_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_LED_CTRLr,(_r._led_ctrl))
#define BCM54282_WRITE_LED_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_LED_CTRLr,(_r._led_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define LED_CTRLr BCM54282_LED_CTRLr
#define LED_CTRLr_SIZE BCM54282_LED_CTRLr_SIZE
typedef BCM54282_LED_CTRLr_t LED_CTRLr_t;
#define LED_CTRLr_CLR BCM54282_LED_CTRLr_CLR
#define LED_CTRLr_SET BCM54282_LED_CTRLr_SET
#define LED_CTRLr_GET BCM54282_LED_CTRLr_GET
#define LED_CTRLr_LED_CTRLf_GET BCM54282_LED_CTRLr_LED_CTRLf_GET
#define LED_CTRLr_LED_CTRLf_SET BCM54282_LED_CTRLr_LED_CTRLf_SET
#define READ_LED_CTRLr BCM54282_READ_LED_CTRLr
#define WRITE_LED_CTRLr BCM54282_WRITE_LED_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_LED_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  AUTO_POWER_DOWN
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     Auto Power-Down Reg (Addr 1Ch shadow 01010b)
 * SIZE:     32
 * FIELDS:
 *     AUTO_POWER_DOWN  AUTO_POWER_DOWN
 *
 ******************************************************************************/
#define BCM54282_AUTO_POWER_DOWNr (0x00000a1c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_AUTO_POWER_DOWNr_SIZE 4

/*
 * This structure should be used to declare and program AUTO_POWER_DOWN.
 *
 */
typedef union BCM54282_AUTO_POWER_DOWNr_s {
	uint32_t v[1];
	uint32_t auto_power_down[1];
	uint32_t _auto_power_down;
} BCM54282_AUTO_POWER_DOWNr_t;

#define BCM54282_AUTO_POWER_DOWNr_CLR(r) (r).auto_power_down[0] = 0
#define BCM54282_AUTO_POWER_DOWNr_SET(r,d) (r).auto_power_down[0] = d
#define BCM54282_AUTO_POWER_DOWNr_GET(r) (r).auto_power_down[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_AUTO_POWER_DOWNr_AUTO_POWER_DOWNf_GET(r) (((r).auto_power_down[0]) & 0xffff)
#define BCM54282_AUTO_POWER_DOWNr_AUTO_POWER_DOWNf_SET(r,f) (r).auto_power_down[0]=(((r).auto_power_down[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access AUTO_POWER_DOWN.
 *
 */
#define BCM54282_READ_AUTO_POWER_DOWNr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_AUTO_POWER_DOWNr,(_r._auto_power_down))
#define BCM54282_WRITE_AUTO_POWER_DOWNr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_AUTO_POWER_DOWNr,(_r._auto_power_down))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define AUTO_POWER_DOWNr BCM54282_AUTO_POWER_DOWNr
#define AUTO_POWER_DOWNr_SIZE BCM54282_AUTO_POWER_DOWNr_SIZE
typedef BCM54282_AUTO_POWER_DOWNr_t AUTO_POWER_DOWNr_t;
#define AUTO_POWER_DOWNr_CLR BCM54282_AUTO_POWER_DOWNr_CLR
#define AUTO_POWER_DOWNr_SET BCM54282_AUTO_POWER_DOWNr_SET
#define AUTO_POWER_DOWNr_GET BCM54282_AUTO_POWER_DOWNr_GET
#define AUTO_POWER_DOWNr_AUTO_POWER_DOWNf_GET BCM54282_AUTO_POWER_DOWNr_AUTO_POWER_DOWNf_GET
#define AUTO_POWER_DOWNr_AUTO_POWER_DOWNf_SET BCM54282_AUTO_POWER_DOWNr_AUTO_POWER_DOWNf_SET
#define READ_AUTO_POWER_DOWNr BCM54282_READ_AUTO_POWER_DOWNr
#define WRITE_AUTO_POWER_DOWNr BCM54282_WRITE_AUTO_POWER_DOWNr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_AUTO_POWER_DOWNr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  SLED_1
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     SLED 1 (Addr 1Ch shadow 01011b)
 * SIZE:     32
 * FIELDS:
 *     SLED_1           SLED_1
 *
 ******************************************************************************/
#define BCM54282_SLED_1r (0x00000b1c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_SLED_1r_SIZE 4

/*
 * This structure should be used to declare and program SLED_1.
 *
 */
typedef union BCM54282_SLED_1r_s {
	uint32_t v[1];
	uint32_t sled_1[1];
	uint32_t _sled_1;
} BCM54282_SLED_1r_t;

#define BCM54282_SLED_1r_CLR(r) (r).sled_1[0] = 0
#define BCM54282_SLED_1r_SET(r,d) (r).sled_1[0] = d
#define BCM54282_SLED_1r_GET(r) (r).sled_1[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_SLED_1r_SLED_1f_GET(r) (((r).sled_1[0]) & 0xffff)
#define BCM54282_SLED_1r_SLED_1f_SET(r,f) (r).sled_1[0]=(((r).sled_1[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access SLED_1.
 *
 */
#define BCM54282_READ_SLED_1r(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_SLED_1r,(_r._sled_1))
#define BCM54282_WRITE_SLED_1r(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_SLED_1r,(_r._sled_1))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define SLED_1r BCM54282_SLED_1r
#define SLED_1r_SIZE BCM54282_SLED_1r_SIZE
typedef BCM54282_SLED_1r_t SLED_1r_t;
#define SLED_1r_CLR BCM54282_SLED_1r_CLR
#define SLED_1r_SET BCM54282_SLED_1r_SET
#define SLED_1r_GET BCM54282_SLED_1r_GET
#define SLED_1r_SLED_1f_GET BCM54282_SLED_1r_SLED_1f_GET
#define SLED_1r_SLED_1f_SET BCM54282_SLED_1r_SLED_1f_SET
#define READ_SLED_1r BCM54282_READ_SLED_1r
#define WRITE_SLED_1r BCM54282_WRITE_SLED_1r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_SLED_1r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  SLED_2
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     SLED 2 (Addr 1Ch shadow 01100b)
 * SIZE:     32
 * FIELDS:
 *     SLED_2           SLED_2
 *
 ******************************************************************************/
#define BCM54282_SLED_2r (0x00000c1c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_SLED_2r_SIZE 4

/*
 * This structure should be used to declare and program SLED_2.
 *
 */
typedef union BCM54282_SLED_2r_s {
	uint32_t v[1];
	uint32_t sled_2[1];
	uint32_t _sled_2;
} BCM54282_SLED_2r_t;

#define BCM54282_SLED_2r_CLR(r) (r).sled_2[0] = 0
#define BCM54282_SLED_2r_SET(r,d) (r).sled_2[0] = d
#define BCM54282_SLED_2r_GET(r) (r).sled_2[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_SLED_2r_SLED_2f_GET(r) (((r).sled_2[0]) & 0xffff)
#define BCM54282_SLED_2r_SLED_2f_SET(r,f) (r).sled_2[0]=(((r).sled_2[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access SLED_2.
 *
 */
#define BCM54282_READ_SLED_2r(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_SLED_2r,(_r._sled_2))
#define BCM54282_WRITE_SLED_2r(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_SLED_2r,(_r._sled_2))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define SLED_2r BCM54282_SLED_2r
#define SLED_2r_SIZE BCM54282_SLED_2r_SIZE
typedef BCM54282_SLED_2r_t SLED_2r_t;
#define SLED_2r_CLR BCM54282_SLED_2r_CLR
#define SLED_2r_SET BCM54282_SLED_2r_SET
#define SLED_2r_GET BCM54282_SLED_2r_GET
#define SLED_2r_SLED_2f_GET BCM54282_SLED_2r_SLED_2f_GET
#define SLED_2r_SLED_2f_SET BCM54282_SLED_2r_SLED_2f_SET
#define READ_SLED_2r BCM54282_READ_SLED_2r
#define WRITE_SLED_2r BCM54282_WRITE_SLED_2r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_SLED_2r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  LED_SELECTOR_1
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T LED Selector 1 Reg (Addr 1Ch shadow 01101b)
 * SIZE:     32
 * FIELDS:
 *     LED_SELECTOR_1   LED_SELECTOR_1
 *
 ******************************************************************************/
#define BCM54282_LED_SELECTOR_1r (0x00000d1c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_LED_SELECTOR_1r_SIZE 4

/*
 * This structure should be used to declare and program LED_SELECTOR_1.
 *
 */
typedef union BCM54282_LED_SELECTOR_1r_s {
	uint32_t v[1];
	uint32_t led_selector_1[1];
	uint32_t _led_selector_1;
} BCM54282_LED_SELECTOR_1r_t;

#define BCM54282_LED_SELECTOR_1r_CLR(r) (r).led_selector_1[0] = 0
#define BCM54282_LED_SELECTOR_1r_SET(r,d) (r).led_selector_1[0] = d
#define BCM54282_LED_SELECTOR_1r_GET(r) (r).led_selector_1[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_LED_SELECTOR_1r_LED_SELECTOR_1f_GET(r) (((r).led_selector_1[0]) & 0xffff)
#define BCM54282_LED_SELECTOR_1r_LED_SELECTOR_1f_SET(r,f) (r).led_selector_1[0]=(((r).led_selector_1[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access LED_SELECTOR_1.
 *
 */
#define BCM54282_READ_LED_SELECTOR_1r(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_LED_SELECTOR_1r,(_r._led_selector_1))
#define BCM54282_WRITE_LED_SELECTOR_1r(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_LED_SELECTOR_1r,(_r._led_selector_1))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define LED_SELECTOR_1r BCM54282_LED_SELECTOR_1r
#define LED_SELECTOR_1r_SIZE BCM54282_LED_SELECTOR_1r_SIZE
typedef BCM54282_LED_SELECTOR_1r_t LED_SELECTOR_1r_t;
#define LED_SELECTOR_1r_CLR BCM54282_LED_SELECTOR_1r_CLR
#define LED_SELECTOR_1r_SET BCM54282_LED_SELECTOR_1r_SET
#define LED_SELECTOR_1r_GET BCM54282_LED_SELECTOR_1r_GET
#define LED_SELECTOR_1r_LED_SELECTOR_1f_GET BCM54282_LED_SELECTOR_1r_LED_SELECTOR_1f_GET
#define LED_SELECTOR_1r_LED_SELECTOR_1f_SET BCM54282_LED_SELECTOR_1r_LED_SELECTOR_1f_SET
#define READ_LED_SELECTOR_1r BCM54282_READ_LED_SELECTOR_1r
#define WRITE_LED_SELECTOR_1r BCM54282_WRITE_LED_SELECTOR_1r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_LED_SELECTOR_1r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  LED_SELECTOR_2
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T LED Selector 2 Reg (Addr 1Ch shadow 01110b)
 * SIZE:     32
 * FIELDS:
 *     LED_SELECTOR_2   LED_SELECTOR_2
 *
 ******************************************************************************/
#define BCM54282_LED_SELECTOR_2r (0x00000e1c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_LED_SELECTOR_2r_SIZE 4

/*
 * This structure should be used to declare and program LED_SELECTOR_2.
 *
 */
typedef union BCM54282_LED_SELECTOR_2r_s {
	uint32_t v[1];
	uint32_t led_selector_2[1];
	uint32_t _led_selector_2;
} BCM54282_LED_SELECTOR_2r_t;

#define BCM54282_LED_SELECTOR_2r_CLR(r) (r).led_selector_2[0] = 0
#define BCM54282_LED_SELECTOR_2r_SET(r,d) (r).led_selector_2[0] = d
#define BCM54282_LED_SELECTOR_2r_GET(r) (r).led_selector_2[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_LED_SELECTOR_2r_LED_SELECTOR_2f_GET(r) (((r).led_selector_2[0]) & 0xffff)
#define BCM54282_LED_SELECTOR_2r_LED_SELECTOR_2f_SET(r,f) (r).led_selector_2[0]=(((r).led_selector_2[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access LED_SELECTOR_2.
 *
 */
#define BCM54282_READ_LED_SELECTOR_2r(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_LED_SELECTOR_2r,(_r._led_selector_2))
#define BCM54282_WRITE_LED_SELECTOR_2r(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_LED_SELECTOR_2r,(_r._led_selector_2))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define LED_SELECTOR_2r BCM54282_LED_SELECTOR_2r
#define LED_SELECTOR_2r_SIZE BCM54282_LED_SELECTOR_2r_SIZE
typedef BCM54282_LED_SELECTOR_2r_t LED_SELECTOR_2r_t;
#define LED_SELECTOR_2r_CLR BCM54282_LED_SELECTOR_2r_CLR
#define LED_SELECTOR_2r_SET BCM54282_LED_SELECTOR_2r_SET
#define LED_SELECTOR_2r_GET BCM54282_LED_SELECTOR_2r_GET
#define LED_SELECTOR_2r_LED_SELECTOR_2f_GET BCM54282_LED_SELECTOR_2r_LED_SELECTOR_2f_GET
#define LED_SELECTOR_2r_LED_SELECTOR_2f_SET BCM54282_LED_SELECTOR_2r_LED_SELECTOR_2f_SET
#define READ_LED_SELECTOR_2r BCM54282_READ_LED_SELECTOR_2r
#define WRITE_LED_SELECTOR_2r BCM54282_WRITE_LED_SELECTOR_2r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_LED_SELECTOR_2r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  LED_GPIO_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T LED GPIO Ctrl/Stat (Addr 1Ch shadow 01111b)
 * SIZE:     32
 * FIELDS:
 *     CURRENT_LED_DISABLE Constant Current LED mode disable.
 *     SHD1C_SEL        LED_GPIO_CONTROL_STATUS Register.
 *     WRITE_EN         Write enable.
 *
 ******************************************************************************/
#define BCM54282_LED_GPIO_CTRLr (0x00000f1c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_LED_GPIO_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program LED_GPIO_CTRL.
 *
 */
typedef union BCM54282_LED_GPIO_CTRLr_s {
	uint32_t v[1];
	uint32_t led_gpio_ctrl[1];
	uint32_t _led_gpio_ctrl;
} BCM54282_LED_GPIO_CTRLr_t;

#define BCM54282_LED_GPIO_CTRLr_CLR(r) (r).led_gpio_ctrl[0] = 0
#define BCM54282_LED_GPIO_CTRLr_SET(r,d) (r).led_gpio_ctrl[0] = d
#define BCM54282_LED_GPIO_CTRLr_GET(r) (r).led_gpio_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_LED_GPIO_CTRLr_WRITE_ENf_GET(r) ((((r).led_gpio_ctrl[0]) >> 15) & 0x1)
#define BCM54282_LED_GPIO_CTRLr_WRITE_ENf_SET(r,f) (r).led_gpio_ctrl[0]=(((r).led_gpio_ctrl[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_LED_GPIO_CTRLr_SHD1C_SELf_GET(r) ((((r).led_gpio_ctrl[0]) >> 10) & 0x1f)
#define BCM54282_LED_GPIO_CTRLr_SHD1C_SELf_SET(r,f) (r).led_gpio_ctrl[0]=(((r).led_gpio_ctrl[0] & ~((uint32_t)0x1f << 10)) | ((((uint32_t)f) & 0x1f) << 10))
#define BCM54282_LED_GPIO_CTRLr_CURRENT_LED_DISABLEf_GET(r) (((r).led_gpio_ctrl[0]) & 0xf)
#define BCM54282_LED_GPIO_CTRLr_CURRENT_LED_DISABLEf_SET(r,f) (r).led_gpio_ctrl[0]=(((r).led_gpio_ctrl[0] & ~((uint32_t)0xf)) | (((uint32_t)f) & 0xf))

/*
 * These macros can be used to access LED_GPIO_CTRL.
 *
 */
#define BCM54282_READ_LED_GPIO_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_LED_GPIO_CTRLr,(_r._led_gpio_ctrl))
#define BCM54282_WRITE_LED_GPIO_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_LED_GPIO_CTRLr,(_r._led_gpio_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define LED_GPIO_CTRLr BCM54282_LED_GPIO_CTRLr
#define LED_GPIO_CTRLr_SIZE BCM54282_LED_GPIO_CTRLr_SIZE
typedef BCM54282_LED_GPIO_CTRLr_t LED_GPIO_CTRLr_t;
#define LED_GPIO_CTRLr_CLR BCM54282_LED_GPIO_CTRLr_CLR
#define LED_GPIO_CTRLr_SET BCM54282_LED_GPIO_CTRLr_SET
#define LED_GPIO_CTRLr_GET BCM54282_LED_GPIO_CTRLr_GET
#define LED_GPIO_CTRLr_WRITE_ENf_GET BCM54282_LED_GPIO_CTRLr_WRITE_ENf_GET
#define LED_GPIO_CTRLr_WRITE_ENf_SET BCM54282_LED_GPIO_CTRLr_WRITE_ENf_SET
#define LED_GPIO_CTRLr_SHD1C_SELf_GET BCM54282_LED_GPIO_CTRLr_SHD1C_SELf_GET
#define LED_GPIO_CTRLr_SHD1C_SELf_SET BCM54282_LED_GPIO_CTRLr_SHD1C_SELf_SET
#define LED_GPIO_CTRLr_CURRENT_LED_DISABLEf_GET BCM54282_LED_GPIO_CTRLr_CURRENT_LED_DISABLEf_GET
#define LED_GPIO_CTRLr_CURRENT_LED_DISABLEf_SET BCM54282_LED_GPIO_CTRLr_CURRENT_LED_DISABLEf_SET
#define READ_LED_GPIO_CTRLr BCM54282_READ_LED_GPIO_CTRLr
#define WRITE_LED_GPIO_CTRLr BCM54282_WRITE_LED_GPIO_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_LED_GPIO_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  FAST_LINK_DROP_DETECT
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     1000BASE-T Fast Link Drop Detection Reg (Addr 1Ch shadow 10000b)
 * SIZE:     32
 * FIELDS:
 *     FAST_LINK_DROP_DETECT FAST_LINK_DROP_DETECT
 *
 ******************************************************************************/
#define BCM54282_FAST_LINK_DROP_DETECTr (0x0000101c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_FAST_LINK_DROP_DETECTr_SIZE 4

/*
 * This structure should be used to declare and program FAST_LINK_DROP_DETECT.
 *
 */
typedef union BCM54282_FAST_LINK_DROP_DETECTr_s {
	uint32_t v[1];
	uint32_t fast_link_drop_detect[1];
	uint32_t _fast_link_drop_detect;
} BCM54282_FAST_LINK_DROP_DETECTr_t;

#define BCM54282_FAST_LINK_DROP_DETECTr_CLR(r) (r).fast_link_drop_detect[0] = 0
#define BCM54282_FAST_LINK_DROP_DETECTr_SET(r,d) (r).fast_link_drop_detect[0] = d
#define BCM54282_FAST_LINK_DROP_DETECTr_GET(r) (r).fast_link_drop_detect[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_FAST_LINK_DROP_DETECTr_FAST_LINK_DROP_DETECTf_GET(r) (((r).fast_link_drop_detect[0]) & 0xffff)
#define BCM54282_FAST_LINK_DROP_DETECTr_FAST_LINK_DROP_DETECTf_SET(r,f) (r).fast_link_drop_detect[0]=(((r).fast_link_drop_detect[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access FAST_LINK_DROP_DETECT.
 *
 */
#define BCM54282_READ_FAST_LINK_DROP_DETECTr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_FAST_LINK_DROP_DETECTr,(_r._fast_link_drop_detect))
#define BCM54282_WRITE_FAST_LINK_DROP_DETECTr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_FAST_LINK_DROP_DETECTr,(_r._fast_link_drop_detect))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define FAST_LINK_DROP_DETECTr BCM54282_FAST_LINK_DROP_DETECTr
#define FAST_LINK_DROP_DETECTr_SIZE BCM54282_FAST_LINK_DROP_DETECTr_SIZE
typedef BCM54282_FAST_LINK_DROP_DETECTr_t FAST_LINK_DROP_DETECTr_t;
#define FAST_LINK_DROP_DETECTr_CLR BCM54282_FAST_LINK_DROP_DETECTr_CLR
#define FAST_LINK_DROP_DETECTr_SET BCM54282_FAST_LINK_DROP_DETECTr_SET
#define FAST_LINK_DROP_DETECTr_GET BCM54282_FAST_LINK_DROP_DETECTr_GET
#define FAST_LINK_DROP_DETECTr_FAST_LINK_DROP_DETECTf_GET BCM54282_FAST_LINK_DROP_DETECTr_FAST_LINK_DROP_DETECTf_GET
#define FAST_LINK_DROP_DETECTr_FAST_LINK_DROP_DETECTf_SET BCM54282_FAST_LINK_DROP_DETECTr_FAST_LINK_DROP_DETECTf_SET
#define READ_FAST_LINK_DROP_DETECTr BCM54282_READ_FAST_LINK_DROP_DETECTr
#define WRITE_FAST_LINK_DROP_DETECTr BCM54282_WRITE_FAST_LINK_DROP_DETECTr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_FAST_LINK_DROP_DETECTr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  REG_100FX_STAT
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     SerDes 100BASE-FX Status Reg (ADDR 1ch shadow 10001b)
 * SIZE:     32
 * FIELDS:
 *     REG_100FX_STAT   REG_100FX_STAT
 *
 ******************************************************************************/
#define BCM54282_REG_100FX_STATr (0x0000111c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_REG_100FX_STATr_SIZE 4

/*
 * This structure should be used to declare and program REG_100FX_STAT.
 *
 */
typedef union BCM54282_REG_100FX_STATr_s {
	uint32_t v[1];
	uint32_t reg_100fx_stat[1];
	uint32_t _reg_100fx_stat;
} BCM54282_REG_100FX_STATr_t;

#define BCM54282_REG_100FX_STATr_CLR(r) (r).reg_100fx_stat[0] = 0
#define BCM54282_REG_100FX_STATr_SET(r,d) (r).reg_100fx_stat[0] = d
#define BCM54282_REG_100FX_STATr_GET(r) (r).reg_100fx_stat[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_REG_100FX_STATr_REG_100FX_STATf_GET(r) (((r).reg_100fx_stat[0]) & 0xffff)
#define BCM54282_REG_100FX_STATr_REG_100FX_STATf_SET(r,f) (r).reg_100fx_stat[0]=(((r).reg_100fx_stat[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access REG_100FX_STAT.
 *
 */
#define BCM54282_READ_REG_100FX_STATr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_REG_100FX_STATr,(_r._reg_100fx_stat))
#define BCM54282_WRITE_REG_100FX_STATr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_REG_100FX_STATr,(_r._reg_100fx_stat))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define REG_100FX_STATr BCM54282_REG_100FX_STATr
#define REG_100FX_STATr_SIZE BCM54282_REG_100FX_STATr_SIZE
typedef BCM54282_REG_100FX_STATr_t REG_100FX_STATr_t;
#define REG_100FX_STATr_CLR BCM54282_REG_100FX_STATr_CLR
#define REG_100FX_STATr_SET BCM54282_REG_100FX_STATr_SET
#define REG_100FX_STATr_GET BCM54282_REG_100FX_STATr_GET
#define REG_100FX_STATr_REG_100FX_STATf_GET BCM54282_REG_100FX_STATr_REG_100FX_STATf_GET
#define REG_100FX_STATr_REG_100FX_STATf_SET BCM54282_REG_100FX_STATr_REG_100FX_STATf_SET
#define READ_REG_100FX_STATr BCM54282_READ_REG_100FX_STATr
#define WRITE_REG_100FX_STATr BCM54282_WRITE_REG_100FX_STATr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_REG_100FX_STATr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  REG_100FX_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     SerDes 100BASE-FX Control Reg (ADDR 1ch shadow 10011b)
 * SIZE:     32
 * FIELDS:
 *     REG_100FX_CTRL   REG_100FX_CTRL
 *
 ******************************************************************************/
#define BCM54282_REG_100FX_CTRLr (0x0000131c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_REG_100FX_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program REG_100FX_CTRL.
 *
 */
typedef union BCM54282_REG_100FX_CTRLr_s {
	uint32_t v[1];
	uint32_t reg_100fx_ctrl[1];
	uint32_t _reg_100fx_ctrl;
} BCM54282_REG_100FX_CTRLr_t;

#define BCM54282_REG_100FX_CTRLr_CLR(r) (r).reg_100fx_ctrl[0] = 0
#define BCM54282_REG_100FX_CTRLr_SET(r,d) (r).reg_100fx_ctrl[0] = d
#define BCM54282_REG_100FX_CTRLr_GET(r) (r).reg_100fx_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_REG_100FX_CTRLr_REG_100FX_CTRLf_GET(r) (((r).reg_100fx_ctrl[0]) & 0xffff)
#define BCM54282_REG_100FX_CTRLr_REG_100FX_CTRLf_SET(r,f) (r).reg_100fx_ctrl[0]=(((r).reg_100fx_ctrl[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access REG_100FX_CTRL.
 *
 */
#define BCM54282_READ_REG_100FX_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_REG_100FX_CTRLr,(_r._reg_100fx_ctrl))
#define BCM54282_WRITE_REG_100FX_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_REG_100FX_CTRLr,(_r._reg_100fx_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define REG_100FX_CTRLr BCM54282_REG_100FX_CTRLr
#define REG_100FX_CTRLr_SIZE BCM54282_REG_100FX_CTRLr_SIZE
typedef BCM54282_REG_100FX_CTRLr_t REG_100FX_CTRLr_t;
#define REG_100FX_CTRLr_CLR BCM54282_REG_100FX_CTRLr_CLR
#define REG_100FX_CTRLr_SET BCM54282_REG_100FX_CTRLr_SET
#define REG_100FX_CTRLr_GET BCM54282_REG_100FX_CTRLr_GET
#define REG_100FX_CTRLr_REG_100FX_CTRLf_GET BCM54282_REG_100FX_CTRLr_REG_100FX_CTRLf_GET
#define REG_100FX_CTRLr_REG_100FX_CTRLf_SET BCM54282_REG_100FX_CTRLr_REG_100FX_CTRLf_SET
#define READ_REG_100FX_CTRLr BCM54282_READ_REG_100FX_CTRLr
#define WRITE_REG_100FX_CTRLr BCM54282_WRITE_REG_100FX_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_REG_100FX_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  SGMII_SLAVE
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     SGMII Slave Reg (ADDR 1ch shadow 10101b)
 * SIZE:     32
 * FIELDS:
 *     SGMII_SLAVE_AUTO_DETECT 
 *     SGMII_SLAVE_MODE 
 *     RGMII_MII_SLV_FREQ_LOCK 
 *     MODE_SELECT      
 *     SERDES_LINK_STAT_CHNG 
 *     SERDES_SPEED     
 *     SERDES_DUPLEX    
 *     SERDES_LINK      
 *
 ******************************************************************************/
#define BCM54282_SGMII_SLAVEr (0x0000151c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_SGMII_SLAVEr_SIZE 4

/*
 * This structure should be used to declare and program SGMII_SLAVE.
 *
 */
typedef union BCM54282_SGMII_SLAVEr_s {
	uint32_t v[1];
	uint32_t sgmii_slave[1];
	uint32_t _sgmii_slave;
} BCM54282_SGMII_SLAVEr_t;

#define BCM54282_SGMII_SLAVEr_CLR(r) (r).sgmii_slave[0] = 0
#define BCM54282_SGMII_SLAVEr_SET(r,d) (r).sgmii_slave[0] = d
#define BCM54282_SGMII_SLAVEr_GET(r) (r).sgmii_slave[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_SGMII_SLAVEr_SERDES_LINKf_GET(r) ((((r).sgmii_slave[0]) >> 9) & 0x1)
#define BCM54282_SGMII_SLAVEr_SERDES_LINKf_SET(r,f) (r).sgmii_slave[0]=(((r).sgmii_slave[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
#define BCM54282_SGMII_SLAVEr_SERDES_DUPLEXf_GET(r) ((((r).sgmii_slave[0]) >> 8) & 0x1)
#define BCM54282_SGMII_SLAVEr_SERDES_DUPLEXf_SET(r,f) (r).sgmii_slave[0]=(((r).sgmii_slave[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))
#define BCM54282_SGMII_SLAVEr_SERDES_SPEEDf_GET(r) ((((r).sgmii_slave[0]) >> 6) & 0x3)
#define BCM54282_SGMII_SLAVEr_SERDES_SPEEDf_SET(r,f) (r).sgmii_slave[0]=(((r).sgmii_slave[0] & ~((uint32_t)0x3 << 6)) | ((((uint32_t)f) & 0x3) << 6))
#define BCM54282_SGMII_SLAVEr_SERDES_LINK_STAT_CHNGf_GET(r) ((((r).sgmii_slave[0]) >> 5) & 0x1)
#define BCM54282_SGMII_SLAVEr_SERDES_LINK_STAT_CHNGf_SET(r,f) (r).sgmii_slave[0]=(((r).sgmii_slave[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))
#define BCM54282_SGMII_SLAVEr_MODE_SELECTf_GET(r) ((((r).sgmii_slave[0]) >> 3) & 0x3)
#define BCM54282_SGMII_SLAVEr_MODE_SELECTf_SET(r,f) (r).sgmii_slave[0]=(((r).sgmii_slave[0] & ~((uint32_t)0x3 << 3)) | ((((uint32_t)f) & 0x3) << 3))
#define BCM54282_SGMII_SLAVEr_RGMII_MII_SLV_FREQ_LOCKf_GET(r) ((((r).sgmii_slave[0]) >> 2) & 0x1)
#define BCM54282_SGMII_SLAVEr_RGMII_MII_SLV_FREQ_LOCKf_SET(r,f) (r).sgmii_slave[0]=(((r).sgmii_slave[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_SGMII_SLAVEr_SGMII_SLAVE_MODEf_GET(r) ((((r).sgmii_slave[0]) >> 1) & 0x1)
#define BCM54282_SGMII_SLAVEr_SGMII_SLAVE_MODEf_SET(r,f) (r).sgmii_slave[0]=(((r).sgmii_slave[0] & ~((uint32_t)0x1 << 1)) | ((((uint32_t)f) & 0x1) << 1))
#define BCM54282_SGMII_SLAVEr_SGMII_SLAVE_AUTO_DETECTf_GET(r) (((r).sgmii_slave[0]) & 0x1)
#define BCM54282_SGMII_SLAVEr_SGMII_SLAVE_AUTO_DETECTf_SET(r,f) (r).sgmii_slave[0]=(((r).sgmii_slave[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access SGMII_SLAVE.
 *
 */
#define BCM54282_READ_SGMII_SLAVEr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_SGMII_SLAVEr,(_r._sgmii_slave))
#define BCM54282_WRITE_SGMII_SLAVEr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_SGMII_SLAVEr,(_r._sgmii_slave))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define SGMII_SLAVEr BCM54282_SGMII_SLAVEr
#define SGMII_SLAVEr_SIZE BCM54282_SGMII_SLAVEr_SIZE
typedef BCM54282_SGMII_SLAVEr_t SGMII_SLAVEr_t;
#define SGMII_SLAVEr_CLR BCM54282_SGMII_SLAVEr_CLR
#define SGMII_SLAVEr_SET BCM54282_SGMII_SLAVEr_SET
#define SGMII_SLAVEr_GET BCM54282_SGMII_SLAVEr_GET
#define SGMII_SLAVEr_SERDES_LINKf_GET BCM54282_SGMII_SLAVEr_SERDES_LINKf_GET
#define SGMII_SLAVEr_SERDES_LINKf_SET BCM54282_SGMII_SLAVEr_SERDES_LINKf_SET
#define SGMII_SLAVEr_SERDES_DUPLEXf_GET BCM54282_SGMII_SLAVEr_SERDES_DUPLEXf_GET
#define SGMII_SLAVEr_SERDES_DUPLEXf_SET BCM54282_SGMII_SLAVEr_SERDES_DUPLEXf_SET
#define SGMII_SLAVEr_SERDES_SPEEDf_GET BCM54282_SGMII_SLAVEr_SERDES_SPEEDf_GET
#define SGMII_SLAVEr_SERDES_SPEEDf_SET BCM54282_SGMII_SLAVEr_SERDES_SPEEDf_SET
#define SGMII_SLAVEr_SERDES_LINK_STAT_CHNGf_GET BCM54282_SGMII_SLAVEr_SERDES_LINK_STAT_CHNGf_GET
#define SGMII_SLAVEr_SERDES_LINK_STAT_CHNGf_SET BCM54282_SGMII_SLAVEr_SERDES_LINK_STAT_CHNGf_SET
#define SGMII_SLAVEr_MODE_SELECTf_GET BCM54282_SGMII_SLAVEr_MODE_SELECTf_GET
#define SGMII_SLAVEr_MODE_SELECTf_SET BCM54282_SGMII_SLAVEr_MODE_SELECTf_SET
#define SGMII_SLAVEr_RGMII_MII_SLV_FREQ_LOCKf_GET BCM54282_SGMII_SLAVEr_RGMII_MII_SLV_FREQ_LOCKf_GET
#define SGMII_SLAVEr_RGMII_MII_SLV_FREQ_LOCKf_SET BCM54282_SGMII_SLAVEr_RGMII_MII_SLV_FREQ_LOCKf_SET
#define SGMII_SLAVEr_SGMII_SLAVE_MODEf_GET BCM54282_SGMII_SLAVEr_SGMII_SLAVE_MODEf_GET
#define SGMII_SLAVEr_SGMII_SLAVE_MODEf_SET BCM54282_SGMII_SLAVEr_SGMII_SLAVE_MODEf_SET
#define SGMII_SLAVEr_SGMII_SLAVE_AUTO_DETECTf_GET BCM54282_SGMII_SLAVEr_SGMII_SLAVE_AUTO_DETECTf_GET
#define SGMII_SLAVEr_SGMII_SLAVE_AUTO_DETECTf_SET BCM54282_SGMII_SLAVEr_SGMII_SLAVE_AUTO_DETECTf_SET
#define READ_SGMII_SLAVEr BCM54282_READ_SGMII_SLAVEr
#define WRITE_SGMII_SLAVEr BCM54282_WRITE_SGMII_SLAVEr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_SGMII_SLAVEr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MISC_1000X_CTRL_2
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     1000BASE-X Misc 1000BASE-X Control Reg (Addr 1Ch shadow 10110b)
 * SIZE:     32
 * FIELDS:
 *     SERDES_JUMBO_MSB SGMII/Fiber jumbo packet support(MSB)
 *
 ******************************************************************************/
#define BCM54282_MISC_1000X_CTRL_2r (0x0000161c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_MISC_1000X_CTRL_2r_SIZE 4

/*
 * This structure should be used to declare and program MISC_1000X_CTRL_2.
 *
 */
typedef union BCM54282_MISC_1000X_CTRL_2r_s {
	uint32_t v[1];
	uint32_t misc_1000x_ctrl_2[1];
	uint32_t _misc_1000x_ctrl_2;
} BCM54282_MISC_1000X_CTRL_2r_t;

#define BCM54282_MISC_1000X_CTRL_2r_CLR(r) (r).misc_1000x_ctrl_2[0] = 0
#define BCM54282_MISC_1000X_CTRL_2r_SET(r,d) (r).misc_1000x_ctrl_2[0] = d
#define BCM54282_MISC_1000X_CTRL_2r_GET(r) (r).misc_1000x_ctrl_2[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MISC_1000X_CTRL_2r_SERDES_JUMBO_MSBf_GET(r) (((r).misc_1000x_ctrl_2[0]) & 0x1)
#define BCM54282_MISC_1000X_CTRL_2r_SERDES_JUMBO_MSBf_SET(r,f) (r).misc_1000x_ctrl_2[0]=(((r).misc_1000x_ctrl_2[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MISC_1000X_CTRL_2.
 *
 */
#define BCM54282_READ_MISC_1000X_CTRL_2r(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_MISC_1000X_CTRL_2r,(_r._misc_1000x_ctrl_2))
#define BCM54282_WRITE_MISC_1000X_CTRL_2r(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_MISC_1000X_CTRL_2r,(_r._misc_1000x_ctrl_2))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MISC_1000X_CTRL_2r BCM54282_MISC_1000X_CTRL_2r
#define MISC_1000X_CTRL_2r_SIZE BCM54282_MISC_1000X_CTRL_2r_SIZE
typedef BCM54282_MISC_1000X_CTRL_2r_t MISC_1000X_CTRL_2r_t;
#define MISC_1000X_CTRL_2r_CLR BCM54282_MISC_1000X_CTRL_2r_CLR
#define MISC_1000X_CTRL_2r_SET BCM54282_MISC_1000X_CTRL_2r_SET
#define MISC_1000X_CTRL_2r_GET BCM54282_MISC_1000X_CTRL_2r_GET
#define MISC_1000X_CTRL_2r_SERDES_JUMBO_MSBf_GET BCM54282_MISC_1000X_CTRL_2r_SERDES_JUMBO_MSBf_GET
#define MISC_1000X_CTRL_2r_SERDES_JUMBO_MSBf_SET BCM54282_MISC_1000X_CTRL_2r_SERDES_JUMBO_MSBf_SET
#define READ_MISC_1000X_CTRL_2r BCM54282_READ_MISC_1000X_CTRL_2r
#define WRITE_MISC_1000X_CTRL_2r BCM54282_WRITE_MISC_1000X_CTRL_2r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MISC_1000X_CTRL_2r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  AUTO_DETECT_SGMII_MEDIA
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     1000BASE-X Auto-Detect SGMII/Media Converter Reg (Addr 1Ch shadow 11000b)
 * SIZE:     32
 * FIELDS:
 *     AUTO_DETECT_SGMII_MEDIA AUTO_DETECT_SGMII_MEDIA
 *
 ******************************************************************************/
#define BCM54282_AUTO_DETECT_SGMII_MEDIAr (0x0000181c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_AUTO_DETECT_SGMII_MEDIAr_SIZE 4

/*
 * This structure should be used to declare and program AUTO_DETECT_SGMII_MEDIA.
 *
 */
typedef union BCM54282_AUTO_DETECT_SGMII_MEDIAr_s {
	uint32_t v[1];
	uint32_t auto_detect_sgmii_media[1];
	uint32_t _auto_detect_sgmii_media;
} BCM54282_AUTO_DETECT_SGMII_MEDIAr_t;

#define BCM54282_AUTO_DETECT_SGMII_MEDIAr_CLR(r) (r).auto_detect_sgmii_media[0] = 0
#define BCM54282_AUTO_DETECT_SGMII_MEDIAr_SET(r,d) (r).auto_detect_sgmii_media[0] = d
#define BCM54282_AUTO_DETECT_SGMII_MEDIAr_GET(r) (r).auto_detect_sgmii_media[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_AUTO_DETECT_SGMII_MEDIAr_AUTO_DETECT_SGMII_MEDIAf_GET(r) (((r).auto_detect_sgmii_media[0]) & 0xffff)
#define BCM54282_AUTO_DETECT_SGMII_MEDIAr_AUTO_DETECT_SGMII_MEDIAf_SET(r,f) (r).auto_detect_sgmii_media[0]=(((r).auto_detect_sgmii_media[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access AUTO_DETECT_SGMII_MEDIA.
 *
 */
#define BCM54282_READ_AUTO_DETECT_SGMII_MEDIAr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_AUTO_DETECT_SGMII_MEDIAr,(_r._auto_detect_sgmii_media))
#define BCM54282_WRITE_AUTO_DETECT_SGMII_MEDIAr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_AUTO_DETECT_SGMII_MEDIAr,(_r._auto_detect_sgmii_media))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define AUTO_DETECT_SGMII_MEDIAr BCM54282_AUTO_DETECT_SGMII_MEDIAr
#define AUTO_DETECT_SGMII_MEDIAr_SIZE BCM54282_AUTO_DETECT_SGMII_MEDIAr_SIZE
typedef BCM54282_AUTO_DETECT_SGMII_MEDIAr_t AUTO_DETECT_SGMII_MEDIAr_t;
#define AUTO_DETECT_SGMII_MEDIAr_CLR BCM54282_AUTO_DETECT_SGMII_MEDIAr_CLR
#define AUTO_DETECT_SGMII_MEDIAr_SET BCM54282_AUTO_DETECT_SGMII_MEDIAr_SET
#define AUTO_DETECT_SGMII_MEDIAr_GET BCM54282_AUTO_DETECT_SGMII_MEDIAr_GET
#define AUTO_DETECT_SGMII_MEDIAr_AUTO_DETECT_SGMII_MEDIAf_GET BCM54282_AUTO_DETECT_SGMII_MEDIAr_AUTO_DETECT_SGMII_MEDIAf_GET
#define AUTO_DETECT_SGMII_MEDIAr_AUTO_DETECT_SGMII_MEDIAf_SET BCM54282_AUTO_DETECT_SGMII_MEDIAr_AUTO_DETECT_SGMII_MEDIAf_SET
#define READ_AUTO_DETECT_SGMII_MEDIAr BCM54282_READ_AUTO_DETECT_SGMII_MEDIAr
#define WRITE_AUTO_DETECT_SGMII_MEDIAr BCM54282_WRITE_AUTO_DETECT_SGMII_MEDIAr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_AUTO_DETECT_SGMII_MEDIAr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  AUX_1000X_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     Auxiliary 1000BASE-X Control Reg (Addr 1Ch shadow 11011b)
 * SIZE:     32
 * FIELDS:
 *     SERDES_JUMBO_LSB SGMII/Fiber jumbo packet support(LSB)
 *
 ******************************************************************************/
#define BCM54282_AUX_1000X_CTRLr (0x00001b1c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_AUX_1000X_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program AUX_1000X_CTRL.
 *
 */
typedef union BCM54282_AUX_1000X_CTRLr_s {
	uint32_t v[1];
	uint32_t aux_1000x_ctrl[1];
	uint32_t _aux_1000x_ctrl;
} BCM54282_AUX_1000X_CTRLr_t;

#define BCM54282_AUX_1000X_CTRLr_CLR(r) (r).aux_1000x_ctrl[0] = 0
#define BCM54282_AUX_1000X_CTRLr_SET(r,d) (r).aux_1000x_ctrl[0] = d
#define BCM54282_AUX_1000X_CTRLr_GET(r) (r).aux_1000x_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_AUX_1000X_CTRLr_SERDES_JUMBO_LSBf_GET(r) ((((r).aux_1000x_ctrl[0]) >> 1) & 0x1)
#define BCM54282_AUX_1000X_CTRLr_SERDES_JUMBO_LSBf_SET(r,f) (r).aux_1000x_ctrl[0]=(((r).aux_1000x_ctrl[0] & ~((uint32_t)0x1 << 1)) | ((((uint32_t)f) & 0x1) << 1))

/*
 * These macros can be used to access AUX_1000X_CTRL.
 *
 */
#define BCM54282_READ_AUX_1000X_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_AUX_1000X_CTRLr,(_r._aux_1000x_ctrl))
#define BCM54282_WRITE_AUX_1000X_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_AUX_1000X_CTRLr,(_r._aux_1000x_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define AUX_1000X_CTRLr BCM54282_AUX_1000X_CTRLr
#define AUX_1000X_CTRLr_SIZE BCM54282_AUX_1000X_CTRLr_SIZE
typedef BCM54282_AUX_1000X_CTRLr_t AUX_1000X_CTRLr_t;
#define AUX_1000X_CTRLr_CLR BCM54282_AUX_1000X_CTRLr_CLR
#define AUX_1000X_CTRLr_SET BCM54282_AUX_1000X_CTRLr_SET
#define AUX_1000X_CTRLr_GET BCM54282_AUX_1000X_CTRLr_GET
#define AUX_1000X_CTRLr_SERDES_JUMBO_LSBf_GET BCM54282_AUX_1000X_CTRLr_SERDES_JUMBO_LSBf_GET
#define AUX_1000X_CTRLr_SERDES_JUMBO_LSBf_SET BCM54282_AUX_1000X_CTRLr_SERDES_JUMBO_LSBf_SET
#define READ_AUX_1000X_CTRLr BCM54282_READ_AUX_1000X_CTRLr
#define WRITE_AUX_1000X_CTRLr BCM54282_WRITE_AUX_1000X_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_AUX_1000X_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  AUTO_DETECT_MEDIUM
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     Auto Detect Medium Reg (Addr 1Ch shadow 11110b)
 * SIZE:     32
 * FIELDS:
 *     AUTO_DETECT_MEDIA_ENABLE Enable/Disable Auto-Detect Medium.
 *     AUTO_DETECT_MEDIA_PRIORITY Medium Select Priority.
 *     AUTO_DETECT_MEDIA_DEFAULT Default Medium Select.
 *     QFSD_WITH_SYNC_STATUS Qualify Fiber Signal Detect with Sync Status.
 *     FIBER_LED_MODE   Use Fiber/Copper Led Transmit Mode.
 *     FIBER_INUSE_LED_MODE Drive Transmit Led Active Low When Fiber is Selected.
 *     SIGNAL_DETECT_INVERT Fiber Signal Detect is active low(1)/high(0).
 *
 ******************************************************************************/
#define BCM54282_AUTO_DETECT_MEDIUMr (0x00001e1c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_AUTO_DETECT_MEDIUMr_SIZE 4

/*
 * This structure should be used to declare and program AUTO_DETECT_MEDIUM.
 *
 */
typedef union BCM54282_AUTO_DETECT_MEDIUMr_s {
	uint32_t v[1];
	uint32_t auto_detect_medium[1];
	uint32_t _auto_detect_medium;
} BCM54282_AUTO_DETECT_MEDIUMr_t;

#define BCM54282_AUTO_DETECT_MEDIUMr_CLR(r) (r).auto_detect_medium[0] = 0
#define BCM54282_AUTO_DETECT_MEDIUMr_SET(r,d) (r).auto_detect_medium[0] = d
#define BCM54282_AUTO_DETECT_MEDIUMr_GET(r) (r).auto_detect_medium[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_SGMII_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_ENABLEf_GET(r) ((((r).auto_detect_medium[0]) >> 9) & 0x1)
#define BCM54282_SGMII_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_ENABLEf_SET(r,f) (r).auto_detect_medium[0]=(((r).auto_detect_medium[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
#define BCM54282_AUTO_DETECT_MEDIUMr_SIGNAL_DETECT_INVERTf_GET(r) ((((r).auto_detect_medium[0]) >> 8) & 0x1)
#define BCM54282_AUTO_DETECT_MEDIUMr_SIGNAL_DETECT_INVERTf_SET(r,f) (r).auto_detect_medium[0]=(((r).auto_detect_medium[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))
#define BCM54282_AUTO_DETECT_MEDIUMr_FIBER_INUSE_LED_MODEf_GET(r) ((((r).auto_detect_medium[0]) >> 7) & 0x1)
#define BCM54282_AUTO_DETECT_MEDIUMr_FIBER_INUSE_LED_MODEf_SET(r,f) (r).auto_detect_medium[0]=(((r).auto_detect_medium[0] & ~((uint32_t)0x1 << 7)) | ((((uint32_t)f) & 0x1) << 7))
#define BCM54282_AUTO_DETECT_MEDIUMr_FIBER_LED_MODEf_GET(r) ((((r).auto_detect_medium[0]) >> 6) & 0x1)
#define BCM54282_AUTO_DETECT_MEDIUMr_FIBER_LED_MODEf_SET(r,f) (r).auto_detect_medium[0]=(((r).auto_detect_medium[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))
#define BCM54282_AUTO_DETECT_MEDIUMr_QFSD_WITH_SYNC_STATUSf_GET(r) ((((r).auto_detect_medium[0]) >> 5) & 0x1)
#define BCM54282_AUTO_DETECT_MEDIUMr_QFSD_WITH_SYNC_STATUSf_SET(r,f) (r).auto_detect_medium[0]=(((r).auto_detect_medium[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))
#define BCM54282_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_DEFAULTf_GET(r) ((((r).auto_detect_medium[0]) >> 2) & 0x1)
#define BCM54282_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_DEFAULTf_SET(r,f) (r).auto_detect_medium[0]=(((r).auto_detect_medium[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_PRIORITYf_GET(r) ((((r).auto_detect_medium[0]) >> 1) & 0x1)
#define BCM54282_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_PRIORITYf_SET(r,f) (r).auto_detect_medium[0]=(((r).auto_detect_medium[0] & ~((uint32_t)0x1 << 1)) | ((((uint32_t)f) & 0x1) << 1))
#define BCM54282_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_ENABLEf_GET(r) (((r).auto_detect_medium[0]) & 0x1)
#define BCM54282_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_ENABLEf_SET(r,f) (r).auto_detect_medium[0]=(((r).auto_detect_medium[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access AUTO_DETECT_MEDIUM.
 *
 */
#define BCM54282_READ_AUTO_DETECT_MEDIUMr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_AUTO_DETECT_MEDIUMr,(_r._auto_detect_medium))
#define BCM54282_WRITE_AUTO_DETECT_MEDIUMr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_AUTO_DETECT_MEDIUMr,(_r._auto_detect_medium))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define AUTO_DETECT_MEDIUMr BCM54282_AUTO_DETECT_MEDIUMr
#define AUTO_DETECT_MEDIUMr_SIZE BCM54282_AUTO_DETECT_MEDIUMr_SIZE
typedef BCM54282_AUTO_DETECT_MEDIUMr_t AUTO_DETECT_MEDIUMr_t;
#define AUTO_DETECT_MEDIUMr_CLR BCM54282_AUTO_DETECT_MEDIUMr_CLR
#define AUTO_DETECT_MEDIUMr_SET BCM54282_AUTO_DETECT_MEDIUMr_SET
#define AUTO_DETECT_MEDIUMr_GET BCM54282_AUTO_DETECT_MEDIUMr_GET
#define SGMII_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_ENABLEf_GET BCM54282_SGMII_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_ENABLEf_GET
#define SGMII_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_ENABLEf_SET BCM54282_SGMII_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_ENABLEf_SET
#define AUTO_DETECT_MEDIUMr_SIGNAL_DETECT_INVERTf_GET BCM54282_AUTO_DETECT_MEDIUMr_SIGNAL_DETECT_INVERTf_GET
#define AUTO_DETECT_MEDIUMr_SIGNAL_DETECT_INVERTf_SET BCM54282_AUTO_DETECT_MEDIUMr_SIGNAL_DETECT_INVERTf_SET
#define AUTO_DETECT_MEDIUMr_FIBER_INUSE_LED_MODEf_GET BCM54282_AUTO_DETECT_MEDIUMr_FIBER_INUSE_LED_MODEf_GET
#define AUTO_DETECT_MEDIUMr_FIBER_INUSE_LED_MODEf_SET BCM54282_AUTO_DETECT_MEDIUMr_FIBER_INUSE_LED_MODEf_SET
#define AUTO_DETECT_MEDIUMr_FIBER_LED_MODEf_GET BCM54282_AUTO_DETECT_MEDIUMr_FIBER_LED_MODEf_GET
#define AUTO_DETECT_MEDIUMr_FIBER_LED_MODEf_SET BCM54282_AUTO_DETECT_MEDIUMr_FIBER_LED_MODEf_SET
#define AUTO_DETECT_MEDIUMr_QFSD_WITH_SYNC_STATUSf_GET BCM54282_AUTO_DETECT_MEDIUMr_QFSD_WITH_SYNC_STATUSf_GET
#define AUTO_DETECT_MEDIUMr_QFSD_WITH_SYNC_STATUSf_SET BCM54282_AUTO_DETECT_MEDIUMr_QFSD_WITH_SYNC_STATUSf_SET
#define AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_DEFAULTf_GET BCM54282_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_DEFAULTf_GET
#define AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_DEFAULTf_SET BCM54282_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_DEFAULTf_SET
#define AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_PRIORITYf_GET BCM54282_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_PRIORITYf_GET
#define AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_PRIORITYf_SET BCM54282_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_PRIORITYf_SET
#define AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_ENABLEf_GET BCM54282_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_ENABLEf_GET
#define AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_ENABLEf_SET BCM54282_AUTO_DETECT_MEDIUMr_AUTO_DETECT_MEDIA_ENABLEf_SET
#define READ_AUTO_DETECT_MEDIUMr BCM54282_READ_AUTO_DETECT_MEDIUMr
#define WRITE_AUTO_DETECT_MEDIUMr BCM54282_WRITE_AUTO_DETECT_MEDIUMr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_AUTO_DETECT_MEDIUMr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MODE_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x001c
 * DESC:     Mode Control Reg (Addr 1Ch shadow 11111b)
 * SIZE:     32
 * FIELDS:
 *     REG_1000X_EN     Access Copper registers.
 *     MODE_SEL         Mode select.
 *     SERDES_CAPABLE   SerDes capable.
 *     FIBER_SIGNAL_DET Fiber signal detect.
 *     COPPER_ENG_DET   Copper Energy detected.
 *     SERDES_LINK      Fiber link.
 *     COPPER_LINK      Copper link.
 *     DUAL_SERDES_CAPABLE Dual SerDes capable.
 *
 ******************************************************************************/
#define BCM54282_MODE_CTRLr (0x00001f1c | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_MODE_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program MODE_CTRL.
 *
 */
typedef union BCM54282_MODE_CTRLr_s {
	uint32_t v[1];
	uint32_t mode_ctrl[1];
	uint32_t _mode_ctrl;
} BCM54282_MODE_CTRLr_t;

#define BCM54282_MODE_CTRLr_CLR(r) (r).mode_ctrl[0] = 0
#define BCM54282_MODE_CTRLr_SET(r,d) (r).mode_ctrl[0] = d
#define BCM54282_MODE_CTRLr_GET(r) (r).mode_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MODE_CTRLr_DUAL_SERDES_CAPABLEf_GET(r) ((((r).mode_ctrl[0]) >> 9) & 0x1)
#define BCM54282_MODE_CTRLr_DUAL_SERDES_CAPABLEf_SET(r,f) (r).mode_ctrl[0]=(((r).mode_ctrl[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
#define BCM54282_MODE_CTRLr_COPPER_LINKf_GET(r) ((((r).mode_ctrl[0]) >> 7) & 0x1)
#define BCM54282_MODE_CTRLr_COPPER_LINKf_SET(r,f) (r).mode_ctrl[0]=(((r).mode_ctrl[0] & ~((uint32_t)0x1 << 7)) | ((((uint32_t)f) & 0x1) << 7))
#define BCM54282_MODE_CTRLr_SERDES_LINKf_GET(r) ((((r).mode_ctrl[0]) >> 6) & 0x1)
#define BCM54282_MODE_CTRLr_SERDES_LINKf_SET(r,f) (r).mode_ctrl[0]=(((r).mode_ctrl[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))
#define BCM54282_MODE_CTRLr_COPPER_ENG_DETf_GET(r) ((((r).mode_ctrl[0]) >> 5) & 0x1)
#define BCM54282_MODE_CTRLr_COPPER_ENG_DETf_SET(r,f) (r).mode_ctrl[0]=(((r).mode_ctrl[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))
#define BCM54282_MODE_CTRLr_FIBER_SIGNAL_DETf_GET(r) ((((r).mode_ctrl[0]) >> 4) & 0x1)
#define BCM54282_MODE_CTRLr_FIBER_SIGNAL_DETf_SET(r,f) (r).mode_ctrl[0]=(((r).mode_ctrl[0] & ~((uint32_t)0x1 << 4)) | ((((uint32_t)f) & 0x1) << 4))
#define BCM54282_MODE_CTRLr_SERDES_CAPABLEf_GET(r) ((((r).mode_ctrl[0]) >> 3) & 0x1)
#define BCM54282_MODE_CTRLr_SERDES_CAPABLEf_SET(r,f) (r).mode_ctrl[0]=(((r).mode_ctrl[0] & ~((uint32_t)0x1 << 3)) | ((((uint32_t)f) & 0x1) << 3))
#define BCM54282_MODE_CTRLr_MODE_SELf_GET(r) ((((r).mode_ctrl[0]) >> 1) & 0x3)
#define BCM54282_MODE_CTRLr_MODE_SELf_SET(r,f) (r).mode_ctrl[0]=(((r).mode_ctrl[0] & ~((uint32_t)0x3 << 1)) | ((((uint32_t)f) & 0x3) << 1))
#define BCM54282_MODE_CTRLr_REG_1000X_ENf_GET(r) (((r).mode_ctrl[0]) & 0x1)
#define BCM54282_MODE_CTRLr_REG_1000X_ENf_SET(r,f) (r).mode_ctrl[0]=(((r).mode_ctrl[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MODE_CTRL.
 *
 */
#define BCM54282_READ_MODE_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_MODE_CTRLr,(_r._mode_ctrl))
#define BCM54282_WRITE_MODE_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_MODE_CTRLr,(_r._mode_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MODE_CTRLr BCM54282_MODE_CTRLr
#define MODE_CTRLr_SIZE BCM54282_MODE_CTRLr_SIZE
typedef BCM54282_MODE_CTRLr_t MODE_CTRLr_t;
#define MODE_CTRLr_CLR BCM54282_MODE_CTRLr_CLR
#define MODE_CTRLr_SET BCM54282_MODE_CTRLr_SET
#define MODE_CTRLr_GET BCM54282_MODE_CTRLr_GET
#define MODE_CTRLr_DUAL_SERDES_CAPABLEf_GET BCM54282_MODE_CTRLr_DUAL_SERDES_CAPABLEf_GET
#define MODE_CTRLr_DUAL_SERDES_CAPABLEf_SET BCM54282_MODE_CTRLr_DUAL_SERDES_CAPABLEf_SET
#define MODE_CTRLr_COPPER_LINKf_GET BCM54282_MODE_CTRLr_COPPER_LINKf_GET
#define MODE_CTRLr_COPPER_LINKf_SET BCM54282_MODE_CTRLr_COPPER_LINKf_SET
#define MODE_CTRLr_SERDES_LINKf_GET BCM54282_MODE_CTRLr_SERDES_LINKf_GET
#define MODE_CTRLr_SERDES_LINKf_SET BCM54282_MODE_CTRLr_SERDES_LINKf_SET
#define MODE_CTRLr_COPPER_ENG_DETf_GET BCM54282_MODE_CTRLr_COPPER_ENG_DETf_GET
#define MODE_CTRLr_COPPER_ENG_DETf_SET BCM54282_MODE_CTRLr_COPPER_ENG_DETf_SET
#define MODE_CTRLr_FIBER_SIGNAL_DETf_GET BCM54282_MODE_CTRLr_FIBER_SIGNAL_DETf_GET
#define MODE_CTRLr_FIBER_SIGNAL_DETf_SET BCM54282_MODE_CTRLr_FIBER_SIGNAL_DETf_SET
#define MODE_CTRLr_SERDES_CAPABLEf_GET BCM54282_MODE_CTRLr_SERDES_CAPABLEf_GET
#define MODE_CTRLr_SERDES_CAPABLEf_SET BCM54282_MODE_CTRLr_SERDES_CAPABLEf_SET
#define MODE_CTRLr_MODE_SELf_GET BCM54282_MODE_CTRLr_MODE_SELf_GET
#define MODE_CTRLr_MODE_SELf_SET BCM54282_MODE_CTRLr_MODE_SELf_SET
#define MODE_CTRLr_REG_1000X_ENf_GET BCM54282_MODE_CTRLr_REG_1000X_ENf_GET
#define MODE_CTRLr_REG_1000X_ENf_SET BCM54282_MODE_CTRLr_REG_1000X_ENf_SET
#define READ_MODE_CTRLr BCM54282_READ_MODE_CTRLr
#define WRITE_MODE_CTRLr BCM54282_WRITE_MODE_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MODE_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  TEST1
 * BLOCKS:   USER
 * REGADDR:  0x001e
 * DESC:     1000BASE-T/100BASE-TX/10BASE-T Test Register 1 (ADDR 1eh)
 * SIZE:     32
 * FIELDS:
 *     TEST1            TEST1
 *
 ******************************************************************************/
#define BCM54282_TEST1r (0x0000001e | PHY_REG_ACC_RAW)

#define BCM54282_TEST1r_SIZE 4

/*
 * This structure should be used to declare and program TEST1.
 *
 */
typedef union BCM54282_TEST1r_s {
	uint32_t v[1];
	uint32_t test1[1];
	uint32_t _test1;
} BCM54282_TEST1r_t;

#define BCM54282_TEST1r_CLR(r) (r).test1[0] = 0
#define BCM54282_TEST1r_SET(r,d) (r).test1[0] = d
#define BCM54282_TEST1r_GET(r) (r).test1[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_TEST1r_TEST1f_GET(r) (((r).test1[0]) & 0xffff)
#define BCM54282_TEST1r_TEST1f_SET(r,f) (r).test1[0]=(((r).test1[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access TEST1.
 *
 */
#define BCM54282_READ_TEST1r(_pc,_r) PHY_BUS_READ(_pc,BCM54282_TEST1r,_r._test1)
#define BCM54282_WRITE_TEST1r(_pc,_r) PHY_BUS_WRITE(_pc,BCM54282_TEST1r,_r._test1)

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define TEST1r BCM54282_TEST1r
#define TEST1r_SIZE BCM54282_TEST1r_SIZE
typedef BCM54282_TEST1r_t TEST1r_t;
#define TEST1r_CLR BCM54282_TEST1r_CLR
#define TEST1r_SET BCM54282_TEST1r_SET
#define TEST1r_GET BCM54282_TEST1r_GET
#define TEST1r_TEST1f_GET BCM54282_TEST1r_TEST1f_GET
#define TEST1r_TEST1f_SET BCM54282_TEST1r_TEST1f_SET
#define READ_TEST1r BCM54282_READ_TEST1r
#define WRITE_TEST1r BCM54282_WRITE_TEST1r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_TEST1r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  POWER_MII_CTRL
 * BLOCKS:   RDB
 * REGADDR:  0x002a
 * DESC:     POWER_MII_CTRL Register (RDB_Register, offset 0x02A)
 * SIZE:     32
 * FIELDS:
 *     SUPER_ISOLATE    Super Isolate enable.
 *
 ******************************************************************************/
//超级隔离寄存器
#define BCM54282_POWER_MII_CTRLr (0x0000002a | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_POWER_MII_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program POWER_MII_CTRL.
 *
 */
typedef union BCM54282_POWER_MII_CTRLr_s {
	uint32_t v[1];
	uint32_t power_mii_ctrl[1];
	uint32_t _power_mii_ctrl;
} BCM54282_POWER_MII_CTRLr_t;

#define BCM54282_POWER_MII_CTRLr_CLR(r) (r).power_mii_ctrl[0] = 0
#define BCM54282_POWER_MII_CTRLr_SET(r,d) (r).power_mii_ctrl[0] = d
#define BCM54282_POWER_MII_CTRLr_GET(r) (r).power_mii_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_POWER_MII_CTRLr_SUPER_ISOLATEf_GET(r) ((((r).power_mii_ctrl[0]) >> 5) & 0x1)
#define BCM54282_POWER_MII_CTRLr_SUPER_ISOLATEf_SET(r,f) (r).power_mii_ctrl[0]=(((r).power_mii_ctrl[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))

/*
 * These macros can be used to access POWER_MII_CTRL.
 *
 */
#define BCM54282_READ_POWER_MII_CTRLr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_POWER_MII_CTRLr,(_r._power_mii_ctrl))
#define BCM54282_WRITE_POWER_MII_CTRLr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_POWER_MII_CTRLr,(_r._power_mii_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define POWER_MII_CTRLr BCM54282_POWER_MII_CTRLr
#define POWER_MII_CTRLr_SIZE BCM54282_POWER_MII_CTRLr_SIZE
typedef BCM54282_POWER_MII_CTRLr_t POWER_MII_CTRLr_t;
#define POWER_MII_CTRLr_CLR BCM54282_POWER_MII_CTRLr_CLR
#define POWER_MII_CTRLr_SET BCM54282_POWER_MII_CTRLr_SET
#define POWER_MII_CTRLr_GET BCM54282_POWER_MII_CTRLr_GET
#define POWER_MII_CTRLr_SUPER_ISOLATEf_GET BCM54282_POWER_MII_CTRLr_SUPER_ISOLATEf_GET
#define POWER_MII_CTRLr_SUPER_ISOLATEf_SET BCM54282_POWER_MII_CTRLr_SUPER_ISOLATEf_SET
#define READ_POWER_MII_CTRLr BCM54282_READ_POWER_MII_CTRLr
#define WRITE_POWER_MII_CTRLr BCM54282_WRITE_POWER_MII_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_POWER_MII_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  COPPER_MISC_TEST
 * BLOCKS:   RDB
 * REGADDR:  0x002c
 * DESC:     COPPER_MISC_TEST Register (RDB_Register, offset 0x02C)
 * SIZE:     32
 * FIELDS:
 *     HALFOUT          Receive and transmit operate on the same pair.
 *     SWAP_RXMDIX      Receive and transmit operate on the same pair.
 *     BT_WAKEUP        Enable/Disable 10BASE-T Wakeup.
 *     RMT_LPBK_EN      Remote copper line-side loopback enable.
 *
 ******************************************************************************/
#define BCM54282_COPPER_MISC_TESTr (0x0000002c | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_COPPER_MISC_TESTr_SIZE 4

/*
 * This structure should be used to declare and program COPPER_MISC_TEST.
 *
 */
typedef union BCM54282_COPPER_MISC_TESTr_s {
	uint32_t v[1];
	uint32_t copper_misc_test[1];
	uint32_t _copper_misc_test;
} BCM54282_COPPER_MISC_TESTr_t;

#define BCM54282_COPPER_MISC_TESTr_CLR(r) (r).copper_misc_test[0] = 0
#define BCM54282_COPPER_MISC_TESTr_SET(r,d) (r).copper_misc_test[0] = d
#define BCM54282_COPPER_MISC_TESTr_GET(r) (r).copper_misc_test[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_COPPER_MISC_TESTr_RMT_LPBK_ENf_GET(r) ((((r).copper_misc_test[0]) >> 15) & 0x1)
#define BCM54282_COPPER_MISC_TESTr_RMT_LPBK_ENf_SET(r,f) (r).copper_misc_test[0]=(((r).copper_misc_test[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_COPPER_MISC_TESTr_BT_WAKEUPf_GET(r) ((((r).copper_misc_test[0]) >> 10) & 0x1)
#define BCM54282_COPPER_MISC_TESTr_BT_WAKEUPf_SET(r,f) (r).copper_misc_test[0]=(((r).copper_misc_test[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))
#define BCM54282_COPPER_MISC_TESTr_SWAP_RXMDIXf_GET(r) ((((r).copper_misc_test[0]) >> 4) & 0x1)
#define BCM54282_COPPER_MISC_TESTr_SWAP_RXMDIXf_SET(r,f) (r).copper_misc_test[0]=(((r).copper_misc_test[0] & ~((uint32_t)0x1 << 4)) | ((((uint32_t)f) & 0x1) << 4))
#define BCM54282_COPPER_MISC_TESTr_HALFOUTf_GET(r) ((((r).copper_misc_test[0]) >> 3) & 0x1)
#define BCM54282_COPPER_MISC_TESTr_HALFOUTf_SET(r,f) (r).copper_misc_test[0]=(((r).copper_misc_test[0] & ~((uint32_t)0x1 << 3)) | ((((uint32_t)f) & 0x1) << 3))

/*
 * These macros can be used to access COPPER_MISC_TEST.
 *
 */
#define BCM54282_READ_COPPER_MISC_TESTr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_COPPER_MISC_TESTr,(_r._copper_misc_test))
#define BCM54282_WRITE_COPPER_MISC_TESTr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_COPPER_MISC_TESTr,(_r._copper_misc_test))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define COPPER_MISC_TESTr BCM54282_COPPER_MISC_TESTr
#define COPPER_MISC_TESTr_SIZE BCM54282_COPPER_MISC_TESTr_SIZE
typedef BCM54282_COPPER_MISC_TESTr_t COPPER_MISC_TESTr_t;
#define COPPER_MISC_TESTr_CLR BCM54282_COPPER_MISC_TESTr_CLR
#define COPPER_MISC_TESTr_SET BCM54282_COPPER_MISC_TESTr_SET
#define COPPER_MISC_TESTr_GET BCM54282_COPPER_MISC_TESTr_GET
#define COPPER_MISC_TESTr_RMT_LPBK_ENf_GET BCM54282_COPPER_MISC_TESTr_RMT_LPBK_ENf_GET
#define COPPER_MISC_TESTr_RMT_LPBK_ENf_SET BCM54282_COPPER_MISC_TESTr_RMT_LPBK_ENf_SET
#define COPPER_MISC_TESTr_BT_WAKEUPf_GET BCM54282_COPPER_MISC_TESTr_BT_WAKEUPf_GET
#define COPPER_MISC_TESTr_BT_WAKEUPf_SET BCM54282_COPPER_MISC_TESTr_BT_WAKEUPf_SET
#define COPPER_MISC_TESTr_SWAP_RXMDIXf_GET BCM54282_COPPER_MISC_TESTr_SWAP_RXMDIXf_GET
#define COPPER_MISC_TESTr_SWAP_RXMDIXf_SET BCM54282_COPPER_MISC_TESTr_SWAP_RXMDIXf_SET
#define COPPER_MISC_TESTr_HALFOUTf_GET BCM54282_COPPER_MISC_TESTr_HALFOUTf_GET
#define COPPER_MISC_TESTr_HALFOUTf_SET BCM54282_COPPER_MISC_TESTr_HALFOUTf_SET
#define READ_COPPER_MISC_TESTr BCM54282_READ_COPPER_MISC_TESTr
#define WRITE_COPPER_MISC_TESTr BCM54282_WRITE_COPPER_MISC_TESTr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_COPPER_MISC_TESTr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  HALT_AGC_CTRL
 * BLOCKS:   RDB
 * REGADDR:  0x00d8
 * DESC:     HALT_AGC_CTRL Register (RDB_Register, offset 0x0D8)
 * SIZE:     32
 * FIELDS:
 *     HALT_AGC_CTRL    HALT_AGC_CTRL
 *
 ******************************************************************************/
#define BCM54282_HALT_AGC_CTRLr (0x000000d8 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_HALT_AGC_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program HALT_AGC_CTRL.
 *
 */
typedef union BCM54282_HALT_AGC_CTRLr_s {
	uint32_t v[1];
	uint32_t halt_agc_ctrl[1];
	uint32_t _halt_agc_ctrl;
} BCM54282_HALT_AGC_CTRLr_t;

#define BCM54282_HALT_AGC_CTRLr_CLR(r) (r).halt_agc_ctrl[0] = 0
#define BCM54282_HALT_AGC_CTRLr_SET(r,d) (r).halt_agc_ctrl[0] = d
#define BCM54282_HALT_AGC_CTRLr_GET(r) (r).halt_agc_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_HALT_AGC_CTRLr_HALT_AGC_CTRLf_GET(r) (((r).halt_agc_ctrl[0]) & 0xffff)
#define BCM54282_HALT_AGC_CTRLr_HALT_AGC_CTRLf_SET(r,f) (r).halt_agc_ctrl[0]=(((r).halt_agc_ctrl[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access HALT_AGC_CTRL.
 *
 */
#define BCM54282_READ_HALT_AGC_CTRLr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_HALT_AGC_CTRLr,(_r._halt_agc_ctrl))
#define BCM54282_WRITE_HALT_AGC_CTRLr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_HALT_AGC_CTRLr,(_r._halt_agc_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define HALT_AGC_CTRLr BCM54282_HALT_AGC_CTRLr
#define HALT_AGC_CTRLr_SIZE BCM54282_HALT_AGC_CTRLr_SIZE
typedef BCM54282_HALT_AGC_CTRLr_t HALT_AGC_CTRLr_t;
#define HALT_AGC_CTRLr_CLR BCM54282_HALT_AGC_CTRLr_CLR
#define HALT_AGC_CTRLr_SET BCM54282_HALT_AGC_CTRLr_SET
#define HALT_AGC_CTRLr_GET BCM54282_HALT_AGC_CTRLr_GET
#define HALT_AGC_CTRLr_HALT_AGC_CTRLf_GET BCM54282_HALT_AGC_CTRLr_HALT_AGC_CTRLf_GET
#define HALT_AGC_CTRLr_HALT_AGC_CTRLf_SET BCM54282_HALT_AGC_CTRLr_HALT_AGC_CTRLf_SET
#define READ_HALT_AGC_CTRLr BCM54282_READ_HALT_AGC_CTRLr
#define WRITE_HALT_AGC_CTRLr BCM54282_WRITE_HALT_AGC_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_HALT_AGC_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  TDR_OVRIDE_VAL
 * BLOCKS:   RDB
 * REGADDR:  0x00fb
 * DESC:     TDR_OVRIDE_VAL Register (RDB_Register, offset 0x0FB)
 * SIZE:     32
 * FIELDS:
 *     TDR_OVRIDE_VAL   TDR_OVRIDE_VAL
 *
 ******************************************************************************/
#define BCM54282_TDR_OVRIDE_VALr (0x000000fb | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_TDR_OVRIDE_VALr_SIZE 4

/*
 * This structure should be used to declare and program TDR_OVRIDE_VAL.
 *
 */
typedef union BCM54282_TDR_OVRIDE_VALr_s {
	uint32_t v[1];
	uint32_t tdr_ovride_val[1];
	uint32_t _tdr_ovride_val;
} BCM54282_TDR_OVRIDE_VALr_t;

#define BCM54282_TDR_OVRIDE_VALr_CLR(r) (r).tdr_ovride_val[0] = 0
#define BCM54282_TDR_OVRIDE_VALr_SET(r,d) (r).tdr_ovride_val[0] = d
#define BCM54282_TDR_OVRIDE_VALr_GET(r) (r).tdr_ovride_val[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_TDR_OVRIDE_VALr_TDR_OVRIDE_VALf_GET(r) (((r).tdr_ovride_val[0]) & 0xffff)
#define BCM54282_TDR_OVRIDE_VALr_TDR_OVRIDE_VALf_SET(r,f) (r).tdr_ovride_val[0]=(((r).tdr_ovride_val[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access TDR_OVRIDE_VAL.
 *
 */
#define BCM54282_READ_TDR_OVRIDE_VALr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_TDR_OVRIDE_VALr,(_r._tdr_ovride_val))
#define BCM54282_WRITE_TDR_OVRIDE_VALr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_TDR_OVRIDE_VALr,(_r._tdr_ovride_val))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define TDR_OVRIDE_VALr BCM54282_TDR_OVRIDE_VALr
#define TDR_OVRIDE_VALr_SIZE BCM54282_TDR_OVRIDE_VALr_SIZE
typedef BCM54282_TDR_OVRIDE_VALr_t TDR_OVRIDE_VALr_t;
#define TDR_OVRIDE_VALr_CLR BCM54282_TDR_OVRIDE_VALr_CLR
#define TDR_OVRIDE_VALr_SET BCM54282_TDR_OVRIDE_VALr_SET
#define TDR_OVRIDE_VALr_GET BCM54282_TDR_OVRIDE_VALr_GET
#define TDR_OVRIDE_VALr_TDR_OVRIDE_VALf_GET BCM54282_TDR_OVRIDE_VALr_TDR_OVRIDE_VALf_GET
#define TDR_OVRIDE_VALr_TDR_OVRIDE_VALf_SET BCM54282_TDR_OVRIDE_VALr_TDR_OVRIDE_VALf_SET
#define READ_TDR_OVRIDE_VALr BCM54282_READ_TDR_OVRIDE_VALr
#define WRITE_TDR_OVRIDE_VALr BCM54282_WRITE_TDR_OVRIDE_VALr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_TDR_OVRIDE_VALr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  ANLOG_PWR_CTRL_OVRIDE
 * BLOCKS:   RDB
 * REGADDR:  0x00ff
 * DESC:     ANLOG_PWR_CTRL_OVRIDE Register (RDB_Register, offset 0x0FF)
 * SIZE:     32
 * FIELDS:
 *     ANLOG_PWR_CTRL_OVRIDE ANLOG_PWR_CTRL_OVRIDE
 *
 ******************************************************************************/
#define BCM54282_ANLOG_PWR_CTRL_OVRIDEr (0x000000ff | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_ANLOG_PWR_CTRL_OVRIDEr_SIZE 4

/*
 * This structure should be used to declare and program ANLOG_PWR_CTRL_OVRIDE.
 *
 */
typedef union BCM54282_ANLOG_PWR_CTRL_OVRIDEr_s {
	uint32_t v[1];
	uint32_t anlog_pwr_ctrl_ovride[1];
	uint32_t _anlog_pwr_ctrl_ovride;
} BCM54282_ANLOG_PWR_CTRL_OVRIDEr_t;

#define BCM54282_ANLOG_PWR_CTRL_OVRIDEr_CLR(r) (r).anlog_pwr_ctrl_ovride[0] = 0
#define BCM54282_ANLOG_PWR_CTRL_OVRIDEr_SET(r,d) (r).anlog_pwr_ctrl_ovride[0] = d
#define BCM54282_ANLOG_PWR_CTRL_OVRIDEr_GET(r) (r).anlog_pwr_ctrl_ovride[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_ANLOG_PWR_CTRL_OVRIDEr_ANLOG_PWR_CTRL_OVRIDEf_GET(r) (((r).anlog_pwr_ctrl_ovride[0]) & 0xffff)
#define BCM54282_ANLOG_PWR_CTRL_OVRIDEr_ANLOG_PWR_CTRL_OVRIDEf_SET(r,f) (r).anlog_pwr_ctrl_ovride[0]=(((r).anlog_pwr_ctrl_ovride[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access ANLOG_PWR_CTRL_OVRIDE.
 *
 */
#define BCM54282_READ_ANLOG_PWR_CTRL_OVRIDEr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_ANLOG_PWR_CTRL_OVRIDEr,(_r._anlog_pwr_ctrl_ovride))
#define BCM54282_WRITE_ANLOG_PWR_CTRL_OVRIDEr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_ANLOG_PWR_CTRL_OVRIDEr,(_r._anlog_pwr_ctrl_ovride))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define ANLOG_PWR_CTRL_OVRIDEr BCM54282_ANLOG_PWR_CTRL_OVRIDEr
#define ANLOG_PWR_CTRL_OVRIDEr_SIZE BCM54282_ANLOG_PWR_CTRL_OVRIDEr_SIZE
typedef BCM54282_ANLOG_PWR_CTRL_OVRIDEr_t ANLOG_PWR_CTRL_OVRIDEr_t;
#define ANLOG_PWR_CTRL_OVRIDEr_CLR BCM54282_ANLOG_PWR_CTRL_OVRIDEr_CLR
#define ANLOG_PWR_CTRL_OVRIDEr_SET BCM54282_ANLOG_PWR_CTRL_OVRIDEr_SET
#define ANLOG_PWR_CTRL_OVRIDEr_GET BCM54282_ANLOG_PWR_CTRL_OVRIDEr_GET
#define ANLOG_PWR_CTRL_OVRIDEr_ANLOG_PWR_CTRL_OVRIDEf_GET BCM54282_ANLOG_PWR_CTRL_OVRIDEr_ANLOG_PWR_CTRL_OVRIDEf_GET
#define ANLOG_PWR_CTRL_OVRIDEr_ANLOG_PWR_CTRL_OVRIDEf_SET BCM54282_ANLOG_PWR_CTRL_OVRIDEr_ANLOG_PWR_CTRL_OVRIDEf_SET
#define READ_ANLOG_PWR_CTRL_OVRIDEr BCM54282_READ_ANLOG_PWR_CTRL_OVRIDEr
#define WRITE_ANLOG_PWR_CTRL_OVRIDEr BCM54282_WRITE_ANLOG_PWR_CTRL_OVRIDEr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_ANLOG_PWR_CTRL_OVRIDEr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  DSP_TAP10
 * BLOCKS:   RDB
 * REGADDR:  0x0125
 * DESC:     DSP_TAP10 Register (RDB_Register, offset 0x125)
 * SIZE:     32
 * FIELDS:
 *     DSP_TAP10        DSP_TAP10
 *
 ******************************************************************************/
#define BCM54282_DSP_TAP10r (0x00000125 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_DSP_TAP10r_SIZE 4

/*
 * This structure should be used to declare and program DSP_TAP10.
 *
 */
typedef union BCM54282_DSP_TAP10r_s {
	uint32_t v[1];
	uint32_t dsp_tap10[1];
	uint32_t _dsp_tap10;
} BCM54282_DSP_TAP10r_t;

#define BCM54282_DSP_TAP10r_CLR(r) (r).dsp_tap10[0] = 0
#define BCM54282_DSP_TAP10r_SET(r,d) (r).dsp_tap10[0] = d
#define BCM54282_DSP_TAP10r_GET(r) (r).dsp_tap10[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_DSP_TAP10r_DSP_TAP10f_GET(r) (((r).dsp_tap10[0]) & 0xffff)
#define BCM54282_DSP_TAP10r_DSP_TAP10f_SET(r,f) (r).dsp_tap10[0]=(((r).dsp_tap10[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access DSP_TAP10.
 *
 */
#define BCM54282_READ_DSP_TAP10r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_DSP_TAP10r,(_r._dsp_tap10))
#define BCM54282_WRITE_DSP_TAP10r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_DSP_TAP10r,(_r._dsp_tap10))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define DSP_TAP10r BCM54282_DSP_TAP10r
#define DSP_TAP10r_SIZE BCM54282_DSP_TAP10r_SIZE
typedef BCM54282_DSP_TAP10r_t DSP_TAP10r_t;
#define DSP_TAP10r_CLR BCM54282_DSP_TAP10r_CLR
#define DSP_TAP10r_SET BCM54282_DSP_TAP10r_SET
#define DSP_TAP10r_GET BCM54282_DSP_TAP10r_GET
#define DSP_TAP10r_DSP_TAP10f_GET BCM54282_DSP_TAP10r_DSP_TAP10f_GET
#define DSP_TAP10r_DSP_TAP10f_SET BCM54282_DSP_TAP10r_DSP_TAP10f_SET
#define READ_DSP_TAP10r BCM54282_READ_DSP_TAP10r
#define WRITE_DSP_TAP10r BCM54282_WRITE_DSP_TAP10r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_DSP_TAP10r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EEE_LPI_TIMERS
 * BLOCKS:   RDB
 * REGADDR:  0x0152
 * DESC:     EEE_LPI_TIMERS Register (RDB_Register, offset 0x152)
 * SIZE:     32
 * FIELDS:
 *     EEE_LPI_TIMERS   EEE_LPI_TIMERS
 *
 ******************************************************************************/
#define BCM54282_EEE_LPI_TIMERSr (0x00000152 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_EEE_LPI_TIMERSr_SIZE 4

/*
 * This structure should be used to declare and program EEE_LPI_TIMERS.
 *
 */
typedef union BCM54282_EEE_LPI_TIMERSr_s {
	uint32_t v[1];
	uint32_t eee_lpi_timers[1];
	uint32_t _eee_lpi_timers;
} BCM54282_EEE_LPI_TIMERSr_t;

#define BCM54282_EEE_LPI_TIMERSr_CLR(r) (r).eee_lpi_timers[0] = 0
#define BCM54282_EEE_LPI_TIMERSr_SET(r,d) (r).eee_lpi_timers[0] = d
#define BCM54282_EEE_LPI_TIMERSr_GET(r) (r).eee_lpi_timers[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EEE_LPI_TIMERSr_EEE_LPI_TIMERSf_GET(r) (((r).eee_lpi_timers[0]) & 0xffff)
#define BCM54282_EEE_LPI_TIMERSr_EEE_LPI_TIMERSf_SET(r,f) (r).eee_lpi_timers[0]=(((r).eee_lpi_timers[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access EEE_LPI_TIMERS.
 *
 */
#define BCM54282_READ_EEE_LPI_TIMERSr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_EEE_LPI_TIMERSr,(_r._eee_lpi_timers))
#define BCM54282_WRITE_EEE_LPI_TIMERSr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_EEE_LPI_TIMERSr,(_r._eee_lpi_timers))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EEE_LPI_TIMERSr BCM54282_EEE_LPI_TIMERSr
#define EEE_LPI_TIMERSr_SIZE BCM54282_EEE_LPI_TIMERSr_SIZE
typedef BCM54282_EEE_LPI_TIMERSr_t EEE_LPI_TIMERSr_t;
#define EEE_LPI_TIMERSr_CLR BCM54282_EEE_LPI_TIMERSr_CLR
#define EEE_LPI_TIMERSr_SET BCM54282_EEE_LPI_TIMERSr_SET
#define EEE_LPI_TIMERSr_GET BCM54282_EEE_LPI_TIMERSr_GET
#define EEE_LPI_TIMERSr_EEE_LPI_TIMERSf_GET BCM54282_EEE_LPI_TIMERSr_EEE_LPI_TIMERSf_GET
#define EEE_LPI_TIMERSr_EEE_LPI_TIMERSf_SET BCM54282_EEE_LPI_TIMERSr_EEE_LPI_TIMERSf_SET
#define READ_EEE_LPI_TIMERSr BCM54282_READ_EEE_LPI_TIMERSr
#define WRITE_EEE_LPI_TIMERSr BCM54282_WRITE_EEE_LPI_TIMERSr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EEE_LPI_TIMERSr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EEE_100TX_MODE_BW_CONTROL
 * BLOCKS:   RDB
 * REGADDR:  0x0156
 * DESC:     EEE_100TX_MODE_BW_CONTROL Register (RDB_Register, offset 0x156)
 * SIZE:     32
 * FIELDS:
 *     EEE_100TX_MODE_BW_CONTROL EEE_100TX_MODE_BW_CONTROL
 *
 ******************************************************************************/
#define BCM54282_EEE_100TX_MODE_BW_CONTROLr (0x00000156 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_EEE_100TX_MODE_BW_CONTROLr_SIZE 4

/*
 * This structure should be used to declare and program EEE_100TX_MODE_BW_CONTROL.
 *
 */
typedef union BCM54282_EEE_100TX_MODE_BW_CONTROLr_s {
	uint32_t v[1];
	uint32_t eee_100tx_mode_bw_control[1];
	uint32_t _eee_100tx_mode_bw_control;
} BCM54282_EEE_100TX_MODE_BW_CONTROLr_t;

#define BCM54282_EEE_100TX_MODE_BW_CONTROLr_CLR(r) (r).eee_100tx_mode_bw_control[0] = 0
#define BCM54282_EEE_100TX_MODE_BW_CONTROLr_SET(r,d) (r).eee_100tx_mode_bw_control[0] = d
#define BCM54282_EEE_100TX_MODE_BW_CONTROLr_GET(r) (r).eee_100tx_mode_bw_control[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EEE_100TX_MODE_BW_CONTROLr_EEE_100TX_MODE_BW_CONTROLf_GET(r) (((r).eee_100tx_mode_bw_control[0]) & 0xffff)
#define BCM54282_EEE_100TX_MODE_BW_CONTROLr_EEE_100TX_MODE_BW_CONTROLf_SET(r,f) (r).eee_100tx_mode_bw_control[0]=(((r).eee_100tx_mode_bw_control[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access EEE_100TX_MODE_BW_CONTROL.
 *
 */
#define BCM54282_READ_EEE_100TX_MODE_BW_CONTROLr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_EEE_100TX_MODE_BW_CONTROLr,(_r._eee_100tx_mode_bw_control))
#define BCM54282_WRITE_EEE_100TX_MODE_BW_CONTROLr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_EEE_100TX_MODE_BW_CONTROLr,(_r._eee_100tx_mode_bw_control))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EEE_100TX_MODE_BW_CONTROLr BCM54282_EEE_100TX_MODE_BW_CONTROLr
#define EEE_100TX_MODE_BW_CONTROLr_SIZE BCM54282_EEE_100TX_MODE_BW_CONTROLr_SIZE
typedef BCM54282_EEE_100TX_MODE_BW_CONTROLr_t EEE_100TX_MODE_BW_CONTROLr_t;
#define EEE_100TX_MODE_BW_CONTROLr_CLR BCM54282_EEE_100TX_MODE_BW_CONTROLr_CLR
#define EEE_100TX_MODE_BW_CONTROLr_SET BCM54282_EEE_100TX_MODE_BW_CONTROLr_SET
#define EEE_100TX_MODE_BW_CONTROLr_GET BCM54282_EEE_100TX_MODE_BW_CONTROLr_GET
#define EEE_100TX_MODE_BW_CONTROLr_EEE_100TX_MODE_BW_CONTROLf_GET BCM54282_EEE_100TX_MODE_BW_CONTROLr_EEE_100TX_MODE_BW_CONTROLf_GET
#define EEE_100TX_MODE_BW_CONTROLr_EEE_100TX_MODE_BW_CONTROLf_SET BCM54282_EEE_100TX_MODE_BW_CONTROLr_EEE_100TX_MODE_BW_CONTROLf_SET
#define READ_EEE_100TX_MODE_BW_CONTROLr BCM54282_READ_EEE_100TX_MODE_BW_CONTROLr
#define WRITE_EEE_100TX_MODE_BW_CONTROLr BCM54282_WRITE_EEE_100TX_MODE_BW_CONTROLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EEE_100TX_MODE_BW_CONTROLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  AFE_RXCONFIG_0
 * BLOCKS:   RDB
 * REGADDR:  0x01c0
 * DESC:     AFE_RXCONFIG_0 Register (RDB_Register, offset 0x1C0)
 * SIZE:     32
 * FIELDS:
 *     AFE_RXCONFIG_0   AFE_RXCONFIG_0
 *
 ******************************************************************************/
#define BCM54282_AFE_RXCONFIG_0r (0x000001c0 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_AFE_RXCONFIG_0r_SIZE 4

/*
 * This structure should be used to declare and program AFE_RXCONFIG_0.
 *
 */
typedef union BCM54282_AFE_RXCONFIG_0r_s {
	uint32_t v[1];
	uint32_t afe_rxconfig_0[1];
	uint32_t _afe_rxconfig_0;
} BCM54282_AFE_RXCONFIG_0r_t;

#define BCM54282_AFE_RXCONFIG_0r_CLR(r) (r).afe_rxconfig_0[0] = 0
#define BCM54282_AFE_RXCONFIG_0r_SET(r,d) (r).afe_rxconfig_0[0] = d
#define BCM54282_AFE_RXCONFIG_0r_GET(r) (r).afe_rxconfig_0[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_AFE_RXCONFIG_0r_AFE_RXCONFIG_0f_GET(r) (((r).afe_rxconfig_0[0]) & 0xffff)
#define BCM54282_AFE_RXCONFIG_0r_AFE_RXCONFIG_0f_SET(r,f) (r).afe_rxconfig_0[0]=(((r).afe_rxconfig_0[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access AFE_RXCONFIG_0.
 *
 */
#define BCM54282_READ_AFE_RXCONFIG_0r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_AFE_RXCONFIG_0r,(_r._afe_rxconfig_0))
#define BCM54282_WRITE_AFE_RXCONFIG_0r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_AFE_RXCONFIG_0r,(_r._afe_rxconfig_0))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define AFE_RXCONFIG_0r BCM54282_AFE_RXCONFIG_0r
#define AFE_RXCONFIG_0r_SIZE BCM54282_AFE_RXCONFIG_0r_SIZE
typedef BCM54282_AFE_RXCONFIG_0r_t AFE_RXCONFIG_0r_t;
#define AFE_RXCONFIG_0r_CLR BCM54282_AFE_RXCONFIG_0r_CLR
#define AFE_RXCONFIG_0r_SET BCM54282_AFE_RXCONFIG_0r_SET
#define AFE_RXCONFIG_0r_GET BCM54282_AFE_RXCONFIG_0r_GET
#define AFE_RXCONFIG_0r_AFE_RXCONFIG_0f_GET BCM54282_AFE_RXCONFIG_0r_AFE_RXCONFIG_0f_GET
#define AFE_RXCONFIG_0r_AFE_RXCONFIG_0f_SET BCM54282_AFE_RXCONFIG_0r_AFE_RXCONFIG_0f_SET
#define READ_AFE_RXCONFIG_0r BCM54282_READ_AFE_RXCONFIG_0r
#define WRITE_AFE_RXCONFIG_0r BCM54282_WRITE_AFE_RXCONFIG_0r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_AFE_RXCONFIG_0r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  AFE_RXCONFIG_2
 * BLOCKS:   RDB
 * REGADDR:  0x01c2
 * DESC:     AFE_RXCONFIG_2 Register (RDB_Register, offset 0x1C2)
 * SIZE:     32
 * FIELDS:
 *     AFE_RXCONFIG_2   AFE_RXCONFIG_2
 *
 ******************************************************************************/
#define BCM54282_AFE_RXCONFIG_2r (0x000001c2 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_AFE_RXCONFIG_2r_SIZE 4

/*
 * This structure should be used to declare and program AFE_RXCONFIG_2.
 *
 */
typedef union BCM54282_AFE_RXCONFIG_2r_s {
	uint32_t v[1];
	uint32_t afe_rxconfig_2[1];
	uint32_t _afe_rxconfig_2;
} BCM54282_AFE_RXCONFIG_2r_t;

#define BCM54282_AFE_RXCONFIG_2r_CLR(r) (r).afe_rxconfig_2[0] = 0
#define BCM54282_AFE_RXCONFIG_2r_SET(r,d) (r).afe_rxconfig_2[0] = d
#define BCM54282_AFE_RXCONFIG_2r_GET(r) (r).afe_rxconfig_2[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_AFE_RXCONFIG_2r_AFE_RXCONFIG_2f_GET(r) (((r).afe_rxconfig_2[0]) & 0xffff)
#define BCM54282_AFE_RXCONFIG_2r_AFE_RXCONFIG_2f_SET(r,f) (r).afe_rxconfig_2[0]=(((r).afe_rxconfig_2[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access AFE_RXCONFIG_2.
 *
 */
#define BCM54282_READ_AFE_RXCONFIG_2r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_AFE_RXCONFIG_2r,(_r._afe_rxconfig_2))
#define BCM54282_WRITE_AFE_RXCONFIG_2r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_AFE_RXCONFIG_2r,(_r._afe_rxconfig_2))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define AFE_RXCONFIG_2r BCM54282_AFE_RXCONFIG_2r
#define AFE_RXCONFIG_2r_SIZE BCM54282_AFE_RXCONFIG_2r_SIZE
typedef BCM54282_AFE_RXCONFIG_2r_t AFE_RXCONFIG_2r_t;
#define AFE_RXCONFIG_2r_CLR BCM54282_AFE_RXCONFIG_2r_CLR
#define AFE_RXCONFIG_2r_SET BCM54282_AFE_RXCONFIG_2r_SET
#define AFE_RXCONFIG_2r_GET BCM54282_AFE_RXCONFIG_2r_GET
#define AFE_RXCONFIG_2r_AFE_RXCONFIG_2f_GET BCM54282_AFE_RXCONFIG_2r_AFE_RXCONFIG_2f_GET
#define AFE_RXCONFIG_2r_AFE_RXCONFIG_2f_SET BCM54282_AFE_RXCONFIG_2r_AFE_RXCONFIG_2f_SET
#define READ_AFE_RXCONFIG_2r BCM54282_READ_AFE_RXCONFIG_2r
#define WRITE_AFE_RXCONFIG_2r BCM54282_WRITE_AFE_RXCONFIG_2r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_AFE_RXCONFIG_2r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  AFE_VDACCTRL_1
 * BLOCKS:   RDB
 * REGADDR:  0x01c5
 * DESC:     AFE_VDACCTRL_1 Register (RDB_Register, offset 0x1C5)
 * SIZE:     32
 * FIELDS:
 *     AFE_VDACCTRL_1   AFE_VDACCTRL_1
 *
 ******************************************************************************/
#define BCM54282_AFE_VDACCTRL_1r (0x000001c5 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_AFE_VDACCTRL_1r_SIZE 4

/*
 * This structure should be used to declare and program AFE_VDACCTRL_1.
 *
 */
typedef union BCM54282_AFE_VDACCTRL_1r_s {
	uint32_t v[1];
	uint32_t afe_vdacctrl_1[1];
	uint32_t _afe_vdacctrl_1;
} BCM54282_AFE_VDACCTRL_1r_t;

#define BCM54282_AFE_VDACCTRL_1r_CLR(r) (r).afe_vdacctrl_1[0] = 0
#define BCM54282_AFE_VDACCTRL_1r_SET(r,d) (r).afe_vdacctrl_1[0] = d
#define BCM54282_AFE_VDACCTRL_1r_GET(r) (r).afe_vdacctrl_1[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_AFE_VDACCTRL_1r_AFE_VDACCTRL_1f_GET(r) (((r).afe_vdacctrl_1[0]) & 0xffff)
#define BCM54282_AFE_VDACCTRL_1r_AFE_VDACCTRL_1f_SET(r,f) (r).afe_vdacctrl_1[0]=(((r).afe_vdacctrl_1[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access AFE_VDACCTRL_1.
 *
 */
#define BCM54282_READ_AFE_VDACCTRL_1r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_AFE_VDACCTRL_1r,(_r._afe_vdacctrl_1))
#define BCM54282_WRITE_AFE_VDACCTRL_1r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_AFE_VDACCTRL_1r,(_r._afe_vdacctrl_1))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define AFE_VDACCTRL_1r BCM54282_AFE_VDACCTRL_1r
#define AFE_VDACCTRL_1r_SIZE BCM54282_AFE_VDACCTRL_1r_SIZE
typedef BCM54282_AFE_VDACCTRL_1r_t AFE_VDACCTRL_1r_t;
#define AFE_VDACCTRL_1r_CLR BCM54282_AFE_VDACCTRL_1r_CLR
#define AFE_VDACCTRL_1r_SET BCM54282_AFE_VDACCTRL_1r_SET
#define AFE_VDACCTRL_1r_GET BCM54282_AFE_VDACCTRL_1r_GET
#define AFE_VDACCTRL_1r_AFE_VDACCTRL_1f_GET BCM54282_AFE_VDACCTRL_1r_AFE_VDACCTRL_1f_GET
#define AFE_VDACCTRL_1r_AFE_VDACCTRL_1f_SET BCM54282_AFE_VDACCTRL_1r_AFE_VDACCTRL_1f_SET
#define READ_AFE_VDACCTRL_1r BCM54282_READ_AFE_VDACCTRL_1r
#define WRITE_AFE_VDACCTRL_1r BCM54282_WRITE_AFE_VDACCTRL_1r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_AFE_VDACCTRL_1r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  AFE_VDACCTRL_2
 * BLOCKS:   RDB
 * REGADDR:  0x01c6
 * DESC:     AFE_VDACCTRL_2 Register (RDB_Register, offset 0x1C6)
 * SIZE:     32
 * FIELDS:
 *     AFE_VDACCTRL_2   AFE_VDACCTRL_2
 *
 ******************************************************************************/
#define BCM54282_AFE_VDACCTRL_2r (0x000001c6 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_AFE_VDACCTRL_2r_SIZE 4

/*
 * This structure should be used to declare and program AFE_VDACCTRL_2.
 *
 */
typedef union BCM54282_AFE_VDACCTRL_2r_s {
	uint32_t v[1];
	uint32_t afe_vdacctrl_2[1];
	uint32_t _afe_vdacctrl_2;
} BCM54282_AFE_VDACCTRL_2r_t;

#define BCM54282_AFE_VDACCTRL_2r_CLR(r) (r).afe_vdacctrl_2[0] = 0
#define BCM54282_AFE_VDACCTRL_2r_SET(r,d) (r).afe_vdacctrl_2[0] = d
#define BCM54282_AFE_VDACCTRL_2r_GET(r) (r).afe_vdacctrl_2[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_AFE_VDACCTRL_2r_AFE_VDACCTRL_2f_GET(r) (((r).afe_vdacctrl_2[0]) & 0xffff)
#define BCM54282_AFE_VDACCTRL_2r_AFE_VDACCTRL_2f_SET(r,f) (r).afe_vdacctrl_2[0]=(((r).afe_vdacctrl_2[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access AFE_VDACCTRL_2.
 *
 */
#define BCM54282_READ_AFE_VDACCTRL_2r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_AFE_VDACCTRL_2r,(_r._afe_vdacctrl_2))
#define BCM54282_WRITE_AFE_VDACCTRL_2r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_AFE_VDACCTRL_2r,(_r._afe_vdacctrl_2))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define AFE_VDACCTRL_2r BCM54282_AFE_VDACCTRL_2r
#define AFE_VDACCTRL_2r_SIZE BCM54282_AFE_VDACCTRL_2r_SIZE
typedef BCM54282_AFE_VDACCTRL_2r_t AFE_VDACCTRL_2r_t;
#define AFE_VDACCTRL_2r_CLR BCM54282_AFE_VDACCTRL_2r_CLR
#define AFE_VDACCTRL_2r_SET BCM54282_AFE_VDACCTRL_2r_SET
#define AFE_VDACCTRL_2r_GET BCM54282_AFE_VDACCTRL_2r_GET
#define AFE_VDACCTRL_2r_AFE_VDACCTRL_2f_GET BCM54282_AFE_VDACCTRL_2r_AFE_VDACCTRL_2f_GET
#define AFE_VDACCTRL_2r_AFE_VDACCTRL_2f_SET BCM54282_AFE_VDACCTRL_2r_AFE_VDACCTRL_2f_SET
#define READ_AFE_VDACCTRL_2r BCM54282_READ_AFE_VDACCTRL_2r
#define WRITE_AFE_VDACCTRL_2r BCM54282_WRITE_AFE_VDACCTRL_2r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_AFE_VDACCTRL_2r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  AFE_AFE_PLLCTRL_4
 * BLOCKS:   RDB
 * REGADDR:  0x01cc
 * DESC:     AFE_AFE_PLLCTRL_4 Register (RDB_Register, offset 0x1CC)
 * SIZE:     32
 * FIELDS:
 *     AFE_AFE_PLLCTRL_4 AFE_AFE_PLLCTRL_4
 *
 ******************************************************************************/
#define BCM54282_AFE_AFE_PLLCTRL_4r (0x000001cc | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_AFE_AFE_PLLCTRL_4r_SIZE 4

/*
 * This structure should be used to declare and program AFE_AFE_PLLCTRL_4.
 *
 */
typedef union BCM54282_AFE_AFE_PLLCTRL_4r_s {
	uint32_t v[1];
	uint32_t afe_afe_pllctrl_4[1];
	uint32_t _afe_afe_pllctrl_4;
} BCM54282_AFE_AFE_PLLCTRL_4r_t;

#define BCM54282_AFE_AFE_PLLCTRL_4r_CLR(r) (r).afe_afe_pllctrl_4[0] = 0
#define BCM54282_AFE_AFE_PLLCTRL_4r_SET(r,d) (r).afe_afe_pllctrl_4[0] = d
#define BCM54282_AFE_AFE_PLLCTRL_4r_GET(r) (r).afe_afe_pllctrl_4[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_AFE_AFE_PLLCTRL_4r_AFE_AFE_PLLCTRL_4f_GET(r) (((r).afe_afe_pllctrl_4[0]) & 0xffff)
#define BCM54282_AFE_AFE_PLLCTRL_4r_AFE_AFE_PLLCTRL_4f_SET(r,f) (r).afe_afe_pllctrl_4[0]=(((r).afe_afe_pllctrl_4[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access AFE_AFE_PLLCTRL_4.
 *
 */
#define BCM54282_READ_AFE_AFE_PLLCTRL_4r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_AFE_AFE_PLLCTRL_4r,(_r._afe_afe_pllctrl_4))
#define BCM54282_WRITE_AFE_AFE_PLLCTRL_4r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_AFE_AFE_PLLCTRL_4r,(_r._afe_afe_pllctrl_4))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define AFE_AFE_PLLCTRL_4r BCM54282_AFE_AFE_PLLCTRL_4r
#define AFE_AFE_PLLCTRL_4r_SIZE BCM54282_AFE_AFE_PLLCTRL_4r_SIZE
typedef BCM54282_AFE_AFE_PLLCTRL_4r_t AFE_AFE_PLLCTRL_4r_t;
#define AFE_AFE_PLLCTRL_4r_CLR BCM54282_AFE_AFE_PLLCTRL_4r_CLR
#define AFE_AFE_PLLCTRL_4r_SET BCM54282_AFE_AFE_PLLCTRL_4r_SET
#define AFE_AFE_PLLCTRL_4r_GET BCM54282_AFE_AFE_PLLCTRL_4r_GET
#define AFE_AFE_PLLCTRL_4r_AFE_AFE_PLLCTRL_4f_GET BCM54282_AFE_AFE_PLLCTRL_4r_AFE_AFE_PLLCTRL_4f_GET
#define AFE_AFE_PLLCTRL_4r_AFE_AFE_PLLCTRL_4f_SET BCM54282_AFE_AFE_PLLCTRL_4r_AFE_AFE_PLLCTRL_4f_SET
#define READ_AFE_AFE_PLLCTRL_4r BCM54282_READ_AFE_AFE_PLLCTRL_4r
#define WRITE_AFE_AFE_PLLCTRL_4r BCM54282_WRITE_AFE_AFE_PLLCTRL_4r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_AFE_AFE_PLLCTRL_4r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  AFE_HPF_TRIM
 * BLOCKS:   RDB
 * REGADDR:  0x01cf
 * DESC:     AFE_HPF_TRIM Register (RDB_Register, offset 0x1CF)
 * SIZE:     32
 * FIELDS:
 *     AFE_HPF_TRIM     AFE_HPF_TRIM
 *
 ******************************************************************************/
#define BCM54282_AFE_HPF_TRIMr (0x000001cf | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_AFE_HPF_TRIMr_SIZE 4

/*
 * This structure should be used to declare and program AFE_HPF_TRIM.
 *
 */
typedef union BCM54282_AFE_HPF_TRIMr_s {
	uint32_t v[1];
	uint32_t afe_hpf_trim[1];
	uint32_t _afe_hpf_trim;
} BCM54282_AFE_HPF_TRIMr_t;

#define BCM54282_AFE_HPF_TRIMr_CLR(r) (r).afe_hpf_trim[0] = 0
#define BCM54282_AFE_HPF_TRIMr_SET(r,d) (r).afe_hpf_trim[0] = d
#define BCM54282_AFE_HPF_TRIMr_GET(r) (r).afe_hpf_trim[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_AFE_HPF_TRIMr_AFE_HPF_TRIMf_GET(r) (((r).afe_hpf_trim[0]) & 0xffff)
#define BCM54282_AFE_HPF_TRIMr_AFE_HPF_TRIMf_SET(r,f) (r).afe_hpf_trim[0]=(((r).afe_hpf_trim[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access AFE_HPF_TRIM.
 *
 */
#define BCM54282_READ_AFE_HPF_TRIMr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_AFE_HPF_TRIMr,(_r._afe_hpf_trim))
#define BCM54282_WRITE_AFE_HPF_TRIMr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_AFE_HPF_TRIMr,(_r._afe_hpf_trim))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define AFE_HPF_TRIMr BCM54282_AFE_HPF_TRIMr
#define AFE_HPF_TRIMr_SIZE BCM54282_AFE_HPF_TRIMr_SIZE
typedef BCM54282_AFE_HPF_TRIMr_t AFE_HPF_TRIMr_t;
#define AFE_HPF_TRIMr_CLR BCM54282_AFE_HPF_TRIMr_CLR
#define AFE_HPF_TRIMr_SET BCM54282_AFE_HPF_TRIMr_SET
#define AFE_HPF_TRIMr_GET BCM54282_AFE_HPF_TRIMr_GET
#define AFE_HPF_TRIMr_AFE_HPF_TRIMf_GET BCM54282_AFE_HPF_TRIMr_AFE_HPF_TRIMf_GET
#define AFE_HPF_TRIMr_AFE_HPF_TRIMf_SET BCM54282_AFE_HPF_TRIMr_AFE_HPF_TRIMf_SET
#define READ_AFE_HPF_TRIMr BCM54282_READ_AFE_HPF_TRIMr
#define WRITE_AFE_HPF_TRIMr BCM54282_WRITE_AFE_HPF_TRIMr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_AFE_HPF_TRIMr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  OPER_MODE_STATUS
 * BLOCKS:   RDB
 * REGADDR:  0x0202
 * DESC:     OPER_MODE_STATUS Register (RDB_Register, offset 0x202)
 * SIZE:     32
 * FIELDS:
 *     OPERATING_MODE_STATUS Mode.
 *     SYNC_STATUS      Sync status.
 *     SERDES_DUPLEX    serdes duplex.
 *     SERDES_SPEED     serdes speed.
 *
 ******************************************************************************/
#define BCM54282_OPER_MODE_STATUSr (0x00000202 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_OPER_MODE_STATUSr_SIZE 4

/*
 * This structure should be used to declare and program OPER_MODE_STATUS.
 *
 */
typedef union BCM54282_OPER_MODE_STATUSr_s {
	uint32_t v[1];
	uint32_t oper_mode_status[1];
	uint32_t _oper_mode_status;
} BCM54282_OPER_MODE_STATUSr_t;

#define BCM54282_OPER_MODE_STATUSr_CLR(r) (r).oper_mode_status[0] = 0
#define BCM54282_OPER_MODE_STATUSr_SET(r,d) (r).oper_mode_status[0] = d
#define BCM54282_OPER_MODE_STATUSr_GET(r) (r).oper_mode_status[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_OPER_MODE_STATUSr_SERDES_SPEEDf_GET(r) ((((r).oper_mode_status[0]) >> 13) & 0x3)
#define BCM54282_OPER_MODE_STATUSr_SERDES_SPEEDf_SET(r,f) (r).oper_mode_status[0]=(((r).oper_mode_status[0] & ~((uint32_t)0x3 << 13)) | ((((uint32_t)f) & 0x3) << 13))
#define BCM54282_OPER_MODE_STATUSr_SERDES_DUPLEXf_GET(r) ((((r).oper_mode_status[0]) >> 12) & 0x1)
#define BCM54282_OPER_MODE_STATUSr_SERDES_DUPLEXf_SET(r,f) (r).oper_mode_status[0]=(((r).oper_mode_status[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_OPER_MODE_STATUSr_SYNC_STATUSf_GET(r) ((((r).oper_mode_status[0]) >> 5) & 0x1)
#define BCM54282_OPER_MODE_STATUSr_SYNC_STATUSf_SET(r,f) (r).oper_mode_status[0]=(((r).oper_mode_status[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))
#define BCM54282_OPER_MODE_STATUSr_OPERATING_MODE_STATUSf_GET(r) (((r).oper_mode_status[0]) & 0x1f)
#define BCM54282_OPER_MODE_STATUSr_OPERATING_MODE_STATUSf_SET(r,f) (r).oper_mode_status[0]=(((r).oper_mode_status[0] & ~((uint32_t)0x1f)) | (((uint32_t)f) & 0x1f))

/*
 * These macros can be used to access OPER_MODE_STATUS.
 *
 */
#define BCM54282_READ_OPER_MODE_STATUSr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_OPER_MODE_STATUSr,(_r._oper_mode_status))
#define BCM54282_WRITE_OPER_MODE_STATUSr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_OPER_MODE_STATUSr,(_r._oper_mode_status))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define OPER_MODE_STATUSr BCM54282_OPER_MODE_STATUSr
#define OPER_MODE_STATUSr_SIZE BCM54282_OPER_MODE_STATUSr_SIZE
typedef BCM54282_OPER_MODE_STATUSr_t OPER_MODE_STATUSr_t;
#define OPER_MODE_STATUSr_CLR BCM54282_OPER_MODE_STATUSr_CLR
#define OPER_MODE_STATUSr_SET BCM54282_OPER_MODE_STATUSr_SET
#define OPER_MODE_STATUSr_GET BCM54282_OPER_MODE_STATUSr_GET
#define OPER_MODE_STATUSr_SERDES_SPEEDf_GET BCM54282_OPER_MODE_STATUSr_SERDES_SPEEDf_GET
#define OPER_MODE_STATUSr_SERDES_SPEEDf_SET BCM54282_OPER_MODE_STATUSr_SERDES_SPEEDf_SET
#define OPER_MODE_STATUSr_SERDES_DUPLEXf_GET BCM54282_OPER_MODE_STATUSr_SERDES_DUPLEXf_GET
#define OPER_MODE_STATUSr_SERDES_DUPLEXf_SET BCM54282_OPER_MODE_STATUSr_SERDES_DUPLEXf_SET
#define OPER_MODE_STATUSr_SYNC_STATUSf_GET BCM54282_OPER_MODE_STATUSr_SYNC_STATUSf_GET
#define OPER_MODE_STATUSr_SYNC_STATUSf_SET BCM54282_OPER_MODE_STATUSr_SYNC_STATUSf_SET
#define OPER_MODE_STATUSr_OPERATING_MODE_STATUSf_GET BCM54282_OPER_MODE_STATUSr_OPERATING_MODE_STATUSf_GET
#define OPER_MODE_STATUSr_OPERATING_MODE_STATUSf_SET BCM54282_OPER_MODE_STATUSr_OPERATING_MODE_STATUSf_SET
#define READ_OPER_MODE_STATUSr BCM54282_READ_OPER_MODE_STATUSr
#define WRITE_OPER_MODE_STATUSr BCM54282_WRITE_OPER_MODE_STATUSr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_OPER_MODE_STATUSr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  SERDES_100FX_CTRL
 * BLOCKS:   RDB
 * REGADDR:  0x0233
 * DESC:     SERDES_100FX_CTRL Register (RDB_Register, offset 0x233)
 * SIZE:     32
 * FIELDS:
 *     FX_SERDES_EN     FD_FX_SERDES.
 *     FD_FX_SERDES     FD_FX_SERDES.
 *
 ******************************************************************************/
#define BCM54282_SERDES_100FX_CTRLr (0x00000233 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_SERDES_100FX_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program SERDES_100FX_CTRL.
 *
 */
typedef union BCM54282_SERDES_100FX_CTRLr_s {
	uint32_t v[1];
	uint32_t serdes_100fx_ctrl[1];
	uint32_t _serdes_100fx_ctrl;
} BCM54282_SERDES_100FX_CTRLr_t;

#define BCM54282_SERDES_100FX_CTRLr_CLR(r) (r).serdes_100fx_ctrl[0] = 0
#define BCM54282_SERDES_100FX_CTRLr_SET(r,d) (r).serdes_100fx_ctrl[0] = d
#define BCM54282_SERDES_100FX_CTRLr_GET(r) (r).serdes_100fx_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_SERDES_100FX_CTRLr_FD_FX_SERDESf_GET(r) ((((r).serdes_100fx_ctrl[0]) >> 1) & 0x1)
#define BCM54282_SERDES_100FX_CTRLr_FD_FX_SERDESf_SET(r,f) (r).serdes_100fx_ctrl[0]=(((r).serdes_100fx_ctrl[0] & ~((uint32_t)0x1 << 1)) | ((((uint32_t)f) & 0x1) << 1))
#define BCM54282_SERDES_100FX_CTRLr_FX_SERDES_ENf_GET(r) (((r).serdes_100fx_ctrl[0]) & 0x1)
#define BCM54282_SERDES_100FX_CTRLr_FX_SERDES_ENf_SET(r,f) (r).serdes_100fx_ctrl[0]=(((r).serdes_100fx_ctrl[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access SERDES_100FX_CTRL.
 *
 */
#define BCM54282_READ_SERDES_100FX_CTRLr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_SERDES_100FX_CTRLr,(_r._serdes_100fx_ctrl))
#define BCM54282_WRITE_SERDES_100FX_CTRLr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_SERDES_100FX_CTRLr,(_r._serdes_100fx_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define SERDES_100FX_CTRLr BCM54282_SERDES_100FX_CTRLr
#define SERDES_100FX_CTRLr_SIZE BCM54282_SERDES_100FX_CTRLr_SIZE
typedef BCM54282_SERDES_100FX_CTRLr_t SERDES_100FX_CTRLr_t;
#define SERDES_100FX_CTRLr_CLR BCM54282_SERDES_100FX_CTRLr_CLR
#define SERDES_100FX_CTRLr_SET BCM54282_SERDES_100FX_CTRLr_SET
#define SERDES_100FX_CTRLr_GET BCM54282_SERDES_100FX_CTRLr_GET
#define SERDES_100FX_CTRLr_FD_FX_SERDESf_GET BCM54282_SERDES_100FX_CTRLr_FD_FX_SERDESf_GET
#define SERDES_100FX_CTRLr_FD_FX_SERDESf_SET BCM54282_SERDES_100FX_CTRLr_FD_FX_SERDESf_SET
#define SERDES_100FX_CTRLr_FX_SERDES_ENf_GET BCM54282_SERDES_100FX_CTRLr_FX_SERDES_ENf_GET
#define SERDES_100FX_CTRLr_FX_SERDES_ENf_SET BCM54282_SERDES_100FX_CTRLr_FX_SERDES_ENf_SET
#define READ_SERDES_100FX_CTRLr BCM54282_READ_SERDES_100FX_CTRLr
#define WRITE_SERDES_100FX_CTRLr BCM54282_WRITE_SERDES_100FX_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_SERDES_100FX_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_BUFFER_CONTROL_0
 * BLOCKS:   RDB
 * REGADDR:  0x0800
 * DESC:     Array alias for MII_BUFFER_CONTROL_0_PHY[0-7]
 * SIZE:     32
 * FIELDS:
 *     AUTOGREEEN_ENABLE Enable AutogrEEEn mode
 *     VAR_LATENCY_EN   Variable latency enable
 *     VARIABLE_IFG_LENGTH IFG used to flush the buffer in variable latency mode
 *     WAIT_IFG_LENGTH  Number of IDLE symbols required before asserting local LPI request
 *     CONFIG_WAKE_ST_TIMER Amount of time the data is buffered before it is transmitted on the MDI
 *     DISABLE_LOC_LPI_HALF_DUPLEX Prevent MII buffer from sending LOC LPI request when in half-duplex mode
 *
 ******************************************************************************/
#define BCM54282_MII_BUFFER_CONTROL_0r (0x00000800 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_MII_BUFFER_CONTROL_0r_SIZE 4

/*
 * This structure should be used to declare and program MII_BUFFER_CONTROL_0.
 *
 */
typedef union BCM54282_MII_BUFFER_CONTROL_0r_s {
	uint32_t v[1];
	uint32_t mii_buffer_control_0[1];
	uint32_t _mii_buffer_control_0;
} BCM54282_MII_BUFFER_CONTROL_0r_t;

#define BCM54282_MII_BUFFER_CONTROL_0r_CLR(r) (r).mii_buffer_control_0[0] = 0
#define BCM54282_MII_BUFFER_CONTROL_0r_SET(r,d) (r).mii_buffer_control_0[0] = d
#define BCM54282_MII_BUFFER_CONTROL_0r_GET(r) (r).mii_buffer_control_0[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_BUFFER_CONTROL_0r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET(r) ((((r).mii_buffer_control_0[0]) >> 15) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET(r,f) (r).mii_buffer_control_0[0]=(((r).mii_buffer_control_0[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_BUFFER_CONTROL_0r_CONFIG_WAKE_ST_TIMERf_GET(r) ((((r).mii_buffer_control_0[0]) >> 11) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0r_CONFIG_WAKE_ST_TIMERf_SET(r,f) (r).mii_buffer_control_0[0]=(((r).mii_buffer_control_0[0] & ~((uint32_t)0x7 << 11)) | ((((uint32_t)f) & 0x7) << 11))
#define BCM54282_MII_BUFFER_CONTROL_0r_WAIT_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0[0]) >> 8) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0r_WAIT_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0[0]=(((r).mii_buffer_control_0[0] & ~((uint32_t)0x7 << 8)) | ((((uint32_t)f) & 0x7) << 8))
#define BCM54282_MII_BUFFER_CONTROL_0r_VARIABLE_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0[0]) >> 3) & 0x1f)
#define BCM54282_MII_BUFFER_CONTROL_0r_VARIABLE_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0[0]=(((r).mii_buffer_control_0[0] & ~((uint32_t)0x1f << 3)) | ((((uint32_t)f) & 0x1f) << 3))
#define BCM54282_MII_BUFFER_CONTROL_0r_VAR_LATENCY_ENf_GET(r) ((((r).mii_buffer_control_0[0]) >> 2) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0r_VAR_LATENCY_ENf_SET(r,f) (r).mii_buffer_control_0[0]=(((r).mii_buffer_control_0[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_BUFFER_CONTROL_0r_AUTOGREEEN_ENABLEf_GET(r) (((r).mii_buffer_control_0[0]) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0r_AUTOGREEEN_ENABLEf_SET(r,f) (r).mii_buffer_control_0[0]=(((r).mii_buffer_control_0[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_BUFFER_CONTROL_0.
 *
 */
#define BCM54282_READ_MII_BUFFER_CONTROL_0r(_pc,_i,_r) phy_brcm_rdb_read(_pc,BCM54282_MII_BUFFER_CONTROL_0r+((_i)*2),(_r._mii_buffer_control_0))
#define BCM54282_WRITE_MII_BUFFER_CONTROL_0r(_pc,_i,_r) phy_brcm_rdb_write(_pc,BCM54282_MII_BUFFER_CONTROL_0r+((_i)*2),(_r._mii_buffer_control_0))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_BUFFER_CONTROL_0r BCM54282_MII_BUFFER_CONTROL_0r
#define MII_BUFFER_CONTROL_0r_SIZE BCM54282_MII_BUFFER_CONTROL_0r_SIZE
typedef BCM54282_MII_BUFFER_CONTROL_0r_t MII_BUFFER_CONTROL_0r_t;
#define MII_BUFFER_CONTROL_0r_CLR BCM54282_MII_BUFFER_CONTROL_0r_CLR
#define MII_BUFFER_CONTROL_0r_SET BCM54282_MII_BUFFER_CONTROL_0r_SET
#define MII_BUFFER_CONTROL_0r_GET BCM54282_MII_BUFFER_CONTROL_0r_GET
#define MII_BUFFER_CONTROL_0r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET BCM54282_MII_BUFFER_CONTROL_0r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET
#define MII_BUFFER_CONTROL_0r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET BCM54282_MII_BUFFER_CONTROL_0r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET
#define MII_BUFFER_CONTROL_0r_CONFIG_WAKE_ST_TIMERf_GET BCM54282_MII_BUFFER_CONTROL_0r_CONFIG_WAKE_ST_TIMERf_GET
#define MII_BUFFER_CONTROL_0r_CONFIG_WAKE_ST_TIMERf_SET BCM54282_MII_BUFFER_CONTROL_0r_CONFIG_WAKE_ST_TIMERf_SET
#define MII_BUFFER_CONTROL_0r_WAIT_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0r_WAIT_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0r_WAIT_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0r_WAIT_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0r_VARIABLE_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0r_VARIABLE_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0r_VARIABLE_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0r_VARIABLE_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0r_VAR_LATENCY_ENf_GET BCM54282_MII_BUFFER_CONTROL_0r_VAR_LATENCY_ENf_GET
#define MII_BUFFER_CONTROL_0r_VAR_LATENCY_ENf_SET BCM54282_MII_BUFFER_CONTROL_0r_VAR_LATENCY_ENf_SET
#define MII_BUFFER_CONTROL_0r_AUTOGREEEN_ENABLEf_GET BCM54282_MII_BUFFER_CONTROL_0r_AUTOGREEEN_ENABLEf_GET
#define MII_BUFFER_CONTROL_0r_AUTOGREEEN_ENABLEf_SET BCM54282_MII_BUFFER_CONTROL_0r_AUTOGREEEN_ENABLEf_SET
#define READ_MII_BUFFER_CONTROL_0r BCM54282_READ_MII_BUFFER_CONTROL_0r
#define WRITE_MII_BUFFER_CONTROL_0r BCM54282_WRITE_MII_BUFFER_CONTROL_0r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_BUFFER_CONTROL_0r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_BUFFER_CONTROL_0_PHY0
 * BLOCKS:   RDB
 * REGADDR:  0x0800
 * DESC:     MII_BUFFER_CONTROL_0_PHY0 Register (RDB_Register, offset 0x800)
 * SIZE:     32
 * FIELDS:
 *     AUTOGREEEN_ENABLE Enable AutogrEEEn mode
 *     VAR_LATENCY_EN   Variable latency enable
 *     VARIABLE_IFG_LENGTH IFG used to flush the buffer in variable latency mode
 *     WAIT_IFG_LENGTH  Number of IDLE symbols required before asserting local LPI request
 *     CONFIG_WAKE_ST_TIMER Amount of time the data is buffered before it is transmitted on the MDI
 *     DISABLE_LOC_LPI_HALF_DUPLEX Prevent MII buffer from sending LOC LPI request when in half-duplex mode
 *
 ******************************************************************************/
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r (0x00000800 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_SIZE 4

/*
 * This structure should be used to declare and program MII_BUFFER_CONTROL_0_PHY0.
 *
 */
typedef union BCM54282_MII_BUFFER_CONTROL_0_PHY0r_s {
	uint32_t v[1];
	uint32_t mii_buffer_control_0_phy0[1];
	uint32_t _mii_buffer_control_0_phy0;
} BCM54282_MII_BUFFER_CONTROL_0_PHY0r_t;

#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_CLR(r) (r).mii_buffer_control_0_phy0[0] = 0
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_SET(r,d) (r).mii_buffer_control_0_phy0[0] = d
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_GET(r) (r).mii_buffer_control_0_phy0[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET(r) ((((r).mii_buffer_control_0_phy0[0]) >> 15) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET(r,f) (r).mii_buffer_control_0_phy0[0]=(((r).mii_buffer_control_0_phy0[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_CONFIG_WAKE_ST_TIMERf_GET(r) ((((r).mii_buffer_control_0_phy0[0]) >> 11) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_CONFIG_WAKE_ST_TIMERf_SET(r,f) (r).mii_buffer_control_0_phy0[0]=(((r).mii_buffer_control_0_phy0[0] & ~((uint32_t)0x7 << 11)) | ((((uint32_t)f) & 0x7) << 11))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_WAIT_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy0[0]) >> 8) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_WAIT_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy0[0]=(((r).mii_buffer_control_0_phy0[0] & ~((uint32_t)0x7 << 8)) | ((((uint32_t)f) & 0x7) << 8))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_VARIABLE_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy0[0]) >> 3) & 0x1f)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_VARIABLE_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy0[0]=(((r).mii_buffer_control_0_phy0[0] & ~((uint32_t)0x1f << 3)) | ((((uint32_t)f) & 0x1f) << 3))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_VAR_LATENCY_ENf_GET(r) ((((r).mii_buffer_control_0_phy0[0]) >> 2) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_VAR_LATENCY_ENf_SET(r,f) (r).mii_buffer_control_0_phy0[0]=(((r).mii_buffer_control_0_phy0[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_AUTOGREEEN_ENABLEf_GET(r) (((r).mii_buffer_control_0_phy0[0]) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY0r_AUTOGREEEN_ENABLEf_SET(r,f) (r).mii_buffer_control_0_phy0[0]=(((r).mii_buffer_control_0_phy0[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_BUFFER_CONTROL_0_PHY0.
 *
 */
#define BCM54282_READ_MII_BUFFER_CONTROL_0_PHY0r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY0r,(_r._mii_buffer_control_0_phy0))
#define BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY0r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY0r,(_r._mii_buffer_control_0_phy0))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_BUFFER_CONTROL_0_PHY0r BCM54282_MII_BUFFER_CONTROL_0_PHY0r
#define MII_BUFFER_CONTROL_0_PHY0r_SIZE BCM54282_MII_BUFFER_CONTROL_0_PHY0r_SIZE
typedef BCM54282_MII_BUFFER_CONTROL_0_PHY0r_t MII_BUFFER_CONTROL_0_PHY0r_t;
#define MII_BUFFER_CONTROL_0_PHY0r_CLR BCM54282_MII_BUFFER_CONTROL_0_PHY0r_CLR
#define MII_BUFFER_CONTROL_0_PHY0r_SET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_SET
#define MII_BUFFER_CONTROL_0_PHY0r_GET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_GET
#define MII_BUFFER_CONTROL_0_PHY0r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET
#define MII_BUFFER_CONTROL_0_PHY0r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET
#define MII_BUFFER_CONTROL_0_PHY0r_CONFIG_WAKE_ST_TIMERf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_CONFIG_WAKE_ST_TIMERf_GET
#define MII_BUFFER_CONTROL_0_PHY0r_CONFIG_WAKE_ST_TIMERf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_CONFIG_WAKE_ST_TIMERf_SET
#define MII_BUFFER_CONTROL_0_PHY0r_WAIT_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_WAIT_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY0r_WAIT_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_WAIT_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY0r_VARIABLE_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_VARIABLE_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY0r_VARIABLE_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_VARIABLE_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY0r_VAR_LATENCY_ENf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_VAR_LATENCY_ENf_GET
#define MII_BUFFER_CONTROL_0_PHY0r_VAR_LATENCY_ENf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_VAR_LATENCY_ENf_SET
#define MII_BUFFER_CONTROL_0_PHY0r_AUTOGREEEN_ENABLEf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_AUTOGREEEN_ENABLEf_GET
#define MII_BUFFER_CONTROL_0_PHY0r_AUTOGREEEN_ENABLEf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY0r_AUTOGREEEN_ENABLEf_SET
#define READ_MII_BUFFER_CONTROL_0_PHY0r BCM54282_READ_MII_BUFFER_CONTROL_0_PHY0r
#define WRITE_MII_BUFFER_CONTROL_0_PHY0r BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY0r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_BUFFER_CONTROL_0_PHY0r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_BUFFER_CONTROL_0_PHY1
 * BLOCKS:   RDB
 * REGADDR:  0x0802
 * DESC:     MII_BUFFER_CONTROL_0_PHY1 Register (RDB_Register, offset 0x802)
 * SIZE:     32
 * FIELDS:
 *     AUTOGREEEN_ENABLE Enable AutogrEEEn mode
 *     VAR_LATENCY_EN   Variable latency enable
 *     VARIABLE_IFG_LENGTH IFG used to flush the buffer in variable latency mode
 *     WAIT_IFG_LENGTH  Number of IDLE symbols required before asserting local LPI request
 *     CONFIG_WAKE_ST_TIMER Amount of time the data is buffered before it is transmitted on the MDI
 *     DISABLE_LOC_LPI_HALF_DUPLEX Prevent MII buffer from sending LOC LPI request when in half-duplex mode
 *
 ******************************************************************************/
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r (0x00000802 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_SIZE 4

/*
 * This structure should be used to declare and program MII_BUFFER_CONTROL_0_PHY1.
 *
 */
typedef union BCM54282_MII_BUFFER_CONTROL_0_PHY1r_s {
	uint32_t v[1];
	uint32_t mii_buffer_control_0_phy1[1];
	uint32_t _mii_buffer_control_0_phy1;
} BCM54282_MII_BUFFER_CONTROL_0_PHY1r_t;

#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_CLR(r) (r).mii_buffer_control_0_phy1[0] = 0
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_SET(r,d) (r).mii_buffer_control_0_phy1[0] = d
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_GET(r) (r).mii_buffer_control_0_phy1[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET(r) ((((r).mii_buffer_control_0_phy1[0]) >> 15) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET(r,f) (r).mii_buffer_control_0_phy1[0]=(((r).mii_buffer_control_0_phy1[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_CONFIG_WAKE_ST_TIMERf_GET(r) ((((r).mii_buffer_control_0_phy1[0]) >> 11) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_CONFIG_WAKE_ST_TIMERf_SET(r,f) (r).mii_buffer_control_0_phy1[0]=(((r).mii_buffer_control_0_phy1[0] & ~((uint32_t)0x7 << 11)) | ((((uint32_t)f) & 0x7) << 11))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_WAIT_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy1[0]) >> 8) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_WAIT_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy1[0]=(((r).mii_buffer_control_0_phy1[0] & ~((uint32_t)0x7 << 8)) | ((((uint32_t)f) & 0x7) << 8))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_VARIABLE_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy1[0]) >> 3) & 0x1f)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_VARIABLE_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy1[0]=(((r).mii_buffer_control_0_phy1[0] & ~((uint32_t)0x1f << 3)) | ((((uint32_t)f) & 0x1f) << 3))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_VAR_LATENCY_ENf_GET(r) ((((r).mii_buffer_control_0_phy1[0]) >> 2) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_VAR_LATENCY_ENf_SET(r,f) (r).mii_buffer_control_0_phy1[0]=(((r).mii_buffer_control_0_phy1[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_AUTOGREEEN_ENABLEf_GET(r) (((r).mii_buffer_control_0_phy1[0]) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY1r_AUTOGREEEN_ENABLEf_SET(r,f) (r).mii_buffer_control_0_phy1[0]=(((r).mii_buffer_control_0_phy1[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_BUFFER_CONTROL_0_PHY1.
 *
 */
#define BCM54282_READ_MII_BUFFER_CONTROL_0_PHY1r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY1r,(_r._mii_buffer_control_0_phy1))
#define BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY1r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY1r,(_r._mii_buffer_control_0_phy1))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_BUFFER_CONTROL_0_PHY1r BCM54282_MII_BUFFER_CONTROL_0_PHY1r
#define MII_BUFFER_CONTROL_0_PHY1r_SIZE BCM54282_MII_BUFFER_CONTROL_0_PHY1r_SIZE
typedef BCM54282_MII_BUFFER_CONTROL_0_PHY1r_t MII_BUFFER_CONTROL_0_PHY1r_t;
#define MII_BUFFER_CONTROL_0_PHY1r_CLR BCM54282_MII_BUFFER_CONTROL_0_PHY1r_CLR
#define MII_BUFFER_CONTROL_0_PHY1r_SET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_SET
#define MII_BUFFER_CONTROL_0_PHY1r_GET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_GET
#define MII_BUFFER_CONTROL_0_PHY1r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET
#define MII_BUFFER_CONTROL_0_PHY1r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET
#define MII_BUFFER_CONTROL_0_PHY1r_CONFIG_WAKE_ST_TIMERf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_CONFIG_WAKE_ST_TIMERf_GET
#define MII_BUFFER_CONTROL_0_PHY1r_CONFIG_WAKE_ST_TIMERf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_CONFIG_WAKE_ST_TIMERf_SET
#define MII_BUFFER_CONTROL_0_PHY1r_WAIT_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_WAIT_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY1r_WAIT_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_WAIT_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY1r_VARIABLE_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_VARIABLE_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY1r_VARIABLE_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_VARIABLE_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY1r_VAR_LATENCY_ENf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_VAR_LATENCY_ENf_GET
#define MII_BUFFER_CONTROL_0_PHY1r_VAR_LATENCY_ENf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_VAR_LATENCY_ENf_SET
#define MII_BUFFER_CONTROL_0_PHY1r_AUTOGREEEN_ENABLEf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_AUTOGREEEN_ENABLEf_GET
#define MII_BUFFER_CONTROL_0_PHY1r_AUTOGREEEN_ENABLEf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY1r_AUTOGREEEN_ENABLEf_SET
#define READ_MII_BUFFER_CONTROL_0_PHY1r BCM54282_READ_MII_BUFFER_CONTROL_0_PHY1r
#define WRITE_MII_BUFFER_CONTROL_0_PHY1r BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY1r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_BUFFER_CONTROL_0_PHY1r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_BUFFER_CONTROL_0_PHY2
 * BLOCKS:   RDB
 * REGADDR:  0x0804
 * DESC:     MII_BUFFER_CONTROL_0_PHY2 Register (RDB_Register, offset 0x804)
 * SIZE:     32
 * FIELDS:
 *     AUTOGREEEN_ENABLE Enable AutogrEEEn mode
 *     VAR_LATENCY_EN   Variable latency enable
 *     VARIABLE_IFG_LENGTH IFG used to flush the buffer in variable latency mode
 *     WAIT_IFG_LENGTH  Number of IDLE symbols required before asserting local LPI request
 *     CONFIG_WAKE_ST_TIMER Amount of time the data is buffered before it is transmitted on the MDI
 *     DISABLE_LOC_LPI_HALF_DUPLEX Prevent MII buffer from sending LOC LPI request when in half-duplex mode
 *
 ******************************************************************************/
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r (0x00000804 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_SIZE 4

/*
 * This structure should be used to declare and program MII_BUFFER_CONTROL_0_PHY2.
 *
 */
typedef union BCM54282_MII_BUFFER_CONTROL_0_PHY2r_s {
	uint32_t v[1];
	uint32_t mii_buffer_control_0_phy2[1];
	uint32_t _mii_buffer_control_0_phy2;
} BCM54282_MII_BUFFER_CONTROL_0_PHY2r_t;

#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_CLR(r) (r).mii_buffer_control_0_phy2[0] = 0
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_SET(r,d) (r).mii_buffer_control_0_phy2[0] = d
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_GET(r) (r).mii_buffer_control_0_phy2[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET(r) ((((r).mii_buffer_control_0_phy2[0]) >> 15) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET(r,f) (r).mii_buffer_control_0_phy2[0]=(((r).mii_buffer_control_0_phy2[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_CONFIG_WAKE_ST_TIMERf_GET(r) ((((r).mii_buffer_control_0_phy2[0]) >> 11) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_CONFIG_WAKE_ST_TIMERf_SET(r,f) (r).mii_buffer_control_0_phy2[0]=(((r).mii_buffer_control_0_phy2[0] & ~((uint32_t)0x7 << 11)) | ((((uint32_t)f) & 0x7) << 11))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_WAIT_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy2[0]) >> 8) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_WAIT_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy2[0]=(((r).mii_buffer_control_0_phy2[0] & ~((uint32_t)0x7 << 8)) | ((((uint32_t)f) & 0x7) << 8))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_VARIABLE_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy2[0]) >> 3) & 0x1f)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_VARIABLE_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy2[0]=(((r).mii_buffer_control_0_phy2[0] & ~((uint32_t)0x1f << 3)) | ((((uint32_t)f) & 0x1f) << 3))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_VAR_LATENCY_ENf_GET(r) ((((r).mii_buffer_control_0_phy2[0]) >> 2) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_VAR_LATENCY_ENf_SET(r,f) (r).mii_buffer_control_0_phy2[0]=(((r).mii_buffer_control_0_phy2[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_AUTOGREEEN_ENABLEf_GET(r) (((r).mii_buffer_control_0_phy2[0]) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY2r_AUTOGREEEN_ENABLEf_SET(r,f) (r).mii_buffer_control_0_phy2[0]=(((r).mii_buffer_control_0_phy2[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_BUFFER_CONTROL_0_PHY2.
 *
 */
#define BCM54282_READ_MII_BUFFER_CONTROL_0_PHY2r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY2r,(_r._mii_buffer_control_0_phy2))
#define BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY2r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY2r,(_r._mii_buffer_control_0_phy2))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_BUFFER_CONTROL_0_PHY2r BCM54282_MII_BUFFER_CONTROL_0_PHY2r
#define MII_BUFFER_CONTROL_0_PHY2r_SIZE BCM54282_MII_BUFFER_CONTROL_0_PHY2r_SIZE
typedef BCM54282_MII_BUFFER_CONTROL_0_PHY2r_t MII_BUFFER_CONTROL_0_PHY2r_t;
#define MII_BUFFER_CONTROL_0_PHY2r_CLR BCM54282_MII_BUFFER_CONTROL_0_PHY2r_CLR
#define MII_BUFFER_CONTROL_0_PHY2r_SET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_SET
#define MII_BUFFER_CONTROL_0_PHY2r_GET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_GET
#define MII_BUFFER_CONTROL_0_PHY2r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET
#define MII_BUFFER_CONTROL_0_PHY2r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET
#define MII_BUFFER_CONTROL_0_PHY2r_CONFIG_WAKE_ST_TIMERf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_CONFIG_WAKE_ST_TIMERf_GET
#define MII_BUFFER_CONTROL_0_PHY2r_CONFIG_WAKE_ST_TIMERf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_CONFIG_WAKE_ST_TIMERf_SET
#define MII_BUFFER_CONTROL_0_PHY2r_WAIT_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_WAIT_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY2r_WAIT_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_WAIT_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY2r_VARIABLE_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_VARIABLE_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY2r_VARIABLE_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_VARIABLE_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY2r_VAR_LATENCY_ENf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_VAR_LATENCY_ENf_GET
#define MII_BUFFER_CONTROL_0_PHY2r_VAR_LATENCY_ENf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_VAR_LATENCY_ENf_SET
#define MII_BUFFER_CONTROL_0_PHY2r_AUTOGREEEN_ENABLEf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_AUTOGREEEN_ENABLEf_GET
#define MII_BUFFER_CONTROL_0_PHY2r_AUTOGREEEN_ENABLEf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY2r_AUTOGREEEN_ENABLEf_SET
#define READ_MII_BUFFER_CONTROL_0_PHY2r BCM54282_READ_MII_BUFFER_CONTROL_0_PHY2r
#define WRITE_MII_BUFFER_CONTROL_0_PHY2r BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY2r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_BUFFER_CONTROL_0_PHY2r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_BUFFER_CONTROL_0_PHY3
 * BLOCKS:   RDB
 * REGADDR:  0x0806
 * DESC:     MII_BUFFER_CONTROL_0_PHY3 Register (RDB_Register, offset 0x806)
 * SIZE:     32
 * FIELDS:
 *     AUTOGREEEN_ENABLE Enable AutogrEEEn mode
 *     VAR_LATENCY_EN   Variable latency enable
 *     VARIABLE_IFG_LENGTH IFG used to flush the buffer in variable latency mode
 *     WAIT_IFG_LENGTH  Number of IDLE symbols required before asserting local LPI request
 *     CONFIG_WAKE_ST_TIMER Amount of time the data is buffered before it is transmitted on the MDI
 *     DISABLE_LOC_LPI_HALF_DUPLEX Prevent MII buffer from sending LOC LPI request when in half-duplex mode
 *
 ******************************************************************************/
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r (0x00000806 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_SIZE 4

/*
 * This structure should be used to declare and program MII_BUFFER_CONTROL_0_PHY3.
 *
 */
typedef union BCM54282_MII_BUFFER_CONTROL_0_PHY3r_s {
	uint32_t v[1];
	uint32_t mii_buffer_control_0_phy3[1];
	uint32_t _mii_buffer_control_0_phy3;
} BCM54282_MII_BUFFER_CONTROL_0_PHY3r_t;

#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_CLR(r) (r).mii_buffer_control_0_phy3[0] = 0
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_SET(r,d) (r).mii_buffer_control_0_phy3[0] = d
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_GET(r) (r).mii_buffer_control_0_phy3[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET(r) ((((r).mii_buffer_control_0_phy3[0]) >> 15) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET(r,f) (r).mii_buffer_control_0_phy3[0]=(((r).mii_buffer_control_0_phy3[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_CONFIG_WAKE_ST_TIMERf_GET(r) ((((r).mii_buffer_control_0_phy3[0]) >> 11) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_CONFIG_WAKE_ST_TIMERf_SET(r,f) (r).mii_buffer_control_0_phy3[0]=(((r).mii_buffer_control_0_phy3[0] & ~((uint32_t)0x7 << 11)) | ((((uint32_t)f) & 0x7) << 11))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_WAIT_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy3[0]) >> 8) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_WAIT_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy3[0]=(((r).mii_buffer_control_0_phy3[0] & ~((uint32_t)0x7 << 8)) | ((((uint32_t)f) & 0x7) << 8))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_VARIABLE_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy3[0]) >> 3) & 0x1f)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_VARIABLE_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy3[0]=(((r).mii_buffer_control_0_phy3[0] & ~((uint32_t)0x1f << 3)) | ((((uint32_t)f) & 0x1f) << 3))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_VAR_LATENCY_ENf_GET(r) ((((r).mii_buffer_control_0_phy3[0]) >> 2) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_VAR_LATENCY_ENf_SET(r,f) (r).mii_buffer_control_0_phy3[0]=(((r).mii_buffer_control_0_phy3[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_AUTOGREEEN_ENABLEf_GET(r) (((r).mii_buffer_control_0_phy3[0]) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY3r_AUTOGREEEN_ENABLEf_SET(r,f) (r).mii_buffer_control_0_phy3[0]=(((r).mii_buffer_control_0_phy3[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_BUFFER_CONTROL_0_PHY3.
 *
 */
#define BCM54282_READ_MII_BUFFER_CONTROL_0_PHY3r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY3r,(_r._mii_buffer_control_0_phy3))
#define BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY3r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY3r,(_r._mii_buffer_control_0_phy3))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_BUFFER_CONTROL_0_PHY3r BCM54282_MII_BUFFER_CONTROL_0_PHY3r
#define MII_BUFFER_CONTROL_0_PHY3r_SIZE BCM54282_MII_BUFFER_CONTROL_0_PHY3r_SIZE
typedef BCM54282_MII_BUFFER_CONTROL_0_PHY3r_t MII_BUFFER_CONTROL_0_PHY3r_t;
#define MII_BUFFER_CONTROL_0_PHY3r_CLR BCM54282_MII_BUFFER_CONTROL_0_PHY3r_CLR
#define MII_BUFFER_CONTROL_0_PHY3r_SET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_SET
#define MII_BUFFER_CONTROL_0_PHY3r_GET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_GET
#define MII_BUFFER_CONTROL_0_PHY3r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET
#define MII_BUFFER_CONTROL_0_PHY3r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET
#define MII_BUFFER_CONTROL_0_PHY3r_CONFIG_WAKE_ST_TIMERf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_CONFIG_WAKE_ST_TIMERf_GET
#define MII_BUFFER_CONTROL_0_PHY3r_CONFIG_WAKE_ST_TIMERf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_CONFIG_WAKE_ST_TIMERf_SET
#define MII_BUFFER_CONTROL_0_PHY3r_WAIT_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_WAIT_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY3r_WAIT_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_WAIT_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY3r_VARIABLE_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_VARIABLE_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY3r_VARIABLE_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_VARIABLE_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY3r_VAR_LATENCY_ENf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_VAR_LATENCY_ENf_GET
#define MII_BUFFER_CONTROL_0_PHY3r_VAR_LATENCY_ENf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_VAR_LATENCY_ENf_SET
#define MII_BUFFER_CONTROL_0_PHY3r_AUTOGREEEN_ENABLEf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_AUTOGREEEN_ENABLEf_GET
#define MII_BUFFER_CONTROL_0_PHY3r_AUTOGREEEN_ENABLEf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY3r_AUTOGREEEN_ENABLEf_SET
#define READ_MII_BUFFER_CONTROL_0_PHY3r BCM54282_READ_MII_BUFFER_CONTROL_0_PHY3r
#define WRITE_MII_BUFFER_CONTROL_0_PHY3r BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY3r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_BUFFER_CONTROL_0_PHY3r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_BUFFER_CONTROL_0_PHY4
 * BLOCKS:   RDB
 * REGADDR:  0x0808
 * DESC:     MII_BUFFER_CONTROL_0_PHY4 Register (RDB_Register, offset 0x808)
 * SIZE:     32
 * FIELDS:
 *     AUTOGREEEN_ENABLE Enable AutogrEEEn mode
 *     VAR_LATENCY_EN   Variable latency enable
 *     VARIABLE_IFG_LENGTH IFG used to flush the buffer in variable latency mode
 *     WAIT_IFG_LENGTH  Number of IDLE symbols required before asserting local LPI request
 *     CONFIG_WAKE_ST_TIMER Amount of time the data is buffered before it is transmitted on the MDI
 *     DISABLE_LOC_LPI_HALF_DUPLEX Prevent MII buffer from sending LOC LPI request when in half-duplex mode
 *
 ******************************************************************************/
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r (0x00000808 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_SIZE 4

/*
 * This structure should be used to declare and program MII_BUFFER_CONTROL_0_PHY4.
 *
 */
typedef union BCM54282_MII_BUFFER_CONTROL_0_PHY4r_s {
	uint32_t v[1];
	uint32_t mii_buffer_control_0_phy4[1];
	uint32_t _mii_buffer_control_0_phy4;
} BCM54282_MII_BUFFER_CONTROL_0_PHY4r_t;

#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_CLR(r) (r).mii_buffer_control_0_phy4[0] = 0
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_SET(r,d) (r).mii_buffer_control_0_phy4[0] = d
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_GET(r) (r).mii_buffer_control_0_phy4[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET(r) ((((r).mii_buffer_control_0_phy4[0]) >> 15) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET(r,f) (r).mii_buffer_control_0_phy4[0]=(((r).mii_buffer_control_0_phy4[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_CONFIG_WAKE_ST_TIMERf_GET(r) ((((r).mii_buffer_control_0_phy4[0]) >> 11) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_CONFIG_WAKE_ST_TIMERf_SET(r,f) (r).mii_buffer_control_0_phy4[0]=(((r).mii_buffer_control_0_phy4[0] & ~((uint32_t)0x7 << 11)) | ((((uint32_t)f) & 0x7) << 11))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_WAIT_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy4[0]) >> 8) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_WAIT_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy4[0]=(((r).mii_buffer_control_0_phy4[0] & ~((uint32_t)0x7 << 8)) | ((((uint32_t)f) & 0x7) << 8))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_VARIABLE_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy4[0]) >> 3) & 0x1f)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_VARIABLE_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy4[0]=(((r).mii_buffer_control_0_phy4[0] & ~((uint32_t)0x1f << 3)) | ((((uint32_t)f) & 0x1f) << 3))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_VAR_LATENCY_ENf_GET(r) ((((r).mii_buffer_control_0_phy4[0]) >> 2) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_VAR_LATENCY_ENf_SET(r,f) (r).mii_buffer_control_0_phy4[0]=(((r).mii_buffer_control_0_phy4[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_AUTOGREEEN_ENABLEf_GET(r) (((r).mii_buffer_control_0_phy4[0]) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY4r_AUTOGREEEN_ENABLEf_SET(r,f) (r).mii_buffer_control_0_phy4[0]=(((r).mii_buffer_control_0_phy4[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_BUFFER_CONTROL_0_PHY4.
 *
 */
#define BCM54282_READ_MII_BUFFER_CONTROL_0_PHY4r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY4r,(_r._mii_buffer_control_0_phy4))
#define BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY4r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY4r,(_r._mii_buffer_control_0_phy4))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_BUFFER_CONTROL_0_PHY4r BCM54282_MII_BUFFER_CONTROL_0_PHY4r
#define MII_BUFFER_CONTROL_0_PHY4r_SIZE BCM54282_MII_BUFFER_CONTROL_0_PHY4r_SIZE
typedef BCM54282_MII_BUFFER_CONTROL_0_PHY4r_t MII_BUFFER_CONTROL_0_PHY4r_t;
#define MII_BUFFER_CONTROL_0_PHY4r_CLR BCM54282_MII_BUFFER_CONTROL_0_PHY4r_CLR
#define MII_BUFFER_CONTROL_0_PHY4r_SET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_SET
#define MII_BUFFER_CONTROL_0_PHY4r_GET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_GET
#define MII_BUFFER_CONTROL_0_PHY4r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET
#define MII_BUFFER_CONTROL_0_PHY4r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET
#define MII_BUFFER_CONTROL_0_PHY4r_CONFIG_WAKE_ST_TIMERf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_CONFIG_WAKE_ST_TIMERf_GET
#define MII_BUFFER_CONTROL_0_PHY4r_CONFIG_WAKE_ST_TIMERf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_CONFIG_WAKE_ST_TIMERf_SET
#define MII_BUFFER_CONTROL_0_PHY4r_WAIT_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_WAIT_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY4r_WAIT_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_WAIT_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY4r_VARIABLE_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_VARIABLE_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY4r_VARIABLE_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_VARIABLE_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY4r_VAR_LATENCY_ENf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_VAR_LATENCY_ENf_GET
#define MII_BUFFER_CONTROL_0_PHY4r_VAR_LATENCY_ENf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_VAR_LATENCY_ENf_SET
#define MII_BUFFER_CONTROL_0_PHY4r_AUTOGREEEN_ENABLEf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_AUTOGREEEN_ENABLEf_GET
#define MII_BUFFER_CONTROL_0_PHY4r_AUTOGREEEN_ENABLEf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY4r_AUTOGREEEN_ENABLEf_SET
#define READ_MII_BUFFER_CONTROL_0_PHY4r BCM54282_READ_MII_BUFFER_CONTROL_0_PHY4r
#define WRITE_MII_BUFFER_CONTROL_0_PHY4r BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY4r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_BUFFER_CONTROL_0_PHY4r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_BUFFER_CONTROL_0_PHY5
 * BLOCKS:   RDB
 * REGADDR:  0x080a
 * DESC:     MII_BUFFER_CONTROL_0_PHY5 Register (RDB_Register, offset 0x80A)
 * SIZE:     32
 * FIELDS:
 *     AUTOGREEEN_ENABLE Enable AutogrEEEn mode
 *     VAR_LATENCY_EN   Variable latency enable
 *     VARIABLE_IFG_LENGTH IFG used to flush the buffer in variable latency mode
 *     WAIT_IFG_LENGTH  Number of IDLE symbols required before asserting local LPI request
 *     CONFIG_WAKE_ST_TIMER Amount of time the data is buffered before it is transmitted on the MDI
 *     DISABLE_LOC_LPI_HALF_DUPLEX Prevent MII buffer from sending LOC LPI request when in half-duplex mode
 *
 ******************************************************************************/
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r (0x0000080a | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_SIZE 4

/*
 * This structure should be used to declare and program MII_BUFFER_CONTROL_0_PHY5.
 *
 */
typedef union BCM54282_MII_BUFFER_CONTROL_0_PHY5r_s {
	uint32_t v[1];
	uint32_t mii_buffer_control_0_phy5[1];
	uint32_t _mii_buffer_control_0_phy5;
} BCM54282_MII_BUFFER_CONTROL_0_PHY5r_t;

#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_CLR(r) (r).mii_buffer_control_0_phy5[0] = 0
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_SET(r,d) (r).mii_buffer_control_0_phy5[0] = d
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_GET(r) (r).mii_buffer_control_0_phy5[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET(r) ((((r).mii_buffer_control_0_phy5[0]) >> 15) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET(r,f) (r).mii_buffer_control_0_phy5[0]=(((r).mii_buffer_control_0_phy5[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_CONFIG_WAKE_ST_TIMERf_GET(r) ((((r).mii_buffer_control_0_phy5[0]) >> 11) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_CONFIG_WAKE_ST_TIMERf_SET(r,f) (r).mii_buffer_control_0_phy5[0]=(((r).mii_buffer_control_0_phy5[0] & ~((uint32_t)0x7 << 11)) | ((((uint32_t)f) & 0x7) << 11))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_WAIT_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy5[0]) >> 8) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_WAIT_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy5[0]=(((r).mii_buffer_control_0_phy5[0] & ~((uint32_t)0x7 << 8)) | ((((uint32_t)f) & 0x7) << 8))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_VARIABLE_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy5[0]) >> 3) & 0x1f)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_VARIABLE_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy5[0]=(((r).mii_buffer_control_0_phy5[0] & ~((uint32_t)0x1f << 3)) | ((((uint32_t)f) & 0x1f) << 3))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_VAR_LATENCY_ENf_GET(r) ((((r).mii_buffer_control_0_phy5[0]) >> 2) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_VAR_LATENCY_ENf_SET(r,f) (r).mii_buffer_control_0_phy5[0]=(((r).mii_buffer_control_0_phy5[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_AUTOGREEEN_ENABLEf_GET(r) (((r).mii_buffer_control_0_phy5[0]) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY5r_AUTOGREEEN_ENABLEf_SET(r,f) (r).mii_buffer_control_0_phy5[0]=(((r).mii_buffer_control_0_phy5[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_BUFFER_CONTROL_0_PHY5.
 *
 */
#define BCM54282_READ_MII_BUFFER_CONTROL_0_PHY5r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY5r,(_r._mii_buffer_control_0_phy5))
#define BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY5r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY5r,(_r._mii_buffer_control_0_phy5))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_BUFFER_CONTROL_0_PHY5r BCM54282_MII_BUFFER_CONTROL_0_PHY5r
#define MII_BUFFER_CONTROL_0_PHY5r_SIZE BCM54282_MII_BUFFER_CONTROL_0_PHY5r_SIZE
typedef BCM54282_MII_BUFFER_CONTROL_0_PHY5r_t MII_BUFFER_CONTROL_0_PHY5r_t;
#define MII_BUFFER_CONTROL_0_PHY5r_CLR BCM54282_MII_BUFFER_CONTROL_0_PHY5r_CLR
#define MII_BUFFER_CONTROL_0_PHY5r_SET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_SET
#define MII_BUFFER_CONTROL_0_PHY5r_GET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_GET
#define MII_BUFFER_CONTROL_0_PHY5r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET
#define MII_BUFFER_CONTROL_0_PHY5r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET
#define MII_BUFFER_CONTROL_0_PHY5r_CONFIG_WAKE_ST_TIMERf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_CONFIG_WAKE_ST_TIMERf_GET
#define MII_BUFFER_CONTROL_0_PHY5r_CONFIG_WAKE_ST_TIMERf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_CONFIG_WAKE_ST_TIMERf_SET
#define MII_BUFFER_CONTROL_0_PHY5r_WAIT_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_WAIT_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY5r_WAIT_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_WAIT_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY5r_VARIABLE_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_VARIABLE_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY5r_VARIABLE_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_VARIABLE_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY5r_VAR_LATENCY_ENf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_VAR_LATENCY_ENf_GET
#define MII_BUFFER_CONTROL_0_PHY5r_VAR_LATENCY_ENf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_VAR_LATENCY_ENf_SET
#define MII_BUFFER_CONTROL_0_PHY5r_AUTOGREEEN_ENABLEf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_AUTOGREEEN_ENABLEf_GET
#define MII_BUFFER_CONTROL_0_PHY5r_AUTOGREEEN_ENABLEf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY5r_AUTOGREEEN_ENABLEf_SET
#define READ_MII_BUFFER_CONTROL_0_PHY5r BCM54282_READ_MII_BUFFER_CONTROL_0_PHY5r
#define WRITE_MII_BUFFER_CONTROL_0_PHY5r BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY5r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_BUFFER_CONTROL_0_PHY5r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_BUFFER_CONTROL_0_PHY6
 * BLOCKS:   RDB
 * REGADDR:  0x080c
 * DESC:     MII_BUFFER_CONTROL_0_PHY6 Register (RDB_Register, offset 0x80C)
 * SIZE:     32
 * FIELDS:
 *     AUTOGREEEN_ENABLE Enable AutogrEEEn mode
 *     VAR_LATENCY_EN   Variable latency enable
 *     VARIABLE_IFG_LENGTH IFG used to flush the buffer in variable latency mode
 *     WAIT_IFG_LENGTH  Number of IDLE symbols required before asserting local LPI request
 *     CONFIG_WAKE_ST_TIMER Amount of time the data is buffered before it is transmitted on the MDI
 *     DISABLE_LOC_LPI_HALF_DUPLEX Prevent MII buffer from sending LOC LPI request when in half-duplex mode
 *
 ******************************************************************************/
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r (0x0000080c | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_SIZE 4

/*
 * This structure should be used to declare and program MII_BUFFER_CONTROL_0_PHY6.
 *
 */
typedef union BCM54282_MII_BUFFER_CONTROL_0_PHY6r_s {
	uint32_t v[1];
	uint32_t mii_buffer_control_0_phy6[1];
	uint32_t _mii_buffer_control_0_phy6;
} BCM54282_MII_BUFFER_CONTROL_0_PHY6r_t;

#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_CLR(r) (r).mii_buffer_control_0_phy6[0] = 0
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_SET(r,d) (r).mii_buffer_control_0_phy6[0] = d
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_GET(r) (r).mii_buffer_control_0_phy6[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET(r) ((((r).mii_buffer_control_0_phy6[0]) >> 15) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET(r,f) (r).mii_buffer_control_0_phy6[0]=(((r).mii_buffer_control_0_phy6[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_CONFIG_WAKE_ST_TIMERf_GET(r) ((((r).mii_buffer_control_0_phy6[0]) >> 11) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_CONFIG_WAKE_ST_TIMERf_SET(r,f) (r).mii_buffer_control_0_phy6[0]=(((r).mii_buffer_control_0_phy6[0] & ~((uint32_t)0x7 << 11)) | ((((uint32_t)f) & 0x7) << 11))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_WAIT_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy6[0]) >> 8) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_WAIT_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy6[0]=(((r).mii_buffer_control_0_phy6[0] & ~((uint32_t)0x7 << 8)) | ((((uint32_t)f) & 0x7) << 8))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_VARIABLE_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy6[0]) >> 3) & 0x1f)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_VARIABLE_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy6[0]=(((r).mii_buffer_control_0_phy6[0] & ~((uint32_t)0x1f << 3)) | ((((uint32_t)f) & 0x1f) << 3))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_VAR_LATENCY_ENf_GET(r) ((((r).mii_buffer_control_0_phy6[0]) >> 2) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_VAR_LATENCY_ENf_SET(r,f) (r).mii_buffer_control_0_phy6[0]=(((r).mii_buffer_control_0_phy6[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_AUTOGREEEN_ENABLEf_GET(r) (((r).mii_buffer_control_0_phy6[0]) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY6r_AUTOGREEEN_ENABLEf_SET(r,f) (r).mii_buffer_control_0_phy6[0]=(((r).mii_buffer_control_0_phy6[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_BUFFER_CONTROL_0_PHY6.
 *
 */
#define BCM54282_READ_MII_BUFFER_CONTROL_0_PHY6r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY6r,(_r._mii_buffer_control_0_phy6))
#define BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY6r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY6r,(_r._mii_buffer_control_0_phy6))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_BUFFER_CONTROL_0_PHY6r BCM54282_MII_BUFFER_CONTROL_0_PHY6r
#define MII_BUFFER_CONTROL_0_PHY6r_SIZE BCM54282_MII_BUFFER_CONTROL_0_PHY6r_SIZE
typedef BCM54282_MII_BUFFER_CONTROL_0_PHY6r_t MII_BUFFER_CONTROL_0_PHY6r_t;
#define MII_BUFFER_CONTROL_0_PHY6r_CLR BCM54282_MII_BUFFER_CONTROL_0_PHY6r_CLR
#define MII_BUFFER_CONTROL_0_PHY6r_SET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_SET
#define MII_BUFFER_CONTROL_0_PHY6r_GET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_GET
#define MII_BUFFER_CONTROL_0_PHY6r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET
#define MII_BUFFER_CONTROL_0_PHY6r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET
#define MII_BUFFER_CONTROL_0_PHY6r_CONFIG_WAKE_ST_TIMERf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_CONFIG_WAKE_ST_TIMERf_GET
#define MII_BUFFER_CONTROL_0_PHY6r_CONFIG_WAKE_ST_TIMERf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_CONFIG_WAKE_ST_TIMERf_SET
#define MII_BUFFER_CONTROL_0_PHY6r_WAIT_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_WAIT_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY6r_WAIT_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_WAIT_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY6r_VARIABLE_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_VARIABLE_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY6r_VARIABLE_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_VARIABLE_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY6r_VAR_LATENCY_ENf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_VAR_LATENCY_ENf_GET
#define MII_BUFFER_CONTROL_0_PHY6r_VAR_LATENCY_ENf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_VAR_LATENCY_ENf_SET
#define MII_BUFFER_CONTROL_0_PHY6r_AUTOGREEEN_ENABLEf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_AUTOGREEEN_ENABLEf_GET
#define MII_BUFFER_CONTROL_0_PHY6r_AUTOGREEEN_ENABLEf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY6r_AUTOGREEEN_ENABLEf_SET
#define READ_MII_BUFFER_CONTROL_0_PHY6r BCM54282_READ_MII_BUFFER_CONTROL_0_PHY6r
#define WRITE_MII_BUFFER_CONTROL_0_PHY6r BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY6r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_BUFFER_CONTROL_0_PHY6r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_BUFFER_CONTROL_0_PHY7
 * BLOCKS:   RDB
 * REGADDR:  0x080e
 * DESC:     MII_BUFFER_CONTROL_0_PHY7 Register (RDB_Register, offset 0x80E)
 * SIZE:     32
 * FIELDS:
 *     AUTOGREEEN_ENABLE Enable AutogrEEEn mode
 *     VAR_LATENCY_EN   Variable latency enable
 *     VARIABLE_IFG_LENGTH IFG used to flush the buffer in variable latency mode
 *     WAIT_IFG_LENGTH  Number of IDLE symbols required before asserting local LPI request
 *     CONFIG_WAKE_ST_TIMER Amount of time the data is buffered before it is transmitted on the MDI
 *     DISABLE_LOC_LPI_HALF_DUPLEX Prevent MII buffer from sending LOC LPI request when in half-duplex mode
 *
 ******************************************************************************/
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r (0x0000080e | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_SIZE 4

/*
 * This structure should be used to declare and program MII_BUFFER_CONTROL_0_PHY7.
 *
 */
typedef union BCM54282_MII_BUFFER_CONTROL_0_PHY7r_s {
	uint32_t v[1];
	uint32_t mii_buffer_control_0_phy7[1];
	uint32_t _mii_buffer_control_0_phy7;
} BCM54282_MII_BUFFER_CONTROL_0_PHY7r_t;

#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_CLR(r) (r).mii_buffer_control_0_phy7[0] = 0
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_SET(r,d) (r).mii_buffer_control_0_phy7[0] = d
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_GET(r) (r).mii_buffer_control_0_phy7[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET(r) ((((r).mii_buffer_control_0_phy7[0]) >> 15) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET(r,f) (r).mii_buffer_control_0_phy7[0]=(((r).mii_buffer_control_0_phy7[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_CONFIG_WAKE_ST_TIMERf_GET(r) ((((r).mii_buffer_control_0_phy7[0]) >> 11) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_CONFIG_WAKE_ST_TIMERf_SET(r,f) (r).mii_buffer_control_0_phy7[0]=(((r).mii_buffer_control_0_phy7[0] & ~((uint32_t)0x7 << 11)) | ((((uint32_t)f) & 0x7) << 11))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_WAIT_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy7[0]) >> 8) & 0x7)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_WAIT_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy7[0]=(((r).mii_buffer_control_0_phy7[0] & ~((uint32_t)0x7 << 8)) | ((((uint32_t)f) & 0x7) << 8))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_VARIABLE_IFG_LENGTHf_GET(r) ((((r).mii_buffer_control_0_phy7[0]) >> 3) & 0x1f)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_VARIABLE_IFG_LENGTHf_SET(r,f) (r).mii_buffer_control_0_phy7[0]=(((r).mii_buffer_control_0_phy7[0] & ~((uint32_t)0x1f << 3)) | ((((uint32_t)f) & 0x1f) << 3))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_VAR_LATENCY_ENf_GET(r) ((((r).mii_buffer_control_0_phy7[0]) >> 2) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_VAR_LATENCY_ENf_SET(r,f) (r).mii_buffer_control_0_phy7[0]=(((r).mii_buffer_control_0_phy7[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_AUTOGREEEN_ENABLEf_GET(r) (((r).mii_buffer_control_0_phy7[0]) & 0x1)
#define BCM54282_MII_BUFFER_CONTROL_0_PHY7r_AUTOGREEEN_ENABLEf_SET(r,f) (r).mii_buffer_control_0_phy7[0]=(((r).mii_buffer_control_0_phy7[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_BUFFER_CONTROL_0_PHY7.
 *
 */
#define BCM54282_READ_MII_BUFFER_CONTROL_0_PHY7r(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY7r,(_r._mii_buffer_control_0_phy7))
#define BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY7r(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_MII_BUFFER_CONTROL_0_PHY7r,(_r._mii_buffer_control_0_phy7))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_BUFFER_CONTROL_0_PHY7r BCM54282_MII_BUFFER_CONTROL_0_PHY7r
#define MII_BUFFER_CONTROL_0_PHY7r_SIZE BCM54282_MII_BUFFER_CONTROL_0_PHY7r_SIZE
typedef BCM54282_MII_BUFFER_CONTROL_0_PHY7r_t MII_BUFFER_CONTROL_0_PHY7r_t;
#define MII_BUFFER_CONTROL_0_PHY7r_CLR BCM54282_MII_BUFFER_CONTROL_0_PHY7r_CLR
#define MII_BUFFER_CONTROL_0_PHY7r_SET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_SET
#define MII_BUFFER_CONTROL_0_PHY7r_GET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_GET
#define MII_BUFFER_CONTROL_0_PHY7r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_DISABLE_LOC_LPI_HALF_DUPLEXf_GET
#define MII_BUFFER_CONTROL_0_PHY7r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_DISABLE_LOC_LPI_HALF_DUPLEXf_SET
#define MII_BUFFER_CONTROL_0_PHY7r_CONFIG_WAKE_ST_TIMERf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_CONFIG_WAKE_ST_TIMERf_GET
#define MII_BUFFER_CONTROL_0_PHY7r_CONFIG_WAKE_ST_TIMERf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_CONFIG_WAKE_ST_TIMERf_SET
#define MII_BUFFER_CONTROL_0_PHY7r_WAIT_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_WAIT_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY7r_WAIT_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_WAIT_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY7r_VARIABLE_IFG_LENGTHf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_VARIABLE_IFG_LENGTHf_GET
#define MII_BUFFER_CONTROL_0_PHY7r_VARIABLE_IFG_LENGTHf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_VARIABLE_IFG_LENGTHf_SET
#define MII_BUFFER_CONTROL_0_PHY7r_VAR_LATENCY_ENf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_VAR_LATENCY_ENf_GET
#define MII_BUFFER_CONTROL_0_PHY7r_VAR_LATENCY_ENf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_VAR_LATENCY_ENf_SET
#define MII_BUFFER_CONTROL_0_PHY7r_AUTOGREEEN_ENABLEf_GET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_AUTOGREEEN_ENABLEf_GET
#define MII_BUFFER_CONTROL_0_PHY7r_AUTOGREEEN_ENABLEf_SET BCM54282_MII_BUFFER_CONTROL_0_PHY7r_AUTOGREEEN_ENABLEf_SET
#define READ_MII_BUFFER_CONTROL_0_PHY7r BCM54282_READ_MII_BUFFER_CONTROL_0_PHY7r
#define WRITE_MII_BUFFER_CONTROL_0_PHY7r BCM54282_WRITE_MII_BUFFER_CONTROL_0_PHY7r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_BUFFER_CONTROL_0_PHY7r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  TOP_MISC_CFG
 * BLOCKS:   RDB
 * REGADDR:  0x0810
 * DESC:     TOP_MISC_CFG Register (RDB_Register, offset 0x810)
 * SIZE:     32
 * FIELDS:
 *     QSGMII_SEL       QSGMII Register select.
 *     QSGMII_PHYA      QSGMII PHY address.
 *
 ******************************************************************************/
#define BCM54282_TOP_MISC_CFGr (0x00000810 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_TOP_MISC_CFGr_SIZE 4

/*
 * This structure should be used to declare and program TOP_MISC_CFG.
 *
 */
typedef union BCM54282_TOP_MISC_CFGr_s {
	uint32_t v[1];
	uint32_t top_misc_cfg[1];
	uint32_t _top_misc_cfg;
} BCM54282_TOP_MISC_CFGr_t;

#define BCM54282_TOP_MISC_CFGr_CLR(r) (r).top_misc_cfg[0] = 0
#define BCM54282_TOP_MISC_CFGr_SET(r,d) (r).top_misc_cfg[0] = d
#define BCM54282_TOP_MISC_CFGr_GET(r) (r).top_misc_cfg[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_TOP_MISC_CFGr_QSGMII_PHYAf_GET(r) ((((r).top_misc_cfg[0]) >> 3) & 0x1)
#define BCM54282_TOP_MISC_CFGr_QSGMII_PHYAf_SET(r,f) (r).top_misc_cfg[0]=(((r).top_misc_cfg[0] & ~((uint32_t)0x1 << 3)) | ((((uint32_t)f) & 0x1) << 3))
#define BCM54282_TOP_MISC_CFGr_QSGMII_SELf_GET(r) ((((r).top_misc_cfg[0]) >> 2) & 0x1)
#define BCM54282_TOP_MISC_CFGr_QSGMII_SELf_SET(r,f) (r).top_misc_cfg[0]=(((r).top_misc_cfg[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))

/*
 * These macros can be used to access TOP_MISC_CFG.
 *
 */
#define BCM54282_READ_TOP_MISC_CFGr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_TOP_MISC_CFGr,(_r._top_misc_cfg))
#define BCM54282_WRITE_TOP_MISC_CFGr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_TOP_MISC_CFGr,(_r._top_misc_cfg))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define TOP_MISC_CFGr BCM54282_TOP_MISC_CFGr
#define TOP_MISC_CFGr_SIZE BCM54282_TOP_MISC_CFGr_SIZE
typedef BCM54282_TOP_MISC_CFGr_t TOP_MISC_CFGr_t;
#define TOP_MISC_CFGr_CLR BCM54282_TOP_MISC_CFGr_CLR
#define TOP_MISC_CFGr_SET BCM54282_TOP_MISC_CFGr_SET
#define TOP_MISC_CFGr_GET BCM54282_TOP_MISC_CFGr_GET
#define TOP_MISC_CFGr_QSGMII_PHYAf_GET BCM54282_TOP_MISC_CFGr_QSGMII_PHYAf_GET
#define TOP_MISC_CFGr_QSGMII_PHYAf_SET BCM54282_TOP_MISC_CFGr_QSGMII_PHYAf_SET
#define TOP_MISC_CFGr_QSGMII_SELf_GET BCM54282_TOP_MISC_CFGr_QSGMII_SELf_GET
#define TOP_MISC_CFGr_QSGMII_SELf_SET BCM54282_TOP_MISC_CFGr_QSGMII_SELf_SET
#define READ_TOP_MISC_CFGr BCM54282_READ_TOP_MISC_CFGr
#define WRITE_TOP_MISC_CFGr BCM54282_WRITE_TOP_MISC_CFGr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_TOP_MISC_CFGr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  TOP_MISC_GLOBAL_RESET
 * BLOCKS:   TOP_LEVEL_MII
 * REGADDR:  0x082b
 * DESC:     TOP_MISC_TOP_GLOBAL_RESET Register (RDB_Register, offset 0x82B)
 * SIZE:     32
 * FIELDS:
 *     MII_BUFFER_0_SOFT_RST Port 0 block in reset state.
 *     MII_BUFFER_1_SOFT_RST Port 1 block in reset state.
 *     MII_BUFFER_2_SOFT_RST Port 2 block in reset state.
 *     MII_BUFFER_3_SOFT_RST Port 3 block in reset state.
 *     MII_BUFFER_4_SOFT_RST Port 4 block in reset state.
 *     MII_BUFFER_5_SOFT_RST Port 5 block in reset state.
 *     MII_BUFFER_6_SOFT_RST Port 6 block in reset state.
 *     MII_BUFFER_7_SOFT_RST Port 7 block in reset state.
 *     RESERVED0        Reserved0.
 *     RESERVED1        Reserved1.
 *     RESET_1588       1588 Block reset.
 *     QSGMII_1_0_RESET QSGMII[0] and QSGMII[1] Block reset.
 *     QSGMII0_RESET    QSGMII[0] Block (Ports 0 to 3) reset.
 *     QSGMII1_RESET    QSGMII[1] Block (Ports 4 to 7) reset.
 *     RESERVED2        Reserved2.
 *     TOP_MII_REG_SOFT_RST Top Level MII register reset. Reset RDB_Register.
 *
 ******************************************************************************/
#define BCM54282_TOP_MISC_GLOBAL_RESETr (0x0000082b | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_TOP_MISC_GLOBAL_RESETr_SIZE 4

/*
 * This structure should be used to declare and program TOP_MISC_GLOBAL_RESET.
 *
 */
typedef union BCM54282_TOP_MISC_GLOBAL_RESETr_s {
	uint32_t v[1];
	uint32_t top_misc_global_reset[1];
	uint32_t _top_misc_global_reset;
} BCM54282_TOP_MISC_GLOBAL_RESETr_t;

#define BCM54282_TOP_MISC_GLOBAL_RESETr_CLR(r) (r).top_misc_global_reset[0] = 0
#define BCM54282_TOP_MISC_GLOBAL_RESETr_SET(r,d) (r).top_misc_global_reset[0] = d
#define BCM54282_TOP_MISC_GLOBAL_RESETr_GET(r) (r).top_misc_global_reset[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_TOP_MISC_GLOBAL_RESETr_TOP_MII_REG_SOFT_RSTf_GET(r) ((((r).top_misc_global_reset[0]) >> 15) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_TOP_MII_REG_SOFT_RSTf_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_RESERVED2f_GET(r) ((((r).top_misc_global_reset[0]) >> 14) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_RESERVED2f_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_QSGMII1_RESETf_GET(r) ((((r).top_misc_global_reset[0]) >> 13) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_QSGMII1_RESETf_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_QSGMII0_RESETf_GET(r) ((((r).top_misc_global_reset[0]) >> 12) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_QSGMII0_RESETf_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_QSGMII_1_0_RESETf_GET(r) ((((r).top_misc_global_reset[0]) >> 11) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_QSGMII_1_0_RESETf_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 11)) | ((((uint32_t)f) & 0x1) << 11))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_RESET_1588f_GET(r) ((((r).top_misc_global_reset[0]) >> 10) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_RESET_1588f_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_RESERVED1f_GET(r) ((((r).top_misc_global_reset[0]) >> 9) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_RESERVED1f_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_RESERVED0f_GET(r) ((((r).top_misc_global_reset[0]) >> 8) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_RESERVED0f_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_7_SOFT_RSTf_GET(r) ((((r).top_misc_global_reset[0]) >> 7) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_7_SOFT_RSTf_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 7)) | ((((uint32_t)f) & 0x1) << 7))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_6_SOFT_RSTf_GET(r) ((((r).top_misc_global_reset[0]) >> 6) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_6_SOFT_RSTf_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_5_SOFT_RSTf_GET(r) ((((r).top_misc_global_reset[0]) >> 5) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_5_SOFT_RSTf_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_4_SOFT_RSTf_GET(r) ((((r).top_misc_global_reset[0]) >> 4) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_4_SOFT_RSTf_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 4)) | ((((uint32_t)f) & 0x1) << 4))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_3_SOFT_RSTf_GET(r) ((((r).top_misc_global_reset[0]) >> 3) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_3_SOFT_RSTf_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 3)) | ((((uint32_t)f) & 0x1) << 3))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_2_SOFT_RSTf_GET(r) ((((r).top_misc_global_reset[0]) >> 2) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_2_SOFT_RSTf_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_1_SOFT_RSTf_GET(r) ((((r).top_misc_global_reset[0]) >> 1) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_1_SOFT_RSTf_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1 << 1)) | ((((uint32_t)f) & 0x1) << 1))
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_0_SOFT_RSTf_GET(r) (((r).top_misc_global_reset[0]) & 0x1)
#define BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_0_SOFT_RSTf_SET(r,f) (r).top_misc_global_reset[0]=(((r).top_misc_global_reset[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access TOP_MISC_GLOBAL_RESET.
 *
 */
#define BCM54282_READ_TOP_MISC_GLOBAL_RESETr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_TOP_MISC_GLOBAL_RESETr,(_r._top_misc_global_reset))
#define BCM54282_WRITE_TOP_MISC_GLOBAL_RESETr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_TOP_MISC_GLOBAL_RESETr,(_r._top_misc_global_reset))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define TOP_MISC_GLOBAL_RESETr BCM54282_TOP_MISC_GLOBAL_RESETr
#define TOP_MISC_GLOBAL_RESETr_SIZE BCM54282_TOP_MISC_GLOBAL_RESETr_SIZE
typedef BCM54282_TOP_MISC_GLOBAL_RESETr_t TOP_MISC_GLOBAL_RESETr_t;
#define TOP_MISC_GLOBAL_RESETr_CLR BCM54282_TOP_MISC_GLOBAL_RESETr_CLR
#define TOP_MISC_GLOBAL_RESETr_SET BCM54282_TOP_MISC_GLOBAL_RESETr_SET
#define TOP_MISC_GLOBAL_RESETr_GET BCM54282_TOP_MISC_GLOBAL_RESETr_GET
#define TOP_MISC_GLOBAL_RESETr_TOP_MII_REG_SOFT_RSTf_GET BCM54282_TOP_MISC_GLOBAL_RESETr_TOP_MII_REG_SOFT_RSTf_GET
#define TOP_MISC_GLOBAL_RESETr_TOP_MII_REG_SOFT_RSTf_SET BCM54282_TOP_MISC_GLOBAL_RESETr_TOP_MII_REG_SOFT_RSTf_SET
#define TOP_MISC_GLOBAL_RESETr_RESERVED2f_GET BCM54282_TOP_MISC_GLOBAL_RESETr_RESERVED2f_GET
#define TOP_MISC_GLOBAL_RESETr_RESERVED2f_SET BCM54282_TOP_MISC_GLOBAL_RESETr_RESERVED2f_SET
#define TOP_MISC_GLOBAL_RESETr_QSGMII1_RESETf_GET BCM54282_TOP_MISC_GLOBAL_RESETr_QSGMII1_RESETf_GET
#define TOP_MISC_GLOBAL_RESETr_QSGMII1_RESETf_SET BCM54282_TOP_MISC_GLOBAL_RESETr_QSGMII1_RESETf_SET
#define TOP_MISC_GLOBAL_RESETr_QSGMII0_RESETf_GET BCM54282_TOP_MISC_GLOBAL_RESETr_QSGMII0_RESETf_GET
#define TOP_MISC_GLOBAL_RESETr_QSGMII0_RESETf_SET BCM54282_TOP_MISC_GLOBAL_RESETr_QSGMII0_RESETf_SET
#define TOP_MISC_GLOBAL_RESETr_QSGMII_1_0_RESETf_GET BCM54282_TOP_MISC_GLOBAL_RESETr_QSGMII_1_0_RESETf_GET
#define TOP_MISC_GLOBAL_RESETr_QSGMII_1_0_RESETf_SET BCM54282_TOP_MISC_GLOBAL_RESETr_QSGMII_1_0_RESETf_SET
#define TOP_MISC_GLOBAL_RESETr_RESET_1588f_GET BCM54282_TOP_MISC_GLOBAL_RESETr_RESET_1588f_GET
#define TOP_MISC_GLOBAL_RESETr_RESET_1588f_SET BCM54282_TOP_MISC_GLOBAL_RESETr_RESET_1588f_SET
#define TOP_MISC_GLOBAL_RESETr_RESERVED1f_GET BCM54282_TOP_MISC_GLOBAL_RESETr_RESERVED1f_GET
#define TOP_MISC_GLOBAL_RESETr_RESERVED1f_SET BCM54282_TOP_MISC_GLOBAL_RESETr_RESERVED1f_SET
#define TOP_MISC_GLOBAL_RESETr_RESERVED0f_GET BCM54282_TOP_MISC_GLOBAL_RESETr_RESERVED0f_GET
#define TOP_MISC_GLOBAL_RESETr_RESERVED0f_SET BCM54282_TOP_MISC_GLOBAL_RESETr_RESERVED0f_SET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_7_SOFT_RSTf_GET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_7_SOFT_RSTf_GET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_7_SOFT_RSTf_SET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_7_SOFT_RSTf_SET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_6_SOFT_RSTf_GET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_6_SOFT_RSTf_GET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_6_SOFT_RSTf_SET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_6_SOFT_RSTf_SET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_5_SOFT_RSTf_GET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_5_SOFT_RSTf_GET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_5_SOFT_RSTf_SET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_5_SOFT_RSTf_SET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_4_SOFT_RSTf_GET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_4_SOFT_RSTf_GET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_4_SOFT_RSTf_SET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_4_SOFT_RSTf_SET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_3_SOFT_RSTf_GET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_3_SOFT_RSTf_GET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_3_SOFT_RSTf_SET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_3_SOFT_RSTf_SET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_2_SOFT_RSTf_GET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_2_SOFT_RSTf_GET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_2_SOFT_RSTf_SET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_2_SOFT_RSTf_SET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_1_SOFT_RSTf_GET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_1_SOFT_RSTf_GET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_1_SOFT_RSTf_SET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_1_SOFT_RSTf_SET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_0_SOFT_RSTf_GET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_0_SOFT_RSTf_GET
#define TOP_MISC_GLOBAL_RESETr_MII_BUFFER_0_SOFT_RSTf_SET BCM54282_TOP_MISC_GLOBAL_RESETr_MII_BUFFER_0_SOFT_RSTf_SET
#define READ_TOP_MISC_GLOBAL_RESETr BCM54282_READ_TOP_MISC_GLOBAL_RESETr
#define WRITE_TOP_MISC_GLOBAL_RESETr BCM54282_WRITE_TOP_MISC_GLOBAL_RESETr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_TOP_MISC_GLOBAL_RESETr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  VOLT_TEMP_MON_CTRL
 * BLOCKS:   RDB
 * REGADDR:  0x0831
 * DESC:     VOLTAGE_TEMPERATURE_MONITOR_CONTROL Register (RDB_Register, offset 0x831)
 * SIZE:     32
 * FIELDS:
 *     VTMON_PWRDN      Monitor power-down.
 *     VTMON_SEL        Monitor selection mode.
 *     VTMON_VOLT_MODE  Voltage supply monitor mode.
 *
 ******************************************************************************/
#define BCM54282_VOLT_TEMP_MON_CTRLr (0x00000831 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_VOLT_TEMP_MON_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program VOLT_TEMP_MON_CTRL.
 *
 */
typedef union BCM54282_VOLT_TEMP_MON_CTRLr_s {
	uint32_t v[1];
	uint32_t volt_temp_mon_ctrl[1];
	uint32_t _volt_temp_mon_ctrl;
} BCM54282_VOLT_TEMP_MON_CTRLr_t;

#define BCM54282_VOLT_TEMP_MON_CTRLr_CLR(r) (r).volt_temp_mon_ctrl[0] = 0
#define BCM54282_VOLT_TEMP_MON_CTRLr_SET(r,d) (r).volt_temp_mon_ctrl[0] = d
#define BCM54282_VOLT_TEMP_MON_CTRLr_GET(r) (r).volt_temp_mon_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_VOLT_TEMP_MON_CTRLr_VTMON_VOLT_MODEf_GET(r) ((((r).volt_temp_mon_ctrl[0]) >> 3) & 0x1)
#define BCM54282_VOLT_TEMP_MON_CTRLr_VTMON_VOLT_MODEf_SET(r,f) (r).volt_temp_mon_ctrl[0]=(((r).volt_temp_mon_ctrl[0] & ~((uint32_t)0x1 << 3)) | ((((uint32_t)f) & 0x1) << 3))
#define BCM54282_VOLT_TEMP_MON_CTRLr_VTMON_SELf_GET(r) ((((r).volt_temp_mon_ctrl[0]) >> 1) & 0x3)
#define BCM54282_VOLT_TEMP_MON_CTRLr_VTMON_SELf_SET(r,f) (r).volt_temp_mon_ctrl[0]=(((r).volt_temp_mon_ctrl[0] & ~((uint32_t)0x3 << 1)) | ((((uint32_t)f) & 0x3) << 1))
#define BCM54282_VOLT_TEMP_MON_CTRLr_VTMON_PWRDNf_GET(r) (((r).volt_temp_mon_ctrl[0]) & 0x1)
#define BCM54282_VOLT_TEMP_MON_CTRLr_VTMON_PWRDNf_SET(r,f) (r).volt_temp_mon_ctrl[0]=(((r).volt_temp_mon_ctrl[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access VOLT_TEMP_MON_CTRL.
 *
 */
#define BCM54282_READ_VOLT_TEMP_MON_CTRLr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_VOLT_TEMP_MON_CTRLr,(_r._volt_temp_mon_ctrl))
#define BCM54282_WRITE_VOLT_TEMP_MON_CTRLr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_VOLT_TEMP_MON_CTRLr,(_r._volt_temp_mon_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define VOLT_TEMP_MON_CTRLr BCM54282_VOLT_TEMP_MON_CTRLr
#define VOLT_TEMP_MON_CTRLr_SIZE BCM54282_VOLT_TEMP_MON_CTRLr_SIZE
typedef BCM54282_VOLT_TEMP_MON_CTRLr_t VOLT_TEMP_MON_CTRLr_t;
#define VOLT_TEMP_MON_CTRLr_CLR BCM54282_VOLT_TEMP_MON_CTRLr_CLR
#define VOLT_TEMP_MON_CTRLr_SET BCM54282_VOLT_TEMP_MON_CTRLr_SET
#define VOLT_TEMP_MON_CTRLr_GET BCM54282_VOLT_TEMP_MON_CTRLr_GET
#define VOLT_TEMP_MON_CTRLr_VTMON_VOLT_MODEf_GET BCM54282_VOLT_TEMP_MON_CTRLr_VTMON_VOLT_MODEf_GET
#define VOLT_TEMP_MON_CTRLr_VTMON_VOLT_MODEf_SET BCM54282_VOLT_TEMP_MON_CTRLr_VTMON_VOLT_MODEf_SET
#define VOLT_TEMP_MON_CTRLr_VTMON_SELf_GET BCM54282_VOLT_TEMP_MON_CTRLr_VTMON_SELf_GET
#define VOLT_TEMP_MON_CTRLr_VTMON_SELf_SET BCM54282_VOLT_TEMP_MON_CTRLr_VTMON_SELf_SET
#define VOLT_TEMP_MON_CTRLr_VTMON_PWRDNf_GET BCM54282_VOLT_TEMP_MON_CTRLr_VTMON_PWRDNf_GET
#define VOLT_TEMP_MON_CTRLr_VTMON_PWRDNf_SET BCM54282_VOLT_TEMP_MON_CTRLr_VTMON_PWRDNf_SET
#define READ_VOLT_TEMP_MON_CTRLr BCM54282_READ_VOLT_TEMP_MON_CTRLr
#define WRITE_VOLT_TEMP_MON_CTRLr BCM54282_WRITE_VOLT_TEMP_MON_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_VOLT_TEMP_MON_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  TEMP_MON_VALUE
 * BLOCKS:   RDB
 * REGADDR:  0x0832
 * DESC:     TEMPERATURE_MONITOR_VALUE Register (RDB_Register, offset 0x832)
 * SIZE:     32
 * FIELDS:
 *     DATA             Temperature Monitor Value.
 *     VTMON_PHY_PWRDN_STS PHY power down status when monitoring.
 *
 ******************************************************************************/
#define BCM54282_TEMP_MON_VALUEr (0x00000832 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_TEMP_MON_VALUEr_SIZE 4

/*
 * This structure should be used to declare and program TEMP_MON_VALUE.
 *
 */
typedef union BCM54282_TEMP_MON_VALUEr_s {
	uint32_t v[1];
	uint32_t temp_mon_value[1];
	uint32_t _temp_mon_value;
} BCM54282_TEMP_MON_VALUEr_t;

#define BCM54282_TEMP_MON_VALUEr_CLR(r) (r).temp_mon_value[0] = 0
#define BCM54282_TEMP_MON_VALUEr_SET(r,d) (r).temp_mon_value[0] = d
#define BCM54282_TEMP_MON_VALUEr_GET(r) (r).temp_mon_value[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_TEMP_MON_VALUEr_VTMON_PHY_PWRDN_STSf_GET(r) ((((r).temp_mon_value[0]) >> 15) & 0x1)
#define BCM54282_TEMP_MON_VALUEr_VTMON_PHY_PWRDN_STSf_SET(r,f) (r).temp_mon_value[0]=(((r).temp_mon_value[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_TEMP_MON_VALUEr_DATAf_GET(r) (((r).temp_mon_value[0]) & 0x3ff)
#define BCM54282_TEMP_MON_VALUEr_DATAf_SET(r,f) (r).temp_mon_value[0]=(((r).temp_mon_value[0] & ~((uint32_t)0x3ff)) | (((uint32_t)f) & 0x3ff))

/*
 * These macros can be used to access TEMP_MON_VALUE.
 *
 */
#define BCM54282_READ_TEMP_MON_VALUEr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_TEMP_MON_VALUEr,(_r._temp_mon_value))
#define BCM54282_WRITE_TEMP_MON_VALUEr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_TEMP_MON_VALUEr,(_r._temp_mon_value))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define TEMP_MON_VALUEr BCM54282_TEMP_MON_VALUEr
#define TEMP_MON_VALUEr_SIZE BCM54282_TEMP_MON_VALUEr_SIZE
typedef BCM54282_TEMP_MON_VALUEr_t TEMP_MON_VALUEr_t;
#define TEMP_MON_VALUEr_CLR BCM54282_TEMP_MON_VALUEr_CLR
#define TEMP_MON_VALUEr_SET BCM54282_TEMP_MON_VALUEr_SET
#define TEMP_MON_VALUEr_GET BCM54282_TEMP_MON_VALUEr_GET
#define TEMP_MON_VALUEr_VTMON_PHY_PWRDN_STSf_GET BCM54282_TEMP_MON_VALUEr_VTMON_PHY_PWRDN_STSf_GET
#define TEMP_MON_VALUEr_VTMON_PHY_PWRDN_STSf_SET BCM54282_TEMP_MON_VALUEr_VTMON_PHY_PWRDN_STSf_SET
#define TEMP_MON_VALUEr_DATAf_GET BCM54282_TEMP_MON_VALUEr_DATAf_GET
#define TEMP_MON_VALUEr_DATAf_SET BCM54282_TEMP_MON_VALUEr_DATAf_SET
#define READ_TEMP_MON_VALUEr BCM54282_READ_TEMP_MON_VALUEr
#define WRITE_TEMP_MON_VALUEr BCM54282_WRITE_TEMP_MON_VALUEr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_TEMP_MON_VALUEr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  TEMP_MON_HI_THRESHOLD
 * BLOCKS:   RDB
 * REGADDR:  0x0833
 * DESC:     TEMPERATURE_MONITOR_HIGH_THRESHOLD Register (RDB_Register, offset 0x833)
 * SIZE:     32
 * FIELDS:
 *     THRESH_HIGH      Temperature Monitor High Threshold.
 *
 ******************************************************************************/
#define BCM54282_TEMP_MON_HI_THRESHOLDr (0x00000833 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_TEMP_MON_HI_THRESHOLDr_SIZE 4

/*
 * This structure should be used to declare and program TEMP_MON_HI_THRESHOLD.
 *
 */
typedef union BCM54282_TEMP_MON_HI_THRESHOLDr_s {
	uint32_t v[1];
	uint32_t temp_mon_hi_threshold[1];
	uint32_t _temp_mon_hi_threshold;
} BCM54282_TEMP_MON_HI_THRESHOLDr_t;

#define BCM54282_TEMP_MON_HI_THRESHOLDr_CLR(r) (r).temp_mon_hi_threshold[0] = 0
#define BCM54282_TEMP_MON_HI_THRESHOLDr_SET(r,d) (r).temp_mon_hi_threshold[0] = d
#define BCM54282_TEMP_MON_HI_THRESHOLDr_GET(r) (r).temp_mon_hi_threshold[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_TEMP_MON_HI_THRESHOLDr_THRESH_HIGHf_GET(r) (((r).temp_mon_hi_threshold[0]) & 0x3ff)
#define BCM54282_TEMP_MON_HI_THRESHOLDr_THRESH_HIGHf_SET(r,f) (r).temp_mon_hi_threshold[0]=(((r).temp_mon_hi_threshold[0] & ~((uint32_t)0x3ff)) | (((uint32_t)f) & 0x3ff))

/*
 * These macros can be used to access TEMP_MON_HI_THRESHOLD.
 *
 */
#define BCM54282_READ_TEMP_MON_HI_THRESHOLDr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_TEMP_MON_HI_THRESHOLDr,(_r._temp_mon_hi_threshold))
#define BCM54282_WRITE_TEMP_MON_HI_THRESHOLDr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_TEMP_MON_HI_THRESHOLDr,(_r._temp_mon_hi_threshold))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define TEMP_MON_HI_THRESHOLDr BCM54282_TEMP_MON_HI_THRESHOLDr
#define TEMP_MON_HI_THRESHOLDr_SIZE BCM54282_TEMP_MON_HI_THRESHOLDr_SIZE
typedef BCM54282_TEMP_MON_HI_THRESHOLDr_t TEMP_MON_HI_THRESHOLDr_t;
#define TEMP_MON_HI_THRESHOLDr_CLR BCM54282_TEMP_MON_HI_THRESHOLDr_CLR
#define TEMP_MON_HI_THRESHOLDr_SET BCM54282_TEMP_MON_HI_THRESHOLDr_SET
#define TEMP_MON_HI_THRESHOLDr_GET BCM54282_TEMP_MON_HI_THRESHOLDr_GET
#define TEMP_MON_HI_THRESHOLDr_THRESH_HIGHf_GET BCM54282_TEMP_MON_HI_THRESHOLDr_THRESH_HIGHf_GET
#define TEMP_MON_HI_THRESHOLDr_THRESH_HIGHf_SET BCM54282_TEMP_MON_HI_THRESHOLDr_THRESH_HIGHf_SET
#define READ_TEMP_MON_HI_THRESHOLDr BCM54282_READ_TEMP_MON_HI_THRESHOLDr
#define WRITE_TEMP_MON_HI_THRESHOLDr BCM54282_WRITE_TEMP_MON_HI_THRESHOLDr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_TEMP_MON_HI_THRESHOLDr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  TEMP_MON_LO_THRESHOLD
 * BLOCKS:   RDB
 * REGADDR:  0x0834
 * DESC:     TEMPERATURE_MONITOR_LOW_THRESHOLD Register (RDB_Register, offset 0x834)
 * SIZE:     32
 * FIELDS:
 *     THRESH_LOW       Temperature Monitor Low Threshold.
 *
 ******************************************************************************/
#define BCM54282_TEMP_MON_LO_THRESHOLDr (0x00000834 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_TEMP_MON_LO_THRESHOLDr_SIZE 4

/*
 * This structure should be used to declare and program TEMP_MON_LO_THRESHOLD.
 *
 */
typedef union BCM54282_TEMP_MON_LO_THRESHOLDr_s {
	uint32_t v[1];
	uint32_t temp_mon_lo_threshold[1];
	uint32_t _temp_mon_lo_threshold;
} BCM54282_TEMP_MON_LO_THRESHOLDr_t;

#define BCM54282_TEMP_MON_LO_THRESHOLDr_CLR(r) (r).temp_mon_lo_threshold[0] = 0
#define BCM54282_TEMP_MON_LO_THRESHOLDr_SET(r,d) (r).temp_mon_lo_threshold[0] = d
#define BCM54282_TEMP_MON_LO_THRESHOLDr_GET(r) (r).temp_mon_lo_threshold[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_TEMP_MON_LO_THRESHOLDr_THRESH_LOWf_GET(r) (((r).temp_mon_lo_threshold[0]) & 0x3ff)
#define BCM54282_TEMP_MON_LO_THRESHOLDr_THRESH_LOWf_SET(r,f) (r).temp_mon_lo_threshold[0]=(((r).temp_mon_lo_threshold[0] & ~((uint32_t)0x3ff)) | (((uint32_t)f) & 0x3ff))

/*
 * These macros can be used to access TEMP_MON_LO_THRESHOLD.
 *
 */
#define BCM54282_READ_TEMP_MON_LO_THRESHOLDr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_TEMP_MON_LO_THRESHOLDr,(_r._temp_mon_lo_threshold))
#define BCM54282_WRITE_TEMP_MON_LO_THRESHOLDr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_TEMP_MON_LO_THRESHOLDr,(_r._temp_mon_lo_threshold))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define TEMP_MON_LO_THRESHOLDr BCM54282_TEMP_MON_LO_THRESHOLDr
#define TEMP_MON_LO_THRESHOLDr_SIZE BCM54282_TEMP_MON_LO_THRESHOLDr_SIZE
typedef BCM54282_TEMP_MON_LO_THRESHOLDr_t TEMP_MON_LO_THRESHOLDr_t;
#define TEMP_MON_LO_THRESHOLDr_CLR BCM54282_TEMP_MON_LO_THRESHOLDr_CLR
#define TEMP_MON_LO_THRESHOLDr_SET BCM54282_TEMP_MON_LO_THRESHOLDr_SET
#define TEMP_MON_LO_THRESHOLDr_GET BCM54282_TEMP_MON_LO_THRESHOLDr_GET
#define TEMP_MON_LO_THRESHOLDr_THRESH_LOWf_GET BCM54282_TEMP_MON_LO_THRESHOLDr_THRESH_LOWf_GET
#define TEMP_MON_LO_THRESHOLDr_THRESH_LOWf_SET BCM54282_TEMP_MON_LO_THRESHOLDr_THRESH_LOWf_SET
#define READ_TEMP_MON_LO_THRESHOLDr BCM54282_READ_TEMP_MON_LO_THRESHOLDr
#define WRITE_TEMP_MON_LO_THRESHOLDr BCM54282_WRITE_TEMP_MON_LO_THRESHOLDr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_TEMP_MON_LO_THRESHOLDr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  VOLT_MON_1V_VALUE
 * BLOCKS:   RDB
 * REGADDR:  0x0835
 * DESC:     VOLTAGE_MONITOR_1V_VALUE Register (RDB_Register, offset 0x835)
 * SIZE:     32
 * FIELDS:
 *     DATA             1.0V Voltage Monitor Data.
 *
 ******************************************************************************/
#define BCM54282_VOLT_MON_1V_VALUEr (0x00000835 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_VOLT_MON_1V_VALUEr_SIZE 4

/*
 * This structure should be used to declare and program VOLT_MON_1V_VALUE.
 *
 */
typedef union BCM54282_VOLT_MON_1V_VALUEr_s {
	uint32_t v[1];
	uint32_t volt_mon_1v_value[1];
	uint32_t _volt_mon_1v_value;
} BCM54282_VOLT_MON_1V_VALUEr_t;

#define BCM54282_VOLT_MON_1V_VALUEr_CLR(r) (r).volt_mon_1v_value[0] = 0
#define BCM54282_VOLT_MON_1V_VALUEr_SET(r,d) (r).volt_mon_1v_value[0] = d
#define BCM54282_VOLT_MON_1V_VALUEr_GET(r) (r).volt_mon_1v_value[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_VOLT_MON_1V_VALUEr_DATAf_GET(r) (((r).volt_mon_1v_value[0]) & 0x7ff)
#define BCM54282_VOLT_MON_1V_VALUEr_DATAf_SET(r,f) (r).volt_mon_1v_value[0]=(((r).volt_mon_1v_value[0] & ~((uint32_t)0x7ff)) | (((uint32_t)f) & 0x7ff))

/*
 * These macros can be used to access VOLT_MON_1V_VALUE.
 *
 */
#define BCM54282_READ_VOLT_MON_1V_VALUEr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_VOLT_MON_1V_VALUEr,(_r._volt_mon_1v_value))
#define BCM54282_WRITE_VOLT_MON_1V_VALUEr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_VOLT_MON_1V_VALUEr,(_r._volt_mon_1v_value))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define VOLT_MON_1V_VALUEr BCM54282_VOLT_MON_1V_VALUEr
#define VOLT_MON_1V_VALUEr_SIZE BCM54282_VOLT_MON_1V_VALUEr_SIZE
typedef BCM54282_VOLT_MON_1V_VALUEr_t VOLT_MON_1V_VALUEr_t;
#define VOLT_MON_1V_VALUEr_CLR BCM54282_VOLT_MON_1V_VALUEr_CLR
#define VOLT_MON_1V_VALUEr_SET BCM54282_VOLT_MON_1V_VALUEr_SET
#define VOLT_MON_1V_VALUEr_GET BCM54282_VOLT_MON_1V_VALUEr_GET
#define VOLT_MON_1V_VALUEr_DATAf_GET BCM54282_VOLT_MON_1V_VALUEr_DATAf_GET
#define VOLT_MON_1V_VALUEr_DATAf_SET BCM54282_VOLT_MON_1V_VALUEr_DATAf_SET
#define READ_VOLT_MON_1V_VALUEr BCM54282_READ_VOLT_MON_1V_VALUEr
#define WRITE_VOLT_MON_1V_VALUEr BCM54282_WRITE_VOLT_MON_1V_VALUEr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_VOLT_MON_1V_VALUEr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  VOLT_MON_1P0V_HI_THRESHOLD
 * BLOCKS:   RDB
 * REGADDR:  0x0836
 * DESC:     VOLTAGE_MONITOR_1P0V_HIGH_THRESHOLD Register (RDB_Register, offset 0x836)
 * SIZE:     32
 * FIELDS:
 *     THRESH_HIGH      1.0V Voltage Monitor High Threshold.
 *
 ******************************************************************************/
#define BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr (0x00000836 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_SIZE 4

/*
 * This structure should be used to declare and program VOLT_MON_1P0V_HI_THRESHOLD.
 *
 */
typedef union BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_s {
	uint32_t v[1];
	uint32_t volt_mon_1p0v_hi_threshold[1];
	uint32_t _volt_mon_1p0v_hi_threshold;
} BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_t;

#define BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_CLR(r) (r).volt_mon_1p0v_hi_threshold[0] = 0
#define BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_SET(r,d) (r).volt_mon_1p0v_hi_threshold[0] = d
#define BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_GET(r) (r).volt_mon_1p0v_hi_threshold[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_THRESH_HIGHf_GET(r) (((r).volt_mon_1p0v_hi_threshold[0]) & 0x7ff)
#define BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_THRESH_HIGHf_SET(r,f) (r).volt_mon_1p0v_hi_threshold[0]=(((r).volt_mon_1p0v_hi_threshold[0] & ~((uint32_t)0x7ff)) | (((uint32_t)f) & 0x7ff))

/*
 * These macros can be used to access VOLT_MON_1P0V_HI_THRESHOLD.
 *
 */
#define BCM54282_READ_VOLT_MON_1P0V_HI_THRESHOLDr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr,(_r._volt_mon_1p0v_hi_threshold))
#define BCM54282_WRITE_VOLT_MON_1P0V_HI_THRESHOLDr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr,(_r._volt_mon_1p0v_hi_threshold))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define VOLT_MON_1P0V_HI_THRESHOLDr BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr
#define VOLT_MON_1P0V_HI_THRESHOLDr_SIZE BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_SIZE
typedef BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_t VOLT_MON_1P0V_HI_THRESHOLDr_t;
#define VOLT_MON_1P0V_HI_THRESHOLDr_CLR BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_CLR
#define VOLT_MON_1P0V_HI_THRESHOLDr_SET BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_SET
#define VOLT_MON_1P0V_HI_THRESHOLDr_GET BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_GET
#define VOLT_MON_1P0V_HI_THRESHOLDr_THRESH_HIGHf_GET BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_THRESH_HIGHf_GET
#define VOLT_MON_1P0V_HI_THRESHOLDr_THRESH_HIGHf_SET BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr_THRESH_HIGHf_SET
#define READ_VOLT_MON_1P0V_HI_THRESHOLDr BCM54282_READ_VOLT_MON_1P0V_HI_THRESHOLDr
#define WRITE_VOLT_MON_1P0V_HI_THRESHOLDr BCM54282_WRITE_VOLT_MON_1P0V_HI_THRESHOLDr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_VOLT_MON_1P0V_HI_THRESHOLDr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  VOLT_MON_1P0V_LO_THRESHOLD
 * BLOCKS:   RDB
 * REGADDR:  0x0837
 * DESC:     VOLTAGE_MONITOR_1P0V_LOW_THRESHOLD Register (RDB_Register, offset 0x837)
 * SIZE:     32
 * FIELDS:
 *     THRESH_LOW       1.0V Voltage Monitor Low Threshold.
 *
 ******************************************************************************/
#define BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr (0x00000837 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_SIZE 4

/*
 * This structure should be used to declare and program VOLT_MON_1P0V_LO_THRESHOLD.
 *
 */
typedef union BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_s {
	uint32_t v[1];
	uint32_t volt_mon_1p0v_lo_threshold[1];
	uint32_t _volt_mon_1p0v_lo_threshold;
} BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_t;

#define BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_CLR(r) (r).volt_mon_1p0v_lo_threshold[0] = 0
#define BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_SET(r,d) (r).volt_mon_1p0v_lo_threshold[0] = d
#define BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_GET(r) (r).volt_mon_1p0v_lo_threshold[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_THRESH_LOWf_GET(r) (((r).volt_mon_1p0v_lo_threshold[0]) & 0x7ff)
#define BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_THRESH_LOWf_SET(r,f) (r).volt_mon_1p0v_lo_threshold[0]=(((r).volt_mon_1p0v_lo_threshold[0] & ~((uint32_t)0x7ff)) | (((uint32_t)f) & 0x7ff))

/*
 * These macros can be used to access VOLT_MON_1P0V_LO_THRESHOLD.
 *
 */
#define BCM54282_READ_VOLT_MON_1P0V_LO_THRESHOLDr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr,(_r._volt_mon_1p0v_lo_threshold))
#define BCM54282_WRITE_VOLT_MON_1P0V_LO_THRESHOLDr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr,(_r._volt_mon_1p0v_lo_threshold))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define VOLT_MON_1P0V_LO_THRESHOLDr BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr
#define VOLT_MON_1P0V_LO_THRESHOLDr_SIZE BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_SIZE
typedef BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_t VOLT_MON_1P0V_LO_THRESHOLDr_t;
#define VOLT_MON_1P0V_LO_THRESHOLDr_CLR BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_CLR
#define VOLT_MON_1P0V_LO_THRESHOLDr_SET BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_SET
#define VOLT_MON_1P0V_LO_THRESHOLDr_GET BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_GET
#define VOLT_MON_1P0V_LO_THRESHOLDr_THRESH_LOWf_GET BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_THRESH_LOWf_GET
#define VOLT_MON_1P0V_LO_THRESHOLDr_THRESH_LOWf_SET BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr_THRESH_LOWf_SET
#define READ_VOLT_MON_1P0V_LO_THRESHOLDr BCM54282_READ_VOLT_MON_1P0V_LO_THRESHOLDr
#define WRITE_VOLT_MON_1P0V_LO_THRESHOLDr BCM54282_WRITE_VOLT_MON_1P0V_LO_THRESHOLDr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_VOLT_MON_1P0V_LO_THRESHOLDr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  VOLT_MON_3P3V_2P5V_VALUE
 * BLOCKS:   RDB
 * REGADDR:  0x0838
 * DESC:     VOLTAGE_MONITOR_3P3V_2P5V_VALUE Register (RDB_Register, offset 0x838)
 * SIZE:     32
 * FIELDS:
 *     DATA             3.3V Voltage Monitor Data.
 *
 ******************************************************************************/
#define BCM54282_VOLT_MON_3P3V_2P5V_VALUEr (0x00000838 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_SIZE 4

/*
 * This structure should be used to declare and program VOLT_MON_3P3V_2P5V_VALUE.
 *
 */
typedef union BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_s {
	uint32_t v[1];
	uint32_t volt_mon_3p3v_2p5v_value[1];
	uint32_t _volt_mon_3p3v_2p5v_value;
} BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_t;

#define BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_CLR(r) (r).volt_mon_3p3v_2p5v_value[0] = 0
#define BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_SET(r,d) (r).volt_mon_3p3v_2p5v_value[0] = d
#define BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_GET(r) (r).volt_mon_3p3v_2p5v_value[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_DATAf_GET(r) (((r).volt_mon_3p3v_2p5v_value[0]) & 0x7ff)
#define BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_DATAf_SET(r,f) (r).volt_mon_3p3v_2p5v_value[0]=(((r).volt_mon_3p3v_2p5v_value[0] & ~((uint32_t)0x7ff)) | (((uint32_t)f) & 0x7ff))

/*
 * These macros can be used to access VOLT_MON_3P3V_2P5V_VALUE.
 *
 */
#define BCM54282_READ_VOLT_MON_3P3V_2P5V_VALUEr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_VOLT_MON_3P3V_2P5V_VALUEr,(_r._volt_mon_3p3v_2p5v_value))
#define BCM54282_WRITE_VOLT_MON_3P3V_2P5V_VALUEr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_VOLT_MON_3P3V_2P5V_VALUEr,(_r._volt_mon_3p3v_2p5v_value))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define VOLT_MON_3P3V_2P5V_VALUEr BCM54282_VOLT_MON_3P3V_2P5V_VALUEr
#define VOLT_MON_3P3V_2P5V_VALUEr_SIZE BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_SIZE
typedef BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_t VOLT_MON_3P3V_2P5V_VALUEr_t;
#define VOLT_MON_3P3V_2P5V_VALUEr_CLR BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_CLR
#define VOLT_MON_3P3V_2P5V_VALUEr_SET BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_SET
#define VOLT_MON_3P3V_2P5V_VALUEr_GET BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_GET
#define VOLT_MON_3P3V_2P5V_VALUEr_DATAf_GET BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_DATAf_GET
#define VOLT_MON_3P3V_2P5V_VALUEr_DATAf_SET BCM54282_VOLT_MON_3P3V_2P5V_VALUEr_DATAf_SET
#define READ_VOLT_MON_3P3V_2P5V_VALUEr BCM54282_READ_VOLT_MON_3P3V_2P5V_VALUEr
#define WRITE_VOLT_MON_3P3V_2P5V_VALUEr BCM54282_WRITE_VOLT_MON_3P3V_2P5V_VALUEr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_VOLT_MON_3P3V_2P5V_VALUEr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  VOLT_MON_3P3V_2P5V_HI_THRESHOLD
 * BLOCKS:   RDB
 * REGADDR:  0x0839
 * DESC:     VOLTAGE_MONITOR_3P3V_2P5V_HIGH_THRESHOLD Register (RDB_Register, offset 0x839)
 * SIZE:     32
 * FIELDS:
 *     THRESH_HIGH      3.3V/2.5V Voltage Monitor High Threshold.
 *
 ******************************************************************************/
#define BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr (0x00000839 | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_SIZE 4

/*
 * This structure should be used to declare and program VOLT_MON_3P3V_2P5V_HI_THRESHOLD.
 *
 */
typedef union BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_s {
	uint32_t v[1];
	uint32_t volt_mon_3p3v_2p5v_hi_threshold[1];
	uint32_t _volt_mon_3p3v_2p5v_hi_threshold;
} BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_t;

#define BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_CLR(r) (r).volt_mon_3p3v_2p5v_hi_threshold[0] = 0
#define BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_SET(r,d) (r).volt_mon_3p3v_2p5v_hi_threshold[0] = d
#define BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_GET(r) (r).volt_mon_3p3v_2p5v_hi_threshold[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_THRESH_HIGHf_GET(r) (((r).volt_mon_3p3v_2p5v_hi_threshold[0]) & 0x7ff)
#define BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_THRESH_HIGHf_SET(r,f) (r).volt_mon_3p3v_2p5v_hi_threshold[0]=(((r).volt_mon_3p3v_2p5v_hi_threshold[0] & ~((uint32_t)0x7ff)) | (((uint32_t)f) & 0x7ff))

/*
 * These macros can be used to access VOLT_MON_3P3V_2P5V_HI_THRESHOLD.
 *
 */
#define BCM54282_READ_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr,(_r._volt_mon_3p3v_2p5v_hi_threshold))
#define BCM54282_WRITE_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr,(_r._volt_mon_3p3v_2p5v_hi_threshold))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define VOLT_MON_3P3V_2P5V_HI_THRESHOLDr BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr
#define VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_SIZE BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_SIZE
typedef BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_t VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_t;
#define VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_CLR BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_CLR
#define VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_SET BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_SET
#define VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_GET BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_GET
#define VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_THRESH_HIGHf_GET BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_THRESH_HIGHf_GET
#define VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_THRESH_HIGHf_SET BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr_THRESH_HIGHf_SET
#define READ_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr BCM54282_READ_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr
#define WRITE_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr BCM54282_WRITE_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_VOLT_MON_3P3V_2P5V_HI_THRESHOLDr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  VOLT_MON_3P3V_2P5V_LO_THRESHOLD
 * BLOCKS:   RDB
 * REGADDR:  0x083a
 * DESC:     VOLTAGE_MONITOR_3P3V_2P5V_LOW_THRESHOLD Register (RDB_Register, offset 0x83A)
 * SIZE:     32
 * FIELDS:
 *     THRESH_LOW       3.3V/2.5V Voltage Monitor Low Threshold.
 *
 ******************************************************************************/
#define BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr (0x0000083a | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_SIZE 4

/*
 * This structure should be used to declare and program VOLT_MON_3P3V_2P5V_LO_THRESHOLD.
 *
 */
typedef union BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_s {
	uint32_t v[1];
	uint32_t volt_mon_3p3v_2p5v_lo_threshold[1];
	uint32_t _volt_mon_3p3v_2p5v_lo_threshold;
} BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_t;

#define BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_CLR(r) (r).volt_mon_3p3v_2p5v_lo_threshold[0] = 0
#define BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_SET(r,d) (r).volt_mon_3p3v_2p5v_lo_threshold[0] = d
#define BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_GET(r) (r).volt_mon_3p3v_2p5v_lo_threshold[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_THRESH_LOWf_GET(r) (((r).volt_mon_3p3v_2p5v_lo_threshold[0]) & 0x7ff)
#define BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_THRESH_LOWf_SET(r,f) (r).volt_mon_3p3v_2p5v_lo_threshold[0]=(((r).volt_mon_3p3v_2p5v_lo_threshold[0] & ~((uint32_t)0x7ff)) | (((uint32_t)f) & 0x7ff))

/*
 * These macros can be used to access VOLT_MON_3P3V_2P5V_LO_THRESHOLD.
 *
 */
#define BCM54282_READ_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr,(_r._volt_mon_3p3v_2p5v_lo_threshold))
#define BCM54282_WRITE_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr,(_r._volt_mon_3p3v_2p5v_lo_threshold))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define VOLT_MON_3P3V_2P5V_LO_THRESHOLDr BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr
#define VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_SIZE BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_SIZE
typedef BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_t VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_t;
#define VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_CLR BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_CLR
#define VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_SET BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_SET
#define VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_GET BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_GET
#define VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_THRESH_LOWf_GET BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_THRESH_LOWf_GET
#define VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_THRESH_LOWf_SET BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr_THRESH_LOWf_SET
#define READ_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr BCM54282_READ_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr
#define WRITE_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr BCM54282_WRITE_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_VOLT_MON_3P3V_2P5V_LO_THRESHOLDr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  VOLT_TEMP_MON_INTR
 * BLOCKS:   RDB
 * REGADDR:  0x083b
 * DESC:     VOLTAGE_TEMPERATURE_MONITOR_INTERRUPT Register (RDB_Register, offset 0x83B)
 * SIZE:     32
 * FIELDS:
 *     TEMP_INTR        Temperature monitor interrupt.
 *     V1P0_INTR        Voltage supply 1.0V monitor interrupt.
 *     V3P3_2P5_INTR    Voltage supply 3.3V/2.5V monitor interrupt.
 *     TEMP_INTR_MASK   Temperature monitor interrupt mask.
 *     V1P0_INTR_MASK   Voltage supply 1.0V monitor interrupt mask.
 *     V3P3_2P5_INTR_MASK Voltage supply 3.3V/2.5V monitor interrupt mask.
 *
 ******************************************************************************/
#define BCM54282_VOLT_TEMP_MON_INTRr (0x0000083b | PHY_REG_ACC_BRCM_RDB)

#define BCM54282_VOLT_TEMP_MON_INTRr_SIZE 4

/*
 * This structure should be used to declare and program VOLT_TEMP_MON_INTR.
 *
 */
typedef union BCM54282_VOLT_TEMP_MON_INTRr_s {
	uint32_t v[1];
	uint32_t volt_temp_mon_intr[1];
	uint32_t _volt_temp_mon_intr;
} BCM54282_VOLT_TEMP_MON_INTRr_t;

#define BCM54282_VOLT_TEMP_MON_INTRr_CLR(r) (r).volt_temp_mon_intr[0] = 0
#define BCM54282_VOLT_TEMP_MON_INTRr_SET(r,d) (r).volt_temp_mon_intr[0] = d
#define BCM54282_VOLT_TEMP_MON_INTRr_GET(r) (r).volt_temp_mon_intr[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_VOLT_TEMP_MON_INTRr_V3P3_2P5_INTR_MASKf_GET(r) ((((r).volt_temp_mon_intr[0]) >> 10) & 0x1)
#define BCM54282_VOLT_TEMP_MON_INTRr_V3P3_2P5_INTR_MASKf_SET(r,f) (r).volt_temp_mon_intr[0]=(((r).volt_temp_mon_intr[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))
#define BCM54282_VOLT_TEMP_MON_INTRr_V1P0_INTR_MASKf_GET(r) ((((r).volt_temp_mon_intr[0]) >> 9) & 0x1)
#define BCM54282_VOLT_TEMP_MON_INTRr_V1P0_INTR_MASKf_SET(r,f) (r).volt_temp_mon_intr[0]=(((r).volt_temp_mon_intr[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
#define BCM54282_VOLT_TEMP_MON_INTRr_TEMP_INTR_MASKf_GET(r) ((((r).volt_temp_mon_intr[0]) >> 8) & 0x1)
#define BCM54282_VOLT_TEMP_MON_INTRr_TEMP_INTR_MASKf_SET(r,f) (r).volt_temp_mon_intr[0]=(((r).volt_temp_mon_intr[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))
#define BCM54282_VOLT_TEMP_MON_INTRr_V3P3_2P5_INTRf_GET(r) ((((r).volt_temp_mon_intr[0]) >> 2) & 0x1)
#define BCM54282_VOLT_TEMP_MON_INTRr_V3P3_2P5_INTRf_SET(r,f) (r).volt_temp_mon_intr[0]=(((r).volt_temp_mon_intr[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_VOLT_TEMP_MON_INTRr_V1P0_INTRf_GET(r) ((((r).volt_temp_mon_intr[0]) >> 1) & 0x1)
#define BCM54282_VOLT_TEMP_MON_INTRr_V1P0_INTRf_SET(r,f) (r).volt_temp_mon_intr[0]=(((r).volt_temp_mon_intr[0] & ~((uint32_t)0x1 << 1)) | ((((uint32_t)f) & 0x1) << 1))
#define BCM54282_VOLT_TEMP_MON_INTRr_TEMP_INTRf_GET(r) (((r).volt_temp_mon_intr[0]) & 0x1)
#define BCM54282_VOLT_TEMP_MON_INTRr_TEMP_INTRf_SET(r,f) (r).volt_temp_mon_intr[0]=(((r).volt_temp_mon_intr[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access VOLT_TEMP_MON_INTR.
 *
 */
#define BCM54282_READ_VOLT_TEMP_MON_INTRr(_pc,_r) phy_brcm_rdb_read(_pc,BCM54282_VOLT_TEMP_MON_INTRr,(_r._volt_temp_mon_intr))
#define BCM54282_WRITE_VOLT_TEMP_MON_INTRr(_pc,_r) phy_brcm_rdb_write(_pc,BCM54282_VOLT_TEMP_MON_INTRr,(_r._volt_temp_mon_intr))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define VOLT_TEMP_MON_INTRr BCM54282_VOLT_TEMP_MON_INTRr
#define VOLT_TEMP_MON_INTRr_SIZE BCM54282_VOLT_TEMP_MON_INTRr_SIZE
typedef BCM54282_VOLT_TEMP_MON_INTRr_t VOLT_TEMP_MON_INTRr_t;
#define VOLT_TEMP_MON_INTRr_CLR BCM54282_VOLT_TEMP_MON_INTRr_CLR
#define VOLT_TEMP_MON_INTRr_SET BCM54282_VOLT_TEMP_MON_INTRr_SET
#define VOLT_TEMP_MON_INTRr_GET BCM54282_VOLT_TEMP_MON_INTRr_GET
#define VOLT_TEMP_MON_INTRr_V3P3_2P5_INTR_MASKf_GET BCM54282_VOLT_TEMP_MON_INTRr_V3P3_2P5_INTR_MASKf_GET
#define VOLT_TEMP_MON_INTRr_V3P3_2P5_INTR_MASKf_SET BCM54282_VOLT_TEMP_MON_INTRr_V3P3_2P5_INTR_MASKf_SET
#define VOLT_TEMP_MON_INTRr_V1P0_INTR_MASKf_GET BCM54282_VOLT_TEMP_MON_INTRr_V1P0_INTR_MASKf_GET
#define VOLT_TEMP_MON_INTRr_V1P0_INTR_MASKf_SET BCM54282_VOLT_TEMP_MON_INTRr_V1P0_INTR_MASKf_SET
#define VOLT_TEMP_MON_INTRr_TEMP_INTR_MASKf_GET BCM54282_VOLT_TEMP_MON_INTRr_TEMP_INTR_MASKf_GET
#define VOLT_TEMP_MON_INTRr_TEMP_INTR_MASKf_SET BCM54282_VOLT_TEMP_MON_INTRr_TEMP_INTR_MASKf_SET
#define VOLT_TEMP_MON_INTRr_V3P3_2P5_INTRf_GET BCM54282_VOLT_TEMP_MON_INTRr_V3P3_2P5_INTRf_GET
#define VOLT_TEMP_MON_INTRr_V3P3_2P5_INTRf_SET BCM54282_VOLT_TEMP_MON_INTRr_V3P3_2P5_INTRf_SET
#define VOLT_TEMP_MON_INTRr_V1P0_INTRf_GET BCM54282_VOLT_TEMP_MON_INTRr_V1P0_INTRf_GET
#define VOLT_TEMP_MON_INTRr_V1P0_INTRf_SET BCM54282_VOLT_TEMP_MON_INTRr_V1P0_INTRf_SET
#define VOLT_TEMP_MON_INTRr_TEMP_INTRf_GET BCM54282_VOLT_TEMP_MON_INTRr_TEMP_INTRf_GET
#define VOLT_TEMP_MON_INTRr_TEMP_INTRf_SET BCM54282_VOLT_TEMP_MON_INTRr_TEMP_INTRf_SET
#define READ_VOLT_TEMP_MON_INTRr BCM54282_READ_VOLT_TEMP_MON_INTRr
#define WRITE_VOLT_TEMP_MON_INTRr BCM54282_WRITE_VOLT_TEMP_MON_INTRr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_VOLT_TEMP_MON_INTRr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  QSGMII_1000X_CONTROL_3
 * BLOCKS:   QSGMII
 * REGADDR:  0x8302
 * DESC:     QSGMII_1000X_CONTROL_3 Register (AER_Register, offset 0x8302)
 * SIZE:     32
 * FIELDS:
 *     FIFO_ELASTICITY_TX_RX 
 *     FREQ_LOCK_ELASTICITY_RX Receive Frequency lock elasticity
 *     DISABLE_TX_CRC   Disable generating CRS from transmitting in half-duplex mode
 *
 ******************************************************************************/
#define BCM54282_QSGMII_1000X_CONTROL_3r (0x00008302 | PHY_REG_ACC_AER_IBLK)

#define BCM54282_QSGMII_1000X_CONTROL_3r_SIZE 4

/*
 * This structure should be used to declare and program QSGMII_1000X_CONTROL_3.
 *
 */
typedef union BCM54282_QSGMII_1000X_CONTROL_3r_s {
	uint32_t v[1];
	uint32_t qsgmii_1000x_control_3[1];
	uint32_t _qsgmii_1000x_control_3;
} BCM54282_QSGMII_1000X_CONTROL_3r_t;

#define BCM54282_QSGMII_1000X_CONTROL_3r_CLR(r) (r).qsgmii_1000x_control_3[0] = 0
#define BCM54282_QSGMII_1000X_CONTROL_3r_SET(r,d) (r).qsgmii_1000x_control_3[0] = d
#define BCM54282_QSGMII_1000X_CONTROL_3r_GET(r) (r).qsgmii_1000x_control_3[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_QSGMII_1000X_CONTROL_3r_DISABLE_TX_CRCf_GET(r) ((((r).qsgmii_1000x_control_3[0]) >> 13) & 0x1)
#define BCM54282_QSGMII_1000X_CONTROL_3r_DISABLE_TX_CRCf_SET(r,f) (r).qsgmii_1000x_control_3[0]=(((r).qsgmii_1000x_control_3[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_QSGMII_1000X_CONTROL_3r_FREQ_LOCK_ELASTICITY_RXf_GET(r) ((((r).qsgmii_1000x_control_3[0]) >> 5) & 0x1)
#define BCM54282_QSGMII_1000X_CONTROL_3r_FREQ_LOCK_ELASTICITY_RXf_SET(r,f) (r).qsgmii_1000x_control_3[0]=(((r).qsgmii_1000x_control_3[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))
#define BCM54282_QSGMII_1000X_CONTROL_3r_FIFO_ELASTICITY_TX_RXf_GET(r) ((((r).qsgmii_1000x_control_3[0]) >> 1) & 0x3)
#define BCM54282_QSGMII_1000X_CONTROL_3r_FIFO_ELASTICITY_TX_RXf_SET(r,f) (r).qsgmii_1000x_control_3[0]=(((r).qsgmii_1000x_control_3[0] & ~((uint32_t)0x3 << 1)) | ((((uint32_t)f) & 0x3) << 1))

/*
 * These macros can be used to access QSGMII_1000X_CONTROL_3.
 *
 */
#define BCM54282_READ_QSGMII_1000X_CONTROL_3r(_pc,_r) phy_aer_iblk_read(_pc,BCM54282_QSGMII_1000X_CONTROL_3r,(_r._qsgmii_1000x_control_3))
#define BCM54282_WRITE_QSGMII_1000X_CONTROL_3r(_pc,_r) phy_aer_iblk_write(_pc,BCM54282_QSGMII_1000X_CONTROL_3r,(_r._qsgmii_1000x_control_3))
#define BCM54282_READLN_QSGMII_1000X_CONTROL_3r(_pc,_l,_r) phy_aer_iblk_read(_pc,BCM54282_QSGMII_1000X_CONTROL_3r|PHY_REG_ACC_AER_IBLK_FORCE_LANE|LSHIFT32(((_l)&0x3),PHY_REG_ACCESS_FLAGS_SHIFT),(_r._qsgmii_1000x_control_3))
#define BCM54282_WRITELN_QSGMII_1000X_CONTROL_3r(_pc,_l,_r) phy_aer_iblk_write(_pc,BCM54282_QSGMII_1000X_CONTROL_3r|PHY_REG_ACC_AER_IBLK_FORCE_LANE|LSHIFT32(((_l)&0x3),PHY_REG_ACCESS_FLAGS_SHIFT),(_r._qsgmii_1000x_control_3))
#define BCM54282_WRITEALL_QSGMII_1000X_CONTROL_3r(_pc,_r) phy_aer_iblk_write(_pc,BCM54282_QSGMII_1000X_CONTROL_3r|PHY_REG_ACC_AER_IBLK_BCAST,(_r._qsgmii_1000x_control_3))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define QSGMII_1000X_CONTROL_3r BCM54282_QSGMII_1000X_CONTROL_3r
#define QSGMII_1000X_CONTROL_3r_SIZE BCM54282_QSGMII_1000X_CONTROL_3r_SIZE
typedef BCM54282_QSGMII_1000X_CONTROL_3r_t QSGMII_1000X_CONTROL_3r_t;
#define QSGMII_1000X_CONTROL_3r_CLR BCM54282_QSGMII_1000X_CONTROL_3r_CLR
#define QSGMII_1000X_CONTROL_3r_SET BCM54282_QSGMII_1000X_CONTROL_3r_SET
#define QSGMII_1000X_CONTROL_3r_GET BCM54282_QSGMII_1000X_CONTROL_3r_GET
#define QSGMII_1000X_CONTROL_3r_DISABLE_TX_CRCf_GET BCM54282_QSGMII_1000X_CONTROL_3r_DISABLE_TX_CRCf_GET
#define QSGMII_1000X_CONTROL_3r_DISABLE_TX_CRCf_SET BCM54282_QSGMII_1000X_CONTROL_3r_DISABLE_TX_CRCf_SET
#define QSGMII_1000X_CONTROL_3r_FREQ_LOCK_ELASTICITY_RXf_GET BCM54282_QSGMII_1000X_CONTROL_3r_FREQ_LOCK_ELASTICITY_RXf_GET
#define QSGMII_1000X_CONTROL_3r_FREQ_LOCK_ELASTICITY_RXf_SET BCM54282_QSGMII_1000X_CONTROL_3r_FREQ_LOCK_ELASTICITY_RXf_SET
#define QSGMII_1000X_CONTROL_3r_FIFO_ELASTICITY_TX_RXf_GET BCM54282_QSGMII_1000X_CONTROL_3r_FIFO_ELASTICITY_TX_RXf_GET
#define QSGMII_1000X_CONTROL_3r_FIFO_ELASTICITY_TX_RXf_SET BCM54282_QSGMII_1000X_CONTROL_3r_FIFO_ELASTICITY_TX_RXf_SET
#define READ_QSGMII_1000X_CONTROL_3r BCM54282_READ_QSGMII_1000X_CONTROL_3r
#define WRITE_QSGMII_1000X_CONTROL_3r BCM54282_WRITE_QSGMII_1000X_CONTROL_3r
#define READLN_QSGMII_1000X_CONTROL_3r BCM54282_READLN_QSGMII_1000X_CONTROL_3r
#define WRITELN_QSGMII_1000X_CONTROL_3r BCM54282_WRITELN_QSGMII_1000X_CONTROL_3r
#define WRITEALL_QSGMII_1000X_CONTROL_3r BCM54282_WRITEALL_QSGMII_1000X_CONTROL_3r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_QSGMII_1000X_CONTROL_3r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  QSGMII_LPI_PASSTHRU
 * BLOCKS:   QSGMII
 * REGADDR:  0x832e
 * DESC:     QSGMII_LPI_PASSTHRU Register (AER_Register, offset 0x832e)
 * SIZE:     32
 * FIELDS:
 *     QSGMII_LPI_PASSTHRU QSGMII_LPI_PASSTHRU
 *
 ******************************************************************************/
#define BCM54282_QSGMII_LPI_PASSTHRUr (0x0000832e | PHY_REG_ACC_AER_IBLK)

#define BCM54282_QSGMII_LPI_PASSTHRUr_SIZE 4

/*
 * This structure should be used to declare and program QSGMII_LPI_PASSTHRU.
 *
 */
typedef union BCM54282_QSGMII_LPI_PASSTHRUr_s {
	uint32_t v[1];
	uint32_t qsgmii_lpi_passthru[1];
	uint32_t _qsgmii_lpi_passthru;
} BCM54282_QSGMII_LPI_PASSTHRUr_t;

#define BCM54282_QSGMII_LPI_PASSTHRUr_CLR(r) (r).qsgmii_lpi_passthru[0] = 0
#define BCM54282_QSGMII_LPI_PASSTHRUr_SET(r,d) (r).qsgmii_lpi_passthru[0] = d
#define BCM54282_QSGMII_LPI_PASSTHRUr_GET(r) (r).qsgmii_lpi_passthru[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_QSGMII_LPI_PASSTHRUr_QSGMII_LPI_PASSTHRUf_GET(r) (((r).qsgmii_lpi_passthru[0]) & 0xffff)
#define BCM54282_QSGMII_LPI_PASSTHRUr_QSGMII_LPI_PASSTHRUf_SET(r,f) (r).qsgmii_lpi_passthru[0]=(((r).qsgmii_lpi_passthru[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access QSGMII_LPI_PASSTHRU.
 *
 */
#define BCM54282_READ_QSGMII_LPI_PASSTHRUr(_pc,_r) phy_aer_iblk_read(_pc,BCM54282_QSGMII_LPI_PASSTHRUr,(_r._qsgmii_lpi_passthru))
#define BCM54282_WRITE_QSGMII_LPI_PASSTHRUr(_pc,_r) phy_aer_iblk_write(_pc,BCM54282_QSGMII_LPI_PASSTHRUr,(_r._qsgmii_lpi_passthru))
#define BCM54282_READLN_QSGMII_LPI_PASSTHRUr(_pc,_l,_r) phy_aer_iblk_read(_pc,BCM54282_QSGMII_LPI_PASSTHRUr|PHY_REG_ACC_AER_IBLK_FORCE_LANE|LSHIFT32(((_l)&0x3),PHY_REG_ACCESS_FLAGS_SHIFT),(_r._qsgmii_lpi_passthru))
#define BCM54282_WRITELN_QSGMII_LPI_PASSTHRUr(_pc,_l,_r) phy_aer_iblk_write(_pc,BCM54282_QSGMII_LPI_PASSTHRUr|PHY_REG_ACC_AER_IBLK_FORCE_LANE|LSHIFT32(((_l)&0x3),PHY_REG_ACCESS_FLAGS_SHIFT),(_r._qsgmii_lpi_passthru))
#define BCM54282_WRITEALL_QSGMII_LPI_PASSTHRUr(_pc,_r) phy_aer_iblk_write(_pc,BCM54282_QSGMII_LPI_PASSTHRUr|PHY_REG_ACC_AER_IBLK_BCAST,(_r._qsgmii_lpi_passthru))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define QSGMII_LPI_PASSTHRUr BCM54282_QSGMII_LPI_PASSTHRUr
#define QSGMII_LPI_PASSTHRUr_SIZE BCM54282_QSGMII_LPI_PASSTHRUr_SIZE
typedef BCM54282_QSGMII_LPI_PASSTHRUr_t QSGMII_LPI_PASSTHRUr_t;
#define QSGMII_LPI_PASSTHRUr_CLR BCM54282_QSGMII_LPI_PASSTHRUr_CLR
#define QSGMII_LPI_PASSTHRUr_SET BCM54282_QSGMII_LPI_PASSTHRUr_SET
#define QSGMII_LPI_PASSTHRUr_GET BCM54282_QSGMII_LPI_PASSTHRUr_GET
#define QSGMII_LPI_PASSTHRUr_QSGMII_LPI_PASSTHRUf_GET BCM54282_QSGMII_LPI_PASSTHRUr_QSGMII_LPI_PASSTHRUf_GET
#define QSGMII_LPI_PASSTHRUr_QSGMII_LPI_PASSTHRUf_SET BCM54282_QSGMII_LPI_PASSTHRUr_QSGMII_LPI_PASSTHRUf_SET
#define READ_QSGMII_LPI_PASSTHRUr BCM54282_READ_QSGMII_LPI_PASSTHRUr
#define WRITE_QSGMII_LPI_PASSTHRUr BCM54282_WRITE_QSGMII_LPI_PASSTHRUr
#define READLN_QSGMII_LPI_PASSTHRUr BCM54282_READLN_QSGMII_LPI_PASSTHRUr
#define WRITELN_QSGMII_LPI_PASSTHRUr BCM54282_WRITELN_QSGMII_LPI_PASSTHRUr
#define WRITEALL_QSGMII_LPI_PASSTHRUr BCM54282_WRITEALL_QSGMII_LPI_PASSTHRUr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_QSGMII_LPI_PASSTHRUr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_1000X_CTRL
 * BLOCKS:   IEEE
 * REGADDR:  0x0000
 * DESC:     1000BASE-X MII Control Register (Addr 00h)
 * SIZE:     32
 * FIELDS:
 *     SS_MSB           Speed select, MSb.
 *     COLL_TEST_EN     Enable collision test mode.
 *     FULL_DUPLEX      Full duplex operation.
 *     RESTART_AN       Restart auto-negotiation.
 *     ISOLATE          Isolate PHY from GMII/RGMII/RTBI.
 *     POWER_DOWN       Power down.
 *     AUTONEG          Auto-negotiation enabled.
 *     SS_LSB           Speed select, LSb.
 *     LOOPBACK         Loopback mode.
 *     RESET            PHY reset.
 *
 ******************************************************************************/
#define BCM54282_MII_1000X_CTRLr (0x00000000 | PHY_REG_ACC_BRCM_1000X)

#define BCM54282_MII_1000X_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program MII_1000X_CTRL.
 *
 */
typedef union BCM54282_MII_1000X_CTRLr_s {
	uint32_t v[1];
	uint32_t mii_1000x_ctrl[1];
	uint32_t _mii_1000x_ctrl;
} BCM54282_MII_1000X_CTRLr_t;

#define BCM54282_MII_1000X_CTRLr_CLR(r) (r).mii_1000x_ctrl[0] = 0
#define BCM54282_MII_1000X_CTRLr_SET(r,d) (r).mii_1000x_ctrl[0] = d
#define BCM54282_MII_1000X_CTRLr_GET(r) (r).mii_1000x_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_1000X_CTRLr_RESETf_GET(r) ((((r).mii_1000x_ctrl[0]) >> 15) & 0x1)
#define BCM54282_MII_1000X_CTRLr_RESETf_SET(r,f) (r).mii_1000x_ctrl[0]=(((r).mii_1000x_ctrl[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_1000X_CTRLr_LOOPBACKf_GET(r) ((((r).mii_1000x_ctrl[0]) >> 14) & 0x1)
#define BCM54282_MII_1000X_CTRLr_LOOPBACKf_SET(r,f) (r).mii_1000x_ctrl[0]=(((r).mii_1000x_ctrl[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_MII_1000X_CTRLr_SS_LSBf_GET(r) ((((r).mii_1000x_ctrl[0]) >> 13) & 0x1)
#define BCM54282_MII_1000X_CTRLr_SS_LSBf_SET(r,f) (r).mii_1000x_ctrl[0]=(((r).mii_1000x_ctrl[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_MII_1000X_CTRLr_AUTONEGf_GET(r) ((((r).mii_1000x_ctrl[0]) >> 12) & 0x1)
#define BCM54282_MII_1000X_CTRLr_AUTONEGf_SET(r,f) (r).mii_1000x_ctrl[0]=(((r).mii_1000x_ctrl[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_MII_1000X_CTRLr_POWER_DOWNf_GET(r) ((((r).mii_1000x_ctrl[0]) >> 11) & 0x1)
#define BCM54282_MII_1000X_CTRLr_POWER_DOWNf_SET(r,f) (r).mii_1000x_ctrl[0]=(((r).mii_1000x_ctrl[0] & ~((uint32_t)0x1 << 11)) | ((((uint32_t)f) & 0x1) << 11))
#define BCM54282_MII_1000X_CTRLr_ISOLATEf_GET(r) ((((r).mii_1000x_ctrl[0]) >> 10) & 0x1)
#define BCM54282_MII_1000X_CTRLr_ISOLATEf_SET(r,f) (r).mii_1000x_ctrl[0]=(((r).mii_1000x_ctrl[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))
#define BCM54282_MII_1000X_CTRLr_RESTART_ANf_GET(r) ((((r).mii_1000x_ctrl[0]) >> 9) & 0x1)
#define BCM54282_MII_1000X_CTRLr_RESTART_ANf_SET(r,f) (r).mii_1000x_ctrl[0]=(((r).mii_1000x_ctrl[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
#define BCM54282_MII_1000X_CTRLr_FULL_DUPLEXf_GET(r) ((((r).mii_1000x_ctrl[0]) >> 8) & 0x1)
#define BCM54282_MII_1000X_CTRLr_FULL_DUPLEXf_SET(r,f) (r).mii_1000x_ctrl[0]=(((r).mii_1000x_ctrl[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))
#define BCM54282_MII_1000X_CTRLr_COLL_TEST_ENf_GET(r) ((((r).mii_1000x_ctrl[0]) >> 7) & 0x1)
#define BCM54282_MII_1000X_CTRLr_COLL_TEST_ENf_SET(r,f) (r).mii_1000x_ctrl[0]=(((r).mii_1000x_ctrl[0] & ~((uint32_t)0x1 << 7)) | ((((uint32_t)f) & 0x1) << 7))
#define BCM54282_MII_1000X_CTRLr_SS_MSBf_GET(r) ((((r).mii_1000x_ctrl[0]) >> 6) & 0x1)
#define BCM54282_MII_1000X_CTRLr_SS_MSBf_SET(r,f) (r).mii_1000x_ctrl[0]=(((r).mii_1000x_ctrl[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))

/*
 * These macros can be used to access MII_1000X_CTRL.
 *
 */
#define BCM54282_READ_MII_1000X_CTRLr(_pc,_r) phy_brcm_1000x_read(_pc,BCM54282_MII_1000X_CTRLr,(_r._mii_1000x_ctrl))
#define BCM54282_WRITE_MII_1000X_CTRLr(_pc,_r) phy_brcm_1000x_write(_pc,BCM54282_MII_1000X_CTRLr,(_r._mii_1000x_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_1000X_CTRLr BCM54282_MII_1000X_CTRLr
#define MII_1000X_CTRLr_SIZE BCM54282_MII_1000X_CTRLr_SIZE
typedef BCM54282_MII_1000X_CTRLr_t MII_1000X_CTRLr_t;
#define MII_1000X_CTRLr_CLR BCM54282_MII_1000X_CTRLr_CLR
#define MII_1000X_CTRLr_SET BCM54282_MII_1000X_CTRLr_SET
#define MII_1000X_CTRLr_GET BCM54282_MII_1000X_CTRLr_GET
#define MII_1000X_CTRLr_RESETf_GET BCM54282_MII_1000X_CTRLr_RESETf_GET
#define MII_1000X_CTRLr_RESETf_SET BCM54282_MII_1000X_CTRLr_RESETf_SET
#define MII_1000X_CTRLr_LOOPBACKf_GET BCM54282_MII_1000X_CTRLr_LOOPBACKf_GET
#define MII_1000X_CTRLr_LOOPBACKf_SET BCM54282_MII_1000X_CTRLr_LOOPBACKf_SET
#define MII_1000X_CTRLr_SS_LSBf_GET BCM54282_MII_1000X_CTRLr_SS_LSBf_GET
#define MII_1000X_CTRLr_SS_LSBf_SET BCM54282_MII_1000X_CTRLr_SS_LSBf_SET
#define MII_1000X_CTRLr_AUTONEGf_GET BCM54282_MII_1000X_CTRLr_AUTONEGf_GET
#define MII_1000X_CTRLr_AUTONEGf_SET BCM54282_MII_1000X_CTRLr_AUTONEGf_SET
#define MII_1000X_CTRLr_POWER_DOWNf_GET BCM54282_MII_1000X_CTRLr_POWER_DOWNf_GET
#define MII_1000X_CTRLr_POWER_DOWNf_SET BCM54282_MII_1000X_CTRLr_POWER_DOWNf_SET
#define MII_1000X_CTRLr_ISOLATEf_GET BCM54282_MII_1000X_CTRLr_ISOLATEf_GET
#define MII_1000X_CTRLr_ISOLATEf_SET BCM54282_MII_1000X_CTRLr_ISOLATEf_SET
#define MII_1000X_CTRLr_RESTART_ANf_GET BCM54282_MII_1000X_CTRLr_RESTART_ANf_GET
#define MII_1000X_CTRLr_RESTART_ANf_SET BCM54282_MII_1000X_CTRLr_RESTART_ANf_SET
#define MII_1000X_CTRLr_FULL_DUPLEXf_GET BCM54282_MII_1000X_CTRLr_FULL_DUPLEXf_GET
#define MII_1000X_CTRLr_FULL_DUPLEXf_SET BCM54282_MII_1000X_CTRLr_FULL_DUPLEXf_SET
#define MII_1000X_CTRLr_COLL_TEST_ENf_GET BCM54282_MII_1000X_CTRLr_COLL_TEST_ENf_GET
#define MII_1000X_CTRLr_COLL_TEST_ENf_SET BCM54282_MII_1000X_CTRLr_COLL_TEST_ENf_SET
#define MII_1000X_CTRLr_SS_MSBf_GET BCM54282_MII_1000X_CTRLr_SS_MSBf_GET
#define MII_1000X_CTRLr_SS_MSBf_SET BCM54282_MII_1000X_CTRLr_SS_MSBf_SET
#define READ_MII_1000X_CTRLr BCM54282_READ_MII_1000X_CTRLr
#define WRITE_MII_1000X_CTRLr BCM54282_WRITE_MII_1000X_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_1000X_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_1000X_STAT
 * BLOCKS:   IEEE
 * REGADDR:  0x0001
 * DESC:     1000BASE-X MII Status Register (Addr 01h)
 * SIZE:     32
 * FIELDS:
 *     EXT_CAPABILITY   Extended register capabilities.
 *     JABBER_DETECT    Jabber condition detected.
 *     LINK             Link is up.
 *     AUTONEG_ABILITY  Auto-negotiation capable.
 *     REMOTE_FAULT     Remote fault detected.
 *     AUTONEG_DONE     Auto-negotiation complete.
 *     MF_PREAMBLE_SUP  Preamble can be suppressed.
 *     EXT_STATUS       Extended status information in register 0Fh.
 *     CAP_100BASE_T2_HD 100BASE-T2 half-duplex capable.
 *     CAP_100BASE_T2_FD 100BASE-T2 full-duplex capable.
 *     CAP_10BASE_T_HD  10BASE-T half-duplex capable.
 *     CAP_10BASE_T_FD  10BASE-T full-duplex capable.
 *     CAP_100BASE_X_HD 100BASE-X half-duplex capable.
 *     CAP_100BASE_X_FD 100BASE-X full-duplex capable.
 *     CAP_100BASE_T4   100BASE-T4 capable.
 *
 ******************************************************************************/
#define BCM54282_MII_1000X_STATr (0x00000001 | PHY_REG_ACC_BRCM_1000X)

#define BCM54282_MII_1000X_STATr_SIZE 4

/*
 * This structure should be used to declare and program MII_1000X_STAT.
 *
 */
typedef union BCM54282_MII_1000X_STATr_s {
	uint32_t v[1];
	uint32_t mii_1000x_stat[1];
	uint32_t _mii_1000x_stat;
} BCM54282_MII_1000X_STATr_t;

#define BCM54282_MII_1000X_STATr_CLR(r) (r).mii_1000x_stat[0] = 0
#define BCM54282_MII_1000X_STATr_SET(r,d) (r).mii_1000x_stat[0] = d
#define BCM54282_MII_1000X_STATr_GET(r) (r).mii_1000x_stat[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_1000X_STATr_CAP_100BASE_T4f_GET(r) ((((r).mii_1000x_stat[0]) >> 15) & 0x1)
#define BCM54282_MII_1000X_STATr_CAP_100BASE_T4f_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_1000X_STATr_CAP_100BASE_X_FDf_GET(r) ((((r).mii_1000x_stat[0]) >> 14) & 0x1)
#define BCM54282_MII_1000X_STATr_CAP_100BASE_X_FDf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_MII_1000X_STATr_CAP_100BASE_X_HDf_GET(r) ((((r).mii_1000x_stat[0]) >> 13) & 0x1)
#define BCM54282_MII_1000X_STATr_CAP_100BASE_X_HDf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_MII_1000X_STATr_CAP_10BASE_T_FDf_GET(r) ((((r).mii_1000x_stat[0]) >> 12) & 0x1)
#define BCM54282_MII_1000X_STATr_CAP_10BASE_T_FDf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_MII_1000X_STATr_CAP_10BASE_T_HDf_GET(r) ((((r).mii_1000x_stat[0]) >> 11) & 0x1)
#define BCM54282_MII_1000X_STATr_CAP_10BASE_T_HDf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 11)) | ((((uint32_t)f) & 0x1) << 11))
#define BCM54282_MII_1000X_STATr_CAP_100BASE_T2_FDf_GET(r) ((((r).mii_1000x_stat[0]) >> 10) & 0x1)
#define BCM54282_MII_1000X_STATr_CAP_100BASE_T2_FDf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 10)) | ((((uint32_t)f) & 0x1) << 10))
#define BCM54282_MII_1000X_STATr_CAP_100BASE_T2_HDf_GET(r) ((((r).mii_1000x_stat[0]) >> 9) & 0x1)
#define BCM54282_MII_1000X_STATr_CAP_100BASE_T2_HDf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 9)) | ((((uint32_t)f) & 0x1) << 9))
#define BCM54282_MII_1000X_STATr_EXT_STATUSf_GET(r) ((((r).mii_1000x_stat[0]) >> 8) & 0x1)
#define BCM54282_MII_1000X_STATr_EXT_STATUSf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))
#define BCM54282_MII_1000X_STATr_MF_PREAMBLE_SUPf_GET(r) ((((r).mii_1000x_stat[0]) >> 6) & 0x1)
#define BCM54282_MII_1000X_STATr_MF_PREAMBLE_SUPf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))
#define BCM54282_MII_1000X_STATr_AUTONEG_DONEf_GET(r) ((((r).mii_1000x_stat[0]) >> 5) & 0x1)
#define BCM54282_MII_1000X_STATr_AUTONEG_DONEf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))
#define BCM54282_MII_1000X_STATr_REMOTE_FAULTf_GET(r) ((((r).mii_1000x_stat[0]) >> 4) & 0x1)
#define BCM54282_MII_1000X_STATr_REMOTE_FAULTf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 4)) | ((((uint32_t)f) & 0x1) << 4))
#define BCM54282_MII_1000X_STATr_AUTONEG_ABILITYf_GET(r) ((((r).mii_1000x_stat[0]) >> 3) & 0x1)
#define BCM54282_MII_1000X_STATr_AUTONEG_ABILITYf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 3)) | ((((uint32_t)f) & 0x1) << 3))
#define BCM54282_MII_1000X_STATr_LINKf_GET(r) ((((r).mii_1000x_stat[0]) >> 2) & 0x1)
#define BCM54282_MII_1000X_STATr_LINKf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_MII_1000X_STATr_JABBER_DETECTf_GET(r) ((((r).mii_1000x_stat[0]) >> 1) & 0x1)
#define BCM54282_MII_1000X_STATr_JABBER_DETECTf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1 << 1)) | ((((uint32_t)f) & 0x1) << 1))
#define BCM54282_MII_1000X_STATr_EXT_CAPABILITYf_GET(r) (((r).mii_1000x_stat[0]) & 0x1)
#define BCM54282_MII_1000X_STATr_EXT_CAPABILITYf_SET(r,f) (r).mii_1000x_stat[0]=(((r).mii_1000x_stat[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access MII_1000X_STAT.
 *
 */
#define BCM54282_READ_MII_1000X_STATr(_pc,_r) phy_brcm_1000x_read(_pc,BCM54282_MII_1000X_STATr,(_r._mii_1000x_stat))
#define BCM54282_WRITE_MII_1000X_STATr(_pc,_r) phy_brcm_1000x_write(_pc,BCM54282_MII_1000X_STATr,(_r._mii_1000x_stat))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_1000X_STATr BCM54282_MII_1000X_STATr
#define MII_1000X_STATr_SIZE BCM54282_MII_1000X_STATr_SIZE
typedef BCM54282_MII_1000X_STATr_t MII_1000X_STATr_t;
#define MII_1000X_STATr_CLR BCM54282_MII_1000X_STATr_CLR
#define MII_1000X_STATr_SET BCM54282_MII_1000X_STATr_SET
#define MII_1000X_STATr_GET BCM54282_MII_1000X_STATr_GET
#define MII_1000X_STATr_CAP_100BASE_T4f_GET BCM54282_MII_1000X_STATr_CAP_100BASE_T4f_GET
#define MII_1000X_STATr_CAP_100BASE_T4f_SET BCM54282_MII_1000X_STATr_CAP_100BASE_T4f_SET
#define MII_1000X_STATr_CAP_100BASE_X_FDf_GET BCM54282_MII_1000X_STATr_CAP_100BASE_X_FDf_GET
#define MII_1000X_STATr_CAP_100BASE_X_FDf_SET BCM54282_MII_1000X_STATr_CAP_100BASE_X_FDf_SET
#define MII_1000X_STATr_CAP_100BASE_X_HDf_GET BCM54282_MII_1000X_STATr_CAP_100BASE_X_HDf_GET
#define MII_1000X_STATr_CAP_100BASE_X_HDf_SET BCM54282_MII_1000X_STATr_CAP_100BASE_X_HDf_SET
#define MII_1000X_STATr_CAP_10BASE_T_FDf_GET BCM54282_MII_1000X_STATr_CAP_10BASE_T_FDf_GET
#define MII_1000X_STATr_CAP_10BASE_T_FDf_SET BCM54282_MII_1000X_STATr_CAP_10BASE_T_FDf_SET
#define MII_1000X_STATr_CAP_10BASE_T_HDf_GET BCM54282_MII_1000X_STATr_CAP_10BASE_T_HDf_GET
#define MII_1000X_STATr_CAP_10BASE_T_HDf_SET BCM54282_MII_1000X_STATr_CAP_10BASE_T_HDf_SET
#define MII_1000X_STATr_CAP_100BASE_T2_FDf_GET BCM54282_MII_1000X_STATr_CAP_100BASE_T2_FDf_GET
#define MII_1000X_STATr_CAP_100BASE_T2_FDf_SET BCM54282_MII_1000X_STATr_CAP_100BASE_T2_FDf_SET
#define MII_1000X_STATr_CAP_100BASE_T2_HDf_GET BCM54282_MII_1000X_STATr_CAP_100BASE_T2_HDf_GET
#define MII_1000X_STATr_CAP_100BASE_T2_HDf_SET BCM54282_MII_1000X_STATr_CAP_100BASE_T2_HDf_SET
#define MII_1000X_STATr_EXT_STATUSf_GET BCM54282_MII_1000X_STATr_EXT_STATUSf_GET
#define MII_1000X_STATr_EXT_STATUSf_SET BCM54282_MII_1000X_STATr_EXT_STATUSf_SET
#define MII_1000X_STATr_MF_PREAMBLE_SUPf_GET BCM54282_MII_1000X_STATr_MF_PREAMBLE_SUPf_GET
#define MII_1000X_STATr_MF_PREAMBLE_SUPf_SET BCM54282_MII_1000X_STATr_MF_PREAMBLE_SUPf_SET
#define MII_1000X_STATr_AUTONEG_DONEf_GET BCM54282_MII_1000X_STATr_AUTONEG_DONEf_GET
#define MII_1000X_STATr_AUTONEG_DONEf_SET BCM54282_MII_1000X_STATr_AUTONEG_DONEf_SET
#define MII_1000X_STATr_REMOTE_FAULTf_GET BCM54282_MII_1000X_STATr_REMOTE_FAULTf_GET
#define MII_1000X_STATr_REMOTE_FAULTf_SET BCM54282_MII_1000X_STATr_REMOTE_FAULTf_SET
#define MII_1000X_STATr_AUTONEG_ABILITYf_GET BCM54282_MII_1000X_STATr_AUTONEG_ABILITYf_GET
#define MII_1000X_STATr_AUTONEG_ABILITYf_SET BCM54282_MII_1000X_STATr_AUTONEG_ABILITYf_SET
#define MII_1000X_STATr_LINKf_GET BCM54282_MII_1000X_STATr_LINKf_GET
#define MII_1000X_STATr_LINKf_SET BCM54282_MII_1000X_STATr_LINKf_SET
#define MII_1000X_STATr_JABBER_DETECTf_GET BCM54282_MII_1000X_STATr_JABBER_DETECTf_GET
#define MII_1000X_STATr_JABBER_DETECTf_SET BCM54282_MII_1000X_STATr_JABBER_DETECTf_SET
#define MII_1000X_STATr_EXT_CAPABILITYf_GET BCM54282_MII_1000X_STATr_EXT_CAPABILITYf_GET
#define MII_1000X_STATr_EXT_CAPABILITYf_SET BCM54282_MII_1000X_STATr_EXT_CAPABILITYf_SET
#define READ_MII_1000X_STATr BCM54282_READ_MII_1000X_STATr
#define WRITE_MII_1000X_STATr BCM54282_WRITE_MII_1000X_STATr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_1000X_STATr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_1000X_ANA
 * BLOCKS:   IEEE
 * REGADDR:  0x0004
 * DESC:     1000BASE-X MII Auto-Negotiation Advertise Register (Addr 04h)
 * SIZE:     32
 * FIELDS:
 *     CAP_1000BASE_X_FD 1000BASE-X full-duplex capable.
 *     CAP_1000BASE_X_HD 1000BASE-X half-duplex capable.
 *     PAUSE            Pause capable.
 *     REMOTE_FAULT     Advertise remote fault detected.
 *
 ******************************************************************************/
#define BCM54282_MII_1000X_ANAr (0x00000004 | PHY_REG_ACC_BRCM_1000X)

#define BCM54282_MII_1000X_ANAr_SIZE 4

/*
 * This structure should be used to declare and program MII_1000X_ANA.
 *
 */
typedef union BCM54282_MII_1000X_ANAr_s {
	uint32_t v[1];
	uint32_t mii_1000x_ana[1];
	uint32_t _mii_1000x_ana;
} BCM54282_MII_1000X_ANAr_t;

#define BCM54282_MII_1000X_ANAr_CLR(r) (r).mii_1000x_ana[0] = 0
#define BCM54282_MII_1000X_ANAr_SET(r,d) (r).mii_1000x_ana[0] = d
#define BCM54282_MII_1000X_ANAr_GET(r) (r).mii_1000x_ana[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_1000X_ANAr_REMOTE_FAULTf_GET(r) ((((r).mii_1000x_ana[0]) >> 13) & 0x1)
#define BCM54282_MII_1000X_ANAr_REMOTE_FAULTf_SET(r,f) (r).mii_1000x_ana[0]=(((r).mii_1000x_ana[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_MII_1000X_ANAr_PAUSEf_GET(r) ((((r).mii_1000x_ana[0]) >> 7) & 0x3)
#define BCM54282_MII_1000X_ANAr_PAUSEf_SET(r,f) (r).mii_1000x_ana[0]=(((r).mii_1000x_ana[0] & ~((uint32_t)0x3 << 7)) | ((((uint32_t)f) & 0x3) << 7))
#define BCM54282_MII_1000X_ANAr_CAP_1000BASE_X_HDf_GET(r) ((((r).mii_1000x_ana[0]) >> 6) & 0x1)
#define BCM54282_MII_1000X_ANAr_CAP_1000BASE_X_HDf_SET(r,f) (r).mii_1000x_ana[0]=(((r).mii_1000x_ana[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))
#define BCM54282_MII_1000X_ANAr_CAP_1000BASE_X_FDf_GET(r) ((((r).mii_1000x_ana[0]) >> 5) & 0x1)
#define BCM54282_MII_1000X_ANAr_CAP_1000BASE_X_FDf_SET(r,f) (r).mii_1000x_ana[0]=(((r).mii_1000x_ana[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))

/*
 * These macros can be used to access MII_1000X_ANA.
 *
 */
#define BCM54282_READ_MII_1000X_ANAr(_pc,_r) phy_brcm_1000x_read(_pc,BCM54282_MII_1000X_ANAr,(_r._mii_1000x_ana))
#define BCM54282_WRITE_MII_1000X_ANAr(_pc,_r) phy_brcm_1000x_write(_pc,BCM54282_MII_1000X_ANAr,(_r._mii_1000x_ana))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_1000X_ANAr BCM54282_MII_1000X_ANAr
#define MII_1000X_ANAr_SIZE BCM54282_MII_1000X_ANAr_SIZE
typedef BCM54282_MII_1000X_ANAr_t MII_1000X_ANAr_t;
#define MII_1000X_ANAr_CLR BCM54282_MII_1000X_ANAr_CLR
#define MII_1000X_ANAr_SET BCM54282_MII_1000X_ANAr_SET
#define MII_1000X_ANAr_GET BCM54282_MII_1000X_ANAr_GET
#define MII_1000X_ANAr_REMOTE_FAULTf_GET BCM54282_MII_1000X_ANAr_REMOTE_FAULTf_GET
#define MII_1000X_ANAr_REMOTE_FAULTf_SET BCM54282_MII_1000X_ANAr_REMOTE_FAULTf_SET
#define MII_1000X_ANAr_PAUSEf_GET BCM54282_MII_1000X_ANAr_PAUSEf_GET
#define MII_1000X_ANAr_PAUSEf_SET BCM54282_MII_1000X_ANAr_PAUSEf_SET
#define MII_1000X_ANAr_CAP_1000BASE_X_HDf_GET BCM54282_MII_1000X_ANAr_CAP_1000BASE_X_HDf_GET
#define MII_1000X_ANAr_CAP_1000BASE_X_HDf_SET BCM54282_MII_1000X_ANAr_CAP_1000BASE_X_HDf_SET
#define MII_1000X_ANAr_CAP_1000BASE_X_FDf_GET BCM54282_MII_1000X_ANAr_CAP_1000BASE_X_FDf_GET
#define MII_1000X_ANAr_CAP_1000BASE_X_FDf_SET BCM54282_MII_1000X_ANAr_CAP_1000BASE_X_FDf_SET
#define READ_MII_1000X_ANAr BCM54282_READ_MII_1000X_ANAr
#define WRITE_MII_1000X_ANAr BCM54282_WRITE_MII_1000X_ANAr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_1000X_ANAr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  MII_1000X_ANP
 * BLOCKS:   IEEE
 * REGADDR:  0x0005
 * DESC:     1000BASE-X MII Auto-Negotiation Link Partner Ability Register (Addr 05h)
 * SIZE:     32
 * FIELDS:
 *     CAP_1000BASE_X_FD 1000BASE-X full-duplex capable.
 *     CAP_1000BASE_X_HD 1000BASE-X half-duplex capable.
 *     PAUSE            Pause capable.
 *     REMOTE_FAULT     Link partner has detected remote fault.
 *     ACK              Link partner has received link code word.
 *     NEXT_PAGE        Link partner has Next Page ability.
 *
 ******************************************************************************/
#define BCM54282_MII_1000X_ANPr (0x00000005 | PHY_REG_ACC_BRCM_1000X)

#define BCM54282_MII_1000X_ANPr_SIZE 4

/*
 * This structure should be used to declare and program MII_1000X_ANP.
 *
 */
typedef union BCM54282_MII_1000X_ANPr_s {
	uint32_t v[1];
	uint32_t mii_1000x_anp[1];
	uint32_t _mii_1000x_anp;
} BCM54282_MII_1000X_ANPr_t;

#define BCM54282_MII_1000X_ANPr_CLR(r) (r).mii_1000x_anp[0] = 0
#define BCM54282_MII_1000X_ANPr_SET(r,d) (r).mii_1000x_anp[0] = d
#define BCM54282_MII_1000X_ANPr_GET(r) (r).mii_1000x_anp[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_MII_1000X_ANPr_NEXT_PAGEf_GET(r) ((((r).mii_1000x_anp[0]) >> 15) & 0x1)
#define BCM54282_MII_1000X_ANPr_NEXT_PAGEf_SET(r,f) (r).mii_1000x_anp[0]=(((r).mii_1000x_anp[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_MII_1000X_ANPr_ACKf_GET(r) ((((r).mii_1000x_anp[0]) >> 14) & 0x1)
#define BCM54282_MII_1000X_ANPr_ACKf_SET(r,f) (r).mii_1000x_anp[0]=(((r).mii_1000x_anp[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_MII_1000X_ANPr_REMOTE_FAULTf_GET(r) ((((r).mii_1000x_anp[0]) >> 13) & 0x1)
#define BCM54282_MII_1000X_ANPr_REMOTE_FAULTf_SET(r,f) (r).mii_1000x_anp[0]=(((r).mii_1000x_anp[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_MII_1000X_ANPr_PAUSEf_GET(r) ((((r).mii_1000x_anp[0]) >> 7) & 0x3)
#define BCM54282_MII_1000X_ANPr_PAUSEf_SET(r,f) (r).mii_1000x_anp[0]=(((r).mii_1000x_anp[0] & ~((uint32_t)0x3 << 7)) | ((((uint32_t)f) & 0x3) << 7))
#define BCM54282_MII_1000X_ANPr_CAP_1000BASE_X_HDf_GET(r) ((((r).mii_1000x_anp[0]) >> 6) & 0x1)
#define BCM54282_MII_1000X_ANPr_CAP_1000BASE_X_HDf_SET(r,f) (r).mii_1000x_anp[0]=(((r).mii_1000x_anp[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))
#define BCM54282_MII_1000X_ANPr_CAP_1000BASE_X_FDf_GET(r) ((((r).mii_1000x_anp[0]) >> 5) & 0x1)
#define BCM54282_MII_1000X_ANPr_CAP_1000BASE_X_FDf_SET(r,f) (r).mii_1000x_anp[0]=(((r).mii_1000x_anp[0] & ~((uint32_t)0x1 << 5)) | ((((uint32_t)f) & 0x1) << 5))

/*
 * These macros can be used to access MII_1000X_ANP.
 *
 */
#define BCM54282_READ_MII_1000X_ANPr(_pc,_r) phy_brcm_1000x_read(_pc,BCM54282_MII_1000X_ANPr,(_r._mii_1000x_anp))
#define BCM54282_WRITE_MII_1000X_ANPr(_pc,_r) phy_brcm_1000x_write(_pc,BCM54282_MII_1000X_ANPr,(_r._mii_1000x_anp))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define MII_1000X_ANPr BCM54282_MII_1000X_ANPr
#define MII_1000X_ANPr_SIZE BCM54282_MII_1000X_ANPr_SIZE
typedef BCM54282_MII_1000X_ANPr_t MII_1000X_ANPr_t;
#define MII_1000X_ANPr_CLR BCM54282_MII_1000X_ANPr_CLR
#define MII_1000X_ANPr_SET BCM54282_MII_1000X_ANPr_SET
#define MII_1000X_ANPr_GET BCM54282_MII_1000X_ANPr_GET
#define MII_1000X_ANPr_NEXT_PAGEf_GET BCM54282_MII_1000X_ANPr_NEXT_PAGEf_GET
#define MII_1000X_ANPr_NEXT_PAGEf_SET BCM54282_MII_1000X_ANPr_NEXT_PAGEf_SET
#define MII_1000X_ANPr_ACKf_GET BCM54282_MII_1000X_ANPr_ACKf_GET
#define MII_1000X_ANPr_ACKf_SET BCM54282_MII_1000X_ANPr_ACKf_SET
#define MII_1000X_ANPr_REMOTE_FAULTf_GET BCM54282_MII_1000X_ANPr_REMOTE_FAULTf_GET
#define MII_1000X_ANPr_REMOTE_FAULTf_SET BCM54282_MII_1000X_ANPr_REMOTE_FAULTf_SET
#define MII_1000X_ANPr_PAUSEf_GET BCM54282_MII_1000X_ANPr_PAUSEf_GET
#define MII_1000X_ANPr_PAUSEf_SET BCM54282_MII_1000X_ANPr_PAUSEf_SET
#define MII_1000X_ANPr_CAP_1000BASE_X_HDf_GET BCM54282_MII_1000X_ANPr_CAP_1000BASE_X_HDf_GET
#define MII_1000X_ANPr_CAP_1000BASE_X_HDf_SET BCM54282_MII_1000X_ANPr_CAP_1000BASE_X_HDf_SET
#define MII_1000X_ANPr_CAP_1000BASE_X_FDf_GET BCM54282_MII_1000X_ANPr_CAP_1000BASE_X_FDf_GET
#define MII_1000X_ANPr_CAP_1000BASE_X_FDf_SET BCM54282_MII_1000X_ANPr_CAP_1000BASE_X_FDf_SET
#define READ_MII_1000X_ANPr BCM54282_READ_MII_1000X_ANPr
#define WRITE_MII_1000X_ANPr BCM54282_WRITE_MII_1000X_ANPr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_MII_1000X_ANPr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EXP_PKT_COUNTER
 * BLOCKS:   USER
 * REGADDR:  0x0015
 * DESC:     Receive/Transmit Packet Counter Register (Addr 00h)
 * SIZE:     32
 * FIELDS:
 *     EXP_PKT_COUNTER  EXP_PKT_COUNTER
 *
 ******************************************************************************/
#define BCM54282_EXP_PKT_COUNTERr (0x000f0015 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EXP_PKT_COUNTERr_SIZE 4

/*
 * This structure should be used to declare and program EXP_PKT_COUNTER.
 *
 */
typedef union BCM54282_EXP_PKT_COUNTERr_s {
	uint32_t v[1];
	uint32_t exp_pkt_counter[1];
	uint32_t _exp_pkt_counter;
} BCM54282_EXP_PKT_COUNTERr_t;

#define BCM54282_EXP_PKT_COUNTERr_CLR(r) (r).exp_pkt_counter[0] = 0
#define BCM54282_EXP_PKT_COUNTERr_SET(r,d) (r).exp_pkt_counter[0] = d
#define BCM54282_EXP_PKT_COUNTERr_GET(r) (r).exp_pkt_counter[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EXP_PKT_COUNTERr_EXP_PKT_COUNTERf_GET(r) (((r).exp_pkt_counter[0]) & 0xffff)
#define BCM54282_EXP_PKT_COUNTERr_EXP_PKT_COUNTERf_SET(r,f) (r).exp_pkt_counter[0]=(((r).exp_pkt_counter[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access EXP_PKT_COUNTER.
 *
 */
#define BCM54282_READ_EXP_PKT_COUNTERr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EXP_PKT_COUNTERr,(_r._exp_pkt_counter))
#define BCM54282_WRITE_EXP_PKT_COUNTERr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EXP_PKT_COUNTERr,(_r._exp_pkt_counter))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EXP_PKT_COUNTERr BCM54282_EXP_PKT_COUNTERr
#define EXP_PKT_COUNTERr_SIZE BCM54282_EXP_PKT_COUNTERr_SIZE
typedef BCM54282_EXP_PKT_COUNTERr_t EXP_PKT_COUNTERr_t;
#define EXP_PKT_COUNTERr_CLR BCM54282_EXP_PKT_COUNTERr_CLR
#define EXP_PKT_COUNTERr_SET BCM54282_EXP_PKT_COUNTERr_SET
#define EXP_PKT_COUNTERr_GET BCM54282_EXP_PKT_COUNTERr_GET
#define EXP_PKT_COUNTERr_EXP_PKT_COUNTERf_GET BCM54282_EXP_PKT_COUNTERr_EXP_PKT_COUNTERf_GET
#define EXP_PKT_COUNTERr_EXP_PKT_COUNTERf_SET BCM54282_EXP_PKT_COUNTERr_EXP_PKT_COUNTERf_SET
#define READ_EXP_PKT_COUNTERr BCM54282_READ_EXP_PKT_COUNTERr
#define WRITE_EXP_PKT_COUNTERr BCM54282_WRITE_EXP_PKT_COUNTERr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EXP_PKT_COUNTERr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EXP_LED_SELECTOR
 * BLOCKS:   USER
 * REGADDR:  0x0015
 * DESC:     Multicolor LED Selector Register (Addr 04h)
 * SIZE:     32
 * FIELDS:
 *     EXP_LED_SELECTOR EXP_LED_SELECTOR
 *
 ******************************************************************************/
#define BCM54282_EXP_LED_SELECTORr (0x000f0415 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EXP_LED_SELECTORr_SIZE 4

/*
 * This structure should be used to declare and program EXP_LED_SELECTOR.
 *
 */
typedef union BCM54282_EXP_LED_SELECTORr_s {
	uint32_t v[1];
	uint32_t exp_led_selector[1];
	uint32_t _exp_led_selector;
} BCM54282_EXP_LED_SELECTORr_t;

#define BCM54282_EXP_LED_SELECTORr_CLR(r) (r).exp_led_selector[0] = 0
#define BCM54282_EXP_LED_SELECTORr_SET(r,d) (r).exp_led_selector[0] = d
#define BCM54282_EXP_LED_SELECTORr_GET(r) (r).exp_led_selector[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EXP_LED_SELECTORr_EXP_LED_SELECTORf_GET(r) (((r).exp_led_selector[0]) & 0xffff)
#define BCM54282_EXP_LED_SELECTORr_EXP_LED_SELECTORf_SET(r,f) (r).exp_led_selector[0]=(((r).exp_led_selector[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access EXP_LED_SELECTOR.
 *
 */
#define BCM54282_READ_EXP_LED_SELECTORr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EXP_LED_SELECTORr,(_r._exp_led_selector))
#define BCM54282_WRITE_EXP_LED_SELECTORr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EXP_LED_SELECTORr,(_r._exp_led_selector))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EXP_LED_SELECTORr BCM54282_EXP_LED_SELECTORr
#define EXP_LED_SELECTORr_SIZE BCM54282_EXP_LED_SELECTORr_SIZE
typedef BCM54282_EXP_LED_SELECTORr_t EXP_LED_SELECTORr_t;
#define EXP_LED_SELECTORr_CLR BCM54282_EXP_LED_SELECTORr_CLR
#define EXP_LED_SELECTORr_SET BCM54282_EXP_LED_SELECTORr_SET
#define EXP_LED_SELECTORr_GET BCM54282_EXP_LED_SELECTORr_GET
#define EXP_LED_SELECTORr_EXP_LED_SELECTORf_GET BCM54282_EXP_LED_SELECTORr_EXP_LED_SELECTORf_GET
#define EXP_LED_SELECTORr_EXP_LED_SELECTORf_SET BCM54282_EXP_LED_SELECTORr_EXP_LED_SELECTORf_SET
#define READ_EXP_LED_SELECTORr BCM54282_READ_EXP_LED_SELECTORr
#define WRITE_EXP_LED_SELECTORr BCM54282_WRITE_EXP_LED_SELECTORr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EXP_LED_SELECTORr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EXP_LED_FLASH_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x0015
 * DESC:     Multicolor LED Flash Rate Controls Register (Addr 05h)
 * SIZE:     32
 * FIELDS:
 *     EXP_LED_FLASH_CTRL EXP_LED_FLASH_CTRL
 *
 ******************************************************************************/
#define BCM54282_EXP_LED_FLASH_CTRLr (0x000f0515 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EXP_LED_FLASH_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program EXP_LED_FLASH_CTRL.
 *
 */
typedef union BCM54282_EXP_LED_FLASH_CTRLr_s {
	uint32_t v[1];
	uint32_t exp_led_flash_ctrl[1];
	uint32_t _exp_led_flash_ctrl;
} BCM54282_EXP_LED_FLASH_CTRLr_t;

#define BCM54282_EXP_LED_FLASH_CTRLr_CLR(r) (r).exp_led_flash_ctrl[0] = 0
#define BCM54282_EXP_LED_FLASH_CTRLr_SET(r,d) (r).exp_led_flash_ctrl[0] = d
#define BCM54282_EXP_LED_FLASH_CTRLr_GET(r) (r).exp_led_flash_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EXP_LED_FLASH_CTRLr_EXP_LED_FLASH_CTRLf_GET(r) (((r).exp_led_flash_ctrl[0]) & 0xffff)
#define BCM54282_EXP_LED_FLASH_CTRLr_EXP_LED_FLASH_CTRLf_SET(r,f) (r).exp_led_flash_ctrl[0]=(((r).exp_led_flash_ctrl[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access EXP_LED_FLASH_CTRL.
 *
 */
#define BCM54282_READ_EXP_LED_FLASH_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EXP_LED_FLASH_CTRLr,(_r._exp_led_flash_ctrl))
#define BCM54282_WRITE_EXP_LED_FLASH_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EXP_LED_FLASH_CTRLr,(_r._exp_led_flash_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EXP_LED_FLASH_CTRLr BCM54282_EXP_LED_FLASH_CTRLr
#define EXP_LED_FLASH_CTRLr_SIZE BCM54282_EXP_LED_FLASH_CTRLr_SIZE
typedef BCM54282_EXP_LED_FLASH_CTRLr_t EXP_LED_FLASH_CTRLr_t;
#define EXP_LED_FLASH_CTRLr_CLR BCM54282_EXP_LED_FLASH_CTRLr_CLR
#define EXP_LED_FLASH_CTRLr_SET BCM54282_EXP_LED_FLASH_CTRLr_SET
#define EXP_LED_FLASH_CTRLr_GET BCM54282_EXP_LED_FLASH_CTRLr_GET
#define EXP_LED_FLASH_CTRLr_EXP_LED_FLASH_CTRLf_GET BCM54282_EXP_LED_FLASH_CTRLr_EXP_LED_FLASH_CTRLf_GET
#define EXP_LED_FLASH_CTRLr_EXP_LED_FLASH_CTRLf_SET BCM54282_EXP_LED_FLASH_CTRLr_EXP_LED_FLASH_CTRLf_SET
#define READ_EXP_LED_FLASH_CTRLr BCM54282_READ_EXP_LED_FLASH_CTRLr
#define WRITE_EXP_LED_FLASH_CTRLr BCM54282_WRITE_EXP_LED_FLASH_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EXP_LED_FLASH_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EXP_LED_BLINK_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x0015
 * DESC:     Multicolor LED Programmable Blink Controls Register (Addr 06h)
 * SIZE:     32
 * FIELDS:
 *     EXP_LED_BLINK_CTRL EXP_LED_BLINK_CTRL
 *
 ******************************************************************************/
#define BCM54282_EXP_LED_BLINK_CTRLr (0x000f0615 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EXP_LED_BLINK_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program EXP_LED_BLINK_CTRL.
 *
 */
typedef union BCM54282_EXP_LED_BLINK_CTRLr_s {
	uint32_t v[1];
	uint32_t exp_led_blink_ctrl[1];
	uint32_t _exp_led_blink_ctrl;
} BCM54282_EXP_LED_BLINK_CTRLr_t;

#define BCM54282_EXP_LED_BLINK_CTRLr_CLR(r) (r).exp_led_blink_ctrl[0] = 0
#define BCM54282_EXP_LED_BLINK_CTRLr_SET(r,d) (r).exp_led_blink_ctrl[0] = d
#define BCM54282_EXP_LED_BLINK_CTRLr_GET(r) (r).exp_led_blink_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EXP_LED_BLINK_CTRLr_EXP_LED_BLINK_CTRLf_GET(r) (((r).exp_led_blink_ctrl[0]) & 0xffff)
#define BCM54282_EXP_LED_BLINK_CTRLr_EXP_LED_BLINK_CTRLf_SET(r,f) (r).exp_led_blink_ctrl[0]=(((r).exp_led_blink_ctrl[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access EXP_LED_BLINK_CTRL.
 *
 */
#define BCM54282_READ_EXP_LED_BLINK_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EXP_LED_BLINK_CTRLr,(_r._exp_led_blink_ctrl))
#define BCM54282_WRITE_EXP_LED_BLINK_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EXP_LED_BLINK_CTRLr,(_r._exp_led_blink_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EXP_LED_BLINK_CTRLr BCM54282_EXP_LED_BLINK_CTRLr
#define EXP_LED_BLINK_CTRLr_SIZE BCM54282_EXP_LED_BLINK_CTRLr_SIZE
typedef BCM54282_EXP_LED_BLINK_CTRLr_t EXP_LED_BLINK_CTRLr_t;
#define EXP_LED_BLINK_CTRLr_CLR BCM54282_EXP_LED_BLINK_CTRLr_CLR
#define EXP_LED_BLINK_CTRLr_SET BCM54282_EXP_LED_BLINK_CTRLr_SET
#define EXP_LED_BLINK_CTRLr_GET BCM54282_EXP_LED_BLINK_CTRLr_GET
#define EXP_LED_BLINK_CTRLr_EXP_LED_BLINK_CTRLf_GET BCM54282_EXP_LED_BLINK_CTRLr_EXP_LED_BLINK_CTRLf_GET
#define EXP_LED_BLINK_CTRLr_EXP_LED_BLINK_CTRLf_SET BCM54282_EXP_LED_BLINK_CTRLr_EXP_LED_BLINK_CTRLf_SET
#define READ_EXP_LED_BLINK_CTRLr BCM54282_READ_EXP_LED_BLINK_CTRLr
#define WRITE_EXP_LED_BLINK_CTRLr BCM54282_WRITE_EXP_LED_BLINK_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EXP_LED_BLINK_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EXT_CABLE_DIAG_RESULT
 * BLOCKS:   USER
 * REGADDR:  0x0015
 * DESC:     Cable Diagnostics Results (Addr 11h)
 * SIZE:     32
 * FIELDS:
 *     EXT_CABLE_DIAG_RESULT EXT_CABLE_DIAG_RESULT
 *
 ******************************************************************************/
#define BCM54282_EXT_CABLE_DIAG_RESULTr (0x000f1115 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EXT_CABLE_DIAG_RESULTr_SIZE 4

/*
 * This structure should be used to declare and program EXT_CABLE_DIAG_RESULT.
 *
 */
typedef union BCM54282_EXT_CABLE_DIAG_RESULTr_s {
	uint32_t v[1];
	uint32_t ext_cable_diag_result[1];
	uint32_t _ext_cable_diag_result;
} BCM54282_EXT_CABLE_DIAG_RESULTr_t;

#define BCM54282_EXT_CABLE_DIAG_RESULTr_CLR(r) (r).ext_cable_diag_result[0] = 0
#define BCM54282_EXT_CABLE_DIAG_RESULTr_SET(r,d) (r).ext_cable_diag_result[0] = d
#define BCM54282_EXT_CABLE_DIAG_RESULTr_GET(r) (r).ext_cable_diag_result[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EXT_CABLE_DIAG_RESULTr_EXT_CABLE_DIAG_RESULTf_GET(r) (((r).ext_cable_diag_result[0]) & 0xffff)
#define BCM54282_EXT_CABLE_DIAG_RESULTr_EXT_CABLE_DIAG_RESULTf_SET(r,f) (r).ext_cable_diag_result[0]=(((r).ext_cable_diag_result[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access EXT_CABLE_DIAG_RESULT.
 *
 */
#define BCM54282_READ_EXT_CABLE_DIAG_RESULTr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EXT_CABLE_DIAG_RESULTr,(_r._ext_cable_diag_result))
#define BCM54282_WRITE_EXT_CABLE_DIAG_RESULTr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EXT_CABLE_DIAG_RESULTr,(_r._ext_cable_diag_result))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EXT_CABLE_DIAG_RESULTr BCM54282_EXT_CABLE_DIAG_RESULTr
#define EXT_CABLE_DIAG_RESULTr_SIZE BCM54282_EXT_CABLE_DIAG_RESULTr_SIZE
typedef BCM54282_EXT_CABLE_DIAG_RESULTr_t EXT_CABLE_DIAG_RESULTr_t;
#define EXT_CABLE_DIAG_RESULTr_CLR BCM54282_EXT_CABLE_DIAG_RESULTr_CLR
#define EXT_CABLE_DIAG_RESULTr_SET BCM54282_EXT_CABLE_DIAG_RESULTr_SET
#define EXT_CABLE_DIAG_RESULTr_GET BCM54282_EXT_CABLE_DIAG_RESULTr_GET
#define EXT_CABLE_DIAG_RESULTr_EXT_CABLE_DIAG_RESULTf_GET BCM54282_EXT_CABLE_DIAG_RESULTr_EXT_CABLE_DIAG_RESULTf_GET
#define EXT_CABLE_DIAG_RESULTr_EXT_CABLE_DIAG_RESULTf_SET BCM54282_EXT_CABLE_DIAG_RESULTr_EXT_CABLE_DIAG_RESULTf_SET
#define READ_EXT_CABLE_DIAG_RESULTr BCM54282_READ_EXT_CABLE_DIAG_RESULTr
#define WRITE_EXT_CABLE_DIAG_RESULTr BCM54282_WRITE_EXT_CABLE_DIAG_RESULTr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EXT_CABLE_DIAG_RESULTr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EXT_CABLE_DIAG_LEN_1
 * BLOCKS:   USER
 * REGADDR:  0x0015
 * DESC:     Cable Diagnostics Lengths 1 (Addr 12h)
 * SIZE:     32
 * FIELDS:
 *     EXT_CABLE_DIAG_LEN_1 EXT_CABLE_DIAG_LEN_1
 *
 ******************************************************************************/
#define BCM54282_EXT_CABLE_DIAG_LEN_1r (0x000f1215 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EXT_CABLE_DIAG_LEN_1r_SIZE 4

/*
 * This structure should be used to declare and program EXT_CABLE_DIAG_LEN_1.
 *
 */
typedef union BCM54282_EXT_CABLE_DIAG_LEN_1r_s {
	uint32_t v[1];
	uint32_t ext_cable_diag_len_1[1];
	uint32_t _ext_cable_diag_len_1;
} BCM54282_EXT_CABLE_DIAG_LEN_1r_t;

#define BCM54282_EXT_CABLE_DIAG_LEN_1r_CLR(r) (r).ext_cable_diag_len_1[0] = 0
#define BCM54282_EXT_CABLE_DIAG_LEN_1r_SET(r,d) (r).ext_cable_diag_len_1[0] = d
#define BCM54282_EXT_CABLE_DIAG_LEN_1r_GET(r) (r).ext_cable_diag_len_1[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EXT_CABLE_DIAG_LEN_1r_EXT_CABLE_DIAG_LEN_1f_GET(r) (((r).ext_cable_diag_len_1[0]) & 0xffff)
#define BCM54282_EXT_CABLE_DIAG_LEN_1r_EXT_CABLE_DIAG_LEN_1f_SET(r,f) (r).ext_cable_diag_len_1[0]=(((r).ext_cable_diag_len_1[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access EXT_CABLE_DIAG_LEN_1.
 *
 */
#define BCM54282_READ_EXT_CABLE_DIAG_LEN_1r(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EXT_CABLE_DIAG_LEN_1r,(_r._ext_cable_diag_len_1))
#define BCM54282_WRITE_EXT_CABLE_DIAG_LEN_1r(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EXT_CABLE_DIAG_LEN_1r,(_r._ext_cable_diag_len_1))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EXT_CABLE_DIAG_LEN_1r BCM54282_EXT_CABLE_DIAG_LEN_1r
#define EXT_CABLE_DIAG_LEN_1r_SIZE BCM54282_EXT_CABLE_DIAG_LEN_1r_SIZE
typedef BCM54282_EXT_CABLE_DIAG_LEN_1r_t EXT_CABLE_DIAG_LEN_1r_t;
#define EXT_CABLE_DIAG_LEN_1r_CLR BCM54282_EXT_CABLE_DIAG_LEN_1r_CLR
#define EXT_CABLE_DIAG_LEN_1r_SET BCM54282_EXT_CABLE_DIAG_LEN_1r_SET
#define EXT_CABLE_DIAG_LEN_1r_GET BCM54282_EXT_CABLE_DIAG_LEN_1r_GET
#define EXT_CABLE_DIAG_LEN_1r_EXT_CABLE_DIAG_LEN_1f_GET BCM54282_EXT_CABLE_DIAG_LEN_1r_EXT_CABLE_DIAG_LEN_1f_GET
#define EXT_CABLE_DIAG_LEN_1r_EXT_CABLE_DIAG_LEN_1f_SET BCM54282_EXT_CABLE_DIAG_LEN_1r_EXT_CABLE_DIAG_LEN_1f_SET
#define READ_EXT_CABLE_DIAG_LEN_1r BCM54282_READ_EXT_CABLE_DIAG_LEN_1r
#define WRITE_EXT_CABLE_DIAG_LEN_1r BCM54282_WRITE_EXT_CABLE_DIAG_LEN_1r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EXT_CABLE_DIAG_LEN_1r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EXT_CABLE_DIAG_LEN_2
 * BLOCKS:   USER
 * REGADDR:  0x0015
 * DESC:     Cable Diagnostics Lengths 2 (Addr 13h)
 * SIZE:     32
 * FIELDS:
 *     EXT_CABLE_DIAG_LEN_2 EXT_CABLE_DIAG_LEN_2
 *
 ******************************************************************************/
#define BCM54282_EXT_CABLE_DIAG_LEN_2r (0x000f1315 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EXT_CABLE_DIAG_LEN_2r_SIZE 4

/*
 * This structure should be used to declare and program EXT_CABLE_DIAG_LEN_2.
 *
 */
typedef union BCM54282_EXT_CABLE_DIAG_LEN_2r_s {
	uint32_t v[1];
	uint32_t ext_cable_diag_len_2[1];
	uint32_t _ext_cable_diag_len_2;
} BCM54282_EXT_CABLE_DIAG_LEN_2r_t;

#define BCM54282_EXT_CABLE_DIAG_LEN_2r_CLR(r) (r).ext_cable_diag_len_2[0] = 0
#define BCM54282_EXT_CABLE_DIAG_LEN_2r_SET(r,d) (r).ext_cable_diag_len_2[0] = d
#define BCM54282_EXT_CABLE_DIAG_LEN_2r_GET(r) (r).ext_cable_diag_len_2[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EXT_CABLE_DIAG_LEN_2r_EXT_CABLE_DIAG_LEN_2f_GET(r) (((r).ext_cable_diag_len_2[0]) & 0xffff)
#define BCM54282_EXT_CABLE_DIAG_LEN_2r_EXT_CABLE_DIAG_LEN_2f_SET(r,f) (r).ext_cable_diag_len_2[0]=(((r).ext_cable_diag_len_2[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access EXT_CABLE_DIAG_LEN_2.
 *
 */
#define BCM54282_READ_EXT_CABLE_DIAG_LEN_2r(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EXT_CABLE_DIAG_LEN_2r,(_r._ext_cable_diag_len_2))
#define BCM54282_WRITE_EXT_CABLE_DIAG_LEN_2r(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EXT_CABLE_DIAG_LEN_2r,(_r._ext_cable_diag_len_2))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EXT_CABLE_DIAG_LEN_2r BCM54282_EXT_CABLE_DIAG_LEN_2r
#define EXT_CABLE_DIAG_LEN_2r_SIZE BCM54282_EXT_CABLE_DIAG_LEN_2r_SIZE
typedef BCM54282_EXT_CABLE_DIAG_LEN_2r_t EXT_CABLE_DIAG_LEN_2r_t;
#define EXT_CABLE_DIAG_LEN_2r_CLR BCM54282_EXT_CABLE_DIAG_LEN_2r_CLR
#define EXT_CABLE_DIAG_LEN_2r_SET BCM54282_EXT_CABLE_DIAG_LEN_2r_SET
#define EXT_CABLE_DIAG_LEN_2r_GET BCM54282_EXT_CABLE_DIAG_LEN_2r_GET
#define EXT_CABLE_DIAG_LEN_2r_EXT_CABLE_DIAG_LEN_2f_GET BCM54282_EXT_CABLE_DIAG_LEN_2r_EXT_CABLE_DIAG_LEN_2f_GET
#define EXT_CABLE_DIAG_LEN_2r_EXT_CABLE_DIAG_LEN_2f_SET BCM54282_EXT_CABLE_DIAG_LEN_2r_EXT_CABLE_DIAG_LEN_2f_SET
#define READ_EXT_CABLE_DIAG_LEN_2r BCM54282_READ_EXT_CABLE_DIAG_LEN_2r
#define WRITE_EXT_CABLE_DIAG_LEN_2r BCM54282_WRITE_EXT_CABLE_DIAG_LEN_2r

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EXT_CABLE_DIAG_LEN_2r'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EXP_OPT_MODE_STAT
 * BLOCKS:   USER
 * REGADDR:  0x0015
 * DESC:     Operating Mode Status Register (Addr 42h)
 * SIZE:     32
 * FIELDS:
 *     OP_MODE_STAT     Operating mode
 *     COPPER_ENG_DET   Copper energy detect
 *     COPPER_DUPLEX    Copper duplex
 *     COPPER_SPEED     Copper speed
 *     FIBER_DUPLEX     Fiber duplex
 *
 ******************************************************************************/
#define BCM54282_EXP_OPT_MODE_STATr (0x000f4215 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EXP_OPT_MODE_STATr_SIZE 4

/*
 * This structure should be used to declare and program EXP_OPT_MODE_STAT.
 *
 */
typedef union BCM54282_EXP_OPT_MODE_STATr_s {
	uint32_t v[1];
	uint32_t exp_opt_mode_stat[1];
	uint32_t _exp_opt_mode_stat;
} BCM54282_EXP_OPT_MODE_STATr_t;

#define BCM54282_EXP_OPT_MODE_STATr_CLR(r) (r).exp_opt_mode_stat[0] = 0
#define BCM54282_EXP_OPT_MODE_STATr_SET(r,d) (r).exp_opt_mode_stat[0] = d
#define BCM54282_EXP_OPT_MODE_STATr_GET(r) (r).exp_opt_mode_stat[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EXP_OPT_MODE_STATr_FIBER_DUPLEXf_GET(r) ((((r).exp_opt_mode_stat[0]) >> 12) & 0x1)
#define BCM54282_EXP_OPT_MODE_STATr_FIBER_DUPLEXf_SET(r,f) (r).exp_opt_mode_stat[0]=(((r).exp_opt_mode_stat[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_EXP_OPT_MODE_STATr_COPPER_SPEEDf_GET(r) ((((r).exp_opt_mode_stat[0]) >> 9) & 0x7)
#define BCM54282_EXP_OPT_MODE_STATr_COPPER_SPEEDf_SET(r,f) (r).exp_opt_mode_stat[0]=(((r).exp_opt_mode_stat[0] & ~((uint32_t)0x7 << 9)) | ((((uint32_t)f) & 0x7) << 9))
#define BCM54282_EXP_OPT_MODE_STATr_COPPER_DUPLEXf_GET(r) ((((r).exp_opt_mode_stat[0]) >> 8) & 0x1)
#define BCM54282_EXP_OPT_MODE_STATr_COPPER_DUPLEXf_SET(r,f) (r).exp_opt_mode_stat[0]=(((r).exp_opt_mode_stat[0] & ~((uint32_t)0x1 << 8)) | ((((uint32_t)f) & 0x1) << 8))
#define BCM54282_EXP_OPT_MODE_STATr_COPPER_ENG_DETf_GET(r) ((((r).exp_opt_mode_stat[0]) >> 7) & 0x1)
#define BCM54282_EXP_OPT_MODE_STATr_COPPER_ENG_DETf_SET(r,f) (r).exp_opt_mode_stat[0]=(((r).exp_opt_mode_stat[0] & ~((uint32_t)0x1 << 7)) | ((((uint32_t)f) & 0x1) << 7))
#define BCM54282_EXP_OPT_MODE_STATr_OP_MODE_STATf_GET(r) (((r).exp_opt_mode_stat[0]) & 0x1f)
#define BCM54282_EXP_OPT_MODE_STATr_OP_MODE_STATf_SET(r,f) (r).exp_opt_mode_stat[0]=(((r).exp_opt_mode_stat[0] & ~((uint32_t)0x1f)) | (((uint32_t)f) & 0x1f))

/*
 * These macros can be used to access EXP_OPT_MODE_STAT.
 *
 */
#define BCM54282_READ_EXP_OPT_MODE_STATr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EXP_OPT_MODE_STATr,(_r._exp_opt_mode_stat))
#define BCM54282_WRITE_EXP_OPT_MODE_STATr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EXP_OPT_MODE_STATr,(_r._exp_opt_mode_stat))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EXP_OPT_MODE_STATr BCM54282_EXP_OPT_MODE_STATr
#define EXP_OPT_MODE_STATr_SIZE BCM54282_EXP_OPT_MODE_STATr_SIZE
typedef BCM54282_EXP_OPT_MODE_STATr_t EXP_OPT_MODE_STATr_t;
#define EXP_OPT_MODE_STATr_CLR BCM54282_EXP_OPT_MODE_STATr_CLR
#define EXP_OPT_MODE_STATr_SET BCM54282_EXP_OPT_MODE_STATr_SET
#define EXP_OPT_MODE_STATr_GET BCM54282_EXP_OPT_MODE_STATr_GET
#define EXP_OPT_MODE_STATr_FIBER_DUPLEXf_GET BCM54282_EXP_OPT_MODE_STATr_FIBER_DUPLEXf_GET
#define EXP_OPT_MODE_STATr_FIBER_DUPLEXf_SET BCM54282_EXP_OPT_MODE_STATr_FIBER_DUPLEXf_SET
#define EXP_OPT_MODE_STATr_COPPER_SPEEDf_GET BCM54282_EXP_OPT_MODE_STATr_COPPER_SPEEDf_GET
#define EXP_OPT_MODE_STATr_COPPER_SPEEDf_SET BCM54282_EXP_OPT_MODE_STATr_COPPER_SPEEDf_SET
#define EXP_OPT_MODE_STATr_COPPER_DUPLEXf_GET BCM54282_EXP_OPT_MODE_STATr_COPPER_DUPLEXf_GET
#define EXP_OPT_MODE_STATr_COPPER_DUPLEXf_SET BCM54282_EXP_OPT_MODE_STATr_COPPER_DUPLEXf_SET
#define EXP_OPT_MODE_STATr_COPPER_ENG_DETf_GET BCM54282_EXP_OPT_MODE_STATr_COPPER_ENG_DETf_GET
#define EXP_OPT_MODE_STATr_COPPER_ENG_DETf_SET BCM54282_EXP_OPT_MODE_STATr_COPPER_ENG_DETf_SET
#define EXP_OPT_MODE_STATr_OP_MODE_STATf_GET BCM54282_EXP_OPT_MODE_STATr_OP_MODE_STATf_GET
#define EXP_OPT_MODE_STATr_OP_MODE_STATf_SET BCM54282_EXP_OPT_MODE_STATr_OP_MODE_STATf_SET
#define READ_EXP_OPT_MODE_STATr BCM54282_READ_EXP_OPT_MODE_STATr
#define WRITE_EXP_OPT_MODE_STATr BCM54282_WRITE_EXP_OPT_MODE_STATr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EXP_OPT_MODE_STATr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EXP_PATT_GEN_STAT
 * BLOCKS:   USER
 * REGADDR:  0x0015
 * DESC:     Mode Gen Status Register (Addr 46h)
 * SIZE:     32
 * FIELDS:
 *     PAT_GEN_FSM      
 *     PAT_GEN_ACTIVE   Pattern generator is still sending packets/idle
 *     RGMII_FIFO_FREQ_LOCK RGMII FIFO in 10/100 copper mode or 100FX (SerDes).
 *     CR_EXT           Send a carrier extension.
 *     PKT_SIZE_6       Increase pattern generator packet size.
 *     GMII_RGMII_FIFO_ELASTICITY_1 GMII/RGMII FIFO ELASTICITY in copper mode or RGMII 100FX on SerDes pads.
 *     GMII_FIFO_ELASTICITY_1 GMII FIFO ELASTICITY in SGMII/Media Converter Mode mode.
 *
 ******************************************************************************/
#define BCM54282_EXP_PATT_GEN_STATr (0x000f4615 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EXP_PATT_GEN_STATr_SIZE 4

/*
 * This structure should be used to declare and program EXP_PATT_GEN_STAT.
 *
 */
typedef union BCM54282_EXP_PATT_GEN_STATr_s {
	uint32_t v[1];
	uint32_t exp_patt_gen_stat[1];
	uint32_t _exp_patt_gen_stat;
} BCM54282_EXP_PATT_GEN_STATr_t;

#define BCM54282_EXP_PATT_GEN_STATr_CLR(r) (r).exp_patt_gen_stat[0] = 0
#define BCM54282_EXP_PATT_GEN_STATr_SET(r,d) (r).exp_patt_gen_stat[0] = d
#define BCM54282_EXP_PATT_GEN_STATr_GET(r) (r).exp_patt_gen_stat[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EXP_PATT_GEN_STATr_GMII_FIFO_ELASTICITY_1f_GET(r) ((((r).exp_patt_gen_stat[0]) >> 15) & 0x1)
#define BCM54282_EXP_PATT_GEN_STATr_GMII_FIFO_ELASTICITY_1f_SET(r,f) (r).exp_patt_gen_stat[0]=(((r).exp_patt_gen_stat[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_EXP_PATT_GEN_STATr_GMII_RGMII_FIFO_ELASTICITY_1f_GET(r) ((((r).exp_patt_gen_stat[0]) >> 14) & 0x1)
#define BCM54282_EXP_PATT_GEN_STATr_GMII_RGMII_FIFO_ELASTICITY_1f_SET(r,f) (r).exp_patt_gen_stat[0]=(((r).exp_patt_gen_stat[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_EXP_PATT_GEN_STATr_PKT_SIZE_6f_GET(r) ((((r).exp_patt_gen_stat[0]) >> 13) & 0x1)
#define BCM54282_EXP_PATT_GEN_STATr_PKT_SIZE_6f_SET(r,f) (r).exp_patt_gen_stat[0]=(((r).exp_patt_gen_stat[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_EXP_PATT_GEN_STATr_CR_EXTf_GET(r) ((((r).exp_patt_gen_stat[0]) >> 12) & 0x1)
#define BCM54282_EXP_PATT_GEN_STATr_CR_EXTf_SET(r,f) (r).exp_patt_gen_stat[0]=(((r).exp_patt_gen_stat[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_EXP_PATT_GEN_STATr_RGMII_FIFO_FREQ_LOCKf_GET(r) ((((r).exp_patt_gen_stat[0]) >> 6) & 0x1)
#define BCM54282_EXP_PATT_GEN_STATr_RGMII_FIFO_FREQ_LOCKf_SET(r,f) (r).exp_patt_gen_stat[0]=(((r).exp_patt_gen_stat[0] & ~((uint32_t)0x1 << 6)) | ((((uint32_t)f) & 0x1) << 6))
#define BCM54282_EXP_PATT_GEN_STATr_PAT_GEN_ACTIVEf_GET(r) ((((r).exp_patt_gen_stat[0]) >> 3) & 0x1)
#define BCM54282_EXP_PATT_GEN_STATr_PAT_GEN_ACTIVEf_SET(r,f) (r).exp_patt_gen_stat[0]=(((r).exp_patt_gen_stat[0] & ~((uint32_t)0x1 << 3)) | ((((uint32_t)f) & 0x1) << 3))
#define BCM54282_EXP_PATT_GEN_STATr_PAT_GEN_FSMf_GET(r) (((r).exp_patt_gen_stat[0]) & 0x7)
#define BCM54282_EXP_PATT_GEN_STATr_PAT_GEN_FSMf_SET(r,f) (r).exp_patt_gen_stat[0]=(((r).exp_patt_gen_stat[0] & ~((uint32_t)0x7)) | (((uint32_t)f) & 0x7))

/*
 * These macros can be used to access EXP_PATT_GEN_STAT.
 *
 */
#define BCM54282_READ_EXP_PATT_GEN_STATr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EXP_PATT_GEN_STATr,(_r._exp_patt_gen_stat))
#define BCM54282_WRITE_EXP_PATT_GEN_STATr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EXP_PATT_GEN_STATr,(_r._exp_patt_gen_stat))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EXP_PATT_GEN_STATr BCM54282_EXP_PATT_GEN_STATr
#define EXP_PATT_GEN_STATr_SIZE BCM54282_EXP_PATT_GEN_STATr_SIZE
typedef BCM54282_EXP_PATT_GEN_STATr_t EXP_PATT_GEN_STATr_t;
#define EXP_PATT_GEN_STATr_CLR BCM54282_EXP_PATT_GEN_STATr_CLR
#define EXP_PATT_GEN_STATr_SET BCM54282_EXP_PATT_GEN_STATr_SET
#define EXP_PATT_GEN_STATr_GET BCM54282_EXP_PATT_GEN_STATr_GET
#define EXP_PATT_GEN_STATr_GMII_FIFO_ELASTICITY_1f_GET BCM54282_EXP_PATT_GEN_STATr_GMII_FIFO_ELASTICITY_1f_GET
#define EXP_PATT_GEN_STATr_GMII_FIFO_ELASTICITY_1f_SET BCM54282_EXP_PATT_GEN_STATr_GMII_FIFO_ELASTICITY_1f_SET
#define EXP_PATT_GEN_STATr_GMII_RGMII_FIFO_ELASTICITY_1f_GET BCM54282_EXP_PATT_GEN_STATr_GMII_RGMII_FIFO_ELASTICITY_1f_GET
#define EXP_PATT_GEN_STATr_GMII_RGMII_FIFO_ELASTICITY_1f_SET BCM54282_EXP_PATT_GEN_STATr_GMII_RGMII_FIFO_ELASTICITY_1f_SET
#define EXP_PATT_GEN_STATr_PKT_SIZE_6f_GET BCM54282_EXP_PATT_GEN_STATr_PKT_SIZE_6f_GET
#define EXP_PATT_GEN_STATr_PKT_SIZE_6f_SET BCM54282_EXP_PATT_GEN_STATr_PKT_SIZE_6f_SET
#define EXP_PATT_GEN_STATr_CR_EXTf_GET BCM54282_EXP_PATT_GEN_STATr_CR_EXTf_GET
#define EXP_PATT_GEN_STATr_CR_EXTf_SET BCM54282_EXP_PATT_GEN_STATr_CR_EXTf_SET
#define EXP_PATT_GEN_STATr_RGMII_FIFO_FREQ_LOCKf_GET BCM54282_EXP_PATT_GEN_STATr_RGMII_FIFO_FREQ_LOCKf_GET
#define EXP_PATT_GEN_STATr_RGMII_FIFO_FREQ_LOCKf_SET BCM54282_EXP_PATT_GEN_STATr_RGMII_FIFO_FREQ_LOCKf_SET
#define EXP_PATT_GEN_STATr_PAT_GEN_ACTIVEf_GET BCM54282_EXP_PATT_GEN_STATr_PAT_GEN_ACTIVEf_GET
#define EXP_PATT_GEN_STATr_PAT_GEN_ACTIVEf_SET BCM54282_EXP_PATT_GEN_STATr_PAT_GEN_ACTIVEf_SET
#define EXP_PATT_GEN_STATr_PAT_GEN_FSMf_GET BCM54282_EXP_PATT_GEN_STATr_PAT_GEN_FSMf_GET
#define EXP_PATT_GEN_STATr_PAT_GEN_FSMf_SET BCM54282_EXP_PATT_GEN_STATr_PAT_GEN_FSMf_SET
#define READ_EXP_PATT_GEN_STATr BCM54282_READ_EXP_PATT_GEN_STATr
#define WRITE_EXP_PATT_GEN_STATr BCM54282_WRITE_EXP_PATT_GEN_STATr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EXP_PATT_GEN_STATr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EXP_AMP_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x0015
 * DESC:     Amplitude Control Register (Addr 51h)
 * SIZE:     32
 * FIELDS:
 *     EXP_AMP_CTRL     EXP_AMP_CTRL
 *
 ******************************************************************************/
#define BCM54282_EXP_AMP_CTRLr (0x000f5215 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EXP_AMP_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program EXP_AMP_CTRL.
 *
 */
typedef union BCM54282_EXP_AMP_CTRLr_s {
	uint32_t v[1];
	uint32_t exp_amp_ctrl[1];
	uint32_t _exp_amp_ctrl;
} BCM54282_EXP_AMP_CTRLr_t;

#define BCM54282_EXP_AMP_CTRLr_CLR(r) (r).exp_amp_ctrl[0] = 0
#define BCM54282_EXP_AMP_CTRLr_SET(r,d) (r).exp_amp_ctrl[0] = d
#define BCM54282_EXP_AMP_CTRLr_GET(r) (r).exp_amp_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EXP_AMP_CTRLr_EXP_AMP_CTRLf_GET(r) (((r).exp_amp_ctrl[0]) & 0xffff)
#define BCM54282_EXP_AMP_CTRLr_EXP_AMP_CTRLf_SET(r,f) (r).exp_amp_ctrl[0]=(((r).exp_amp_ctrl[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access EXP_AMP_CTRL.
 *
 */
#define BCM54282_READ_EXP_AMP_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EXP_AMP_CTRLr,(_r._exp_amp_ctrl))
#define BCM54282_WRITE_EXP_AMP_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EXP_AMP_CTRLr,(_r._exp_amp_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EXP_AMP_CTRLr BCM54282_EXP_AMP_CTRLr
#define EXP_AMP_CTRLr_SIZE BCM54282_EXP_AMP_CTRLr_SIZE
typedef BCM54282_EXP_AMP_CTRLr_t EXP_AMP_CTRLr_t;
#define EXP_AMP_CTRLr_CLR BCM54282_EXP_AMP_CTRLr_CLR
#define EXP_AMP_CTRLr_SET BCM54282_EXP_AMP_CTRLr_SET
#define EXP_AMP_CTRLr_GET BCM54282_EXP_AMP_CTRLr_GET
#define EXP_AMP_CTRLr_EXP_AMP_CTRLf_GET BCM54282_EXP_AMP_CTRLr_EXP_AMP_CTRLf_GET
#define EXP_AMP_CTRLr_EXP_AMP_CTRLf_SET BCM54282_EXP_AMP_CTRLr_EXP_AMP_CTRLf_SET
#define READ_EXP_AMP_CTRLr BCM54282_READ_EXP_AMP_CTRLr
#define WRITE_EXP_AMP_CTRLr BCM54282_WRITE_EXP_AMP_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EXP_AMP_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EXP_SGOUT_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x0015
 * DESC:     SGOUT Control Register (Addr 52h)
 * SIZE:     32
 * FIELDS:
 *     EXP_SGOUT_CTRL   EXP_SGOUT_CTRL
 *
 ******************************************************************************/
#define BCM54282_EXP_SGOUT_CTRLr (0x000f5215 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EXP_SGOUT_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program EXP_SGOUT_CTRL.
 *
 */
typedef union BCM54282_EXP_SGOUT_CTRLr_s {
	uint32_t v[1];
	uint32_t exp_sgout_ctrl[1];
	uint32_t _exp_sgout_ctrl;
} BCM54282_EXP_SGOUT_CTRLr_t;

#define BCM54282_EXP_SGOUT_CTRLr_CLR(r) (r).exp_sgout_ctrl[0] = 0
#define BCM54282_EXP_SGOUT_CTRLr_SET(r,d) (r).exp_sgout_ctrl[0] = d
#define BCM54282_EXP_SGOUT_CTRLr_GET(r) (r).exp_sgout_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EXP_SGOUT_CTRLr_EXP_SGOUT_CTRLf_GET(r) (((r).exp_sgout_ctrl[0]) & 0xffff)
#define BCM54282_EXP_SGOUT_CTRLr_EXP_SGOUT_CTRLf_SET(r,f) (r).exp_sgout_ctrl[0]=(((r).exp_sgout_ctrl[0] & ~((uint32_t)0xffff)) | (((uint32_t)f) & 0xffff))

/*
 * These macros can be used to access EXP_SGOUT_CTRL.
 *
 */
#define BCM54282_READ_EXP_SGOUT_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EXP_SGOUT_CTRLr,(_r._exp_sgout_ctrl))
#define BCM54282_WRITE_EXP_SGOUT_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EXP_SGOUT_CTRLr,(_r._exp_sgout_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EXP_SGOUT_CTRLr BCM54282_EXP_SGOUT_CTRLr
#define EXP_SGOUT_CTRLr_SIZE BCM54282_EXP_SGOUT_CTRLr_SIZE
typedef BCM54282_EXP_SGOUT_CTRLr_t EXP_SGOUT_CTRLr_t;
#define EXP_SGOUT_CTRLr_CLR BCM54282_EXP_SGOUT_CTRLr_CLR
#define EXP_SGOUT_CTRLr_SET BCM54282_EXP_SGOUT_CTRLr_SET
#define EXP_SGOUT_CTRLr_GET BCM54282_EXP_SGOUT_CTRLr_GET
#define EXP_SGOUT_CTRLr_EXP_SGOUT_CTRLf_GET BCM54282_EXP_SGOUT_CTRLr_EXP_SGOUT_CTRLf_GET
#define EXP_SGOUT_CTRLr_EXP_SGOUT_CTRLf_SET BCM54282_EXP_SGOUT_CTRLr_EXP_SGOUT_CTRLf_SET
#define READ_EXP_SGOUT_CTRLr BCM54282_READ_EXP_SGOUT_CTRLr
#define WRITE_EXP_SGOUT_CTRLr BCM54282_WRITE_EXP_SGOUT_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EXP_SGOUT_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EEE_STAT_CTRL
 * BLOCKS:   USER
 * REGADDR:  0x0015
 * DESC:     EEE Status Control Register (Addr afh)
 * SIZE:     32
 * FIELDS:
 *     STATISTIC_COUNTERS_ENABLE Statistic counters enable/disabe.
 *     STATISTIC_COUNTERS_RESET EEE Statistic Counter soft reset.
 *     RESERVED0        Reserved.
 *     RESERVED1        Reserved. Must be set to 0.
 *     STATISTIC_SATURATE_MODE Statistic counters mode.
 *     STATISTIC_UPPER_16BITS_SEL 16-bit statistic counter registers.
 *     STATISTIC_1000BT_MODE Statistic counters are in 1000BASE-T/100BASE-T mode.
 *
 ******************************************************************************/
#define BCM54282_EEE_STAT_CTRLr (0x000faf15 | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EEE_STAT_CTRLr_SIZE 4

/*
 * This structure should be used to declare and program EEE_STAT_CTRL.
 *
 */
typedef union BCM54282_EEE_STAT_CTRLr_s {
	uint32_t v[1];
	uint32_t eee_stat_ctrl[1];
	uint32_t _eee_stat_ctrl;
} BCM54282_EEE_STAT_CTRLr_t;

#define BCM54282_EEE_STAT_CTRLr_CLR(r) (r).eee_stat_ctrl[0] = 0
#define BCM54282_EEE_STAT_CTRLr_SET(r,d) (r).eee_stat_ctrl[0] = d
#define BCM54282_EEE_STAT_CTRLr_GET(r) (r).eee_stat_ctrl[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EEE_STAT_CTRLr_STATISTIC_1000BT_MODEf_GET(r) ((((r).eee_stat_ctrl[0]) >> 15) & 0x1)
#define BCM54282_EEE_STAT_CTRLr_STATISTIC_1000BT_MODEf_SET(r,f) (r).eee_stat_ctrl[0]=(((r).eee_stat_ctrl[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_EEE_STAT_CTRLr_STATISTIC_UPPER_16BITS_SELf_GET(r) ((((r).eee_stat_ctrl[0]) >> 14) & 0x1)
#define BCM54282_EEE_STAT_CTRLr_STATISTIC_UPPER_16BITS_SELf_SET(r,f) (r).eee_stat_ctrl[0]=(((r).eee_stat_ctrl[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))
#define BCM54282_EEE_STAT_CTRLr_STATISTIC_SATURATE_MODEf_GET(r) ((((r).eee_stat_ctrl[0]) >> 13) & 0x1)
#define BCM54282_EEE_STAT_CTRLr_STATISTIC_SATURATE_MODEf_SET(r,f) (r).eee_stat_ctrl[0]=(((r).eee_stat_ctrl[0] & ~((uint32_t)0x1 << 13)) | ((((uint32_t)f) & 0x1) << 13))
#define BCM54282_EEE_STAT_CTRLr_RESERVED1f_GET(r) ((((r).eee_stat_ctrl[0]) >> 12) & 0x1)
#define BCM54282_EEE_STAT_CTRLr_RESERVED1f_SET(r,f) (r).eee_stat_ctrl[0]=(((r).eee_stat_ctrl[0] & ~((uint32_t)0x1 << 12)) | ((((uint32_t)f) & 0x1) << 12))
#define BCM54282_EEE_STAT_CTRLr_RESERVED0f_GET(r) ((((r).eee_stat_ctrl[0]) >> 2) & 0x3ff)
#define BCM54282_EEE_STAT_CTRLr_RESERVED0f_SET(r,f) (r).eee_stat_ctrl[0]=(((r).eee_stat_ctrl[0] & ~((uint32_t)0x3ff << 2)) | ((((uint32_t)f) & 0x3ff) << 2))
#define BCM54282_EEE_STAT_CTRLr_STATISTIC_COUNTERS_RESETf_GET(r) ((((r).eee_stat_ctrl[0]) >> 1) & 0x1)
#define BCM54282_EEE_STAT_CTRLr_STATISTIC_COUNTERS_RESETf_SET(r,f) (r).eee_stat_ctrl[0]=(((r).eee_stat_ctrl[0] & ~((uint32_t)0x1 << 1)) | ((((uint32_t)f) & 0x1) << 1))
#define BCM54282_EEE_STAT_CTRLr_STATISTIC_COUNTERS_ENABLEf_GET(r) (((r).eee_stat_ctrl[0]) & 0x1)
#define BCM54282_EEE_STAT_CTRLr_STATISTIC_COUNTERS_ENABLEf_SET(r,f) (r).eee_stat_ctrl[0]=(((r).eee_stat_ctrl[0] & ~((uint32_t)0x1)) | (((uint32_t)f) & 0x1))

/*
 * These macros can be used to access EEE_STAT_CTRL.
 *
 */
#define BCM54282_READ_EEE_STAT_CTRLr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EEE_STAT_CTRLr,(_r._eee_stat_ctrl))
#define BCM54282_WRITE_EEE_STAT_CTRLr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EEE_STAT_CTRLr,(_r._eee_stat_ctrl))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EEE_STAT_CTRLr BCM54282_EEE_STAT_CTRLr
#define EEE_STAT_CTRLr_SIZE BCM54282_EEE_STAT_CTRLr_SIZE
typedef BCM54282_EEE_STAT_CTRLr_t EEE_STAT_CTRLr_t;
#define EEE_STAT_CTRLr_CLR BCM54282_EEE_STAT_CTRLr_CLR
#define EEE_STAT_CTRLr_SET BCM54282_EEE_STAT_CTRLr_SET
#define EEE_STAT_CTRLr_GET BCM54282_EEE_STAT_CTRLr_GET
#define EEE_STAT_CTRLr_STATISTIC_1000BT_MODEf_GET BCM54282_EEE_STAT_CTRLr_STATISTIC_1000BT_MODEf_GET
#define EEE_STAT_CTRLr_STATISTIC_1000BT_MODEf_SET BCM54282_EEE_STAT_CTRLr_STATISTIC_1000BT_MODEf_SET
#define EEE_STAT_CTRLr_STATISTIC_UPPER_16BITS_SELf_GET BCM54282_EEE_STAT_CTRLr_STATISTIC_UPPER_16BITS_SELf_GET
#define EEE_STAT_CTRLr_STATISTIC_UPPER_16BITS_SELf_SET BCM54282_EEE_STAT_CTRLr_STATISTIC_UPPER_16BITS_SELf_SET
#define EEE_STAT_CTRLr_STATISTIC_SATURATE_MODEf_GET BCM54282_EEE_STAT_CTRLr_STATISTIC_SATURATE_MODEf_GET
#define EEE_STAT_CTRLr_STATISTIC_SATURATE_MODEf_SET BCM54282_EEE_STAT_CTRLr_STATISTIC_SATURATE_MODEf_SET
#define EEE_STAT_CTRLr_RESERVED1f_GET BCM54282_EEE_STAT_CTRLr_RESERVED1f_GET
#define EEE_STAT_CTRLr_RESERVED1f_SET BCM54282_EEE_STAT_CTRLr_RESERVED1f_SET
#define EEE_STAT_CTRLr_RESERVED0f_GET BCM54282_EEE_STAT_CTRLr_RESERVED0f_GET
#define EEE_STAT_CTRLr_RESERVED0f_SET BCM54282_EEE_STAT_CTRLr_RESERVED0f_SET
#define EEE_STAT_CTRLr_STATISTIC_COUNTERS_RESETf_GET BCM54282_EEE_STAT_CTRLr_STATISTIC_COUNTERS_RESETf_GET
#define EEE_STAT_CTRLr_STATISTIC_COUNTERS_RESETf_SET BCM54282_EEE_STAT_CTRLr_STATISTIC_COUNTERS_RESETf_SET
#define EEE_STAT_CTRLr_STATISTIC_COUNTERS_ENABLEf_GET BCM54282_EEE_STAT_CTRLr_STATISTIC_COUNTERS_ENABLEf_GET
#define EEE_STAT_CTRLr_STATISTIC_COUNTERS_ENABLEf_SET BCM54282_EEE_STAT_CTRLr_STATISTIC_COUNTERS_ENABLEf_SET
#define READ_EEE_STAT_CTRLr BCM54282_READ_EEE_STAT_CTRLr
#define WRITE_EEE_STAT_CTRLr BCM54282_WRITE_EEE_STAT_CTRLr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EEE_STAT_CTRLr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EEE_ADV
 * BLOCKS:   USER
 * REGADDR:  0x000e
 * DEVAD:    7
 * DESC:     EEE Advertisment Register (Addr 3ch)
 * SIZE:     32
 * FIELDS:
 *     EEE_100BASE_TX   COPPER_AN_ADVERTISEMENT Register.
 *     EEE_1000BASE_T   1000BASET_CONTROL Register.
 *
 ******************************************************************************/
#define BCM54282_EEE_ADVr (0x07003c0e | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EEE_ADVr_SIZE 4

/*
 * This structure should be used to declare and program EEE_ADV.
 *
 */
typedef union BCM54282_EEE_ADVr_s {
	uint32_t v[1];
	uint32_t eee_adv[1];
	uint32_t _eee_adv;
} BCM54282_EEE_ADVr_t;

#define BCM54282_EEE_ADVr_CLR(r) (r).eee_adv[0] = 0
#define BCM54282_EEE_ADVr_SET(r,d) (r).eee_adv[0] = d
#define BCM54282_EEE_ADVr_GET(r) (r).eee_adv[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EEE_ADVr_EEE_1000BASE_Tf_GET(r) ((((r).eee_adv[0]) >> 2) & 0x1)
#define BCM54282_EEE_ADVr_EEE_1000BASE_Tf_SET(r,f) (r).eee_adv[0]=(((r).eee_adv[0] & ~((uint32_t)0x1 << 2)) | ((((uint32_t)f) & 0x1) << 2))
#define BCM54282_EEE_ADVr_EEE_100BASE_TXf_GET(r) ((((r).eee_adv[0]) >> 1) & 0x1)
#define BCM54282_EEE_ADVr_EEE_100BASE_TXf_SET(r,f) (r).eee_adv[0]=(((r).eee_adv[0] & ~((uint32_t)0x1 << 1)) | ((((uint32_t)f) & 0x1) << 1))

/*
 * These macros can be used to access EEE_ADV.
 *
 */
#define BCM54282_READ_EEE_ADVr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EEE_ADVr,(_r._eee_adv))
#define BCM54282_WRITE_EEE_ADVr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EEE_ADVr,(_r._eee_adv))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EEE_ADVr BCM54282_EEE_ADVr
#define EEE_ADVr_SIZE BCM54282_EEE_ADVr_SIZE
typedef BCM54282_EEE_ADVr_t EEE_ADVr_t;
#define EEE_ADVr_CLR BCM54282_EEE_ADVr_CLR
#define EEE_ADVr_SET BCM54282_EEE_ADVr_SET
#define EEE_ADVr_GET BCM54282_EEE_ADVr_GET
#define EEE_ADVr_EEE_1000BASE_Tf_GET BCM54282_EEE_ADVr_EEE_1000BASE_Tf_GET
#define EEE_ADVr_EEE_1000BASE_Tf_SET BCM54282_EEE_ADVr_EEE_1000BASE_Tf_SET
#define EEE_ADVr_EEE_100BASE_TXf_GET BCM54282_EEE_ADVr_EEE_100BASE_TXf_GET
#define EEE_ADVr_EEE_100BASE_TXf_SET BCM54282_EEE_ADVr_EEE_100BASE_TXf_SET
#define READ_EEE_ADVr BCM54282_READ_EEE_ADVr
#define WRITE_EEE_ADVr BCM54282_WRITE_EEE_ADVr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EEE_ADVr'
 ******************************************************************************/




/*******************************************************************************
 * CHIP:  BCM54282
 * REGISTER:  EEE_803D
 * BLOCKS:   USER
 * REGADDR:  0x000e
 * DEVAD:    7
 * DESC:     EEE 803d Register (Addr 803dh)
 * SIZE:     32
 * FIELDS:
 *     EEE_CAPABILITY_USING_QSGMII_AN Enable EEE capability using QSGMII autonegotiation
 *     LPI_FEATURE_ENABLE LPI Feature Enable
 *
 ******************************************************************************/
#define BCM54282_EEE_803Dr (0x07803d0e | PHY_REG_ACC_BRCM_SHADOW)

#define BCM54282_EEE_803Dr_SIZE 4

/*
 * This structure should be used to declare and program EEE_803D.
 *
 */
typedef union BCM54282_EEE_803Dr_s {
	uint32_t v[1];
	uint32_t eee_803d[1];
	uint32_t _eee_803d;
} BCM54282_EEE_803Dr_t;

#define BCM54282_EEE_803Dr_CLR(r) (r).eee_803d[0] = 0
#define BCM54282_EEE_803Dr_SET(r,d) (r).eee_803d[0] = d
#define BCM54282_EEE_803Dr_GET(r) (r).eee_803d[0]

/*
 * These macros can be used to access individual fields.
 *
 */
#define BCM54282_EEE_803Dr_LPI_FEATURE_ENABLEf_GET(r) ((((r).eee_803d[0]) >> 15) & 0x1)
#define BCM54282_EEE_803Dr_LPI_FEATURE_ENABLEf_SET(r,f) (r).eee_803d[0]=(((r).eee_803d[0] & ~((uint32_t)0x1 << 15)) | ((((uint32_t)f) & 0x1) << 15))
#define BCM54282_EEE_803Dr_EEE_CAPABILITY_USING_QSGMII_ANf_GET(r) ((((r).eee_803d[0]) >> 14) & 0x1)
#define BCM54282_EEE_803Dr_EEE_CAPABILITY_USING_QSGMII_ANf_SET(r,f) (r).eee_803d[0]=(((r).eee_803d[0] & ~((uint32_t)0x1 << 14)) | ((((uint32_t)f) & 0x1) << 14))

/*
 * These macros can be used to access EEE_803D.
 *
 */
#define BCM54282_READ_EEE_803Dr(_pc,_r) phy_brcm_shadow_read(_pc,BCM54282_EEE_803Dr,(_r._eee_803d))
#define BCM54282_WRITE_EEE_803Dr(_pc,_r) phy_brcm_shadow_write(_pc,BCM54282_EEE_803Dr,(_r._eee_803d))

/*
 * Unless PHY_EXCLUDE_CHIPLESS_TYPES is defined, all of the above types
 * will be redefined without the chip prefix for easier programming.
 * If multiple chips will be programmed in the same source file, then you should
 * define PHY_EXCLUDE_CHIPLESS_TYPES before including all chip header files
 * and refer to the fully qualified versions.
 *
 */
#ifndef PHY_EXCLUDE_CHIPLESS_TYPES

#define EEE_803Dr BCM54282_EEE_803Dr
#define EEE_803Dr_SIZE BCM54282_EEE_803Dr_SIZE
typedef BCM54282_EEE_803Dr_t EEE_803Dr_t;
#define EEE_803Dr_CLR BCM54282_EEE_803Dr_CLR
#define EEE_803Dr_SET BCM54282_EEE_803Dr_SET
#define EEE_803Dr_GET BCM54282_EEE_803Dr_GET
#define EEE_803Dr_LPI_FEATURE_ENABLEf_GET BCM54282_EEE_803Dr_LPI_FEATURE_ENABLEf_GET
#define EEE_803Dr_LPI_FEATURE_ENABLEf_SET BCM54282_EEE_803Dr_LPI_FEATURE_ENABLEf_SET
#define EEE_803Dr_EEE_CAPABILITY_USING_QSGMII_ANf_GET BCM54282_EEE_803Dr_EEE_CAPABILITY_USING_QSGMII_ANf_GET
#define EEE_803Dr_EEE_CAPABILITY_USING_QSGMII_ANf_SET BCM54282_EEE_803Dr_EEE_CAPABILITY_USING_QSGMII_ANf_SET
#define READ_EEE_803Dr BCM54282_READ_EEE_803Dr
#define WRITE_EEE_803Dr BCM54282_WRITE_EEE_803Dr

#endif /* PHY_EXCLUDE_CHIPLESS_TYPES */
/*******************************************************************************
 * End of 'BCM54282_EEE_803Dr'
 ******************************************************************************/




#endif /* __BCM54282_DEFS_H__ */
