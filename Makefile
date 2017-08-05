.PHONY: all run

all: bin/game

run: bin/game
	./bin/game

bin/game: src/ src/assets.c
	@mkdir -p bin
	gcc -Wall src/main.c -o $@

src/assets.c: assets/
	for file in $(shell find assets/include/ -type f); do xxd -i $$file; done > $@
