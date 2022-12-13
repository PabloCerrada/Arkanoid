#pragma once
#include "GameState.h"
#include <stack>


class GameStateMachine
{
private:
    stack<GameState*> stackStates;              //posible error
public:
    GameState* currentState();
    void pushState(GameState* state);
    void changeState();
    void popState();
};

