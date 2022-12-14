#pragma once
#include "GameObject.h"
#include "Mouse.h"
class Game;
class MenuButton : public GameObject 
{
private:
	enum mouseState {MOUSE_OUT, MOUSE_OVER, CLICKED};
	Vector2D pos;
	int width, height, currentPositionState;
	Mouse* mouse;
	Texture* texture;
	//void* function(Game* game);
public:
	MenuButton(Vector2D pos, int width, int height, Texture* texture);
	virtual ~MenuButton() {};
	virtual void update();
	virtual void render();
	virtual void handleEvents() {};
	virtual void handleEvents(SDL_Event event);
	SDL_Rect getRect(); // Comun method to get the rectangle for all the objects
	typedef void Callback(Game* game);
};

