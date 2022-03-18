#pragma once

struct Block
{
	int blockHealth = 3;
	int posX;
	int posY;
	int sizeX = 80;
	int sizeY = 32;

	void draw();
};