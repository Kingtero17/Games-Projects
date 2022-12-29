#include <stdio.h>
#include <windows.h>
#include <conio.h>

void gotoxy ( int x, int y);
void Ocultar_Cursor();
void Pintar_Marco();

void gotoxy(int x, int y){
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

void Ocultar_Cursor(){
	CONSOLE_CURSOR_INFO cci = {100, FALSE};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

void Pintar_Marco(){
	//Marco de la Pantalla de inicio del juego.

	//Lineas Horizontales.
	for(int i = 2; i < 118; i++){
		gotoxy(i, 2);
		printf("%c",205);		//Se coloca (%c,y aqui el numero en codigo ASCII).
		gotoxy(i, 28);
		printf("%c",205);
	}
	//Lineas Verticales.
	for(int i = 2; i < 29; i++){
		gotoxy(2, i);
		printf("%c",186);		//Se coloca (%c,y aqui el numero en codigo ASCII).
		gotoxy(117, i);
		printf("%c",186);
	}
    //Esquinas.
    gotoxy (2,2); printf ("%c",201);
    gotoxy (2,28); printf ("%c",200);
    gotoxy (117,2); printf ("%c",187);
    gotoxy (117,28); printf ("%c",188);
}