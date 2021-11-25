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

#ifndef __WIFI_SRV_H__
#define __WIFI_SRV_H__

#include "wifi_agent.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    WIFI_SRV_UNINIT = 0,
    WIFI_SRV_READY,
    WIFI_SRV_NET_READY,
} WIFI_SRV_STATUS_T;

int wifi_srv_send2peer(int msg, int data_len, void *data, int sync);
int wifi_srv_init(void);

extern struct wifi_init_paras wifi_paras;

#ifdef __cplusplus
}
#endif

#endif


