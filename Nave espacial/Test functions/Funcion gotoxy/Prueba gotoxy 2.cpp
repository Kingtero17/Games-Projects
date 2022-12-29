#include<iostream>
#include<windows.h>

char avion_11[]={' ',' ',' ','*',' ',' ',' ',0};        //Nave Espacial.
char avion_12[]={' ','|','*','*','*','|',' ',0};
char avion_13[]={'*','*',' ','*',' ','*','*',0};

char explosion_e1[]={' ',' ','*','*',' ',' ',' ',0};    //Explosion de la Nave#1.
char explosion_e2[]={' ','*','*','*','*',' ',' ',0};
char explosion_e3[]={' ',' ','*','*',' ',' ',' ',0};

char explosion_e11[]={'*',' ','*','*',' ','*',' ',0};    //Explosion de la Nave#2.
char explosion_e22[]={' ','*','*','*','*',' ',' ',0};
char explosion_e33[]={'*',' ','*','*',' ','*',' ',0};

char borrar_avion[]={' ',' ',' ',' ',' ',' ',' ',0};    //Borrar Nave Espacial.


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
    puts(avion_11);
    puts(avion_12);
    puts(avion_13);

    gotoxy(10,1);printf("Vidas 5");
    Sleep(3000);

    return 0;
}