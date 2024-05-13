/**************************************************************************//**
 * @file     best1503.h
 * @brief    CMSIS Core Peripheral Access Layer Header File for
 *           ARMCM4 Device Series
 * @version  V2.02
 * @date     10. September 2014
 *
 * @note     configured for CM4 with FPU
 *
 ******************************************************************************/
/* Copyright (c) 2011 - 2014 ARM LIMITED
   Copyright (c) 2023 BES

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


#ifndef __BEST1503_H__
#define __BEST1503_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __ASSEMBLER__
/* -------------------------  Interrupt Number Definition  ------------------------ */

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

/* --------------------  BEST1502x Specific Interrupt Numbers  --------------------- */
    FPU_IRQn                    =   0,      /*!< FPU Interrupt                      */
    SPI_WAKEUP_IRQn             =   1,      /*!< SPI Slave Wakeup Interrupt         */
    UART3_IRQn                  =   2,      /*!< UART3 Interrupt                    */
    AUDMA_IRQn                  =   3,      /*!< Audio DMA Interrupt                */
    GPDMA_IRQn                  =   4,      /*!< General Purpose DMA Interrupt      */
    AON_WDT_IRQn                =   5,      /*!< AON Watchdog Timer Interrupt       */
    UART4_IRQn                  =   6,      /*!< UART4 Interrupt                    */
    SPILCD_IRQn                 =   7,      /*!< SPILCD Interrupt                   */
    WAKEUP_IRQn                 =   8,      /*!< Wakeup Interrupt                   */
    AON_GPIO_IRQn               =   9,      /*!< AON GPIO Interrupt                 */
    MCU_WDT_IRQn                =  10,      /*!< Watchdog Timer Interrupt           */
    DSI_IRQn                    =  11,      /*!< DSI Interrupt                      */
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
    CAP_SENSOR_IRQn             =  CODEC_TX_PEAK_IRQn,  /*!< CAP SENSOR Interrupt   */
    UART2_IRQn                  =  26,      /*!< UART2 Interrupt                    */
    MCU_TIMER10_IRQn            =  27,      /*!< Timer10 Interrupt                  */
    MCU_TIMER11_IRQn            =  28,      /*!< Timer11 Interrupt                  */
    I2C1_IRQn                   =  29,      /*!< I2C1 Interrupt                     */
    DUMP_IRQn                   =  30,      /*!< DUMP Interrupt                     */
    SPILCD2_IRQn                =  31,      /*!< SPILCD2 Interrupt                  */
    ISDONE_IRQn                 =  32,      /*!< Intersys MCU2BT Data Done Interrupt */
    ISDONE1_IRQn                =  33,      /*!< Intersys MCU2BT Data1 Done Interrupt */
    ISDATA_IRQn                 =  34,      /*!< Intersys BT2MCU Data Indication Interrupt */
    ISDATA1_IRQn                =  35,      /*!< Intersys BT2MCU Data1 Indication Interrupt */
    CP2MCU_DATA_IRQn            =  36,      /*!< Intersys CP2MCU Data Indication Interrupt */
    CP2MCU_DATA1_IRQn           =  37,      /*!< Intersys CP2MCU Data1 Indication Interrupt */
    CP2MCU_DATA2_IRQn           =  38,      /*!< Intersys CP2MCU Data Indication Interrupt */
    CP2MCU_DATA3_IRQn           =  39,      /*!< Intersys CP2MCU Data1 Indication Interrupt */
    PMU1_IRQn                   =  40,      /*!< PMU1 Interrupt                     */
    UART5_IRQn                  =  41,      /*!< UART5 Interrupt                    */
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
    CRC_IRQn                    =  52,      /*!< CRC Interrupt                      */
    I2C4_IRQn                   =  53,      /*!< I2C4 Interrupt                     */
    I2C5_IRQn                   =  54,      /*!< I2C5 Interrupt                     */
    I2C6_IRQn                   =  55,      /*!< I2C6 Interrupt                     */
    I2C7_IRQn                   =  56,      /*!< I2C7 Interrupt                     */
    ISDONE2_IRQn                =  57,      /*!< Intersys MCU2BT Data2 Done Interrupt */
    ISDONE3_IRQn                =  58,      /*!< Intersys MCU2BT Data3 Done Interrupt */
    ISDATA2_IRQn                =  59,      /*!< Intersys BT2MCU Data2 Indication Interrupt */
    ISDATA3_IRQn                =  60,      /*!< Intersys BT2MCU Data3 Indication Interrupt */
    BT_STAMP_IRQn               =  61,      /*!< BT Playtime Stamp Interrupt        */
    MCU_TIMER20_IRQn            =  62,      /*!< Timer20 Interrupt                  */
    MCU_TIMER21_IRQn            =  MCU_TIMER20_IRQn, /*!< Timer21 Interrupt         */
    TRNG_IRQn                   =  63,      /*!< TRNG Interrupt                     */
    I2C2_IRQn                   =  64,      /*!< I2C2 Interrupt                     */
    I2C3_IRQn                   =  65,      /*!< I2C3 Interrupt                     */
    VMM_IRQn                    =  66,      /*!< VMM Interrupt                      */
    DISPLAY_IRQn                =  67,      /*!< Display Interrupt                  */
    LCD_FRAME_DONE_IRQn         =  68,      /*!< Lcd Frame Done Interrupt           */
    NONE69_IRQn                 =  69,      /*!< None69 Interrupt                   */
    GPU_IRQn                    =  70,      /*!< GPU Interrupt                      */
    SDMMC0_IRQn                 =  71,      /*!< SDMMC Interrupt                    */
    BTTIME_IRQn                 =  72,      /*!< Bttime Interrupt                   */
    BT2MCU_SLP_IRQn             =  73,      /*!< BT2MCU Slp Interrupt               */
    CHARGER_IRQn                =  74,      /*!< Charger Interrupt                  */
    CORDIC_IRQn                 =  75,      /*!<  Cordic Interrupt                  */
    MCU_PPI_IRQn                =  76,      /*!< MCU PPI Interrupt                  */
    JPEG_DEC_IRQn               =  77,      /*!< JPEG Dec Interrupt                 */

    USER_IRQn_QTY,
    INVALID_IRQn                = USER_IRQn_QTY,
} IRQn_Type;

