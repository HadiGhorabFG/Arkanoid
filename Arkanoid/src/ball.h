#pragma once
#include "circle.h"

struct Ball
{
	Circle circle {0, 0, 7};

	int velocityX = 200;
	int velocityY = -200;
	int posX = 640;
	int posY = 500;
	int size = 64;

	void draw();
	void update();

	bool alive;

	bool step(float dx, float dy);
	bool sweep(float dx, float dy);

	bool operator==(const Ball& other);
};
