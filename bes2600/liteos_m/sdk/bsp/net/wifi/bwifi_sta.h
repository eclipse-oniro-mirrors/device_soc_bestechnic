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

#ifndef BWIFI_STA_H
#define BWIFI_STA_H

#ifdef  __cplusplus
extern "C"
{
#endif

#ifndef ETH_ALEN
#define ETH_ALEN 6
#endif

struct bwifi_station_config {
    u8 ssid[33];
    u8 passwd[65];//passwd for encrypted ssid, set "all zero" for unencryped ssid
    int8_t wep_keyid;//for wep,[0-3] default val:0
    u8 hidden;//1:hidden
    u8 bssid[ETH_ALEN];//bssid or "all zero"
    u8 mfp;
};
struct bwifi_quick_connect_config {
    struct bwifi_station_config config;
    uint32_t channel;
    uint32_t ip[3];//struct ip_info ip;
};

#ifdef  __cplusplus
}
#endif

#endif /*BWIFI_STA_H*/
