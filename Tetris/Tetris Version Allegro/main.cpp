#include <ctime>
#include <stdio.h>
#include <string>
#include <allegro.h>

using namespace std;

//VARIABLES PRINCIPALES DEL PROGRAMA
const int TAM = 20;
const int FILAS = 20 * TAM;
const int COLUMNAS = 10 * TAM;
typedef int Tablero[COLUMNAS][FILAS];

//ESTRUCTURAS DE LAS PIEZAS
struct Coord{
	int x, y;
};
struct Pieza{
    Coord orig;
	Coord perif[3];
	int Color;
	Coord Posicion(int n) const;
};

//DEFINICION DE LA FUNCION MIEMBRO POSICION DE LA ESTRUCTURA PIEZA
Coord Pieza::Posicion(int n)const{
    Coord ret = { orig.x, orig.y};
    if(n != 0){
        ret.x += perif[n -1].x;
        ret.y += perif[n -1].y;
    }
    return ret;
}

//ESTRUCTURAS DE LAS FUNCIONES PARA ROTAR LA PIEZA
Coord Rota_Derecha(const Coord& C){
    Coord ret = { -C.y, C.x };
	return ret;
}
Coord Rota_Izquierda(const Coord& C){
    Coord ret = { C.y, -C.x };
   	return ret;

}

const Coord Perifs[7][3] = {
    { {  0, -1 }, {  1, -1 }, {  1,  0 } }, // Pieza O
    { {  0, -1 }, { -1,  0 }, {  1,  0 } }, // Pieza T
    { { -1,  0 }, {  1, -1 }, {  0, -1 } }, // Pieza S
    { {  0, -1 }, { -1, -1 }, {  1,  0 } }, // Pieza Z
    { {  1,  0 }, { -1,  0 }, {  1, -1 } }, // Pieza L
    { {  1,  0 }, { -1,  0 }, { -1, -1 } }, // Pieza J
    { {  1,  0 }, { -1,  0 }, {  2,  0 } }, // Pieza I


};

void hola(int ho);

//PROTOTIPOS DE LAS FUNCIONES DEL PROGRAMA
void cuadrado(BITMAP *buffer, int  x, int  y, int Color);
void pieza_Pintar(BITMAP *buffer, Pieza& P);
void pieza_Rota_Derecha(Pieza& P);
void pieza_Rota_Izquierda(Pieza& P);
void tablero_Vacio(BITMAP *buffer, const Tablero& T, int Color);
void tablero_Pintar(BITMAP *buffer, const Tablero& T);
void tablero_Pieza_Incrusta(BITMAP *buffer,  Tablero& T,  Pieza& P);
bool tablero_Colision(const Tablero& T, Pieza& P, int Color);
void pieza_Nueva(Pieza& P);
bool tablero_Fila_Lleno(const Tablero& T, int Fila, int Color);
void tablero_Colapsa(BITMAP *buffer, Tablero& T,  int Fila, int Color);
int tablero_Cuenta_Linea(BITMAP *buffer, Tablero& T, int Color);
void puntaje(BITMAP *buffer, int& Score);


