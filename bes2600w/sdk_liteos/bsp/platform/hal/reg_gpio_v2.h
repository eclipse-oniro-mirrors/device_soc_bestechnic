/*
 * Copyright (c) 2021 bestechnic (Shanghai) Technologies CO., LIMITED.
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
#ifndef __REG_GPIO_V2_H__
#define __REG_GPIO_V2_H__

#include "plat_types.h"

struct GPIO_PORT_T {
    __IO uint32_t GPIO_DR;                              // 0x00
    __IO uint32_t GPIO_DDR;                             // 0x04
    __IO uint32_t GPIO_CTL;                             // 0x08
};

struct GPIO_BANK_T {
    __IO uint32_t GPIO_DR_SET;                          // 0x00
    __IO uint32_t GPIO_DDR_SET;                         // 0x04
    __IO uint32_t GPIO_CTL_SET;                         // 0x08
    __IO uint32_t GPIO_DR_CLR;                          // 0x0C
    __IO uint32_t GPIO_DDR_CLR;                         // 0x10
    __IO uint32_t GPIO_CTL_CLR;                         // 0x14
    __IO uint32_t GPIO_INTEN_CLR;                       // 0x18
    __IO uint32_t GPIO_INTMASK_CLR;                     // 0x1C
    __IO uint32_t GPIO_INTTYPE_LEVEL_CLR;               // 0x20
    __IO uint32_t GPIO_INT_POLARITY_CLR;                // 0x24
    __IO uint32_t GPIO_DEBOUNCE_CLR;                    // 0x28
    __IO uint32_t RESERVED_2C;                          // 0x2C
    __IO uint32_t GPIO_INTEN_SET;                       // 0x30
    __IO uint32_t GPIO_INTMASK_SET;                     // 0x34
    __IO uint32_t GPIO_INTTYPE_LEVEL_SET;               // 0x38
    __IO uint32_t GPIO_INT_POLARITY_SET;                // 0x3C
    __I  uint32_t GPIO_INTSTATUS;                       // 0x40
    __I  uint32_t GPIO_RAW_INTSTATUS;                   // 0x44
    __IO uint32_t GPIO_DEBOUNCE_SET;                    // 0x48
    __O  uint32_t GPIO_PORTA_EOI;                       // 0x4C
    __I  uint32_t GPIO_EXT_PORT;                        // 0x50
    __IO uint32_t RESERVED_54[3];                       // 0x54
    __IO uint32_t GPIO_LS_SYNC;                         // 0x60
};

#endif
