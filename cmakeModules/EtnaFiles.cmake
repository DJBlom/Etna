
set(${PROJECT_NAME}Main
    ${CMAKE_SOURCE_DIR}/source/src/etna/Main.cpp
)

set(${PROJECT_NAME}StartupFiles
    ${CMAKE_SOURCE_DIR}/startup/Startup.cpp
)

set(${PROJECT_NAME}SourceFiles
    ${CMAKE_SOURCE_DIR}/source/src/system/SystemPeripherals.cpp
    ${CMAKE_SOURCE_DIR}/source/src/system/SystemGpios.cpp
    ${CMAKE_SOURCE_DIR}/source/src/system/SystemLogger.cpp
    ${CMAKE_SOURCE_DIR}/source/src/peripheral/Ahb1Peripheral.cpp 
    ${CMAKE_SOURCE_DIR}/source/src/peripheral/Apb1Peripheral.cpp 
    ${CMAKE_SOURCE_DIR}/source/src/gpio/GpioMode.cpp
    ${CMAKE_SOURCE_DIR}/source/src/gpio/GpioAF.cpp
    ${CMAKE_SOURCE_DIR}/source/src/usart/Usart.cpp
    ${CMAKE_SOURCE_DIR}/source/src/registers/MCURegisters.cpp
    ${CMAKE_SOURCE_DIR}/source/src/Uart2DmaController.cpp
)

set(${PROJECT_NAME}HeaderFiles
    ${CMAKE_SOURCE_DIR}/source/abstract/
    ${CMAKE_SOURCE_DIR}/source/concrete/
    ${CMAKE_SOURCE_DIR}/source/concrete/system
    ${CMAKE_SOURCE_DIR}/source/concrete/peripheral
    ${CMAKE_SOURCE_DIR}/source/concrete/gpio
    ${CMAKE_SOURCE_DIR}/source/concrete/usart
    ${CMAKE_SOURCE_DIR}/source/concrete/registers
)


