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
#ifndef __HAL_CMU_H__
#define __HAL_CMU_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "stdint.h"
#include "cmsis.h"
#include "plat_addr_map.h"
#include "plat_types.h"
#ifdef CHIP_SUBSYS_SENS
#include CHIP_SPECIFIC_HDR(hal_senscmu)
#elif defined(CHIP_SUBSYS_CSP)
#include CHIP_SPECIFIC_HDR(hal_cspcmu)
#elif defined(CHIP_SUBSYS_BTH)
#include CHIP_SPECIFIC_HDR(hal_bthcmu)
#else
#include CHIP_SPECIFIC_HDR(hal_cmu)
#endif

#ifdef CPU_TO_DEV_ADDR_REMAP
#define ADDR_CPU_TO_DEV(a)                  ((typeof(a))addr_remap_cpu_to_dev((uint32_t)(a)))
#define ADDR_DEV_TO_CPU(a)                  ((typeof(a))addr_remap_dev_to_cpu((uint32_t)(a)))
#else
#define ADDR_CPU_TO_DEV(a)                  (a)
#define ADDR_DEV_TO_CPU(a)                  (a)
#endif

#ifndef HAL_CMU_DEFAULT_CRYSTAL_FREQ
#define HAL_CMU_DEFAULT_CRYSTAL_FREQ        26000000
#endif

#define LPU_TIMER_US(us)                    (((us) * 32 + 1000 - 1) / 1000)

// SIMU_RES
#define CMU_SIMU_RES_PASSED                 (0x9A55)
#define CMU_SIMU_RES_FAILED                 (0xFA11)
#define CMU_SIMU_RES_FINISHED               (0xAA66)

enum HAL_CMU_CLK_STATUS_T {
    HAL_CMU_CLK_DISABLED,
    HAL_CMU_CLK_ENABLED,
};

enum HAL_CMU_CLK_MODE_T {
    HAL_CMU_CLK_AUTO,
    HAL_CMU_CLK_MANUAL,
};

enum HAL_CMU_RST_STATUS_T {
    HAL_CMU_RST_SET,
    HAL_CMU_RST_CLR,
};

enum HAL_CMU_TIMER_ID_T {
    HAL_CMU_TIMER_ID_00,
    HAL_CMU_TIMER_ID_01,
    HAL_CMU_TIMER_ID_10,
    HAL_CMU_TIMER_ID_11,
    HAL_CMU_TIMER_ID_20,
    HAL_CMU_TIMER_ID_21,
};

#ifndef HAL_CMU_FREQ_T
enum HAL_CMU_FREQ_T {
    HAL_CMU_FREQ_32K,
    HAL_CMU_FREQ_26M,
    HAL_CMU_FREQ_52M,
    HAL_CMU_FREQ_78M,
    HAL_CMU_FREQ_104M,
    HAL_CMU_FREQ_208M,

    HAL_CMU_FREQ_QTY
};
#endif

#ifndef HAL_CMU_PLL_T
enum HAL_CMU_PLL_T {
    HAL_CMU_PLL_AUD,
    HAL_CMU_PLL_USB,

    HAL_CMU_PLL_QTY
};
#endif

#ifndef HAL_CMU_PLL_USER_T
enum HAL_CMU_PLL_USER_T {
    HAL_CMU_PLL_USER_SYS,
    HAL_CMU_PLL_USER_AUD,
    HAL_CMU_PLL_USER_USB,

    HAL_CMU_PLL_USER_QTY,
    HAL_CMU_PLL_USER_ALL = HAL_CMU_PLL_USER_QTY,
};
#endif

#ifndef HAL_CMU_PERIPH_FREQ_T
enum HAL_CMU_PERIPH_FREQ_T {
    HAL_CMU_PERIPH_FREQ_26M,
    HAL_CMU_PERIPH_FREQ_52M,

    HAL_CMU_PERIPH_FREQ_QTY
};
#endif

enum HAL_CMU_LPU_CLK_CFG_T {
    HAL_CMU_LPU_CLK_NONE,
    HAL_CMU_LPU_CLK_26M,
    HAL_CMU_LPU_CLK_PLL,

    HAL_CMU_LPU_CLK_QTY
};

