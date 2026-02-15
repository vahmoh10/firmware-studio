# SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
# SPDX-License-Identifier: AGPL-3.0-only

if(NOT DEFINED CPU)
    message(FATAL_ERROR "CPU is not defined")
endif()

set(SUPPORTED_CPUS
    "cortex-m33"
)

if(NOT CPU IN_LIST SUPPORTED_CPUS)
    message(FATAL_ERROR "${CPU} is not supported")
endif()

add_library(compile_options INTERFACE)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(COMPILE_OPTIONS -Wall -Wextra -Wpedantic -Werror -mcpu=${CPU})
else()
    message(FATAL_ERROR "${CMAKE_C_COMPILER_ID} is not supported")
endif()

target_link_options(compile_options INTERFACE ${COMPILE_OPTIONS})
