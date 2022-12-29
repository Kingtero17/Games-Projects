#include<iostream>
#include<stdio.h>
#include<time.h>

//Recuerda siemepre declarar los prototipos de las funciones arriba de la funcion principal(main).
void Juego(char c [3][3]);
void Intro_Primera(char c [3][3]);
void Tablero(char c [3][3]);
void Intro_Yo(char c[3][3]);
void Intro_Cpu(char c[3][3]);
int Ganador(char c [3][3]);

int main(){
	char c [3][3];
	Juego(c);	//Llama a todas las funciones fundamentales y hace un refresco de pantalla.
    system("pause");
	return 0;
}

void Juego(char c [3][3]){	//Aqui se coloca (c), en vez de (char c [3][3]) porque los parametros de esta funcion ya los pide desde un principio.
	int i = 0;
	int j;
	Intro_Primera(c);
	
	do{
		system("cls");
		Tablero(c);
		if(i % 2 == 0){
			Intro_Yo(c);
		}
		else{
			Intro_Cpu(c);
		}
		j = Ganador(c);
		i++;
	}while(i <= 9 && j == 2);

	system("cls");
	Tablero(c);

	if(j == 0){
		printf("Enhorabuena crack!! Has ganado!\n\n");
	}
	else if(j == 1){
		printf("Ohh noo! Perdiste puta\n\n");
	}
	else{
		printf("Has empatado! Intetanlo de nuevo...\n\n");
	}
}


void Intro_Primera(char c [3][3]){
	int i, j;
	char aux;
	aux = '1';	//Se pone entre dos apostrofes para que el programa detecte el numero 1 como un caracter y no como un valor numerico.
	for(i = 0; i < 3; i++){
		for(j = 0 ; j < 3; j++){
			c[i][j] = aux++;
		}
	}
}

/*Ya declarada una variable aux, le decimos al programa que la matriz es igual a esa variable, la cual ya le dimos un valor, el cual es 1.
Y a parte de eso, que la variable aux aumentara de 1 en 1 hasta lo maximo de la matriz; asi rellenara todos los huecos del 1 al 9.*/

/*Para hacer el tablero, le decimos al programa que si se cumplen unos parametros imprima "|" y sino los cumple que no lo haga;
esto para retratar la imagen como de un tablero y para las lineas horizontales tambien se sigue el miosmo procedimineto.*/


void Tablero(char c [3][3]){
	int i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(j < 2){
				printf(" %c |", c [i][j]);
			
			}
			else{
				printf(" %c ", c [i][j]);
			}
		}
		if(i < 2){
			printf("\n-----------\n");
		}
	}
	printf("\n\n");
}

