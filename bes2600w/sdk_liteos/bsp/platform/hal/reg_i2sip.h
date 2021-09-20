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
#ifndef __REG_I2SIP_H_
#define __REG_I2SIP_H_

#include "plat_types.h"

#define I2SIP_FIFO_DEPTH 8
#define I2SIP_CHAN_REG_SIZE 0x40
#define I2SIP_CHAN_REG(c, r) (c * I2SIP_CHAN_REG_SIZE + r)

/* i2sip register */
/* enable register */
#define I2SIP_ENABLE_REG_REG_OFFSET 0x0
#define I2SIP_ENABLE_REG_I2S_ENABLE_SHIFT (0)
#define I2SIP_ENABLE_REG_I2S_ENABLE_MASK ((0x1)<<I2SIP_ENABLE_REG_I2S_ENABLE_SHIFT)
#ifndef CHIP_BEST1000
#define I2SIP_ENABLE_REG_SLAVE_MODE_SHIFT (1)
#define I2SIP_ENABLE_REG_SLAVE_MODE_MASK (1 << I2SIP_ENABLE_REG_SLAVE_MODE_SHIFT)
#endif
#define I2SIP_ENABLE_REG_SPDIF_ENABLE_SHIFT (8)
#define I2SIP_ENABLE_REG_SPDIF_ENABLE_MASK ((0x1)<<I2SIP_ENABLE_REG_SPDIF_ENABLE_SHIFT)

/* recv block enable register */
#define I2SIP_RX_BLOCK_ENABLE_REG_REG_OFFSET 0x4
#define I2SIP_RX_BLOCK_ENABLE_REG_ENABLE_SHIFT (0)
#define I2SIP_RX_BLOCK_ENABLE_REG_ENABLE_MASK ((0x1)<<I2SIP_RX_BLOCK_ENABLE_REG_ENABLE_SHIFT)

/* send block enable register */
#define I2SIP_TX_BLOCK_ENABLE_REG_REG_OFFSET 0x8
#define I2SIP_TX_BLOCK_ENABLE_REG_ENABLE_SHIFT (0)
#define I2SIP_TX_BLOCK_ENABLE_REG_ENABLE_MASK ((0x1)<<I2SIP_TX_BLOCK_ENABLE_REG_ENABLE_SHIFT)

/* clk gen enable register */
#define I2SIP_CLK_GEN_ENABLE_REG_REG_OFFSET 0xc
#define I2SIP_CLK_GEN_ENABLE_REG_ENABLE_SHIFT (0)
#define I2SIP_CLK_GEN_ENABLE_REG_ENABLE_MASK ((0x1)<<I2SIP_CLK_GEN_ENABLE_REG_ENABLE_SHIFT)

/* clk config register */
#define I2SIP_CLK_CFG_REG_OFFSET 0x10
#define I2SIP_CLK_CFG_WSS_SHIFT (3)
#define I2SIP_CLK_CFG_WSS_MASK ((0x3)<<I2SIP_CLK_CFG_WSS_SHIFT)
#define I2SIP_CLK_CFG_WSS_VAL_16CYCLE 0
#define I2SIP_CLK_CFG_WSS_VAL_24CYCLE 1
#define I2SIP_CLK_CFG_WSS_VAL_32CYCLE 2

#define I2SIP_CLK_CFG_SCLK_GATE_SHIFT (0)
#define I2SIP_CLK_CFG_SCLK_GATE_MASK ((0x7)<<I2SIP_CLK_CFG_SCLK_GATE_SHIFT)
#define I2SIP_CLK_CFG_SCLK_GATE_VAL_NO_GATE 0
#define I2SIP_CLK_CFG_SCLK_GATE_VAL_12_GATE 1
#define I2SIP_CLK_CFG_SCLK_GATE_VAL_16_GATE 2
#define I2SIP_CLK_CFG_SCLK_GATE_VAL_20_GATE 3
#define I2SIP_CLK_CFG_SCLK_GATE_VAL_24_GATE 4

