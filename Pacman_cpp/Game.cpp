#include "Game.h"

#include <ctime>

void Game::renderReady() {
	Console::draw(Vec2(11, 17), "READY!", yellow);
	Sleep(2000);
	Console::clear(Vec2(11, 17), Vec2(6, 1));
}

void Game::renderScore() {
	std::string msg = "Score : " + std::to_string(this->score);
	Console::draw(Vec2(0, -4), msg, white);
}

void Game::renderMoves() {
	std::string msg = "Moves : " + std::to_string(this->moves);
	Console::draw(Vec2(0, -3), msg, white);
}

void Game::renderLives() {
	Console::clear(Vec2(0, -2), Vec2(15, 1));
	std::string msg = "Lives : ";
	Console::draw(Vec2(0, -2), msg, white);
	for (uint i = 0; i < pacman.livesLeft(); ++i) {
		Console::draw(Vec2(msg.length() + i * 2, -2), 'C', yellow);
	}
}

void Game::resetEnemies() {
	for (Enemy& e : enemies) e.kill();
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

Game::Game() : score(0), moves(0) {}

void Game::init() {
	srand((uint)time(NULL));

	Console::resizeWindow({ 100, 100, 750, 650 });
	Console::setTitle("PACMAN");
	Console::hideCursor();
	Console::disableSelection();
	Console::disableResize();
	Console::setBackgroundColour(black);

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
				Enemy::inDanger = 30;
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