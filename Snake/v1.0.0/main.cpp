#include <windows.h>
#include <iostream>
#include <conio.h>

//Definiendo teclas.
#define ARRIBA		72
#define IZQUIERDA	75
#define DERECHA		77
#define ABAJO		80
#define ESC			27

//Declarando funciones principales.
void dibujar_cuerpo(int &tam);
void guardar_posicion(int &posx, int &posy, int &n, int &tam);
void borrar_cuerpo(int &n);
void borrar_guardado(int &tam);
void teclear();
void cambiar_velocidad(int &velocidad);
void comida(int &tam, int &posx_c, int &posy_c, int &score, int &velocidad);
void puntaje(int &score);
void reiniciar_partida(int &posx, int &posy, int &n, int &tam, int &posx_c, int &posy_c, int &dir, int &score, int &velocidad, int &h);
bool game_over(int &posx, int &posy, int &n, int &tam, int &posx_c, int &posy_c, int &dir, int &score, int &velocidad, int &h);


//Declarando funciones interfaz.
void gotoxy(int x, int y);
void ocultar_cursor();
void pintar_marco();
void menu_inicio();

//Inicializando variables.
int cuerpo[200][2];
int posx = 10, posy = 12;
int n = 1;
int tam = 3;
int dir = 3;
int posx_c = 30, posy_c = 15;
int score = 0;
int velocidad = 100, h = 1;


int main (){
	//Menu inicio. 
	system("Title Juego de la Snake");
	ocultar_cursor();
	menu_inicio();

	char tecla;
	tecla = getch();

	switch(tecla){
		//Caso ESC.
		case ESC :
			return 0;
		break;	//Fin del caso 'ESC'.

		//Caso 'd'.
		case 'd':
			system("cls");
			Sleep(100);
			ocultar_cursor();
			pintar_marco();
			gotoxy(posx_c, posy_c);printf("%c", 4);

			while(tecla != ESC && game_over(posx, posy, n, tam, posx_c, posy_c, dir, score, velocidad, h)){
				teclear();
				borrar_cuerpo(n);
				guardar_posicion(posx, posy, n, tam);
				dibujar_cuerpo(tam);
				dibujar_cuerpo(tam);
				comida( tam, posx_c, posy_c, score, velocidad);
				puntaje(score);
				teclear();

				if(dir == 1)posy--;
				if(dir == 2)posy++;
				if(dir == 3)posx++;
				if(dir == 4)posx--;

				Sleep(velocidad);
			}//Fin del While.
			pintar_marco();
		break;//Fin del caso 'd'.
	}//Fin del Swicth.

	system("cls");
	pintar_marco();
	gotoxy(51,13);printf("Gracias por jugar!");
	gotoxy(34,14);printf("Presione cualquier tecla para finalizar el programa.");
	system("pause > NULL");		//El system ("pause") nos sirve para que el programa se pause y no se cierre solo.
	return 0;
}


//Definiendo funciones principales.
void dibujar_cuerpo(int &tam){
	if(posx > 2 && posx < 117 && posy > 2 && posy < 28){	
		for(int i = 1; i < tam; i++){
			gotoxy(cuerpo[i][0], cuerpo[i][1]);printf("*");
		}
	}
}

void guardar_posicion(int &posx, int &posy, int &n, int &tam){
	cuerpo[n][0] = posx;
	cuerpo[n][1] = posy;
	n ++;
	if(n == tam){
		n = 1;
	}
}

void borrar_cuerpo(int &n){
	gotoxy(cuerpo[n][0], cuerpo[n][1]);printf(" ");
}

void borrar_guardado(int &tam){
	for (int i = 1; i < tam; i++){
		gotoxy(cuerpo[i][0] , cuerpo[i][1]);printf(" ");
    }
}

