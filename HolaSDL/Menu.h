#pragma once
#include "ArkanoidObject.h"
class Menu: public ArkanoidObject
{
private:
	string decision = " ";
	SDL_Event event;
	int x, y;
	int newGameTop = 372, newGameDown = 502, left = 238, right = 560, loadTop = 217, loadDown = 343;
public:
	Menu() {};
	Menu(Vector2D pos, int width, int height, Texture* texture);
	string getDecision();
	virtual ~Menu() {};
	virtual void handleEvents();
};

