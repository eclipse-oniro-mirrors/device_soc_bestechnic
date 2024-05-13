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
#ifndef __HAL_I2C_H__
#define __HAL_I2C_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "plat_addr_map.h"
#include "plat_types.h"
#include "hal_gpio.h"

// For 10-bit address devices: OR the following mask with the real address
#define HAL_I2C_10BITADDR_MASK              (1 << 15)

enum HAL_I2C_ACTION_AFTER_WRITE_T {
    HAL_I2C_STOP_AFTER_WRITE = 0,
    HAL_I2C_RESTART_AFTER_WRITE,
};

enum HAL_I2C_ID_T {
    HAL_I2C_ID_0 = 0,
#ifdef I2C1_BASE
    HAL_I2C_ID_1,
#endif
#ifdef I2C2_BASE
    HAL_I2C_ID_2,
#endif
#ifdef I2C3_BASE
    HAL_I2C_ID_3,
#endif
#ifdef I2C4_BASE
    HAL_I2C_ID_4,
#endif
#ifdef I2C5_BASE
    HAL_I2C_ID_5,
#endif
#ifdef I2C6_BASE
    HAL_I2C_ID_6,
#endif
#ifdef I2C7_BASE
    HAL_I2C_ID_7,
#endif

    HAL_I2C_ID_NUM,
};

enum HAL_I2C_TASK_USER_T {
    HAL_I2C_TASK_USER_0 = 0,
    HAL_I2C_TASK_USER_1,
    HAL_I2C_TASK_USER_2,
    HAL_I2C_TASK_USER_3,
    HAL_I2C_TASK_USER_4,
    HAL_I2C_TASK_USER_5,
    HAL_I2C_TASK_USER_6,
    HAL_I2C_TASK_USER_7,

    HAL_I2C_TASK_USER_NUM,
};

enum HAL_I2C_API_MODE_T {
    HAL_I2C_API_MODE_TASK = 0,
    HAL_I2C_API_MODE_SIMPLE,
    HAL_I2C_API_MODE_SENSOR_ENGINE,
};

enum HAL_I2C_INT_STATUS_T {
    // Same as i2cip intr status definitions
    HAL_I2C_INT_STATUS_GEN_CALL_MASK    = (1 << 11),
    HAL_I2C_INT_STATUS_START_DET_MASK   = (1 << 10),
    HAL_I2C_INT_STATUS_STOP_DET_MASK    = (1 << 9),
    HAL_I2C_INT_STATUS_ACTIVITY_MASK    = (1 << 8),
    HAL_I2C_INT_STATUS_RX_DONE_MASK     = (1 << 7),
    HAL_I2C_INT_STATUS_TX_ABRT_MASK     = (1 << 6),
    HAL_I2C_INT_STATUS_RD_REQ_MASK      = (1 << 5),
    HAL_I2C_INT_STATUS_TX_EMPTY_MASK    = (1 << 4),
    HAL_I2C_INT_STATUS_TX_OVER_MASK     = (1 << 3),
    HAL_I2C_INT_STATUS_RX_FULL_MASK     = (1 << 2),
    HAL_I2C_INT_STATUS_RX_OVER_MASK     = (1 << 1),
    HAL_I2C_INT_STATUS_RX_UNDER_MASK    = (1 << 0),
};

enum HAL_I2C_ERRCODE_T {
    HAL_I2C_ERRCODE_INV_PARAM           = (1 << 31),
    HAL_I2C_ERRCODE_IN_USE              = (1 << 30),
    HAL_I2C_ERRCODE_FIFO_ERR            = (1 << 29),
    HAL_I2C_ERRCODE_SYNC_TIMEOUT        = (1 << 28),
    HAL_I2C_ERRCODE_ACT_TIMEOUT         = (1 << 27),
    HAL_I2C_ERRCODE_TFNF_TIMEOUT        = (1 << 26),
    HAL_I2C_ERRCODE_TFE_TIMEOUT         = (1 << 25),
    HAL_I2C_ERRCODE_RFNE_TIMEOUT        = (1 << 24),
    HAL_I2C_ERRCODE_CLOSED              = (1 << 23),
    HAL_I2C_ERRCODE_CANCELLED           = (1 << 22),
    HAL_I2C_ERRCODE_NO_RX_TIMER         = (1 << 21),
    HAL_I2C_ERRCODE_EXTRA_RX            = (1 << 20),