enum HAL_CMU_LPU_SLEEP_MODE_T {
    HAL_CMU_LPU_SLEEP_MODE_BUS_32K,
    HAL_CMU_LPU_SLEEP_MODE_SUBSYS_32K,
    HAL_CMU_LPU_SLEEP_MODE_CPU_PD_BUS_32K,
    HAL_CMU_LPU_SLEEP_MODE_CPU_PD_SUBSYS_32K,
    HAL_CMU_LPU_SLEEP_MODE_SUBSYS_PD,

    HAL_CMU_LPU_SLEEP_MODE_QTY,
    HAL_CMU_LPU_SLEEP_MODE_SYS = HAL_CMU_LPU_SLEEP_MODE_BUS_32K,
    HAL_CMU_LPU_SLEEP_MODE_CHIP = HAL_CMU_LPU_SLEEP_MODE_SUBSYS_32K,
    HAL_CMU_LPU_SLEEP_MODE_POWER_DOWN = HAL_CMU_LPU_SLEEP_MODE_SUBSYS_PD,
};

#ifndef HAL_PWM_ID_T
enum HAL_PWM_ID_T {
    HAL_PWM_ID_0,
    HAL_PWM_ID_1,
    HAL_PWM_ID_2,
    HAL_PWM_ID_3,

    HAL_PWM_ID_QTY
};
#endif

#ifndef HAL_I2S_ID_T
enum HAL_I2S_ID_T {
    HAL_I2S_ID_0 = 0,

    HAL_I2S_ID_QTY,
};
#endif

#ifndef HAL_SPDIF_ID_T
enum HAL_SPDIF_ID_T {
    HAL_SPDIF_ID_0 = 0,

    HAL_SPDIF_ID_QTY,
};
#endif

enum HAL_CMU_USB_CLOCK_SEL_T {
    HAL_CMU_USB_CLOCK_SEL_PLL,
    HAL_CMU_USB_CLOCK_SEL_24M_X2,
    HAL_CMU_USB_CLOCK_SEL_48M,
    HAL_CMU_USB_CLOCK_SEL_26M_X2,
    HAL_CMU_USB_CLOCK_SEL_26M_X4,
};

enum HAL_FLASH_ID_T {
    HAL_FLASH_ID_0 = 0,
#ifdef FLASH1_CTRL_BASE
    HAL_FLASH_ID_1 = 1,
#endif
#ifdef FLASH2_CTRL_BASE
    HAL_FLASH_ID_2 = 2,
#endif
    HAL_FLASH_ID_NUM,
};

enum HAL_SDIO_ID_T {
    HAL_SDIO_ID_0 = 0,
#ifdef SDIO1_DEVICE_BASE
    HAL_SDIO_ID_1 = 1,
#endif
    HAL_SDIO_ID_NUM,
};

#ifndef HAL_CMU_I2S_MCLK_ID_T
enum HAL_CMU_I2S_MCLK_ID_T {
    HAL_CMU_I2S_MCLK_QTY,
};
#endif

struct CORE_STARTUP_CFG_T {
    __IO uint32_t stack;
    __IO uint32_t reset_hdlr;
};

#ifdef HAL_CMU_VALID_CRYSTAL_FREQ
void hal_cmu_set_crystal_freq_index(uint32_t index);

uint32_t hal_cmu_get_default_crystal_freq(void);

uint32_t hal_cmu_get_crystal_freq(void);
#else
//__STATIC_FORCEINLINE void hal_cmu_set_crystal_freq_index(uint32_t index) {}

//__STATIC_FORCEINLINE uint32_t hal_cmu_get_default_crystal_freq(void) {return HAL_CMU_DEFAULT_CRYSTAL_FREQ;}

__STATIC_FORCEINLINE uint32_t hal_cmu_get_crystal_freq(void) {return HAL_CMU_DEFAULT_CRYSTAL_FREQ;}
#endif

#ifdef CMU_FAST_TIMER_WITH_LOW_SYS_FREQ
uint32_t hal_cmu_get_fast_timer_freq(void);
#else
__STATIC_FORCEINLINE uint32_t hal_cmu_get_fast_timer_freq(void) {return hal_cmu_get_crystal_freq() / 4;}
#endif

int hal_cmu_clock_enable(enum HAL_CMU_MOD_ID_T id);

int hal_cmu_clock_disable(enum HAL_CMU_MOD_ID_T id);

