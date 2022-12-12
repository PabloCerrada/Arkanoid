#include "ArkanoidError.h"
const char* ArkanoidError::what() {
	return logic_error::what();
}