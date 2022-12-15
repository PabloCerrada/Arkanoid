#include "MainMenuState.h"
#include "Game.h"
MainMenuState::MainMenuState(Game* game) {
	this->game = game;
	playButton = new MenuButton(Vector2D(WIN_WIDTH / 2 - BUTTON_WIDTH / 2, 200), BUTTON_WIDTH, BUTTON_HEIGHT, game->getTexture(Play1));
	resumeButton = new MenuButton(Vector2D(WIN_WIDTH / 2 - BUTTON_WIDTH / 2, 350), BUTTON_WIDTH, BUTTON_HEIGHT, game->getTexture(Resume1));
	exitButton = new MenuButton(Vector2D(WIN_WIDTH / 2 - BUTTON_WIDTH / 2, 500), BUTTON_WIDTH, BUTTON_HEIGHT, game->getTexture(Exit1));



	//DEJAR LA LISTA OBJETOS VACIA
	objetos.clear();

	objetos.push_back(playButton);
	objetos.push_back(resumeButton);
	objetos.push_back(exitButton);
}
void MainMenuState::render()
{
	SDL_RenderClear(game->getRenderer());
	for (auto it : objetos) {
		it->render();
	}
	SDL_RenderPresent(game->getRenderer());
}
void MainMenuState::update()
{
	for (auto it : objetos) {
		it->update();
	}
}

void MainMenuState::handleEvent() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) game->setExit();
		playButton->handleEvents(event);
		resumeButton->handleEvents(event);
		exitButton->handleEvents(event);
	}
}