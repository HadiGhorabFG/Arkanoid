#include "engine.h"

SDL_Window* window;
SDL_Renderer* renderer;

KeyStates keys[SDL_NUM_SCANCODES];

float delta_time = 0.f;
int frameNumber = 0;

bool GetKey(SDL_Scancode key)
{
	return keys[key].state;
}

bool GetKeyDown(SDL_Scancode key)
{
	return keys[key].state && keys[key].changeFrame == frameNumber;
}

bool GetKeyUp(SDL_Scancode key)
{
	return !keys[key].state && keys[key].changeFrame == frameNumber;
}

void RenderText(TTF_Font* font, const char* text, SDL_Color& color, int posX, int posY)
{
	SDL_Surface* text_surf = TTF_RenderText_Solid(font, text, color);
	SDL_Texture* text_texture = SDL_CreateTextureFromSurface(renderer, text_surf);

	SDL_Rect textRect = { posX, posY, text_surf->w, text_surf->h };
	SDL_RenderCopy(renderer, text_texture, NULL, &textRect);

	SDL_FreeSurface(text_surf);
	SDL_DestroyTexture(text_texture);

}

float clamp(float a, float min, float max)
{
	if (a < min)
		return min;
	if (a > max)
		return max;

	return a;
}