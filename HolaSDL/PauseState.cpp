#include "PauseState.h"
#include "Game.h"
PauseState::PauseState(Game* game) {
	this->game = game;
	resumeButton = new Button(Vector2D(WIN_WIDTH / 2 - BLUEBUTTON_WIDTH / 2, 100), BLUEBUTTON_WIDTH, BLUEBUTTON_HEIGHT, game->getTexture(Resume1), game, Game::returnToGame);
	exitButton = new Button(Vector2D(WIN_WIDTH / 2 - REDBUTTON_WIDTH / 2, 300), REDBUTTON_WIDTH, REDBUTTON_HEIGHT, game->getTexture(Exit1), game, Game::exitFunction);
	saveButton = new Button(Vector2D(WIN_WIDTH / 2 - REDBUTTON_WIDTH / 2, 500), REDBUTTON_WIDTH, REDBUTTON_HEIGHT, game->getTexture(Play1), game, Game::saveFunction);

	//DEJAR LA LISTA OBJETOS VACIA
	objetos.clear();
	objetos.push_back(resumeButton);
	objetos.push_back(exitButton);
	objetos.push_back(saveButton);
}

PauseState::~PauseState() {
	delete resumeButton;
	delete exitButton;
}
void PauseState::render()
{
	SDL_RenderClear(game->getRenderer());
	for (auto it : objetos) {
		it->render();
	}
	SDL_RenderPresent(game->getRenderer());
}
void PauseState::update()
{
	for (auto it : objetos) {
		it->update();
	}
}

void PauseState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) game->setExit();
		resumeButton->handleEvents(event);
		exitButton->handleEvents(event);
	}

}