/* recv block fifo reset register */
#define I2SIP_RX_BLOCK_FIFO_RESET_REG_OFFSET 0x14
#define I2SIP_RX_BLOCK_FIFO_RESET_RESET_SHIFT (0)
#define I2SIP_RX_BLOCK_FIFO_RESET_RESET_MASK ((0x1)<<I2SIP_RX_BLOCK_FIFO_RESET_RESET_SHIFT)

/* send block fifo reset register */
#define I2SIP_TX_BLOCK_FIFO_RESET_REG_OFFSET 0x18
#define I2SIP_TX_BLOCK_FIFO_RESET_RESET_SHIFT (0)
#define I2SIP_TX_BLOCK_FIFO_RESET_RESET_MASK ((0x1)<<I2SIP_TX_BLOCK_FIFO_RESET_RESET_SHIFT)

/* left recv buffer register */
#define I2SIP_LEFT_RX_BUFF_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x20)

/* left send buffer register */
#define I2SIP_LEFT_TX_BUFF_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x20)

/* right recv buffer register */
#define I2SIP_RIGHT_RX_BUFF_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x24)

/* right send buffer register */
#define I2SIP_RIGHT_TX_BUFF_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x24)

/* channel 0 */
/* recv enable register */
#define I2SIP_RX_ENABLE_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x28)
#define I2SIP_RX_ENABLE_ENABLE_SHIFT (0)
#define I2SIP_RX_ENABLE_ENABLE_MASK ((0x1)<<I2SIP_RX_ENABLE_ENABLE_SHIFT)

/* send enable register */
#define I2SIP_TX_ENABLE_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x2c)
#define I2SIP_TX_ENABLE_ENABLE_SHIFT (0)
#define I2SIP_TX_ENABLE_ENABLE_MASK ((0x1)<<I2SIP_TX_ENABLE_ENABLE_SHIFT)

/* recv config register */
#define I2SIP_RX_CFG_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x30)
#define I2SIP_RX_CFG_WLEN_SHIFT (0)
#define I2SIP_RX_CFG_WLEN_MASK ((0x7)<<I2SIP_RX_CFG_WLEN_SHIFT)
#define I2SIP_RX_CFG_WLEN_VAL_IGNORE 0
#define I2SIP_RX_CFG_WLEN_VAL_12BIT 1
#define I2SIP_RX_CFG_WLEN_VAL_16BIT 2
#define I2SIP_RX_CFG_WLEN_VAL_20BIT 3
#define I2SIP_RX_CFG_WLEN_VAL_24BIT 4
#define I2SIP_RX_CFG_WLEN_VAL_32BIT 5

/* send config register */
#define I2SIP_TX_CFG_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x34)
#define I2SIP_TX_CFG_WLEN_SHIFT (0)
#define I2SIP_TX_CFG_WLEN_MASK ((0x7)<<I2SIP_TX_CFG_WLEN_SHIFT)
#define I2SIP_TX_CFG_WLEN_VAL_IGNORE 0
#define I2SIP_TX_CFG_WLEN_VAL_12BIT 1
#define I2SIP_TX_CFG_WLEN_VAL_16BIT 2
#define I2SIP_TX_CFG_WLEN_VAL_20BIT 3
#define I2SIP_TX_CFG_WLEN_VAL_24BIT 4
#define I2SIP_TX_CFG_WLEN_VAL_32BIT 5

/* recv or send config register */
#define I2SIP_CFG_WLEN_VAL_IGNORE 0
#define I2SIP_CFG_WLEN_VAL_12BIT  1
#define I2SIP_CFG_WLEN_VAL_16BIT  2
#define I2SIP_CFG_WLEN_VAL_20BIT  3
#define I2SIP_CFG_WLEN_VAL_24BIT  4
#define I2SIP_CFG_WLEN_VAL_32BIT  5


