#include<iostream>
#include<windows.h>

//Funcion gotoxy.
//La funcion gotoxy funciona para posicionarnos en las coordenadas "x" y "y" que le indiquemos, en la consola.

void gotoxy(int x,int y){                       //Necesitamos pasarle dos parametros enteros ("x" y "y").
    HANDLE hCon;                                //Llamamos a un HANDLE (Un identificador de un objeto o un recurso) y le damos un nombre (por tradicion "hcon").
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);     //Igualamos a el indificador a GetStdHandle (recupera al identificador al dispositivo estandar que se pasa como parametro; hay 3 parametros: de salida estandar, de entrada estandar y de error estandar), en este caso, salida estandar.
    COORD dwPos;                                //Creamos una estructura de COORD de nombre "dwPos" por tradicion.
    dwPos.X = x;                                //Le asignamos los valores que tenemos como parametros de la funcion a la estructura, tanto en X como en Y.
    dwPos.Y = y;
    SetConsoleCursorPosition(hCon,dwPos);       //la funcion SetConsoleCursorPosition requiere de dos parametros(el identificador, estructura de coordenadas definidas en la libreria "windows.h").
}

int main(){
gotoxy(1,0);printf("Vidas 5");

//Imprimiendo Corazones.
for(int i = 0; i < 3; i++){
    gotoxy(110+i,0);printf("%c", 3);
    gotoxy(110+i,0);printf("%c", 3);
    gotoxy(110+i,0);printf("%c", 3);
}
return 0;
}
