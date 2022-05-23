#include "Bullet.h"

#include "graphics.h"

#define SPEED 0.5 // швидкість снаряду за замовчування

Bullet::Bullet(const int id, const float width, const float height, const float centX, const float centY,
				const float moveDirX, const float movedirY, unsigned int red, unsigned int green, unsigned int blue)
	:MovingObject(id, GetRGB(red, green, blue), width, height, centX, centY, moveDirX, movedirY)
{
	mSpeed = SPEED;
	// рохраховуємо вершини
	setVertices();
	// рахуємо радіус описаного кола та його центр
	circumCenter = findRectangleCircumCenter(mVertices[0], mVertices[3]);
	circumRadius = findRectangleCircumRadius(mVertices[0], mVertices[3]);
}

// відображається як прямокутник
// малюємо сторони
void Bullet::displaySelf()
{
	if (mIsRender)
	{
		DrawLine(mVertices[0].x, mVertices[0].y, mVertices[1].x, mVertices[1].y, mColor);
		DrawLine(mVertices[1].x, mVertices[1].y, mVertices[3].x, mVertices[3].y, mColor);
		DrawLine(mVertices[3].x, mVertices[3].y, mVertices[2].x, mVertices[2].y, mColor);
		DrawLine(mVertices[2].x, mVertices[2].y, mVertices[0].x, mVertices[0].y, mColor);
	}
}

// коли переміщуємося, зміщуємо всі вершини, та центри
void Bullet::move()
{
	// переміщуємо вершини
	for (std::vector<Vec2>::iterator it = mVertices.begin(); it != mVertices.end(); it++)
	{
		it->x += (mMoveDirection.x * mSpeed);
		it->y += (mMoveDirection.y * mSpeed);
	}

	mCenter.x += (mMoveDirection.x * mSpeed);
	mCenter.y += (mMoveDirection.y * mSpeed);

	circumCenter.x += (mMoveDirection.x * mSpeed);
	circumCenter.y += (mMoveDirection.y * mSpeed);
}

void Bullet::setVertices()
{
	mVertices.clear();

	mVertices.push_back(Vec2(mCenter.x - (mWidth * 0.5), mCenter.y - (mHeight * 0.5)));
	mVertices.push_back(Vec2(mCenter.x + (mWidth * 0.5), mCenter.y - (mHeight * 0.5)));
	mVertices.push_back(Vec2(mCenter.x - (mWidth * 0.5), mCenter.y + (mHeight * 0.5)));
	mVertices.push_back(Vec2(mCenter.x + (mWidth * 0.5), mCenter.y + (mHeight * 0.5)));
}
