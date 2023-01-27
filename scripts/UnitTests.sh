#!/bin/bash

cd ./test
make -s -f Makefile EtnaUnitTests
./EtnaUnitTests -c -v

