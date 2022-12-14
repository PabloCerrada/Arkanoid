#pragma once
#include "GameState.h"
#include "MenuButton.h"
/*#include "SDL.h"	//posible error circular?
#include "SDL_image.h"					//para poder pasarle el renderer*/


class Game;
class MainMenuState:public GameState
{
private:
	Game* game;
	MenuButton* resumeButton;
	MenuButton* playButton;
	MenuButton* exitButton;
public:
	MainMenuState(Game* game);
	virtual void update();
	virtual void render();
	virtual void handleEvent();
};

