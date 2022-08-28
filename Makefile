########################################################
# Contents: 	Build system for heap_management.
#
# Author: 	Dawid Blom.
#
# Date: 	17/04/2022.
#
#
#
# NOTE: 
########################################################


# Name of executable file without extension.
FILE 		:=debug
LINKER		:=flash.ld

# Path to openocd script for the board.
OPENOCD	:= openocd -f /usr/share/openocd/scripts/board/st_nucleo_f4.cfg


# Project Paths.
SRC_DIR 	:=src
OBJ_DIR 	:=obj
BIN_DIR 	:=bin
HH_DIR		:=header
MAP_DIR		:=map


# File extensions.
SRC_EXT 	:=.cpp
OBJ_EXT 	:=.o
BIN_EXT 	:=.elf
MAP_EXT 	:=.map
START_EXT	:=.s



# Final executable.
BIN 		:=$(BIN_DIR)/$(FILE)$(BIN_EXT)

SRC_ONE		:=$(wildcard $(SRC_DIR)/*$(SRC_EXT))

SRC_TWO		:=$(wildcard $(SRC_DIR)/*$(START_EXT))

SRC_THREE	:=$(wildcard $(HH_DIR)/$(SRC_DIR)/*$(SRC_EXT))

OBJ_ONE 	:=$(patsubst $(SRC_DIR)/%$(SRC_EXT), $(OBJ_DIR)/%$(OBJ_EXT), $(SRC_ONE))

OBJ_TWO 	:=$(patsubst $(SRC_DIR)/%$(START_EXT), $(OBJ_DIR)/%$(OBJ_EXT), $(SRC_TWO))

OBJ_THREE	:=$(patsubst $(HH_DIR)/$(SRC_DIR)/%$(SRC_EXT), $(OBJ_DIR)/%$(OBJ_EXT), $(SRC_THREE))

DEB 		:=$(OBJ_ONE:.o=.d)




# Compilation Instructions.
CXX 		:=arm-none-eabi-g++ -std=c++20
MARCH		:=cortex-m4
CPPFLAGS 	:=-Iheader
CXXFLAGS 	:=-g -c -O0 -Wall -Werror -mcpu=$(MARCH) -mthumb -mfloat-abi=soft 
LDLIBS 		:=-mcpu=$(MARCH) -mthumb -mfloat-abi=soft --specs=nosys.specs -T
MAP			:=-Wl,-Map=$(FILE)$(MAP_EXT)





.PHONY: all clean

# Target.
all: $(BIN)


# Linking Phase.
$(BIN): $(OBJ_ONE) $(OBJ_TWO) $(OBJ_THREE) | $(BIN_DIR)
	$(CXX) $(LDLIBS) $(LINKER) $^ -o $@ $(MAP)


# Compiling phase.
$(OBJ_ONE): $(SRC_ONE) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS)$(CPPFLAGS) $< -o $@

$(OBJ_TWO): $(SRC_TWO) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS)$(CPPFLAGS) $< -o $@

$(OBJ_THREE): $(SRC_THREE) | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS)$(CPPFLAGS) $< -o $@


# Creating the directories required for comilation.
$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

# Cleaning up the project directory.
clean:
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ_DIR)

# Setting up the connection to openocd.
load: 
	$(OPENOCD)

# Automatic dependency generation for the header files.
-include $(DEB)
