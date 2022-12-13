#include "PlayState.h"

PlayState::PlayState() {
	// We finally create the game objects 
	blocksMap = new BlocksMap(WIN_WIDTH - 2 * WALL_WIDTH, (WIN_HEIGHT - 2 * WALL_WIDTH) / 2, game);

	paddle = new Paddle(NORMAL_PADDLE_WIDTH, PADDLE_HEIGHT, game->getTexture(Paddle1));

	ball = new Ball(BALL_RADIUS, Vector2D(0, -1), game->getTexture(Ball1), this);

	walls[0] = new Wall(WALL_WIDTH, WIN_HEIGHT, Vector2D(1, 0), game->getTexture(SideWall1));
	walls[1] = new Wall(WALL_WIDTH, WIN_HEIGHT, Vector2D(-1, 0), game->getTexture(SideWall1));
	walls[2] = new Wall(WIN_WIDTH, WALL_WIDTH, Vector2D(0, 1), game->getTexture(TopWall1));

	// We add all the objects to the ArkanoidObjects list
	objects.push_back(blocksMap);
	objects.push_back(walls[0]);
	objects.push_back(walls[1]);
	objects.push_back(walls[2]);
	objects.push_back(paddle);
	objects.push_back(ball);
}
PlayState::~PlayState() {
	delete paddle;
	delete ball;
	blocksMap->deleteBlocks();
	delete blocksMap;
	for (int i = 0; i < NUM_WALLS; i++) delete walls[i];
	auto e = rewards.begin();
	while (e != rewards.end())
	{
		auto c = e;
		++e;
		deleteReward(*c);
	}
}

void PlayState::run() {
	uint32_t startTime, frameTime;
	startTime = SDL_GetTicks();
	while (!exit && !gameover && !win) {
		handleEvents();
		frameTime = SDL_GetTicks() - startTime;
		if (frameTime >= FRAME_RATE) {
			update();
			startTime = SDL_GetTicks();
		}
		render();
	}
	if (!exit) {
		SDL_RenderClear(game->getRenderer());
		if (gameover) GameOver();
		else if (win) Win();
		SDL_RenderPresent(game->getRenderer());
		SDL_Delay(3000);
	}
}
void PlayState::update() {
	for (auto it : objects)
	{
		it->update();
	}
	auto e = rewards.begin();
	while (!nextLevelBool && e != rewards.end())
	{
		auto c = e;
		++e;
		(*c)->update();
	}
	nextLevelBool = false;
	if (blocksMap->getNBlocks() <= 0 && level == 3) win = true;
	else if (blocksMap->getNBlocks() <= 0 && level != 3) {
		reset();
		SDL_Delay(400);
	}

	unsigned timer = clock();
	timerExecution = (double(timer) / CLOCKS_PER_SEC);

	if (timerPaddle + REWARD_TIME < timerExecution) { // The shorterpaddle and biggerpaddle rewards is activated REWARDS_TIME seconds
		resetPaddle();
	}
}
void PlayState::render() {
	SDL_RenderClear(game->getRenderer());
	for (auto it : objects) {
		it->render();
	}
	for (auto it : rewards) {
		it->render();
	}
	SDL_RenderPresent(game->getRenderer());
}

//Function that handle the events
void PlayState::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) game->setExit();
		paddle->handleEvents(event);
		saveToFile(LEVEL_DESCRIPT[3], event);
	}
}
bool PlayState::collidesReward(SDL_Rect rewardRect) {
	// Reward - Paddle
	if (SDL_HasIntersection(&paddle->getRect(), &rewardRect)) {
		return true;
	}
	return false;
}

void PlayState::deleteReward(Reward* rewardToDelete) {
	delete (rewardToDelete);
	rewards.remove(rewardToDelete);
}
//Function that handles collisions with ball
bool PlayState::collidesBall(SDL_Rect ballRect, Vector2D& colVector) {
	// Ball - Walls
	for (int i = 0; i < NUM_WALLS; i++) {
		if (walls[i]->collides(ballRect, colVector)) return true;
	}

	// Ball - Paddle
	if (paddle->collides(ballRect, colVector)) return true;

	// Ball - Blocks and Reward spawn
	if (blocksMap->collide(ballRect, colVector, colVector)) {
		int probability = rand() % 10; // Interval [0, 10)
		if (probability == 1) {
			int randomLetter = rand() % NUM_REWARDS; // Interval [0, 4) = 4 posibilities = 4 letters = 4 rewards
			Reward* newReward = new Reward(Vector2D(ball->getRect().x - BALL_RADIUS, ball->getRect().y), REWARD_WIDTH, REWARD_HEIGHT, 1, RANDOM_REWARD_LETTER[randomLetter], Vector2D(0, 1), game->getTexture(Reward1), this);
			rewards.push_back(newReward);
		}
		return true;
	}

	// Ball - DeadLine
	if (ballRect.y >= WIN_HEIGHT) {
		if (life == 1) {
			gameover = true; // You will lose only if you have a single life
		}
		else { // Reseted position and directions of paddle and ball if you have more than one life
			ball->setPos(Vector2D(WIN_WIDTH / 2 - (BALL_RADIUS / 2), WIN_HEIGHT / 2 + 200));
			ball->setDirection(Vector2D(0, -1));
			oneLessLife();
		}
	}


	return false;
}

