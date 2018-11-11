#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

#include "Pacman.h"

class Enemy : public Character {
private:

	Vec2 randomDirection();

	virtual void init();

public:
	static uint inDanger;

	Enemy();
	Enemy(const uint x, const uint y, const Colour c);

	void render();

	virtual void kill();
	virtual void update(Walls& walls);

	~Enemy();
};

#endif