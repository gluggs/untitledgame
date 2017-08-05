#pragma once

#include <stdlib.h>
#include "math.c"
#include "gamestate.c"

struct charstats {
	uint32_t vit, str, dex, fth, mgc, def;
};

struct item {
	uint32_t id;
	uint32_t lvl;
	uint8_t rarity;
	struct charstats stats;
};

struct characterdata {
	vec2 position;
	vec2 velocity;
	vec2 size;
	struct item backpack[30];
	struct charstats stats;
	uint32_t health;
	uint32_t level;
};

void character_stats_update(struct characterdata* self) {
	self->stats = (struct charstats){};

	for (size_t i = 0; i < 5; i++) {
		self->stats.str += self->backpack[i].stats.str;
		self->stats.vit += self->backpack[i].stats.vit;
		self->stats.dex += self->backpack[i].stats.dex;
		self->stats.fth += self->backpack[i].stats.fth;
		self->stats.mgc += self->backpack[i].stats.mgc;
		self->stats.def += self->backpack[i].stats.def;
	}
}

void character_tick(gamestate* st, void* voiddata) {
	struct characterdata* data = voiddata;
}

struct entity entity_character_init() {
	struct characterdata* data = malloc(sizeof(struct characterdata));
	*data = (struct characterdata){};

	struct entity r = { &character_tick, data };
	return r;
}
