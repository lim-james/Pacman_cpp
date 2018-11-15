#include "Vec2.h"

#include <iostream>

Vec2::Vec2() : x(0), y(0) {}

Vec2::Vec2(const int x, const int y) : x(x), y(y) {}

void Vec2::draw(const char * str, Colour colour) {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, coord());
	SetConsoleTextAttribute(hConsoleOutput, colour);

	std::cout << str;
}

void Vec2::draw(const char c, Colour colour) {
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, coord());
	SetConsoleTextAttribute(hConsoleOutput, colour);

	std::cout << c;
}

Vec2 Vec2::operator + (const Vec2& rhs) {
	return Vec2(x + rhs.x, y + rhs.y);
}

bool Vec2::operator == (const Vec2& rhs) {
	return x == rhs.x && y == rhs.y;
}

COORD Vec2::coord() {
	COORD c;
	c.X = x + 5;
	c.Y = y + 8;
	return c;
}

Vec2::~Vec2() {}
