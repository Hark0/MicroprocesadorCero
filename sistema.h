// sistema.h

// -------------------------------------------------- vars
char aplicacion[8] = { "1234567" };

struct colorRGB
{
	int r;
    int g;
	int b;
};

int ventana_ancho = 1600;
int ventana_alto = 2560;

SDL_Window *Ventana_SDL;
SDL_Surface *Pantalla_Ventana;


// -------------------------------------------------- funciones
unsigned char init_sistema(void);
void setup_sistema(void);
void flip_ventana(void);
void loop_sistema(void);
void cls(SDL_Surface *superficie, int r, int g, int b);
