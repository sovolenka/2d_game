#include "Common.h"

#include <cstdlib>

int SCREEN_WIDTH;
int SCREEN_HEIGHT;

// повертає випадкове число в заданому проміжку
int getRandomNumberInRange(int start, int end)
{
	return start + (std::rand() % (end - start + 1));
}