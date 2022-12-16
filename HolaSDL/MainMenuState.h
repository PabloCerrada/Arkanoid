#pragma once
#include "GameState.h"
#include "MenuButton.h"
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
	~MainMenuState();
	virtual void update();
	virtual void render();
	virtual void handleEvents();
};

