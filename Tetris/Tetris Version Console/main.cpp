#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define ARRIBA		72
#define IZQUIERDA	75		//Aqui estamos definiendo las teclas para poder movernos en el juego.
#define DERECHA		77
#define ABAJO		80
#define ESC			27

const int FILAS = 20;
const int COLUMNAS = 10;
typedef int Tablero[COLUMNAS][FILAS];

//Funcion gotoxy; Coordenadas.
void gotoxy(int x, int y){
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle( STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

void Ocultar_Cursor(){
	CONSOLE_CURSOR_INFO cci = {100, FALSE};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

struct Coord{
	int x, y;
};

struct Pieza{
	Coord orig;			//Aqui obviamente estamos inicializando una variable de la estructura Coord como orig y perif.
	Coord perif[3];		//Por eso en la funcion Pintar_Pieza podemos acceder a "x" y "y" de Coord.
};

void Cuadrado(int x, int y){
	gotoxy(x,y);
	printf("*");
}

void Cuadrado_Vacio(int x, int y){
	gotoxy(x,y);
	printf(" ");
}

/*Para acceder a los datos miembros de una estructura tenemos que colocar el nombre de la variable
de la estructura, seguido de un punto y al lado el nombre del miembro de la estructura que se quiere
acceder.Ejemplo: P.orig.*/


/*Hay 4 formas de inicializar una variable de una estructura: 1- Despues del corchete y antes del punto
y coma colocar el nombre de la variable que queremos que tenga acceso a esos miembros ( }orig; ).
2- Coloando la palabra struct seguido del nombre de la estructura seguido del nombre de la variable
que tenga acceso a esos miembros ( struct Coord orig;).3- Colocando el nombre de la estructura seguido
del nombre de la variable que tenga acceso a esos miembros ( Coord orig;).
4- Colocando  el nombre de la estructura como parametro dentro de una funcion e inicializando directamente
la variable(Coord C).*/

//Aqui estamos inicializando una variable P de la estructura Pieza directamente,
//y a su vez la colocamos como parametro por referencia, asi podremos cambiar su valor.

void Pintar_Pieza(const Pieza& P){
    printf("\033[0;31m");
	Cuadrado(P.orig.x, P.orig.y);
	
	for(int i = 0; i < 3; i++){
		Cuadrado(P.orig.x + P.perif[i].x,
		P.orig.y + P.perif[i].y);
	}
}


void Borrar_Pieza(const Pieza &P){
	Cuadrado_Vacio(P.orig.x, P.orig.y);

	for(int i = 0; i < 3; i++){
		Cuadrado_Vacio(P.orig.x + P.perif[i].x,
		P.orig.y + P.perif[i].y);
	}
}

/*Para rotar las piezas del tetris o las piezas de nuestro juego necesitamos terner en cuenta
que el angulo lo queremos rotar y en que sentido(Si en el sentido de las agujas del reloj (Derecha)
o al sentido opuesto de las agujas del reloj(Izquierda)).*/


Coord Rota_Derecha(const Coord& C){
    Coord ret = { -C.y, C.x };
	return ret; 
}

Coord Rota_Izquierda(const Coord& C){
    Coord ret = { C.y, -C.x };
	return ret;
}

void Rota_Derecha(Pieza& P){
	for(int i = 0; i < 3; i++){
		P.perif[i] = Rota_Derecha(P.perif[i]);
	}
}

void Rota_Izquierda(Pieza& P){
	for(int i = 0; i < 3; i++){
		P.perif[i] = Rota_Izquierda(P.perif[i]);
	}
}

void Tablero_Pinta( Tablero &T){
	for(int i = 0; i < COLUMNAS; i++){
		for(int j = 0; j < FILAS; j++){
			gotoxy(i, j); Cuadrado_Vacio(i, j);		//Significa casilla vacia, o sea que no hay ninguna pieza.
		}
	}
}


int main(){
	system("cls");
	Ocultar_Cursor();
	Tablero T;
	Tablero_Pinta(T);

	
	Pieza S1 = { { 2, 2 }, { { -1, -1}, { 0,  -1 }, { 1, 0 } } };
	Pieza L1 = { { 2, 8 }, { { -1, 0 }, { -1, -1 }, { 1, 0 } } };

	
	Pintar_Pieza(S1);
	Pintar_Pieza(L1);
	
	while(1){
		
		if(kbhit()){
			
			char Tecla;	
			Tecla = getch();

			if(Tecla == DERECHA){
				Borrar_Pieza(S1);
				Rota_Derecha(S1);
				Borrar_Pieza(L1);
				Rota_Derecha(L1);
			}
			else if(Tecla == IZQUIERDA){
				Borrar_Pieza(S1);
				Rota_Izquierda(S1);
				Borrar_Pieza(L1);
				Rota_Izquierda(L1);
			}
			Pintar_Pieza(S1);
			Pintar_Pieza(L1);
		}
	}
	printf("\033[0m");
	return 0;
}