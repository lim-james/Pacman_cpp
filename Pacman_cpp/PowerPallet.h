#ifndef POWERPALLET_H
#define POWERPALLET_H

#include "Entity.h"

class PowerPallet : public Entity {
private:
	bool taken;

	virtual void init();
public:
	PowerPallet();
	PowerPallet(const uint x, const uint y);

	bool isTaken();
	void take();

	~PowerPallet();
};

#endif