enum HAL_CMU_CLK_STATUS_T hal_cmu_clock_get_status(enum HAL_CMU_MOD_ID_T id);

int hal_cmu_clock_set_mode(enum HAL_CMU_MOD_ID_T id, enum HAL_CMU_CLK_MODE_T mode);

enum HAL_CMU_CLK_MODE_T hal_cmu_clock_get_mode(enum HAL_CMU_MOD_ID_T id);

int hal_cmu_reset_set(enum HAL_CMU_MOD_ID_T id);

int hal_cmu_reset_clear(enum HAL_CMU_MOD_ID_T id);

enum HAL_CMU_RST_STATUS_T hal_cmu_reset_get_status(enum HAL_CMU_MOD_ID_T id);

int hal_cmu_reset_pulse(enum HAL_CMU_MOD_ID_T id);

int hal_cmu_timer_set_div(enum HAL_CMU_TIMER_ID_T id, uint32_t div);

void hal_cmu_timer0_select_fast(void);

void hal_cmu_timer0_select_slow(void);

void hal_cmu_timer1_select_fast(void);

void hal_cmu_timer1_select_slow(void);

void hal_cmu_timer2_select_fast(void);

void hal_cmu_timer2_select_slow(void);

void hal_cmu_dsp_timer0_select_fast(void);

void hal_cmu_dsp_timer0_select_slow(void);

void hal_cmu_dsp_timer1_select_fast(void);

void hal_cmu_dsp_timer1_select_slow(void);

int hal_cmu_timer_clock_enable(uint32_t timer_base);

int hal_cmu_timer_clock_disable(uint32_t timer_base);

int hal_cmu_xdma_clock_enable(uint32_t xdma_base);

int hal_cmu_xdma_clock_disable(uint32_t xdma_base);

int hal_cmu_periph_set_div(uint32_t div);

int hal_cmu_uart0_set_div(uint32_t div);

int hal_cmu_uart1_set_div(uint32_t div);

int hal_cmu_uart2_set_div(uint32_t div);

int hal_cmu_uart3_set_div(uint32_t div);

int hal_cmu_spi_set_div(uint32_t div);

int hal_cmu_slcd_set_div(uint32_t div);

int hal_cmu_sdio_set_div(uint32_t div);

int hal_cmu_sdmmc0_set_div(uint32_t div);

int hal_cmu_sdmmc1_set_div(uint32_t div);

int hal_cmu_i2c_set_div(uint32_t div);

int hal_cmu_i3c_set_div(uint32_t div);

int hal_cmu_uart0_set_freq(enum HAL_CMU_PERIPH_FREQ_T freq);

int hal_cmu_uart1_set_freq(enum HAL_CMU_PERIPH_FREQ_T freq);

int hal_cmu_uart2_set_freq(enum HAL_CMU_PERIPH_FREQ_T freq);

int hal_cmu_uart3_set_freq(enum HAL_CMU_PERIPH_FREQ_T freq);

int hal_cmu_spi_set_freq(enum HAL_CMU_PERIPH_FREQ_T freq);

int hal_cmu_slcd_set_freq(enum HAL_CMU_PERIPH_FREQ_T freq);

int hal_cmu_sdmmc0_set_freq(enum HAL_CMU_PERIPH_FREQ_T freq);

int hal_cmu_sdmmc1_set_freq(enum HAL_CMU_PERIPH_FREQ_T freq);

int hal_cmu_emmc_set_freq(enum HAL_CMU_PERIPH_FREQ_T freq);

int hal_cmu_i2c_set_freq(enum HAL_CMU_PERIPH_FREQ_T freq);

int hal_cmu_i3c_set_freq(enum HAL_CMU_PERIPH_FREQ_T freq);

int hal_cmu_ispi_set_freq(enum HAL_CMU_PERIPH_FREQ_T freq);

int hal_cmu_pwm_set_freq(enum HAL_PWM_ID_T id, uint32_t freq);

int hal_cmu_flash_set_freq(enum HAL_CMU_FREQ_T freq);

int hal_cmu_flash1_set_freq(enum HAL_CMU_FREQ_T freq);

int hal_cmu_flash2_set_freq(enum HAL_CMU_FREQ_T freq);

int hal_cmu_mem_set_freq(enum HAL_CMU_FREQ_T freq);

