#include <iostream>
#include <windows.h>
#include <conio.h>

/*Recuerda incluir las otras librerias estandar si es necesario,
ya que sino las incluimos algunas de nuestras funciones
no funcionaran y daran error.*/

//Aqui estamos definiendo los prototipos de las funcioenes mas tecnicas (Funciones principales de la interfaz).
void gotoxy(int x, int y);
void Ocultar_Cursor();
void Pintar_Marco();
void Menu_Juego();

/*Aqui estan definidas las funciones prototipos de la libreria que nosotros creamos.
Tienes que tener en cuenta que para que la libreria funcione, necesitamos que se llame igual que como
esta guardada en la carperta; sino dara error.*/

//Funcion gotoxy; Coordenadas
void gotoxy(int x, int y){
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle( STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

//Funcion Ocultar Cursor; como su nombre lo indica oculta el cursor de la pantalla.
void Ocultar_Cursor(){
	CONSOLE_CURSOR_INFO cci = {100, FALSE};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

//Funcion Pintar Marco; Marco del juego.
void Pintar_Marco(){
	//Lineas Horizontales.
	for(int i = 2; i < 118; i++){
		gotoxy(i, 2);
		printf("%c",205); 
		gotoxy(i, 28);
		printf("%c",205);
	}
	//Lineas Verticales.
	for(int i = 2; i < 29; i++){
		gotoxy(2, i);
		printf("%c",186); 
		gotoxy(117, i);
		printf("%c",186);
	}
    //Esquinas.
    gotoxy(2,2); printf ("%c",201);
    gotoxy(2,28); printf ("%c",200);
    gotoxy(117,2); printf ("%c",187);
    gotoxy(117,28); printf ("%c",188);
}

//Funcion Menu de Juego; Aqui se pinta tanto el marco como la portada del juego.
void Menu_Juego(){
	//Marco del Menu del juego.

	//Lineas Horizontales.
	for(int i = 2; i < 118; i++){
		gotoxy(i, 2);
		printf("%c",205);
		gotoxy(i, 28);
		printf("%c",205);
	}
	//Lineas Verticales.
	for(int i = 2; i < 29; i++){
		gotoxy(2, i);
		printf("%c",186); 
		gotoxy(117, i);
		printf("%c",186);
	}
    //Esquinas.
    gotoxy(2,2); printf ("%c",201);
    gotoxy(2,28); printf ("%c",200);
    gotoxy(117,2); printf ("%c",187);
    gotoxy(117,28); printf ("%c",188);

//Portada del juego.
char Portada [22][111] =		// 112 - 2 = 110 en le eje "x" y 21 de en el eje "y".
{
"        aaaaaaaaaaaa  aa         aa      aaaa      aa       aa aaaaaaaaaaaa                                   ",
"                  aa  aaa        aa    aaaaaaaa    aa    aa    aa                                             ",	
"                  aa  aa  aa     aa  aaaaaaaaaaaa  a  aa       aa                                             ",	
"        aaaaaaaaaaaa  aa   aaa   aa aaaaaaaaaaaaaa aa          aaaaaaaaaaaa                                   ",	
"        aa            aa     aa  aa  aaaaaaaaaaaa  a aa        aa                                             ",
"        aa            aa        aaa    aaaaaaaa    aa   aa     aa                                             ",
"        aaaaaaaaaaaa  aa         aa      aaaa      aa      aa  aaaaaaaaaaaa                                   ",	
"                                     **        **                                                             ",	
"                                     ****    ****             ************      -PRESIONE D PARA JUGAR.       ",	
"                                     ** ****** **             ************      -PRESIONE P PARA VER PUNTAJES ",	
"     ********************************************             ************      -PRESIONE ESC PARA SALIR.     ",
"     ********************************************             ************                                    ",	
"     ********************************************             ************                                    ",	
"     ********************************************             ************                                    ",	
"     ************                                             ************                                    ",	
"     ************            *********************************************                                    ",
"     ************            *********************************************                                    ",	
"     ************            *********************************************                                    ",	
"     *********************************************************************                                    ",	
"     *************************************                                                                    ",	
"     *************************************                                                                    ",	

};

	for(int i = 0 ; i < 21; i++){
		for(int j = 0; j < 109; j++){
			gotoxy(j + 5, i + 5); printf("%c", Portada[i][j]);
		}
	}
}