##############################################################
# Contents	: Testing MakefileWorker.mk with cpputest
#
# Author	: Dawid Blom.
#
# Date		: September 18, 2022
#
# NOTE		:
##############################################################

PROJECT_DIR :=$(realpath ..)

TEST_DIR :=$(realpath .)

TEST_TARGET	:=EtnaTests

CPP_PLATFORM :=G++

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