    // Same as i2cip tx abort source definitions
    HAL_I2C_ERRCODE_SLVRD_INTX          = (1 << 15),
    HAL_I2C_ERRCODE_SLV_ARBLOST         = (1 << 14),
    HAL_I2C_ERRCODE_SLVFLUSH_TXFIFO     = (1 << 13),
    HAL_I2C_ERRCODE_ARB_LOST            = (1 << 12),
    HAL_I2C_ERRCODE_MASTER_DIS          = (1 << 11),
    HAL_I2C_ERRCODE_10B_RD_NORSTRT      = (1 << 10),
    HAL_I2C_ERRCODE_SBYTE_NORSTRT       = (1 << 9),
    HAL_I2C_ERRCODE_HS_NORSTRT          = (1 << 8),
    HAL_I2C_ERRCODE_SBYTE_ACKDET        = (1 << 7),
    HAL_I2C_ERRCODE_HS_ACKDET           = (1 << 6),
    HAL_I2C_ERRCODE_GCALL_READ          = (1 << 5),
    HAL_I2C_ERRCODE_GCALL_NOACK         = (1 << 4),
    HAL_I2C_ERRCODE_TXDATA_NOACK        = (1 << 3),
    HAL_I2C_ERRCODE_10ADDR2_NOACK       = (1 << 2),
    HAL_I2C_ERRCODE_10ADDR1_NOACK       = (1 << 1),
    HAL_I2C_ERRCODE_7B_ADDR_NOACK       = (1 << 0),
};

struct HAL_I2C_CONFIG_T {
    /* mode
     SIMPLE_MODE : pulling when reading or writing (always sync), or use dma external;master or slave;only enable slave related irq;
     TASK_MODE : task to driven reading or writing (sync or async, dma or non-dma);only master
     */
    enum HAL_I2C_API_MODE_T mode;

    uint8_t use_sync    : 1;
    uint8_t use_dma     : 1;
    uint8_t as_master   : 1;
    // Set rising_time_ns to tune I2C speed (0 to use default value)
    uint16_t rising_time_ns;
    uint32_t speed;
    uint32_t addr_as_slave;
};

struct HAL_GPIO_I2C_CONFIG_T {
    enum HAL_GPIO_PIN_T scl;
    enum HAL_GPIO_PIN_T sda;
    uint32_t speed;
};

uint32_t hal_i2c_open(enum HAL_I2C_ID_T id, const struct HAL_I2C_CONFIG_T *cfg);
uint32_t hal_i2c_close(enum HAL_I2C_ID_T id);

/* for master task mode */
typedef void (*HAL_I2C_TRANSFER_HANDLER_T)(enum HAL_I2C_ID_T id, uint32_t transfer_id,
                                            const uint8_t *tx_buf, uint32_t tx_len,
                                            const uint8_t *rx_buf, uint32_t rx_len,
                                            enum HAL_I2C_ERRCODE_T errcode);
uint32_t hal_i2c_send(enum HAL_I2C_ID_T id, uint32_t device_addr, uint8_t *buf, uint32_t reg_len, uint32_t value_len,
        uint32_t transfer_id, HAL_I2C_TRANSFER_HANDLER_T handler);
uint32_t hal_i2c_recv(enum HAL_I2C_ID_T id, uint32_t device_addr, uint8_t *buf, uint32_t reg_len, uint32_t value_len,
        uint8_t restart_after_write, uint32_t transfer_id, HAL_I2C_TRANSFER_HANDLER_T handler);
// New I2C task mode APIs
uint32_t hal_i2c_task_open(enum HAL_I2C_ID_T id, enum HAL_I2C_TASK_USER_T user, const struct HAL_I2C_CONFIG_T *cfg);
uint32_t hal_i2c_task_close(enum HAL_I2C_ID_T id, enum HAL_I2C_TASK_USER_T user);
uint32_t hal_i2c_task_send(enum HAL_I2C_ID_T id, uint16_t device_addr, const uint8_t *tx_buf, uint16_t tx_len,
        uint32_t transfer_id, HAL_I2C_TRANSFER_HANDLER_T handler);
uint32_t hal_i2c_task_recv(enum HAL_I2C_ID_T id, uint16_t device_addr, const uint8_t *tx_buf, uint16_t tx_len,
        uint8_t *rx_buf, uint16_t rx_len,
        uint32_t transfer_id, HAL_I2C_TRANSFER_HANDLER_T handler);
uint32_t hal_i2c_task_msend(enum HAL_I2C_ID_T id, uint16_t device_addr, const uint8_t *tx_buf, uint16_t tx_item_len,
        uint16_t item_cnt, uint32_t transfer_id, HAL_I2C_TRANSFER_HANDLER_T handler);
