#pragma once
#include "GameObject.h"
class Game;
class MenuButton : public GameObject 
{
private:
	enum mouseState {MOUSE_OUT, MOUSE_OVER};
	Vector2D pos, mousePos;
	int xMouse, yMouse, width, height, currentPositionState;
	Game* game;
	Texture* texture;
	void(* CallBack)(Game* game);
public:
	MenuButton(Vector2D pos, int width, int height, Texture* texture, Game* game, void(* functionCallback)(Game* game));
	virtual ~MenuButton() {};
	virtual void update();
	virtual void render();
	virtual void handleEvents() {};
	virtual void handleEvents(SDL_Event event);
	Vector2D getMousePosition();
	SDL_Rect getRect(); // Comun method to get the rectangle for all the objects
	//typedef void Callback(Game* game);
};

