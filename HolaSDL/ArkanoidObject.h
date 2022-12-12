#pragma once
#include "GameObject.h"
class ArkanoidObject : public GameObject
{
protected:
	Vector2D pos; // Absolute position for all the objects
	int width, height; // Width and height for all the objects
	Texture* texture; // Texture for all the objects
public:
	virtual ~ArkanoidObject() {};
	virtual SDL_Rect getRect(); // Comun method to get the rectangle for all the objects
	virtual void loadFromFile(ifstream& in);
	virtual void saveToFile(ofstream& in);
	virtual void update() {};
	virtual void render();
	virtual void handleEvents() {};
};

