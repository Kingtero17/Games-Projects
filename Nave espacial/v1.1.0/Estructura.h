#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include"Interfaz.h"


//Definiendo teclas flecha izquierda y derecha para mover la nave espacial, flecha arriba para pausar el juego y la tecla "ESC" pora salir.
#define ESC 27
#define IZQUIERDA 75
#define DERECHA 77
#define ARRIBA	72


char avion_11[]={' ',' ',' ','*',' ',' ',' ',0};        //Nave Espacial.
char avion_12[]={' ','|','*','*','*','|',' ',0};
char avion_13[]={'*','*',' ','*',' ','*','*',0};

char explosion_e1[]={' ',' ','*','*',' ',' ',' ',0};    //Explosion de la Nave#1.
char explosion_e2[]={' ','*','*','*','*',' ',' ',0};
char explosion_e3[]={' ',' ','*','*',' ',' ',' ',0};

char explosion_e11[]={'*',' ','*','*',' ','*',' ',0};    //Explosion de la Nave#2.
char explosion_e22[]={' ','*','*','*','*',' ',' ',0};
char explosion_e33[]={'*',' ','*','*',' ','*',' ',0};

char borrar_avion[]={' ',' ',' ',' ',' ',' ',' ',0};    //Borrar Nave Espacial.


//Coordenadas, corazones y vidas iniciales de la nave.
int ix = 54;
int iy = 19;
int num_vidas = 3;
int corazones = 3;

//Coordenadas de los asteroides.
int x = 36, y = 10;
int xx = 82, yy = 9;
int x1 = 90, y1 = 8;
int x2 = 74, y2 = 4;
int x3 = 58, y3 = 7;
int x4 = 42, y4 = 3;
int x5 = 66, y5 = 2;
int x6 = 50, y6 = 5;
int x7 = 28, y7 = 6;
int x8 = 98, y8 = 1;

//Estas variables nos diran en que nivel estamos.
int repeticion = 0, nivel = 1;
//Variable de tipo buleano.
bool condicion = false;

//Declarando funciones.
void vidas(int &num_vidas);
void barra_de_salud(int &corazones);
void explosion(void);
void asteroides(int &ix, int &iy, int &num_vidas, int &corazones);
void mover_nave(int &ix, int &iy, char &tecla);
void imprimir_nivel(int &nivel);
void cambio_nivel(int &ix, int &iy, int &nivel, int &repeticion);
void reiniciar_partida(int &ix, int &iy, int &num_vidas, int &corazones, int &nivel, int &repeticion);
void inicializando_variables(int &ix, int &iy, int &num_vidas, int &corazones, int &nivel, int &repeticion);


//Definiendo funciones.
void vidas(int &num_vidas){
    gotoxy(2,1);                        //Gotoxy funciona con el eje "x,y".
    printf("VIDAS %d", num_vidas);      //Printf("%d", variable a imprimir).
}

//Barra de Salud.
void barra_de_salud(int &corazones){
    gotoxy(110,1);printf(" ");
    gotoxy(111,1);printf(" ");
    gotoxy(112,1);printf(" ");

    /*Borramos antes de imprimir y luego imprimimos,
    asi si perdemos un corazon, la variable "n" va a valer "n-=1"
    y por ende se imprimira un corazon menos.*/

    for(int v = 0; v < corazones; v++){
        gotoxy(110+v,1);
        printf("%c", 3);
    }
}

//Explosion nave.
void explosion(void){
    //Primera explosion.
    gotoxy(ix,iy);  puts(explosion_e1);
    gotoxy(ix,iy+1);puts(explosion_e2);
    gotoxy(ix,iy+2);puts(explosion_e3);

    Sleep(380);     //Funcion "Sleep" detiene el programa 380 milisegundos para asi poder apreciar la explosion.

    //Segunda explosion.
    gotoxy(ix,iy);  puts(explosion_e11);
    gotoxy(ix,iy+1);puts(explosion_e22);
    gotoxy(ix,iy+2);puts(explosion_e33);

    Sleep(380);

    //Nave espacial.
    gotoxy(ix,iy);  puts(avion_11);
    gotoxy(ix,iy+1);puts(avion_12);
    gotoxy(ix,iy+2);puts(avion_13);

    /*Se imprime la nave, porque sino, despues de
    la explosion no se veria la misma.*/
}


