#ifndef OBJECT_H 
#define OBJECT_H

#include "Vec2.h"
#include "Colour.h"
#include "Console.h"

class Object {

protected:

	Vec2 position, size;
	char icon;
	Colour colour;

	Object();
	Object(const uint x, const uint y, const uint width, const uint height, const char c, const Colour colour);

	~Object();

public:

	virtual void render() = 0;

};

#endif