#pragma once
#include "ArkanoidError.h"
class SDLError : public ArkanoidError
{
private:
public:
	SDLError(const string& m) : ArkanoidError("SDL Error: " + m) {}; // m is the message
};