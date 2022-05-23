#include "Common.h"
#include "MovingObject.h"

// ���� Plane - ����, �� ������� GameManager
// ������ ������ ���� �������, � ������� ��������
class Plane : public MovingObject
{
public:
	Plane(const int id, const float width, const float height, const float centX, const float centY, const int movingSpeed = 4,
		unsigned int red = 255, unsigned int green = 0, unsigned int blue = 0);

	void displaySelf();
	void move();
	void setVertices();
};

