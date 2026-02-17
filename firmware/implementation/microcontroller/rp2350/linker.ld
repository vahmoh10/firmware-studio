# SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
# SPDX-License-Identifier: AGPL-3.0-only

MEMORY {
    FLASH (rx): ORIGIN = 0x10000000, LENGTH = 4M
    SRAM (rwx): ORIGIN = 0x20000000, LENGTH = 520K
}

SECTIONS {
    .vector_table : {
        *(.vector_table)
    } > FLASH

    .image_def : {
        *(.image_def)
    } > FLASH

    .text : {
        *(.text)
    } > FLASH

    .rodata : {
        *(.rodata)
    } > FLASH

    .data : {
        data_start = .;
        *(.data)
        data_end = .;
    } > SRAM AT > FLASH

    data_load = LOADADDR(.data);

    .bss : {
        bss_start = .;
        *(.bss)
        bss_end = .;
    } > SRAM

    stack_top = ORIGIN(SRAM) + LENGTH(SRAM);
}
