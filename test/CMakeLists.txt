project(Etna VERSION 0.0.1 LANGUAGES CXX C)
include(EtnaFiles)

#if (DEFINED ENV{CPPUTEST_HOME} AND BUILD_UNIT_TEST)
#    include(UnitTest)
#    UnitTest()
#endif()

find_program(GCOV gcov)
if(DEFINED ENV{CPPUTEST_HOME} AND GCOV AND BUILD_COVERAGE)
    include(CodeCoverage)
    CodeCoverage()
endif()


















