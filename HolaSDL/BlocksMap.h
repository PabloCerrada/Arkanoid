#pragma once
#include "Block.h"
#include "ArkanoidObject.h"
class Game;							//por que no va con PlayState
class BlocksMap : public ArkanoidObject
{
private:
	int nRows = 0, nCols = 0;
	int nBlocks = 0;
	Block*** blocks = nullptr;
	Game* game;
public:
	BlocksMap(int width, int height, Game* game);
	virtual ~BlocksMap(){};
	virtual void loadFromFile(ifstream& in);
	virtual void saveToFile(ofstream& in);
	int getNBlocks();
	virtual void render();
	bool collide(SDL_Rect& ballRect, Vector2D directionBall, Vector2D& collisionVector);
	void deleteBlocks();
};

