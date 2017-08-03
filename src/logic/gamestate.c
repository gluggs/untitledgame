#pragma once

#include <stdint.h>
#include "map.c"
#include "vector.c"

struct charstats {
	uint32_t vit, str, dex, fth, mgc, def;
};

typedef uint32_t itemid;

struct item {
	itemid id;
	uint32_t lvl;
	uint8_t rarity;
};

struct inventory {
	struct item backpack[30];
};

struct character {
	vec2 position;
	vec2 velocity;
	vec2 size;
	struct inventory inv;
	struct charstats stats;
	uint32_t level;
};

struct enemy {
	vec2 position;
	vec2 size;
	uint32_t health;
	attack attack;
};

struct gamestate {
	struct tilemap* map;
	struct character* character;
	struct {
		size_t length;
		size_t capacity;
		struct enemy s[];
	}* enemies;
};

typedef void (*attack)(struct gamestate*);

