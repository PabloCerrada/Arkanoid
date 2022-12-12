#include "ArkanoidObject.h"
#include "Game.h"
SDL_Rect ArkanoidObject::getRect() {
	SDL_Rect destRect;
	destRect.x = pos.getX();
	destRect.y = pos.getY();
	destRect.h = height;
	destRect.w = width;
	return destRect;
}

void ArkanoidObject::loadFromFile(ifstream& in) {
	// We read the position, a comun value for all the objects
	double posX, posY;
	in >> posX >> posY;
	if (posX> WIN_WIDTH)
	{
		throw FileFormatError("The position: X = " + to_string(posX) + " is located outside the screen");
	}
	else if( posY > WIN_HEIGHT)
	{
		throw FileFormatError("The position: Y = " + to_string(posY) + " is located outside the screen");
	}
	pos = { posX, posY };
}

void ArkanoidObject::saveToFile(ofstream& in) {
	// We save the position, a comun value for all the objects
	in << pos.getX() << " " << pos.getY() << "\n";
}

void ArkanoidObject::render()
{
	texture->render(getRect());
}