#include "EndState.h"
#include "Game.h"

EndState::EndState(Game* game) {
	this->game = game;
	exitButton = new Button(Vector2D(WIN_WIDTH / 2 - REDBUTTON_WIDTH / 2, 300), REDBUTTON_WIDTH, REDBUTTON_HEIGHT, game->getTexture(Exit1), game, Game::exitFunction);
	menuButton = new Button(Vector2D(WIN_WIDTH / 2 - BLUEBUTTON_WIDTH / 2, 100), BLUEBUTTON_WIDTH, BLUEBUTTON_HEIGHT, game->getTexture(Main1), game, Game::returnToMainMenu);

	texture = game->getTexture(EndMenu1);
	//DEJAR LA LISTA OBJETOS VACIA
	objetos.clear();

	objetos.push_back(menuButton);
	objetos.push_back(exitButton);
}

EndState::~EndState()
{
	delete exitButton;
	delete menuButton;
}
void EndState::render()
{
	SDL_RenderClear(game->getRenderer());
	texture->render(game->getWindowRect());
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
void EndState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT || event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) game->setExit();
		menuButton->handleEvents(event);
		exitButton->handleEvents(event);
	}
}