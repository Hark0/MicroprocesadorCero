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


// -------------------------------------------------- namespace
using namespace std;


// -------------------------------------------------- vars


// -------------------------------------------------- main
int main(int argc, char *argv[])
{
	init_logica();

	if (init_sistema() != 0)
	{
		setup_sistema();

		while (1)
		{
			render_display(0);
			printvar(display, 16, 16, contador_loop());
			flip_ventana();
		}
		
		cierra_sistema();
	}
}
