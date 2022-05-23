#ifndef MOVINGOBJECT_H
#define MOVINGOBJECT_H

#include "GameObject.h"

// абстрактний клас для всіх рухомих об'єктів
class MovingObject : public GameObject
{
public:
	MovingObject() {}

	MovingObject(const int id, const unsigned int color, const float width, const float height)
		: GameObject(id, color, width, height) {}

	MovingObject(const int id, const unsigned int color, const float width, const float height,
				const float centX, const float centY)
		: GameObject(id, color, width, height, centX, centY) {}

	MovingObject(const int id, const unsigned int color, const float width, const float height,
				const float centX, const float centY, const float moveDirX, const float movedirY)
		: GameObject(id, color, width, height, centX, centY)
	{
		mMoveDirection.x = moveDirX;
		mMoveDirection.y = movedirY;
	}

	virtual void move() = 0;

	virtual void setDirection(const Vec2& dir)
	{
		mMoveDirection.x = dir.x;
		mMoveDirection.y = dir.y;
	}

	virtual Vec2 getDirection()
	{
		return mMoveDirection;
	}

	virtual Vec2 getCircumCenter()
	{
		return circumCenter;
	}

	virtual double getCircumRadius()
	{
		return circumRadius;
	}

protected:

	float mSpeed;
	Vec2 mMoveDirection;
	Vec2 circumCenter;
	double circumRadius;
};

#endif // !MOVINGOBJECT_H

