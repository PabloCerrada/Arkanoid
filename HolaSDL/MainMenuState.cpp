#include "MainMenuState.h"
#include "Game.h"
MainMenuState::MainMenuState(Game* game) {
	this->game = game;
	playButton = new Button(Vector2D(WIN_WIDTH / 2 - REDBUTTON_WIDTH / 2, 150), REDBUTTON_WIDTH, REDBUTTON_HEIGHT, game->getTexture(Play1), game, Game::playFunction);
	resumeButton = new Button(Vector2D(WIN_WIDTH / 2 - BLUEBUTTON_WIDTH / 2, 300), BLUEBUTTON_WIDTH, BLUEBUTTON_HEIGHT, game->getTexture(Resume1), game, Game::loadFunction);
	exitButton = new Button(Vector2D(WIN_WIDTH / 2 - REDBUTTON_WIDTH / 2, 450), REDBUTTON_WIDTH, REDBUTTON_HEIGHT, game->getTexture(Exit1), game, Game::exitFunction);

	texture = game->getTexture(MainMenu1);




	//DEJAR LA LISTA OBJETOS VACIA
	objetos.clear();

	objetos.push_back(playButton);
	objetos.push_back(resumeButton);
	objetos.push_back(exitButton);
}
MainMenuState::~MainMenuState()
{
	delete playButton;
	delete resumeButton;
	delete exitButton;
}
void MainMenuState::render()
{
	SDL_RenderClear(game->getRenderer());
	texture->render(game->getWindowRect());
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

void MainMenuState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT  || event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE) game->setExit();
		
		resumeButton->handleEvents(event);
		exitButton->handleEvents(event);
		playButton->handleEvents(event);
	}
}