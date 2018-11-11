#ifndef CHARACTER_H
#define CHARACTER_H

#include "Walls.h"
#include "Entity.h"

class Character : public Entity {
protected:

	Vec2 origin;
	Vec2 direction;

	Character();
	Character(const uint x, const uint y, const char c, const Colour co);

	void clearRender();

	bool wallAhead(Walls& walls);
	void move();

	virtual void kill() = 0;
	virtual void update(Walls& walls) = 0;

	~Character();
};

#endif