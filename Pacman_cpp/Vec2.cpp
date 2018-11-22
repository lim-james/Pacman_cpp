#include "Vec2.h"

#include <iostream>

Vec2::Vec2() : x(0), y(0) {}

Vec2::Vec2(const int x, const int y) : x(x), y(y) {}

Vec2 Vec2::operator + (const Vec2& rhs) {
	return Vec2(x + rhs.x, y + rhs.y);
}

bool Vec2::operator == (const Vec2& rhs) {
	return x == rhs.x && y == rhs.y;
}

Vec2::~Vec2() {}
