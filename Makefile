# Makefile for C++ Assignment 1
#   by Tim Müller (11774606)
#
# This Makefile is tested using g++ on Ubuntu 18.04. For usage, refer to
#   README.txt.

CC = g++
ARGS = -std=c++17 -O2 -Wall -Wextra

BIN_DIR = bin
SRC_DIR = src
LIB_BIN = $(BIN_DIR)/obj


LIBRARIES = assignment1.o

all: test_code test_custom test_random main

$(LIB_BIN)/assignment1.o: $(SRC_DIR)/assignment1.cpp
	$(CC) $(ARGS) -o $(LIB_BIN)/assignment1.o -c $(SRC_DIR)/assignment1.cpp

test_code: tests/testCode.cpp $(LIB_BIN)/assignment1.o
	$(CC) $(ARGS) -o bin/test_code.out $< $(LIB_BIN)/assignment1.o

test_custom: tests/test_custom.cpp $(LIB_BIN)/assignment1.o
	$(CC) $(ARGS) -o bin/test_custom.out $< $(LIB_BIN)/assignment1.o

test_random: tests/test_random.cpp $(LIB_BIN)/assignment1.o
	$(CC) $(ARGS) -o bin/test_random.out $< $(LIB_BIN)/assignment1.o

main: $(SRC_DIR)/main.cpp $(LIB_BIN)/assignment1.o
	$(CC) $(ARGS) -o $(BIN_DIR)/main.out $< $(LIB_BIN)/assignment1.o

clean:
	rm -r $(BIN_DIR)/*.out
	rm -r $(LIB_BIN)/*.o