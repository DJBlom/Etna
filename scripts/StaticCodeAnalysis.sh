#!/bin/bash

BUILD_DIR=build
BUILD_TYPE=Release


$CMAKE -S . -B $BUILD_DIR --warn-uninitialized -DBUILD_STATIC:TYPE=ON -DCMAKE_BUILD_TYPE=$RELEASE -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
$CMAKE --build $BUILD_DIR 
