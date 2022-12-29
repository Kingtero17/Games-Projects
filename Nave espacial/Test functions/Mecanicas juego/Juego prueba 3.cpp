#include<iostream>
#include<conio.h>
#include<windows.h>

//Definiendo teclas izquierda y derecha para mover la nave espacial.
#define IZQUIERDA 75
#define DERECHA 77

//Declarando funciones.
void Vidas();
void Explosion(void);
void Jugar(void);
void Teclear(void);

char avion_11[]={' ',' ',' ','*',' ',' ',' ',0};        //Nave Espacial.
char avion_12[]={' ','|','*','*','*','|',' ',0};
char avion_13[]={'*','*',' ','*',' ','*','*',0};

char explosion_e1[]={' ',' ','*','*',' ',' ',' ',0};    //Explosion de la Nave#1.
char explosion_e2[]={' ','*','*','*','*',' ',' ',0};
char explosion_e3[]={' ',' ','*','*',' ',' ',' ',0};

char explosion_e11[]={'*',' ','*','*',' ','*',' ',0};    //Explosion de la Nave#2.
char explosion_e22[]={' ','*','*','*','*',' ',' ',0};
char explosion_e33[]={'*',' ','*','*',' ','*',' ',0};

char borrar_avion[]={' ',' ',' ',' ',' ',' ',' ',0};    //Borrar la Nave espacial.


//Coordenadas, corazones y vidas iniciales de la nave.
int ix = 40;
int iy = 19;
int Num_vidas = 3;
int Corazones = 3;

//Coordenadas de los asteroides.
int y = 8, x = 12;
int yy = 12, xx = 17;
int x1 = 58, y1 = 44;
int x2 = 70, y2 = 9;
int x3 = 63, y3 = 14;

//Funcion gotoxy.
void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

/*
Instrucciones:
gotoxy(Coordenadas(eje x, eje y)); 
printf("Colocar aqui lo que quieras imprimir");
*/

int main(){
    Vidas();
    Explosion();
    Jugar();
    return 0;
}

//Definiendo funciones.
void Vidas(){
    gotoxy(2,1);printf("Vidas 5");

    for(int v = 0; v < 3; v++){
        gotoxy(110,1);printf("%c", 3);
        gotoxy(111,1);printf("%c", 3);
        gotoxy(112,1);printf("%c", 3);
    }
}

void Explosion(void){
    //Primera Explosion.
    gotoxy(ix,iy); puts(explosion_e1);
    gotoxy(ix,iy+1); puts(explosion_e2);
    gotoxy(ix,iy+2); puts(explosion_e3);

    Sleep(380); //Funcion "Sleep" detiene el programa 380 milisegundos para asi poder apreciar la explosion.
    
    //Segunda Explosion
    gotoxy(ix,iy); puts(explosion_e11);
    gotoxy(ix,iy+1); puts(explosion_e22);
    gotoxy(ix,iy+2); puts(explosion_e33);

    Sleep(380);

    //Imprimimos la nave.
    gotoxy(ix,iy); puts(avion_11);
    gotoxy(ix,iy+1); puts(avion_12);
    gotoxy(ix,iy+2); puts(avion_13);
}

/*Apartir de esta parte del progrma, haremos todas
las mecanicas de los asteroides, de los niveles, 
el movimiento de la nave, etc.*/

void Jugar(void){
    //Mecanicas de los asteriodes.
    int i = 1000;
    do{
        //El 0 es la imagen que el programa proyectara de los asteroides.
        gotoxy(x,y);   printf("%c", 169);
        gotoxy(xx,yy); printf("%c", 169);
        gotoxy(x1,y1); printf("%c", 169);
        gotoxy(x2,y2); printf("%c", 169);
        gotoxy(x3,y3); printf("%c", 169);

        Sleep(50);

        //Parar borrar los asteroides despues de cierto tiempo.
        gotoxy(x,y);   printf(" ");
        gotoxy(xx,yy); printf(" ");
        gotoxy(x1,y1); printf(" ");
        gotoxy(x2,y2); printf(" ");
        gotoxy(x3,y3); printf(" ");

        /*Si "y" (Eje "y" del asteroide) es mayor que 20, entoces "y" pasara a valer 4 (El asteroide subira)
        y "x" sera igual a un numero pseudo-random con limite de 110 y le sumamos 6 (El "6+" funciona para
        que el asteroide no se genere tan cerca al lado izquierdo de la pantalla y para que la posicion del
        asteroide sea un poco mas random).*/

        //Procedimiento con todos los asteroides.
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

        //Mover nave espacial.

        /*Funcion "kbhit" indica que si se detecta una tecla,
        el programa procese esa tecla y no se detenga el programa.
        Con "tecla = getch" le indicamos al programa esté atento para
        recibir una tecla del teclado y que dicha tecla (El valor de la misma)
        se la pase a la variable tecla.*/

        if(kbhit()){
            unsigned char tecla = getch();
                switch(tecla){
                    case IZQUIERDA:
                        if(ix > 4){
                            gotoxy(ix,iy);   puts(borrar_avion);
                            gotoxy(ix,iy+1); puts(borrar_avion);
                            gotoxy(ix,iy+2); puts(borrar_avion);

                            ix -= 2;    //Despues de borrar la nave, le restamos 2 a su posicion actual.

                            gotoxy(ix,iy);   puts(avion_11);
                            gotoxy(ix,iy+1); puts(avion_12);
                            gotoxy(ix,iy+2); puts(avion_13);
                        }
                    break;

                    /*Si detecta que algunos de los dos casos (IZQUIERDA o DERECHA) y si la nave nave se encuentra entre los limites
                    establecidos, entonces borraremos la nave, le restaremos o sumaremos a su posicion (Dependiendo el caso) y 
                    al final volveremos a imprimir la misma. Para crear la sensacion de movimiento.*/

                    case DERECHA :
                        if(ix < 118){
                            gotoxy(ix,iy);   puts(borrar_avion);
                            gotoxy(ix,iy+1); puts(borrar_avion);
                            gotoxy(ix,iy+2); puts(borrar_avion);

                            ix += 2;    //ix = ix +2; 'o' ix += 2;

                            gotoxy(ix,iy);   puts(avion_11);
                            gotoxy(ix,iy+1); puts(avion_12);
                            gotoxy(ix,iy+2); puts(avion_13); 
                        }
                    break;
                }//Fin del switch
        }//Fin del if
        //Aumentamos la posicion en "y" de los asteroides para que vayan cayendo.
        y++; yy++; y1++; y2++; y3++;
        i--;
    }while(i > 0);
}