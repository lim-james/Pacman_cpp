#include "Object.h"

Object::Object() : position(Vec2(0,0)), size(Vec2(0,0)), icon(' ') {
}

Object::Object(const uint x, const uint y, const uint width, const uint height, const char c, const Colour co)
	: position(Vec2(x, y)), size(Vec2(width, height)), icon(c), colour(co) {

}

Object::~Object() {
}
