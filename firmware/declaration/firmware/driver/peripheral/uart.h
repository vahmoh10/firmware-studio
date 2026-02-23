// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_DRIVER_PERIPHERAL_UART_H
#define FIRMWARE_DRIVER_PERIPHERAL_UART_H

void uart_initialize(void);
void uart_write(const char* data);

#endif
