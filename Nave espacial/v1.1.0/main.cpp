#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Estructura.h"

int main(){

    char Tecla;
    
    do{
        system("Title Juego de la Nave Espacial");
        Ocultar_Cursor();
        Menu();
        Tecla = getch();
    }while(Tecla != '1' && Tecla != ESC);
    
    switch(Tecla){
        //Caso ESC.
        case ESC:
            return 0;
        break;  //Fin del caso ESC.

        //Caso '1'.
        case '1':
            system("cls");
            Sleep(30);
	
        while(Num_vidas > 0){
            Ocultar_Cursor();
            Jugar(Num_vidas, Corazones, ix, iy, nivel, repeticion);
            Vidas(Num_vidas);
            Barra_de_Salud(Corazones);
            gotoxy(55,1); printf("NIVEL %i",nivel);
        }
        break;  //Fin del caso '1'.
    }//Fin del Switch.
    system("cls");
    Pintar_Marco();
    gotoxy(51,13); printf("Gracias por jugar!");
    gotoxy(34,14); printf("Presiona cualquier tecla para finalizar el programa.");
	system("pause > NULL");     //System("pause") nos funciona para que el programa se pause y no se cierre solo.
	return 0;
}