#pragma once
#include "GameState.h"
#include "Button.h"

class Game;
class PauseState :public GameState
{
private:
	Game* game;
	Button* resumeButton;
	Button* exitButton;
	Button* saveButton;
	Texture* texture;
public:

	PauseState(Game* game);
	virtual ~PauseState();
	virtual void update();
	virtual void render();
	virtual void handleEvents();
};

