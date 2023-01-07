#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Estructura.h"

int main(){
    char tecla;

    //Menu de inicio.
    do{
        system("Title Juego de la Nave Espacial");
        ocultar_cursor();
        menu_inicio();
        tecla = getch();
    }while(tecla != '1' && tecla != '2' && tecla != ESC);   //Mientras sea verdadero, se ejecutara el loop.

    switch(tecla){
        //Caso ESC (Menu inicio).
        case ESC:
            return 0;
        break;  //Fin del caso ESC.

        //Caso '1' (Menu inicio).
        case '1':
            system("cls");
            Sleep(30);

            //Loop principal.
            while(num_vidas > 0){
                //Llamadas a las funciones principales.
                ocultar_cursor();
                mover_nave(ix, iy, tecla);
                asteroides( ix, iy, num_vidas, corazones);
                cambio_nivel(ix, iy, nivel, repeticion);
                mover_nave(ix, iy, tecla);
                vidas(num_vidas);
                barra_de_salud(corazones);
                imprimir_nivel(nivel);

                //Opcion pausa durante el juego.
                if(tecla == ARRIBA){
                    menu_pausa();
                    do{
                        tecla = getch();
                        switch(tecla){
                            //Caso '1'.
                            case '1':
                                reiniciar_partida(ix, iy, num_vidas, corazones, nivel, repeticion);
                            break;  //Fin del caso '1'.
                            //Caso '2'.
                            case '2':
                                system("cls");
                                inicializando_variables(ix, iy, num_vidas, corazones, nivel, repeticion);
                                return main();
                            break;  //Fin del caso '2'.
                            //Caso ESC.
                            case ESC:
                                pantalla_final();
                                return 0;
                            break;  //Fin del caso ESC.
                        }
                    }while(tecla != '1' && tecla != '2' && tecla != '3' && tecla != ESC);   //Mientras sea verdadero, se ejecutara el loop.
                    system("cls");
                }   //Fin de opcion pausa.

                //Opcion game over.
                if(num_vidas == 0){
                    menu_game_over();
                    do{
                        tecla = getch();
                        switch(tecla){
                            //Caso '1'.
                            case '1':
                                reiniciar_partida(ix, iy, num_vidas, corazones, nivel, repeticion);
                            break;  //Fin del caso '1'.
                            //Caso '2'.
                            case '2':
                                system("cls");
                                inicializando_variables(ix, iy, num_vidas, corazones, nivel, repeticion);
                                return main();
                            break;  //Fin del caso '2'.
                            //Caso '3'.
                            case ESC:
                                pantalla_final();
                                return 0;
                            break;  //Fin del caso ESC.
                        }
                    }while(tecla != '1' && tecla != '2' && tecla != ESC);   //Mientras sea verdadero, se ejecutara el loop.
                }   //Fin opcion game over.
            }//Fin del while(Loop principal).
        break;  //Fin del caso '1'.
        
        //Caso '2' (Menu inicio).
        case '2':
            menu_controles();
            getch();
            return main();
        break;  ///Fin del caso '2'.
        
    }//Fin del switch (Menu inicio).
    pantalla_final();
	return 0;
}
