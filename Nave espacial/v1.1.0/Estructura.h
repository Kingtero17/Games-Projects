#include<windows.h>
#include<conio.h>
#include<stdio.h>
#include"Interfaz.h"


//Teclas de izquierda y derecha para mover la nave espacial, y la tecla "ESC" pora salir.
#define ESC 27
#define IZQUIERDA 75
#define DERECHA 77

//Dibujos de la nave y de sus explosion.
char avion_11[]={' ',' ',' ','*',' ',' ',' ',0};        //Dibujo de la Nave Espacial.
char avion_12[]={' ','|','*','*','*','|',' ',0};
char avion_13[]={'*','*',' ','*',' ','*','*',0};

char explosion_11[]={' ',' ','*','*',' ',' ',' ',0};    //Dibujo de la explosion de la Nave #1.
char explosion_12[]={' ','*','*','*','*',' ',' ',0};
char explosion_13[]={' ',' ','*','*',' ',' ',' ',0};

char explosion_r1[]={'*',' ','*','*',' ','*',' ',0};    //Dibujo de la explosion de la Nave#2.
char explosion_r2[]={' ','*','*','*','*',' ',' ',0};
char explosion_r3[]={'*',' ','*','*',' ','*',' ',0};

char borrar_avion[]={' ',' ',' ',' ',' ',' ',' ',0};    //Es para borrar la Nave Espacial.


//Estas son las cordenadas, los corazones y las vida iniciales de la nave.
int Num_vidas = 3;
int Corazones = 3;
int ix = 54;
int iy = 19;

//Estas son las coordenadas de los asteroides.
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

int i, v;
//Estas variables nos diran en que nivel estamos.
int repeticion = 0, nivel = 1;
//Variable de tipo buleano.
bool condicion = false;

//Aqui estamos definiendo todos los prototipos de las funciones.
void Vidas(int vi);
void Barra_de_Salud(int n);
void Explosion(void);
void Reiniciar_Nivel(int &Num_vidas, int &Corazones, int &ix, int &iy, int &nivel, int &repeticion);
void Jugar(int &Num_vidas, int &Corazones, int &ix, int &iy, int &nivel, int &repeticion);



//Definiendo todas las funciones ya declaradas.
void Vidas(int vi){
    gotoxy(2,1);                     // gotoxy funciona con el eje "x,y" y necesita del printf para imprimir.
    printf("VIDAS %d", vi);         // Esto imprimira el numero de vidas en la pantalla.
}

void Barra_de_Salud(int n){
    gotoxy(110,1);
    printf(" ");
    gotoxy(111,1);
    printf(" ");
    gotoxy(112,1);
    printf(" ");

    Sleep(10);

    for(int v = 0; v < n; v++){
        gotoxy(110+v,1);
        printf("*");
    }
}

/*Le colocamo un 1+ y 2+ para que se pueda observar la animación de forma
    correcta, sino se verian todas las explosuiones en una misma linea.*/
void Explosion(void){
    //Primera Explosion.
    gotoxy(ix,iy); puts(explosion_11);
    gotoxy(ix,iy+1); puts(explosion_12);
    gotoxy(ix,iy+2); puts(explosion_13);

    Sleep(380);     //La funcion "Sleep" detiene el programa 380 milisegundos para asi poder apreciar la explosion.

    //Segunda Explosion.
    gotoxy(ix,iy); puts(explosion_r1);
    gotoxy(ix,iy+1); puts(explosion_r2);
    gotoxy(ix,iy+2); puts(explosion_r3);

    Sleep(380);

    //Tambien hay que colocar el dibujo del avion.
    gotoxy(ix,iy); puts(avion_11);
    gotoxy(ix,iy+1); puts(avion_12);
    gotoxy(ix,iy+2); puts(avion_13);

    Sleep (380);
}


/*En esta parte del progrma, haremos todas las mecanicas de los asteroides,
de los niveles, el movimiento de la nave, etc.*/
void Reiniciar_Nivel(int &Num_vidas, int &Corazones, int &ix, int &iy, int &nivel, int &repeticion){
    char Tecla;
    Tecla = getch();
    if(Tecla == 'a' || Tecla == 'A'){
        gotoxy(39, 14);
        printf("                                      ");
        gotoxy(47, 15);
        printf("                         ");

        gotoxy(ix,iy); puts(borrar_avion);
        gotoxy(ix,iy+1); puts(borrar_avion);
        gotoxy(ix,iy+2); puts(borrar_avion);

        Num_vidas = 3;
        Corazones = 3;
        ix = 54;
        iy = 19;
        nivel = 1;
        repeticion = 0;
        
        gotoxy(ix,iy); puts(avion_11);
        gotoxy(ix,iy+1); puts(avion_12);
        gotoxy(ix,iy+2); puts(avion_13);
    }
}

