/**************************************************************************//**
 * @file     best1501.h
 * @brief    CMSIS Core Peripheral Access Layer Header File for
 *           ARMCM4 Device Series
 * @version  V2.02
 * @date     10. September 2014
 *
 * @note     configured for CM4 with FPU
 *
 ******************************************************************************/
/* Copyright (c) 2011 - 2014 ARM LIMITED
   Copyright (c) 2020 BES

   All rights reserved.
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   - Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   - Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   - Neither the name of ARM nor the names of its contributors may be used
     to endorse or promote products derived from this software without
     specific prior written permission.
   *
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED. IN NO EVENT SHALL COPYRIGHT HOLDERS AND CONTRIBUTORS BE
   LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
   INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
   CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
   ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
   POSSIBILITY OF SUCH DAMAGE.
   ---------------------------------------------------------------------------*/


#ifndef __BEST1501_H__
#define __BEST1501_H__

#ifdef CHIP_SUBSYS_SENS

#include "best1501_sens.h"

#else

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ASSEMBLER__
/* -------------------------  Interrupt Number Definition  ------------------------ */


#if (defined __1600_BTH_HAL__)

typedef enum IRQn
{
/* -------------------  Cortex-M33 Processor Exceptions Numbers  ------------------ */
    NonMaskableInt_IRQn         = -14,      /*!<  2 Non Maskable Interrupt          */
    HardFault_IRQn              = -13,      /*!<  3 HardFault Interrupt             */
    MemoryManagement_IRQn       = -12,      /*!<  4 Memory Management Interrupt     */
    BusFault_IRQn               = -11,      /*!<  5 Bus Fault Interrupt             */
    UsageFault_IRQn             = -10,      /*!<  6 Usage Fault Interrupt           */
    SVCall_IRQn                 =  -5,      /*!< 11 SV Call Interrupt               */
    DebugMonitor_IRQn           =  -4,      /*!< 12 Debug Monitor Interrupt         */
    PendSV_IRQn                 =  -2,      /*!< 14 Pend SV Interrupt               */
    SysTick_IRQn                =  -1,      /*!< 15 System Tick Interrupt           */

/* --------------------  BEST1501 Specific Interrupt Numbers  --------------------- */
    SYS_EMMC_IRQn               =   0,      /*!< SYS EMMC Interrupt                 */
    SPI_WAKEUP_IRQn             =   1,      /*!< SPI Slave Wakeup Interrupt         */
    SYS_USB_IRQn                =   2,      /*!< SYS USB Interrupt                  */
    SYS_I2C0_IRQn               =   3,      /*!< SYS I2C0 Interrupt                 */
    AUDMA_IRQn                  =   4,      /*!< Audio DMA Interrupt                */
    AON_WDT_IRQn                =   5,      /*!< AON Watchdog Timer Interrupt       */
    SYS_SPI0_IRQn               =   6,      /*!< SYS SPI0 Interrupt                 */
    SYS_I2S0_IRQn               =   7,      /*!< SYS I2S0 Interrupt                 */
    SYS_GPU_IRQn                =   8,      /*!< SYS GPU or BTH Wakeup Interrupt    */
    AON_GPIO_IRQn               =   9,      /*!< AON GPIO Interrupt                 */
    MCU_WDT_IRQn                =  10,      /*!< Watchdog Timer Interrupt           */
    SYS_SPDIF0_IRQn             =  11,      /*!< SYS SPDIF0 Interrupt               */
    MCU_TIMER00_IRQn            =  12,      /*!< Timer00 Interrupt                  */
    MCU_TIMER01_IRQn            =  13,      /*!< Timer01 Interrupt                  */
#ifdef FPGA
    I2C0_IRQn                   =  14,      /*!< I2C0 Interrupt                     */
#else
    SYS_USB_PIN_IRQn            =  14,      /*!< SYS_USB_PIN Interrupt              */
#endif
    SYS_AUDMA_IRQn              =  15,      /*!< SYS AUDMA Interrupt                */
    SYS_GPDMA_IRQn              =  16,      /*!< SYS GPDMA Interrupt                */
    UART0_IRQn                  =  17,      /*!< UART0 Interrupt                    */
    UART1_IRQn                  =  18,      /*!< UART1 Interrupt                    */
    CODEC_IRQn                  =  19,      /*!< CODEC Interrupt                    */
    BTPCM_IRQn                  =  20,      /*!< BTPCM Interrupt                    */
#ifdef FPGA
    I2S0_IRQn                   =  21,      /*!< I2S0 Interrupt                     */
#else
    SYS_I2S1_IRQn               =  21,      /*!< SYS I2S1 Interrupt                 */
#endif
    SYS_SPILCD_IRQn             =  22,      /*!< SYS SPILCD Interrupt               */
    SYS_I2C1_IRQn               =  23,      /*!< SYS I2C1 Interrupt                 */
    BT_IRQn                     =  24,      /*!< BT to MCU Interrupt                */
    CODEC_TX_PEAK_IRQn          =  25,      /*!< CODEC TX PEAK Interrupt            */
    SYS_GPIO_IRQn               =  26,      /*!< SYS GPIO Interrupt                 */
    MCU_TIMER10_IRQn            =  27,      /*!< Timer10 Interrupt                  */
    MCU_TIMER11_IRQn            =  28,      /*!< Timer11 Interrupt                  */
    SYS_SEDMA_IRQn              =  29,      /*!< SYS SEDMA Interrupt                */
    DUMP_IRQn                   =  30,      /*!< DUMP Interrupt                     */
    BT_TIME_IRQn                =  31,      /*!< SPIPHY Interrupt                   */
    ISDONE_IRQn                 =  32,      /*!< Intersys MCU2BT Data Done Interrupt */
    ISDONE1_IRQn                =  33,      /*!< Intersys MCU2BT Data1 Done Interrupt */
    ISDATA_IRQn                 =  34,      /*!< Intersys BT2MCU Data Indication Interrupt */
    ISDATA1_IRQn                =  35,      /*!< Intersys BT2MCU Data1 Indication Interrupt */
    BTH2SYS_DONE_IRQn           =  36,      /*!< Intersys BTH2SYS Data Done Interrupt */
    BTH2SYS_DONE1_IRQn          =  37,      /*!< Intersys BTH2SYS Data Done Interrupt */
    SYS2BTH_DATA_IRQn           =  38,      /*!< Intersys SYS2BTH Data Indication Interrupt */
    SYS2BTH_DATA1_IRQn          =  39,      /*!< Intersys SYS2BTH Data1 Indication Interrupt */
    PMU1_IRQn                   =  40,      /*!< PMU1 Interrupt                     */
    SYS_SEC_ENG_IRQn            =  41,      /*!< SYS SEC ENG Interrupt              */
    PMU_IRQn                    =  42,      /*!< PMU Interrupt                      */
    SYS_SDMMC_IRQn              =  43,      /*!< SYS SDMMC or EMMC Interrupt        */
    AON_IRQn                    =  44,      /*!< AON Interrupt                      */
    AON_TIMER00_IRQn            =  45,      /*!< AON Timer00 Interrupt              */
    AON_TIMER01_IRQn            =  46,      /*!< AON Timer01 Interrupt              */
    AON_TIMER10_IRQn            =  47,      /*!< AON Timer00 Interrupt              */
    AON_TIMER11_IRQn            =  48,      /*!< AON Timer01 Interrupt              */
    SYS_IMGDMA_IRQn             =  49,      /*!< SYS IMGDMA or GPU Interrupt        */
    SYS_DISPLAY_IRQn            =  50,      /*!< SYS DISPLAY Interrupt              */
    SYS_DSI_IRQn                =  51,      /*!< SYS DSI Interrupt                  */
    SENS_IRQn                   =  52,      /*!< SENSOR CPU to MCU Interrupt        */
    SENS2MCU_DATA_IRQn          =  53,      /*!< Intersys SENS2MCU Data Indication Interrupt */
    SENS2MCU_DATA1_IRQn         =  54,      /*!< Intersys SENS2MCU Data1 Indication Interrupt */
    SENS2MCU_DATA2_IRQn         =  55,      /*!< Intersys SENS2MCU Data Indication Interrupt */
    SENS2MCU_DATA3_IRQn         =  56,      /*!< Intersys SENS2MCU Data1 Indication Interrupt */
    MCU2SENS_DONE_IRQn          =  57,      /*!< Intersys MCU2SENS Data Done Interrupt */
    MCU2SENS_DONE1_IRQn         =  58,      /*!< Intersys MCU2SENS Data Done Interrupt */
    MCU2SENS_DONE2_IRQn         =  59,      /*!< Intersys MCU2SENS Data Done Interrupt */
    MCU2SENS_DONE3_IRQn         =  60,      /*!< Intersys MCU2SENS Data Done Interrupt */
    BT_STAMP_IRQn               =  61,      /*!< BT Playtime Stamp Interrupt        */
    SYS_WDT_IRQn                =  62,      /*!< SYS WDT Interrupt                  */
    BTC_WDT_IRQn                =  63,      /*!< BTC WDT Interrupt                  */

    USER_IRQn_QTY,
    INVALID_IRQn                = USER_IRQn_QTY,
} IRQn_Type;

