#include "Plane.h"
#include <math.h>
#include "graphics.h"
#include "Geometry.h"

Plane::Plane(const int id, const float width, const float height, const float centX, const float centY, const int movingSpeed,
	unsigned int red, unsigned int green, unsigned int blue)
	: MovingObject(id, GetRGB(red, green, blue), width, height, centX, centY)
{
	mSpeed = movingSpeed;
	setVertices();
	circumRadius = findTriangleCircumRadius(mVertices[0], mVertices[1], mVertices[2]);
	circumCenter = findTriangleCircumCenter(mVertices[0], mVertices[1], mVertices[2]);
}


void Plane::displaySelf()
{
	if (mIsRender)
	{
		DrawLine(mVertices[0].x, mVertices[0].y, mVertices[1].x, mVertices[1].y, mColor);
		DrawLine(mVertices[0].x, mVertices[0].y, mVertices[2].x, mVertices[2].y, mColor);
		DrawLine(mVertices[1].x, mVertices[1].y, mVertices[2].x, mVertices[2].y, mColor);
	}
}

void Plane::setVertices()
{
	mVertices.clear();

	mVertices.push_back(Vec2(mCenter.x, mCenter.y));
	mVertices.push_back(Vec2(mCenter.x - mWidth, mCenter.y - mHeight * 0.5));
	mVertices.push_back(Vec2(mCenter.x - mWidth, mCenter.y + mHeight * 0.5));
}

void Plane::move()
{
	for (std::vector<Vec2>::iterator it = mVertices.begin(); it != mVertices.end(); it++)
	{
		it->x += mSpeed;
	}

	mCenter.x += mSpeed;
	circumCenter.x += mSpeed;
}