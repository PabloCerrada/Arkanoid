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
	stackStates.push(state);
}

void GameStateMachine::popState()
{
	stackStates.pop();
}

int GameStateMachine::stackLength() {
	return stackStates.size();
}