#define USB_PIN_IRQn            INVALID_IRQn
#define TRNG_IRQn               INVALID_IRQn
#define GPDMA_IRQn              4
#define I2C1_IRQn               INVALID_IRQn
#define SDMMC0_IRQn             INVALID_IRQn
#define SEC_ENG_IRQn            INVALID_IRQn
#define SEDMA_IRQn              INVALID_IRQn
#define UART2_IRQn              INVALID_IRQn

#define GPIO_IRQn               AON_GPIO_IRQn
#define GPADC_IRQn              INVALID_IRQn
#define PWRKEY_IRQn             INVALID_IRQn
#ifdef CORE_SLEEP_POWER_DOWN
#define TIMER00_IRQn            AON_TIMER00_IRQn
#define TIMER01_IRQn            AON_TIMER01_IRQn
#else
#define TIMER00_IRQn            MCU_TIMER00_IRQn
#define TIMER01_IRQn            MCU_TIMER01_IRQn
#endif
#define TIMER10_IRQn            MCU_TIMER10_IRQn
#define TIMER11_IRQn            MCU_TIMER11_IRQn
#define TIMER20_IRQn            AON_TIMER00_IRQn
#define TIMER21_IRQn            AON_TIMER01_IRQn

#define WDT_IRQn                AON_WDT_IRQn

