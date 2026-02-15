# SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
# SPDX-License-Identifier: AGPL-3.0-only

if(NOT IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${MICROCONTROLLER}")
    message(FATAL_ERROR "${MICROCONTROLLER} is not supported")
endif()

add_library(microcontroller STATIC)

target_include_directories(microcontroller PRIVATE ${MICROCONTROLLER}/declaration)

target_link_libraries(microcontroller PRIVATE compile_options include_directories)

add_subdirectory(${MICROCONTROLLER})
