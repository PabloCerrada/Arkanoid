#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "Texture.h"
#include "Vector2D.h"
#include "Paddle.h"
#include "Ball.h"
#include "Wall.h"
#include "BlocksMap.h"
#include "Reward.h"
#include "SDLError.h"
#include "FileFormatError.h"
#include "FileNotFoundError.h"
#include <math.h>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Menu.h"
using namespace std;
using uint = unsigned int;



const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint WALL_WIDTH = 21;
const uint NUM_TEXTURES = 9;

const uint NUM_LEVELS = 4;

const uint NUM_WALLS = 3;
const uint BLOCK_WIDTH = 50;
const uint BLOCK_HEIGHT = 21;
const uint PADDLE_HEIGHT = 22;
const uint NORMAL_PADDLE_WIDTH = 88;
const uint BIG_PADDLE_WIDTH = 116;
const uint SHORT_PADDLE_WIDTH = 60;
const uint BALL_RADIUS = 20;
const uint FRAME_RATE = 10;
const uint REWARD_TIME = 10;
const uint REWARD_WIDTH = 44;
const uint REWARD_HEIGHT = 23;
const uint NUM_REWARDS = 4;

enum TextureName { Ball1, Block1, GameOver1, Paddle1, SideWall1, TopWall1, Winner1, Reward1,Menu1};
enum LevelsName { Level1, Level2, Level3 };

const char RANDOM_REWARD_LETTER[NUM_REWARDS] = { 'R', 'L', 'E', 'S' };

const string LEVEL_DESCRIPT[NUM_LEVELS] = {"../maps/level01.dat","../maps/level02.dat","../maps/level03.dat", "../maps/levelS.dat" };		//preguntar si nos deja hacer así el paso de nivel

typedef struct
{
	string filename; // path to get the image
	uint hframes, vframes; // if the image is subdivided in various images this values are different than (1, 1)

}TextureDescription;


const TextureDescription TEXT_DESCRIPT[NUM_TEXTURES] =
{
	{"ball2.png",1,1},{"bricks2.png",3,2},{"gameover1.png",1,1},{"paddle2.png",1,1},{"side2.png",1,1},{"topside.png",1,1},{"youwin.png",1,1},{"rewards.png", 8, 10},{"Menu.png", 1, 1}
};
 
class Game {
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	double timerExecution, timerPaddle; // Actual execution time timer and one when the paddle takes changing-width reward
	int level = 1, life = 1, paddleWidth = NORMAL_PADDLE_WIDTH;
	bool exit = false, gameover = false, win = false, nextLevelBool = false; // control booleans
	Paddle* paddle;
	Ball* ball;
	Wall* walls[NUM_WALLS];
	BlocksMap* blocksMap;
	Menu* menu;
	string* levels[NUM_LEVELS];
	list<Reward*> rewards;
	list<ArkanoidObject*> objects;
	string dec = " ";
	Texture* textures[NUM_TEXTURES];
public:
	Game();
	~Game();
	void run();
	void render();
	void handleEvents();
	void update();
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
	void SetExit();
	Texture* getTexture(TextureName name);
	SDL_Rect getWindowRect();
};
