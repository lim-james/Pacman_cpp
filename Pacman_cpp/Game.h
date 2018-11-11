#ifndef GAME_H
#define GAME_H

#include "Walls.h"
#include "Pacman.h"
#include "Enemy.h"
#include "PowerPallet.h"

class Game {
private:
	Walls walls;
	
	Pacman pacman;

	Enemy enemies[4] = {
		Enemy(13, 11, salmon),
		Enemy(13, 11, red),
		Enemy(13, 11, cyan),
		Enemy(13, 11, green)
	};

	PowerPallet powers[4] = {
		PowerPallet(1, 3),
		PowerPallet(1, 23),
		PowerPallet(26, 3),
		PowerPallet(26, 23)
	};

	void hideCursor();

	void interactions(Enemy& e, Pacman& p);

public:
	Game();

	void init();
	void loop();

	~Game();
};

#endif