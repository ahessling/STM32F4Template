cmake_minimum_required (VERSION 2.8)

# Project specific settings
project (STM32F4Template C CXX ASM)

# STM32-specific settings
set(DEVICE_FAMILY STM32F40_41xxx)

# Speed of external resonator
set(HSE_VALUE 8000000)

# Used linker file (just for testing)
get_filename_component(LINKER_SCRIPT linker/STM32F417IGHx_FLASH.ld ABSOLUTE)

# add subdirectories
add_subdirectory(lib)
add_subdirectory(src)
