// eventos.cpp

#include "eventos.h"

// -------------------------------------------------- vars
int mouse = 0;


// -------------------------------------------------- init vars eventos
void init_eventos(void)
{
	evento_posx = 0;
	evento_posy = 0;
}


// -------------------------------------------------- gestion eventos sdl2
unsigned int gestion_evento_SDL2(void)
{
	while (SDL_PollEvent(&evento) != 0)
	{
		switch (evento.type)
		{
		case SDL_MOUSEBUTTONDOWN:
			{
				if (mouse == 1)
				{
					// tpsx = evento.button.x; //*Buffer_Escala;
					// tpsy = evento.button.y; //*Buffer_Escala;
					return 1;
				}
				break;
			}

		case SDL_FINGERDOWN:
			{
				if (mouse == 0)
				{
					// tpsx = evento.tfinger.x * Video_Ancho_Ventana ;
					// tpsy = evento.tfinger.y * Video_Alto_Ventana;
					// touch=1;
					return 1;
				}
				break;
			}

		case SDL_FINGERUP:
			{
				if (mouse == 0)
				{
					// touch=0;
					// btn_puls=0;
					return 10;
				}
				break;
			}

		case SDL_KEYDOWN:
			{
				switch (evento.key.keysym.sym)
				{
				case SDLK_ESCAPE:
					{
						// app_run= 0;
						break;
					}
				case SDLK_LEFT:	// izda
					{
						break;
					}
				case SDLK_RIGHT:	// dhca
					{
						break;
					}
				case SDLK_UP:	// arriba
					{
						break;
					}
				case SDLK_DOWN:	// abajo
					{
						break;
					}
				}
				break;
				return 2;
			}
		}
	}
	return 0;
}

