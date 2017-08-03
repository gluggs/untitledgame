#pragma once

typedef uint32_t tilesetid;
typedef uint16_t tile;

struct tilemap {
	tilesetid tileset;
	size_t width;
	size_t height;
	tile tiles[];
};