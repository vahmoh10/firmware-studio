// SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
// SPDX-License-Identifier: AGPL-3.0-only

#ifndef FIRMWARE_COMPILER_H
#define FIRMWARE_COMPILER_H

#ifndef __GNUC__
    #error "compiler is not supported"
#endif

#ifdef __GNUC__
    #define FIRMWARE_SECTION(NAME) __attribute__((section(NAME)))
#else
    #define FIRMWARE_SECTION(NAME)
#endif

#ifdef __GNUC__
    #define FIRMWARE_USED __attribute__((used))
#else
    #define FIRMWARE_USED
#endif

#endif
