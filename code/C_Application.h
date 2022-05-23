#ifndef TEST_C_APPLICATION_H
#define TEST_C_APPLICATION_H

#include "GameManager.h"

class C_Application
{
public:
	C_Application(int screenWidth, int screenHeight);
	~C_Application();

	// викликається з фіксованою частотою в 50 кадрів в секунду (50 fps)
	void Tick(T_PressedKey pressedKeys);

private:
	const int	m_ScreenWidth;
	const int	m_ScreenHeight;

	GameManager* mManager;
};

#endif // #ifndef TEST_C_APPLICATION_H
