#include "Wall.h"

Wall::Wall() : Object(0, 0, 0, 0, 219, blue) {}

Wall::Wall(const uint x, const uint y, const uint width, const uint height)
	: Object(x, y, width, height, 219, blue) {}

bool Wall::contains(Vec2 point) {
	return point.x >= position.x && point.x < position.x + size.x &&
		   point.y >= position.y && point.y < position.y + size.y;
}

void Wall::render() {
	Vec2 point;
	for (int x = 0; x < size.x; ++x) {
		point.x = position.x + x;
		for (int y = 0; y < size.y; ++y) {
			point.y = position.y + y;
			point.draw(icon, colour);
		}
	}
}

Wall::~Wall() {}
