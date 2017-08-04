#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "map.c"
#include "math.c"
#include "list.c"

// Types

struct gamestate;
struct item;
struct character;
struct enemy;

typedef struct gamestate gamestate;
typedef void (*action)(gamestate*,void*);

// Implementation

struct item {
	uint32_t id;
	uint32_t lvl;
	uint8_t rarity;
};

struct character {
	vec2 position;
	vec2 velocity;
	vec2 size;
	struct item backpack[30];
	struct { 
		uint32_t vit, str, dex, fth, mgc, def;
	} stats;
	uint32_t health;
	uint32_t level;
};

struct entity {
	action tick;
	void* data;
};

struct gamestate {
	struct tilemap* map;
	list(struct entity) entities;
};
