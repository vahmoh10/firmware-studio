# SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
# SPDX-License-Identifier: AGPL-3.0-only

if(NOT DEFINED MICROCONTROLLER)
    message(FATAL_ERROR "MICROCONTROLLER is not defined")
endif()

set(SUPPORTED_MICROCONTROLLERS
    "rp2350"
)

if(NOT MICROCONTROLLER IN_LIST SUPPORTED_MICROCONTROLLERS)
    message(FATAL_ERROR "${MICROCONTROLLER} is not supported")
endif()

add_library(link_options INTERFACE)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(LINK_OPTIONS
        -T${CMAKE_CURRENT_SOURCE_DIR}/implementation/microcontroller/${MICROCONTROLLER}/linker.ld
        -nostdlib
    )
else()
    message(FATAL_ERROR "${CMAKE_C_COMPILER_ID} is not supported")
endif()

target_link_options(link_options INTERFACE ${LINK_OPTIONS})
