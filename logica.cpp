// logica.c

#include "logica.h"


// -------------------------------------------------- init vars
void init_logica(void)
{
	contador = 0;
}


// -------------------------------------------------- contador loop
unsigned char contador_loop(void)
{
	contador++;
	if (contador == 256)
	{
		contador =0;
	}
	return contador;
}