#else /* __1600_BTH_HAL__ */

typedef enum IRQn
{
/* -------------------  Cortex-M33 Processor Exceptions Numbers  ------------------ */
    NonMaskableInt_IRQn         = -14,      /*!<  2 Non Maskable Interrupt          */
    HardFault_IRQn              = -13,      /*!<  3 HardFault Interrupt             */
    MemoryManagement_IRQn       = -12,      /*!<  4 Memory Management Interrupt     */
    BusFault_IRQn               = -11,      /*!<  5 Bus Fault Interrupt             */
    UsageFault_IRQn             = -10,      /*!<  6 Usage Fault Interrupt           */
    SVCall_IRQn                 =  -5,      /*!< 11 SV Call Interrupt               */
    DebugMonitor_IRQn           =  -4,      /*!< 12 Debug Monitor Interrupt         */
    PendSV_IRQn                 =  -2,      /*!< 14 Pend SV Interrupt               */
    SysTick_IRQn                =  -1,      /*!< 15 System Tick Interrupt           */

/* --------------------  BEST1501 Specific Interrupt Numbers  --------------------- */
    FPU_IRQn                    =   0,      /*!< FPU Interrupt                      */
    SPI_WAKEUP_IRQn             =   1,      /*!< SPI Slave Wakeup Interrupt         */
    SDMMC0_IRQn                 =   2,      /*!< SDMMC Interrupt                    */
    AUDMA_IRQn                  =   3,      /*!< Audio DMA Interrupt                */
    GPDMA_IRQn                  =   4,      /*!< General Purpose DMA Interrupt      */
    AON_WDT_IRQn                =   5,      /*!< AON Watchdog Timer Interrupt       */
    USB_PHY_IRQn                =   6,      /*!< USB PHY Interrupt                  */
    USB_IRQn                    =   7,      /*!< USB Interrupt                      */
    WAKEUP_IRQn                 =   8,      /*!< Wakeup Interrupt                   */
    AON_GPIO_IRQn               =   9,      /*!< AON GPIO Interrupt                 */
    MCU_WDT_IRQn                =  10,      /*!< Watchdog Timer Interrupt           */
    DISPLAY_IRQn                =  11,      /*!< DISPLAY Interrupt                  */
    MCU_TIMER00_IRQn            =  12,      /*!< Timer00 Interrupt                  */
    MCU_TIMER01_IRQn            =  13,      /*!< Timer01 Interrupt                  */
    I2C0_IRQn                   =  14,      /*!< I2C0 Interrupt                     */
    SPI0_IRQn                   =  15,      /*!< SPI0 Interrupt                     */
    PAGE_SPY_IRQn               =  16,      /*!< PAGE SPY Interrupt                 */
    UART0_IRQn                  =  17,      /*!< UART0 Interrupt                    */
    UART1_IRQn                  =  18,      /*!< UART1 Interrupt                    */
    CODEC_IRQn                  =  19,      /*!< CODEC Interrupt                    */
    BTPCM_IRQn                  =  20,      /*!< BTPCM Interrupt                    */
    I2S0_IRQn                   =  21,      /*!< I2S0 Interrupt                     */
    SPDIF0_IRQn                 =  22,      /*!< SPDIF0 Interrupt                   */
    I2S1_IRQn                   =  23,      /*!< I2S1 Interrupt                     */
    BT_IRQn                     =  24,      /*!< BT to MCU Interrupt                */
    CODEC_TX_PEAK_IRQn          =  25,      /*!< CODEC TX PEAK Interrupt            */
    UART2_IRQn                  =  26,      /*!< UART2 Interrupt                    */
    MCU_TIMER10_IRQn            =  27,      /*!< Timer10 Interrupt                  */
    MCU_TIMER11_IRQn            =  28,      /*!< Timer11 Interrupt                  */
    I2C1_IRQn                   =  29,      /*!< I2C1 Interrupt                     */
    DUMP_IRQn                   =  30,      /*!< DUMP Interrupt                     */
    BTTIME_IRQn                 =  31,      /*!< SPIPHY Interrupt                   */
    ISDONE_IRQn                 =  32,      /*!< Intersys MCU2BT Data Done Interrupt */
    ISDONE1_IRQn                =  33,      /*!< Intersys MCU2BT Data1 Done Interrupt */
    ISDATA_IRQn                 =  34,      /*!< Intersys BT2MCU Data Indication Interrupt */
    ISDATA1_IRQn                =  35,      /*!< Intersys BT2MCU Data1 Indication Interrupt */
    BTH2SYS_DATA_IRQn           =  36,      /*!< Intersys CP2MCU Data Done Interrupt */
    BTH2SYS_DATA1_IRQn          =  37,      /*!< Intersys CP2MCU Data1 Done Interrupt */
    SYS2BTH_DATA_IRQn           =  38,      /*!< Intersys CP2MCU Data Indication Interrupt */
    SYS2BTH_DATA1_IRQn          =  39,      /*!< Intersys CP2MCU Data1 Indication Interrupt */
    PMU1_IRQn                   =  40,      /*!< PMU1 Interrupt                     */
    USB_PIN_IRQn                =  41,      /*!< USB Pin Interrupt                  */
    PMU_IRQn                    =  42,      /*!< PMU Interrupt                      */
    SEC_ENG_IRQn                =  43,      /*!< Security Engine Interrupt          */
    AON_IRQn                    =  44,      /*!< AON Interrupt                      */
    AON_TIMER00_IRQn            =  45,      /*!< AON Timer00 Interrupt              */
    AON_TIMER01_IRQn            =  46,      /*!< AON Timer01 Interrupt              */
    SEDMA_IRQn                  =  47,      /*!< Security Engine DMA Interrupt      */
    MCU2CP_DONE_IRQn            =  48,      /*!< Intersys MCU2CP Data Done Interrupt */
    MCU2CP_DONE1_IRQn           =  49,      /*!< Intersys MCU2CP Data Done Interrupt */
    MCU2CP_DONE2_IRQn           =  50,      /*!< Intersys MCU2CP Data Done Interrupt */
    MCU2CP_DONE3_IRQn           =  51,      /*!< Intersys MCU2CP Data Done Interrupt */
    SENS_IRQn                   =  52,      /*!< SENSOR CPU to MCU Interrupt        */
    SENS2MCU_DATA_IRQn          =  53,      /*!< Intersys SENS2MCU Data Indication Interrupt */
    SENS2MCU_DATA1_IRQn         =  54,      /*!< Intersys SENS2MCU Data1 Indication Interrupt */
    SENS2MCU_DATA2_IRQn         =  55,      /*!< Intersys SENS2MCU Data Indication Interrupt */
    SENS2MCU_DATA3_IRQn         =  56,      /*!< Intersys SENS2MCU Data1 Indication Interrupt */
    MCU2SENS_DONE_IRQn          =  57,      /*!< Intersys MCU2SENS Data Done Interrupt */
    MCU2SENS_DONE1_IRQn         =  58,      /*!< Intersys MCU2SENS Data Done Interrupt */
    MCU2SENS_DONE2_IRQn         =  59,      /*!< Intersys MCU2SENS Data Done Interrupt */
    MCU2SENS_DONE3_IRQn         =  60,      /*!< Intersys MCU2SENS Data Done Interrupt */
    BT_STAMP_IRQn               =  61,      /*!< BT Playtime Stamp Interrupt        */
    MCU_TIMER20_IRQn            =  62,      /*!< Timer10 Interrupt                  */
    TRNG_IRQn                   =  63,      /*!< TRNG Interrupt                     */
#if defined(__FPGA_1501P__)
    ISDONE2_IRQn                 =  64,      /*!< Intersys MCU2BT Data Done Interrupt */
    ISDONE3_IRQn                =  65,      /*!< Intersys MCU2BT Data1 Done Interrupt */
    ISDATA2_IRQn                 =  66,      /*!< Intersys BT2MCU Data Indication Interrupt */
    ISDATA3_IRQn                =  67,      /*!< Intersys BT2MCU Data1 Indication Interrupt */
#endif

    USER_IRQn_QTY,
    INVALID_IRQn                = USER_IRQn_QTY,
} IRQn_Type;

