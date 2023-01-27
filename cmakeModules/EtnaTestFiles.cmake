include(EtnaFiles)

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
