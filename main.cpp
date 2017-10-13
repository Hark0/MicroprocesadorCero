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
// #include "basic_sdl2.h"
#include "sistema.cpp"


// -------------------------------------------------- namespace
using namespace std;


// -------------------------------------------------- vars


// -------------------------------------------------- main
int main(int argc, char *argv[])
{
	if (init_sistema() != 0)
	{
		setup_sistema();
		flip_ventana();
		loop_sistema();
	}
}