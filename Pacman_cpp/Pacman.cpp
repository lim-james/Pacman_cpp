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
	if (didPress('W') || didPress(VK_UP)) {
		direction = Vec2(0, -1);
	} else if (didPress('A') || didPress(VK_LEFT)) {
		direction = Vec2(-1, 0);
	} else if (didPress('S') || didPress(VK_DOWN)) {
		direction = Vec2(0, 1);
	} else if (didPress('D') || didPress(VK_RIGHT)) {
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

uint Pacman::livesLeft() {
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