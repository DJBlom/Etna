cmake_minimum_required(VERSION 3.22)
set(CMAKE_TRY_COMPILE_TARGET_TYPE "STATIC_LIBRARY")
project(Etna VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")

add_compile_options(
    -Wall
    -Werror
    -Wextra
    -Wconversion
    -Wsign-conversion
    $<$<CONFIG:DEBUG>:-g3>
    $<$<CONFIG:DEBUG>:-Og>
    $<$<CONFIG:RELEASE>:-O3>
)

add_compile_definitions(
    $<$<CONFIG:DEBUG>:DEBUG>
)

add_executable(Etna
    ${CMAKE_SOURCE_DIR}/startup/Startup.cpp
    ${CMAKE_SOURCE_DIR}/source/src/Main.cpp
    ${CMAKE_SOURCE_DIR}/source/src/HAL/GreenUserLED.cpp
)

target_include_directories(Etna PRIVATE
    ${CMAKE_SOURCE_DIR}/source/abstract/components
    ${CMAKE_SOURCE_DIR}/source/abstract/HAL
    ${CMAKE_SOURCE_DIR}/source/concrete/components
    ${CMAKE_SOURCE_DIR}/source/concrete/HAL
    ${CMAKE_SOURCE_DIR}/source/concrete/registers
)

set(LINKER_SCRIPTS
    ${CMAKE_SOURCE_DIR}/startup/Flash.ld
)

set_target_properties(Etna PROPERTIES 
    SUFFIX .elf
    LINK_DEPENDS "${LINKER_SCRIPTS}"
)


target_link_options(Etna PRIVATE
    -T${CMAKE_SOURCE_DIR}/startup/Flash.ld
    LINKER:--print-memory-usage
    LINKER:-Map,${CMAKE_CURRENT_BINARY_DIR}/Etna.map
)

if (EXISTS ${CMAKE_OBJCOPY})
    add_custom_command(
        TARGET Etna
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O ihex $<TARGET_FILE:Etna>
                ${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_NAME:Etna>.hex
)
else ()
    message(STATUS "'objcopy' not found: cannot generate .hex file")
endif()

if (EXISTS "${TOOLCHAIN_SIZE}")
  add_custom_command(
    TARGET Etna 
    POST_BUILD
    COMMAND ${TOOLCHAIN_SIZE} --format=berkeley $<TARGET_FILE:Etna>
            >${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_NAME:Etna>.bsz
  )
  add_custom_command(
    TARGET Etna
    POST_BUILD
    COMMAND ${TOOLCHAIN_SIZE} --format=sysv -x $<TARGET_FILE:Etna>
            >${CMAKE_CURRENT_BINARY_DIR}/$<TARGET_NAME:Etna>.ssz
    )
else()
    message(STATUS "'size' not found: cannot generate .[bs]sz files")
endif()
