#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "Estructura.h"

int main(){
    char tecla;

    do{
        system("Title Juego de la Nave Espacial");
        ocultar_cursor();
        menu_inicio();
        tecla = getch();
    }while(tecla != '1' && tecla != '2' && tecla != ESC);

    switch(tecla){
        //Caso ESC.
        case ESC:
            return 0;
        break;  //Fin del caso ESC.

        //Caso '1'.
        case '1':
            system("cls");
            Sleep(30);

        //Loop principal.
        while(num_vidas > 0){
            ocultar_cursor();
            mover_nave(ix, iy, tecla);
            asteroides( ix, iy, num_vidas, corazones);
            cambio_nivel(ix, iy, nivel, repeticion);
            mover_nave(ix, iy, tecla);
            vidas(num_vidas);
            barra_de_salud(corazones);
            gotoxy(55,1); printf("NIVEL %i",nivel);

            if(tecla == ARRIBA){
                menu_pausa();
                tecla = getch();
                switch(tecla){
                    case '1':
                        reiniciar_partida(ix, iy, num_vidas, corazones, nivel, repeticion);
                    break;

                    case '2':
                        system("cls");
                        inicializando_variables(ix, iy, num_vidas, corazones, nivel, repeticion);
                        return main();
                    break;
                    
                    case ESC:
                        pantalla_final();
                        return 0;
                    break;
                }
                system("cls");
            }
            if(num_vidas == 0){
                menu_game_over();
                tecla = getch();
                switch(tecla){
                    case '1':
                        reiniciar_partida(ix, iy, num_vidas, corazones, nivel, repeticion);
                        break;

                    case '2':
                        system("cls");
                        inicializando_variables(ix, iy, num_vidas, corazones, nivel, repeticion);
                        return main();
                    break;

                    case ESC:
                        pantalla_final();
                        return 0;
                    break;
                }
            }
        }//Fin del while.
        break;  //Fin del caso '1'.

        case '2':
            menu_controles();
            getch();
            return main();
        break;

    }//Fin del Switch.
    pantalla_final();
	return 0;
}
