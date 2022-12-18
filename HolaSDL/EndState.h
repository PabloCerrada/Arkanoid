#pragma once
#include "GameState.h"
#include "Button.h"
class Game;
class EndState : public GameState
{
private:
	Game* game;
	Button* menuButton;
	Button* exitButton;
	Texture* texture;
public:
	EndState(Game* game);
	virtual ~EndState();
	virtual void update();
	virtual void render();
	virtual void handleEvents();
	
};

