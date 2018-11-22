#include "Console.h"

#include <sstream>

void Console::resizeWindow(const RECT rect) {
	MoveWindow(window, rect.top, rect.left, rect.bottom - rect.top, rect.right - rect.left, TRUE);
}

void Console::setTitle(const char* str) {
	SetConsoleTitle(str);
}

void Console::hideCursor() {
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsoleOutput, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hConsoleOutput, &cursorInfo);
}

void Console::disableSelection() {
	SetConsoleMode(hConsoleInput, ENABLE_EXTENDED_FLAGS);
}

void Console::disableResize() {
	HWND consoleWindow = GetConsoleWindow();
	SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
}

void Console::setBackgroundColour(const Colour colour) {
	background = colour;
	std::stringstream stream;
	stream << std::hex << (int)colour * 16;
	std::string result = "color " + stream.str();
	system(result.c_str());
}

void Console::setTextColour(const Colour colour) {
	std::stringstream stream;
	stream << std::hex << (int)colour;
	std::string result = "color " + stream.str();
	system(result.c_str());
}

void Console::gotoPosition(const Vec2 position) {
	COORD pos;
	pos.X = position.x + 5;
	pos.Y = position.y + 8;
	SetConsoleCursorPosition(hConsoleOutput, pos);
}

void Console::setColour(const Colour foreground, const Colour background) {
	SetConsoleTextAttribute(hConsoleOutput, background * 16 + foreground);
}

void Console::clear(const Vec2 position) {
	gotoPosition(position);
	std::cout << ' ';
}

void Console::clear(const Vec2 position, const Vec2 size) {
	draw(position, size, background);
}

void Console::draw(const Vec2 position, const Vec2 size, const Colour fill) {
	setColour(black, fill);

	for (int x = (int)position.x; x < (int)position.x + size.x; ++x) {
		for (int y = (int)position.y; y < (int)position.y + size.y; ++y) {
			gotoPosition(Vec2(x, y));
			std::cout << ' ';
		}
	}
}