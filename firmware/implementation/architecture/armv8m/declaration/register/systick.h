// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_ARCHITECTURE_ARMV8M_REGISTER_SYSTICK_H
#define FIRMWARE_ARCHITECTURE_ARMV8M_REGISTER_SYSTICK_H

#include <stdint.h>

#define SYSTICK_SYST_CSR_ENABLE_POSITION 0
#define SYSTICK_SYST_CSR_TICKINT_POSITION 1
#define SYSTICK_SYST_CSR_CLKSOURCE_POSITION 2

typedef struct {
    uint32_t SYST_CSR;
    uint32_t SYST_RVR;
    uint32_t SYST_CVR;
} systick_t;

#define SYSTICK ((volatile systick_t *)0xE000E010)

#endif
