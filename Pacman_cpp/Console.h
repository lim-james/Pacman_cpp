#ifndef CONSOLE_H
#define CONSOLE_H

#include "Colour.h"
#include "Vec2.h"

#include <Windows.h>
#include <iostream>

namespace Console {

	static const HWND window = GetConsoleWindow();
	static const HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	static const HANDLE hConsoleInput = GetStdHandle(STD_INPUT_HANDLE);

	static Colour background = black;

	void resizeWindow(const RECT rect);
	void setTitle(const char* str);

	void hideCursor();
	void disableSelection();
	void disableResize();

	void setBackgroundColour(const Colour colour);
	void setTextColour(const Colour colour);

	void gotoPosition(const Vec2 position);
	void setColour(const Colour foreground, const Colour background);

	void clear(const Vec2 position);
	void clear(const Vec2 position, const Vec2 size);

	void draw(const Vec2 position, const Vec2 size, const Colour fill);

	template<typename type>
	void draw(const Vec2 position, const type content, const Colour foreground, const Colour background = black) {
		gotoPosition(position);
		setColour(foreground, background);
		std::cout << content;
	}

}

#endif