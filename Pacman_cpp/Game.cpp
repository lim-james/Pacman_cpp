#include "Game.h"

#include <ctime>

void Game::hideCursor() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Game::interactions(Enemy& e, Pacman& p) {
	if (Enemy::inDanger) {
		e.kill();
	} else {
		p.kill();
	}
}

Game::Game() {}

void Game::init() {
	srand((uint)time(NULL));
	hideCursor();

	walls.load("Walls.txt");
	pacman = Pacman(13, 23);
	walls.render();
}

void Game::loop() {
	while (pacman.hasLivesLeft()) {
		if (Enemy::inDanger) Enemy::inDanger--;

		pacman.update(walls);

		for (PowerPallet& p : powers) {
			if (p.isTaken()) continue;
			if (pacman.collided(p)) {
				p.take();
				Enemy::inDanger = 20;
			}
			p.render();
		}

		for (Enemy& e : enemies) {
			if (e.collided(pacman)) interactions(e, pacman);
			e.update(walls);
			if (e.collided(pacman)) interactions(e, pacman);
		}

		Sleep(120);
	}
}

Game::~Game() {}
