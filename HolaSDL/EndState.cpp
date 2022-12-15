#include "EndState.h"
#include "Game.h"

EndState::EndState(Game* game) {
	this->game = game;
	playButton = new MenuButton(Vector2D(WIN_WIDTH / 2 - REDBUTTON_WIDTH / 2, 100), REDBUTTON_WIDTH, REDBUTTON_HEIGHT, game->getTexture(Play1), game, Game::playFunction);
	resumeButton = new MenuButton(Vector2D(WIN_WIDTH / 2 - BLUEBUTTON_WIDTH / 2, 250), BLUEBUTTON_WIDTH, BLUEBUTTON_HEIGHT, game->getTexture(Resume1), game, Game::loadFunction);
	exitButton = new MenuButton(Vector2D(WIN_WIDTH / 2 - REDBUTTON_WIDTH / 2, 400), REDBUTTON_WIDTH, REDBUTTON_HEIGHT, game->getTexture(Exit1), game, Game::exitFunction);


	//DEJAR LA LISTA OBJETOS VACIA
	objetos.clear();

	objetos.push_back(playButton);
	objetos.push_back(resumeButton);
	objetos.push_back(exitButton);
}
void EndState::render()
{
	SDL_RenderClear(game->getRenderer());
	for (auto it : objetos) {
		it->render();
	}
	SDL_RenderPresent(game->getRenderer());
}
void EndState::update()
{
	for (auto it : objetos) {
		it->update();
	}
}

void EndState::handleEvent() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) game->setExit();
		playButton->handleEvents(event);
		resumeButton->handleEvents(event);
		exitButton->handleEvents(event);
	}
}