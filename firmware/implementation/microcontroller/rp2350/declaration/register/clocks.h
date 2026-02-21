// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_CLOCKS_H
#define FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_CLOCKS_H

#include <stdint.h>

#define CLOCKS_CLK_REF_CTRL_SRC_MASK 0x3u
#define CLOCKS_CLK_PERI_CTRL_ENABLE_POSITION 11

typedef enum : uint8_t {
    CLOCKS_CLK_REF_CTRL_SRC_XOSC_CLKSRC = 0x2,
} clocks_clk_ref_ctrl_src_t;

typedef struct {
    uint32_t CTRL;
    uint32_t DIV;
    uint32_t SELECTED;
} clocks_clk_gpout_t;

typedef struct {
    clocks_clk_gpout_t GPIO[4];
    uint32_t CLK_REF_CTRL;
    uint32_t CLK_REF_DIV;
    uint32_t CLK_REF_SELECTED;
    uint32_t CLK_SYS_CTRL;
    uint32_t CLK_SYS_DIV;
    uint32_t CLK_SYS_SELECTED;
    uint32_t CLK_PERI_CTRL;
    uint32_t CLK_PERI_DIV;
    uint32_t CLK_PERI_SELECTED;
} clocks_t;

#define CLOCKS ((volatile clocks_t *)0x40010000)

#endif
