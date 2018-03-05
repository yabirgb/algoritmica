C = g++
BIN = bin
SRC = src

SRC_FILES := $(wildcard $(SRC)/*.cpp)

BIN_FILES := $(patsubst $(SRC)/%.cpp,$(BIN)/%,$(SRC_FILES))

sort = $(BIN)/burbuja $(BIN)/insercion $(BIN)/seleccion $(BIN)/mergesort $(BIN)/quicksort $(BIN)/heapsort
others = $(BIN)/hanoi $(BIN)/floyd

all: clean $(sort) $(others)
sort: $(sort)
others: $(others)

$(BIN)/%:
	@echo "[Compiling]: $@"
	$(C) $(CFLAGS) $(SRC)/$(@F).cpp -O0 -o $@_O0
	$(C) $(CFLAGS) $(SRC)/$(@F).cpp -O1 -o $@_O1
	$(C) $(CFLAGS) $(SRC)/$(@F).cpp -O2 -o $@_O2

clean:
	rm -f $(BIN)/*
