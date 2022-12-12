#pragma once
#include "ArkanoidObject.h"
class Wall : public ArkanoidObject
{
private:
	Vector2D colVector; // Reflex vector, left wall = (1, 0), right wall = (-1, 0), top wall = (0, 1)
public:
	Wall() {};
	Wall(int width, int height, Vector2D colVector, Texture* texture);
	virtual ~Wall() {};
	bool collides(SDL_Rect ballRect, Vector2D& collisionVector);
};

