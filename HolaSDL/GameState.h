#pragma once
#include <list>
#include "GameObject.h"
using namespace std;
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

