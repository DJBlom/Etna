##############################################################
# Contents: Paths to source files used by CppUTest
#
# Author: Dawid Blom.
#
# Date: September 18, 2022
#
# NOTE: This Makefile adds value to the CppUTests framework
# by specifying the folders where the code is to be tested.
##############################################################
PROJECT_DIR :=$(realpath ..)
TEST_DIR :=$(realpath .)

<<<<<<< HEAD
TEST_TARGET	:=EtnaTests
CPP_PLATFORM :=G++
=======
TEST_TARGET :=EtnaTests

CPP_PLATFORM :=g++
>>>>>>> main

SRC_DIRS :=\
	$(PROJECT_DIR)/source/src/components\
	$(PROJECT_DIR)/source/src/HAL\

INCLUDE_DIRS :=\
	$(CPPUTEST_HOME)/include\
	$(PROJECT_DIR)/source/abstract/components\
	$(PROJECT_DIR)/source/abstract/HAL\
	$(PROJECT_DIR)/source/abstract/registers\
	$(PROJECT_DIR)/source/concrete/components\
	$(PROJECT_DIR)/source/concrete/HAL\
	$(PROJECT_DIR)/source/concrete/registers\
	$(TEST_DIR)/mocks

TEST_SRC_DIRS :=\
	$(TEST_DIR)/\
	$(TEST_DIR)/tests\
	$(TEST_DIR)/mocks

CPPUTEST_USE_GCOV := Y
CPPUTEST_USE_EXTENSIONS := Y
-include $(CPPUTEST_HOME)/build/MakefileWorker.mk


