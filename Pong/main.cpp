#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "Pong.h"

#define ESC 27

int Puntaje_1 = 0;
int Puntaje_2 = 0;
int _x = 62;
int _y = 14;
int Op_Juego;
char Tecla;

int main(){

    Pintar_Marco();
    Interfaz T; T.Menu_Juego(Op_Juego);
    Ocultar_Cursor();

	Jugador A(6 , 15); A.Pintar();
	Jugador B(113, 16); B.Pintar();
	Pelota P(62, 14, 1, 1);

	while(P.Game_Over(Puntaje_1, Puntaje_2, _x, _y) && Op_Juego != ESC){

        if(kbhit()){
            A.Borrar(); B.Borrar();

            char Tecla;
            Tecla = getch();
            if((Tecla == 'q' || Tecla == 'Q') && A.RY() > 4) A.Y(-1); else if((Tecla == 'a' || Tecla == 'A') && A.RY() < 26) A.Y(+1);
            else if(Tecla == ESC){
                system("cls");
                Pintar_Marco();
                gotoxy(51,13); printf("Gracias por jugar!");
                gotoxy(34,14); printf("Presiona cualquier tecla para finalizar el programa.");
                getch();
                return 0;
            }//Esto es el fin de la opcion ESC

            //Opcion Jugador vs Jugador
            if(Op_Juego == '2'){
            if((Tecla == 'o' || Tecla == 'O') && B.RY() > 4) B.Y(-1);
            else if((Tecla == 'l' || Tecla == 'L') && B.RY() < 26) B.Y(+1);
            } //Aqui termina Op_Juego == 2;

            A.Pintar(); B.Pintar();
        }

    P.Pintar();P.Mover(A, B);P.Puntuacion(Puntaje_1, Puntaje_2);

    //Opcion Jugador vs CPU
    if(Op_Juego == '1'){
        B.Mover_Cpu(P.PX(), P.PY(), P.DX());
    }
	Sleep(10);
	system("Color 0e");
}

if(Op_Juego == ESC){
    system("cls");
    Pintar_Marco();
    gotoxy(34,14); printf("Presiona cualquier tecla para finalizar el programa.");
    getch();
	return 0;
	}

    getch();
    return 0;
}

