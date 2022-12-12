#pragma once
#include "MovingObject.h"
class Game;
class Reward : public MovingObject
{
private:
	int nCols, nRows, cont = 0;
	char letra;
	Game* game;
public:
	Reward(int width, int height, Texture* texture, Game* game);
	Reward(Vector2D pos, int width, int height, int velocity, char letra, Vector2D direction, Texture* texture, Game* game);
	virtual ~Reward() {};
	virtual void loadFromFile(ifstream& in);
	virtual void saveToFile(ofstream& in);
	virtual void render();
	void update();
};

