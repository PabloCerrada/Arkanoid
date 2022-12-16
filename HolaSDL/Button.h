#pragma once
#include "GameObject.h"
class Game;
class Button : public GameObject 
{
private:
	void(*CallBack)(Game* game);
	enum mouseState {MOUSE_OUT, MOUSE_OVER};
	Vector2D pos, mousePos;
	int xMouse, yMouse, width, height, currentPositionState;
	Game* game;
	Texture* texture;
public:
	Button(Vector2D pos, int width, int height, Texture* texture, Game* game, void(*functionCallback)(Game* game));
	virtual ~Button() {};
	virtual void update();
	virtual void render();
	virtual void handleEvents() {};
	virtual void handleEvents(SDL_Event event);
	Vector2D getMousePosition();
	SDL_Rect getRect(); // Comun method to get the rectangle for all the objects
};