/* int status register */
#define I2SIP_INT_STATUS_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x38)
#define I2SIP_INT_STATUS_TX_FIFO_OVER_SHIFT (5)
#define I2SIP_INT_STATUS_TX_FIFO_OVER_MASK ((0x1)<<I2SIP_INT_STATUS_TX_FIFO_OVER_SHIFT)
#define I2SIP_INT_STATUS_TX_FIFO_EMPTY_SHIFT (4)
#define I2SIP_INT_STATUS_TX_FIFO_EMPTY_MASK ((0x1)<<I2SIP_INT_STATUS_TX_FIFO_EMPTY_SHIFT)
#define I2SIP_INT_STATUS_RX_FIFO_OVER_SHIFT (1)
#define I2SIP_INT_STATUS_RX_FIFO_OVER_MASK ((0x1)<<I2SIP_INT_STATUS_RX_FIFO_OVER_SHIFT)
#define I2SIP_INT_STATUS_RX_FIFO_DA_SHIFT (0)
#define I2SIP_INT_STATUS_RX_FIFO_DA_MASK ((0x1)<<I2SIP_INT_STATUS_RX_FIFO_DA_SHIFT)

/* int mask register */
#define I2SIP_INT_MASK_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x3c)
#define I2SIP_INT_MASK_TX_FIFO_OVER_SHIFT (5)
#define I2SIP_INT_MASK_TX_FIFO_OVER_MASK ((0x1)<<I2SIP_INT_MASK_TX_FIFO_OVER_SHIFT)
#define I2SIP_INT_MASK_TX_FIFO_EMPTY_SHIFT (4)
#define I2SIP_INT_MASK_TX_FIFO_EMPTY_MASK ((0x1)<<I2SIP_INT_MASK_TX_FIFO_EMPTY_SHIFT)
#define I2SIP_INT_MASK_RX_FIFO_OVER_SHIFT (1)
#define I2SIP_INT_MASK_RX_FIFO_OVER_MASK ((0x1)<<I2SIP_INT_MASK_RX_FIFO_OVER_SHIFT)
#define I2SIP_INT_MASK_RX_FIFO_DA_SHIFT (0)
#define I2SIP_INT_MASK_RX_FIFO_DA_MASK ((0x1)<<I2SIP_INT_MASK_RX_FIFO_DA_SHIFT)
#define I2SIP_INT_MASK_ALL \
    (I2SIP_INT_MASK_TX_FIFO_OVER_MASK|I2SIP_INT_MASK_TX_FIFO_EMPTY_MASK|I2SIP_INT_MASK_RX_FIFO_OVER_MASK|I2SIP_INT_MASK_RX_FIFO_DA_MASK)
#define I2SIP_INT_UNMASK_ALL 0

/* clr recv over flow register */
#define I2SIP_CLR_RX_OVER_FLOW_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x40)
#define I2SIP_CLR_RX_OVER_FLOW_CLR_SHIFT (0)
#define I2SIP_CLR_RX_OVER_FLOW_CLR_MASK ((0x1)<<I2SIP_CLR_RX_OVER_FLOW_CLR_SHIFT)

/* clr send over flow register */
#define I2SIP_CLR_TX_OVER_FLOW_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x44)
#define I2SIP_CLR_TX_OVER_FLOW_CLR_SHIFT (0)
#define I2SIP_CLR_TX_OVER_FLOW_CLR_MASK ((0x1)<<I2SIP_CLR_TX_OVER_FLOW_CLR_SHIFT)

/* recv fifo config register */
#define I2SIP_RX_FIFO_CFG_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x48)
#define I2SIP_RX_FIFO_CFG_LEVEL_SHIFT (0)
#define I2SIP_RX_FIFO_CFG_LEVEL_MASK ((0xf)<<I2SIP_RX_FIFO_CFG_LEVEL_SHIFT)

