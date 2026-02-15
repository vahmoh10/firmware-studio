# SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
# SPDX-License-Identifier: AGPL-3.0-only

add_library(link_options INTERFACE)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    set(LINK_OPTIONS -nostdlib)
else()
    message(FATAL_ERROR "${CMAKE_C_COMPILER_ID} is not supported")
endif()

target_link_options(link_options INTERFACE ${LINK_OPTIONS})
