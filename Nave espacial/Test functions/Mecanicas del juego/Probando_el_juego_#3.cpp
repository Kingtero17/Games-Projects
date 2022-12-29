#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
//La funcion gotoxy la creamos con la libreria windows.
//Tener en cuenta que la pantalla por defecto de la consola tiene 119 espacios en el eje "Y".


//Teclas de izquierda y derecha para mover la nave espacial.
#define IZQUIERDA 75
#define DERECHA 77

//Declarando funciones.
void Vidas(int vi);
void Explosion(void);
void Jugar(void);
void Teclear(void);

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
int ix = 40;
int iy = 19;

//Estas son las coordenadas de los asteroides.
int y = 8, x = 12;
int yy = 12, xx = 17;
int x1 = 58, y1 = 44;
int x2 = 70, y2 = 9;
int x3 = 63, y3 = 14;


int i, v;
//Estas variables nos diran en que nivel estamos.
int repeticion = 0, nivel = 1;
//Variable de tipo buleano.
bool condicion = false;


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

int main(){
    Vidas(3);
    Explosion();
    Jugar();
    return 0;
}

void Vidas(int vi){
    gotoxy(2,1);
    printf("Vidas 5");

    gotoxy(110,1);
    printf(" ");
    gotoxy(111,1);
    printf(" ");
    gotoxy(112,1);
    printf(" ");

    int n;
    
    for(int v = 0; v < n; v++){
    gotoxy(110+v,1);
    printf("*");
    gotoxy(111+v,1);
    printf("*");
    gotoxy(112+v,1);
    printf("*");
    }
}


void Explosion(void){
    //Primero Explosion.

    /*Le colocamo un 1+ y 2+ para que se pueda observar la animación de forma
    correcta, sino se verian todas las explosiones en una misma linea.*/

    gotoxy(ix,iy); puts(explosion_11);
    gotoxy(ix,iy+1); puts(explosion_12);
    gotoxy(ix,iy+2); puts(explosion_13);

    Sleep(380); //La funcion "Sleep" detiene el programa 380 milisegundos para asi poder apreciar la explosion.
    
    //Segunda Explosion
    gotoxy(ix,iy); puts(explosion_r1);
    gotoxy(ix,iy+1); puts(explosion_r2);
    gotoxy(ix,iy+2); puts(explosion_r3);

    Sleep(380);

    //Tambien hay que colocar el dibujo de la nave.
    gotoxy(ix,iy); puts(avion_11);
    gotoxy(ix,iy+1); puts(avion_12);
    gotoxy(ix,iy+2); puts(avion_13);
    Sleep(380);
}

/*En esta parte del progrma, haremos todas las mecanicas de los asteroides,
de los niveles, el movimiento de la nave, etc.*/

void Jugar(void){
    //Mecanicas de los asteriodes.
    int i = 100;
    do{
        //El 0 es la imagen que el programa proyectara de los asteroides.
        gotoxy(x,y); printf ("0");
        gotoxy(xx,yy); printf ("0");
        gotoxy(x1,y1); printf ("0");
        gotoxy(x2,y2); printf ("0");
        gotoxy(x3,y3); printf ("0");

        Sleep(70);

        gotoxy(x,y); printf (" ");      //Esto es para que el programa borre los asteroides despues de cierto tiempo.
        gotoxy(xx,yy); printf (" ");
        gotoxy(x1,y1); printf (" ");
        gotoxy(x2,y2); printf (" ");
        gotoxy(x3,y3); printf (" ");

    /*Si "Y" es mayor que 20, entoces "Y" (en este caso la posicion "Y" del asteroide) pasara a valer 4
    en la posicion y "X" es igual a un numero random que no pase de 110 +6 ( El 6+ es para que el
    asteroide no se genere tan cerca al lado izquierdo de la pantalla).*/

    //Hay que hacer el mismo procedimiento con todos los asteroides.

        if(y > 20){
            y = 4;
            x = (rand() % 110) + 6;
        }

        if(yy > 20){
            yy = 4;
            xx = (rand() % 110) + 6;
        }

        if(y1 > 20){
            y1 = 4;
            x1 = (rand() % 110) + 6;
        }

        if(y2 > 20){
            y2 = 4;
            x2 = (rand() % 110) + 6;
        }

        if(y3 > 20){
            y3 = 4;
            x3 = (rand() % 110) + 6;
        }

        //Mecanicas para mover la nave espacial.

    /*Se escribe "kbhit" para indicar que si se detecta que sea presionado una tecla, el programa procese
    esa tecla y no se detenga el programa.
    Lo que estamos haciendo con "tecla = getch"  es que el programa esté atento para recibir una tecla del teclado.*/

        if(kbhit()){
            unsigned char tecla = getch();
                switch(tecla){
                    case IZQUIERDA:
                        if(ix > 4){
                            gotoxy(ix,iy); puts(borrar_avion);
                            gotoxy(ix,iy+1); puts(borrar_avion);
                            gotoxy(ix,iy+2); puts(borrar_avion);

                            ix -= 2;    //Es para que borre dos espacios de la nave y de la sensacion de que se mueve.

                            gotoxy(ix,iy); puts(avion_11);
                            gotoxy(ix,iy+1); puts(avion_12);
                            gotoxy(ix,iy+2); puts(avion_13);
                        }
                    break;

                    /* El break lo que hace es detener la ejecución de una parte del programa,
                    para que en tal caso de que quieras hacer otro "case", no te errores porque te tomaria
                    dos casos como uno (como un todo).*/

                    case DERECHA :
                        if(ix < 118 ){
                            gotoxy(ix,iy); puts(borrar_avion);
                            gotoxy(ix,iy+1); puts(borrar_avion);
                            gotoxy(ix,iy+2); puts(borrar_avion);

                            ix += 2;    //ix = ix +2; lo mismo que arriba

                            gotoxy(ix,iy); puts(avion_11);
                            gotoxy(ix,iy+1); puts(avion_12);
                            gotoxy(ix,iy+2); puts(avion_13); 
                        }
                    break;
                }//Fin del switch
        }//Fin del if
        //Esto es para que los asteroides vayan cayendo a lo largo de la pantalla.
        y++; yy++; y1++; y2++; y3++;
        i--;
    }while(i > 0);
}