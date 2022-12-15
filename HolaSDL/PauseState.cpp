#include "PauseState.h"
#include "Game.h"
PauseState::PauseState(Game* game) {
	this->game = game;
	resumeButton = new MenuButton(Vector2D(WIN_WIDTH / 2 - BUTTON_WIDTH / 2, 100), BUTTON_WIDTH, BUTTON_HEIGHT, game->getTexture(Resume1));
	exitButton = new MenuButton(Vector2D(WIN_WIDTH / 2 - BUTTON_WIDTH / 2, 300), BUTTON_WIDTH, BUTTON_HEIGHT, game->getTexture(Exit1));


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