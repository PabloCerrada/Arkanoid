#include "Game.h"
#include "Menu.h"
#include <stdio.h>
#include <iostream>

using namespace std;

using uint = unsigned int;


int main(int argc, char* argv[]){
	_CrtSetDbgFlag (_CRTDBG_ALLOC_MEM_DF| _CRTDBG_LEAK_CHECK_DF);
	try {
		Game* game = new Game();
		game->run();
		delete game;
	}  
	catch(FileFormatError error)
	{
		cout << error.what() << endl;
	}
	catch(FileNotFoundError error)
	{
		cout << error.what() << endl;
	}
	catch(SDLError error)
	{
		cout << error.what() << endl;
	}
	catch (ArkanoidError error) {
		cout << error.what() << endl;
	}
	return 0;
}