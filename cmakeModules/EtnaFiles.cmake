
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
set(${PROJECT_NAME}TestSourceFiles
    ${CMAKE_SOURCE_DIR}/test/MainTest.cpp
    ${CMAKE_SOURCE_DIR}/test/tests/AlgorithmsTest.cpp
    ${CMAKE_SOURCE_DIR}/test/tests/DMAControllerTest.cpp
    ${CMAKE_SOURCE_DIR}/test/tests/GpioTest.cpp
    ${CMAKE_SOURCE_DIR}/test/tests/MCURegisterTest.cpp
    ${CMAKE_SOURCE_DIR}/test/tests/PeripheralsTest.cpp 
    ${CMAKE_SOURCE_DIR}/test/tests/SystemTest.cpp
    ${CMAKE_SOURCE_DIR}/test/tests/UsartCommunicationTest.cpp
    ${CMAKE_SOURCE_DIR}/test/mocks/SystemGpiosMock.cpp
    ${CMAKE_SOURCE_DIR}/test/mocks/SystemLoggerMock.cpp
    ${CMAKE_SOURCE_DIR}/test/mocks/SystemPeripheralsMock.cpp
)

set(${PROJECT_NAME}TestHeaderFiles
    ${EtnaHeaderFiles}
    $ENV{CPPUTEST_HOME}/include
    ${CMAKE_SOURCE_DIR}/test/mocks
)

set(${PROJECT_NAME}TestLinkFiles
    $ENV{CPPUTEST_HOME}/lib/libCppUTest.a
    $ENV{CPPUTEST_HOME}/lib/libCppUTestExt.a
)