void teclear(){
	//Moviento de la serpiente.
	char tecla;
	if(kbhit()){
		tecla = getch();
		switch(tecla){
			//Caso ARRIBA.
			case ARRIBA:
				if(posy > 2)
				if(dir != 2)
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

void cambiar_velocidad(int &velocidad){
	if(score == h * 20){
		velocidad -= 5;
		h++;
	}
}

void comida(int &tam, int &posx_c, int &posy_c, int &score, int &Velocidad){
	if(posx == posx_c && posy == posy_c){
		posx_c = (rand()%112) + 4;
		posy_c = (rand()%23 ) + 4;
		tam++;
		score += 10;
		gotoxy(posx_c, posy_c);printf("%c",4);
		cambiar_velocidad(velocidad);
	}
}

void puntaje(int &score){
	gotoxy(3, 1);printf("score %d",score);
}

void reiniciar_partida(int &posx, int &posy, int &n, int &tam, int &posx_c, int &posy_c, int &dir, int &score,int &velocidad, int &h){
	char tecla;
	tecla = getch();
	if(tecla == 'a'){
		gotoxy(39, 14);
		printf("                                      ");
		gotoxy(47, 15);
		printf("                         ");
		borrar_guardado(tam);
		n = 1;
		tam = 3;
		posx = 10, posy = 12;
		dir = 3; 
		velocidad = 100, 
		h = 1;
		score = 0;

		gotoxy(posx_c, posy_c);printf(" ",4);
		gotoxy(posx_c,posy_c);printf("%c",4);
		gotoxy(3, 1);printf("score    ");
		pintar_marco();
	}
}

bool game_over(int &posx, int &posy, int &n, int &tam, int &posx_c, int &posy_c, int &dir, int &score, int &velocidad, int &h){
	if(posy == 2 || posy == 28 || posx == 2 || posx == 117 ){
		gotoxy(39, 14);printf("-Presione A para reiniciar la partida.");
		gotoxy(47, 15);printf("-Presione ESC para salir.");
		reiniciar_partida(posx, posy, n, tam,  posx_c, posy_c, dir, score, velocidad, h);
	}
	for(int a = tam - 1; a > 0; a--){
		if(cuerpo[a][0] == posx && cuerpo[a][1] == posy){
			gotoxy(39, 14);printf("-Presione A para reiniciar la partida.");
			gotoxy(47, 15);printf("-Presione ESC para salir.");
			reiniciar_partida(posx, posy, n, tam, posx_c, posy_c, dir, score, velocidad, h);
		}
	}
	return true;
}

//Declarando funciones interfaz.
void gotoxy(int x, int y){
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

//Ocultar cursor.
void ocultar_cursor(){
	CONSOLE_CURSOR_INFO cci = {100, FALSE};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

//Marco de la pantalla.
void pintar_marco(){
	//Lineas horizontales.
	for(int i = 2; i < 118; i++){
		gotoxy(i, 2); printf("%c",205);		//Printf("%c", simbolo en codigo ASCII).
		gotoxy(i, 28);printf("%c",205);
	}
	//Lineas verticales.
	for(int i = 2; i < 29; i++){
		gotoxy(2, i);  printf("%c",186);		//Printf("%c", simbolo en codigo ASCII).
		gotoxy(117, i);printf("%c",186);
	}
    //Esquinas.
    gotoxy(2,2);   printf("%c",201);
    gotoxy(2,28);  printf("%c",200);
    gotoxy(117,2); printf("%c",187);
    gotoxy(117,28);printf("%c",188);
}

//Menu inicio.
void menu_inicio(){
	//Lineas Horizontales.
	for(int i = 2; i < 118; i++){
		gotoxy(i, 2); printf("%c",205);		//Printf("%c", simbolo en codigo ASCII).
		gotoxy(i, 28);printf("%c",205);
	}
	//Lineas Verticales.
	for(int i = 2; i < 29; i++){
		gotoxy(2, i);  printf("%c",186);		//Printf("%c", simbolo en codigo ASCII).
		gotoxy(117, i);printf("%c",186);
	}
	//Esquinas.
	gotoxy(2,2);   printf("%c",201);
	gotoxy(2,28);  printf("%c",200);
	gotoxy(117,2); printf("%c",187);
	gotoxy(117,28);printf("%c",188);

char menu_inicio[22][111] =		//112 - 2 = 110 en le eje "x" y 21 de en el eje "y".
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
"                                     ************             ************      -PRESIONE ESC PARA SALIR.     ",	
"     ********************************************             ************                                    ",
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
			gotoxy(j + 5, i + 5);printf("%c", menu_inicio[i][j]);
		}
	}
}