#ifdef PSC_GPIO_IRQ_CTRL
#define GPIO_IRQn               AON_IRQn
#else
#define GPIO_IRQn               AON_GPIO_IRQn
#define GPIO1_IRQn              AON_GPIO_IRQn
#define GPIO2_IRQn              AON_GPIO_IRQn
#endif
#define GPADC_IRQn              INVALID_IRQn
#define PWRKEY_IRQn             INVALID_IRQn
#define WDT_IRQn                AON_WDT_IRQn
#define RTC_IRQn                PMU_IRQn

#include "plat_addr_map.h"

#if (TIMER0_BASE == AON_TIMER0_BASE)
#define TIMER00_IRQn            AON_TIMER00_IRQn
#define TIMER01_IRQn            AON_TIMER01_IRQn
#elif (TIMER0_BASE == MCU_TIMER0_BASE)
#define TIMER00_IRQn            MCU_TIMER00_IRQn
#define TIMER01_IRQn            MCU_TIMER01_IRQn
#elif (TIMER0_BASE == MCU_TIMER1_BASE)
#define TIMER00_IRQn            MCU_TIMER10_IRQn
#define TIMER01_IRQn            MCU_TIMER11_IRQn
#elif (TIMER0_BASE == MCU_TIMER2_BASE)
#define TIMER00_IRQn            MCU_TIMER20_IRQn
#define TIMER01_IRQn            MCU_TIMER21_IRQn
#endif

#if (TIMER1_BASE == MCU_TIMER0_BASE)
#define TIMER10_IRQn            MCU_TIMER00_IRQn
#define TIMER11_IRQn            MCU_TIMER01_IRQn
#elif (TIMER1_BASE == MCU_TIMER1_BASE)
#define TIMER10_IRQn            MCU_TIMER10_IRQn
#define TIMER11_IRQn            MCU_TIMER11_IRQn
#elif (TIMER1_BASE == MCU_TIMER2_BASE)
#define TIMER10_IRQn            MCU_TIMER20_IRQn
#define TIMER11_IRQn            MCU_TIMER21_IRQn
#endif

#ifdef TIMER2_BASE
#if (TIMER2_BASE == MCU_TIMER0_BASE)
#define TIMER20_IRQn            MCU_TIMER00_IRQn
#define TIMER21_IRQn            MCU_TIMER01_IRQn
#elif (TIMER2_BASE == MCU_TIMER1_BASE)
#define TIMER20_IRQn            MCU_TIMER10_IRQn
#define TIMER21_IRQn            MCU_TIMER11_IRQn
#elif (TIMER2_BASE == MCU_TIMER2_BASE)
#define TIMER20_IRQn            MCU_TIMER20_IRQn
#define TIMER21_IRQn            MCU_TIMER21_IRQn
#else
#define TIMER20_IRQn            INVALID_IRQn
#define TIMER21_IRQn            INVALID_IRQn
#endif
#endif

#endif

/* ================================================================================ */
/* ================      Processor and Core Peripheral Section     ================ */
/* ================================================================================ */

/* --------  Configuration of Core Peripherals  ----------------------------------- */
#define __CM33_REV                0x0000U   /* Core revision r0p1 */
#define __SAUREGION_PRESENT       1U        /* SAU regions present */
#define __MPU_PRESENT             1U        /* MPU present */
#define __VTOR_PRESENT            1U        /* VTOR present */
#define __NVIC_PRIO_BITS          3U        /* Number of Bits used for Priority Levels */
#define __Vendor_SysTickConfig    0U        /* Set to 1 if different SysTick Config is used */
#define __FPU_PRESENT             1U        /* FPU present */
#define __DSP_PRESENT             1U        /* DSP extension present */

#ifdef ARM_CMNS
#if defined(RTOS) && defined(KERNEL_RTX5)
#define RTE_CMSIS_RTOS2_RTX5_ARMV8M_NS
#endif
#endif

#include "core_cm33.h"                      /* Processor and core peripherals */

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

