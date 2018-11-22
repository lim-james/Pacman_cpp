#ifndef ENTITY_H
#define ENTITY_H

#include "Object.h"

class Entity : public Object {

protected:

	Entity();
	Entity(const uint x, const uint y, const char c, const Colour co);

	~Entity();

	virtual void init() = 0;

public:

	bool collided(Entity& c);
	virtual void render();

};

#endif