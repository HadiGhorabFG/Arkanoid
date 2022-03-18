#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;

struct KeyStates
{
	bool state = false;
	int changeFrame = 0;
};

bool GetKey(SDL_Scancode key);
bool GetKeyDown(SDL_Scancode key);
bool GetKeyUp(SDL_Scancode key);

extern int frameNumber;

extern KeyStates keys[SDL_NUM_SCANCODES];

extern float delta_time;

float clamp(float a, float min, float max);

void RenderText(TTF_Font* font, const char* text, SDL_Color& color, int posX, int posY);