#include<windows.h>
#include<conio.h>
#include<stdio.h>

/*Recordar que la libreria tiene que tener el mismo nombre con el cual se guardara la libreria,
porque en caso contrario dara error al compilar.*/

//Declarando funciones.
void gotoxy(int x,int y);
void Ocultar_Cursor();
void Menu_Juego();
void Pintar_Marco();

void gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}

/*El programa se escribe asi y se va a imprimir
lo que este en la variable Prift(Estoy hablando de la funcion gotoxy).

Para indicarle al programa que deseas imprimir en pantalla, instrucciones:
gotoxy(las respectivas coordenadas(eje x, eje y)); printf("Colocar aqui lo que quieras imprimir");*/

void Ocultar_Cursor(){
	CONSOLE_CURSOR_INFO cci = {100, FALSE};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

/*Esta funcion como  su nombre lo indica oculta el cursor de la pantalla.
Una funcion meramente estética, para que no arruine el juego.*/

void Menu_Juego(){
	//Marco de la Pantalla de inicio del juego.

	//Lineas Horizontales.
	for(int i = 2; i < 118; i++){
		gotoxy( i, 2);
		printf("%c",205);		//Se coloca (%c,y aqui el simbolo en codigo ASCII).
		gotoxy( i, 28);
		printf("%c",205);
	}
	//Lineas Verticales.
	for(int i = 2; i < 29; i++){
		gotoxy(2, i);
		printf("%c",186);		//Se coloca (%c,y aqui el simbolo en codigo ASCII).
		gotoxy( 117, i);
		printf("%c",186);
	}
    //Esquinas.
    gotoxy(2,2); printf ("%c",201);
    gotoxy(2,28); printf ("%c",200);
    gotoxy(117,2); printf ("%c",187);
    gotoxy(117,28); printf ("%c",188);

	char Portada [22][110] =  	//Recuerda que siempre se tiene que agregar una fila y una columna mas, sino da error.
	{                       	//115 - 6 = 109 en el eje "x" (col) y 21 en el eje "y" (fil).
	"    *        *          *             *    *            *           *      *      *        *    *          * ",
	"       *           *         *     *               *            *             *      *       *       *       ",
	" *          ******  ******  ******  ******  ******        *         *   *        *       *       *      *  * ",
	"    *   *        *  *    *  *    *  *       *          *          *        *         *       *       *       ",
	"            ******  ******  ******  *       ******  *        *         *         *       *              *    ",
	"  *   *     *       *       *    *  *       *            *      *         *   *      *       *    *        * ",
	"            ******  *       *    *  ******  ******         *        *                                *       ",
	"     *                    *      *        *        *                     -PRESIONE D PARA JUGAR.            *",
	"  *     *  |     *    *                                     *    *       -PRESIONE ESC PARA SALIR.      *    ",
	"     *     |  *           *    ee    *   *       *     |                       *         *                   ",
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

void Pintar_Marco(){
	//Marco de la Pantalla de inicio del juego.

	//Lineas Horizontales.
	for(int i = 2; i < 118; i++){
		gotoxy( i, 2);
		printf("%c",205);		//Se coloca (%c,y aqui el simbolo en codigo ASCII).
		gotoxy( i, 28);
		printf("%c",205);
	}
	//Lineas Verticales.
	for(int i = 2; i < 29; i++){
		gotoxy ( 2, i);
		printf ("%c",186);		//Se coloca (%c,y aqui el simbolo en codigo ASCII).
		gotoxy ( 117, i);
		printf ("%c",186);
	}
    //Esquinas
    gotoxy(2,2); printf ("%c",201);
    gotoxy(2,28); printf ("%c",200);
    gotoxy(117,2); printf ("%c",187);
    gotoxy(117,28); printf ("%c",188);
}