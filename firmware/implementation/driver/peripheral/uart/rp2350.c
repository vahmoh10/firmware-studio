// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#include <firmware/driver/peripheral/uart.h>

#include <firmware/microcontroller/rp2350/register/clocks.h>
#include <firmware/microcontroller/rp2350/register/io_bank0.h>
#include <firmware/microcontroller/rp2350/register/pads_bank0.h>
#include <firmware/microcontroller/rp2350/register/resets.h>
#include <firmware/microcontroller/rp2350/register/uart.h>
#include <firmware/microcontroller/rp2350/register/xosc.h>

void uart_initialize(void) {
    XOSC->CTRL = XOSC_CTRL_ENABLE_ENABLE << XOSC_CTRL_ENABLE_POSITION;
    CLOCKS->CLK_REF_CTRL = CLOCKS_CLK_REF_CTRL_SRC_XOSC_CLKSRC & CLOCKS_CLK_REF_CTRL_SRC_MASK;
    CLOCKS->CLK_PERI_CTRL |= 1u << CLOCKS_CLK_PERI_CTRL_ENABLE_POSITION;
    RESETS->RESET &= ~(1u << RESETS_RESET_UART0_POSITION);
    PADS_BANK0->GPIO[0] &= ~(1u << PADS_BANK0_GPIO_ISO_POSITION);
    IO_BANK0->GPIO[0].CTRL = IO_BANK0_GPIO_CTRL_FUNCSEL_UART;
    UART0->UARTIBRD = 6;
    UART0->UARTFBRD = 33;
    UART0->UARTLCR_H = (UART_UARTLCR_H_WLEN_8 & UART_UARTLCR_H_WLEN_MASK) << UART_UARTLCR_H_WLEN_POSITION;
    UART0->UARTCR |= 1u << UART_UARTCR_UARTEN_POSITION;
}

void uart_write(const char* data) {
    if (data == nullptr) {
        return;
    }
    while (*data) {
        while ((UART0->UARTFR & (1u << UART_UARTFR_TXFF_POSITION)) != 0) {
        }
        UART0->UARTDR = *data;
        data++;
    }
}
