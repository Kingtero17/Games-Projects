#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Estructura.h"

int main(){

    system("Title Juego de la Nave Espacial");
    Menu_Juego();
    Ocultar_Cursor();

    char Tecla;
    Tecla = getch();

    if(Tecla == ESC){
        return 0;
    }//Fin de la declaracion del ESC.

    if(Tecla == 'd' || Tecla == 'D'){
        system("cls");
        Sleep(130);
	
        while(Tecla != ESC && Num_vidas > 0){
            Ocultar_Cursor();
            Jugar(Num_vidas, Corazones, ix, iy, nivel, repeticion);
            Vidas(Num_vidas);
            Barra_de_Salud(Corazones);
            gotoxy(55,1); printf("NIVEL %i",nivel);
        }
    }

    system("cls");
    Pintar_Marco();
    gotoxy(51,13); printf("Gracias por jugar!");
    gotoxy(34,14); printf("Presiona cualquier tecla para finalizar el programa.");
	system("pause > NULL");     //El system ("pause") nos sirve para que el programa se pause y no se cierre solo.
	return 0;
}
