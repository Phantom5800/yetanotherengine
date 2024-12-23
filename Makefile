CC=g++.exe
INCLUDE=-Iinc
CFLAGS=-c
DEBUG_FLAGS=-Wall
SRC=src
OUT=out

EXE=game.exe

OBJ=$(OUT)/main.o

all: debug
debug: $(OUT)/$(EXE)
run:
	$(OUT)/$(EXE)

$(OUT)/main.o: src/main.cpp
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(SRC)/main.cpp $(INCLUDE) -o $(OUT)/main.o

$(OUT)/$(EXE): $(OBJ)
	$(CC) $(OBJ) $(INCLUDE) -o $(OUT)/$(EXE)

clean:
	rm out/*
