#include "Wall.h"
Wall::Wall(int width, int height, Vector2D colVector, Texture* texture)
{
	this->width = width;
	this->height = height;
	this->texture = texture;
	this->colVector = colVector;
}

bool Wall::collides(SDL_Rect ballRect, Vector2D& collisionVector) {
	collisionVector = colVector;
	return SDL_HasIntersection(&ballRect, &getRect());
}


