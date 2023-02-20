#include "Pong.h"


int main(){
	char tecla;
	int cont1 = 0, cont2 = 0;
	Jugador A(6, 15);
	Jugador B(113, 16);
	Pelota P(62, 14, 1, 1);
	system("Title Pong");

	//Menu de inicio.
	do{
		I.ocultar_cursor();
		I.pintar_marco();
		I.menu_inicio();
		tecla = getch();
	}while(tecla != '1' && tecla != '2' && tecla != ESC);//Mientras sea verdadero, se ejecutara el loop.

	switch(tecla){
		//Caso '1': Jugar.
		case '1':
			system("cls");
			do{
				I.opcion_juego();
				tecla = getch();
			}while(tecla != '1' && tecla != '2' && tecla != '3');

			switch(tecla){
				//Caso '1' (Opcion Juego).
				case '1':
					system("cls");
					system("Color 0e");
					I.pintar_marco();
					while(!P.Game_over(Puntaje_1, Puntaje_2)){
						A.Borrar(); B.Borrar();
						A.MoverA(tecla);if(!cont1++)B.Mover_cpu(P.Px(), P.Py(), P.Dx());
						A.Pintar(); B.Pintar();P.Puntuacion(Puntaje_1, Puntaje_2);
						if(!cont2++)P.Mover(A, B);
						if(cont1 > 3)cont1 = 0;
						if(cont2 > 2)cont2 = 0;

						//Opcion pausa.
						if(tecla == '3'){
							I.menu_pausa();
							do{
								tecla = getch();
								switch(tecla){
									//Caso '1' (Menu pausa).
									case '1':
										P.Reiniciar_partida(Puntaje_1, Puntaje_2, _x, _y);
									break;//Fin del caso '1'.

									//Caso '2' (Menu pausa).
									case '2':
										system("cls");
										system("Color 07");
										P.Reiniciar_partida(Puntaje_1, Puntaje_2, _x, _y);
										return main();
									break;//Fin del caso '2'.

									//Caso ESC (Menu pausa).
									case ESC:
										system("Color 07");
										I.pantalla_final();
										return 0;
									break;//Fin del caso ESC.
								}
							}while(tecla != '1' && tecla != '2' && tecla != '3' && tecla != ESC);	//Mientras sea verdadero, se ejecutara el loop.
							tecla = '0';
							system("cls");
							I.pintar_marco();
						}//Fin opcion pausa.

						//Opcion Game over.
						if(P.Game_over(Puntaje_1, Puntaje_2)){
							do{
								I.menu_game_over();
								tecla = getch();
								switch(tecla){
									//Caso '1' (Menu Game over).
									case '1':
										P.Reiniciar_partida(Puntaje_1, Puntaje_2, _x, _y);
									break;//Fin del caso '1'.

									//Caso '2' (Menu Game over).
									case '2':
										system("cls");
										system("Color 07");
										P.Reiniciar_partida(Puntaje_1, Puntaje_2, _x, _y);
										return main();
									break;//Fin del caso '2'.

									//Caso ESC (Menu Game over).
									case ESC:
										system("Color 07");
										I.pantalla_final();
										return 0;
									break;//Fin del caso ESC.
								}
							}while(tecla != '1' && tecla != '2' && tecla != ESC);	//Mientras sea verdadero, se ejecutara el loop.
							tecla = '0';
							system("cls");
							I.pintar_marco();
						}
						Sleep(10);
					}
				break;//Fin caso '1'.

				//Caso '2' (Opcion Juego).
				case '2':
					system("cls");
					system("Color 0e");
					I.pintar_marco();
					while(!P.Game_over(Puntaje_1, Puntaje_2)){
						A.Borrar(); B.Borrar();
						A.MoverA(tecla);B.MoverB(tecla);
						A.Pintar(); B.Pintar();P.Puntuacion(Puntaje_1, Puntaje_2);
						if(!cont2++)P.Mover(A, B);
						if(cont2 > 2)cont2 = 0;

						//Opcion pausa.
						if(tecla == '3'){
							I.menu_pausa();
							do{
								tecla = getch();
								switch(tecla){
									//Caso '1' (Menu pausa).
									case '1':
										P.Reiniciar_partida(Puntaje_1, Puntaje_2, _x, _y);
									break;//Fin del caso '1'.

									//Caso '2' (Menu pausa).
									case '2':
										system("cls");
										system("Color 07");
										P.Reiniciar_partida(Puntaje_1, Puntaje_2, _x, _y);
										return main();
									break;//Fin del caso '2'.

									//Caso ESC (Menu pausa).
									case ESC:
										system("Color 07");
										I.pantalla_final();
										return 0;
									break;//Fin del caso ESC.
								}
							}while(tecla != '1' && tecla != '2' && tecla != '3' && tecla != ESC);	//Mientras sea verdadero, se ejecutara el loop.
							tecla = '0';
							system("cls");
							I.pintar_marco();
						}//Fin opcion pausa.

						//Opcion Game over.
						if(P.Game_over(Puntaje_1, Puntaje_2)){
							do{
								I.menu_game_over();
								tecla = getch();
								switch(tecla){
									//Caso '1' (Menu Game over).
									case '1':
										P.Reiniciar_partida(Puntaje_1, Puntaje_2, _x, _y);
									break;//Fin del caso '1'.

									//Caso '2' (Menu Game over).
									case '2':
										system("cls");
										system("Color 07");
										P.Reiniciar_partida(Puntaje_1, Puntaje_2, _x, _y);
										return main();
									break;//Fin del caso '2'.

									//Caso ESC (Menu Game over).
									case ESC:
										system("Color 07");
										I.pantalla_final();
										return 0;
									break;//Fin del caso ESC.
								}
							}while(tecla != '1' && tecla != '2' && tecla != ESC);	//Mientras sea verdadero, se ejecutara el loop.
							tecla = '0';
							system("cls");
							I.pintar_marco();
						}
						Sleep(10);
					}
				break;//Fin caso '2'.

				//Caso '3' (Opcion Juego).
				case '3':
					return main();
				break;//Fin caso '3'.
			}
		break;//Fin caso '1' (Opcion Juego).


		//Caso '2' (Menu de inicio).
		case '2':
			I.menu_controles();
			getch();
			return main();
		break;//Fin del caso '2'.

		//Caso ESC (Menu inicio).
		case ESC:
			return 0;
		break;//Fin del caso ESC.
	}
	system("cls");
	I.pantalla_final();
	return 0;
}
