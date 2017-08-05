#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "map.c"

// Types

struct gamestate;
struct entity;

typedef struct gamestate gamestate;
typedef void (*action)(gamestate*, void*);

// Implementation

struct entity {
	action tick;
	void* data;
};

struct gamestate {
	struct tilemap* map;
	struct entitylink {
		struct entitylink* next;
		struct entity val;
	}* entities;
};