int main(){

    allegro_init();
    install_keyboard();
    install_timer();
    set_color_depth(32);
    set_gfx_mode(GFX_AUTODETECT_WINDOWED, FILAS , FILAS, 0, 0);
    BITMAP *buffer = create_bitmap ( FILAS, FILAS);

    srand(time(0));
    int Tick;
    int Score = 0;
    Tablero T;
    Pieza P, Sig;
    pieza_Nueva(P);
    pieza_Nueva(Sig);
    P.orig.x = 4;
    P.orig.y = 1;

while(!key[KEY_ESC]){


    clear_to_color(buffer,0x000000);
    tablero_Vacio(buffer, T, 0);
    tablero_Pintar(buffer,T);
    pieza_Pintar(buffer, P);
    pieza_Pintar(buffer, Sig);

    vline(buffer, 0, 0, 400, 0xFFFFFF);
    vline(buffer, 201, 0, 401, 0xFFFFFF);
    textout_ex(buffer, font,"SIGUIENTE PIEZA", 242, 20, 0xFBFFFF, 0x000000);
    textout_ex(buffer, font,"NIVEL", 280, 140, 0xFBFFFF, 0x000000);
    textout_ex(buffer, font,"PUNTOS", 275, 240, 0xFBFFFF, 0x000000);
    puntaje(buffer, Score);
    blit(buffer, screen, 0, 0, 0, 0, FILAS, FILAS);

    Pieza Copia = P;

    if(Tick > 8 && !tablero_Colision(T, P, 0)&& !key[KEY_DOWN]){
        P.orig.y++;
        Tick = 0;
    }



    if(key[KEY_RIGHT]){
        P.orig.x++;
    }
    if(key[KEY_LEFT]){
        P.orig.x--;
    }
    if(key[KEY_DOWN]){
        P.orig.y++;
    }
    if(key[KEY_UP]){
        if(P.Color != 5 )
        pieza_Rota_Derecha(P);
    }


    if(tablero_Colision(T, P, 0)){
        P = Copia;

        if(key[KEY_DOWN] && !key[KEY_RIGHT] && !key[KEY_LEFT] ){
        tablero_Pieza_Incrusta(buffer, T, P);
        P = Sig;
        pieza_Nueva(Sig);
        P.orig.x = 4;
        P.orig.y = 2;
        int Conta = tablero_Cuenta_Linea(buffer, T, 0);
        Score += Conta;

        }
    }


    rest(80);
    Tick++;
    pieza_Pintar(buffer, P);
    blit(buffer, screen, 0, 0, 0, 0, FILAS, FILAS);
    }



return 0;
}
END_OF_MAIN();

//DEFINICIONES DE LAS FUNCIONES DEL PROGRAMA
void cuadrado(BITMAP *buffer, int x, int y, int Color){


    if(Color == 0) //Negro //
    rectfill(buffer,2 + x * TAM,
                    2 + y * TAM,
                    x * TAM + TAM,
                    y * TAM + TAM, 0x000000);

    if(Color == 1) //Violeta //
    rectfill(buffer,2 + x * TAM,
                    2 + y * TAM,
                    x * TAM + TAM,
                    y * TAM + TAM, 0xFD00FF);

    if(Color == 2) // Rojo //
    rectfill(buffer,2 + x * TAM,
                    2 + y * TAM,
                    x * TAM + TAM,
                    y * TAM + TAM, 0xFF0016);

    if(Color == 3) // Naranja //
    rectfill(buffer,2 + x * TAM,
                    2 + y * TAM,
                    x * TAM + TAM,
                    y * TAM + TAM, 0xFF5900);

    if(Color == 4)// Azul Cielo //
    rectfill(buffer,2 + x * TAM,
                    2 + y * TAM,
                    x * TAM + TAM,
                    y * TAM + TAM, 0x00FFFF);

    if(Color == 5)// Verde
    rectfill(buffer,2 + x * TAM,
                    2 + y * TAM,
                    x * TAM + TAM,
                    y * TAM + TAM, 0x13FF00);


    if(Color == 6)// Amarillo //
    rectfill(buffer,2 + x * TAM,
                    2 + y * TAM,
                    x * TAM + TAM,
                    y * TAM + TAM, 0xFFFF00);

    if(Color == 7)// Azul //
    rectfill(buffer,2 + x * TAM,
                    2 + y * TAM,
                    x * TAM + TAM,
                    y * TAM + TAM, 0x002BFF);

}

void pieza_Pintar(BITMAP *buffer, Pieza& P){
    for(int i = 0; i < 4; i++){
        Coord c = P.Posicion(i);
        cuadrado(buffer, c.x, c.y, P.Color);
    }
}

void pieza_Rota_Derecha(Pieza& P){
	for(int i = 0; i < 3; i++){
		P.perif[i] = Rota_Derecha(P.perif[i]);
	}

}

void pieza_Rota_Izquierda(Pieza& P){
	for(int i = 0; i < 3; i++){
		P.perif[i] = Rota_Izquierda(P.perif[i]);
	}

}



void tablero_Vacio(BITMAP *buffer, const Tablero& T, int Color){
    for(int i = 0; i < COLUMNAS; i++){
        for(int j = 0; j < FILAS; j++){
            cuadrado(buffer, i, j, Color);
        }
    }

}


