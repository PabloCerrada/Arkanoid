#pragma once
#include "GameState.h"
#include "SDL.h"	//posible error circular?
#include "SDL_image.h"					//para poder pasarle el renderer

class MainMenuState:public GameState
{
public:
	MainMenuState(SDL_Renderer* renderer);
	virtual void update();
	virtual void render();
};