int hal_cmu_sys_set_freq(enum HAL_CMU_FREQ_T freq);

enum HAL_CMU_FREQ_T hal_cmu_sys_get_freq(void);

enum HAL_CMU_FREQ_T hal_cmu_flash_get_freq(void);

void hal_cmu_flash_all_reset_clear(int reset);

int hal_cmu_flash_all_select_pll(enum HAL_CMU_PLL_T pll);

int hal_cmu_flash_select_pll(enum HAL_CMU_PLL_T pll);

int hal_cmu_flash1_select_pll(enum HAL_CMU_PLL_T pll);

int hal_cmu_flash2_select_pll(enum HAL_CMU_PLL_T pll);

int hal_cmu_mem_select_pll(enum HAL_CMU_PLL_T pll);

int hal_cmu_emmc_select_pll(enum HAL_CMU_PLL_T pll);

int hal_cmu_sys_select_pll(enum HAL_CMU_PLL_T pll);

int hal_cmu_get_pll_status(enum HAL_CMU_PLL_T pll);

int hal_cmu_pll_enable(enum HAL_CMU_PLL_T pll, enum HAL_CMU_PLL_USER_T user);

int hal_cmu_pll_disable(enum HAL_CMU_PLL_T pll, enum HAL_CMU_PLL_USER_T user);

void hal_cmu_audio_resample_enable(void);

void hal_cmu_audio_resample_disable(void);

int hal_cmu_get_audio_resample_status(void);

int hal_cmu_codec_adc_set_div(uint32_t div);

uint32_t hal_cmu_codec_adc_get_div(void);

int hal_cmu_codec_dac_set_div(uint32_t div);

uint32_t hal_cmu_codec_dac_get_div(void);

void hal_cmu_codec_clock_enable(void);

void hal_cmu_codec_clock_disable(void);

void hal_cmu_codec_vad_clock_enable(int type);

void hal_cmu_codec_vad_clock_disable(int type);

void hal_cmu_codec_reset_set(void);

void hal_cmu_codec_reset_clear(void);

void hal_cmu_codec_iir_enable(uint32_t speed);

void hal_cmu_codec_iir_disable(void);

int hal_cmu_codec_iir_set_div(uint32_t div);

void hal_cmu_codec_iir_eq_enable(uint32_t speed);

void hal_cmu_codec_iir_eq_disable(void);

void hal_cmu_codec_psap_enable(uint32_t speed);

void hal_cmu_codec_psap_disable(void);

void hal_cmu_codec_fir_enable(uint32_t speed);

void hal_cmu_codec_fir_disable(void);

int hal_cmu_codec_fir_set_div(uint32_t div);

void hal_cmu_codec_fir_select_sys_clock(void);

void hal_cmu_codec_fir_select_own_clock(void);

void hal_cmu_codec_rs_enable(uint32_t speed);

void hal_cmu_codec_rs_disable(void);

int hal_cmu_codec_rs_set_div(uint32_t div);

void hal_cmu_codec_rs_adc_enable(uint32_t speed);

void hal_cmu_codec_rs_adc_disable(void);

int hal_cmu_codec_rs_adc_set_div(uint32_t div);

void hal_cmu_codec_set_fault_mask(uint32_t msk);

void hal_cmu_i2s_clock_out_enable(enum HAL_I2S_ID_T id);

void hal_cmu_i2s_clock_out_disable(enum HAL_I2S_ID_T id);

void hal_cmu_i2s_pol_clock_out_enable(enum HAL_I2S_ID_T id);

void hal_cmu_i2s_pol_clock_out_disable(enum HAL_I2S_ID_T id);

void hal_cmu_i2s_set_slave_mode(enum HAL_I2S_ID_T id);

void hal_cmu_i2s_set_master_mode(enum HAL_I2S_ID_T id);

void hal_cmu_i2s_clock_enable(enum HAL_I2S_ID_T id);

void hal_cmu_i2s_clock_disable(enum HAL_I2S_ID_T id);

int hal_cmu_i2s_set_div(enum HAL_I2S_ID_T id, uint32_t div);

void hal_cmu_i2s_resample_enable(enum HAL_I2S_ID_T id);

void hal_cmu_i2s_resample_disable(enum HAL_I2S_ID_T id);

