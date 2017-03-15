# add the sources here
set(sources
    main.cpp
    system_stm32f4xx.c
    startup_stm32f40_41xxx.s
)

# GCC optimization level
set(opt_level "-O2")

# set some project constants
set(elf_file ${application_name}.elf)
set(bin_file ${application_name}.bin)
set(hex_file ${application_name}.hex)

# add sources to elf file
add_executable(${elf_file} ${sources})

# link StdPeriph library to project
target_link_libraries(${elf_file} stm32f4xx)

# set additional for compiler and linker
set(additional_flags ${opt_level})
target_compile_options(${elf_file} PRIVATE ${additional_flags})
#target_link_libraries(${elf_file} PRIVATE ${additional_flags})

# show size of resulting firmware image
add_custom_target(${elf_file}-size DEPENDS ${elf_file} COMMAND ${ARM_SIZE_EXECUTABLE} -B -d --target=binary ${elf_file})

# create binary and hex files
add_custom_target(${hex_file} DEPENDS ${elf_file} COMMAND ${CMAKE_OBJCOPY} -Oihex ${elf_file} ${hex_file})
add_custom_target(${bin_file} DEPENDS ${elf_file} COMMAND ${CMAKE_OBJCOPY} -Obinary ${elf_file} ${bin_file})
add_custom_target(${application_name} ALL DEPENDS ${elf_file}-size ${bin_file} ${hex_file})
