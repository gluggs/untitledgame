.PHONY: all run

all: bin/game

run: bin/game
	./bin/game

bin/game: src/ src/assets.c
	@mkdir -p bin
	gcc src/main.c -o $@

src/assets.c: assets/
	for file in $(shell find assets/ -type f); do xxd -i $$file; done > $@
