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
#ifndef __RFCOMM_I_H__
#define __RFCOMM_I_H__
#include "co_ppbuff.h"
#include "l2cap_i.h"
#if defined(__cplusplus)
extern "C" {
#endif

#define HSP_HS_SERVER_CHANNEL 1
#define HSP_AG_SERVER_CHANNEL 2
#define HF_CFG_SERVER_CHANNEL 3
#define AG_CFG_SERVER_CHANNEL 4
#define PBAP_CFG_SERVER_CHANNEL 5
#define MAS_CFG_SERVER_CHANNEL  6
#define MNS_CFG_SERVER_CHANNEL  7
#define OPP_CFG_SERVER_CHANNEL  8

struct rfcomm_ctx_input {
    struct ctx_content ctx;
    struct bdaddr_t *remote;
    uint32 l2cap_handle;
};

struct rfcomm_ctx_output {
    uint32 rfcomm_handle;
    bt_socket_t socket;
};

enum rfcomm_session_state_enum {
    SESSION_CLOSE,          /*l2cap connection closed, wait for openning, and then can send out sabm request*/
    SESSION_L2CAP_CHANNEL_CREATING,
    SESSION_CONNECT,      /*l2cap channel created*/
    SESSION_WAITING_OPEN, /*has sent sabm of dlci 0, wait ack*/
    SESSION_OPEN,            /* rfcomm session created, means dlci 0 created ok */
    SESSION_CLOSING       /* all dlc disced, dlci 0 wait to close */
};

#define RFCOMM_OPEN_WAIT_SESSION_TIME_MS (100)
#define RFCOMM_OPEN_WAIT_SESSION_COUNT (5)
#define RFCOMM_OPEN_WAIT_DLC_TIME_MS (1000)
#define RFCOMM_OPEN_REQUEST_WAIT_MS (8000)

struct rfcomm_open_request_t
{
    bt_service_port_t *port;
    void *sock_priv;
    uint8_t remote_server_channel;
    uint8_t remote_uuid_len;
    struct bdaddr_t remote;
    uint8_t wait_timer_id;
    uint8_t timer_wait_count;
    uint8_t uuid[2]; // keep uuid as the last filed
};

#define RFCOMM_OPEN_INFO_MAX_SIZE 8

struct rfcomm_open_item_t {
    struct rfcomm_open_request_t *req;
};

struct rfcomm_session {
    uint32_t l2cap_handle;
    bool initiator;
    enum rfcomm_session_state_enum state;
    bt_bdaddr_t remote;
    struct list_node dlcs;
    struct rfcomm_open_item_t open_waits[RFCOMM_OPEN_INFO_MAX_SIZE];
};

void rfcomm_init(void);
int8 rfcomm_send(uint32 rfcomm_handle, uint8 *data, uint32 datalen, void *priv);
int8 rfcomm_send_hfp_at_cmd(uint32 rfcomm_handle, uint8 *data, uint32 datalen, void *priv, bool insert_head, bool give_credit_with_uih);
bt_status_t rfcomm_close(uint32_t rfcomm_handle);
bt_status_t rfcomm_close_v2(uint32_t rfcomm_handle, uint8_t reason);
uint32 rfcomm_get_l2cap_handle(uint32 rfcomm_handle);
bool rfcomm_l2cap_channle_is_creating(struct bdaddr_t *remote);
uint32_t rfcomm_get_session_l2cap_handle(const bt_bdaddr_t *remote);
bool rfcomm_is_dlc_connecting(uint32_t session_handle, uint8_t local_server_channel);
void rfcomm_give_handled_credits(uint32_t rfcomm_handle, uint16_t handled_credits);
void rfcomm_dlc_set_socket_priv(uint32_t rfcomm_handle, void *sock_priv);
struct pp_buff *rfcomm_data_ppb_alloc(uint32_t rfcomm_handle, uint16_t datalen, void *priv, uint32_t ca, uint32_t line);
struct rfcomm_session *rfcomm_get_session(const bt_bdaddr_t *remote);

bt_status_t rfcomm_create_port(uint16_t local_server_channel, bt_socket_callback_t socket_callback, const bt_sdp_record_attr_t *attr_list, uint16_t attr_count);
bt_status_t rfcomm_set_rx_credits(uint16_t local_server_channel, bool upper_layer_give_credit, uint16_t initial_credits, uint16_t credit_give_step);
bt_status_t rfcomm_listen(uint16_t local_server_channel, bool support_multi_device, bt_socket_accept_callback_t accept_callback);
bt_status_t rfcomm_remove_listen(uint16_t local_server_channel);
bt_status_t rfcomm_connect(const bt_bdaddr_t *remote, uint16_t local_server_channel, const uint8_t *uuid, uint16_t uuid_len, void *priv);
bt_status_t rfcomm_connect_server_channel(const bt_bdaddr_t *remote, uint16_t local_server_channel, uint16_t remote_server_channel, void *priv);
bt_status_t rfcomm_write(uint32_t rfcomm_handle, struct pp_buff *ppb);
bt_status_t rfcomm_disconnect(uint32_t rfcomm_handle, uint8_t reason);

#ifdef IBRT
void rfcomm_ibrt_slave_release_dlc(uint8_t device_id, uint8_t dlci);
void rfcomm_start_save_credit_before_switch(const bt_bdaddr_t *remote);
uint32 rfcomm_save_ctx(uint32 rfcomm_handle, uint8_t *buf, uint32_t buf_len);
uint32 rfcomm_restore_ctx(struct rfcomm_ctx_input *input, struct rfcomm_ctx_output *output, void *sock_priv);
#endif

void rfcomm_pts_register_dlci2_channel1(void);
void pts_rfcomm_close(void);
void pts_rfcomm_close_dlci0(void);
void pts_rfcomm_send_data(void);

#if defined(__cplusplus)
}
#endif
#endif /* __RFCOMM_I_H__ */
