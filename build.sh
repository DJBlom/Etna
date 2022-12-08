#!/bin/bash

set -o errexit
set -o nounset
USAGE="Usage: $(basename $0) [-v | --verbose] [ reset | clean | debug | release | openocd  ]"

CMAKE=cmake
BUILD=build
TYPE=DEBUG
BUILD_DIR=$BUILD
CLEAN=
RESET=
VERBOSE=
OPENOCD=


for arg; do
    case "$arg" in
        --help|-h)    echo $USAGE; exit 0;;
        -v|--verbose) VERBOSE='VERBOSE=1'  ;;
        debug)        TYPE=DEBUG;   BUILD_DIR=$BUILD/debug ;;
        release)      TYPE=RELEASE; BUILD_DIR=$BUILD/release ;;
        clean)        CLEAN=1  ;;
        reset)        RESET=1 ;;
        openocd)      OPENOCD=1 ;;
        *)            echo -e "unknown option $arg\n$USAGE" >&2;  exit 1 ;;
    esac
done

if [[ -n $OPENOCD  ]] 
then
    openocd -f /usr/share/openocd/scripts/board/st_nucleo_f4.cfg
elif [[ -n $RESET && -d $BUILD_DIR  ]] 
then
    rm -rf $BUILD_DIR/*
elif [[ -n $CLEAN  ]] 
then
    $CMAKE --build $BUILD_DIR --target clean
    $CMAKE --build $BUILD_DIR 
else
    $CMAKE -S . -B $BUILD_DIR --warn-uninitialized -DCMAKE_BUILD_TYPE=$TYPE -DCMAKE_TOOLCHAIN_FILE=toolchain_etna.cmake
    $CMAKE --build $BUILD_DIR 
fi

