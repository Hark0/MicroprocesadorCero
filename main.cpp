// MAIN interface 13/10/2017 // HRK //

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <math.h>
#include <time.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>


// -------------------------------------------------- include
#include "logica.cpp"
#include "sistema.cpp"
#include "eventos.cpp"


// -------------------------------------------------- namespace
using namespace std;


// -------------------------------------------------- vars
unsigned int estado_maquina;
unsigned int t_evento;


// -------------------------------------------------- main
int main(int argc, char *argv[])
{
	// ----------------------------------------------- init vars
	estado_maquina = 1;
	init_logica();
	init_eventos();

	// ----------------------------------------------- init sdl2
	if (init_sistema() != 0)
	{
		setup_sistema();

		// ------------------------------------------- main loop
		while (estado_maquina)
		{
			render_display(0);
			printvar(display, 16, 16, contador_loop());

			t_evento = gestion_evento_SDL2();
			printvar(display, 116, 16, t_evento);

			if (t_evento == 10)
			{
				estado_maquina = 0;
			}

			flip_ventana();
		}

		// ------------------------------------------- cierra sdl2
		cierra_sistema();
	}

	return 0;
}
