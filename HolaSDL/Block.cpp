#include "Block.h"
Block::Block(Vector2D pos, int width, int height, int color, Texture* texture) {
	this->pos = pos;
	this->width = width;
	this->height = height;
	this->color = color;
	switch (color)
	{
	case 1:	nCols = 0, nRows = 0;		//blue
		break;
	case 2: nCols = 0, nRows = 1;		//yellow
		break;
	case 3: nCols = 1, nRows = 0;		//green
		break;
	case 4: nCols = 1, nRows = 1;		//black
		break;
	case 5: nCols = 2, nRows = 0;		//red
		break;
	case 6: nCols = 2, nRows = 1;		//purple
		break;
	}
	this->texture = texture;
}

void Block::render() {
	texture->renderFrame(getRect(), nRows, nCols);
}

Vector2D Block::getPos() {
	return pos;
}

int Block::getColor() {
	return color;
}
