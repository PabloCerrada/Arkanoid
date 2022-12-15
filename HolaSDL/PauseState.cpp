#include "PauseState.h"
#include "Game.h"
PauseState::PauseState(Game* game) {
	this->game = game;
	resumeButton = new MenuButton(Vector2D(WIN_WIDTH / 2 - BLUEBUTTON_WIDTH / 2, 100), BLUEBUTTON_WIDTH, BLUEBUTTON_HEIGHT, game->getTexture(Resume1), game, Game::loadFunction);
	exitButton = new MenuButton(Vector2D(WIN_WIDTH / 2 - REDBUTTON_WIDTH / 2, 300), REDBUTTON_WIDTH, REDBUTTON_HEIGHT, game->getTexture(Exit1), game, Game::exitFunction);

	//DEJAR LA LISTA OBJETOS VACIA
	objetos.clear();
	objetos.push_back(resumeButton);
	objetos.push_back(exitButton);
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

void PauseState::handleEvent() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) game->setExit();
		resumeButton->handleEvents(event);
		exitButton->handleEvents(event);
	}

}