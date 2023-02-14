#include "Estructura.h"

int main (){
	char tecla;

	//Menu de inicio.
	do{
	system("Title Snake");
	ocultar_cursor();
	menu_inicio();
	tecla = getch();
	}while(tecla != '1' && tecla != '2' && tecla  != '3' && tecla != ESC);//Mientras sea verdadero, se ejecutara el loop.

	switch(tecla){
		//Caso ESC (Menu inicio).
		case ESC:
			return 0;
		break;//Fin del caso ESC.

		//Caso '1' (Menu de inicio).
		case '1':
			system("cls");
			pintar_marco();

			while(!game_over()){
				gotoxy(posx_c, posy_c);printf("\033[1;31m");printf("%c",4);printf("\033[0m");	//Inicializamos la comida de color rojo.
				dibujar_cuerpo(tam);
				borrar_cuerpo(n);
				guardar_posicion(posx, posy, n, tam);
				dibujar_cuerpo(tam);
				comida(posx_c, posy_c, tam, score);
				puntaje(score);

				//Movimiento Snake.
				if(dir == 1) posy--;
				if(dir == 2) posy++;
				if(dir == 3) posx++;
				if(dir == 4) posx--;

				//Opcion pausa.
				if(kbhit()){
					tecla = getch();
					if(tecla == '3'){
						menu_pausa();
						do{
							tecla = getch();
							switch(tecla){
								//Caso '1' (Menu pausa).
								case '1':
								reiniciar_partida();
								break;//Fin del caso '1'.

								//Caso '2' (Menu pausa).
								case '2':
								system("cls");
								inicializando_variables(posx, posy, n, tam, posx_c, posy_c, dir, score, velocidad, h);
								return main();
								break;//Fin del caso '2'.

								//Caso ESC (Menu pausa).
								case ESC:
								pantalla_final();
								return 0;
								break;//Fin del caso ESC.
							}
						}while(tecla != '1' && tecla != '2' && tecla != '3' && tecla != ESC);	//Mientras sea verdadero, se ejecutara el loop.
						system("cls");
						pintar_marco();
					}
				}//Fin de opcion pausa.

				//Opcion game over.
				if(game_over()){
					dir = 0;
					menu_game_over();
					do{
						tecla = getch();
						switch(tecla){
							//Caso '1' (Game over).
							case '1':
								reiniciar_partida();
							break;//Fin del caso '1'.

							//Caso '2' (Game over).
							case '2':
								guardar_puntaje(score);
							break;//Fin del caso '2'.

							//Caso '3' (Game over).
							case '3':
								system("cls");
								inicializando_variables(posx, posy, n, tam, posx_c, posy_c, dir, score, velocidad, h);
								return main();
							break;//Fin del caso '3'.

							case ESC:
								pantalla_final();
								return 0;
							break;//Fin del caso ESC.
							}
					}while(tecla != '1' && tecla != '2' && tecla != '3' && tecla != ESC);	//Mientras sea verdadero, se ejecutara el loop.
				}//Fin opcion game over.
				mover_snake(posx, posy, tecla);
				mover_snake(posx, posy, tecla);
				Sleep(velocidad);
			}
		break;//Fin del caso '1'.

		//Caso '2' (Menu de inicio).
		case '2':
			leer_puntaje();
			system("cls");
			return main();
		break;//Fin del caso '2'.

		//Caso '3' (Menu de inicio);
		case '3':
			menu_controles();
			getch();
			return main();
		break;//Fin del caso '3'.
	}
	system("cls");
	pantalla_final();
	return 0;
}