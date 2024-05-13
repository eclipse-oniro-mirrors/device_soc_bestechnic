/***************************************************************************
 *
 * Copyright 2015-2020 BES.
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
#ifndef __BTM_MEDIATOR__H__
#define __BTM_MEDIATOR__H__
#include "bluetooth.h"
#ifdef __cplusplus
extern "C" {
#endif

#define BTM_ACTIVITY_ENV_NUM            BT_ACL_MAX_LINK_NUMS // activity number set to as same as bt device number temperorily
#define BTM_IBRT_SWITCH_RETRY_MAX       10

typedef enum {
    ACTIVITY_IDLE                       = 0,
    ACTIVITY_RESERVED                   = 1,
    ACTIVITY_PENDING                    = 2,
    ACTIVITY_ONGOING                    = 3,
    ACTIVITY_W4_RETRY                   = 4,
}BT_ACTIVITY_STATE_E;

typedef enum {
    PAGE_ACTIVITY_IDX                   = 0,
    START_IBRT_ACTIVITY_IDX             = 1,
    IBRT_SWITCH_ACTIVITY_IDX            = 2,

    BT_ACTIVITY_IDX_NUM,
}BT_ACTIVITY_ID_E;

typedef struct {
    struct bdaddr_t bdaddr;
} btm_page_para_t;

typedef struct {
    uint16_t slaveConnHandle;
    uint16_t mobileConnHandle;
} btm_start_ibrt_para_t;

typedef struct {
    uint16_t mobileConnHandle;
} btm_ibrt_switch_para_t;

typedef struct {
    uint16_t mobileConnHandle;
    uint8_t  reason;
} btm_stop_ibrt_para_t;

typedef union {
    btm_page_para_t         pagePara;
    btm_start_ibrt_para_t   startIbrtPara;
    btm_ibrt_switch_para_t  ibrtSwitchPara;
    btm_stop_ibrt_para_t    stopIbrtPara;
} btm_activity_para_t;


typedef struct {
    struct list_node        node;
    BT_ACTIVITY_STATE_E     activityState;
    uint8_t                 activityRetryCnt;
    uint8_t                 activityRetryTimer;
    uint32_t                inListTimeStamp;
    btm_activity_para_t     activityPara;
} btm_activity_env_t;

typedef struct {
    //struct list_node freeActivityList;
    struct list_node        pendingActivityList;
    struct list_node        ongoingActivityList;
    uint8_t                 ongoingCnt;
    btm_activity_env_t      activityEnv[BTM_ACTIVITY_ENV_NUM];
} btm_activity_mediator_t;

void btm_me_mediator_init(void);

btm_activity_mediator_t *btm_me_get_activity(void);

bt_status_t btm_activity_start(BT_ACTIVITY_ID_E activity, btm_activity_para_t* activityPara);

bt_status_t btm_page_activity_start(btm_page_para_t* pagePara);

bt_status_t btm_start_ibrt_activity_start(btm_start_ibrt_para_t* startIbrtPara);

bt_status_t btm_ibrt_switch_activity_start(btm_ibrt_switch_para_t* ibrtSwitchPara);

btm_activity_env_t* btm_get_free_activity_env(BT_ACTIVITY_ID_E activity);

bool btm_check_is_activity_exist(BT_ACTIVITY_ID_E activity,btm_activity_para_t* activityPara);

uint8_t btm_get_activity_ongoing_cnt(BT_ACTIVITY_ID_E activity);

bool btm_mediator_event_handler(uint16_t evt_id, void* pdata);

BT_ACTIVITY_ID_E btm_start_ibrt_result_handle(uint8_t err_code, uint16_t conhandle, bool *isNeedRetry);

BT_ACTIVITY_ID_E btm_ibrt_switch_result_handle(uint8_t err_code, uint16_t conhandle, bool *isNeedRetry);

BT_ACTIVITY_ID_E btm_page_result_handle(uint8_t err_code, bt_bdaddr_t* addr);

BT_ACTIVITY_ID_E btm_ibrt_disconnect_stop_all_activity(uint16_t conhandle);

void btm_mediator_check_pending_activity(BT_ACTIVITY_ID_E stoppedActivity);

#ifdef __cplusplus
}
#endif
#endif              /* __BTM_MEDIATOR__H__ */