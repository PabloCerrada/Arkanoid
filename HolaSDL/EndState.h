#pragma once
#include "GameState.h"
#include "MenuButton.h"
class Game;
class EndState : public GameState
{
private:
	Game* game;
	MenuButton* resumeButton;
	MenuButton* playButton;
	MenuButton* exitButton;
public:
	EndState(Game* game);
	virtual void update();
	virtual void render();
	virtual void handleEvent();
	
};

