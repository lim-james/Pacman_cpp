#include "Character.h"

Character::Character() 
	: Entity(), origin(Vec2(0,0)), direction(Vec2(0,0)) {}

Character::Character(const uint x, const uint y, const char c, const Colour co)
	: Entity(x, y, c, co), origin(x, y) {}

void Character::clearRender() {
	position.draw(' ', black);
}


bool Character::wallAhead(Walls& walls) {
	return walls.collide(position + direction);
}

void Character::move() {
	position = position + direction;
}

Character::~Character() {}
