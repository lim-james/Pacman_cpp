#ifndef WALL_H
#define WALL_H

#include "Object.h"

class Wall : public Object {
public:
	Wall();
	Wall(const uint x, const uint y, const uint width, const uint height);

	bool contains(Vec2 point);

	virtual void render();

	~Wall();
};

#endif 