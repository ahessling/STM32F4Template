cmake_minimum_required (VERSION 2.8.12)

# set the build type
if(NOT CMAKE_BUILD_TYPE) 
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

if(CMAKE_BUILD_TYPE MATCHES Debug)
  message("Debug build.")
elseif(CMAKE_BUILD_TYPE MATCHES Release)
  message("Release build.")
endif()

# set search path for CMake modules
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMake/Modules)

# include OpenOCD module, but make it not required
find_package(Openocd)

# Project specific settings
set(application_name "STM32F4Template")

project (${application_name} C CXX ASM)

# STM32-specific settings
set(DEVICE_FAMILY STM32F40_41xxx)

# Speed of external resonator
set(HSE_VALUE 8000000)

# Used linker file (just for testing)
get_filename_component(LINKER_SCRIPT linker/stm32f407vgt.ld ABSOLUTE)

# Use LTO? WARNING: This might break the code
#set(ADDITIONAL_CORE_FLAGS -flto)

# OpenOCD config file
get_filename_component(OPENOCD_CONFIG tools/stm32f4discovery.cfg ABSOLUTE)

# add libraries
add_subdirectory(lib)

# add main project
add_subdirectory(src)
