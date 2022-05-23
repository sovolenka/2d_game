#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Cannon.h"
#include "Plane.h"
#include "Bullet.h"
#include "Renderer.h"

// клас GameManager керує грою - він створює літаки, гармату та снаряди
// а також обробляє ввід з клавіатури та викликає Renderer для відображення на екрані
class GameManager
{
public:
	GameManager();
	~GameManager();

	void init();

	void callFrameBegining(const T_PressedKey pressedKeys);
	void render();

private:

	void generateNpc();
	void generateRandomNumberOfNpcs();
	bool createLevel();

	void updateObjects();
	void updateStage();

	void handleKey(const T_PressedKey pressedKeys);

	unsigned int mNpcCounter;

	Renderer* mRenderer;

	Cannon* player;
	
	std::vector<MovingObject*> mAIList;
};

#endif // !GAMEMANAGER_H
