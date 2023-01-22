if (NOT DEFINED ENV{CPPUTEST_HOME})
    message("CPPUTEST_HOME is not set!")
    return()
endif()

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

    add_test(NAME ${UNIT_TEST} COMMAND $<TARGET_FILE:${UNIT_TEST}>)
endfunction()
