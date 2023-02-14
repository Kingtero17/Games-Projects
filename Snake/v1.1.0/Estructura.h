#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "Interfaz.h"

//Definiendo teclas para el movimiento.
#define ARRIBA		72
#define IZQUIERDA 	75
#define DERECHA		77
#define ABAJO		80
#define ESC			27

//Declarando funciones principales.
void dibujar_cuerpo(int &tam);
void guardar_posicion(int &posx, int &posy, int &n, int &tam);
void borrar_guardado(int &tam);
void borrar_cuerpo(int &n);
void mover_snake(int &posx, int &posy, int tecla);
void cambiar_velocidad(int &velocidad);
void comida(int &posx_c, int &posy_c, int &tam, int &score);
void puntaje(int &score);
void guardar_puntaje(int &score); FILE *pun;
void leer_puntaje();
void inicializando_variables(int &posx, int &posy, int &n, int &tam, int &posx_c, int &posy_c, int &dir, int &score, int &velocidad, int &h);
void reiniciar_partida();
bool game_over();


//Inicializando tamaño, velocidad, posicion, ect.
int cuerpo[200][2];
int posx = 10, posy = 12;
int n = 1;
int tam = 3;
int dir = 3;
int posx_c = 30, posy_c = 15;
int velocidad = 100, h = 1;
int score = 0;


//Definiendo funciones principales.
void dibujar_cuerpo(int &tam){
	if(posx > 2 && posx < 117 && posy > 2 && posy < 28){
		for(int i = 1; i < tam; i++){
			gotoxy(cuerpo[i][0], cuerpo[i][1]);
			printf("\033[0;32m");printf("*");printf("\033[0m");
		}
	}
}

//Guadar posicion.
void guardar_posicion(int &posx, int &posy, int &n, int &tam){
	cuerpo[n][0] = posx;
	cuerpo[n][1] = posy;
	n ++;
	if(n == tam){
		n = 1;	//La parte de atrás del cuerpo será la cabeza.
	}
}

//Borrar cuerpo.
void borrar_cuerpo(int &n){
	gotoxy(cuerpo[n][0], cuerpo[n][1]);printf(" ");
}

//Borrar guardado.
void borrar_guardado(int &tam){
	for(int i = 1; i < tam; i++){
		gotoxy(cuerpo[i][0], cuerpo[i][1]);printf(" ");	//Así borraremos el rastro que deja.
	}
}

//Mover snake.
void mover_snake(int &posx, int &posy, int tecla){
	//Moviento Snake.
	if(kbhit()){
		tecla = getch();
		switch(tecla){
			//Caso ARRIBA.
			case ARRIBA:
				if(posy > 2)	//Verifica la posicion de la snake con respecto a lo limites.
				if(dir != 2)	//Verifica si la direccion actual no es la contraria, si es asi, cambiamos de direccion.
				dir = 1;
			break;	//Fin del caso ARRIBA.

			//Caso ABAJO.
			case ABAJO:
				if(posy < 28)
				if(dir != 1)
				dir = 2;
			break;	//Fin del caso ABAJO.

			//Caso DERECHA.
			case DERECHA:
				if(posx < 117)
				if(dir != 4)
				dir = 3;
			break;	//Fin del caso DERECHA.

			//Caso IZQUIERDA.
			case IZQUIERDA:
				if(posx > 2)
				if(dir != 3)
				dir = 4;
			break;	//Fin del caso IZQUIERDA.
		}
	}
}

//Cambiar velocidad.
void cambiar_velocidad(int &velocidad){
	if(score == h*20){
		velocidad -= 5; //Mientras más cerca de 0, la velocidad aumentará.
		h++;
	}
}

//Comida.
void comida(int &posx_c, int &posy_c, int &tam, int &score){
	if(posx == posx_c && posy == posy_c){
		posx_c = (rand()%112) + 4;
		posy_c = (rand()% 23) + 4;
		tam++;
		score += 10;
		gotoxy(posx_c, posy_c);
		printf("\033[1;31m");printf("%c",4);printf("\033[0m");
		cambiar_velocidad(velocidad);
	}
}

//Puntaje.
void puntaje(int &score){
	gotoxy(3, 1);printf("score %d",score);
}

//Guardar punatje.
void guardar_puntaje(int &score){
	system("cls");
	pintar_marco();

	pun = fopen("Score.txt", "a+");	//Abrimos el archivo, y sino está, se creará dicho archivo.
	gotoxy(37,3);printf("INGRESE SU NOMBRE PARA GUARDAR SU RECORD: \n");

	char nombre[15];
	char vacio[47] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
					' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
					' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
					' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
					' ',' ',' ', ' '
					};

	gotoxy(37, 4);scanf("%s",nombre);	//Se guarda el usuario.
	gotoxy(37, 5);printf("%s %d PUNTOS", nombre, score);
	fprintf(pun, "%s ", vacio);fprintf(pun,"%d \n", score);	//Se guarda el record.

	getch();	//Se espera que el usuario presiona cualquier tecla.
	fclose(pun);	//Se cierra el archivo.
}

//Leer puntaje.
void leer_puntaje(){
	pun = fopen("Score.txt", "r");	//Se abre el archivo en formato de lectura.
	int c;

	system("cls");
	pintar_marco();
	gotoxy(47,3);printf("MEJORES PUNTUACIONES:\n");

	while((c = getc(pun)) != EOF){	//Mientras no se alcance el final del archivo.
		if(c == '\n'){
			printf("\n");	//Si hay salto de linea, se imprime dicho caracter.
		}
		else{
			printf("%c", c);	//Si hay un caracter, se imprime.
		}
	}
	getch();	//Se espera que el usuario presiona cualquier tecla.
	fclose(pun);	//Se cierra el archivo.
}

//Inicializando variables.
void inicializando_variables(int &posx, int &posy, int &n, int &tam, int &posx_c, int &posy_c, int &dir, int &score, int &velocidad, int &h){
	//Inicializando variables.
	posx = 10, posy = 12;
	n = 1;
	tam = 3;
	dir = 3;
	posx_c = 30, posy_c = 15;
	velocidad = 100, h = 1;
	score = 0;
}

//Reiniciar partida.
void reiniciar_partida(){
	system("cls");
	borrar_guardado(tam);
	inicializando_variables(posx, posy, n, tam, posx_c, posy_c, dir, score, velocidad, h);
	gotoxy(posx_c,posy_c);printf("\033[1;31m");printf("%c",4);printf("\033[0m");
	pintar_marco();
}

//Game over.
bool game_over(){
	//Opcion: Limites del juego.
	if(posy == 2 || posy == 28 || posx == 2 || posx == 117){
		return true;
	}
	//Opcion: Choque contigo mismo.
	for(int a = tam - 1; a > 0; a--){
		if(cuerpo[a][0] == posx && cuerpo[a][1] == posy){
			return true;
		}
	}
	return false;
}