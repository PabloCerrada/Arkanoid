#include "MovingObject.h"
void MovingObject::loadFromFile(ifstream& in) {
	ArkanoidObject::loadFromFile(in);
	double directionX, directionY;
	in >> directionX >> directionY;
	direction = { directionX, directionY };
	in >> velocity;
}

void MovingObject::saveToFile(ofstream& in) {
	ArkanoidObject::saveToFile(in);
	in << direction.getX() << " " << direction.getY() << "\n";
	in << velocity << "\n";
}

void MovingObject::render()
{
	texture->render(getRect());
}

void MovingObject::update()
{
	direction.normalize();
	pos = pos + direction * velocity;
}
