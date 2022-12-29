#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>

char avion_11[]={' ',' ',' ','*',' ',' ',' ',0};       //Dibujo de la Nave Espacial.
char avion_12[]={' ','|','*','*','*','|',' ',0};
char avion_13[]={'*','*',' ','*',' ','*','*',0};

char explosion_11[]={' ',' ','*','*',' ',' ',' ',0};   //Dibujo de la explosion de la Nave #1.
char explosion_12[]={' ','*','*','*','*',' ',' ',0};
char explosion_13[]={' ',' ','*','*',' ',' ',' ',0};

char explosion_r1[]={'*',' ','*','*',' ','*',' ',0};   //Dibujo de la explosion de la Nave#2.
char explosion_r2[]={' ','*','*','*','*',' ',' ',0};
char explosion_r3[]={'*',' ','*','*',' ','*',' ',0};

char borrar_avion[]={' ',' ',' ',' ',' ',' ',' ',0};   //Es para borrar la Nave Espacial.

void gotoxy(int x,int y){
     HANDLE hcon;
     hcon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y= y;
     SetConsoleCursorPosition(hcon,dwPos);
}

int main(){
puts(avion_11);
puts(avion_12);
puts(avion_13);

gotoxy(2,1);
printf("Vidas 5");
printf("\n");
Sleep(3000);
return 0;
}

