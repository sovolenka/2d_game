#include "Renderer.h"

#include "Common.h"

#include "graphics.h"

void Renderer::refresh()
{
	// очищаємо екран, малюємо фон

	// малюємо небо
	FillRect(0, 0, SCREEN_WIDTH, 575, GetRGB(135, 206, 250));
	// малюємо землю
	FillRect(0, 575, SCREEN_WIDTH, SCREEN_HEIGHT, GetRGB(139, 69, 19));
}

// відображаємо об'єкти
void Renderer::render(const std::vector<GameObject*>& renderList)
{
	for (int ei = 0; ei < renderList.size(); ei++)
	{
		renderList[ei]->displaySelf();
	}
}