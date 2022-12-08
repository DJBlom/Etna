set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION Cotex-M4-STM32F411RE)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CROSS_GCC_PATH /home/odin/workspace/c++_projects/embedded/etna/toolchain)
find_program(CROSS_GCC_PATH/bin "arm-none-eabi-g++")
if (NOT CROSS_GCC_PATH)
  message(FATAL_ERROR "Cannot find ARM GCC compiler: arm-none-eabi-g++")
endif()

set(TOOLCHAIN ${CROSS_GCC_PATH})
set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/bin/arm-none-eabi-g++)
set(TOOLCHAIN_AS ${TOOLCHAIN}/bin/arm-none-eabi-as CACHE STRING "arm-none-eabi-as")
set(TOOLCHAIN_LD ${TOOLCHAIN}/bin/arm-none-eabi-ld CACHE STRING "arm-none-eabi-ld")
set(TOOLCHAIN_SIZE ${TOOLCHAIN}/bin/arm-none-eabi-size CACHE STRING "arm-none-eabi-size")


set(MACHINE_ARCHITECTURE cortex-m4)
set(ARM_OPTIONS 
    -mcpu=${MACHINE_ARCHITECTURE} 
    -mthumb
    -mlittle-endian
    -mfloat-abi=soft 
)

add_compile_options(
    ${ARM_OPTIONS}
    -fmessage-length=0
    -funsigned-char
    -ffunction-sections
    -fdata-sections
    -MMD
    -MP
)

add_compile_definitions(
    STM32F411xx
    USE_FULL_ASSERT
    $<$<CONFIG:DEBUG>:OS_USE_TRACE_SEMIHOSTING_STDOUT>
    $<$<CONFIG:DEBUG>:OS_USE_SEMIHOSTING>
)

add_link_options(
    ${ARM_OPTIONS}
    $<$<CONFIG:DEBUG>:--specs=rdimon.specs>
    $<$<CONFIG:DEBUG>:--specs=nano.specs>
    $<$<CONFIG:RELEASE>:--specs=nosys.specs>
    $<$<CONFIG:RELEASE>:--specs=nano.specs>
    $<$<CONFIG:DEBUG>:-u_printf_float>
    $<$<CONFIG:DEBUG>:-u_scanf_float>
    LINKER:--build-id
    LINKER:--gc-sections
)


set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
