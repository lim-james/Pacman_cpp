#ifndef WALLS_H
#define WALLS_H

#include <string>
#include <vector>

#include "Wall.h"

class Walls {

private:

	std::vector<Wall> walls;

public:

	Walls();

	void load(const std::string file);
	void render();

	bool collide(Vec2 point); // returns if point is inside 

	~Walls();

};

#endif