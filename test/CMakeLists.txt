project(Etna VERSION 0.0.1 LANGUAGES CXX C)
include(EtnaFiles)




find_program(GCOV gcov)
if(GCOV)
    include(UnitTest)
    include(CodeCoverage)
    UnitTest()

    set(PROJECT_TEST_NAME ${PROJECT_NAME})
    append_coverage_compiler_flags()
    setup_target_for_coverage_lcov(NAME ${PROJECT_NAME}Coverage EXECUTABLE ctest)
endif()


