void Intro_Yo(char c [3][3]){
	int i, j, k;
	char aux;
	
	/*En esta seccion del programa le estamos diciendo que ingresemos un numero entre el 1 y el 9.
	Despues de ingresar ese numero el programa va a ir a los casos correspondientes de cada numero a verificar si ese numero
	ya a sido ingresado; en el caso de que el numero no ha sido ingresado se colocara una "X" en el lugar del numero ingresado, en el caso
	de que el numero si ha ingresado el programa te dira: "La casilla esta ocupada! Intentalo con otro numero!!".*/
	
	do{
		do{
			printf("Coloca una ficha: "); 
			fflush(stdin);
			scanf("%c", &aux);
		}while(aux < '1' || aux > '9'); //Aqui es entre el caracter 1 y entre el caracter 9... No son numeros son caracteres
		
		k = 0 ;
		
		switch(aux){
			case'1':{
				i = 0;
				j = 0;
				if(c [i][j] == 'X' || c [i][j] == 'O'){
					k = 1;
					printf("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;
			}
			case'2':{
				i = 0;
				j = 1;
				if(c [i][j] == 'X' || c [i][j] == 'O'){
					k = 1;
					printf("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;
			}
			case'3':{
				i = 0;
				j = 2;
				if(c [i][j] == 'X' || c [i][j] == 'O'){
					k = 1;
					printf("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;
			}
			case'4':{
				i = 1;
				j = 0;
				if(c [i][j] == 'X' || c [i][j] == 'O'){
					k = 1;
					printf("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;
			}
			case'5':{
				i = 1;
				j = 1;
				if(c [i][j] == 'X' || c [i][j] == 'O'){
					k = 1;
					printf("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;
			}
			case'6':{
				i = 1;
				j = 2;
				if(c [i][j] == 'X' || c [i][j] == 'O'){
					k = 1;
					printf("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;
			}
			case'7':{
				i = 2;
				j = 0;
				if(c [i][j] == 'X' || c [i][j] == 'O'){
					k = 1;
					printf("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;
			}
			case'8':{
				i = 2;
				j = 1;
				if(c [i][j] == 'X' || c [i][j] == 'O'){
					k = 1;
					printf("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;
			}
			case'9':{
				i = 2;
				j = 2;
				if(c [i][j] == 'X' || c [i][j] == 'O'){
					k = 1;
					printf("La casilla esta ocupada! Intentalo con otro numero!!\n\n");
				}
				break;
			}
		}
	}while(k == 1);

	c [i][j] = 'X';
}

void Intro_Cpu(char c [3][3]){
	int i, j, k;
	
	/*En esta seccion del programa le estamos diciendo que elija un nuemro random entre 0 y 2 en cada lado de la matriz.
	Si ese numero es igual a una 'X' o a 'O' entonces el bucle se volvera a ejecutar hasta que consiga un lugar que no este ocupado
	cuando consiga un lugar que no este ocupado colocara una 'O'.*/
	
	do{
		srand(time(0));
		i = (rand () %3);
		j = (rand () %3);
		k = 0;
		
		if(c [i][j] == 'X'|| c [i][j] == 'O'){
			k = 1;
		}
	}while(k == 1);
	
	c [i][j] = 'O';
}

int Ganador(char c [3][3]){
	if(c [0][0] == 'X' || c [0][0] == 'O'){	//Punto 1.
		if(c [0][0] == c [0][1] && c [0][0] == c [0][2]){
			if(c [0][0] == 'X'){
				return 0;	//He ganado.
			}
			else{
				return 1;	//He perdido.
			}
		}
		if(c [0][0] == c[1][0] && c[0][0] == c[2][0]){
			if(c [0][0] == 'X'){
				return 0;	//He ganado.
			}
			else{
				return 1;	//He perdido.
			}
		}
	}
	if(c [1][1] == 'X' || c [1][1] == 'O'){	//Punto 5.
		if(c [1][1] == c [0][0] && c [1][1] == c [2][2]){
			if(c [1][1] == 'X'){
				return 0;	//He ganado.
			}
			else{
				return 1;	//He perdido.
			}
		}
		if(c [1][1] == c [1][0] && c [1][1] == c [1][2]){
			if(c [1][1] == 'X'){
				return 0;	//He ganado.
			}
			else{
				return 1;	//He perdido.
			}
		}
		if(c [1][1] == c [0][1] && c [1][1] == c [2][1]){
			if(c [1][1] == 'X'){
				return 0;	//He ganado.
			}
			else{
				return 1;	//He perdido.
			}
		}
		if(c [1][1] == c [2][0] && c [1][1] == c [0][2]){
			if(c [1][1] == 'X'){
				return 0;	//He ganado.
			}
			else{
				return 1;	//He perdido.
			}
		}
	}
	if(c [2][2] == 'X' || c [2][2] == 'O'){	//Punto 9.
		if(c [2][2] == c [2][0] && c [2][2] == c [2][1]){
			if(c [2][2] == 'X'){
				return 0;	//He ganado.
			}
				else{
					return 1;	//He perdido.
				}
		}
		if(c [2][2] == c [0][2] && c [2][2] == c [1][2]){
			if(c [2][2] == 'X'){
				return 0;	//He ganado.
			}
			else{
				return 1;	//He perdido.
			}
		}
	}
	return 2;
}
//Creado por Kingtero17.