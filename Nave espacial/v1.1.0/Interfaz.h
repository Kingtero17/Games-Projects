#include<windows.h>
#include<conio.h>
#include<stdio.h>

/*
La libreria debe de tener el mismo nombre con el
cual se guardara el archivo, en caso contrario
dara error al compilar.
*/

//Declarando funciones.
void gotoxy(int x,int y);
void ocultar_cursor();
void pintar_marco();
void menu_inicio();
void menu_controles();
void menu_pausa();
void menu_game_over();
void pantalla_final();


//Definiendo las funciones.
void gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

/*
Instrucciones:
gotoxy(Coordenadas(eje x, eje y));
printf("Colocar aqui lo que quieras imprimir");
*/


/*Funcion oculta el cursor de la pantalla.
Una funcion simplemente estética.*/
void ocultar_cursor(){
	CONSOLE_CURSOR_INFO cci = {50, FALSE};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

//Marco del juego.
void pintar_marco(){
	//Lineas Horizontales.
	for(int i = 2; i < 118; i++){
		gotoxy(i, 2); printf("%c",205);		//Printf("%c", simbolo en codigo ASCII).
		gotoxy(i, 28);printf("%c",205);
	}
	//Lineas Verticales.
	for(int i = 2; i < 29; i++){
		gotoxy(2, i);  printf("%c",186);	//Printf("%c", simbolo en codigo ASCII).
		gotoxy(117, i);printf("%c",186);
	}
    //Esquinas
    gotoxy(2,2);   printf("%c",201);
    gotoxy(2,28);  printf("%c",200);
    gotoxy(117,2); printf("%c",187);
    gotoxy(117,28);printf("%c",188);
}

//Pantalla de inicio del juego.
void menu_inicio(){
	//Lineas Horizontales.
	for(int i = 2; i < 118; i++){
		gotoxy(i, 2); printf("%c",205);		//Printf("%c", simbolo en codigo ASCII).
		gotoxy(i, 28);printf("%c",205);
	}
	//Lineas Verticales.
	for(int i = 2; i < 29; i++){
		gotoxy(2, i);  printf("%c",186);	//Printf("%c", simbolo en codigo ASCII).
		gotoxy(117, i);printf("%c",186);
	}
    //Esquinas.
    gotoxy(2,2);   printf("%c",201);
    gotoxy(2,28);  printf("%c",200);
    gotoxy(117,2); printf("%c",187);
    gotoxy(117,28);printf("%c",188);

	char Portada [22][110] =  	//Siempre agregar una fila y una columna demás, sino dará error.
	{                       	//115 - 6 = 109 en el eje "x" (col) y 21 en el eje "y" (fil).
	"    *        *          *             *    *            *           *      *      *        *    *          * ",
	"       *           *         *     *               *            *             *      *       *       *       ",
	" *          ******  ******  ******  ******  ******        *         *   *        *       *       *      *  * ",
	"    *   *        *  *    *  *    *  *       *          *          *        *         *       *       *       ",
	"            ******  ******  ******  *       ******  *        *         *         *       *              *    ",
	"  *   *     *       *       *    *  *       *            *      *         *   *      *       *    *        * ",
	"            ******  *       *    *  ******  ******         *        *                                *       ",
	"     *                    *    *          *        *                     -PRESIONE 1 PARA JUGAR.            *",
	"  *     *  |     *    *                                     *    *       -PRESIONE 2 PARA VER CONTROLES.  *  ",
	"     *     |  *           *    ee    *   *       *     |                 -PRESIONE ESC PARA SALIR.           ",
	"         | |      *     *     eeee           *         | |   *           *        *             *    *   *  *",
	"  *  *   | |              *   eeee      *              | |         *          *          *                   ",
	"         |    1111                            1111       | *    *                   *        *      *    *   ",
	"    *         1111    xxxx    xxxx    xxxx    1111   *   |               *                                 * ",
	" *         *  1111    xxxx    xxxx    xxxx    1111              *    *          *        *       *     *     ",
	"       aa      aa                              aa      aa               *           *         *            * ",
	"   *  aaaa    aaaa        aaaaaaaaaaaa   *    aaaa    aaaa *    *   *       *           *            *       ",
	" *    aaaa    aaaa   *    aaaaaaaaaaaa        aaaa    aaaa                    *     *          *           * ",
	"       aa      aa             aaaa        *    aa      aa     *    *      *                  *     *     *   ",
	"   *               *                               *                            *     *    *                 ",
	" *     *    *           *       *      *     *       *   *    *    *   *    *      *           *      *     *",
	};
	
	for(int i = 0; i < 21; i++){
		for(int j = 0; j < 109; j++){
			gotoxy(j + 5, i + 5); printf("%c", Portada[i][j]);
		}
	}
}

//Menu controles.
void menu_controles(){
	system("cls");
	pintar_marco();
	gotoxy(53, 11);printf("CONTROLES:");
	gotoxy(40, 13);printf("MOVER DERECHA:    Flecha Derecha   %c", 16);
	gotoxy(40, 14);printf("MOVER IZQUIERDA:  Flecha Izquierda %c", 17);
	gotoxy(40, 15);printf("PAUSAR JUEGO:     Flecha Arriba    %c", 30);
	gotoxy(30, 17);printf("-Presione cualquier tecla para volver al menu de inicio.");
}

//Menu de pausa del juego.
void menu_pausa(){
	gotoxy(56, 7); printf("PAUSE");
	gotoxy(28, 9); printf("SALIR:              Presione ESC para salir.");
	gotoxy(28, 10);printf("REINICIAR PARTIDA:  Presione 1 para reiniciar la partida.");
	gotoxy(28, 11);printf("MENU DE INICIO:     Presione 2 para volver al menu de inicio.");
	gotoxy(28, 12);printf("REANUDAR PARTIDA:   Presione 3 para reanudar la partida.");
}

//Menu Game over.
void menu_game_over(){
	gotoxy(28, 9); printf("SALIR:              Presione ESC para salir.");
	gotoxy(28, 10);printf("REINICIAR PARTIDA:  Presione 1 para reiniciar la partida.");
    gotoxy(28, 11);printf("MENU DE INICIO:     Presione 2 para volver al menu de inicio.");

}

//Pantalla final del juego.
void pantalla_final(){
	system("cls");
    pintar_marco();
    gotoxy(51,13);printf("Gracias por jugar!");
    gotoxy(34,14);printf("Presione cualquier tecla para finalizar el programa.");
	system("pause > NULL");   //System("pause") nos funciona para que el programa se pause y no se cierre solo.
}