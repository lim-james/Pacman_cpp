#ifndef PACMAN_H
#define PACMAN_H

#include "Character.h"
#include "PowerPallet.h"

class Pacman : public Character {
private:
	uint lives;
	
	bool didPress(uint key);
	void keyActions();

	virtual void init();

public:
	Pacman();
	Pacman(const uint x, const uint y);

	bool hasLivesLeft();

	virtual void kill();
	virtual void update(Walls& walls);

	~Pacman();
};

#endif