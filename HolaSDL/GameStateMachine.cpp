#include "GameStateMachine.h"
GameState* GameStateMachine::currentState() 
{
	return stackStates.top();
}

void GameStateMachine::changeState(GameState* state)
{
	popState();
	pushState(state);
}

void GameStateMachine::pushState(GameState* state) 
{
	stackStates.push(state);				//error de stack
}

void GameStateMachine::popState()
{
	stackStates.pop();
}