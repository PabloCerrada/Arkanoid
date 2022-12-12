#pragma once
#include "ArkanoidObject.h"
class MovingObject : public ArkanoidObject
{
protected:
	Vector2D direction; // Direction for all the MovingObjects
	int velocity;
public:
	virtual ~MovingObject(){};
	virtual void loadFromFile(ifstream& in);
	virtual void saveToFile(ofstream& in);
	virtual void update();
	virtual void render();
	virtual void handleEvents(){};
};

