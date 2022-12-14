#pragma once
#include "GameState.h"
#include "MenuButton.h"
/*#include "SDL.h"	//posible error circular?
#include "SDL_image.h"					//para poder pasarle el renderer*/

const uint BUTTON_WIDTH = 400;
const uint BUTTON_HEIGHT = 100;
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

