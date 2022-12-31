#include<iostream>
#include<windows.h>

//Definiendo la flecha izquierda y derecha del teclado.
#define IZQUIERDA 75
#define DERECHA 77

//Corazones y vidas iniciales de la nave.
int Num_vidas = 3;
int Corazones = 3;

//Coordenadas de los asteroides.
int y = 8,   x = 12;
int yy = 12, xx = 17;
int x1 = 58, y1 = 44;
int x2 = 70, y2 = 9;
int x3 = 63, y3 = 14;

//Declarando funciones
void Jugar(void);
void Vidas(void);

//Funcion gotoxy.
void gotoxy(int x,int y){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    SetConsoleCursorPosition(hcon,dwPos);
}

/*  Instrucciones:
    gotoxy(Coordenadas(eje x, eje y));
    printf("Colocar aqui lo que quieras imprimir");
*/

int main(){
    Jugar();
    Vidas();
    return 0;
}

void Vidas(void){
    gotoxy(2,1); printf("Vidas 5");

    gotoxy(110,1);printf("%c", 3);
    gotoxy(111,1);printf("%c", 3);
    gotoxy(112,1);printf("%c", 3);
}

void Jugar(void){
    //Mecanicas de los asteriodes.
    int i = 100;
    do{
        gotoxy(x,y);  printf("*");
        gotoxy(xx,yy);printf("*");
        gotoxy(x1,y1);printf("*");
        gotoxy(x2,y2);printf("*");
        gotoxy(x3,y3);printf("*");

        Sleep(30);

        //Para borrar a los asteroides despues de cierto tiempo.
        gotoxy(x,y);  printf(" ");
        gotoxy(xx,yy);printf(" ");
        gotoxy(x1,y1);printf(" ");
        gotoxy(x2,y2);printf(" ");
        gotoxy(x3,y3);printf(" ");

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

        //Aumentamos la posicion en "y" de los asteroides para que vayan cayendo.
        y++; yy++; y1++; y2++; y3++;
        i--;
    }while(i > 0);
}