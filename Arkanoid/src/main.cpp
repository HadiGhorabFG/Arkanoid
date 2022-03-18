#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "engine.h"
#include "player.h"
#include "block.h"
#include "game.h"
#include "ball.h"
#include <iostream>
#include <string>

int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenSizeX, screenSizeY, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	TTF_Font* font = TTF_OpenFont("res/roboto.ttf", 20);

	LoadMap();

	bool running = true;
	Uint64 previous_ticks = SDL_GetPerformanceCounter();

	while (running)
	{
		Uint64 ticks = SDL_GetPerformanceCounter();
		Uint64 delta_ticks = ticks - previous_ticks;
		previous_ticks = ticks;
		delta_time = (float)delta_ticks / SDL_GetPerformanceFrequency();

		frameNumber++;

		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
				case SDL_QUIT:
					running = false;
					break;

				case SDL_KEYDOWN:
				{
					int scancode = event.key.keysym.scancode;
					if (scancode == SDL_SCANCODE_ESCAPE)
						running = false;
					
					keys[scancode].state = true;
					keys[scancode].changeFrame = frameNumber;
					break;
				}

				case SDL_KEYUP:
				{
					int scancode = event.key.keysym.scancode;
					keys[scancode].state = false;
					keys[scancode].changeFrame = frameNumber;
					break;
				}

				default:
					break;
			}
		}

		SDL_SetRenderDrawColor(renderer, 25, 25, 40, 255);
		SDL_RenderClear(renderer);

		player.update();
		player.draw();

		for (size_t i = 0; i < balls.size(); i++)
		{
			if (!balls[i].alive)
				continue;

			balls[i].update();
			balls[i].draw();
		}

		for (size_t x = 0; x < MAP_ROWS; x++)
		{
			for (size_t y = 0; y < MAP_COLLUMS; y++)
			{
				Block* b = blocks[y * MAP_COLLUMS + x];	
				
				if(b != nullptr)
					b->draw();
			}
		}

		string scoreString = "Score: " + to_string(score);
		const char* scoreText = scoreString.c_str();

		SDL_Color textColor = { 255, 255, 255, 255 };

		RenderText(font, scoreText, textColor, 20, 20);

		SDL_RenderPresent(renderer);

		SDL_Delay(16);
	}
}