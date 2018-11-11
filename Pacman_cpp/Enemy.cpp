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
	position.draw(icon, inDanger ? blue : colour);
}

void Enemy::kill() {
	position = origin;
}

void Enemy::update(Walls& walls) {
	while (wallAhead(walls)) {
		direction = randomDirection();
	}
	clearRender();
	move();
	render();
}

Enemy::~Enemy() {}
