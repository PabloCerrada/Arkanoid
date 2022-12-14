#pragma once
#include <list>
#include "GameObject.h"
using namespace std;

const uint BUTTON_WIDTH = 400;
const uint BUTTON_HEIGHT = 100;

class GameState
{
protected:
    list<GameObject*> objetos;
public:
   virtual ~GameState() {};
   virtual void render()=0;
   virtual void update()=0;
   virtual void handleEvent()=0;
};

