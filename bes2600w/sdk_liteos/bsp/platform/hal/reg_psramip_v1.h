/*
 * Copyright (c) 2021 bestechnic (Shanghai) Technologies CO., LIMITED.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef PSRAM_REG_H
#define PSRAM_REG_H

#include "plat_types.h"

/* ip register */
/* 0x0 */
#define PSRIP_CMD_ADDR_REG_OFFSET 0x0
#define PSRIP_CMD_ADDR_ADDR_SHIFT (8)
#define PSRIP_CMD_ADDR_ADDR_MASK ((0xfffffff)<<PSRIP_CMD_ADDR_ADDR_SHIFT)
#define PSRIP_CMD_ADDR_CMD_SHIFT (0)
#define PSRIP_CMD_ADDR_CMD_MASK ((0xf)<<PSRIP_CMD_ADDR_CMD_SHIFT)

/* 0x4 */
#define PSRIP_ACCSIZE_REG_OFFSET 0x4
#define PSRIP_ACCSIZE_SIZE_SHIFT (0)
#define PSRIP_ACCSIZE_SIZE_MASK ((0xf)<<PSRIP_ACCSIZE_SIZE_SHIFT)

/* 0x8 */
#define PSRIP_TX_DATA_REG_OFFSET 0x8
#define PSRIP_TX_DATA_DATA_SHIFT (0)
#define PSRIP_TX_DATA_DATA_MASK ((0xff)<<PSRIP_TX_DATA_DATA_SHIFT)

/* 0xc */
#define PSRIP_STAT_REG_OFFSET 0x0c
#define PSRIP_STAT_RX_COUNT_SHIFT (4)
#define PSRIP_STAT_RX_COUNT_MASK ((0x1f)<<PSRIP_STAT_RX_COUNT_SHIFT)
#define PSRIP_STAT_RX_EMPTY_SHIFT (3)
#define PSRIP_STAT_RX_EMPTY_MASK ((0x1)<<PSRIP_STAT_RX_EMPTY_SHIFT)
#define PSRIP_STAT_TX_FULL_SHIFT (2)
#define PSRIP_STAT_TX_FULL_MASK ((0x1)<<PSRIP_STAT_TX_FULL_SHIFT)
#define PSRIP_STAT_TX_EMPTY_SHIFT (1)
#define PSRIP_STAT_TX_EMPTY_MASK ((0x1)<<PSRIP_STAT_TX_EMPTY_SHIFT)
#define PSRIP_STAT_BUSY_SHIFT (0)
#define PSRIP_STAT_BUSY_MASK ((0x1)<<PSRIP_STAT_BUSY_SHIFT)

/* 0x10 */
#define PSRIP_RX_DATA_REG_OFFSET 0x10
#define PSRIP_RX_DATA_DATA_SHIFT (0)
#define PSRIP_RX_DATA_DATA_MASK ((0xff)<<PSRIP_RX_DATA_DATA_SHIFT)

/* 0x14 */
#define PSRIP_DUMMY_REG_OFFSET 0x14
#define PSRIP_DUMMY_WAIT_SHIFT (0)
#define PSRIP_DUMMY_WAIT_MASK ((0xf)<<PSRIP_DUMMY_WAIT_SHIFT)

/* 0x18 */
#define PSRIP_FIFOCLR_REG_OFFSET 0x18
#define PSRIP_FIFOCLR_CLR_TX_SHIFT (1)
#define PSRIP_FIFOCLR_CLR_TX_MASK ((0x1)<<PSRIP_FIFOCLR_CLR_TX_SHIFT)
#define PSRIP_FIFOCLR_CLR_RX_SHIFT (0)
#define PSRIP_FIFOCLR_CLR_RX_MASK ((0x1)<<PSRIP_FIFOCLR_CLR_RX_SHIFT)

/* 0x1c */
#define PSRIP_LSPCTRL_REG_OFFSET 0x1c
#define PSRIP_LSPCTRL_LPCSHIWAIT_SHIFT (16)
#define PSRIP_LSPCTRL_LPCSHIWAIT_MASK ((0xffff)<<PSRIP_LSPCTRL_LPCSHIWAIT_SHIFT)
#define PSRIP_LSPCTRL_LPCSLOWWAIT_SHIFT (12)
#define PSRIP_LSPCTRL_LPCSLOWWAIT_MASK ((0xf)<<PSRIP_LSPCTRL_LPCSLOWWAIT_SHIFT)
#define PSRIP_LSPCTRL_RES_SHIFT (8)
#define PSRIP_LSPCTRL_RES_MASK ((0xf)<<PSRIP_LSPCTRL_RES_SHIFT)
#define PSRIP_LSPCTRL_CABCLK90PRE_SHIFT (0)
#define PSRIP_LSPCTRL_CABCLK90PRE_MASK ((0xff)<<PSRIP_LSPCTRL_CABCLK90PRE_SHIFT)

