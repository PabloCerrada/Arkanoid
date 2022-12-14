#pragma once
#include "GameState.h"
#include <stack>


class GameStateMachine
{
private:
    stack<GameState*> stackStates;              //posible error
public:
    GameStateMachine();
    GameState* currentState();
    void pushState(GameState* state);
    void changeState(GameState* state);
    void popState();
    int stackLength();
};

