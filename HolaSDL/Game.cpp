#include "Game.h"

Game::Game() {
	// We first initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("ARKANOID", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) 
	{
		if (SDL_GetError())
		{
			throw SDLError("SDL was not initialized correctly ");
		}
	}
	// We now create the textures
	for (uint i = 0; i < NUM_TEXTURES; i++) {
		const TextureDescription &desc = TEXT_DESCRIPT[i];
		textures[i] = new Texture(renderer, "../images/"+ desc.filename, desc.vframes, desc.hframes);
	}
	stateMachine = new GameStateMachine();
	cout << stateMachine->stackLength();
	stateMachine->pushState(new MainMenuState(this));
	//stateMachine->pushState(new PlayState(this));
}
Game::~Game() {
	for (uint i = 0; i < NUM_TEXTURES; i++) delete textures[i];
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run() {
	uint32_t startTime, frameTime;
	startTime = SDL_GetTicks();
	while (!exit) {
		handleEvent();
		frameTime = SDL_GetTicks() - startTime;
		if (frameTime >= FRAME_RATE) {
			update();
			startTime = SDL_GetTicks();
		}
		render();
	}
	if (!exit) {
		/*SDL_RenderClear(renderer);
		if (gameover) GameOver();
		else if (win) Win();
		SDL_RenderPresent(renderer);
		SDL_Delay(3000);*/
	}
}
void Game::render()
{
	stateMachine->currentState()->render();
}
void Game::update()
{
	stateMachine->currentState()->update();
}
void Game::handleEvent()
{
	stateMachine->currentState()->handleEvent();
}
//We use this function to avoid breaking the privacy between classes ;)
Texture* Game::getTexture(TextureName name) {
	return textures[name];
}

//Function to get the windows sizes
SDL_Rect Game::getWindowRect() {
	SDL_Rect destRect;
	destRect.h = WIN_HEIGHT;
	destRect.w = WIN_WIDTH;
	destRect.x = 0;
	destRect.y = 0;
	return destRect;
}

SDL_Renderer* Game::getRenderer() {
	return renderer;
}

bool Game::getExit() {
	return exit;
}

void Game::setExit() {
	exit = !exit;
}
