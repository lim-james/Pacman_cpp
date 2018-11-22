#include "Enemy.h"

uint Enemy::inDanger = false;

Vec2 Enemy::randomDirection() {
	int r = rand() % 2 * 2 - 1;
	if (direction.y)
		return Vec2(r, 0);
	return Vec2(0, r);
}

void Enemy::init() {
	direction = randomDirection();
}

Enemy::Enemy() {
	init();
}

Enemy::Enemy(const uint x, const uint y, const Colour c)
	: Character(x, y, 254, c) {
	init();
}

void Enemy::render() {
	Colour fill = colour;
	if (inDanger) {
		if (inDanger < 20) {
			fill = inDanger % 4 ? blue : white;
		} else {
			fill = blue;
		}
	}
	Console::draw(position, icon, fill);
}

void Enemy::kill() {
	clearRender();
	position = origin;
}

void Enemy::update(Walls& walls) {
	if (wallAhead(walls)) {
		while (wallAhead(walls)) {
			direction = randomDirection();
		}
	} else {
		if (!wallAhead(walls, Vec2(direction.y, direction.x)) && rand() % 2) {
			direction = Vec2(direction.y, direction.x);
		}

		if (!wallAhead(walls, Vec2(direction.y, -direction.x)) && rand() % 2) {
			direction = Vec2(direction.y, -direction.x);
		}
	}

	clearRender();
	move();
	render();
}

Enemy::~Enemy() {}
