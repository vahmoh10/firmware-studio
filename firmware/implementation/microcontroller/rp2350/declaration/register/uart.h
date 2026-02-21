// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_UART_H
#define FIRMWARE_MICROCONTROLLER_RP2350_REGISTER_UART_H

#include <stdint.h>

#define UART_UARTFR_TXFF_POSITION 5
#define UART_UARTCR_UARTEN_POSITION 0
#define UART_UARTCR_WLEN_POSITION 5
#define UART_UARTCR_WLEN_MASK 0x3u

typedef enum : uint8_t {
    UART_UARTLCR_H_WLEN_5 = 0,
    UART_UARTLCR_H_WLEN_6 = 1,
    UART_UARTLCR_H_WLEN_7 = 2,
    UART_UARTLCR_H_WLEN_8 = 3,
} uart_uartlcr_h_wlen_t;

typedef struct {
    uint32_t UARTDR;
    uint32_t UARTRSR;
    uint32_t RESERVED0[4];
    uint32_t UARTFR;
    uint32_t RESERVED1;
    uint32_t UARTILPR;
    uint32_t UARTIBRD;
    uint32_t UARTFBRD;
    uint32_t UARLCR_H;
    uint32_t UARTCR;
} uart_t;

#define UART0 ((volatile uart_t *)0x40070000)
#define UART1 ((volatile uart_t *)0x40078000)

#endif