void tablero_Pintar(BITMAP *buffer, const Tablero& T){
    for(int i = 0; i < COLUMNAS; i++){
        for(int j = 0; j < FILAS; j++){
            cuadrado(buffer, i, j, T[i][j]);
        }
    }

}

void tablero_Pieza_Incrusta(BITMAP *buffer, Tablero& T, Pieza& P){
    for(int i = 0; i < 4; i++){
        Coord C = P.Posicion(i);
        T[C.x][C.y] = P.Color;
    }
}


bool tablero_Colision(const Tablero& T, Pieza& P, int Color){
    for(int i = 0; i < 4; i++){
        Coord C = P.Posicion(i);

        if(C.x < 0 || C.x == COLUMNAS / TAM){
            return true;
        }

        if(C.y < 0 || C.y == FILAS / TAM){
            return true;
        }

        if(T[C.x][C.y] != Color){
            return true;
        }
    }

}


void pieza_Nueva(Pieza& P){

P.orig.x = 14.7;
P.orig.y = 3;
int R;

R = rand() % 7;

switch(R){
// COLORES DE LAS PIEZAS
    case 0:
        P.Color = 5;
    break;

    case 1:
        P.Color = 3;
    break;

    case 2:
        P.Color = 1;
    break;

    case 3:
        P.Color = 2;
    break;

    case 4:
        P.Color = 4;
    break;

    case 5:
        P.Color = 7;
    break;

    case 6:
        P.Color = 6;
    break;
}

    for(int i = 0; i < 3; i++){
        P.perif[i] = Perifs[R][i];
    }

    R++;
}


bool tablero_Fila_Lleno(const Tablero& T, int Fila, int Color){
    for(int i = 0; i < 10; i++){
        if(T[i][Fila] == Color){
            return false;
        }
    }
    return true;
}


void tablero_Colapsa(BITMAP *buffer, Tablero& T, int Fila, int Color){
    //ESTAMOS COPIANDO LA FILA DE ARRIBA EN LA DEBAJO, Y ASI SUCESIVAMENTE
    for(int j = Fila; j > 0; j--){
        for(int i = 0; i < 10; i++){ // El numero 10 significa Columnas
            T[i][j] = T[i][j-1];
        }
    }

    for(int i = 0; i < 10; i++){ // El numero 10 significa Columnas
        T[i][0] = Color;
    }

}

int tablero_Cuenta_Linea(BITMAP *buffer, Tablero& T, int Color){
    int Fila = 20 - 1;
    int Score = 0;

    while(Fila >= 0){
        if(tablero_Fila_Lleno(T, Fila, Color)){
            tablero_Colapsa(buffer, T, Fila, Color);
            Score++;
        }else{
            Fila--;
        }
    }
    return Score;
}


void puntaje(BITMAP *buffer, int &Score){


if(Score == 0){
    textout_ex(buffer, font, "0", 295, 260, 0xFBFFFF, 0x000000);

}


if(Score == 1){
    textout_ex(buffer, font, "1", 295, 260, 0xFBFFFF, 0x000000);

}


if(Score == 2){
    textout_ex(buffer, font, "2", 295, 260, 0xFBFFFF, 0x000000);

}


if(Score == 3){
    textout_ex(buffer, font, "3", 295, 260, 0xFBFFFF, 0x000000);

}


if(Score == 4){
    textout_ex(buffer, font, "4", 295, 260, 0xFBFFFF, 0x000000);

}


if(Score == 5){
    textout_ex(buffer, font, "5", 295, 260, 0xFBFFFF, 0x000000);

}


if(Score == 6){
    textout_ex(buffer, font, "6", 295, 260, 0xFBFFFF, 0x000000);

}


if(Score == 7){
    textout_ex(buffer, font, "7", 295, 260, 0xFBFFFF, 0x000000);

}


if(Score == 8){
    textout_ex(buffer, font, "8", 295, 260, 0xFBFFFF, 0x000000);

}


if(Score == 9){
    textout_ex(buffer, font, "9", 295, 260, 0xFBFFFF, 0x000000);

}


if(Score == 10){
    textout_ex(buffer, font, "10", 290, 260, 0xFBFFFF, 0x000000);

}


if(Score == 1100){
    textout_ex(buffer, font, "11", 290, 260, 0xFBFFFF, 0x000000);

}

}
