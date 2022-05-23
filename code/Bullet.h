#ifndef BULLET_H
#define BULLET_H

#include "MovingObject.h"

// ���� Bullet - ����������� GameManager, ���� ���������� ������� �����
// ����������� � ���� ������������
class Bullet : public MovingObject
{
public:
	Bullet(const int id, const float width, const float height, const float centX, const float centY,
			const float moveDirX, const float movedirY, unsigned int red = 255, unsigned int green = 255, unsigned int blue = 255);

	void displaySelf();
	void move();
	void setVertices();
};

#endif // !BULLET_H

