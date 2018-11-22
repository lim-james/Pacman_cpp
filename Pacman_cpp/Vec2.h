#ifndef VEC2_H
#define VEC2_H

#define uint unsigned int 

class Vec2 {

public:

	int x, y;

	Vec2();
	Vec2(const int x, const int y);

	Vec2 operator + (const Vec2& rhs); 
	bool operator == (const Vec2& rhs); 

	~Vec2();

};

#endif