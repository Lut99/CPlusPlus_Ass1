# Makefile for C++ Assignment 1
#   by Lut99

CC=g++
ARGS = -std=c++17 -O2

BIN_DIR = bin
SRC_DIR = src
LIB_BIN = $(BIN_DIR)/lib
LIB_SRC = $(SRC_DIR)/lib

LIBRARIES =

$(LIB_BIN)/%.o: $(LIB_SRC)/%.cpp
	$(CC) $(ARGS) -o $@ -c $<



clean:
	rm -r $(BIN_DIR)/*.out
	rm -r $(LIB_BIN)/*.o