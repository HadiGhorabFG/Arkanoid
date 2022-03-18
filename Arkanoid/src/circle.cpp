#include "circle.h"
#include <SDL/SDL.h>
#include "engine.h"
#define TAU 6.283

void drawCircle(const Circle& c)
{
	int resolution = 48;

	for (size_t i = 0; i < resolution; i++)
	{
		float step = TAU / resolution;
		float angle = (step * i);

		float x1 = cos(angle);
		float y1 = sin(angle);
		
		float nextAngle = (step * (i + 1));

		float x2 = cos(nextAngle);
		float y2 = sin(nextAngle);

		SDL_RenderDrawLine(
			renderer, 
			x1 * c.radius + c.posX, 
			y1 * c.radius + c.posY, 
			x2 * c.radius + c.posX, 
			y2 * c.radius + c.posY);
	}
}
