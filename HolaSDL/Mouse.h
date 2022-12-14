#pragma once
#include "SDL.h"
#include "Vector2D.h"
class Mouse
{
private:
	Vector2D pos;
	int x, y;
public:
	Mouse() {};
	Vector2D getMousePosition();
};

