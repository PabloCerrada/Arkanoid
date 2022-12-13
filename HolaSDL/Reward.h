#pragma once
#include "MovingObject.h"
class PlayState;
class Reward : public MovingObject
{
private:
	int nCols, nRows, cont = 0;
	char letra;
	PlayState* playState;
public:
	Reward(int width, int height, Texture* texture, PlayState* playState);
	Reward(Vector2D pos, int width, int height, int velocity, char letra, Vector2D direction, Texture* texture, PlayState* playState);
	virtual ~Reward() {};
	virtual void loadFromFile(ifstream& in);
	virtual void saveToFile(ofstream& in);
	virtual void render();
	void update();
};

