project(Etna VERSION 0.0.1 LANGUAGES CXX C)
include(EtnaFiles)

find_program(GCOV gcov)
if(DEFINED ENV{CPPUTEST_HOME} AND GCOV AND BUILD_COVERAGE)
    include(CodeCoverage)
    CodeCoverage()
endif()


