/* removed */
/* 0x20 */
#define PSRIP_PHYOCTR_REG_OFFSET 0x20
#define PSRIP_PHYOCTR_PU_SHIFT (0)
#define PSRIP_PHYOCTR_PU_MASK ((0x1)<<PSRIP_PHYOCTR_PU_SHIFT)

/* 0x24 */
#define PSRIP_MODECALIBR_REG_OFFSET 0x24
#define PSRIP_MODECALIBR_NHS_CLK_PREDIV_SHIFT (16)
#define PSRIP_MODECALIBR_NHS_CLK_PREDIV_MASK ((0xff)<<PSRIP_MODECALIBR_NHS_CLK_PREDIV_SHIFT)
#define PSRIP_MODECALIBR_RES_SHIFT (11)
#define PSRIP_MODECALIBR_RES_MASK ((0x1f)<<PSRIP_MODECALIBR_RES_SHIFT)
#define PSRIP_MODECALIBR_DQS_RD_SEL_SHIFT (8)
#define PSRIP_MODECALIBR_DQS_RD_SEL_MASK ((0x7)<<PSRIP_MODECALIBR_DQS_RD_SEL_SHIFT)
#define PSRIP_MODECALIBR_DQS_WR_SEL_SHIFT (4)
#define PSRIP_MODECALIBR_DQS_WR_SEL_MASK ((0x7)<<PSRIP_MODECALIBR_DQS_WR_SEL_SHIFT)
#define PSRIP_MODECALIBR_CALIBST_SHIFT (3)
#define PSRIP_MODECALIBR_CALIBST_MASK ((0x1)<<PSRIP_MODECALIBR_CALIBST_SHIFT)
#define PSRIP_MODECALIBR_ENABLE_CALIB_SHIFT (1)
#define PSRIP_MODECALIBR_ENABLE_CALIB_MASK ((0x1)<<PSRIP_MODECALIBR_ENABLE_CALIB_SHIFT)
#define PSRIP_MODECALIBR_TRIGGER_SHIFT (0)
#define PSRIP_MODECALIBR_TRIGGER_MASK ((0x1)<<PSRIP_MODECALIBR_TRIGGER_SHIFT)

/* 0x28 */
#define PSRIP_SPWKUPCTRL1_REG_OFFSET 0x28
#define PSRIP_SPWKUPCTRL1_SLPWKUPSTAT_SHIFT (16)
#define PSRIP_SPWKUPCTRL1_SLPWKUPSTAT_MASK ((0x3)<<PSRIP_SPWKUPCTRL1_SLPWKUPSTAT_SHIFT)
#define PSRIP_SPWKUPCTRL1_ONPROCESS_SHIFT (1)
#define PSRIP_SPWKUPCTRL1_ONPROCESS_MASK ((0x1)<<PSRIP_SPWKUPCTRL1_ONPROCESS_SHIFT)
#define PSRIP_SPWKUPCTRL1_SLP_WKUP_SHIFT (0)
#define PSRIP_SPWKUPCTRL1_SLP_WKUP_MASK ((0x1)<<PSRIP_SPWKUPCTRL1_SLP_WKUP_SHIFT)

/* 0x2C */
#define PSRIP_SPWKUPCTRL2_REG_OFFSET 0x2C
#define PSRIP_SPWKUPCTRL2_SLPWKUPSTAT_SHIFT (16)
#define PSRIP_SPWKUPCTRL2_SLPWKUPSTAT_MASK ((0x3)<<PSRIP_SPWKUPCTRL2_SLPWKUPSTAT_SHIFT)
#define PSRIP_SPWKUPCTRL2_HIGH_DENSITY_EN_SHIFT (1)
#define PSRIP_SPWKUPCTRL2_HIGH_DENSITY_EN_MASK ((0x1)<<PSRIP_SPWKUPCTRL2_HIGH_DENSITY_EN_SHIFT)
#define PSRIP_SPWKUPCTRL2_WRAP_MODE_ENABLE_SHIFT (3)
#define PSRIP_SPWKUPCTRL2_WRAP_MODE_ENABLE_MASK ((0x1)<<PSRIP_SPWKUPCTRL2_WRAP_MODE_ENABLE_SHIFT)
#define PSRIP_SPWKUPCTRL2_WRAPTYPE_MODE_SHIFT (2)
#define PSRIP_SPWKUPCTRL2_1KWRAPTYPE_MODE_MASK ((0x1)<<PSRIP_SPWKUPCTRL2_WRAPTYPE_MODE_SHIFT)
#define PSRIP_SPWKUPCTRL2_32BYTEWRAPTYPE_MODE_MASK ((0x1)<<PSRIP_SPWKUPCTRL2_WRAPTYPE_MODE_SHIFT)
#define PSRIP_SPWKUPCTRL2_HS_MODE_SHIFT (0)
#define PSRIP_SPWKUPCTRL2_HS_MODE_MASK ((0x1)<<PSRIP_SPWKUPCTRL2_HS_MODE_SHIFT)

#endif /* PSRAM_REG_H */

