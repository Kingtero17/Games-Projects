#include<iostream>
#include<conio.h>
#include<string.h>

using namespace std;

//Declarando funcion.
void PintarAvion(int x);

//Nave espacial.
char avion_11[]={' ',' ',' ','*',' ',' ',' ',0};
char avion_12[]={' ','|','*','*','*','|',' ',0};
char avion_13[]={'*','*',' ','*',' ','*','*',0};

char CampoDeMovimientox []={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                            ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                            ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                            ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                            ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
0};


char Moversex [_MEMORYFWD_H]="";

int main(){
    PintarAvion(80);

    //Getch de la libreria "conio.h", le indica al programa que se pause hasta que se presione una tecla.
    getch();
    return 0;
}

void PintarAvion(int x){
    //La funcion strcpy tiene dos parametros(Cadena de destino, Cadena que se copiara en el destino).
    strcpy(Moversex, CampoDeMovimientox);

    //Campo de movimiento.
    Moversex[x] = 0;

    /*Mandamos a imprimir primero los espacios indicados y depues la cadena de caracteres de la nave espacial*/
    printf(Moversex); puts(avion_11);
    printf(Moversex); puts(avion_12);
    printf(Moversex); puts(avion_13);
}