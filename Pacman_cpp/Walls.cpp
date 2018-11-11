#include "Walls.h"

#include <fstream>

Walls::Walls() {}

void Walls::load(const std::string file) {
	std::ifstream ifs(file);
	uint count;
	ifs >> count;
	for (uint i = 0; i < count; ++i) {
		uint x, y, width, height;
		ifs >> x >> y >> width >> height;
		walls.push_back(Wall(x, y, width, height));
	}
}

void Walls::render() {
	for (Object& w : walls) {
		w.render();
	}
}

bool Walls::collide(Vec2 point) {
	for (Wall &w : walls) {
		if (w.contains(point))
			return true;
	}
	return false;
}

Walls::~Walls()
{
}
