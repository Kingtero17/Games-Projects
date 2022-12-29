#include <allegro.h>
#define MAXFILAS 20 // En este caso colocaremos un espacio demas en las columnas y filas
#define MAXCOLS  31

using namespace std;

BITMAP *buffer;
BITMAP *muros;
BITMAP *pacbmp;
BITMAP *pacman;
PALLETE paleta;

int Pacx = 30*10, Pacy = 30*10;
int Dir = 0;

char Mapa[MAXFILAS][MAXCOLS] =
{
    "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX",
    "X           XXXXXX           X",
    "X XXX XXXXX XXXXXX XXXXX XXX X",
    "X XXX XXXXX XXXXXX XXXXX XXX X",
    "X                            X",
    "X XXX XX XXXXXXXXXXXX XX XXX X",
    "X     XX     XXXX     XX     X",
    "X XXX XXXXXX XXXX XXXXXX XXX X",
    "X XXX XX              XX XXX X",
    "      XX XXXXXXXXXXXX XX      ",

};


void Dibujar_mapa(){

int Row, Col;

for(Row = 0; Row < MAXFILAS; Row++){
    for(Col = 0; Col < MAXCOLS; Col++){
        if(Mapa[Row][Col] == 'X'){
           draw_sprite(buffer, muros, Col*8, Row*8);/*Aqui en las coordenadas colocamos un *(50 pixeles)
                                                      y lo multiplicaremos por la cantidad de pixeles que tiene nuestra imagen.
                                                       En caso contrario, solo se nos pintaria un pixel y no el cuadro completo*/
      }
    }
  }
}


void Pantalla(){
     blit(buffer, screen, 0, 0, 0, 0, 260, 100);
}


void Dibujar_personaje(){
     blit(pacbmp, pacman, Dir*33,0,0,0,33,33);
     draw_sprite(buffer, pacman, Pacx, Pacy);

}


int main()
{
    allegro_init();
    install_keyboard();

    set_color_depth(16);
    set_gfx_mode(GFX_AUTODETECT, 260, 100, 0, 0);/*900, 600 Nuestra tarjeta grafica no soporta los 1500 x 1000 pixeles
                                                            y por eso no abre el programa (Tambien es porque no tenemos tarjeta grafica XD)*/

    buffer = create_bitmap(260, 100);
    muros = load_bitmap("Hola.bmp", NULL);

    pacbmp = create_bitmap(33,33);
    pacman = load_bitmap("Personaje.bmp", NULL);


    while(!key[KEY_ESC]){


    // Rutina de movimiento de PACMAN
    if(key[KEY_RIGHT]) Dir = 1;
    else if(key[KEY_LEFT]) Dir = 0;
    else if(key[KEY_UP]) Dir = 3;
    else if(key[KEY_DOWN]) Dir = 2;

    if(Dir == 0) Pacx -=30;
    if(Dir == 1) Pacx +=30;
    if(Dir == 2) Pacy -=30;
    if(Dir == 0) Pacy +=30;

    clear(buffer);


    Dibujar_mapa();

    Pantalla();
    rest(150);

    }
allegro_exit();
return 0;
}
END_OF_MAIN();
