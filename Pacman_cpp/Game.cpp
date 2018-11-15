#include "Game.h"

#include <ctime>

void Game::resizeWindow() {
	HWND hwnd = GetConsoleWindow();
	RECT rect = { 100, 100, 750, 650 }; // lef top right bottom
	MoveWindow(hwnd, rect.top, rect.left, rect.bottom - rect.top, rect.right - rect.left, TRUE);
}

void Game::hideCursor() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(out, &cursorInfo);
}

void Game::disableSelection() {
	HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
	SetConsoleMode(in, ENABLE_EXTENDED_FLAGS);
}

void Game::resetEnemies() {
	for (Enemy& e : enemies) {
		e.kill();
	}
}

void Game::interactions(Enemy& e, Pacman& p) {
	if (Enemy::inDanger) {
		e.kill();
		score++;
		renderScore();
		Sleep(200);
	} else {
		p.kill();
		resetEnemies();
		renderLives();
		renderReady();
		Sleep(500);
	}
}

void Game::renderReady() {
	Vec2(11, 17).draw("READY!", yellow);
	Sleep(2000);
	Vec2(11, 17).draw("      ", white);
}

void Game::renderScore() {
	std::string msg = "Score : " + std::to_string(this->score);
	Vec2(0, -4).draw(msg.c_str(), white);
}

void Game::renderMoves() {
	std::string msg = "Moves : " + std::to_string(this->moves);
	Vec2(0, -3).draw(msg.c_str(), white);
}

void Game::renderLives() {
	Vec2(0, -2).draw("              ", white);
	std::string msg = "Lives : ";
	Vec2(0, -2).draw(msg.c_str(), white);
	for (int i = 0; i < pacman.livesLeft(); ++i) {
		Vec2(msg.length() + i * 2, -2).draw('C', yellow);
	}
}

Game::Game() : score(0), moves(0) {}

void Game::init() {
	srand((uint)time(NULL));

	resizeWindow();
	hideCursor();
	disableSelection();

	walls.load("Walls.txt");
	pacman = Pacman(13, 23);
	walls.render();

	renderScore();
	renderLives();
	renderReady();
}

void Game::loop() {
	while (pacman.livesLeft()) {
		moves++;
		renderMoves();

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
			if (moves % 2) {
				e.update(walls);
				if (e.collided(pacman)) interactions(e, pacman);
			}
		}

		Sleep(100);
	}
}

Game::~Game() {}
