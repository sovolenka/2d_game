#include "Common.h"

#include <cstdlib>

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

// ������� ��������� ����� � �������� �������
int getRandomNumberInRange(int start, int end)
{
	return start + (std::rand() % (end - start + 1));
}