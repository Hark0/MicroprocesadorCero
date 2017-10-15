// sistema.c

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

#include "sistema.h"

// -------------------------------------------------- local vars
colorRGB papel;
colorRGB tinta;
colorRGB fondo_display;
colorRGB tinta_display;

unsigned char contador_frames;


// -------------------------------------------------- init sistema SDL2
unsigned char init_sistema(void)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		return 0;
	}

	Ventana_SDL =
		SDL_CreateWindow("SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, ventana_ancho,
						 ventana_alto, SDL_WINDOW_SHOWN);

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
	contador_frames = 0;
		
	papel.r = 96;
	papel.g = 0;
	papel.b = 0;

	tinta.r = 255;
	tinta.g = 255;
	tinta.b = 255;

	fondo_display.r = 32;
	fondo_display.g = 32;
	fondo_display.b = 32;
	
	tinta_display.r = 200;
	tinta_display.g = 200;
	tinta_display.b = 200;

	display = SDL_CreateRGBSurface(0, display_ancho, display_alto, 32, 0, 0, 0, 0);
	display_doblebuffer = SDL_CreateRGBSurface(0, display_ancho, display_alto, 32, 0, 0, 0, 0);

	test_tile = IMG_Load("media/test_tile_8x8.png");
	sprites_heroe = IMG_Load("media/Spritesheet_001.png");
	sprites_boton = IMG_Load("media/boton_sombra_16x20.png");

	SDL_SetColorKey(test_tile, SDL_TRUE, SDL_MapRGB(test_tile->format, 255, 0, 255));
	SDL_SetColorKey(sprites_heroe, SDL_TRUE, SDL_MapRGB(sprites_heroe->format, 255, 0, 255));
	SDL_SetColorKey(sprites_boton, SDL_TRUE, SDL_MapRGB(sprites_boton->format, 255, 0, 255));

	cls(Pantalla_Ventana, papel.r, papel.g, papel.b);
	cls(display, fondo_display.r, fondo_display.g, fondo_display.b);
	cls(display_doblebuffer, 0, 0, 0);

//	display_zoom = ventana_ancho / display_ancho;

	if (opcion_centrado_H == 1)
	{
		display_posx = (ventana_ancho - (display_ancho * display_zoom)) / 2;
		display_posy = display_posx;
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

	cls(display_doblebuffer, 0, 0, 0);
	cls(Pantalla_Ventana, papel.r, papel.g, papel.b);
	
	SDL_BlitSurface(display, NULL, display_doblebuffer, NULL);
	SDL_BlitScaled(display_doblebuffer, NULL, Pantalla_Ventana, &orig);

	dibuja_sprite(sprites_boton, Pantalla_Ventana, 0, 0, 16, 20, display_zoom * 2, 80, 1480);

	// scanline(Pantalla_Ventana, 1);
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
	SDL_FreeSurface(sprites_heroe);
	SDL_FreeSurface(test_tile);
	SDL_FreeSurface(display);
	SDL_FreeSurface(display_doblebuffer);
	SDL_FreeSurface(Pantalla_Ventana);
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
	Uint8 r = tinta_display.r;
	Uint8 g = tinta_display.g;
	Uint8 b = tinta_display.b;

	SDL_Color color = { r, g, b, 255 };
	SDL_Surface *surfacetexto = TTF_RenderText_Blended(fuente, cadena, color);

	dest.x = x;
	dest.y = y;
	dest.w = surfacetexto->w;
	dest.h = surfacetexto->h;

	SDL_BlitSurface(surfacetexto, NULL, superficie, &dest);
	SDL_FreeSurface(surfacetexto);
}


// -------------------------------------------------- print var surface SDL2
void printvar(SDL_Surface * superficie, int x, int y, int var)
{
	char valor[16];
	sprintf(valor, "%d", var);
	print(superficie, x, y, valor);
}


// -------------------------------------------------- pixel surface SDL2
void pixel(SDL_Surface * superficie, int x, int y, int color)
{
	Uint32 *pixels = (Uint32 *) superficie->pixels;

	if (color == 3)
	{
		pixels[(y * superficie->w) + x] = 0xFF00FFFF;	// ARGB
	}

	if (color == 2)
	{
		pixels[(y * superficie->w) + x] = 0xFFFF0000;	// ARGB
	}

	if (color == 1)
	{
		pixels[(y * superficie->w) + x] = 0xFFFFFFFF;	// ARGB
	}

	if (color == 0)
	{
		pixels[(y * superficie->w) + x] = 0xFF000000;	// ARGB
	}
}


// -------------------------------------------------- scanline surface SDL2
void scanline(SDL_Surface * superficie, int color)
{
	int x_scan;
	int x_scan_max = superficie->w;
	int y_scan;
	int y_scan_max = superficie->h;

	for (y_scan = 0; y_scan < y_scan_max; y_scan = y_scan + 6)
	{
		for (x_scan = 0; x_scan < x_scan_max; x_scan++)
		{
			pixel(superficie, x_scan, y_scan, color);
		}
	}
}


// -------------------------------------------------- render sprite
void dibuja_sprite(SDL_Surface * spfc_origen, SDL_Surface * spfc_destino, int idx, int idy, int tilex, int tiley, int zoom, int x, int y)
{
	orig.x = tilex * idx;
	orig.y = tiley * idy;
	orig.w = tilex;
	orig.h = tiley;
	
	dest.x = x;
	dest.y = y;
	dest.w = tilex * zoom;
	dest.h = tiley * zoom;
	
	
	SDL_BlitScaled(spfc_origen, &orig, spfc_destino, &dest);
}


// -------------------------------------------------- render display
void render_display(unsigned char id_display)
{
	cls(display, fondo_display.r, fondo_display.g, fondo_display.b);

	if (id_display == 0)
	{
		print(display, 0, 0, aplicacion);
		print(display, 0, 8, "OK");
		pixel(display, (display_ancho / 2) - 1, (display_alto / 2) - 1, 1);

		dest.x = 32;
		dest.y = 32;
		SDL_BlitSurface(test_tile, NULL, display, &dest);
		
		dest.x = 8;
		dest.y = 80;
		SDL_BlitSurface(sprites_heroe, NULL, display, &dest);

		contador_frames++;
		if (contador_frames == 7)
		{
			contador_frames = 0;
		}

		orig.x = contador_frames * 8;
		orig.y = 0;
		orig.w = 8;
		orig.h = 8;

		dest.x = 128;
		SDL_BlitSurface(test_tile, &orig, display, &dest);
		}
}