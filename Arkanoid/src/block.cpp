#include "block.h"
#include <SDL/SDL.h>
#include "engine.h"

void Block::draw()
{
	switch (blockHealth)
	{
		case 3:
			SDL_SetRenderDrawColor(renderer, 252, 186, 3, 255);
			break;
		case 2:
			SDL_SetRenderDrawColor(renderer, 52, 207, 235, 255);
			break;
		case 1:
			SDL_SetRenderDrawColor(renderer, 232, 52, 235, 255);
			break;
		default:
			break;
	}

	SDL_Rect rect = { posX, posY, sizeX, sizeY };
	SDL_RenderDrawRect(renderer, &rect);
}
