project(Etna VERSION 0.0.1 LANGUAGES CXX C)
include(EtnaFiles)

#find_program(CPPUTEST cpputest)
#if(CPPUTEST)
#    message("Found cpputest!!!!")
#endif()
if (BUILD_UNIT_TEST)
    include(UnitTest)
    UnitTest()
endif()


find_program(GCOV gcov)
if(GCOV AND BUILD_COVERAGE)
    include(CodeCoverage)
    CodeCoverage()
endif()


















