#include "BlocksMap.h"
#include "PlayState.h"
#include "Game.h"
#include <fstream>
BlocksMap::BlocksMap(int width, int height, Game* game) {
	this->width = width;
	this->height = height;
	this->game = game;
}

void BlocksMap::loadFromFile(ifstream& in) {
	ArkanoidObject::loadFromFile(in);
	in >> nRows >> nCols;
	if (nRows == 0 || nCols == 0) throw FileFormatError("File format is incorrect, columns either rows can not be 0");
	blocks = new Block**[nRows];
	for (int i = 0; i < nRows; i++) {
		blocks[i] = new Block*[nCols];
		for (int j = 0; j < nCols; j++) {
			int color = 0;
			in >> color;
			if (color < 0 || color > 6) throw FileFormatError("File format is incorrect, color has to be in the [0, 6] interval");
			if (color != 0) ++nBlocks;
			blocks[i][j] = new Block(Vector2D(width / nCols * j + BLOCK_WIDTH / 2, height / nRows * i + BLOCK_HEIGHT), width / nCols, height / nRows, color, game->getTexture(Block1));
		}													//OFFSET						OFFSET
	}
}

void BlocksMap::saveToFile(ofstream& in) {
	ArkanoidObject::saveToFile(in);
	in << nRows << " " << nCols << "\n";
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			if (blocks[i][j]==nullptr)
			{
				in << 0 << " ";
			}
			else
			{
				in << blocks[i][j]->getColor() << " ";
			}
			
		}
		in << "\n";
	}
}

void BlocksMap::render() {
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			if (blocks[i][j] != nullptr) {
				blocks[i][j]->render();
			}
		}
	}
}

bool BlocksMap::collide(SDL_Rect& ballRect, Vector2D directionBall, Vector2D& collisionVector) {
	SDL_Rect areaCol;
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			if (blocks[i][j] != nullptr && SDL_IntersectRect(&blocks[i][j]->getRect(), &ballRect, &areaCol) && blocks[i][j]->getColor() != 0) {
				if (areaCol.w > areaCol.h) {
					if (areaCol.y > blocks[i][j]->getPos().getY()) {
						collisionVector = Vector2D(0, 1); // DownSide
					}
					else {
						collisionVector = Vector2D(0, -1); //UpSide
					}	
				}
				else {
					if (areaCol.x > blocks[i][j]->getPos().getX()) {
						collisionVector = Vector2D(1, 0); //Rightside
					}
					else {
						collisionVector = Vector2D(-1, 0); //Leftside
					}
				}
				delete blocks[i][j];
				blocks[i][j] = nullptr;
				--nBlocks;
				return true;
			}
		}
	}
	return false;
}

void BlocksMap::deleteBlocks() {
	for (int i = 0; i < nRows; i++) {
		for (int j = 0; j < nCols; j++) {
			if (blocks[i][j] != nullptr) delete blocks[i][j];
		}
		delete blocks[i];
	}
	delete blocks;
}

int BlocksMap::getNBlocks() {
	return nBlocks;
}