//Function that triggers when you lose...
void PlayState::GameOver() {
	game->getTexture(GameOver1)->render(game->getWindowRect());
}
//... and when you win
void PlayState::Win() {
	game->getTexture(Winner1)->render(game->getWindowRect());
}

void PlayState::oneMoreLife() {
	++life;
}

void PlayState::oneLessLife() {
	--life;
}

void PlayState::shorterPaddle() {
	paddle->setWidth(SHORT_PADDLE_WIDTH);
	unsigned timer = clock();
	timerPaddle = (double(timer) / CLOCKS_PER_SEC); // Start a timer when shorterPaddle reward is picked up
}

void PlayState::biggerPaddle() {
	paddle->setWidth(BIG_PADDLE_WIDTH);
	unsigned timer = clock();
	timerPaddle = (double(timer) / CLOCKS_PER_SEC); // Start a timer when biggerPaddle reward is picked up

}

void PlayState::resetPaddle() {
	paddle->setWidth(NORMAL_PADDLE_WIDTH); // Paddle back to the normal width
}

void PlayState::loadFromFile(const string& path) {
	ifstream in;
	in.open(path);
	if (!in) throw FileNotFoundError("Path unknown");
	in >> level;
	if (level < 0)
	{
		throw FileFormatError("level is " + to_string(level) + ",must be 0 or bigger");
	}
	for (auto it : objects) {
		it->loadFromFile(in);
	}
	int nRewards = 0;
	in >> nRewards;
	if (nRewards < 0) throw FileFormatError("nRewards is" + to_string(nRewards) + "must be 0 or bigger");
	for (int i = 0; i < nRewards; i++) {
		Reward* newReward = new Reward(REWARD_WIDTH, REWARD_HEIGHT, game->getTexture(Reward1), this);
		newReward->loadFromFile(in);
		rewards.push_back(newReward);

	}
	in.close();
}

void PlayState::saveToFile(const string& path, SDL_Event event) {
	if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_s) { // Press S to save
		ofstream in;
		in.open(path);
		if (!in) throw FileNotFoundError("Path unknown");
		in << level << "\n";
		cout << level;
		for (auto it : objects) {
			it->saveToFile(in);
			in << "\n";
		}
		in << rewards.size() << "\n";
		for (auto it : rewards) {
			it->saveToFile(in);
		}
		in.close();
	}
}
//This function is called everytime we pass to the next level.
//It deletes blocksmap and rewards and change atributes (everything excepts walls) of the other objects.
void PlayState::reset()
{
	if (level != 3) {
		ball->setPos(Vector2D(WIN_WIDTH / 2 - (BALL_RADIUS / 2), WIN_HEIGHT / 2 + 200));
		ball->setDirection(Vector2D(0, -1));

		blocksMap->deleteBlocks();
		objects.remove(blocksMap);

		delete blocksMap;
		blocksMap = new BlocksMap(WIN_WIDTH - 2 * WALL_WIDTH, (WIN_HEIGHT - 2 * WALL_WIDTH) / 2, game);

		ifstream in;
		in.open(LEVEL_DESCRIPT[level++]);
		in >> level;
		blocksMap->loadFromFile(in);
		in.close();
		objects.push_front(blocksMap); // Pushed front to avoid error at the lecture

		paddle->setPos(Vector2D(WIN_WIDTH / 2 - (paddleWidth / 2), WIN_HEIGHT - PADDLE_HEIGHT * 2));
		auto e = rewards.begin();
		while (e != rewards.end())
		{
			auto c = e;
			++e;
			deleteReward(*c);
		}
		nextLevelBool = true;
	}
	else {
		win = true;
	}

}
