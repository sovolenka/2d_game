#ifndef RENDERER_H
#define RENDERER_H

#include "GameObject.h"

// ���� Renderer ������� �� ��������� ���������� �� �����
// ����� ��� �� ��'���� (���������� �� ��� ����� displaySelf())
class Renderer
{
public:
	void refresh();
	void render(const std::vector<GameObject*>& renderList);
};

#endif // !RENDERER_H

