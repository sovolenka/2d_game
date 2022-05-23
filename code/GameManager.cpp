#include "GameManager.h"
#include "Geometry.h"
#include <typeinfo>

#include"Bullet.h"

#include <queue>

#define BULLET_WIDTH 1
#define BULLET_HEIGHT 4

#define PLANE_WIDTH 20
#define PLANE_HEIGHT 10

#define CANNON_WIDTH 20
#define CANNON_HEIGHT 30
#define CANNON_WIDTH_PER 0.5
#define CANNON_HEIGHT_PER  0.9

// ��������� ���� - ���� id ��� GameObjects
class IdManager
{
public:

	static void init()
	{
		nextId = 0;
	}

	static int getId()
	{
		if (idQueue.empty())
		{
			return nextId++;
		}
		
		int id = idQueue.front();
		idQueue.pop();
		return id;
	}

	static void giveIdBack(const int id)
	{
		idQueue.push(id);
	}

	static void reset()
	{
		init();
		std::queue<int> empty;
		std::swap(idQueue, empty);
	}

private:

	static int nextId;
	static std::queue<int> idQueue;
};
std::queue<int> IdManager::idQueue;
int IdManager::nextId;

GameManager::GameManager()
{
	IdManager::init();

	mNpcCounter = 0;

	mRenderer = new Renderer();
}

GameManager::~GameManager()
{
	delete mRenderer;

	for (int ci = 0; ci < mAIList.size(); ci++)
	{
		delete mAIList[ci];
	}
	mAIList.clear();
}

void GameManager::init()
{
	createLevel();
}

// ������� ���� �� ��������� ����� � �������� �� 10 �� 300
// �� � ���������� �������� � �������� �� 1 �� 15
void GameManager::generateNpc()
{
	int randomHeight = getRandomNumberInRange(10, 300);
	int randomSpeed = getRandomNumberInRange(1, 15);

	mAIList.push_back(new Plane(IdManager::getId(), PLANE_WIDTH, PLANE_HEIGHT, 0, randomHeight, randomSpeed));
	mNpcCounter++;
}

// ������� ��������� ������� �����
void GameManager::generateRandomNumberOfNpcs()
{
	int randomNumberOfNpcs = getRandomNumberInRange(1, 5);

	for (int x = 0; x < randomNumberOfNpcs; x++)
	{
		generateNpc();
	}
}

bool GameManager::createLevel()
{
	// ���������� ������� �����
	// ��������� ����� �� �������
	generateRandomNumberOfNpcs();

	player = new Cannon(IdManager::getId(), CANNON_WIDTH, CANNON_HEIGHT,
									(SCREEN_WIDTH * CANNON_WIDTH_PER), (SCREEN_HEIGHT * CANNON_HEIGHT_PER));

	return true;
}

// ���������� ��� � ���������
void GameManager::handleKey(const T_PressedKey pressedKeys)
{
	if (pressedKeys & s_KeyLeft)
	{
		player->movePlayer(eDirection::eLeft);
	}

	if (pressedKeys & s_KeyRight)
	{
		player->movePlayer(eDirection::eRight);
	}

	if (pressedKeys & s_KeySpace)
	{
		// ���� ������� �������� �� ����� - ��������� �������
		Vec2 pos = player->getCenter();
		Vec2 dir = player->getLookDirection();

		mAIList.push_back(new Bullet(IdManager::getId(), BULLET_WIDTH, BULLET_HEIGHT, pos.x, pos.y, dir.x, dir.y));
	}
}

void GameManager::updateObjects()
{
	// ������ ����� �� �������
	for (int ci = 0; ci < mAIList.size(); ci++)
	{
		mAIList[ci]->move();
	}
}

void GameManager::updateStage()
{
	// ��������� ���������� �� ������
	// ���� ��'��� ������� ����� - ���������
	// ���� ���� ���� ������ - ���������

	std::vector<int> removeObjects;

	// ����������� �� ��� ������ �� ��������
	for (int ai = 0; ai < mAIList.size(); ai++)
	{
		// ���� ������� �����
		if (mAIList[ai]->getCenter().x > SCREEN_WIDTH || mAIList[ai]->getCenter().y < 0) {
			removeObjects.push_back(ai);

			// ���� ����
			if (dynamic_cast<Bullet*>(mAIList[ai]) == nullptr) {
				// �������� ������� �����
				mNpcCounter--;
			}
			continue;
		}
		else {
			// ���� �� ������
			if (dynamic_cast<Bullet*>(mAIList[ai]) == nullptr) {
				// ���������� �� ������� ���糿
				// ��������� ����� �� ��'����
				for (int ab = 0; ab < mAIList.size(); ab++)
				{
					// ���� ������
					if (dynamic_cast<Plane*>(mAIList[ab]) == nullptr) {
						// ����������, �� ��������� ������ �� ����
						bool collided = testCircleCollission(mAIList[ai]->getCircumCenter(), mAIList[ab]->getCircumCenter(), mAIList[ai]->getCircumRadius(), mAIList[ab]->getCircumRadius());

						if (collided) {
							// ���� ��������� - ��������� ����
							removeObjects.push_back(ai);
							mNpcCounter--;
							break;
						}
					}
				}
			}
		}
	}

	// ��������� ����� � ������
	for (int i = removeObjects.size() - 1; i > -1; i--)
	{
		mAIList.erase(mAIList.begin() + removeObjects[i]);
	}
	// ���� ���� �������� �� ����� - ���������
	if (mNpcCounter == 0) {
		generateRandomNumberOfNpcs();
	}
}

void GameManager::callFrameBegining(const T_PressedKey pressedKeys)
{
	// ������� �����
	mRenderer->refresh();

	// ���������� ��� � ���������
	handleKey(pressedKeys);

	// ������ ����� �� �������
	updateObjects();

	// ���������� �������� �� ���� �� �����
	updateStage();
}

void GameManager::render()
{
	// ���������� ��'����
	std::vector<GameObject*> displayList;
	// ������� ����� �� �������
	displayList.insert(displayList.end(), mAIList.begin(), mAIList.end());
	// ������� �������
	displayList.insert(displayList.end(), player);
	mRenderer->render(displayList);
}
