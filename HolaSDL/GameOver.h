#pragma once
#include "Vector2D.h"
#include "Texture.h"
class GameOver
{
private:
	Vector2D pos; 
	unsigned int width;
	unsigned int height;
	Texture* texture = nullptr;
public:
	
	GameOver(Vector2D position, unsigned int w, unsigned int h, Texture* text) : pos(position), width(w), height(h), texture(text) {}
	void render();
	SDL_Rect getDestRect();
};

