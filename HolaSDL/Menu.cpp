#include "Menu.h"

Menu::Menu(Vector2D pos, int width, int height, Texture* texture)
{
	this->pos = pos;
	this->width = width;
	this->height = height;
	this->texture = texture;
}
void Menu::handleEvents() // This method handles the mouse input and depending on where you click the decision is Load or NewGame
{
	while (SDL_PollEvent(&event)) {
		SDL_GetMouseState(&x, &y);
		if (event.type == SDL_MOUSEBUTTONDOWN) {
			if (event.button.button == SDL_BUTTON_LEFT) {
				if ( y > loadTop && y < loadDown && x > left && x < right) {
					decision = "LOAD";
				}
				else if (y > newGameTop && y < newGameDown && x > left && x < right) {
					decision = "NEW GAME";
				}
			}
		}
	}
	
	
}

string Menu::getDecision()
{
	return decision;
}