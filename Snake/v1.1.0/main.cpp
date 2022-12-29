#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "Estructura.h"



int main (){

	//Llamando a las funciones principales de la interfaz. 
	system("Title Juego de la Snake");
	Ocultar_Cursor();
	Menu_Juego();

	//Esperamos que la persona presione una tecla, dependiendo de la tecla se ejecutara el juego o se saldra del programa.
	Tecla = getch();

	//La verison#1 tenia el swicth lo cambiamos por el if para poder recibir los casos en mayusculas.
	//Si la tecla es igual a ESC ,entonces se cerrara el programa.
	if(Tecla == ESC){
		return 0; 
	}

	//Si la tecla es igual a 'p' o a 'P' ,entonces mostrara los puntajes guardados.
	if(Tecla == 'p' || Tecla == 'P'){
		Leer_Puntaje();	
	}

	//Si la tecla es igual a 'd' o a 'D' ,entonces se ejecutara el juego.
	if(Tecla == 'd' || Tecla == 'D'){
		system("cls");
		Sleep(100);
		Ocultar_Cursor();
		Pintar_Marco();
		gotoxy(xc, yc);
		printf("\033[1;31m");printf ("%c",4);printf("\033[0m");
	
		while(Tecla != ESC && Game_over(n, Tam, x, y, xc, yc, Dir, score, Velocidad, h)){
			Borrar_cuerpo(n);
			Guardar_posicion(x, y, n, Tam);
			Dibujar_cuerpo(Tam);
			Dibujar_cuerpo(Tam);

			Comida(xc, yc, score, Tam, Velocidad);

			Puntaje(score);

			Teclear();
			Teclear();

			if(Dir == 1) y--;
			if(Dir == 2) y++;
			if(Dir == 3) x++;
			if(Dir == 4) x--;

			Sleep(Velocidad);
		}
	Pintar_Marco();
	}

	system("cls");
	Pintar_Marco();
	gotoxy(51,13); printf("Gracias por jugar!");
	gotoxy(34,14); printf("Presiona cualquier tecla para finalizar el programa.");
	getch();
	return 0;
}