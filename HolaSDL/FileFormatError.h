#pragma once
#include "ArkanoidError.h"
class FileFormatError : public ArkanoidError
{
private:
public:
	FileFormatError(const string& m) : ArkanoidError("File format error: " + m) {}; // m is the message
};