void hal_cmu_i2s_clock_select_external(enum HAL_I2S_ID_T id);

void hal_cmu_i2s_clock_select_internal(enum HAL_I2S_ID_T id);

int hal_cmu_i2s_mclk_enable(enum HAL_CMU_I2S_MCLK_ID_T id);

void hal_cmu_i2s_mclk_disable(void);

int hal_cmu_sci_set_div(uint32_t div);

int hal_cmu_sci_reset(bool reset);

void hal_cmu_pcm_clock_out_enable(void);

void hal_cmu_pcm_clock_out_disable(void);

void hal_cmu_pcm_set_slave_mode(int clk_pol);

void hal_cmu_pcm_set_master_mode(void);

void hal_cmu_pcm_clock_enable(void);

void hal_cmu_pcm_clock_disable(void);

int hal_cmu_pcm_set_div(uint32_t div);

int hal_cmu_spdif_clock_enable(enum HAL_SPDIF_ID_T id);

int hal_cmu_spdif_clock_disable(enum HAL_SPDIF_ID_T id);

int hal_cmu_spdif_set_div(enum HAL_SPDIF_ID_T id, uint32_t div);

void hal_cmu_emmc_clock_enable(uint32_t freq);

void hal_cmu_emmc_clock_disable(void);

void hal_cmu_emmc_clock_continue(void);

void hal_cmu_emmc_clock_pause(void);

void hal_cmu_emmc_clock_switch(uint32_t freq);

void hal_cmu_emmc_phy_open(void);

void hal_cmu_emmc_phy_close(void);

void hal_cmu_emmc_phy_start(int on);

void hal_cmu_emmc_phy_sleep(void);

void hal_cmu_emmc_phy_wakeup(void);

void hal_cmu_sdmmc0_clock_enable(void);

void hal_cmu_sdmmc0_clock_disable(void);

void hal_cmu_sdmmc1_clock_enable(void);

void hal_cmu_sdmmc1_clock_disable(void);

void hal_cmu_i3c0_clock_enable(void);

void hal_cmu_i3c0_clock_disable(void);

void hal_cmu_i3c1_clock_enable(void);

void hal_cmu_i3c1_clock_disable(void);

void hal_cmu_sdio_device_clock_enable(void);

void hal_cmu_sdio_device_clock_disable(void);

void hal_cmu_sdio1_device_clock_enable(void);

void hal_cmu_sdio1_device_clock_disable(void);

void hal_cmu_usb_set_device_mode(void);

void hal_cmu_usb_set_host_mode(void);

enum HAL_CMU_USB_CLOCK_SEL_T hal_cmu_usb_rom_select_clock_source(int pll_en, unsigned int crystal);

void hal_cmu_usb_rom_set_clock_source(enum HAL_CMU_USB_CLOCK_SEL_T sel);

void hal_cmu_usb_clock_enable(void);

void hal_cmu_usb_clock_disable(void);

void hal_cmu_usb3_clock_enable(void);

void hal_cmu_usb3_clock_disable(void);

void hal_cmu_bt_clock_enable(void);

void hal_cmu_bt_clock_disable(void);

void hal_cmu_bt_reset_set(void);

void hal_cmu_bt_reset_clear(void);

void hal_cmu_bt_sys_reset_clear(void);

void hal_cmu_bt_cpu_reset_clear(void);

void hal_cmu_bt_module_init(void);

void hal_cmu_bt_sys_clock_force_on(void);

void hal_cmu_bt_sys_clock_auto(void);

void hal_cmu_bt_sys_force_ram_on(void);

void hal_cmu_bt_sys_force_ram_auto(void);

void hal_cmu_bt_sys_set_freq(enum HAL_CMU_FREQ_T freq);

int hal_cmu_clock_out_enable(enum HAL_CMU_CLOCK_OUT_ID_T id);

void hal_cmu_clock_out_disable(void);

void hal_cmu_write_lock(void);

void hal_cmu_write_unlock(void);

void hal_cmu_sys_reboot(void);

#if defined(ARM_CMNS)
void hal_cmu_sys_reboot_se(void);
#endif

void hal_cmu_jtag_enable(void);

void hal_cmu_jtag_disable(void);

void hal_cmu_jtag_clock_enable(void);

void hal_cmu_jtag_clock_disable(void);

