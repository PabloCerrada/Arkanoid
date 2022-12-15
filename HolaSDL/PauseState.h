#pragma once
#include "GameState.h"
#include "MenuButton.h"

class Game;
class PauseState :public GameState
{
private:
	Game* game;
	MenuButton* resumeButton;
	MenuButton* exitButton;
public:
	PauseState(Game* game);
	virtual void update();
	virtual void render();
	virtual void handleEvent();
};

