#pragma once

#include <stdint.h>
#include "vector.c"

typedef struct {
	uint32_t vit, str, dex, fth, mgc, def;
} charstats;

typedef uint32_t itemid;

typedef struct {
	itemid id;
	uint32_t lvl;
	uint8_t rarity;
} item;

typedef struct {
	item backpack[30];
} inventory;

typedef struct {
	vec2 position;
	vec2 velocity;
	vec2 size;
	inventory inv;
	charstats stats;
	uint32_t level;
} character;

typedef void (*attack)(gamestate*);

typedef struct {
	vec2 position;
	vec2 size;
	uint32_t health;
	attack attack;
} enemy;