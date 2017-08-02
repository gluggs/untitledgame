#pragma once

typedef uint32_t tilesetid;
typedef uint16_t tile;

typedef struct {
	tilesetid tileset;
	size_t width;
	size_t height;
	tile tiles[];
} tilemap;