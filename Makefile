# Makefile for C++ Assignment 1
#   by Lut99

CC = g++
ARGS = -std=c++17 -O2 -Wall -Wextra

BIN_DIR = bin
SRC_DIR = src
LIB_BIN = $(BIN_DIR)/lib
LIB_SRC = $(SRC_DIR)/lib

LIBRARIES = assignment1.o

$(LIB_BIN)/%.o: $(LIB_SRC)/%.cpp
	$(CC) $(ARGS) -o $@ -c $<

$(BIN_DIR)/assignment1.o: $(SRC_DIR)/assignment1.cpp
	$(CC) $(ARGS) -o $(BIN_DIR)/assignment1.o -c $(SRC_DIR)/assignment1.cpp

test_code: tests/testCode.cpp $(BIN_DIR)/assignment1.o
	$(CC) $(ARGS) -o tests/bin/test_code.out $< $(BIN_DIR)/assignment1.o

test_custom: tests/test_custom.cpp $(BIN_DIR)/assignment1.o
	$(CC) $(ARGS) -o tests/bin/test_custom.out $< $(BIN_DIR)/assignment1.o

clean:
	rm -r $(BIN_DIR)/*.out
	rm -r $(LIB_BIN)/*.o