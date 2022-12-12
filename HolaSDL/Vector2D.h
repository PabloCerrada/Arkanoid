#pragma once
#ifndef VECTOR2D_H_
#define VECTOR2D_H_
#include <iostream>
#include "SDLError.h"
#include "FileFormatError.h"
#include "FileNotFoundError.h"
class Vector2D {
private:
	double x, y;
public:
	Vector2D();
	Vector2D(double x, double y);
	double getX() const;
	double getY() const;
	void normalize();
	Vector2D operator+(const Vector2D& v) const;
	Vector2D operator-(const Vector2D& v) const;
	Vector2D operator*(double d) const;
	double operator*(const Vector2D& d) const;
	friend std::ostream& operator<<(std::ostream& os, const Vector2D& v);
	
};
#endif // También lo escriben los IDEs (va con el #ifndef de arriba)

