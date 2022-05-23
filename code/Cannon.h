#ifndef CANNON_H
#define CANNON_H

#include "Common.h"
#include "MovingObject.h"

// клас Cannon - гармата, якою керує гравець
// зображається трикутником
class Cannon : public MovingObject
{
public:
	Cannon(const int id, const float width, const float height, const float centX, const float centY,
		unsigned int red = 0, unsigned int green = 0, unsigned int blue = 255);

	void displaySelf();
	void move() {}
	void setVertices();
	void movePlayer(const eDirection dir);
	Vec2 getLookDirection();
};

#endif 

