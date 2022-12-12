#pragma once
#include "MovingObject.h"
using namespace std;
class Paddle : public MovingObject
{
private:
	Vector2D colVector; // Reflex vector, depending where the ball hits it could change
public:
	Paddle(int width, int height, Texture* texture);
	virtual ~Paddle() {};
	virtual void update();
	void handleEvents(SDL_Event event);
	bool collides(SDL_Rect ballRect, Vector2D& collisionVector);
	void setPos(Vector2D newValue);
	void setWidth(int newValue);
};

