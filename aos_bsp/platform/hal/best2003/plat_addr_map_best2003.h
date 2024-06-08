/***************************************************************************
 *
 * Copyright 2015-2019 BES.
 * All rights reserved. All unpublished rights reserved.
 *
 * No part of this work may be used or reproduced in any form or by any
 * means, or stored in a database or retrieval system, without prior written
 * permission of BES.
 *
 * Use of this work is governed by a license granted by BES.
 * This work contains confidential and proprietary information of
 * BES. which is protected by copyright, trade secret,
 * trademark and other intellectual property rights.
 *
 ****************************************************************************/
#ifndef __PLAT_ADDR_MAP_BEST2003_H__
#define __PLAT_ADDR_MAP_BEST2003_H__

#ifdef __cplusplus
extern "C" {
#endif

#define ROM_BASE                                0x00020000
#define ROMD_BASE                               0x24020000

#ifndef ROM_SIZE
#ifdef FPGA
#define ROM_SIZE                                0x00020000
#else
#define ROM_SIZE                                0x00010000
#endif
#endif

#define RAM0_BASE                               0x20000000
#define RAMX0_BASE                              0x00200000
#define RAM1_BASE                               0x20040000
#define RAMX1_BASE                              0x00240000
#define RAM2_BASE                               0x20080000
#define RAMX2_BASE                              0x00280000
#define RAM3_BASE                               0x20100000
#define RAMX3_BASE                              0x00300000
#define RAM4_BASE                               0x20180000
#define RAMX4_BASE                              0x00380000
#define RAM5_BASE                               0x201C0000
#define RAMX5_BASE                              0x003C0000
#define RAM_BASE                                RAM0_BASE
#define RAMX_BASE                               RAMX0_BASE

#define RAM5_SIZE                               0x00040000

/* total ram6 size is 0x30000 */
#define RAM6_BASE                               0x20200000

#define CODEC_VAD_RAM_BASE                      RAM6_BASE
#define CODEC_VAD_MAX_BUF_SIZE                  0x00030000

#ifdef CODEC_VAD_CFG_BUF_SIZE
#if (CODEC_VAD_CFG_BUF_SIZE & (0x8000 - 1)) || (CODEC_VAD_CFG_BUF_SIZE > CODEC_VAD_MAX_BUF_SIZE)
#error "Bad CODEC_VAD_CFG_BUF_SIZE"
#endif
#define RAM6_SIZE                               (CODEC_VAD_MAX_BUF_SIZE - CODEC_VAD_CFG_BUF_SIZE)
#else
#define RAM6_SIZE                               CODEC_VAD_MAX_BUF_SIZE
#endif

/* rename ram6 for network heap usage */
#ifdef RAMV_EN
#define RAMV_BASE                               RAM6_BASE
#define RAMV_SIZE                               RAM6_SIZE
#endif

#ifdef __BT_RAMRUN__
#define BT_RAMRUN_BASE                           RAM3_BASE
#define BT_RAMRUNX_BASE                          RAMX3_BASE
#endif

#ifdef CP_IN_SAME_EE
#ifndef RAMCPX_SIZE
#define RAMCPX_SIZE                             (RAMX1_BASE - RAMX0_BASE)
#endif
#ifndef RAMCPX_BASE
#define RAMCPX_BASE                             RAMX0_BASE
#endif
#ifndef RAMCP_SIZE
#define RAMCP_SIZE                              (RAM2_BASE - RAM1_BASE)
#endif
#define RAMCP_BASE                              (RAMCPX_BASE + RAMCPX_SIZE - RAMX0_BASE + RAM0_BASE)

#define RAMCP_TOP                               (RAMCP_BASE + RAMCP_SIZE)
#elif defined(CP_AS_SUBSYS) || defined(CHIP_ROLE_CP)
#define RAMCP_SUBSYS_BASE                       RAM0_BASE
#if defined(NO_SUBSYS_RAM)
#ifdef RAMCP_SUBSYS_SIZE
#undef RAMCP_SUBSYS_SIZE
#endif
#define RAMCP_SUBSYS_SIZE                       (0)
#else
#ifndef RAMCP_SUBSYS_SIZE
#define RAMCP_SUBSYS_SIZE                       (RAM2_BASE - RAM0_BASE)
#endif
#endif
#define CP_SUBSYS_MAILBOX_SIZE                  0x20

#if RAMCP_SUBSYS_SIZE != 0
#define CP_SUBSYS_MAILBOX_BASE                  (RAMCP_SUBSYS_BASE + RAMCP_SUBSYS_SIZE - CP_SUBSYS_MAILBOX_SIZE)
#else
#define CP_SUBSYS_MAILBOX_BASE                  (RAM_NC_BASE + RAM_NC_SIZE - CP_SUBSYS_MAILBOX_SIZE)
#endif

#define RAMCP_TOP                               (RAMCP_SUBSYS_BASE + RAMCP_SUBSYS_SIZE)

#if defined(CHIP_ROLE_CP) && defined(NO_SUBSYS_RAM) && (PSRAM_REGION_SIZE > 0)
#define RAM_NC_SIZE                             (0x2000)
#define RAM_NC_BASE                             (PSRAM_NC_REGION_BASE + PSRAM_REGION_SIZE - RAM_NC_SIZE)
#endif

#else
#define RAMCP_TOP                               RAM0_BASE
#endif

#define RAM_TOTAL_SIZE                          (RAM6_BASE + RAM6_SIZE - RAM0_BASE) // 0x00200000
#undef RAM_BASE
#undef RAMX_BASE

#if defined(ARM_CMSE) || defined(ARM_CMNS)
/*MPC: SRAM block size: 0x8000, FLASH block size 0x40000*/
#ifndef RAM_S_SIZE
#define RAM_S_SIZE                              0x00020000
#endif
#define RAM_NSC_SIZE                            0
#ifndef FLASH_S_SIZE
#define FLASH_S_SIZE                            0x00040000
#endif

#define RAM_NS_BASE                             (RAMCP_TOP + RAM_S_SIZE)
#define RAMX_NS_BASE                            (RAMCP_TOP - RAM0_BASE + RAMX0_BASE + RAM_S_SIZE)

#if defined(ARM_CMNS)
#define RAM_BASE                                RAM_NS_BASE
#else
#if ((RAM_S_SIZE) & (0x8000-1))
#error "RAM_S_SIZE should be 0x8000 aligned"
#endif
#if (FLASH_S_SIZE & (0x40000-1))
#error "FLASH_S_SIZE should be 0x40000 aligned"
#endif
#define RAM_BASE                                RAMCP_TOP
#define RAM_SIZE                                RAM_S_SIZE
#ifndef NS_APP_START_OFFSET
#define NS_APP_START_OFFSET                     (FLASH_S_SIZE)
#endif
#ifndef FLASH_REGION_SIZE
#define FLASH_REGION_SIZE                       FLASH_S_SIZE
#endif
#endif
#endif /* defined(ARM_CMSE) || defined(ARM_CMNS) */

#ifndef RAM_BASE
#ifdef CHIP_ROLE_CP
#define RAM_BASE                                RAMCP_SUBSYS_BASE
#else
#define RAM_BASE                                RAMCP_TOP
#endif
#endif
#define RAMX_BASE                               (RAM_BASE - RAM0_BASE + RAMX0_BASE)

#ifndef RAM_SIZE
#ifdef CHIP_ROLE_CP
#define RAM_SIZE                                (CP_SUBSYS_MAILBOX_BASE - RAMCP_SUBSYS_BASE)
#elif defined(CP_AS_SUBSYS)
#define RAM_SIZE                                (RAM5_BASE + RAM5_SIZE - RAM_BASE - RAMCP_SUBSYS_SIZE)
#else
#define RAM_SIZE                                (RAM5_BASE + RAM5_SIZE - RAM_BASE)
#endif
#endif /* RAM_SIZE */

#ifdef CHIP_ROLE_CP
#ifndef PSRAMCP_BASE
#define PSRAMCP_BASE                            (PSRAM_BASE + PSRAM_SIZE)
#endif
#endif

#define REAL_FLASH_BASE                         0x2C000000
#define REAL_FLASH_NC_BASE                      0x28000000
#define REAL_FLASHX_BASE                        0x0C000000
#define REAL_FLASHX_NC_BASE                     0x08000000

#define REAL_FLASH1_BASE                        0x2E000000
#define REAL_FLASH1_NC_BASE                     0x2A000000
#define REAL_FLASH1X_BASE                       0x0E000000
#define REAL_FLASH1X_NC_BASE                    0x0A000000

#define FLASH_BASE                              REAL_FLASH_BASE
#define FLASH_NC_BASE                           REAL_FLASH_NC_BASE
#define FLASHX_BASE                             REAL_FLASHX_BASE
#define FLASHX_NC_BASE                          REAL_FLASHX_NC_BASE
#ifndef ALT_BOOT_FLASH
#if defined(PROGRAMMER) && !defined(PROGRAMMER_INFLASH)
#define FLASH1_BASE                             FLASH_BASE
#define FLASH1_NC_BASE                          FLASH_NC_BASE
#define FLASH1X_BASE                            FLASHX_BASE
#define FLASH1X_NC_BASE                         FLASHX_NC_BASE
#elif !defined(FLASH1_BASE)
#define FLASH1_BASE                             REAL_FLASH1_BASE
#define FLASH1_NC_BASE                          REAL_FLASH1_NC_BASE
#define FLASH1X_BASE                            REAL_FLASH1X_BASE
#define FLASH1X_NC_BASE                         REAL_FLASH1X_NC_BASE
#endif
#endif /* !ALT_BOOT_FLASH */

#ifndef PSRAM_BASE
#define PSRAM_BASE                              0x34000000
#endif
#define PSRAM_NC_BASE                           (PSRAM_BASE - 0x4000000)
#define PSRAMX_BASE                             (PSRAM_BASE - 0x20000000)
#define PSRAMX_NC_BASE                          (PSRAMX_BASE - 0x4000000)

#ifndef PSRAMUHS_BASE
#define PSRAMUHS_BASE                           0x3C000000
#define PSRAMUHS_NC_BASE                        0x38000000
#define PSRAMUHSX_BASE                          0x1C000000
#define PSRAMUHSX_NC_BASE                       0x18000000
#endif

#define DCACHE_CTRL_BASE                        0x27FFA000
#define DCACHE_SIZE                             0x00008000
#define ICACHE_CTRL_BASE                        0x27FFC000
#define ICACHE_SIZE                             0x00008000

#define CMU_BASE                                0x40000000
#define MCU_WDT_BASE                            0x40001000
#define MCU_TIMER0_BASE                         0x40002000
#define MCU_TIMER1_BASE                         0x40003000
#define MCU_TIMER2_BASE                         0x40004000
#define I2C0_BASE                               0x40005000
#define I2C1_BASE                               0x40006000
#define SPI_BASE                                0x40007000
#define SPILCD_BASE                             0x40008000
#define ISPI_BASE                               0x40009000
#define SPIPHY_BASE                             0x4000A000
#define UART0_BASE                              0x4000B000
#define UART1_BASE                              0x4000C000
#define UART2_BASE                              0x4000D000
#define BTPCM_BASE                              0x4000E000
#define I2S0_BASE                               0x4000F000
#define SPDIF0_BASE                             0x40010000
#define TRANSQW_BASE                            0x40011000
#define TRANSQD_BASE                            0x40012000
#define TRNG_BASE                               0x40013000
#define IRDA_BASE                               0x40014000
#define I2C2_BASE                               0x40015000
#define UART3_BASE                              0x40016000
#define I2S1_BASE                               0x40017000
#define SEC_ENG_BASE                            0x40020000
#define SEC_CTRL_BASE                           0x40030000
#define MPC_PSRAMUHS_BASE                       0x40040000
#define SPY_PSRAMUHS_BASE                       0x40041000
#define MPC_IMEM_LO_A7_BASE                     0x40042000
#define SPY_IMEM_LO_A7_BASE                     0x40043000
#define MPC_IMEM_HI_A7_BASE                     0x40044000
#define SPY_IMEM_HI_A7_BASE                     0x40045000
#define MPC_PSRAM0_BASE                         0x40046000
#define SPY_PSRAM0_BASE                         0x40047000
#define MPC_PSRAM1_BASE                         0x40048000
#define SPY_PSRAM1_BASE                         0x40049000
#define MPC_PSRAM_A7_BASE                       0x4004A000
#define SPY_PSRAM_A7_BASE                       0x4004B000
#define REAL_MPC_FLASH0_BASE                    0x4004C000
#define REAL_SPY_FLASH0_BASE                    0x4004D000
#define REAL_MPC_FLASH1_BASE                    0x4004E000
#define REAL_SPY_FLASH1_BASE                    0x4004F000

#ifdef ALT_BOOT_FLASH
#define MPC_FLASH0_BASE                         REAL_MPC_FLASH1_BASE
#define SPY_FLASH0_BASE                         REAL_SPY_FLASH1_BASE
#define MPC_FLASH1_BASE                         REAL_MPC_FLASH0_BASE
#define SPY_FLASH1_BASE                         REAL_SPY_FLASH0_BASE
#else
#define MPC_FLASH0_BASE                         REAL_MPC_FLASH0_BASE
#define SPY_FLASH0_BASE                         REAL_SPY_FLASH0_BASE
#define MPC_FLASH1_BASE                         REAL_MPC_FLASH1_BASE
#define SPY_FLASH1_BASE                         REAL_SPY_FLASH1_BASE
#endif

#define MPC_ROM0_BASE                           0x40050000
#define SPY_ROM0_BASE                           0x40051000
#define MPC_SRAM0_BASE                          0x40052000
#define SPY_SRAM0_BASE                          0x40053000
#define MPC_SRAM1_BASE                          0x40054000
#define SPY_SRAM1_BASE                          0x40055000
#define MPC_SRAM2_BASE                          0x40056000
#define SPY_SRAM2_BASE                          0x40057000
#define MPC_SRAM3_BASE                          0x40058000
#define SPY_SRAM3_BASE                          0x40059000
#define MPC_SRAM4_BASE                          0x4005A000
#define SPY_SRAM4_BASE                          0x4005B000
#define MPC_SRAM5_BASE                          0x4005C000
#define SPY_SRAM5_BASE                          0x4005D000

#define AON_CMU_BASE                            0x40080000
#define AON_GPIO_BASE                           0x40081000
#define AON_WDT_BASE                            0x40082000
#define AON_PWM0_BASE                           0x40083000
#define AON_TIMER_BASE                          0x40084000
#define AON_IOMUX_BASE                          0x40086000
#define AON_PSC_BASE                            0x40088000
#define AON_PWM1_BASE                           0x40089000

#define CHECKSUM_BASE                           0x40100000
#define CRC_BASE                                0x40108000
#define SDMMC0_BASE                             0x40110000
#define SYS_AUDMA_BASE                          0x40120000
#define SYS_GPDMA_BASE                          0x40130000
#define REAL_FLASH_CTRL_BASE                    0x40140000
#ifndef FLASH_DUAL_CHIP
#define REAL_FLASH1_CTRL_BASE                   0x40148000
#endif

#ifdef ALT_BOOT_FLASH
#define FLASH_CTRL_BASE                         REAL_FLASH1_CTRL_BASE
#else
#define FLASH_CTRL_BASE                         REAL_FLASH_CTRL_BASE
#ifndef FLASH_DUAL_CHIP
#define FLASH1_CTRL_BASE                        REAL_FLASH1_CTRL_BASE
#endif
#endif

#define PSRAM_CTRL_BASE                         0x40150000
#define I2C_SLAVE_BASE                          0x40160000
#define WFTSF_BASE                              0x40170000
#define USB_BASE                                0x40180000
#define SEDMA_BASE                              0x401D0000
#define BTDUMP_BASE                             0x401E0000
#define PSRAMUHS_CTRL_BASE                      0x401F0000

#define CODEC_BASE                              0x40380000

#define PATCH_ENTRY_NUM                         8
#define PATCH_CTRL_BASE                         0x000FFE00
#define PATCH_DATA_BASE                         0x000FFF00

#define BT_SUBSYS_BASE                          0xA0000000
#define BT_RAM_BASE                             0xC0000000
#define BT_RAM_SIZE                             0x00008000
#define BT_UART_BASE                            0xD0300000
#define BT_CMU_BASE                             0xD0330000

#define WIFI_SUBSYS_BASE                        0x60000000
#define WIFI_RAM_BASE                           0x80000000
#define WIFI_RAM_SIZE                           0x00020000
#define WIFI_PAS_BASE                           0x82000000
#define WIFI_TRANSQM_BASE                       0x9000A000
#define WIFI_CMU_BASE                           0x90000000

#define DSP_SUBSYS_BASE                         0x50000000

#define DSP_BOOT_BASE                           0x00000000
#define DSP_BOOT_SIZE                           (24 * 4)

#define DSP_RAM0_BASE                           0x50000000
#define DSP_RAM1_BASE                           0x50040000
#define DSP_RAM2_BASE                           0x50080000
#define DSP_RAM3_BASE                           0x50100000
#define DSP_RAM4_BASE                           0x50180000
#define DSP_RAM5_BASE                           0x501C0000
#define DSP_RAM_BASE                            DSP_RAM0_BASE

#define DSP_RAM5_SIZE                           0x00040000

#define MAX_DSP_RAM_SIZE                        (DSP_RAM5_BASE + DSP_RAM5_SIZE - DSP_RAM1_BASE)

#ifndef DSP_RAM_SIZE
#ifdef LARGE_DSP_RAM
#define DSP_RAM_SIZE                            MAX_DSP_RAM_SIZE
#else /*LARGE_DSP_RAM*/
#ifdef FPGA
#define DSP_RAM_SIZE                            (DSP_RAM1_BASE - DSP_RAM0_BASE)
#else /*FPGA*/
#define DSP_RAM_SIZE                            (DSP_RAM3_BASE - DSP_RAM0_BASE)
#endif /*FPGA*/
#endif /*LARGE_DSP_RAM*/
#endif

#define GPV_MAIN_BASE                           0x50300000
#define GPV_PSRAM1G_BASE                        0x50400000

#define DSP_BOOT_REG                            0x58000000
#define DSP_WDT_BASE                            0x58001000
#define DSP_TIMER0_BASE                         0x58002000
#define DSP_TIMER1_BASE                         0x58003000
#define DSP_TRANSQM_BASE                        0x58004000
#define DSP_TIMESTAMP_GEN_BASE                  0x58020000

#define DSI_BASE                                0x58005000
#define CSI_BASE                                0x58006000
#define LCDC_BASE                               0x58100000

#define DSP_DEBUGSYS_APB_BASE                   0x58040000

#define DSP_XDMA_BASE                           0x58200000

#define GIC_DISTRIBUTOR_BASE                    0x58301000
#define GIC_INTERFACE_BASE                      0x58302000

#define IOMUX_BASE                              AON_IOMUX_BASE
#define GPIO_BASE                               AON_GPIO_BASE
#define PWM_BASE                                AON_PWM0_BASE
#define PWM1_BASE                               AON_PWM1_BASE

#ifdef CHIP_BEST2003_DSP
#define TIMER0_BASE                             DSP_TIMER0_BASE
#define TIMER1_BASE                             DSP_TIMER1_BASE
#define TRANSQ0_BASE                            TRANSQW_BASE
#define TRANSQ0_PEER_BASE                       WIFI_TRANSQM_BASE
#define TRANSQ1_BASE                            DSP_TRANSQM_BASE
#define TRANSQ1_PEER_BASE                       TRANSQD_BASE
#define WDT_BASE                                DSP_WDT_BASE
#else
#if defined(CP_AS_SUBSYS) || defined(CHIP_ROLE_CP)
#define CP_SUBSYS_TIMER0_BASE                   MCU_TIMER2_BASE
/* Caution: Cannot use fast timer irq */
#define CP_SUBSYS_TIMER1_BASE                   MCU_TIMER1_BASE
#endif
#ifdef CHIP_ROLE_CP
#define TIMER0_BASE                             CP_SUBSYS_TIMER0_BASE
#define TIMER1_BASE                             CP_SUBSYS_TIMER1_BASE
#else
#define TIMER0_BASE                             MCU_TIMER0_BASE
/* Caution: Cannot use fast timer irq */
#define TIMER1_BASE                             MCU_TIMER1_BASE
#ifndef CP_AS_SUBSYS
#define TIMER2_BASE                             MCU_TIMER2_BASE
#endif
#endif
#define TRANSQ0_BASE                            TRANSQW_BASE
#define TRANSQ0_PEER_BASE                       WIFI_TRANSQM_BASE
#define TRANSQ1_BASE                            TRANSQD_BASE
#define TRANSQ1_PEER_BASE                       DSP_TRANSQM_BASE
#define WDT_BASE                                AON_WDT_BASE
#endif

#define TRANSQ0_SLOT_NUM                        52

#ifndef DSP_USE_GPDMA
#if defined(CHIP_DMA_CFG_IDX) && (CHIP_DMA_CFG_IDX == 1)
#ifdef CHIP_ROLE_CP
/* CP subsys use the AUDMA */
#define AUDMA_BASE                              SYS_AUDMA_BASE
#else
/* Main MCU use the GPDMA */
#define AUDMA_BASE                              SYS_GPDMA_BASE
#endif
#else /* !defined(CHIP_DMA_CFG_IDX) */
#if !defined(CHIP_ROLE_CP)
/* Main MCU use two DMA */
#define AUDMA_BASE                              SYS_AUDMA_BASE
#define GPDMA_BASE                              SYS_GPDMA_BASE
#endif /* !CHIP_ROLE_CP */
#endif
#else /*DSP_USE_GPDMA*/
#ifdef CHIP_BEST2003_DSP
#define AUDMA_BASE                              SYS_GPDMA_BASE //A7 use GPDMA
#else
#define AUDMA_BASE                              SYS_AUDMA_BASE //MCU use AUDMA
#endif
#endif /*DSP_USE_GPDMA*/

/* For linker scripts */
#define VECTOR_SECTION_SIZE                     360
#define REBOOT_PARAM_SECTION_SIZE               64
#define ROM_BUILD_INFO_SECTION_SIZE             40
#define ROM_EXPORT_FN_SECTION_SIZE              128

#ifndef DSP_PSRAMUHS_SIZE
#define DSP_PSRAMUHS_SIZE                       (0)
#endif

#ifndef MCU_PSRAMUHS_SIZE
#define MCU_PSRAMUHS_SIZE                       (0)
#endif

#if defined(__NuttX__) && defined(CHIP_BEST2003_DSP)
#define DSP_PSRAMUHS_BASE                       (PSRAMUHS_NC_BASE)
#define DSP_PSRAMUHS_NC_BASE                    (PSRAMUHS_NC_BASE)
#define DSP_PSRAMUHSX_BASE                      (PSRAMUHSX_NC_BASE)
#else
#define DSP_PSRAMUHS_BASE                       (PSRAMUHS_BASE)
#define DSP_PSRAMUHS_NC_BASE                    (PSRAMUHS_NC_BASE)
#define DSP_PSRAMUHSX_BASE                      (PSRAMUHSX_BASE)
#endif

#define MCU_PSRAMUHS_BASE                       (PSRAMUHS_BASE + DSP_PSRAMUHS_SIZE)
#define MCU_PSRAMUHS_NC_BASE                    (PSRAMUHS_NC_BASE + DSP_PSRAMUHS_SIZE)
#define MCU_PSRAMUHSX_BASE                      (PSRAMUHSX_BASE + DSP_PSRAMUHS_SIZE)

#define BT_INTESYS_MEM_OFFSET                   0x00004000

/* For module features */
#define CODEC_FREQ_CRYSTAL                      CODEC_FREQ_26M
#define CODEC_PLL_DIV                           156
#define CODEC_CMU_DIV                           13
#define CODEC_PLAYBACK_BIT_DEPTH                20
#define CODEC_HAS_FIR
#define GPADC_CTRL_VER                          3
#define GPADC_VALUE_BITS                        16
#define GPADC_CALIB_DEFAULT_A                   0x3789
#define GPADC_CALIB_DEFAULT_B                   0x4950
#define I2S_TX_MULTI_CHAN
#define I2S_RX_MULTI_CHAN
#define SEC_ENG_HAS_HASH
#define SEC_ENG_HAS_ZMODP
#define SEC_ENG_HAS_ECP
#define PAGE_SPY_HAS_IRQ
#define INTERFACE_ADDR_BITS                     10
#ifndef AUD_SECTION_STRUCT_VERSION
#define AUD_SECTION_STRUCT_VERSION              2
#endif
#define AHB_DMA_MULTI_MASTER
#define RMT_IPC_API_ENABLE
#define CHIP_WIFITSF_VER                        1

#if defined(PROGRAMMER) && !defined(PROGRAMMER_INFLASH)
/* 64M-byte */
#define HAL_NORFLASH_ADDR_MASK                  0x03FFFFFF
#else
/* Total 64M-byte space and let each flash ctrl owns 32M-byte space */
#define HAL_NORFLASH_ADDR_MASK                  0x01FFFFFF
#endif

#define RSA_RAW_KEY_ENABLE
#define RSA_RAW_KEY_IN_ROM

/* For boot struct version */
#ifndef SECURE_BOOT_VER
#define SECURE_BOOT_VER                         4
#endif

#ifndef MCU_PSRAM_SIZE
#define MCU_PSRAM_SIZE                          PSRAM_SIZE
#endif

#ifndef PSRAMCP_BASE
#define PSRAMCP_BASE                            (PSRAM_BASE + MCU_PSRAM_SIZE)
#endif
#ifndef PSRAMCPX_BASE
#define PSRAMCPX_BASE                           (PSRAMX_BASE + MCU_PSRAM_SIZE)
#endif

#ifndef PSRAMCP_SIZE
#define PSRAMCP_SIZE                            0
#endif

#ifndef PSRAMDSP_SIZE
#define PSRAMDSP_SIZE                           0
#endif

#ifndef PSRAMDSP_BASE
#define PSRAMDSP_BASE                           (PSRAMCP_BASE + PSRAMCP_SIZE)
#endif

#ifndef PSRAMFS_SIZE
#define PSRAMFS_SIZE                            0
#endif
#define PSRAMFS_BASE                            (PSRAMDSP_BASE + PSRAMDSP_SIZE)

#if defined(CONFIG_BOOT_RUNFROMFLASH) && defined(CHIP_BEST2003_DSP)
#undef RAM_BASE
#undef RAMX_BASE
#undef RAM_SIZE
#define RAM_BASE                                (DSP_PSRAMUHS_BASE)
#define RAMX_BASE                               (DSP_PSRAMUHSX_BASE)
#define RAM_SIZE                                (DSP_PSRAMUHS_SIZE)

#undef FLASH_BASE
#undef FLASH_NC_BASE
#undef FLASHX_BASE
#undef FLASHX_NC_BASE
#undef HAL_NORFLASH_ADDR_MASK
#define HAL_NORFLASH_ADDR_MASK                  0x0000FFFF
#define FLASH_BASE                              (CONFIG_FLASH_START)
#define FLASH_NC_BASE                           (CONFIG_FLASH_START)
#define FLASHX_BASE                             (CONFIG_FLASH_START)
#define FLASHX_NC_BASE                          (CONFIG_FLASH_START)
#endif

/* For ROM export functions */
#define NO_MEMMOVE

#ifdef __cplusplus
}
#endif

#endif
