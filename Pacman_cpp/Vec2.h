#ifndef VEC2_H
#define VEC2_H

#include <Windows.h>

#include "Colour.h"

#define uint unsigned int 

class Vec2 {
public:
	int x, y;

	Vec2();
	Vec2(const int x, const int y);

	void draw(const char * str, Colour colour);
	void draw(const char c, Colour colour);
	Vec2 operator + (const Vec2& rhs); 
	bool operator == (const Vec2& rhs); 

	COORD coord();

	~Vec2();
};

#endif