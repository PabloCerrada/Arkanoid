#include "Paddle.h"
#include "PlayState.h"
Paddle::Paddle(int width, int height, Texture* texture)
{
	this->width = width;
	this->height = height;
	this->texture = texture;
}

void Paddle::update() {
	// The paddle can only be moved between certains dimensions
	// We use both offsets equal to 4
	if (pos.getX() > WALL_WIDTH + 4 && direction.getX() < 0 || pos.getX() < WIN_WIDTH - width - WALL_WIDTH - 4 && direction.getX() > 0)
	{
		pos = pos + direction * velocity;
	}

}

//This functions handles when a key is held and adds velocity depending of the key.
void Paddle::handleEvents(SDL_Event event) {
	if (event.type == SDL_KEYDOWN) {
		if (event.key.keysym.sym == SDLK_LEFT) {
			direction = Vector2D(-1, 0);
		}
		else if (event.key.keysym.sym == SDLK_RIGHT) {
			direction = Vector2D(1, 0);
		}
	}
	else {
		direction = Vector2D(0, 0);
	}
}
bool Paddle::collides(SDL_Rect ballRect, Vector2D& collisionVector) {
	// We calcule the intersection rectangule between the ball and the paddle
	SDL_Rect intersectionScreenPoint;
	SDL_IntersectRect(&ballRect, &getRect(), &intersectionScreenPoint);

	// We calcule the distance between the center in x of the intersection rectangle to the center of the paddle 
	// and we scale it to ratio of (-1,1). 0 is the center, -1 is the max value at the left of the paddle and 1 at the rightside
	double intersectionPaddlePoint = (double)((intersectionScreenPoint.x + intersectionScreenPoint.w / 2) - (getRect().x + getRect().w / 2)) / (width / 2);
	colVector = Vector2D(intersectionPaddlePoint, -2);
	collisionVector = colVector;
	return SDL_HasIntersection(&ballRect, &getRect());
}

void Paddle::setPos(Vector2D newValue) { // Method to change the position to the original when a level is completed
	pos = newValue;
}

void Paddle::setWidth(int newValue) { // Method to change the width to the original when a reward-time is completed
	width = newValue;
}

