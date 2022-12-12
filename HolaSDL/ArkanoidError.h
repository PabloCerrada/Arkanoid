#pragma once
#include <stdexcept>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <exception>
using namespace std;
class ArkanoidError : public logic_error {
public:
	ArkanoidError(const string& m) : logic_error(m) {}; // m is the message
	virtual const char* what();
};