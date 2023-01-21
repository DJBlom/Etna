
find_program(CPPCHECK_EXECUTABLE cppcheck)
function(StaticCodeAnalysis)
    if(CPPCHECK_EXECUTABLE)
        set(CMAKE_CXX_CPPCHECK "cppcheck")
        set(CPPCHECK_OPTIONS --enable=all --std=c++20 --platform=mips32 --project=compile_commands.json -istartup -itest -icmakeModules -ibuild -itoolchain)
        set(STATIC_ANALYSIS ${PROJECT_NAME}StaticAnalysis)

        add_executable(${STATIC_ANALYSIS}
            ${CMAKE_SOURCE_DIR}/source/src/etna/Main.cpp
            ${EtnaSourceFiles}
        )

        #add_custom_target(${STATIC_ANALYSIS}
        #    COMMAND ${CPPCHECK_EXECUTABLE} ${CPPCHECK_OPTIONS} ${EtnaSourceFiles}
        #    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
        #    COMMENT "Performing Static Code Analysis"
        #)

        include_directories(${STATIC_ANALYSIS} PRIVATE
            ${EtnaHeaderFiles}
        )

        target_link_libraries(${STATIC_ANALYSIS} PRIVATE)
    endif()
endfunction()
