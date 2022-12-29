#include <windows.h>
#include <iostream>
#include <conio.h>

#define ARRIBA		72
#define IZQUIERDA	75	//Aqui estamos definiendo las teclas para poder movernos en el juego.
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

//Aqui estamos definiendo los prototipos de las funcioenes mas tecnicas (Funciones principales de la interfaz).
void Menu_Juego();
void Pintar_Marco();
void gotoxy (int x, int y);
void Ocultar_Cursor();

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

int main (){

	//Llamando a las funciones principales de la interfaz 

	system("Title Juego de la Snake");
	Ocultar_Cursor();
	Menu_Juego();

	//Esperamos que la persona presione una tecla, dependiendo de la tecla se ejecutara el juego o se saldra del programa.
	Tecla = getch();


	switch(Tecla){

		case ESC :
			return 0;
		break; // Corte del caso 'ESC'.


		case 'd':
			system("cls");
			Sleep(100);
			Ocultar_Cursor();
			Pintar_Marco();
			gotoxy(xc, yc); printf("%c", 4);

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
			}//Termina el While.

			Pintar_Marco();
		break;//Corte del caso 'd'.
	}//Termina el Swicth.

	system("cls");
	Pintar_Marco();
	gotoxy(51,13); printf("Gracias por jugar!");
	gotoxy(34,14); printf("Presiona cualquier tecla para finalizar el programa.");
	system("pause > NULL");		//El system ("pause") nos sirve para que el programa se pause y no se cierre solo.
	return 0;
}

/*Desde este punto empezamos a definir todas las funciones, tanto como del juego,
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
		for (int i = 1; i < Tam; i++){
			gotoxy(Cuerpo[i][0] , Cuerpo[i][1]); printf("*");
		}
	}
}

void Borrar_cuerpo(int &n){
	gotoxy(Cuerpo[n][0] , Cuerpo[n][1]); printf(" ");
}

void Borrar_guardado(int &Tam){
	for (int i = 1; i < Tam; i++){
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
	if (score == h*20){
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
		gotoxy (xc,yc); printf ("%c",4);

		Cambiar_velocidad(Velocidad);
	}
}


void Puntaje(int &score){
gotoxy ( 3, 1); printf("score %d",score);
}


void Reiniciar_Partida(int &n, int &Tam, int &x, int &y, int &xc, int &yc, int &Dir, int &score,int &Velocidad, int &h){

	Tecla = getch();
	if(Tecla == 'a'){

		gotoxy(39, 14);
		printf("                                      ");
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

		gotoxy (xc,yc); printf (" ",4);
		gotoxy (xc,yc); printf ("%c",4);
		gotoxy ( 3, 1); printf("score    ");
		Pintar_Marco();
	}
}

bool Game_over(int &n, int &Tam, int &x, int &y, int &xc, int &yc, int &Dir, int &score, int &Velocidad, int &h){

	if(y == 2 || y == 28 || x == 2 || x == 117 ){
	
		gotoxy(39, 14);
        printf("-Presione A para reiniciar la partida.");
        gotoxy(47, 15);
        printf("-Presione ESC para salir.");
        
		Reiniciar_Partida(n, Tam, x, y, xc, yc, Dir, score, Velocidad, h);
	}

	for(int a = Tam - 1; a > 0; a--){
		if(Cuerpo[a][0] == x && Cuerpo[a][1] == y){

            gotoxy(39, 14);
            printf("-Presione A para reiniciar la partida.");
			gotoxy(47, 15);
            printf("-Presione ESC para salir.");

			Reiniciar_Partida(n, Tam, x, y, xc, yc, Dir, score, Velocidad, h);
        }
	}
	return true;
}

//A partir de aqui estamo definiendo las funciones declaradas de la interfaz.
void Menu_Juego(){

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
    gotoxy(2,2); printf ("%c",201);
    gotoxy(2,28); printf ("%c",200);
    gotoxy(117,2); printf ("%c",187);
    gotoxy(117,28); printf ("%c",188);

char Portada [22][111] =		//112 - 2 = 110 en le eje "x" y 21 de en el eje "y".
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
			gotoxy(j + 5, i + 5); printf("%c", Portada[i][j]);
		}
	}
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
		gotoxy( 2, i);
		printf("%c",186);		//Se coloca (%c,y aqui el numero en codigo ASCII).
		gotoxy( 117, i);
		printf("%c",186);
	}
    //Esquinas.
        gotoxy(2,2); printf ("%c",201);
        gotoxy(2,28); printf ("%c",200);
        gotoxy(117,2); printf ("%c",187);
        gotoxy(117,28); printf ("%c",188);

}

void gotoxy ( int x, int y){
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