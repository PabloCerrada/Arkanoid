#include "Ball.h"
#include "Game.h"

Ball::Ball(int radius, Vector2D colVector, Texture* texture, Game* game)
{
	this->width = radius;
	this->height = radius;
	this->texture = texture;
	this->game = game;
	this->colVector = colVector;
}

void Ball::update() {
	// We only change the direction if the ball collides with something
	if (game->collidesBall(getRect(), colVector)) {
		direction = direction - colVector * (2 * (direction * colVector)); // Bounce direction equation
	}
	direction.normalize(); // We normalize the vector to avoid summing up the velocity
	pos = pos + direction * velocity;
	
}

void Ball::setDirection(Vector2D newValue) { // Method to change the direction to the original when a level is completed
	direction = newValue;
}
void Ball::setPos(Vector2D newValue) { // Method to change the position to the original when a level is completed
	pos = newValue;
}