#pragma once
#include "ArkanoidError.h"
class FileNotFoundError : public ArkanoidError
{
private:
public:
	FileNotFoundError(const string& m) : ArkanoidError("File not found: " + m) {}; // m is the message
};