#ifndef GEOMETRY_H
#define GEOMETRY_H

struct Vec2
{
	Vec2()
	{
		x = 0;
		y = 0;
	}
	Vec2(const float _x, const float _y)
		: x(_x), y(_y)
	{}

	float x, y;
};
// трикутник
extern Vec2 findTriangleCircumCenter(Vec2 P, Vec2 Q, Vec2 R);
extern double findTriangleCircumRadius(Vec2 P, Vec2 Q, Vec2 R);
// прямокутник
extern double findRectangleCircumRadius(Vec2 P, Vec2 Q);
extern Vec2 findRectangleCircumCenter(Vec2 P, Vec2 Q);

extern bool testCircleCollission(Vec2 center1, Vec2 center2, double radius1, double radius2);
#endif // !GEOMETRY_H
