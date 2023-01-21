#!/bin/bash

set -o errexit
set -o nounset
USAGE="Usage: $(basename $0) [-v | --verbose] [ Reset | Test | Release | Openocd  ]"

CMAKE=cmake
BUILD=build
TYPE=Release
BUILD_DIR=$BUILD
TESTING_DIR=Testing
RESET=
TEST=Test
VERBOSE=
OPENOCD=


for arg; do
    case "$arg" in
        --help|-h)    echo $USAGE; exit 0;;
        -v|--verbose) VERBOSE='VERBOSE=1'  ;;
        Release)      TYPE=Release; BUILD_DIR=$BUILD/Release ;;
        Test)         TYPE=Test; BUILD_DIR=$BUILD ;;
        Reset)        RESET=1 ;;
        Openocd)      OPENOCD=1 ;;
        *)            echo -e "unknown option $arg\n$USAGE" >&2;  exit 1 ;;
    esac
done

if [[ -n $OPENOCD  ]] 
then
    openocd -f /usr/share/openocd/scripts/board/st_nucleo_f4.cfg
elif [[ -n $RESET && -d $BUILD_DIR  ]] 
then
    rm -rf $BUILD_DIR/*
    rm -rf $TESTING_DIR
elif [ "$TYPE" = "$TEST" ]
then
    $CMAKE -S . -B $BUILD_DIR --warn-uninitialized -DBUILD_TEST:TYPE=ON 
    $CMAKE --build $BUILD_DIR 
else
    $CMAKE -S . -B $BUILD_DIR --warn-uninitialized -DBUILD_ETNA:TYPE=ON -DCMAKE_BUILD_TYPE=$TYPE -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_TOOLCHAIN_FILE=cmakeModules/EtnaToolchain.cmake 
    $CMAKE --build $BUILD_DIR 
fi

