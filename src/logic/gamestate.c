#pragma once

#include "map.c"
#include "main.c"

typedef struct {
	tilemap* map;
	character* character;
	struct {
		size_t length;
		size_t capacity;
		enemy s[];
	}* enemies;
} gamestate;