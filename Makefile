.PHONY: all run

all: bin/game

run: bin/game
	./bin/game

bin/game: src/*.c
	gcc $^ -o $@