// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_SIO_H
#define FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_SIO_H

#include <stdint.h>

typedef struct {
    const uint32_t CPUID;
    const uint32_t GPIO_IN;
    const uint32_t GPIO_HI_IN;
    const uint32_t RESERVED;
    uint32_t GPIO_OUT;
    uint32_t GPIO_HI_OUT;
    uint32_t GPIO_OUT_SET;
    uint32_t GPIO_HI_OUT_SET;
    uint32_t GPIO_OUT_CLR;
    uint32_t GPIO_HI_OUT_CLR;
    uint32_t GPIO_OUT_XOR;
    uint32_t GPIO_HI_OUT_XOR;
    uint32_t GPIO_OE;
    uint32_t GPIO_HI_OE;
    uint32_t GPIO_OE_SET;
    uint32_t GPIO_HI_OE_SET;
    uint32_t GPIO_OE_CLR;
    uint32_t GPIO_HI_OE_CLR;
    uint32_t GPIO_OE_XOR;
    uint32_t GPIO_HI_OE_XOR;
} sio_t;

#define SIO ((volatile sio_t *)0xD0000000)

#endif
