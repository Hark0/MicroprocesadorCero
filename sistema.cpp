// sistema.c

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "sistema.h"

// -------------------------------------------------- local vars
colorRGB papel;
colorRGB tinta;
	

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
	fuente = TTF_OpenFont("media/zxsp.ttf", font_px);
}


// -------------------------------------------------- setup SDL2
void setup_sistema(void)
{
	papel.r = 128;
	papel.g = 0;
	papel.b = 0;

	tinta.r = 200;
	tinta.g = 200;
	tinta.b = 200;

	display = SDL_CreateRGBSurface(0, display_ancho, display_alto, 32, 0, 0, 0, 0);
	display_doblebuffer = SDL_CreateRGBSurface(0, display_ancho, display_alto, 32, 0, 0, 0, 0);

	cls(Pantalla_Ventana, papel.r, papel.g, papel.b);
	cls(display, 0, 0, 128);
	cls(display_doblebuffer, 0, 0, 0);
	
	print(display,0,0,aplicacion);
	print(display,0,8,"OK");

	if (opcion_centrado_H == 1)
	{
		display_posx = (ventana_ancho - (display_ancho * display_zoom)) / 2;
	}

	if (opcion_centrado_V == 1)
	{
		display_posy = (ventana_alto - (display_alto * display_zoom)) / 2;
	}

	if (opcion_centrado == 1)
	{
		display_posx = (ventana_ancho - (display_ancho * display_zoom)) / 2;
		display_posy = (ventana_alto - (display_alto * display_zoom)) / 2;
	}
}


// -------------------------------------------------- flip SDL2
void flip_ventana(void)
{
	orig.x = display_posx;
	orig.y = display_posy;
	orig.w = display_ancho * display_zoom;
	orig.h = display_alto * display_zoom;

	SDL_BlitScaled(display, NULL, Pantalla_Ventana, &orig);
	SDL_UpdateWindowSurface(Ventana_SDL);
}


// -------------------------------------------------- loop infinito
void loop_sistema(void)
{
	while (1)
	{
	}
}


// -------------------------------------------------- cierra SDL2
void cierra_sistema(void)
{
	SDL_FreeSurface(display);
	SDL_FreeSurface(display_doblebuffer);
	SDL_DestroyWindow(Ventana_SDL);
	SDL_Quit();
}


// -------------------------------------------------- cls SDL2
void cls(SDL_Surface * superficie, int r, int g, int b)
{
	SDL_FillRect(superficie, NULL, SDL_MapRGB(superficie->format, r, g, b));
}


// -------------------------------------------------- print surface SDL2
void print(SDL_Surface * superficie, int x, int y, char cadena[])
{
	Uint8 r = tinta.r;
	Uint8 g = tinta.g;
	Uint8 b = tinta.b;

	SDL_Color color = { r, g, b, 255 };
	SDL_Surface *surfacetexto = TTF_RenderText_Blended(fuente, cadena, color);

	dest.x = x;
	dest.y = y;
	dest.w = surfacetexto->w;
	dest.h = surfacetexto->h;

	SDL_BlitSurface(surfacetexto, NULL, superficie, &dest);
	SDL_FreeSurface(surfacetexto);
}