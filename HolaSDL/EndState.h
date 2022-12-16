#pragma once
#include "GameState.h"
#include "MenuButton.h"
class Game;
class EndState : public GameState
{
private:
	Game* game;
	MenuButton* menuButton;
	MenuButton* exitButton;
public:
	EndState(Game* game);
	virtual ~EndState();
	virtual void update();
	virtual void render();
	virtual void handleEvents();
	
};

