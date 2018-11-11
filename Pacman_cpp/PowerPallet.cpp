#include "PowerPallet.h"

void PowerPallet::init() {
	taken = false;
}

PowerPallet::PowerPallet() {
	init();
}

PowerPallet::PowerPallet(const uint x, const uint y) : Entity(x, y, 'O', white) {
	init();
}

bool PowerPallet::isTaken() {
	return taken;
}

void PowerPallet::take() {
	taken = true;
}

PowerPallet::~PowerPallet() {}