//Comportamiento de los asteroides.
void asteroides(int &ix, int &iy, int &num_vidas, int &corazones){
    //Mecanicas de los asteriodes.
    gotoxy(x,y);  printf("%c", 1);
    gotoxy(xx,yy);printf("%c", 1);
    gotoxy(x1,y1);printf("%c", 1);
    gotoxy(x2,y2);printf("%c", 1);
    gotoxy(x3,y3);printf("%c", 1);
    gotoxy(x4,y4);printf("%c", 1);
    gotoxy(x5,y5);printf("%c", 1);
	gotoxy(x6,y6);printf("%c", 1);
    gotoxy(x7,y7);printf("%c", 1);
	gotoxy(x8,y8);printf("%c", 1);

    Sleep(80);

    /*
    Despues de cierto tiempo el programa borrara
    los asteroides, haciendo la ilusion de caida.
    */

    gotoxy(x,y);  printf(" ");
    gotoxy(xx,yy);printf(" ");
    gotoxy(x1,y1);printf(" ");
    gotoxy(x2,y2);printf(" ");
    gotoxy(x3,y3);printf(" ");
    gotoxy(x4,y4);printf(" ");
    gotoxy(x5,y5);printf(" ");
	gotoxy(x6,y6);printf(" ");
	gotoxy(x7,y7);printf(" ");
	gotoxy(x8,y8);printf(" ");


    /*Si "y" (Eje "y" del asteroide) es mayor que 20, entoces "y" pasara a valer 4 (El asteroide subira)
    y "x" sera igual a un numero pseudo-random con limite de 110 y le sumamos 6 (El "6+" funciona para
    que el asteroide no se genere tan cerca al lado izquierdo de la pantalla y para que la posicion del
    asteroide sea un poco mas random).*/

    //Procedimiento con todos los asteroides.
    if(y > 20){
        y = 4;
        x = 6 +(rand() % 95);
        if(y  == 4){
            condicion = false;  //Cambio de nivel.
        }
    }
    if(yy > 20){
        yy = 4;
        xx = 7 +(rand() % 110);
    }
    if(y1 > 20){
        y1 = 4;
        x1 = 6 +(rand() % 110);
    }
    if(y2 > 20){
        y2 = 4;
        x2 = 7 +(rand() % 110);
    }
    if(y3 > 20){
        y3 = 4;
        x3 = 6 +(rand() % 110);
    }
    if(y4 > 20){
        y4 = 4;
        x4 = 7 +(rand() %110);	
    }

    if(y5 > 20){
        y5 = 4;
        x5 = 6 +(rand() %110);	
    }
    if(y6 > 20){
        y6 = 4;
        x6 = 7 +(rand() %110);	
    }
    if(y7 > 20){
        y7 = 4;
        x7 = 6 +(rand() %110);	
    }
    if(y8 > 20){
        y8 = 4;
        x8 = 7 +(rand() %110);	
    }

    //Rutina de impacto de los asteroides.

    /*Si "x" es mayor que las coordenadas de la nave en el eje "x" (ix) y "x" es menor que las coordenadas
    de la nave en el eje "x" (ix) + 7 y "y" es igual que las coordenadas de la nave en el eje "y" (iy) menos 1.
    Entonces se le restará un corazon a la barra de salud. Esto se tienen que hacer con todos
    los asteroides.*/

    if ( (x > ix && x < ix + 7 && y == iy - 1) || (xx > ix && xx < ix + 7 && yy == iy - 1)
    || (x1 > ix && x1 < ix + 7 && y1 == iy - 1)|| (x2 > ix && x2 < ix + 7 && y2 == iy - 1)
    || (x3 > ix && x3 < ix + 7 && y3 == iy - 1)|| (x4 > ix && x4 < ix + 7 && y4 == iy - 1)
	|| (x5 > ix && x5 < ix + 7 && y5 == iy - 1)|| (x6 > ix && x6 < ix + 7 && y6 == iy - 1)
	|| (x7 > ix && x7 < ix + 7 && y7 == iy - 1)|| (x8 > ix && x8 < ix + 7 && y8 == iy - 1)){
        corazones --;
        barra_de_salud(corazones);
    }
    //Imprimimos la nave, sino se borraria con la colision de los asteroides.
    gotoxy(ix,iy);  puts(avion_11);
    gotoxy(ix,iy+1);puts(avion_12);
    gotoxy(ix,iy+2);puts(avion_13);

    //Loop corazones.
    if(corazones == 0){     //(!corazones).
        num_vidas --;
        corazones = 3;
        vidas(num_vidas);
        barra_de_salud(corazones);
        explosion();
    }

    //Aumentamos la posicion en "y" de los asteroides para que vayan cayendo.
    y++; yy++; y1++; y2++; y3++; y4++; y5++; y6++; y7++; y8++;
}

