#pragma once

// Types

struct tilemap;

typedef uint32_t tilesetid;
typedef uint16_t tile;

// Implementation

struct tilemap {
	tilesetid tileset;
	size_t width;
	size_t height;
	tile tiles[];
};
