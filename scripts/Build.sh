#!/bin/bash

set -o errexit
set -o nounset
USAGE="Usage: $(basename $0) [-v | --verbose] [ Reset | Release | StaticAnalysis | CodeCoverage | UnitTest | Openocd  ]"

CMAKE=cmake
BUILD=build
BUILD_DIR=$BUILD
TESTING_DIR=Testing

RESET=
TYPE=Release
RELEASE=Release
UNIT_TEST=UnitTest
STATIC_TEST=StaticAnalysis
CODE_COVERAGE=CodeCoverage
VERBOSE=
OPENOCD=
VERIFYGDB=


for arg; do
    case "$arg" in
        --help|-h)              echo $USAGE; exit 0;;
        -v|--verbose)           VERBOSE='VERBOSE=1'  ;;
        Reset)                  RESET=1 ;;
        Release)                TYPE=Release; BUILD_DIR=$BUILD/Release ;;
        StaticAnalysis)         TYPE=StaticAnalysis; BUILD_DIR=$BUILD/StaticCodeAnalysis ;;
        UnitTest)               TYPE=UnitTest; BUILD_DIR=$BUILD/UnitTest ;;
        CodeCoverage)           TYPE=CodeCoverage; BUILD_DIR=$BUILD/CodeCoverage ;;
        Openocd)                OPENOCD=1 ;;
        VerifyGDB)              VERIFYGDB=1 ;;
        *)                      echo -e "unknown option $arg\n$USAGE" >&2;  exit 1 ;;
    esac
done

if [[ -n $RESET && -d $BUILD_DIR  ]] 
then
    rm -rf $BUILD_DIR/*
    rm -rf $TESTING_DIR
    cd test
    make clean
elif [[ -n $OPENOCD  ]] 
then
    #openocd -f /usr/share/openocd/scripts/board/st_nucleo_f4.cfg
    openocd -f /usr/share/openocd/scripts/board/st_nucleo_f4.cfg 
elif [[ -n $VERIFYGDB ]]
then
    gdb -ex "target remote :3333" -ex "load build/Release/source/Etna.elf" -ex "verify" -ex "continue"
elif [ "$TYPE" = "$RELEASE" ]
then
    $CMAKE -S . -B $BUILD_DIR --warn-uninitialized -DBUILD_ETNA:TYPE=ON -DCMAKE_BUILD_TYPE=$RELEASE -DCMAKE_TOOLCHAIN_FILE=cmakeModules/EtnaToolchain.cmake 
    $CMAKE --build $BUILD_DIR 
elif [ "$TYPE" = "$STATIC_TEST" ]
then
    $CMAKE -S . -B $BUILD_DIR --warn-uninitialized -DBUILD_STATIC:TYPE=ON -DCMAKE_BUILD_TYPE=$RELEASE -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
    $CMAKE --build $BUILD_DIR 
elif [ "$TYPE" = "$UNIT_TEST" ]
then
    cd ./test
    make -s -f Makefile EtnaUnitTests
    ./EtnaUnitTests -c -v
elif [ "$TYPE" = "$CODE_COVERAGE" ]
then
    $CMAKE -S . -B $BUILD_DIR --warn-uninitialized -DBUILD_COVERAGE:TYPE=ON -DCMAKE_BUILD_TYPE=$RELEASE -DCMAKE_CXX_FLAGS_RELEASE="-g -O0 -fprofile-arcs -ftest-coverage"
    $CMAKE --build $BUILD_DIR 
    cd build/CodeCoverage
    ctest -T Test -T Coverage
    lcov --rc lcov_branch_coverage=1 --directory . --capture --output-file Coverage.info
    lcov --rc lcov_branch_coverage=1 --list Coverage.info > Coverage.txt

    curl -Os https://uploader.codecov.io/latest/linux/codecov
    chmod 755 codecov
    ./codecov
fi

