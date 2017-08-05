#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
	int64_t x,y;
} vec2;

vec2 v2add(vec2 a, vec2 b) {
	return (vec2){a.x + b.x, a.y + b.y};
}

vec2 v2sub(vec2 a, vec2 b) {
	return (vec2){a.x - b.x, a.y - b.y};
}

vec2 v2mul(vec2 a, int64_t b) {
	return (vec2){a.x * b, a.y * b};
}

vec2 v2div(vec2 a, int64_t b) {
	return (vec2){a.x / b, a.y / b};
}

vec2 v2cmul(vec2 a, vec2 b) {
	return (vec2){a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x};
}

int64_t v2wedge(vec2 a, vec2 b) {
	return a.x * b.y - a.y * b.x;
}

int64_t v2dot(vec2 a, vec2 b) {
	return a.x * b.x + a.y * b.y;
}

typedef struct {
	vec2 start;
	vec2 end;
} seg2;

bool s2int(seg2 a, seg2 b) {
	vec2 a_end_rel = v2sub(a.end, a.start);
	vec2 b_end_rel = v2sub(b.end, b.start);
	bool a_sep_b =
		v2wedge(a_end_rel, v2sub(b.start, a.start)) *
		v2wedge(a_end_rel, v2sub(b.end, a.start)) < 0;
	bool b_sep_a =
		v2wedge(b_end_rel, v2sub(a.start, b.start)) *
		v2wedge(b_end_rel, v2sub(a.end, b.start)) < 0;
	return a_sep_b && b_sep_a;
}

uint64_t isqrt(uint64_t x) {
	uint64_t root;
	uint64_t new_root = x;
	
	do {
		root = new_root;
		new_root = (root + x / root) / 2;
	} while (new_root < root);
	
	return root;
}

uint64_t v2mag(vec2 a) {
	return isqrt(a.x * a.x + a.y * a.y);
}