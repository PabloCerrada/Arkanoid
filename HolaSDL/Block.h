#pragma once
#include "ArkanoidObject.h"
class Block : public ArkanoidObject
{
private:
	int color, nCols, nRows; // Columns and rows of the image
public:
	Block(Vector2D pos, int width, int height, int color, Texture* texture);
	virtual ~Block() {};
	virtual void render();
	Vector2D getPos();
	int getColor();
};

