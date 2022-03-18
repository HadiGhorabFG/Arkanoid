#pragma once

struct Player
{
	int velocityX;
	int velocityY;
	int posX = 600;
	int posY = 600;
	int sizeX = 80;
	int sizeY = 20;

	void draw();
	void update();

	bool step(float dx, float dy);
	bool sweep(float dx, float dy);
};
