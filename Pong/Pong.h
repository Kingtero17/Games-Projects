#include "Interfaz.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define ESC 27

//Encabezado de la clase Jugador.
class Jugador{
    private:
        int x, y;

    public:
        Jugador(int _x, int _y);

        void Pintar() const;
        void Borrar() const;

        void Y(int _y){
            y += _y;
        };
        
        int RY(){
            return y;
        };

        int RX(){
            return x;
        };

        void Mover_Cpu(int _x, int _y, int _dx);
};


//Encabezado de la clase Pelota.
class Pelota{

    int x, y;
    int dx, dy;

    public:
        Pelota(int _x, int _y, int _dx, int _dy);
        void Pintar() const;
        void Borrar() const;
        void Mover(Jugador A, Jugador B);
        void Asistencia(int _x, int _y){
            x = _x;
            y = _y;
        };
        void Puntuacion(int &Puntaje_1, int &Puntaje_2);
        bool Game_Over(int &Puntaje_1, int &Puntaje_2, int &_x, int &_y);
        void Reiniciar_Partida(int &Puntaje_1, int &Puntaje_2, int &_x, int &_y);
        int PX(){
        return x;
        };

        int PY(){
        return y;
        };
        int DX(){
            return dx;
        };
};

// Definiendo la clase interfaz para hacer el menú
class Interfaz{
    public:
        void Menu_Juego(int &a);
};



//Definiciones de los metodos de la clase Jugador.
Jugador::Jugador(int _x, int _y) : x(_x), y(_y){
    //Aqui estamos inicializando directamente los miembros privados.
}

void Jugador::Pintar() const{
	gotoxy(x , y-1); printf("%c", 219);
	gotoxy(x , y  ); printf("%c", 219);
	gotoxy(x , y+1); printf("%c", 219);
}

void Jugador::Borrar() const{
    gotoxy(x , y-1); printf(" ");
	gotoxy(x , y  ); printf(" ");
	gotoxy(x , y+1); printf(" ");
}

void Jugador::Mover_Cpu(int _x, int _y, int _dx){

    if(_x > 80 && _dx > 0){
        Borrar();

        if(_y > y && y+1 < 27){
        y++; Pintar();
        }

        if(_y < y && y-1 > 3 ){
            y--; Pintar();
        }
    }
}


//Definiciones de los metodos de la clase Pelota.
Pelota::Pelota(int _x, int _y, int _dx, int _dy): x(_x), y(_y), dx(_dx), dy(_dy)
{
    //Aqui estamos inicializando directamente los miembros privados.
}

void Pelota::Pintar() const{
    gotoxy(x, y); printf("%c", 184);
}

void Pelota::Borrar() const{
    gotoxy(x, y); printf(" ");
}

void Pelota::Mover(Jugador A, Jugador B){
    Borrar();
    x+= dx;
    y+= dy;
    Pintar();

    if(x + dx == 2 || x + dx == 117){
        Borrar();
        dx = -dx;
        Asistencia(62, 14);
        Pintar();
    }

    if(y + dy == 2 || y + dy == 28){
        Borrar();
        dy = -dy;
        Pintar();
    }

    if( x + dx == A.RX() && y >= A.RY()-1 && y <= A.RY()+1) {dx = -dx;}
    if( x + dx == B.RX() && y >= B.RY()-1 && y <= B.RY()+1) {dx = -dx;}
}

void Pelota::Puntuacion(int &Puntaje_1, int &Puntaje_2){

    //Puntuacion 1.
    gotoxy(40, 1); printf("%d", Puntaje_1);
    if(x + dx == 116){
        Puntaje_1 += 1;
        gotoxy(40, 1); printf("%d", Puntaje_1);
    }

    //Puntuacion 2.
    gotoxy(79, 1); printf("%d", Puntaje_2);
    if(x + dx == 3){
        Puntaje_2 += 1;
        gotoxy(79, 1); printf("%d", Puntaje_2);
    }


    if(Puntaje_1 == 3){
        gotoxy(53,3); printf("JUGADOR 1 WIN!");
    }

    if(Puntaje_2 == 3){
        gotoxy(53,3); printf("JUGADOR 2 WIN!");
    }
}

void Pelota::Reiniciar_Partida(int &Puntaje_1, int &Puntaje_2, int &_x, int &_y){

    Borrar();

    gotoxy(53,3); printf("              ");
    gotoxy(39, 13);                              //
    printf("                                      ");
    gotoxy(47, 14);
    printf("                         ");

    Puntaje_1 = 0;
    Puntaje_2 = 0;
    x = _x;
    y = _y;

    _x = 62;
    _y = 14;
}

bool Pelota::Game_Over(int &Puntaje_1, int &Puntaje_2, int &_x, int &_y){

    if(Puntaje_1 == 3 || Puntaje_2 == 3){
		gotoxy(39, 13);
        printf("-Presione E para reiniciar la partida.");

		gotoxy(47, 14);
        printf("-Presione ESC para salir.");

        char Tecla;
        Tecla = getch();
        if(Tecla == 'e' || Tecla == 'E'){
            Reiniciar_Partida(Puntaje_1, Puntaje_2, _x, _y);
        }

        if(Tecla == ESC){
            system("cls");
            Pintar_Marco();
            gotoxy(51,13); printf("Gracias por jugar!");
            gotoxy(34,14); printf("Presiona cualquier tecla para finalizar el programa.");
            return 0;
        }
    }
    return true;
}


//Aqui definimos el metedo Menu_Juego de la clase Interfaz.
void Interfaz::Menu_Juego(int &a){

    char Portada[22][111] =
{
"                                                                                                              ",
"    aaaaaaaas                                                                                                 ",
"  aaaaaaaaaaass                                                                                               ",
"  aaaa      aass                                                                                              ",
"  aaaa      aass                                                                                              ",
"  aaaa      aass         /                                                                                    ",
"  aaaa      aass    / /   /                                            -PRESIONA 1 JUGADOR VS CPU             ",
"  aaaaaaaaaaaas    /   / /                                             -PRESIONA 2 JUGADOR VS JUGADOR         ",
"  aaaaaaaaaas     / /   /                        aaaaas                -PRESIONA ESC PARA SAIR                ",
"  aaaas          /   / /                      aaaaaaaaaas                                                     ",
"  aaaas         aaas  /   aaas      aaas    aaa         aas                                                   ",
"  aaaas       aaaaaaas    aaasas    aaas    aaa         aas                                                   ",
"  aaaas       aaaaaaas    aaas aas  aaas    aaa                                                               ",
"  aaaas         aaas      aaas  aas aaas    aaa                                                               ",
"  aaaas                   aaas   aasaaas    aaa     aaaaass                                                   ",
"  aaaas                   aaas    aasaas    aaa         aass                                                  ",
"  aaaas                   aaas     aasas    aaa        aaass                                                  ",
"  aaaas                   aaas      aass     aaaaaaaaaaaass                                                   ",
"  aaaas                   aaas      aaas        saaaaaaas                                                     ",
"                                                                                                              ",
"                                                                                                              ",

};

    for(int i = 0 ; i < 21; i++){
        for(int j = 0; j < 109; j++){
            gotoxy(j + 8, i + 6); printf("%c", Portada[i][j]);
        }
    }

    a = getch();

    for(int i = 0 ; i < 21; i++){
        for(int j = 0; j < 109; j++){
            gotoxy(j + 5, i + 5); printf(" ");
        }
    }

}

