#include "MenuButton.h"
#include "Game.h"

MenuButton::MenuButton(Vector2D pos, int width, int height, Texture* texture) {
	this->pos = pos;
	this->width = width;
	this->height = height;
	this->texture = texture;
	mouse = new Mouse();
	currentPositionState = MOUSE_OUT;
}
/*void* MenuButton::function(Game* game) {
	cout << "hola";
}*/

void MenuButton::update()
{
	if (mouse->getMousePosition().getX() < (pos.getX() + width)
		&& mouse->getMousePosition().getX() > pos.getX()
		&& mouse->getMousePosition().getY() < (pos.getY() + height)
		&& mouse->getMousePosition().getY() > pos.getY()) {
		currentPositionState = MOUSE_OVER;
	}
	else {
		currentPositionState = MOUSE_OUT;
	}
}

void MenuButton::handleEvents(SDL_Event event) {
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		if (event.button.button == SDL_BUTTON_LEFT) {
			if (currentPositionState == 1) {
				cout << "Click";
				currentPositionState = CLICKED;
			}
		}
	}
}

void MenuButton::render() {
	texture->renderFrame(getRect(), 0, 0);
}

SDL_Rect MenuButton::getRect() {
	SDL_Rect destRect;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	destRect.h = height;
	destRect.w = width;
	return destRect;
}