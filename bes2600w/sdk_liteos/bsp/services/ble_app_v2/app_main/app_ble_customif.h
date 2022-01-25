/***************************************************************************
*
*Copyright 2015-2019 BES.
*All rights reserved. All unpublished rights reserved.
*
*No part of this work may be used or reproduced in any form or by any
*means, or stored in a database or retrieval system, without prior written
*permission of BES.
*
*Use of this work is governed by a license granted by BES.
*This work contains confidential and proprietary information of
*BES. which is protected by copyright, trade secret,
*trademark and other intellectual property rights.
*
****************************************************************************/

#ifndef __APP_BLE_CUSTOMIF_H__
#define __APP_BLE_CUSTOMIF_H__

/*****************************header include********************************/

/******************************macro defination*****************************/

/******************************type defination******************************/

#ifdef __cplusplus
extern "C" {
#endif

#ifdef USE_BT_ADAPTER
typedef void (*ble_adv_data_report_cb_t)(ble_bdaddr_t *bleAddr,          int8_t rssi,uint8_t *adv_buf,uint8_t len);
void app_ble_adv_report_callback_register(ble_adv_data_report_cb_t cb);
void app_ble_adv_report_callback_deregister(void);
#endif
/*---------------------------------------------------------------------------
 *            app_ble_customif_init
 *---------------------------------------------------------------------------
 *
 *Synopsis:
 *    None
 *
 * Parameters:
 *    void
 *
 * Return:
 *    void
 */
void app_ble_customif_init(void);


#ifdef __cplusplus
}
#endif

#endif /* #ifndef __APP_BLE_CUSTOMIF_H__ */

