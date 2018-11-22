#include "Entity.h"

Entity::Entity() : Object(0, 0, 1, 1, ' ', black) {}

Entity::Entity(const uint x, const uint y, const char c, const Colour co)
	: Object(x, y, 1, 1, c, co) {}

Entity::~Entity() {}

bool Entity::collided(Entity& c) {
	return position == c.position;
}

void Entity::render() {
	Console::draw(position, icon, colour);
}