#include "Reward.h"
#include "PlayState.h"
#include "Game.h"
// Constructor used when rewards are created destroying a block
Reward::Reward(Vector2D pos, int width, int height, int velocity, char letra, Vector2D direction, Texture* texture, PlayState* playState)
{
	this->pos = pos;
	this->width = width;
	this->height = height;
	this->velocity = velocity;
	this->direction = direction;
	this->texture = texture;
	this->playState = playState;
	this->letra = letra;

	switch (letra)
	{
	case 'L': nCols = 0, nRows = 0; 	//L
		break;
	case 'E': nCols = 0, nRows = 1;		//E
		break;
	case 'C': nCols = 0, nRows = 2;		//C
		break;
	case 'S': nCols = 0, nRows = 3;		//S
		break;
	case 'R': nCols = 0, nRows = 4;		//R
		break;
	case 'M': nCols = 0, nRows = 5;		//M
		break;
	}
}

// Constructor used when rewards are read from file
Reward::Reward(int width, int height, Texture* texture, PlayState* playState) {
	this->width = width;
	this->height = height;
	this->texture = texture;
	this->playState = playState;
}

void Reward::render() {
	texture->renderFrame(getRect(),nRows,nCols);
}

void Reward::loadFromFile(ifstream& in) {
	MovingObject::loadFromFile(in);
	in >> letra;
	if (letra != 'L' && letra != 'E' && letra != 'S' && letra != 'R') FileFormatError("Letter " + to_string(letra) + " is not valid");
	switch (letra)
	{
	case 'L': nCols = 0, nRows = 0; 	//L
		break;
	case 'E': nCols = 0, nRows = 1;		//E
		break;
	case 'C': nCols = 0, nRows = 2;		//C
		break;
	case 'S': nCols = 0, nRows = 3;		//S
		break;
	case 'R': nCols = 0, nRows = 4;		//R
		break;
	case 'M': nCols = 0, nRows = 5;		//M
		break;
	}
}

void Reward::saveToFile(ofstream& in) {
	MovingObject::saveToFile(in);
	in << letra << "\n";
}

void Reward::update() {
	++cont; // Animation
	if (nCols == 7 && cont % 2 == 0) {
		nCols = 0;
	}
	else if (cont % 2 == 0) {
		++nCols;
	}
	direction.normalize();
	pos = pos + direction * velocity;

	// We only delete the reward if nextLevel reward is not taken, because it is deleted in the reset method of Game.cpp
	if (playState->collidesReward(getRect())) {
		switch (letra) {
		case 'L': playState->reset();
			break;
		case 'E': 
			playState->biggerPaddle();
			playState->deleteReward(this);
			break;
		case 'S': 
			playState->shorterPaddle();
			playState->deleteReward(this);
			break;
		case 'R': 
			playState->oneMoreLife();
			playState->deleteReward(this);
			break;
		}
		
	}
	if (pos.getY() > WIN_HEIGHT + height) { // Deleting reward when you do not take it
		playState->deleteReward(this);
	}
}

