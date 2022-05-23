#include "Common.h"
#include <math.h>

// будує лінію між двома точками
void lineFromPoints(Vec2 P, Vec2 Q, double& a,
	double& b, double& c)
{
	a = Q.y - P.y;
	b = P.x - Q.x;
	c = a * (P.x) + b * (P.y);
}


// перетворює вхідну лінію в її серединний перпендикуляр
void perpendicularBisectorFromLine(Vec2 P, Vec2 Q,
	double& a, double& b, double& c)
{
	Vec2 mid_point = Vec2((P.x + Q.x) / 2,
		(P.y + Q.y) / 2);

	// c = -bx + ay
	c = -b * (mid_point.x) + a * (mid_point.y);

	double temp = a;
	a = -b;
	b = temp;
}

// повертає точку перетину двох ліній
Vec2 lineLineIntersection(double a1, double b1, double c1,
	double a2, double b2, double c2)
{
	double determinant = a1 * b2 - a2 * b1;
	double x = (b2 * c1 - b1 * c2) / determinant;
	double y = (a1 * c2 - a2 * c1) / determinant;
	return Vec2(x, y);
	
}

// знаходить центр описаного кола трикутника методок серединних перпендикулярів
//Vec2 findTriangleCircumCenter(Vec2 P, Vec2 Q, Vec2 R)
//{
//	// Line PQ is represented as ax + by = c
//	double a, b, c;
//	lineFromPoints(P, Q, a, b, c);
//
//	// Line QR is represented as ex + fy = g
//	double e, f, g;
//	lineFromPoints(Q, R, e, f, g);
//
//	// Converting lines PQ and QR to perpendicular
//	// vbisectors. After this, L = ax + by = c
//	// M = ex + fy = g
//	perpendicularBisectorFromLine(P, Q, a, b, c);
//	perpendicularBisectorFromLine(Q, R, e, f, g);
//
//	// The point of intersection of L and M gives
//	// the circumcenter
//	Vec2 circumcenter =
//		lineLineIntersection(a, b, c, e, f, g);
//
//	return circumcenter;
//}

// знаходить центр описаного кола трикутника
Vec2 findTriangleCircumCenter(Vec2 A, Vec2 B, Vec2 C)
{
	int d = 2 * (A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
	int ux = ((A.x * A.x + A.y * A.y) * (B.y - C.y) + (B.x * B.x + B.y * B.y) * (C.y - A.y) + (C.x * C.x + C.y * C.y) * (A.y - B.y)) / d;
	int uy = ((A.x * A.x + A.y * A.y) * (C.x - B.x) + (B.x * B.x + B.y * B.y) * (A.x - C.x) + (C.x * C.x + C.y * C.y) * (B.x - A.x)) / d;
	return Vec2(ux, uy);
}

// рахує довжину лінії по двом точкам
double getLineLengthByPoints(Vec2 P, Vec2 Q)
{
	return sqrt(pow((Q.x - P.x), 2) + pow((Q.y - P.y), 2));
}

// рахує площу трикутника за формулою Герона
double getTriangleAreaByLines(double a, double b, double c)
{
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

// рахує радіус описаного кола для трикутника
double findTriangleCircumRadius(Vec2 P, Vec2 Q, Vec2 R)
{
	double pq = getLineLengthByPoints(P, Q);
	double qr = getLineLengthByPoints(Q, R);
	double pr = getLineLengthByPoints(P, R);

	double s = getTriangleAreaByLines(pq, qr, pr);
	return (pq * qr * pr) / (4 * s);;
}

// P та Q це діагональні вершини прямокутника
double findRectangleCircumRadius(Vec2 P, Vec2 Q)
{
	return getLineLengthByPoints(P, Q) / 2;
}

// рахує центр описаного кола для прямокутника
Vec2 findRectangleCircumCenter(Vec2 P, Vec2 Q)
{
	return Vec2((P.x + Q.x) / 2, (P.y + Q.y) / 2);
}

// перевіряє, чи сталося зіткнення (колізія)
bool testCircleCollission(Vec2 center1, Vec2 center2, double radius1, double radius2)
{
	// рахуємо відстань між центрами двох кіл
	double dx = (center1.x + radius1) - (center2.x + radius2);
	double dy = (center1.y + radius1) - (center2.y + radius2);

	double distance = sqrt(dx * dx + dy * dy);

	// якщо відстань між центрами менше, ніж сума радіусів кіл
	// значить сталося зіткнення
	if (distance < radius1 + radius2)
	{
		// зіткнення
		return true;
	}
	else {
		// нема зіткнення
		return false;
	}
}
