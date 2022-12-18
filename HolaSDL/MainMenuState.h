#pragma once
#include "GameState.h"
#include "Button.h"
class Game;
class MainMenuState:public GameState
{
private:
	Game* game;
	Button* resumeButton;
	Button* playButton;
	Button* exitButton;
	Texture* texture;
public:
	MainMenuState(Game* game);
	~MainMenuState();
	virtual void update();
	virtual void render();
	virtual void handleEvents();
};

