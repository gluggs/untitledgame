#pragma once

typedef struct {
	int64_t x, y;
} vec2;

inline vec2 v2_add(vec2 a, b) {
	vec2 r = {a.x + b.x, a.y + b.y};
	return r;
}

inline vec2 v2_sub(vec2 a, b) {
	vec2 r = {a.x - b.x, a.y - b.y};
	return r;
}

inline vec2 v2_mul(vec2 a, int64_t b) {
	vec2 r = { a.x * b, a.y * b };
	return r;
}

inline vec2 v2_div(vec2 a, int64_t b) {
	vec2 r = { a.x / b, a.y / b };
	return r;
}