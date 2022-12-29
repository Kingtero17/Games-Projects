#include<iostream>
#include<windows.h>

int main(){
    //Arreglos de caracteres.
    char avion_11[]={' ',' ',' ','*',' ',' ',' ',0};    //El "0" al final le indica al programa que hasta allí hay caracteres a imprimir.
    char avion_12[]={' ','|','*','*','*','|',' ',0};
    char avion_13[]={'*','*',' ','*',' ','*','*',0};

    //Imprimimos los arreglos de caracteres con la funcion "puts" de la biblioteca <windows.h>
    puts(avion_11);
    puts(avion_12);
    puts(avion_13);

    //Funcion "Sleep" para que el programa se pause o se detenga 3 mil milisegundos (3 segundos) y podamos apreciar la nave.
    Sleep(3000);
}