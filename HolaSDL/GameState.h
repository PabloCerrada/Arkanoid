#pragma once
#include <list>
#include "GameObject.h"
using namespace std;

const uint REDBUTTON_WIDTH = 400;
const uint REDBUTTON_HEIGHT = 100;
const uint BLUEBUTTON_WIDTH = 200;
const uint BLUEBUTTON_HEIGHT = 80;

class GameState
{
protected:
    list<GameObject*> objetos;
public:
   virtual ~GameState() {};
   virtual void render()=0;
   virtual void update()=0;
   virtual void handleEvents()=0;
};

