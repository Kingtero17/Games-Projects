#include<iostream>
#include<conio.h>
#include<string.h>
#include<memory.h>

using namespace std;

#define ESPACIOS 75;

void PintarAvion(int x);

char avion_11[]={' ',' ',' ','*',' ',' ',' ',0};
char avion_12[]={' ','|','*','*','*','|',' ',0};
char avion_13[]={'*','*',' ','*',' ','*','*',0};

char CampoDeMovimientox []={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',0};

char Moversex [_MEMORYFWD_H]="";

int main(){
char tecla;
int a, d, horizontal=35;

do{
   PintarAvion(horizontal); 
   tecla= getch();
   if(tecla=='a')horizontal-=2;
   if(tecla=='d')horizontal+=2;
}while(1==1);

getch();
}

void PintarAvion(int x){
   strcpy(Moversex, CampoDeMovimientox);
   Moversex[x]=0;

   printf(Moversex); puts(avion_11);
   printf(Moversex); puts(avion_12);
   printf(Moversex); puts(avion_13);
}
