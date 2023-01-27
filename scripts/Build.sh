#!/bin/bash

set -o errexit
set -o nounset
USAGE="Usage: $(basename $0) [-v | --verbose] [ Reset | Release ]"

CMAKE=cmake
BUILD=build
BUILD_DIR=$BUILD
TESTING_DIR=Testing
TOOLCHAIN=cmakeModules/EtnaToolchain.cmake

RESET=
TYPE=Release
RELEASE=Release
VERBOSE=


for arg; do
    case "$arg" in
        --help|-h)              echo $USAGE; exit 0;;
        -v|--verbose)           VERBOSE='VERBOSE=1'  ;;
        Reset)                  RESET=1 ;;
        Release)                TYPE=Release; BUILD_DIR=$BUILD/Release ;;
        *)                      echo -e "unknown option $arg\n$USAGE" >&2;  exit 1 ;;
    esac
done

if [[ -n $RESET && -d $BUILD_DIR  ]] 
then
    rm -rf $BUILD_DIR/*
    rm -rf $TESTING_DIR
    cd test
    make clean
elif [ "$TYPE" = "$RELEASE" ]
then
    $CMAKE -S . -B $BUILD_DIR --warn-uninitialized -DBUILD_ETNA:TYPE=ON -DCMAKE_BUILD_TYPE=$RELEASE -DCMAKE_TOOLCHAIN_FILE=$TOOLCHAIN
    $CMAKE --build $BUILD_DIR 
fi
