project(Etna VERSION 0.0.1 LANGUAGES CXX)
include(EtnaFiles)

if(CMAKE_TOOLCHAIN_FILE)
    include(CompileEtna)
    CompileEtna()
endif()

find_program(CPPCHECK cppcheck)
if(CPPCHECK)
    include(StaticCodeAnalysis)
    StaticCodeAnalysis()
endif()
