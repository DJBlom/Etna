project(Etna VERSION 0.0.1 LANGUAGES CXX C)
include(EtnaFiles)

if(${CPPUTEST_HOME})
    include(UnitTest)
    UnitTest()
else()           
    message("CPPUTEST_HOME is not set; You must tell CMake where to find CppUTest")
    return()    
endif()

find_program(GCOV gcov)
if(GCOV)
    include(CodeCoverage)
    set(PROJECT_TEST_NAME ${PROJECT_NAME})
    append_coverage_compiler_flags()
    setup_target_for_coverage_lcov(NAME ${PROJECT_NAME}Coverage EXECUTABLE ctest)
endif()


