/* send fifo config register */
#define I2SIP_TX_FIFO_CFG_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x4c)
#define I2SIP_TX_FIFO_CFG_LEVEL_SHIFT (0)
#define I2SIP_TX_FIFO_CFG_LEVEL_MASK ((0xf)<<I2SIP_TX_FIFO_CFG_LEVEL_SHIFT)

/* recv fifo flush register */
#define I2SIP_RX_FIFO_FLUSH_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x50)
#define I2SIP_RX_FIFO_FLUSH_SHIFT (0)
#define I2SIP_RX_FIFO_FLUSH_MASK ((0x1)<<I2SIP_RX_FIFO_FLUSH_SHIFT)

/* send fifo flush register */
#define I2SIP_TX_FIFO_FLUSH_REG_OFFSET(c) I2SIP_CHAN_REG(c, 0x54)
#define I2SIP_TX_FIFO_FLUSH_SHIFT (0)
#define I2SIP_TX_FIFO_FLUSH_MASK ((0x1)<<I2SIP_TX_FIFO_FLUSH_SHIFT)

/* dma ctrl register */
#ifdef CHIP_BEST1000
#define I2SIP_DMA_CTRL_REG_OFFSET 0x58
#define I2SIP_DMA_CTRL_RX_ENABLE_SHIFT (0)
#define I2SIP_DMA_CTRL_RX_ENABLE_MASK ((0x1)<<I2SIP_DMA_CTRL_RX_ENABLE_SHIFT)
#define I2SIP_DMA_CTRL_TX_ENABLE_SHIFT (1)
#define I2SIP_DMA_CTRL_TX_ENABLE_MASK ((0x1)<<I2SIP_DMA_CTRL_TX_ENABLE_SHIFT)
#else
#define I2SIP_DMA_CTRL_REG_OFFSET 0x1c8
#define I2SIP_DMA_CTRL_RX_ENABLE_SHIFT (0)
#define I2SIP_DMA_CTRL_RX_ENABLE_MASK ((0x1)<<I2SIP_DMA_CTRL_RX_ENABLE_SHIFT)
#define I2SIP_DMA_CTRL_TX_ENABLE_SHIFT (1)
#define I2SIP_DMA_CTRL_TX_ENABLE_MASK ((0x1)<<I2SIP_DMA_CTRL_TX_ENABLE_SHIFT)
#define I2SIP_DMA_CTRL_RX_1_CHAN_SHIFT (2)
#define I2SIP_DMA_CTRL_RX_1_CHAN_MASK (1 << I2SIP_DMA_CTRL_RX_1_CHAN_SHIFT)
#define I2SIP_DMA_CTRL_TX_1_CHAN_SHIFT (3)
#define I2SIP_DMA_CTRL_TX_1_CHAN_MASK (1 << I2SIP_DMA_CTRL_TX_1_CHAN_SHIFT)
#define I2SIP_DMA_CTRL_RX_CHAN_SEL_SHIFT (4)
#define I2SIP_DMA_CTRL_RX_CHAN_SEL_MASK (3 << I2SIP_DMA_CTRL_RX_CHAN_SEL_SHIFT)
#define I2SIP_DMA_CTRL_RX_CHAN_SEL(n) BITFIELD_VAL(I2SIP_DMA_CTRL_RX_CHAN_SEL, n)
#define I2SIP_DMA_CTRL_TX_CHAN_SEL_SHIFT (6)
#define I2SIP_DMA_CTRL_TX_CHAN_SEL_MASK (3 << I2SIP_DMA_CTRL_TX_CHAN_SEL_SHIFT)
#define I2SIP_DMA_CTRL_TX_CHAN_SEL(n) BITFIELD_VAL(I2SIP_DMA_CTRL_TX_CHAN_SEL, n)
#define I2SIP_DMA_CTRL_RX_DMA_BLK_SIZE_SHIFT (16)
#define I2SIP_DMA_CTRL_RX_DMA_BLK_SIZE_MASK (0xF << I2SIP_DMA_CTRL_RX_DMA_BLK_SIZE_SHIFT)
#define I2SIP_DMA_CTRL_RX_DMA_BLK_SIZE(n) BITFIELD_VAL(I2SIP_DMA_CTRL_RX_DMA_BLK_SIZE, n)
#define I2SIP_DMA_CTRL_RX_FIFO_PUSH_REALIGN_SHIFT (20)
#define I2SIP_DMA_CTRL_RX_FIFO_PUSH_REALIGN_MASK (1 << I2SIP_DMA_CTRL_RX_FIFO_PUSH_REALIGN_SHIFT)
#define I2SIP_DMA_CTRL_RX_FIFO_POP_REALIGN_SHIFT (21)
#define I2SIP_DMA_CTRL_RX_FIFO_POP_REALIGN_MASK (1 << I2SIP_DMA_CTRL_RX_FIFO_POP_REALIGN_SHIFT)
#define I2SIP_DMA_CTRL_RX_DMA_BLK_EN_SHIFT (22)
#define I2SIP_DMA_CTRL_RX_DMA_BLK_EN_MASK (1 << I2SIP_DMA_CTRL_RX_DMA_BLK_EN_SHIFT)
#define I2SIP_DMA_CTRL_TX_DMA_BLK_SIZE_SHIFT (24)
#define I2SIP_DMA_CTRL_TX_DMA_BLK_SIZE_MASK (0xF << I2SIP_DMA_CTRL_TX_DMA_BLK_SIZE_SHIFT)
#define I2SIP_DMA_CTRL_TX_DMA_BLK_SIZE(n) BITFIELD_VAL(I2SIP_DMA_CTRL_TX_DMA_BLK_SIZE, n)
#define I2SIP_DMA_CTRL_TX_FIFO_PUSH_REALIGN_SHIFT (28)
#define I2SIP_DMA_CTRL_TX_FIFO_PUSH_REALIGN_MASK (1 << I2SIP_DMA_CTRL_TX_FIFO_PUSH_REALIGN_SHIFT)
#define I2SIP_DMA_CTRL_TX_FIFO_POP_REALIGN_SHIFT (29)
#define I2SIP_DMA_CTRL_TX_FIFO_POP_REALIGN_MASK (1 << I2SIP_DMA_CTRL_TX_FIFO_POP_REALIGN_SHIFT)
#define I2SIP_DMA_CTRL_TX_DMA_BLK_EN_SHIFT (30)
#define I2SIP_DMA_CTRL_TX_DMA_BLK_EN_MASK (1 << I2SIP_DMA_CTRL_TX_DMA_BLK_EN_SHIFT)
#endif
/* tdm ctrl register */
#define I2SIP_TDM_CTRL_REG_OFFSET 0x1d0
/* channel 0 end */

/* i2s trigger register */
#define I2SIP_EN_SEL_OFFSET 0x1d4
#define I2SIP_TX_EN_SEL_SHIFT (0)
#define I2SIP_TX_EN_SEL_MASK ((0x3)<<I2SIP_TX_EN_SEL_SHIFT)
#define I2SIP_TX_EN_SEL(n) BITFIELD_VAL(I2SIP_TX_EN_SEL, n)
#define I2SIP_RX_EN_SEL_SHIFT (2)
#define I2SIP_RX_EN_SEL_MASK ((0x3)<<I2SIP_RX_EN_SEL_SHIFT)
#define I2SIP_RX_EN_SEL(n) BITFIELD_VAL(I2SIP_RX_EN_SEL, n)
#define I2SIP_CLK_EN_SEL_SHIFT (4)
#define I2SIP_CLK_EN_SEL_MASK ((0x3)<<I2SIP_CLK_EN_SEL_SHIFT)
#define I2SIP_CLK_EN_SEL(n) BITFIELD_VAL(I2SIP_CLK_EN_SEL, n)

#define I2SIP_TSF_EVENT_SEL (1 << 6)

/* i2sip register end */

#endif /* __REG_I2SIP_H_ */