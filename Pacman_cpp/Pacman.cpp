#include "Pacman.h"

#include <Windows.h>

void Pacman::init() {
	lives = 3;
	direction = Vec2(1, 0);
}

bool Pacman::didPress(uint key) {
	return GetKeyState(key) & 0x8000;
}

void Pacman::keyActions() {
	if (didPress('W')) {
		direction = Vec2(0, -1);
	} else if (didPress('A')) {
		direction = Vec2(-1, 0);
	} else if (didPress('S')) {
		direction = Vec2(0, 1);
	} else if (didPress('D')) {
		direction = Vec2(1, 0);
	}
}

Pacman::Pacman() {
	init();
}

Pacman::Pacman(const uint x, const uint y) : Character(x, y, 'C', yellow) {
	init();
}

void Pacman::kill() {
	lives--;
	position = origin;
}

bool Pacman::hasLivesLeft() {
	return lives;
}

void Pacman::update(Walls& walls) {
	keyActions();
	if (!wallAhead(walls)) {
		clearRender();
		move();
	}
	render();
}

Pacman::~Pacman() {}