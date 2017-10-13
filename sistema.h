// sistema.h

// -------------------------------------------------- vars
char aplicacion[8] = { "0123456" };

struct colorRGB
{
	int r;
	int g;
	int b;
};

int ventana_ancho = 1600;
int ventana_alto = 2560;

int display_ancho = 256;
int display_alto = 192;
int display_zoom = 4;
int display_posx = 0;
int display_posy = 0;
int font_px = 8;

unsigned char opcion_centrado = 0;
unsigned char opcion_centrado_H = 1;
unsigned char opcion_centrado_V = 0;

SDL_Window *Ventana_SDL;
SDL_Surface *Pantalla_Ventana;
SDL_Surface *display;
SDL_Surface *display_doblebuffer;
SDL_Rect orig;
SDL_Rect dest;
TTF_Font *fuente;


// -------------------------------------------------- funciones
unsigned char init_sistema(void);
void setup_sistema(void);
void flip_ventana(void);
void loop_sistema(void);
void cierra_sistema(void);
void cls(SDL_Surface * superficie, int r, int g, int b);
void print(SDL_Surface * superficie, int x, int y, char cadena[]);


