#pragma once
#include "GameState.h"
#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"
#include "BlocksMap.h"
#include "Reward.h"
#include "Game.h"

const uint WALL_WIDTH = 21;
const uint NUM_LEVELS = 4;
const uint NUM_WALLS = 3;
const uint BLOCK_WIDTH = 50;
const uint BLOCK_HEIGHT = 21;
const uint PADDLE_HEIGHT = 22;
const uint NORMAL_PADDLE_WIDTH = 88;
const uint BIG_PADDLE_WIDTH = 116;
const uint SHORT_PADDLE_WIDTH = 60;
const uint BALL_RADIUS = 20;
const uint REWARD_TIME = 10;
const uint REWARD_WIDTH = 44;
const uint REWARD_HEIGHT = 23;
const uint NUM_REWARDS = 4;

enum LevelsName { Level1, Level2, Level3 };

const char RANDOM_REWARD_LETTER[NUM_REWARDS] = { 'R', 'L', 'E', 'S' };

const string LEVEL_DESCRIPT[NUM_LEVELS] = { "../maps/level01.dat","../maps/level02.dat","../maps/level03.dat", "../maps/levelS.dat" };

class PlayState : public GameState 
{
private:
	double timerExecution, timerPaddle; // Actual execution time timer and one when the paddle takes changing-width reward
	int level = 1, life = 1, paddleWidth = NORMAL_PADDLE_WIDTH;
	bool gameover = false, win = false, nextLevelBool = false; // control booleans
	Game* game;
	Paddle* paddle;
	Ball* ball;
	Wall* walls[NUM_WALLS];
	BlocksMap* blocksMap;
	string* levels[NUM_LEVELS];
	list<Reward*> rewards;
	list<ArkanoidObject*> objects;
public:
	PlayState(Game* game1);
	~PlayState();
	virtual void run();
	virtual void render();
	virtual void handleEvents();
	virtual void update();
	bool collidesBall(SDL_Rect ballRect, Vector2D& colVector);
	bool collidesReward(SDL_Rect rewardRect);
	void GameOver();
	void Win();
	void oneMoreLife();
	void oneLessLife();
	void shorterPaddle();
	void biggerPaddle();
	void resetPaddle();
	void reset();
	void loadFromFile(const string& path);
	void saveToFile(const string& path, SDL_Event event);
	void deleteReward(Reward* rewardToDelete);
};