#define GPIO_IRQn               AON_IRQn
#define GPADC_IRQn              INVALID_IRQn
#define PWRKEY_IRQn             INVALID_IRQn
#ifdef CORE_SLEEP_POWER_DOWN
#define TIMER00_IRQn            AON_TIMER00_IRQn
#define TIMER01_IRQn            AON_TIMER01_IRQn
#else
#define TIMER00_IRQn            MCU_TIMER00_IRQn
#define TIMER01_IRQn            MCU_TIMER01_IRQn
#endif
#define TIMER10_IRQn            MCU_TIMER10_IRQn
#define TIMER11_IRQn            MCU_TIMER11_IRQn
#define WDT_IRQn                AON_WDT_IRQn
#endif /* !(defined __1600_BTH_HAL__) */

#endif

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* --------  Configuration of Core Peripherals  ----------------------------------- */
#define __CM33_REV                0x0000U   /* Core revision r0p1 */
#define __SAUREGION_PRESENT       0U        /* SAU regions present */
#define __MPU_PRESENT             1U        /* MPU present */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __NVIC_PRIO_BITS          3U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1U        /* FPU present */
#define __DSP_PRESENT             1U        /* DSP extension present */
#define __NUM_CODE_PATCH          56
#define __NUM_LIT_PATCH           8


