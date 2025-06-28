CC = gcc
CFLAGS = -Iinclude
SRC = $(wildcard src/*.c)

EXAMPLES = $(wildcard examples/*.c)

BINARIES = $(patsubst examples/%.c, bin/%, $(EXAMPLES))

all: $(BINARIES)

bin/%: examples/%.c $(SRC) | bin
	$(CC) -o $@ $< $(SRC) $(CFLAGS)

bin: 
	mkdir -p bin

clean:
	rm -rf bin