#include "Mouse.h"
Vector2D Mouse::getMousePosition() {
	SDL_GetMouseState(&x, &y);
	pos = Vector2D(x, y);
	return pos;
}