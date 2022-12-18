#include "Button.h"
#include "Game.h"

Button::Button(Vector2D pos, int width, int height, Texture* texture, Game* game, void(*functionCallback)(Game* game)) : CallBack(functionCallback) {
	this->pos = pos;
	this->width = width;
	this->height = height;
	this->texture = texture;
	this->game = game;
	currentPositionState = MOUSE_OUT;
}

void Button::update()
{
	if (getMousePosition().getX() < (pos.getX() + width)
		&& getMousePosition().getX() > pos.getX()
		&& getMousePosition().getY() < (pos.getY() + height)
		&& getMousePosition().getY() > pos.getY()) {
		currentPositionState = MOUSE_OVER;
	}
	else {
		currentPositionState = MOUSE_OUT;
	}

	if (currentPositionState==1)
	{
		if (cont==20)
		{
			cont = 0;
			if (nCols == 2)
			{
				nCols = 0;
			}
			else
			{
				nCols++;
			}
		}
		else
		{
			cont++;
		}
		
	}
	else
	{
		nCols = 0;
	}
}

void Button::handleEvents(SDL_Event event) {
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (event.button.button == SDL_BUTTON_LEFT) {
			if (currentPositionState == 1) {
				CallBack(game);
			}
		}
	}
}

void Button::render() {
	texture->renderFrame(getRect(), 0, nCols);
}

SDL_Rect Button::getRect() {
	SDL_Rect destRect;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	destRect.h = height;
	destRect.w = width;
	return destRect;
}

Vector2D Button::getMousePosition() {
	SDL_GetMouseState(&xMouse, &yMouse);
	mousePos = Vector2D(xMouse, yMouse);
	return mousePos;
}