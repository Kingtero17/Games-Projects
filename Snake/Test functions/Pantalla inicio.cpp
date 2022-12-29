#include <iostream>
#include <windows.h>
#include <conio.h>

int Cuerpo[200][2];

void gotoxy ( int x, int y){
	HANDLE hCon;
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	hCon = GetStdHandle( STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hCon,dwPos);

}

int main (){
	//Lineas Horizontales.
	for(int i = 2; i < 118; i++){
		gotoxy( i, 2); 
		printf("%c",205);		//Se coloca (%c,y aqui el numero en codigo ASCII). 
		gotoxy( i, 28); 
		printf("%c",205);
	}
	//Lineas Verticales.
	for(int i = 2; i < 29; i++){
		gotoxy( 2, i); 
		printf("%c",186);		//Se coloca (%c,y aqui el numero en codigo ASCII).
		gotoxy( 117, i); 
		printf("%c",186);
	}
    //Esquinas.
    gotoxy(2,2); printf ("%c",201);
    gotoxy(2,28); printf ("%c",200);
    gotoxy(117,2); printf ("%c",187);
    gotoxy(117,28); printf ("%c",188);
            
    //Cuerpo de la Serpiente.
            
	for (int j = 0; j < 3; j++){
		for (int i = 0; i < 2; i++ ){
		Cuerpo [j][i] = rand ( )%10; 
		}
	}

	for (int j = 0; j < 3; j++){
	gotoxy (Cuerpo [j][0], Cuerpo [j][1] );
	}
	system("pause");	//El system ("pause") nos sirve para que el programa se pause y no se cierre solo.
	return 0;
}


