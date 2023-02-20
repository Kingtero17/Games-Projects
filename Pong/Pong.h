#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include "Interfaz.h"

//Definiendo teclas para el movimiento.
#define ARRIBA		72
#define ABAJO		80
#define ESC			27

//Inicializando Puntajes y Posicion del Jugador A. 
int Puntaje_1 = 0;
int Puntaje_2 = 0;
int _x = 62;
int _y = 14;

Interfaz I;


//Declarando clase Jugador.
class Jugador{
	private:
		int x, y;

	public:
		Jugador(int _x, int _y);	//Constructor.
		void Pintar() const;
		void Borrar() const;
		void MoverA(char &tecla);
		void MoverB(char &tecla);
		void Mover_cpu(int _x, int _y, int _dx);
		void Y(int _y){y += _y;};
		int Ry(){return y;};
		int Rx(){return x;};
};

//Declarando clase Pelota.
class Pelota{
	private:
		int x, y;
		int dx, dy;

	public:
		Pelota(int _x, int _y, int _dx, int _dy);	//Constructor.
		void Pintar() const;
		void Borrar() const;
		void Mover(Jugador A, Jugador B);
		void Asistencia(int _x, int _y){x = _x;y = _y;};
		void Puntuacion(int &Puntaje_1, int &Puntaje_2);
		bool Game_over(int &Puntaje_1, int &Puntaje_2);
		void Reiniciar_partida(int &Puntaje_1, int &Puntaje_2, int &_x, int &_y);
		int Px(){return x;};
		int Py(){return y;};
		int Dx(){return dx;};
};


//Definiendo metodos clase Jugador.
Jugador::Jugador(int _x, int _y): x(_x), y(_y){}	//Inicializando directamente los miembros privados.

//Pintar Jugador.
void Jugador::Pintar() const{
	I.gotoxy(x, y-1);printf("%c", 219);
	I.gotoxy(x, y  );printf("%c", 219);
	I.gotoxy(x, y+1);printf("%c", 219);
}

//Borrar Jugador.
void Jugador::Borrar() const{
	I.gotoxy(x, y-1);printf(" ");
	I.gotoxy(x, y  );printf(" ");
	I.gotoxy(x, y+1);printf(" ");
}

//MoverA Jugador1.
void Jugador::MoverA(char &tecla){
	if(kbhit()){
		tecla = getch();
		switch (tecla){
			//Casos minusculas.
			case 'w':	//Arriba.
				if(Ry() > 4){
					Y(-1);
				}
			break;

			case 's':	//Abajo.
				if(Ry() < 26){
					Y(+1);
				}
			break;
			//Fin casos minusculas.

			//Casos mayusculas.
			case 'W':	//Arriba.
				if(Ry() > 4){
					Y(-1);
				}
			break;

			case 'S':	//Abajo.
				if(Ry() < 26){
					Y(+1);
				}
			break;
			//Fin casos mayusculas.
		}
	}
}

//MoverB Jugador2.
void Jugador::MoverB(char &tecla){
	if(kbhit()){
		tecla = getch();
		switch (tecla){
			case ARRIBA:	//Caso arriba.
				if(Ry() > 4){
					Y(-1);
				}
			break;

			case ABAJO:		//Caso abajo.
				if(Ry() < 26){
					Y(+1);
				}
			break;
		}
	}
}

//Mover_cpu Jugador.
void Jugador::Mover_cpu(int _x, int _y, int _dx){
	if(_x > 70 && _dx > 0){
		Borrar();
		if(_y > y && y+1 < 27){
			y++; Pintar();
		}
		if(_y < y && y-1 > 3){
			y--; Pintar();
		}
	}
}

//Definiendo metodos clase Pelota.
Pelota::Pelota(int _x, int _y, int _dx, int _dy): x(_x), y(_y), dx(_dx), dy(_dy){}	//Inicializando directamente los miembros privados.

//Pintar Pelota.
void Pelota::Pintar() const{
	I.gotoxy(x, y);printf("%c", 184);
}

//Borrar Pelota.
void Pelota::Borrar() const{
	I.gotoxy(x, y);printf(" ");
}

//Mover Pelota.
void Pelota::Mover(Jugador A, Jugador B){
	Borrar();
	x+= dx;
	y+= dy;
	Pintar();

	if(y + dy == 2 || y + dy == 28){
		Borrar();
		dy = -dy;
		Pintar();
	}

	if( x + dx == A.Rx() && y >= A.Ry()-1 && y <= A.Ry()+1){dx = -dx;}
	if( x + dx == B.Rx() && y >= B.Ry()-1 && y <= B.Ry()+1){dx = -dx;}
}

//Puntuacion Pelota.
void Pelota::Puntuacion(int &Puntaje_1, int &Puntaje_2){
	//Puntuacion 1.
	I.gotoxy(40, 1);printf("%d", Puntaje_1);
	if(x + dx == 116){
		Borrar();
		dx = -dx;
		Asistencia(62, 14);
		Pintar();
		Puntaje_1 += 1;
		I.gotoxy(40, 1);printf("%d", Puntaje_1);
	}

	//Puntuacion 2.
	I.gotoxy(78, 1);printf("%d", Puntaje_2);
	if(x + dx == 3){
		Borrar();
		dx = -dx;
		Asistencia(62, 14);
		Pintar();
		Puntaje_2 += 1;
		I.gotoxy(78, 1);printf("%d", Puntaje_2);
	}
}

//Reiniciar_partida Pelota.
void Pelota::Reiniciar_partida(int &Puntaje_1, int &Puntaje_2, int &_x, int &_y){
	Puntaje_1 = 0;
	Puntaje_2 = 0;
	x = _x;
	y = _y;
	_x = 62;
	_y = 14;
}

//Game_over Pelota.
bool Pelota::Game_over(int &Puntaje_1, int &Puntaje_2){
	if(Puntaje_1 == 3 || Puntaje_2 == 3){
		//Jugador 1 Win.
		if(Puntaje_1 == 3){
		I.gotoxy(53,3);printf("JUGADOR 1 WIN!");
		}
		//Jugador 2 Win.
		if(Puntaje_2 == 3){
		I.gotoxy(53,3);printf("JUGADOR 2 WIN!");
		}
		return true;
	}
	return false;
}