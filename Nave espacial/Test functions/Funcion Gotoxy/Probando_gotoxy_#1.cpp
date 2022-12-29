#include<iostream>
#include<conio.h>
#include<windows.h>
#include<stdio.h>

void gotoxy(int x,int y){
     HANDLE hcon;
     hcon = GetStdHandle(STD_OUTPUT_HANDLE);
     COORD dwPos;
     dwPos.X = x;
     dwPos.Y= y;
     SetConsoleCursorPosition(hcon,dwPos);
}

int main(){
gotoxy(2,1);
printf("Vidas 5");

gotoxy(110,1);
printf(" ");
gotoxy(111,1);
printf(" ");
gotoxy(112,1);
printf(" ");

     for(int i = 0; i > 0; ++i){
          gotoxy(110+i,1);
          printf("*");
          gotoxy(111+i,1);
          printf("*");
          gotoxy(112+i,1);
          printf("*");
     }
return 0;
}