uint32_t hal_i2c_task_mrecv(enum HAL_I2C_ID_T id, uint16_t device_addr, const uint8_t *tx_buf, uint16_t tx_item_len,
        uint8_t *rx_buf, uint16_t rx_item_len, uint16_t item_cnt,
        uint32_t transfer_id, HAL_I2C_TRANSFER_HANDLER_T handler);
uint32_t hal_i2c_cancel_active_task(enum HAL_I2C_ID_T id);
/* for master task mode end */

/* for slave and simple master mode */
typedef void (*HAL_I2C_SLAVE_TRANSFER_HANDLER_T)(enum HAL_I2C_ID_T id, uint32_t transport_dir,
                                            const uint8_t *tx_buf, uint32_t tx_len,
                                            const uint8_t *rx_buf, uint32_t rx_len,
                                            enum HAL_I2C_ERRCODE_T errcode);
typedef void (*HAL_I2C_RD_REQ_HANDLER_T)(enum HAL_I2C_ID_T id, uint32_t reg_addr, uint8_t **tx_buf,
                                            uint32_t *tx_len, enum HAL_I2C_ERRCODE_T errcode);
typedef void (*HAL_I2C_INT_HANDLER_T)(enum HAL_I2C_ID_T id, enum HAL_I2C_INT_STATUS_T status, uint32_t errocode);
uint32_t hal_i2c_slv_simple_send_raw(enum HAL_I2C_ID_T id, const uint8_t *tx_buf, uint32_t tx_len, uint32_t yield);
uint32_t hal_i2c_slv_simple_send(enum HAL_I2C_ID_T id, const uint8_t *tx_buf, uint32_t tx_len, uint32_t yield);
uint32_t hal_i2c_slv_simple_recv(enum HAL_I2C_ID_T id, uint8_t *rx_buf, uint32_t rx_len, uint32_t yield);
uint32_t hal_i2c_slv_task_send_recv(enum HAL_I2C_ID_T id, uint8_t *rx_buf, uint32_t rx_len, uint32_t transfer_id, HAL_I2C_SLAVE_TRANSFER_HANDLER_T handler, HAL_I2C_RD_REQ_HANDLER_T rd_req_handler);
uint32_t hal_i2c_set_interrupt_handler(enum HAL_I2C_ID_T id, HAL_I2C_INT_HANDLER_T handler);
uint32_t hal_i2c_mst_write(enum HAL_I2C_ID_T id, uint32_t device_addr, const uint8_t *buf, uint32_t buf_len, uint32_t *act_len, uint32_t restart, uint32_t stop, uint32_t yield);
uint32_t hal_i2c_mst_read(enum HAL_I2C_ID_T id, uint32_t device_addr, uint8_t *buf, uint32_t buf_len, uint32_t *act_len, uint32_t restart, uint32_t stop, uint32_t yield);
// New I2C simple mode APIs
uint32_t hal_i2c_simple_send(enum HAL_I2C_ID_T id, uint16_t device_addr, const uint8_t *tx_buf, uint16_t tx_len);
uint32_t hal_i2c_simple_recv(enum HAL_I2C_ID_T id, uint16_t device_addr, const uint8_t *tx_buf, uint16_t tx_len, uint8_t *rx_buf, uint16_t rx_len);
/* for slave and simple master mode end */

/* for gpio i2c */
int hal_gpio_i2c_open(const struct HAL_GPIO_I2C_CONFIG_T *cfg);
int hal_gpio_i2c_close(const struct HAL_GPIO_I2C_CONFIG_T *cfg);
int hal_gpio_i2c_recovery(const struct HAL_GPIO_I2C_CONFIG_T *cfg, uint8_t retry_cnt);
uint32_t hal_gpio_i2c_send(const struct HAL_GPIO_I2C_CONFIG_T *cfg, uint32_t device_addr, const uint8_t *buf, uint32_t reg_len, uint32_t value_len);
uint32_t hal_gpio_i2c_recv(const struct HAL_GPIO_I2C_CONFIG_T *cfg, uint32_t device_addr, uint8_t *buf, uint32_t reg_len, uint32_t value_len, uint8_t restart_after_write);
// New GPIO I2C APIs
uint32_t hal_gpio_i2c_simple_send(const struct HAL_GPIO_I2C_CONFIG_T *cfg, uint32_t device_addr, const uint8_t *tx_buf, uint16_t tx_len);
uint32_t hal_gpio_i2c_simple_recv(const struct HAL_GPIO_I2C_CONFIG_T *cfg, uint32_t device_addr, const uint8_t *tx_buf, uint16_t tx_len, uint8_t *rx_buf, uint16_t rx_len);
/* for gpio i2c end */

#ifdef __cplusplus
}
#endif

#endif /* __HAL_I2C_H__ */
