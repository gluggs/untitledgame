.PHONY: all

all: bin/game

bin/game: src/*.c
	gcc $^ -o $@