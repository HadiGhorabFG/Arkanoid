#include <SDL/SDL.h>
#include "engine.h"
#include "ball.h"
#include "game.h"
#include "circle.h"
#include "collision.h"
#include <algorithm>
#include <iostream>

bool alive = true;

void Ball::draw()
{
	SDL_SetRenderDrawColor(renderer, 168, 50, 50, 255);
	drawCircle(circle);
}

void Ball::update()
{
	if (!step(0, velocityY * delta_time))
	{
		velocityY *= -1;
	}

	if (!step(velocityX * delta_time, 0))
	{
		velocityX *= -1;
	}

	circle.posX = posX;
	circle.posY = posY;
}

bool Ball::step(float dx, float dy)
{
	if (sweep(dx, dy))
		return false;

	if (posY + dy > screenSizeY)
	{
		Ball* b = this;

		for (int i = 0; i < balls.size(); i++)
		{
			if (balls[i] == *b)
			{
				alive = false;
				return false;
			}
		}
	}

	posX += dx;
	posY += dy;
	return true;
}

bool Ball::sweep(float dx, float dy)
{
	if (posX + dx < 0 || posX + dx > screenSizeX ||
		posY + dy < 0)
	{
		return true;
	}

	AABB playerAABB{ player.posX, player.posX + player.sizeX, player.posY, player.posY + player.sizeY };
	Circle c{ posX + dx, posY + dy, circle.radius };

	if (AABBCircleIntersect(playerAABB, c))
		return true;

	for (size_t x = 0; x < MAP_ROWS; x++)
	{
		for (size_t y = 0; y < MAP_COLLUMS; y++)
		{
			if (blocks[y * MAP_COLLUMS + x] != nullptr)
			{
				Block* b = blocks[y * MAP_COLLUMS + x];
				AABB blockAABB{ b->posX, b->posX + b->sizeX, b->posY, b->posY + b->sizeY };

				if (AABBCircleIntersect(blockAABB, c) && b->blockHealth > 1)
				{
					b->blockHealth--;
					return true;
				}
				else if(AABBCircleIntersect(blockAABB, c) && b->blockHealth == 1)
				{
					score += scorePerBlock;

					if (balls.size() < 3)
					{
						Ball b;
						b.posX = player.posX + (player.sizeX / 2);
						b.posY = player.posY - b.circle.radius;
						balls.push_back(b);
					}

					blocks[y * MAP_COLLUMS + x] = nullptr;
					return true;
				}
			}
		}
	}

	return false;
}

bool Ball::operator==(const Ball& other)
{
	return &other == this;
}
