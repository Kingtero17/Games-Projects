#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Estructura.h"

int main(){
    char tecla;

    do{
        system("Title Juego de la Nave Espacial");
        ocultar_cursor();
        menu();
        tecla = getch();
    }while(tecla != '1' && tecla != ESC);

    switch(tecla){
        //Caso ESC.
        case ESC:
            return 0;
        break;  //Fin del caso ESC.

        //Caso '1'.
        case '1':
            system("cls");
            Sleep(30);

        while(num_vidas > 0){
            ocultar_cursor();
            mover_nave(ix, iy);
            asteroides( ix, iy, num_vidas, corazones);
            cambio_nivel(ix, iy, nivel, repeticion);
            mover_nave(ix, iy);
            vidas(num_vidas);
            barra_de_salud(corazones);
            game_over(ix, iy, num_vidas, corazones, nivel, repeticion);
            gotoxy(55,1); printf("NIVEL %i",nivel);
        }
        break;  //Fin del caso '1'.
    }//Fin del Switch.
    system("cls");
    pintar_marco();
    gotoxy(51,13); printf("Gracias por jugar!");
    gotoxy(34,14); printf("Presiona cualquier tecla para finalizar el programa.");
	system("pause > NULL");     //System("pause") nos funciona para que el programa se pause y no se cierre solo.
	return 0;
}
