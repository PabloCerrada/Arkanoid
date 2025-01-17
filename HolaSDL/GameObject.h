#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include "Vector2D.h"
#include "Texture.h"
#include <fstream>
class GameObject
{
private:
public:
	virtual ~GameObject() {};
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void handleEvents(SDL_Event event) = 0;
	virtual void loadFromFile(ifstream& in) {};
	virtual void saveToFile(ofstream& in) {};
};

