#ifndef COMMON_H
#define COMMON_H

#include <math.h>

#include "Geometry.h"

extern int SCREEN_WIDTH;
extern int SCREEN_HEIGHT;

typedef unsigned int T_PressedKey;

static const T_PressedKey s_KeyLeft = 0x01;
static const T_PressedKey s_KeyUp = 0x02;
static const T_PressedKey s_KeyRight = 0x04;
static const T_PressedKey s_KeyDown = 0x08;
static const T_PressedKey s_KeySpace = 0x10;

enum eDirection { eUp, eRight, eDown, eLeft};
extern int getRandomNumberInRange(int start, int end);

#endif // !COMMON_H

