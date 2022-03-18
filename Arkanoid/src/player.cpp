#include "player.h"
#include <SDL/SDL.h>
#include "engine.h"
#include "game.h"

void Player::draw()
{
	SDL_SetRenderDrawColor(renderer, 25, 200, 25, 255);
	SDL_Rect rect = { posX, posY, sizeX, sizeY };
	SDL_RenderDrawRect(renderer, &rect);
}

void Player::update()
{
	if (GetKey(SDL_SCANCODE_D))
	{
		velocityX = 500;
	}

	if (GetKey(SDL_SCANCODE_A))
	{
		velocityX = -500;
	}

	if (GetKeyUp(SDL_SCANCODE_D) || GetKeyUp(SDL_SCANCODE_A))
	{
		velocityX = 0;
	}

	step(velocityX * delta_time, 0);
}

bool Player::step(float dx, float dy)
{
	if (sweep(dx, dy))
		return false;

	posX += dx;
	posY += dy;
	return true;
}

bool Player::sweep(float dx, float dy)
{
	if (posX + dx < 0 || posX + dx > screenSizeX - sizeX ||
		posY + dy < 0 || posY + dy > screenSizeY)
	{
		return true;
	}

	return false;
}