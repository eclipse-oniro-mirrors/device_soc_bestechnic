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
#include "string.h"
#include "cmsis.h"
#ifdef RTOS
#include "cmsis_os.h"
#endif
#include "hal_timer.h"
#include "hal_mcu2cp.h"
#include "hal_cmu.h"
#include "cp_ipc.h"

static CP_IPC_MSG_CB ipc_rx_handler[IPC_MSG_TYPE_NUM] = {NULL};

static CP_IPC_MSG_CB ipc_tx_handler[IPC_MSG_TYPE_NUM] = {NULL};

#ifdef CP_BUILD
static uint32_t mcu2cp_msg_arrived(const unsigned char *data, unsigned int len)
{
    CP_IPC_MSG_HDR *msg = (CP_IPC_MSG_HDR *) data;

    if (msg || msg->id < IPC_MSG_TYPE_NUM) {
        if (ipc_rx_handler[msg->id])
            ipc_rx_handler[msg->id]((void *)data);
    }

    return len;
}

static void cp2mcu_msg_sent(const unsigned char *data, unsigned int len)
{
    CP_IPC_MSG_HDR *msg = (CP_IPC_MSG_HDR *) data;

    if (msg || msg->id < IPC_MSG_TYPE_NUM) {
        if (ipc_tx_handler[msg->id])
            ipc_tx_handler[msg->id]((void *)data);
    }
}
#else
static unsigned int cp2mcu_msg_arrived(const unsigned char *data, unsigned int len)
{
    CP_IPC_MSG_HDR *msg = (CP_IPC_MSG_HDR *) data;

    if (msg || msg->id < IPC_MSG_TYPE_NUM) {
        if (ipc_rx_handler[msg->id])
            ipc_rx_handler[msg->id]((void *)data);
    }

    return len;
}

static void mcu2cp_msg_sent(const unsigned char *data, unsigned int len)
{
    CP_IPC_MSG_HDR *msg = (CP_IPC_MSG_HDR *) data;

    if (msg || msg->id < IPC_MSG_TYPE_NUM) {
        if (ipc_tx_handler[msg->id])
            ipc_tx_handler[msg->id]((void *)data);
    }
}

static unsigned int cp2mcu_sys_arrived(const unsigned char *data, unsigned int len)
{
    return len;
}
#endif

int cp_ipc_init()
{
#ifdef CP_BUILD
    hal_mcu2cp_set_send_msg_list_cp();
#else
    /* use cmu dbg reg to store the base address of send msg list when cp run seperate image */
    hal_cmu_dbg_set_val(0, 0);
    hal_cmu_dbg_set_val(1, 0);
    hal_mcu2cp_set_send_msg_list_mcu();
#endif

    return 0;
}

int cp_ipc_start()
{
#ifdef CP_BUILD
    /* wait mcu init send msg addr */
    while (hal_mcu2cp_get_send_msg_list_mcu() == NULL)
        osDelay(100);

    hal_mcu2cp_open_cp(HAL_MCU2CP_ID_0, mcu2cp_msg_arrived, cp2mcu_msg_sent, false);
    hal_mcu2cp_start_recv_cp(HAL_MCU2CP_ID_0);

#ifdef HAL_MCU2CP_ID_1
    hal_mcu2cp_open_cp(HAL_MCU2CP_ID_1, NULL, NULL, false);
    hal_mcu2cp_start_recv_cp(HAL_MCU2CP_ID_1);
#endif
#else
    /* wait cp to init cmu dbg reg */
    while (hal_mcu2cp_get_send_msg_list_cp() == NULL)
        osDelay(100);

    hal_mcu2cp_open_mcu(HAL_MCU2CP_ID_0, cp2mcu_msg_arrived, mcu2cp_msg_sent, false);
    hal_mcu2cp_start_recv_mcu(HAL_MCU2CP_ID_0);

#ifdef HAL_MCU2CP_ID_1
    hal_mcu2cp_open_mcu(HAL_MCU2CP_ID_1, cp2mcu_sys_arrived, NULL, false);
    hal_mcu2cp_start_recv_mcu(HAL_MCU2CP_ID_1);
#endif
#endif

    return 0;
}

int cp_ipc_send(CP_IPC_MSG_HDR *msg)
{
    int ret;

    if (!msg)
        return -1;

#ifdef CP_BUILD
    ret = hal_mcu2cp_send_cp(HAL_MCU2CP_ID_0, (const unsigned char *)msg, sizeof(CP_IPC_MSG_HDR));
#else
    ret = hal_mcu2cp_send_mcu(HAL_MCU2CP_ID_0, (const unsigned char *)msg, sizeof(CP_IPC_MSG_HDR));
#endif

    return ret;
}

int cp_ipc_send_self(CP_IPC_MSG_HDR *msg)
{
    int ret = 0;

    if (!msg)
        return -1;

#ifdef CP_BUILD
    mcu2cp_msg_arrived((const unsigned char *)msg, 0);
#else
    cp2mcu_msg_arrived((const unsigned char *)msg, 0);
#endif

    return ret;
}

int cp_ipc_cb_set(CP_IPC_MSG_TYPE type, CP_IPC_MSG_CB func, bool tx)
{
    if (type >= IPC_MSG_TYPE_NUM)
        return -1;

    if (tx) {
        ipc_tx_handler[type] = func;
    } else
        ipc_rx_handler[type] = func;

    return 0;
}
