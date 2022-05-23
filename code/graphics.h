#ifndef TEST_GRAPHICS_H
#define TEST_GRAPHICS_H


#undef UNICODE
#include <windows.h>


// повертає колір пікселя по даних rgb
inline unsigned int GetRGB(unsigned int r, unsigned int g, unsigned int b)
{
	return r + (g<<8) + (b<<16);
}


void FillRect(int x, int y, int sx, int sy, unsigned int color);
void DrawLine(int x1, int y1, int x2, int y2, unsigned int color);


struct s_init
{
	HINSTANCE		instance;
	WNDPROC			wndProc;
	const char*		captionText;
	int				screenWidth;
	int				screenHeight;
};

HWND InitializeGraphics(const s_init&);

void UninitializeGraphics();


#endif // #ifndef TEST_GRAPHICS_H
