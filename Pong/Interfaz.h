//Declarando clase Interfaz.
class Interfaz{
	public:
		void menu_inicio();
		void gotoxy(int x, int y);
		void ocultar_cursor();
		void pintar_marco();
		void opcion_juego();
		void menu_controles();
		void menu_pausa();
		void menu_game_over();
		void pantalla_final();
};

//Definiendo metodos clase Interfaz.
//Menu_inicio.
void Interfaz::menu_inicio(){
	char Portada[22][111] =		// 112 - 2 = 110 en le eje "x" y 21 de en el eje "y".
	{
	"                                                                                                              ",
	"    aaaaaaaas                                                                                                 ",
	"  aaaaaaaaaaass                                                                                               ",
	"  aaaa      aass                                                                                              ",
	"  aaaa      aass                                                                                              ",
	"  aaaa      aass         /                                                                                    ",
	"  aaaa      aass    / /   /                                             PRESIONE 1 PARA JUGAR                 ",
	"  aaaaaaaaaaaas    /   / /                                              PRESIONE 2 PARA VER CONTROLES         ",
	"  aaaaaaaaaas     / /   /                        aaaaas                 PRESIONE ESC PARA SALIR               ",
	"  aaaas          /   / /                      aaaaaaaaaas                                                     ",
	"  aaaas         aaas  /   aaas      aaas    aaa         aas                                                   ",
	"  aaaas       aaaaaaas    aaasas    aaas    aaa         aas                                                   ",
	"  aaaas       aaaaaaas    aaas aas  aaas    aaa                                                               ",
	"  aaaas         aaas      aaas  aas aaas    aaa                                                               ",
	"  aaaas                   aaas   aasaaas    aaa     aaaaass                                                   ",
	"  aaaas                   aaas    aasaas    aaa         aass                                                  ",
	"  aaaas                   aaas     aasas    aaa        aaass                                                  ",
	"  aaaas                   aaas      aass     aaaaaaaaaaaass                                                   ",
	"  aaaas                   aaas      aaas        saaaaaaas                                                     ",
	"                                                                                                              ",
	"                                                                                                              ",
	};

	for(int i = 0 ; i < 21; i++){
		for(int j = 0; j < 109; j++){
			gotoxy(j + 8, i + 6);printf("%c", Portada[i][j]);
		}
	}
}

//Gotoxy(Coordenadas).
void Interfaz::gotoxy(int x, int y){
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon,dwPos);
}
/*
Instrucciones:
gotoxy(Coordenadas(eje x, eje y));
printf("Colocar aqui lo que quieras imprimir");
*/

//Ocultar_cursor.
void Interfaz::ocultar_cursor(){
	CONSOLE_CURSOR_INFO cci = {100, FALSE};
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
}

//Marco del juego.
void Interfaz::pintar_marco(){
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
}

//Menu opcion juego.
void Interfaz::opcion_juego(){
	pintar_marco();
	gotoxy(50, 10); printf("ELIGE UNA OPCION");
	gotoxy(29, 13);printf("JUGADOR VS CPU:     Presione 1 para jugar Jugador vs Cpu");
	gotoxy(29, 14);printf("JUGADOR VS JUGADOR: Presione 2 para jugar Jugador vs Jugador");
	gotoxy(29, 15);printf("MENU DE INICIO:     Presione 3 para volver al menu de inicio");
}

//Menu controles.
void Interfaz::menu_controles(){
	system("cls");
	pintar_marco();
	gotoxy(54, 9); printf("CONTROLES");
	//Jugador 1.
	gotoxy(38, 11); printf("JUGADOR 1");
	gotoxy(35, 12);printf("MOVER ARRIBA: W");
	gotoxy(35, 13);printf("MOVER ABAJO:  S");
	//Jugador 2.
	gotoxy(70, 11); printf("JUGADOR 2");
	gotoxy(67, 12);printf("MOVER ARRIBA: %c", 30);
	gotoxy(67, 13);printf("MOVER ABAJO:  %c", 31);
	//Pausa y volver al menu.
	gotoxy(51, 14);printf("PAUSAR JUEGO: 3");
	gotoxy(31, 16);printf("Presione cualquier tecla para volver al menu de inicio");
}

//Menu de pausa.
void Interfaz::menu_pausa(){
	gotoxy(56, 7); printf("PAUSE");
	gotoxy(28, 9); printf("SALIR:              Presione ESC para salir");
	gotoxy(28, 10);printf("REINICIAR PARTIDA:  Presione 1 para reiniciar la partida");
	gotoxy(28, 11);printf("MENU DE INICIO:     Presione 2 para volver al menu de inicio");
	gotoxy(28, 12);printf("REANUDAR PARTIDA:   Presione 3 para reanudar la partida");
}

//Menu Game over.
void Interfaz::menu_game_over(){
	gotoxy(54, 7); printf("GAME OVER");
	gotoxy(28, 9); printf("SALIR:              Presione ESC para salir");
	gotoxy(28, 10);printf("REINICIAR PARTIDA:  Presione 1 para reiniciar la partida");
    gotoxy(28, 11);printf("MENU DE INICIO:     Presione 2 para volver al menu de inicio");
}

//Pantalla final del juego.
void Interfaz::pantalla_final(){
	system("cls");
    pintar_marco();
    gotoxy(49, 13);printf("Gracias por jugar!");
    gotoxy(33, 14);printf("Presione cualquier tecla para finalizar el programa");
	system("pause > NULL");   //System("pause") nos funciona para que el programa se pause y no se cierre solo.
}