void Jugar(int &Num_vidas, int &Corazones, int &ix, int &iy, int &nivel, int &repeticion){
    //Mecanicas de los asteriodes.

    //El 0 es la imagen que el programa proyectara de los asteroides.
    gotoxy(x,y); printf ("0");
    gotoxy(xx,yy); printf ("0");
    gotoxy(x1,y1); printf ("0");
    gotoxy(x2,y2); printf ("0");
    gotoxy(x3,y3); printf ("0");
    gotoxy(x4,y4); printf ("0");
    gotoxy(x5,y5); printf ("0");
	gotoxy(x6,y6); printf ("0");
    gotoxy(x7,y7); printf ("0");
	gotoxy(x8,y8); printf ("0");

    Sleep(70);

    //Esto es para que el programa borre los asteroides despues de cierto tiempo.
    gotoxy(x,y); printf (" ");
    gotoxy(xx,yy); printf (" ");
    gotoxy(x1,y1); printf (" ");
    gotoxy(x2,y2); printf (" ");
    gotoxy(x3,y3); printf (" ");
    gotoxy(x4,y4); printf (" ");
    gotoxy(x5,y5); printf (" ");
	gotoxy(x6,y6); printf (" ");
	gotoxy(x7,y7); printf (" ");
	gotoxy(x8,y8); printf (" ");


    /*Si "Y" es mayor que 20, entoces "Y" (en este caso la posicion "Y" del asteroide) pasara a valer 4
    en la posicion y "X" es igual a un numero random que no pase de 110 +6 ( El 6+ es para que el
    asteroide no se genere tan cerca al lado izquierdo de la pantalla).*/

    //Hay que hacer el mismo procedimiento con todos los asteroides.

    if(y > 20){
        y = 4;
        x = 6 +(rand() % 95);
        
        if(y  == 4){
            condicion = false;  //Esto es para el cambio de nivel.
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

    //Mecanicas para mover la nave espacial.

    /*Se escribe "kbhit" para indicar que si se detecta que sea presionado una tecla, el programa procese
    esa tecla y no se detenga el programa.
    Lo que estamos haciendo con "tecla = getch"  es que el programa esté atento para recibir una tecla del teclado.*/
    if(kbhit()){
        unsigned char tecla = getch();
        switch(tecla){
            case IZQUIERDA :
                if(ix > 4){
                    gotoxy(ix,iy); puts(borrar_avion);
                    gotoxy(ix,iy+1); puts(borrar_avion);
                    gotoxy(ix,iy+2); puts(borrar_avion);

                    ix -= 2;    //Le estamos diciendo a la nave que se mueve 2 casillas hacia la izquierda.

                    gotoxy(ix,iy); puts(avion_11);
                    gotoxy(ix,iy+1); puts(avion_12);
                    gotoxy(ix,iy+2); puts(avion_13);
                }
            break;

            case DERECHA :
                if(ix < 118 ){
                    gotoxy(ix,iy); puts(borrar_avion);
                    gotoxy(ix,iy+1); puts(borrar_avion);
                    gotoxy(ix,iy+2); puts(borrar_avion);

                    ix += 2; //Lo mismo que arriba pero a la derecha 

                    gotoxy(ix,iy); puts(avion_11);
                    gotoxy(ix,iy+1); puts(avion_12);
                    gotoxy(ix,iy+2); puts(avion_13);
                }
            break;
        }//Fin del switch.
    }//Fin del if.


    //Rutina de golpes para los asteroides.

    /*la formula es: Si "X" es mayor que las que coordenadas de la nave y "X" es menor que las coordenadas
    de la nave + 7 (esto lo hace para que detecte cuando golpee la nave) y "Y" es igual la nave menos 1. Entonces
    cuando golpee esas coordenadas esa parte de la nave desapacera. Esto se tienen que hacer con todos
    los asteroides.*/

    if ( (x > ix && x < ix + 7 && y == iy - 1) || (xx > ix && xx < ix + 7 && yy == iy - 1)
    || (x1 > ix && x1 < ix + 7 && y1 == iy - 1)|| (x2 > ix && x2 < ix + 7 && y2 == iy - 1)
    || (x3 > ix && x3 < ix + 7 && y3 == iy - 1)|| (x4 > ix && x4 < ix + 7 && y4 == iy - 1)
	|| (x5 > ix && x5 < ix + 7 && y5 == iy - 1)|| (x6 > ix && x6 < ix + 7 && y6 == iy - 1)
	|| (x7 > ix && x7 < ix + 7 && y7 == iy - 1)|| (x8 > ix && x8 < ix + 7 && y8 == iy - 1)){

        Corazones --;
        Barra_de_Salud(Corazones);
        printf ("\a"); //Este comando genera un sonido cada vez que un asteroide impacta sobre la nave.
    }

    gotoxy(ix,iy); puts(avion_11);
    gotoxy(ix,iy+1); puts(avion_12);
    gotoxy(ix,iy+2); puts(avion_13);

    if(Corazones == 0){  //Tambien los puedes escribir(!Corazones).
        Num_vidas --;
        Vidas(Num_vidas);
        Explosion();
        Corazones = 3;
        Barra_de_Salud(Corazones);
    }

    //Rutina para cambio de nivel.
    if(!condicion){
    repeticion++;
    condicion = true;
    }

    if(repeticion == 20){
        nivel++;
        gotoxy(55,1); printf("NIVEL %i",nivel);
        
        gotoxy(ix,iy); puts(borrar_avion);
        gotoxy(ix,iy+1); puts(borrar_avion);
        gotoxy(ix,iy+2); puts(borrar_avion);
        
        iy -=1;
        
        gotoxy(ix,iy); puts(avion_11);
        gotoxy(ix,iy+1); puts(avion_12);
        gotoxy(ix,iy+2); puts(avion_13);
        
        repeticion = 0;
    }

    //Esto es para que practicamente los asteroides vayan cayendo a lo largo de la pantalla.
    y++; yy++; y1++; y2++; y3++; y4++; y5++; y6++; y7++; y8++;

    if(Num_vidas == 0){
		gotoxy(39, 14);
        printf("-Presione A para reiniciar la partida.");
        gotoxy(47, 15);
        printf("-Presione ESC para salir.");
        Reiniciar_Nivel(Num_vidas, Corazones, ix, iy, nivel, repeticion);
    }
}