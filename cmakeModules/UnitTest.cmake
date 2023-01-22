
set(UNIT_TEST UnitTest)
function(${UNIT_TEST})
    add_executable(${UNIT_TEST}
        ${EtnaTestSourceFiles}
        ${EtnaSourceFiles}
    )

    include_directories(${UNIT_TEST} PRIVATE
        ${EtnaTestHeaderFiles}
    )

    target_link_libraries(${UNIT_TEST} PRIVATE
        ${EtnaTestLinkFiles}
    )

    add_test(NAME AlgorithmsTest.cpp COMMAND ${UNIT_TEST})
    add_test(NAME DMAControllerTest.cpp COMMAND ${UNIT_TEST})
    add_test(NAME GpioTest.cpp COMMAND ${UNIT_TEST})
    add_test(NAME MCURegisterTest.cpp COMMAND ${UNIT_TEST})
    add_test(NAME PeripheralsTest.cpp COMMAND ${UNIT_TEST})
    add_test(NAME SystemTest.cpp COMMAND ${UNIT_TEST})
    add_test(NAME UsartCommunicationTest.cpp COMMAND ${UNIT_TEST})
    add_test(NAME SystemGpiosMock.cpp COMMAND ${UNIT_TEST})
    add_test(NAME SystemLoggerMock.cpp COMMAND ${UNIT_TEST})
    add_test(NAME SystemPeripheralsMock.cpp COMMAND ${UNIT_TEST})
endfunction()
