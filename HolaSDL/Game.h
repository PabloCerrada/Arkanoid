#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "Texture.h"
#include "Vector2D.h"
#include "SDLError.h"
#include "FileFormatError.h"
#include "FileNotFoundError.h"
#include <math.h>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "GameStateMachine.h"
#include "PlayState.h"
using namespace std;
using uint = unsigned int;



const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 9;
const uint FRAME_RATE = 10;

enum TextureName { Ball1, Block1, GameOver1, Paddle1, SideWall1, TopWall1, Winner1, Reward1,Menu1};

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
	bool exit = false; // control booleans
	Texture* textures[NUM_TEXTURES];
	GameStateMachine* stateMachine;
public:
	Game();
	~Game();
	void run();
	Texture* getTexture(TextureName name);				//update handleEvent, render
	SDL_Rect getWindowRect();
	void render();
	void update();
	void handleEvent();
	SDL_Renderer* getRenderer();
	void setExit();
	//void getState()
	//{
	//	stateMachine->currentState();					//type id para pillar que tipo de estado es
	//}
	bool getExit();
};
