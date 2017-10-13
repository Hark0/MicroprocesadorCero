// sistema.c

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "sistema.h"


// -------------------------------------------------- init sistema
unsigned char init_sistema(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		return 0;
	}

	Ventana_SDL = SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ventana_ancho, ventana_alto, SDL_WINDOW_SHOWN);

	if (Ventana_SDL == NULL)
	{
		return 0;
	}

	if (TTF_Init() < 0)
	{
		return 0;
	}

	Pantalla_Ventana = SDL_GetWindowSurface(Ventana_SDL);
}


// -------------------------------------------------- setup SDL2
void setup_sistema(void)
{
	colorRGB papel;
	colorRGB tinta;

	papel.r = 128;
	papel.g = 0;
	papel.b = 0;

	tinta.r = 255;
	tinta.g = 255;
	tinta.b = 255;
	
	cls(Pantalla_Ventana, papel.r, papel.g, papel.b);
}


// -------------------------------------------------- flip SDL2
void flip_ventana(void)
{
	SDL_UpdateWindowSurface(Ventana_SDL);
}


// -------------------------------------------------- loop infinito
void loop_sistema(void)
{
	while(1)
	{}
}


// -------------------------------------------------- cls SDL2
void cls(SDL_Surface *superficie, int r, int g, int b)
{
	SDL_FillRect(superficie, NULL, SDL_MapRGB(superficie->format, r, g, b));
}