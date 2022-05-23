#ifndef RENDERER_H
#define RENDERER_H

#include "GameObject.h"

// клас Renderer відповідає за виведення зображення на екран
// малює фон та об'єкти (викликаючи на них метод displaySelf())
class Renderer
{
public:
	void refresh();
	void render(const std::vector<GameObject*>& renderList);
};

#endif // !RENDERER_H