void hal_cmu_simu_init(void);

void hal_cmu_simu_pass(void);

void hal_cmu_simu_fail(void);

void hal_cmu_simu_finish(void);

void hal_cmu_simu_tag(uint8_t shift);

void hal_cmu_simu_set_val(uint32_t val);

uint32_t hal_cmu_simu_get_val(void);

void hal_cmu_low_freq_mode_init(void);

void hal_cmu_low_freq_mode_enable(enum HAL_CMU_FREQ_T old_freq, enum HAL_CMU_FREQ_T new_freq);

void hal_cmu_low_freq_mode_disable(enum HAL_CMU_FREQ_T old_freq, enum HAL_CMU_FREQ_T new_freq);

void hal_cmu_subsys_setup(void);

void hal_cmu_rom_enable_pll(void);

void hal_cmu_programmer_enable_pll(void);

void hal_cmu_init_pll_selection(void);

void hal_cmu_rom_setup(void);

void hal_cmu_programmer_setup(void);

void hal_cmu_fpga_setup(void);

void hal_cmu_setup(void);

// Some internal functions

void hal_cmu_apb_init_div(void);

void hal_cmu_rom_clock_init(void);

void hal_cmu_init_chip_feature(uint16_t feature);

void hal_cmu_osc_x2_enable(void);

void hal_cmu_osc_x4_enable(void);

void hal_cmu_module_init_state(void);

void hal_cmu_lpu_wait_26m_ready(void);

int hal_cmu_lpu_busy(void);

int hal_cmu_lpu_init(enum HAL_CMU_LPU_CLK_CFG_T cfg);

int hal_cmu_lpu_sleep(enum HAL_CMU_LPU_SLEEP_MODE_T mode);

void hal_cmu_set_wakeup_pc(uint32_t pc);

void hal_cmu_set_wakeup_vector(uint32_t vector);

void hal_cmu_lcdc_clock_enable(uint32_t pixmhz);

void hal_cmu_lcdc_clock_disable(void);

void hal_cmu_lcdc_sleep(void);

void hal_cmu_lcdc_wakeup(void);

uint32_t hal_cmu_lcdc_get_pixmhz(void);

int hal_cmu_lcdc_set_pixmhz(uint32_t freqmhz);

uint32_t hal_cmu_lcdc_get_qspimhz(void);

int hal_cmu_lcdc_set_qspimhz(uint32_t freqmhz);

void hal_cmu_lcdc_qspi_clock_enable(uint32_t freqmhz);

void hal_cmu_lcdc_qspi_clock_disable(void);

void hal_cmu_lcdc_qspi_sleep(void);

void hal_cmu_lcdc_qspi_wakeup(void);

void hal_cmu_gpu_set_mhz(uint32_t freqmhz);

void hal_cmu_gpu_clock_enable(uint32_t freqmhz);

void hal_cmu_gpu_clock_disable(void);

void hal_cmu_gpu_wakeup(void);

void hal_cmu_gpu_sleep(void);

void hal_cmu_sec_eng_clock_enable(void);

void hal_cmu_sec_eng_clock_disable(void);

void hal_cmu_dma2d_clock_enable(uint32_t freqmhz);

void hal_cmu_dma2d_clock_disable(void);

void hal_cmu_dma2d_reset_set(void);

void hal_cmu_dma2d_reset_clear(void);

void hal_cmu_dma2d_wakeup(void);

void hal_cmu_dma2d_sleep(void);

uint32_t addr_remap_cpu_to_dev(uint32_t addr);

uint32_t addr_remap_dev_to_cpu(uint32_t addr);

void hal_cmu_gamu_clock_enable(void);

void hal_cmu_gamu_clock_disable(void);

void hal_cmu_gamu_sleep(void);

void hal_cmu_gamu_wakeup(void);

void hal_cmu_crc_clock_enable(void);

void hal_cmu_crc_clock_disable(void);

void hal_cmu_checksum_clock_enable(void);

void hal_cmu_checksum_clock_disable(void);

void hal_cmu_shanhai_clock_enable(void);

void hal_cmu_shanhai_clock_disable(void);

void hal_cmu_wdt_sleep(void);

void hal_cmu_wdt_wakeup(void);

#ifdef __cplusplus
}
#endif

#endif

