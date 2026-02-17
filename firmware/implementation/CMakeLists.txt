# SPDX-FileCopyrightText: 2026 Vahid Mohammadi vahmoh10@protonmail.com
# SPDX-License-Identifier: AGPL-3.0-only

add_subdirectory(architecture)
add_subdirectory(kernel)
add_subdirectory(microcontroller)

add_executable(firmware main.c)

target_link_libraries(firmware PRIVATE compile_options link_options architecture kernel microcontroller)

set_target_properties(firmware PROPERTIES SUFFIX ".elf")

if(MICROCONTROLLER STREQUAL "rp2350")
    find_program(PICOTOOL NAMES picotool picotool.exe PATHS ${CMAKE_CURRENT_SOURCE_DIR} REQUIRED)
    add_custom_command(TARGET firmware POST_BUILD COMMAND ${PICOTOOL} uf2 convert firmware.elf firmware.uf2)
endif()
