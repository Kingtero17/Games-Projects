#include<iostream>
#include<conio.h>
#include<string.h>

//Declarando funcion.
void PintarAvion(int x);

//Cadena de caracteres.
char avion_11[]={' ',' ',' ','*',' ',' ',' ',0};
char avion_12[]={' ','|','*','*','*','|',' ',0};   //Nave espacial.
char avion_13[]={'*','*',' ','*',' ','*','*',0};

char CampoDeMovimientox[]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                           ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                           ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                           ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                           ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
                           ' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
0};

char Moversex[_MEMORYFWD_H]="";

int main(){
   char tecla;
   int posicion = 50;
   while(true){
      PintarAvion(posicion);
      tecla = getch();
      if(tecla == 'a')posicion -= 2;
      if(tecla == 'd')posicion += 2;
      system("cls");
   }
   getch();
}

void PintarAvion(int x){
   strcpy(Moversex, CampoDeMovimientox);
   Moversex[x]=0;

   printf(Moversex);puts(avion_11);
   printf(Moversex);puts(avion_12);
   printf(Moversex);puts(avion_13);
}