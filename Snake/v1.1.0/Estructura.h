#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "Interfaz.h"

#define ARRIBA		72
#define IZQUIERDA 	75	//Aqui estamos definiendo las teclas para poder movernos en el juego.
#define DERECHA		77
#define ABAJO		80
#define ESC			27

//Aqui estamos definiendo los prototipos de las funciones que hace que el juego funcione.
void Teclear();
void Borrar_cuerpo(int &n);
void Dibujar_cuerpo(int &Tam);
void Borrar_guardado(int &Tam);
void Guardar_posicion(int &x, int &y, int &n, int &Tam); 
void Cambiar_velocidad(int &Velocidad);
void Comida(int &xc, int &yc, int &score,int &Tam, int &Velocidad);
void Reiniciar_Partida(int &n, int &Tam, int &x, int &y, int &xc, int &yc, int &Dir, int &score, int &Velocidad, int &h);
bool Game_over(int &n, int &Tam, int &x, int &y, int &xc, int &yc, int &Dir, int &score, int &Velocidad, int &h);
void Puntaje(int &score);
void Mejor_Puntaje(int &score); FILE *Pun;
void Leer_Puntaje(); 

//Aqui estamos inicializando todas las variables que usaremos en todo el programa.
int Cuerpo[200][2];
int n = 1;
int Tam = 3;
int x = 10, y = 12;
int Dir = 3;
int xc = 30, yc = 15;
int Velocidad = 100, h = 1;
int score = 0;
char Tecla;


/*Desde este punto empezamos a definir todas las funciones, tanto como del juego
como las funciones que tienen que ver con la interfaz.*/

void Guardar_posicion(int &x, int &y, int &n, int &Tam){
	Cuerpo[n][0] = x ;
	Cuerpo[n][1] = y ;
	n ++;
	if( n == Tam ){
		n = 1;
	}
}

void Dibujar_cuerpo(int &Tam){
	if(x > 2 && x < 117 && y > 2 && y < 28){
		for(int i = 1; i < Tam; i++){
			gotoxy(Cuerpo[i][0] , Cuerpo[i][1]);
			printf("\033[0;32m"); printf("*"); printf("\033[0m");
		}
	}
}
void Borrar_cuerpo(int &n){
	gotoxy(Cuerpo[n][0] , Cuerpo[n][1]); printf(" ");
}

void Borrar_guardado(int &Tam){
	for(int i = 1; i < Tam; i++){
		gotoxy(Cuerpo[i][0] , Cuerpo[i][1]); printf(" ");
	}
}


void Teclear(){
    //Moviento de la serpiente.

    if(kbhit()){
        Tecla = getch();
        switch (Tecla){

            case ARRIBA:
				if(y > 2)
				if(Dir != 2)
				Dir = 1;
				break;

			case ABAJO:
				if(y < 28) 
				if(Dir != 1)
				Dir = 2;
				break;

			case DERECHA:
				if(x < 117) 
				if(Dir != 4)
				Dir = 3;
				break;

			case IZQUIERDA:
				if(x > 2)
				if(Dir != 3)
				Dir = 4;
				break;
		}
	}
}

void Cambiar_velocidad(int &Velocidad){
	if(score == h*20){
		Velocidad -= 5;
		h++;
	}
}

void Comida(int &xc, int &yc, int &score,int &Tam, int &Velocidad){
	if(x == xc && y == yc){

		xc = (rand()%112) + 4;
		yc = (rand()%23 ) + 4;

		Tam++;
		score += 10;
		gotoxy (xc,yc); 
		printf("\033[1;31m");printf ("%c",4);printf("\033[0m");

		Cambiar_velocidad(Velocidad);
	}
}

void Puntaje(int &score){
gotoxy (3, 1); printf("score %d",score);
}


void Mejor_Puntaje(int &score){
	system("cls");
	
	Pun = fopen("Mejor Puntaje.txt", "a+");
	gotoxy(1,1); printf("INGRESE SU NOMBRE PARA GUARDAR SU RECORD: ");
	
	char Nombre[15];
	
    scanf("%s", Nombre);
	gotoxy(1,2); printf("%s %d puntos", Nombre, score);
	fprintf(Pun, "%s %d \n", Nombre, score);
	
	Sleep(2000);

	fclose(Pun);
	
    system("cls");
    Pintar_Marco();
    gotoxy(51,13); printf("Gracias por jugar!");
    gotoxy(34,14); printf("Presiona cualquier tecla para finalizar el programa.");
	getch();
    exit(0);
}

void Leer_Puntaje(){
	Pun = fopen("Mejor Puntaje.txt", "r");
	int c;
	
	system("cls");

	gotoxy(0,1);printf("MEJORES PUNTUACIONES:\n");
	
	while((c = getc(Pun)) != EOF){
		if(c == '\n') printf("\n");
		else printf("%c", c);	
	}
	getch();
	fclose(Pun);
}

void Reiniciar_Partida(int &n, int &Tam, int &x, int &y, int &xc, int &yc, int &Dir, int &score,int &Velocidad, int &h){
	gotoxy(39, 13);
    printf("                                      ");
    gotoxy(41,14);
    printf("                                   ");
    gotoxy(47, 15);
    printf("                         ");

	Borrar_guardado(Tam);
	n = 1;
	Tam = 3;
	x = 10, y = 12;
	Dir = 3; 
	Velocidad = 100,
	h = 1;
	score = 0;
	gotoxy(xc,yc); printf (" ",4);
	gotoxy(xc,yc); printf("\033[1;31m");printf ("%c",4);printf("\033[0m");
	gotoxy(3, 1); printf("score    ");
	Pintar_Marco();
}

bool Game_over(int &n, int &Tam, int &x, int &y, int &xc, int &yc, int &Dir, int &score, int &Velocidad, int &h){

	if(y == 2 || y == 28 || x == 2 || x == 117){
		Dir = 0;

		gotoxy(39, 13);
		printf("-Presione A para reiniciar la partida.");

		gotoxy(41,14);

		printf("-Presione P para guardar su record!");

		gotoxy(47, 15);
		printf("-Presione ESC para salir.");

		Tecla = getch();
		if(Tecla == 'P' || Tecla == 'p'){
			Mejor_Puntaje(score);	
		}
		if(Tecla == 'a' || Tecla == 'A'){
			Reiniciar_Partida(n, Tam, x, y, xc, yc, Dir, score, Velocidad, h);	
		}
	}

		for(int a = Tam - 1; a > 0; a--){
			if(Cuerpo[a][0] == x && Cuerpo[a][1] == y){
				Dir = 0;

				gotoxy(39, 13);
				printf("-Presione A para reiniciar la partida.");

				gotoxy(41,14);
				printf("-Presione P para guardar su record!");

				gotoxy(47, 15);
				printf("-Presione ESC para salir.");

				Tecla = getch();
				if(Tecla == 'a' || Tecla == 'A'){
					Reiniciar_Partida(n, Tam, x, y, xc, yc, Dir, score, Velocidad, h);	
				}

				if(Tecla == 'p' || Tecla == 'P'){
					Mejor_Puntaje(score);	
				}
			}
		}
return true;
}