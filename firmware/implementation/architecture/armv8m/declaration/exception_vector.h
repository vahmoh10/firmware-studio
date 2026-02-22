// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_ARCHITECTURE_ARMV8M_EXCEPTION_VECTOR_H
#define FIRMWARE_ARCHITECTURE_ARMV8M_EXCEPTION_VECTOR_H

#include <firmware/compiler.h>

void Reset_Handler(void);

FIRMWARE_NAKED
void PendSV_Handler(void);

void SysTick_Handler(void);

[[noreturn]]
void Default_Handler(void);

#endif
