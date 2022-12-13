#pragma once
#include "MovingObject.h"
class PlayState;
class Ball : public MovingObject
{
private:
	Vector2D colVector; // Reflex vector, depending where the balls hits
	PlayState* playState;
public:
	Ball(int radius, Vector2D colVector, Texture* texture, PlayState* playState);
	virtual ~Ball() {};
	virtual void update();
	void setPos(Vector2D newValue);
	void setDirection(Vector2D newValue);
};

