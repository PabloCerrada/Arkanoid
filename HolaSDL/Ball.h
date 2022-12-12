#pragma once
#include "MovingObject.h"
class Game;
class Ball : public MovingObject
{
private:
	Vector2D colVector; // Reflex vector, depending where the balls hits
	Game* game;
public:
	Ball(int radius, Vector2D colVector, Texture* texture, Game* game);
	virtual ~Ball() {};
	virtual void update();
	void setPos(Vector2D newValue);
	void setDirection(Vector2D newValue);
};

