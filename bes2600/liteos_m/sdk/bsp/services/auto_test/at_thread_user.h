/*
 * Copyright (c) 2021 Bestechnic (Shanghai) Co., Ltd. All rights reserved.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef __AT_THREAD_USER_H__
#define __AT_THREAD_USER_H__

#ifdef __cplusplus
extern "C" {
#endif

enum THREAD_USER_ID
{
    THREAD_USER0,
    THREAD_USER1,
    THREAD_USER2,
    THREAD_USER3,
    THREAD_USER4,
    THREAD_USER_COUNT,
};

typedef struct {
	uint32_t id;
	uint32_t ptr;
	uint32_t param0;
	uint32_t param1;
} AT_USER_MESSAGE;

typedef enum
{
    RF_FREQUENCY_2402 = 0x31,//'1'
    RF_FREQUENCY_2441,
	RF_FREQUENCY_2480,
	RF_FREQUENCY_2440,
	RF_CHANNEL_BLE_STOP, //'5'
	RF_FREQUENCY_2402_RX,//'6'
	RF_FREQUENCY_2480_RX,
	RF_FREQUENCY_2440_RX

}RF_FREQUENCY_E;
typedef enum
{
    RF_CHANNEL_DH3,
	RF_CHANNEL_DH5,
	RF_CHANNEL_2DH5,
	RF_CHANNEL_3DH5

}RF_CHANNEL_E;

typedef enum
{
	RF_TX,
	RF_RX

}RF_TXRX_E;

typedef enum
{
    MODEUNKNOW,
    TWSMODEMASTER,
    TWSMODESLAVE,
    TWSMODEFREEMAN

}GTK_FACTORY_TEST_TWS_MODE;

void BleFrequencyTestStartRx(uint8_t index);
void BleFrequencyTestStart(uint8_t index);
void BleFrequencyTestStop();
void BtFrequencyTestStart(uint8_t index);
void BtFrequencyTestStop();
bool BleNosignalTestConfigPara(uint8_t index);
bool BtNosignalTestConfigPara(uint8_t channel,  uint8_t frequency, uint8_t tx_rx);
bool StopBTRfTest(void);

#define AT_USER_MESSAGE_ID_CMD    0

bool at_thread_user_is_inited(enum THREAD_USER_ID user_id);
int at_thread_user_init(enum THREAD_USER_ID user_id);
int at_thread_user_enqueue_cmd(enum THREAD_USER_ID user_id,
        uint32_t cmd_id,
        uint32_t param0,
        uint32_t param1,
        uint32_t pfunc
        );
#ifdef __cplusplus
	}
#endif

#endif // __AT_THREAD_USER_H__

