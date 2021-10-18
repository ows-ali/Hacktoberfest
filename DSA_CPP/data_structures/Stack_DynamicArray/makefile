HOME = .
BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

all: $(BIN)/main

$(BIN)/main : $(OBJ)/main.o $(OBJ)/Stack.o
	g++ -o $(BIN)/main $(OBJ)/main.o $(OBJ)/Stack.o -std=c++11

$(OBJ)/main.o : $(SRC)/main.cpp $(INCLUDE)/Stack.hpp
	g++ -c -o $(OBJ)/main.o $(SRC)/main.cpp -I$(INCLUDE)/ -std=c++11

$(OBJ)/Stack.o : $(SRC)/Stack.cpp $(INCLUDE)/Stack.hpp
	g++ -c -o $(OBJ)/Stack.o $(SRC)/Stack.cpp -I$(INCLUDE) -std=c++11
