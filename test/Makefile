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

TEST_TARGET :=EtnaUnitTests
CPP_PLATFORM :=g++

CPP_PLATFORM :=-std=c++20

SRC_DIRS :=\
	$(PROJECT_DIR)/source/src/\
	$(PROJECT_DIR)/source/src/system\
	$(PROJECT_DIR)/source/src/peripheral\
	$(PROJECT_DIR)/source/src/gpio\
	$(PROJECT_DIR)/source/src/usart\
	$(PROJECT_DIR)/source/src/registers\






	
INCLUDE_DIRS :=\
	$(CPPUTEST_HOME)/include\
	$(PROJECT_DIR)/source/abstract/\
	$(PROJECT_DIR)/source/concrete/\
	$(PROJECT_DIR)/source/concrete/system\
	$(PROJECT_DIR)/source/concrete/peripheral\
	$(PROJECT_DIR)/source/concrete/gpio\
	$(PROJECT_DIR)/source/concrete/usart\
	$(PROJECT_DIR)/source/concrete/registers\
	$(TEST_DIR)/mocks

TEST_SRC_DIRS :=\
	$(TEST_DIR)/\
	$(TEST_DIR)/tests\
	$(TEST_DIR)/mocks

CPPUTEST_USE_EXTENSIONS := Y
-include $(CPPUTEST_HOME)/build/MakefileWorker.mk





