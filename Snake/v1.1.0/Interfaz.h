//Declarando funciones interfaz.
void gotoxy(int x, int y);
void ocultar_cursor();
void pintar_marco();
void menu_inicio();

//Definiendo funciones interfaz.

//Funcion gotoxy; coordenadas.
void gotoxy(int x, int y){
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle( STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);
}

//Ocultar cursor; como su nombre lo indica oculta el cursor de la pantalla.
void ocultar_cursor(){
	CONSOLE_CURSOR_INFO cci = {100, FALSE};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

//Pintar marco; marco del juego.
void pintar_marco(){
	//Lineas horizontales.
	for(int i = 2; i < 118; i++){
		gotoxy(i, 2); printf("%c",205);
		gotoxy(i, 28);printf("%c",205);
	}
	//Lineas verticales.
	for(int i = 2; i < 29; i++){
		gotoxy(2, i);  printf("%c",186);
		gotoxy(117, i);printf("%c",186);
	}
    //Esquinas.
    gotoxy(2,2);   printf("%c",201);
    gotoxy(2,28);  printf("%c",200);
    gotoxy(117,2); printf("%c",187);
    gotoxy(117,28);printf("%c",188);
}

//Menu de inicio.
void menu_inicio(){
	//Marco del Menu del juego.

	//Lineas horizontales.
	for(int i = 2; i < 118; i++){
		gotoxy(i, 2); printf("%c",205);
		gotoxy(i, 28);printf("%c",205);
	}
	//Lineas Verticales.
	for(int i = 2; i < 29; i++){
		gotoxy(2, i);  printf("%c",186); 
		gotoxy(117, i);printf("%c",186);
	}
    //Esquinas.
    gotoxy(2,2);   printf("%c",201);
    gotoxy(2,28);  printf("%c",200);
    gotoxy(117,2); printf("%c",187);
    gotoxy(117,28);printf("%c",188);

//Portada de inicio del juego.
char portada [22][111] =		// 112 - 2 = 110 en le eje "x" y 21 de en el eje "y".
{
"        aaaaaaaaaaaa  aa         aa      aaaa      aa       aa aaaaaaaaaaaa                                   ",
"                  aa  aaa        aa    aaaaaaaa    aa    aa    aa                                             ",
"                  aa  aa  aa     aa  aaaaaaaaaaaa  a  aa       aa                                             ",
"        aaaaaaaaaaaa  aa   aaa   aa aaaaaaaaaaaaaa aa          aaaaaaaaaaaa                                   ",
"        aa            aa     aa  aa  aaaaaaaaaaaa  a aa        aa                                             ",
"        aa            aa        aaa    aaaaaaaa    aa   aa     aa                                             ",
"        aaaaaaaaaaaa  aa         aa      aaaa      aa      aa  aaaaaaaaaaaa                                   ",
"                                     **        **                              -PRESIONE 1 PARA JUGAR.        ",
"                                     ****    ****             ************     -PRESIONE 2 PARA VER PUNTAJES  ",
"                                     ** ****** **             ************     -PRESIONE 3 PARA VER CONTROLES ",
"     ********************************************             ************     -PRESIONE ESC PARA SALIR.      ",
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
			gotoxy(j + 5, i + 5); printf("%c", portada[i][j]);
		}
	}
}

//Menu controles.
void menu_controles(){
	system("cls");
	pintar_marco();
	gotoxy(53, 9); printf("CONTROLES:");
	gotoxy(40, 11);printf("MOVER ARRIBA:     Flecha Arriba    %c", 30);
	gotoxy(40, 12);printf("MOVER ABAJO:      Flecha Abajo     %c", 31);
	gotoxy(40, 13);printf("MOVER DERECHA:    Flecha Derecha   %c", 16);
	gotoxy(40, 14);printf("MOVER IZQUIERDA:  Flecha Izquierda %c", 17);
	gotoxy(40, 15);printf("PAUSAR JUEGO:     Numero tres      %c", 51);
	gotoxy(31, 17);printf("Presione cualquier tecla para volver al menu de inicio.");
}

//Menu de pausa.
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
	gotoxy(28, 11);printf("GUARDAR RECORD:     Presione 2 para guardar su record.");
    gotoxy(28, 12);printf("MENU DE INICIO:     Presione 3 para volver al menu de inicio.");

}

//Pantalla final del juego.
void pantalla_final(){
	system("cls");
    pintar_marco();
    gotoxy(49,13);printf("Gracias por jugar!");
    gotoxy(32,14);printf("Presione cualquier tecla para finalizar el programa.");
	system("pause > NULL");   //System("pause") nos funciona para que el programa se pause y no se cierre solo.
}