//Mover nave espacial.
void mover_nave(int &ix, int &iy, char &tecla){
    /*Funcion "kbhit" indica que si se detecta una tecla,
    el programa procese esa tecla y no se detenga el programa.
    Con "tecla = getch" le indicamos al programa esté atento para
    recibir una tecla del teclado y que dicha tecla (El valor de la misma)
    se la pase a la variable tecla.*/

    if(kbhit()){
        tecla = getch();
        switch(tecla){
            case IZQUIERDA:
                if(ix > 4){
                    gotoxy(ix,iy);  puts(borrar_avion);
                    gotoxy(ix,iy+1);puts(borrar_avion);
                    gotoxy(ix,iy+2);puts(borrar_avion);

                    ix -= 2;    //Despues de borrar la nave, le restamos 2 a su posicion actual.

                    gotoxy(ix,iy);  puts(avion_11);
                    gotoxy(ix,iy+1);puts(avion_12);
                    gotoxy(ix,iy+2);puts(avion_13);
                }
            break;

            /*Si detecta que algunos de los dos casos (IZQUIERDA o DERECHA) y si la nave nave se encuentra entre los limites
            establecidos, entonces borraremos la nave, le restaremos o sumaremos a su posicion (Dependiendo el caso) y
            al final volveremos a imprimir la misma. Para crear la sensacion de movimiento.*/

            case DERECHA:
                if(ix < 118 ){
                    gotoxy(ix,iy);  puts(borrar_avion);
                    gotoxy(ix,iy+1);puts(borrar_avion);
                    gotoxy(ix,iy+2);puts(borrar_avion);

                    ix += 2;    //ix = ix +2; 'o' ix += 2;

                    gotoxy(ix,iy);  puts(avion_11);
                    gotoxy(ix,iy+1);puts(avion_12);
                    gotoxy(ix,iy+2);puts(avion_13);
                }
            break;
        }//Fin del switch.
    }//Fin del if.
}

//Nivel.
void imprimir_nivel(int &nivel){
    gotoxy(55,1);               //Gotoxy funciona con el eje "x,y".
    printf("NIVEL %i",nivel);   //Printf("%d", variable a imprimir).
}

//Cambiar nivel.
void cambio_nivel(int &ix, int &iy, int &nivel, int &repeticion){
    //Cambio de nivel.
    if(!condicion){
    repeticion++;
    condicion = true;
    }

    //loop principal del cambio de nivel.
    if(repeticion == 20){
        nivel++;
        gotoxy(55,1);printf("NIVEL %i",nivel);
        
        gotoxy(ix,iy);  puts(borrar_avion);
        gotoxy(ix,iy+1);puts(borrar_avion);
        gotoxy(ix,iy+2);puts(borrar_avion);
        
        iy -=1;
        
        gotoxy(ix,iy);  puts(avion_11);
        gotoxy(ix,iy+1);puts(avion_12);
        gotoxy(ix,iy+2);puts(avion_13);
        
        repeticion = 0;
    }
    /*
        La nave estara mas cerca de la posicion inicial de los asteroides,
        lo cual hara que el usuario tenga menos tiempo de reaccion; haciendo 
        asi, el juego mas dificil.
    */
}

//Inicializacion de variables.
void inicializando_variables(int &ix, int &iy, int &num_vidas, int &corazones, int &nivel, int &repeticion){  
    //Asignamos valores de reinicio.
    ix = 54;
    iy = 19;
    num_vidas = 3;
    corazones = 3;
    nivel = 1;
    repeticion = 0;
}

//Reiniciar partida.
void reiniciar_partida(int &ix, int &iy, int &num_vidas, int &corazones, int &nivel, int &repeticion){
    //Borramos pantalla.
    system("cls");

    //Borramos nave.
    gotoxy(ix,iy);  puts(borrar_avion);
    gotoxy(ix,iy+1);puts(borrar_avion);
    gotoxy(ix,iy+2);puts(borrar_avion);

    //Asignamos valores de reinicio.
    inicializando_variables(ix, iy, num_vidas, corazones, nivel, repeticion);

    //Imprimir vidas y corazones.
    vidas(num_vidas);
    barra_de_salud(corazones);

    //Imprimir nave.
    gotoxy(ix,iy);  puts(avion_11);
    gotoxy(ix,iy+1);puts(avion_12);
    gotoxy(ix,iy+2);puts(avion_13);
}