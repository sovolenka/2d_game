#include "Cannon.h"

#include "graphics.h"

#define SPEED 4

Cannon::Cannon(const int id, const float width, const float height, const float centX, const float centY,
	unsigned int red, unsigned int green, unsigned int blue)
	: MovingObject(id, GetRGB(red, green, blue), width, height, centX, centY)
{
	mSpeed = SPEED;
	setVertices();
}

// ������� ������� ����������
void Cannon::displaySelf()
{
	if (mIsRender)
	{
		DrawLine(mVertices[0].x, mVertices[0].y, mVertices[1].x, mVertices[1].y, mColor);
		DrawLine(mVertices[0].x, mVertices[0].y, mVertices[2].x, mVertices[2].y, mColor);
		DrawLine(mVertices[1].x, mVertices[1].y, mVertices[2].x, mVertices[2].y, mColor);
	}
}

// ������ ���������� ������
void Cannon::setVertices()
{
	mVertices.clear();

	mVertices.push_back(Vec2(mCenter.x, mCenter.y));
	mVertices.push_back(Vec2(mCenter.x - mWidth * 0.5, mCenter.y + mHeight));
	mVertices.push_back(Vec2(mCenter.x + mWidth * 0.5, mCenter.y + mHeight));
}

// ��������� ������� � ������� �������, ������� �� ����� � ���������
void Cannon::movePlayer(const eDirection dir)
{
	int sign;
	if (dir == eDirection::eLeft)
	{
		sign = -1;
	}

	if (dir == eDirection::eRight)
	{
		sign = 1;
	}

	// ��������� ������� �� ������
	for (std::vector<Vec2>::iterator it = mVertices.begin(); it != mVertices.end(); it++)
	{
		it->x += mSpeed * sign;
	}

	mCenter.x += mSpeed * sign;
}

// ������� ������ �������
Vec2 Cannon::getLookDirection()
{
	return Vec2(0, -mHeight);
}