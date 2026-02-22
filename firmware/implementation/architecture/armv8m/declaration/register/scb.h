// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_ARCHITECTURE_ARMV8M_REGISTER_SCB_H
#define FIRMWARE_ARCHITECTURE_ARMV8M_REGISTER_SCB_H

#include <stdint.h>

#define SCB_ICSR_PENDSVSET_POSITION 28

typedef struct {
    const uint32_t CPUID;
    uint32_t ICSR;
} scb_t;

#define SCB ((volatile scb_t *)0xE000ED00)

#endif