#if defined(CPU_M4)
#include "core_cm4.h"                      /* Processor and core peripherals */
#else
#include "core_cm33.h"                      /* Processor and core peripherals */

#endif
#ifndef __ASSEMBLER__

#include "system_ARMCM.h"                  /* System Header                                     */

#endif

/* ================================================================================ */
/* ================       Device Specific Peripheral Section       ================ */
/* ================================================================================ */

/* -------------------  Start of section using anonymous unions  ------------------ */
#if   defined (__CC_ARM)
  #pragma push
  #pragma anon_unions
#elif defined (__ICCARM__)
  #pragma language=extended
#elif defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
  #pragma clang diagnostic push
  #pragma clang diagnostic ignored "-Wc11-extensions"
  #pragma clang diagnostic ignored "-Wreserved-id-macro"
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning 586
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

/* --------------------  End of section using anonymous unions  ------------------- */
#if   defined (__CC_ARM)
  #pragma pop
#elif defined (__ICCARM__)
  /* leave anonymous unions enabled */
#elif (defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050))
  #pragma clang diagnostic pop
#elif defined (__GNUC__)
  /* anonymous unions are enabled by default */
#elif defined (__TMS470__)
  /* anonymous unions are enabled by default */
#elif defined (__TASKING__)
  #pragma warning restore
#elif defined (__CSMC__)
  /* anonymous unions are enabled by default */
#else
  #warning Not supported compiler type
#endif

#ifdef __cplusplus
}
#endif

#endif

#endif
