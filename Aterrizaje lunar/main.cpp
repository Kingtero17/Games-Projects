#include <iostream>
#include <allegro.h>
#include <cmath>
#include <math.h>

void Rotar( float &X, float &Y, float Cx, float Cy, float Da);    //Solo referenciamos la "X y la Y" porque esa variables van a cambaiar. Y si nunca cambian crearia un problema en el programa
void Pintar_nave(float Cx, float Cy, BITMAP *buffer);
void Mover_nave(float &Cx, float &Cy, float &Vx, float &Vy);      //Necesitamos colocar el "&" antes de nuestras variables de la nave, para que as� los valores se modifiquen con cada accion
void Aceleracion(float Da, float &Vx, float &Vy);
void Pintar_fuego(float Da, float Cx, float Cy, BITMAP *buffer);
void Medidor_de_combustible(bool Gastar_combustible, float &Combustible, BITMAP *buffer);
void Pintar_nivel(int Num_nivel, BITMAP *buffer);
void Explosion(float Cx, float Cy,  BITMAP *buffer, int Num_nivel);
bool Gamer_over(float &Cx, float &Cy, float &Vx, float &Vy, int Num_nivel, float &Combustible, BITMAP *buffer);
bool Aterrizaje(float Cx, float Cy, float Vx, float Vy, BITMAP *buffer, int Num_nivel);
bool Choque_triangulo(float X1, float Y1, float X2, float Y2, float P1x, float P1y, float P2x, float P2y, int Tipo_triangulo);   //Necesitamos los datos del triangulo y de la pendiente para asi determinar si la nave a colisionado la nave
bool Choque_nave(int Num_nivel, float Cx, float Cy);
void Avanzar_de_nivel(float &Cx, float &Cy, float &Vx, float &Vy, int &Num_nivel, float &Combustible, BITMAP *buffer);
void Reiniciar_nivel(float &Cx, float &Cy, float &Vx, float &Vy, float &Combustible);

int main(){

   allegro_init();      //Esta es la funci�n pincipal de allegro
   install_keyboard();  //Esta funci�n es para que nuestro personaje se pueda mover
   set_color_depth(32); //En esta funci�n le indicamos al programa la cantatidad de bits que admitira
   set_gfx_mode(GFX_AUTODETECT_WINDOWED, 740, 500, 0, 0); //Esta funci�n define los par�metros en donde se proyectar� el juego, todas los dimensiones estan en pixeles (no en cent�metros)
   BITMAP *buffer = create_bitmap (740,500); //No entiendo esta funci�n

   float Cx, Cy;
   float Vx, Vy;
   Cx = 710;
   Cy = 100;
   Vy = -2 ;
    float Combustible = 100; //El 100 significa que el tanque de la nave esta lleno
   int Num_nivel = 1;

   /*Necesitamos hacer un ciclo que est� observando si se estan leyendo las teclas
   y que si detecta que se estan leyendo; que haga algo XD*/

   while( !key [KEY_ESC] && !Gamer_over(Cx, Cy, Vx, Vy, Num_nivel, Combustible, buffer)){

      bool Gastar_combustible = false;
      clear_to_color(buffer,0x000000 ); //Colocas el buffer, coma 0 por (x) el numero del color deseado
      Pintar_nivel(Num_nivel, buffer);
      Mover_nave(Cx, Cy, Vx, Vy);

      if(key[KEY_UP] && Combustible > 0){
         Aceleracion(0, Vx, Vy); //Cuando el angulo sea igual a 0, vamos a tener uanaceleracion hacia arriba
         Pintar_fuego(0, Cx, Cy, buffer);
         Gastar_combustible = true ;
      }

      if(key[KEY_RIGHT] && Combustible > 0){
         Aceleracion(-90, Vx, Vy ); //Cuando nosotros rotamos el angulo en el sentido de las agujas del reloj, el angulo se pone negativo y si es al contrario a las agujas del reloj es positivo
         Pintar_fuego(-90, Cx, Cy, buffer);
         Gastar_combustible = true ;
      }

      if(key[KEY_LEFT] && Combustible > 0){
         Aceleracion(90, Vx, Vy ); //Primero van los grados y despues las posciones. Todo esto llamando a la funcion Aceleracion
         Pintar_fuego(90, Cx, Cy, buffer);
         Gastar_combustible = true ;
      }

      Medidor_de_combustible(Gastar_combustible, Combustible, buffer);
      Pintar_nave(Cx, Cy, buffer);
      blit(buffer,screen,0,0,0,0,740,500); //Colocas buffer, despues en donde lo quieres proyectar, sus respectivas coordenadas y el tama�o de la pantalla. La funcion nos sirve para proyectar
      Avanzar_de_nivel(Cx, Cy, Vx, Vy, Num_nivel, Combustible, buffer);

      rest(20);
   }
   return 0;
}
END_OF_MAIN ();

void Reiniciar_nivel(float &Cx, float &Cy, float &Vx, float &Vy, float &Combustible){
   Cx = 710; Cy = 100;
   Vx =  0 ; Vy = -2;
   Combustible = 100;
}


void Avanzar_de_nivel(float &Cx, float &Cy, float &Vx, float &Vy, int &Num_nivel, float &Combustible, BITMAP *buffer){
   if(Aterrizaje(Cx, Cy, Vx, Vy, buffer, Num_nivel) == true){
      Cx = 710; Cy = 100;
      Vx = 0; Vy = 0.2;
      if(Num_nivel != 2) Num_nivel++;

      while(!key[KEY_A]){
         textout_centre_ex(screen, font, "PRESS (A) FOR THE NETX LEVEL", 370, 250, 0xFBFF00, 0x000000);
         rest(20);
      }
      Combustible = 100;
   }
}


bool Choque_nave(int Num_nivel, float Cx, float Cy){
   //Pata Izquierda de la Nave
   float R1x = Cx-20 ; float R1y = Cy ; //Tenemos que hacer , mas tarde, la funcion un poco mejor. Ya que de la forma implementada abra errores; pero igualmente nos sirve de testeo
   float R2x = Cx-10 ; float R2y = Cy+20 ;

   //Pata Derecha de la Nave
   float P1x = Cx+10 ; float P1y = Cy ;
   float P2x = Cx+20 ; float P2y = Cy+20 ;

   //Cuerpo de la Nave
   float Q1x = Cx-10 ; float Q1y = Cy-15 ;
   float Q2x = Cx+10 ; float Q2y = Cy ;

   if(Num_nivel ==  2){

      //X1   Y2   X2   Y1, coordenadas del triangulo   // Las coordenadas estan puestas desde el punto mas cercano del triangulo al lado izquierdo hasta al mas lejano del lado derecho
      if(Choque_triangulo(110, 100, 300, 500, R1x, R1y, R2x, R2y, 0) == true || Choque_triangulo(110, 100, 300, 500, P1x, P1y, P2x, P2y, 0) == true || Choque_triangulo(110, 100, 300, 500, Q1x, Q1y, Q2x, Q2y, 0) == true) return true;
      else if(Choque_triangulo(500, 500, 600, 300, R1x, R1y, R2x, R2y, 0) == true || Choque_triangulo(500, 500, 600, 300, P1x, P1y, P2x, P2y, 0) == true || Choque_triangulo(500, 500, 600, 300, Q1x, Q1y, Q2x, Q2y, 0) == true) return true;
      else if(Choque_triangulo(600, 300, 800, 500, R1x, R1y, R2x, R2y, 0) == true || Choque_triangulo(600, 300, 800, 500, P1x, P1y, P2x, P2y, 0) == true || Choque_triangulo(600, 300, 800, 500, Q1x, Q1y, Q2x, Q2y, 0) == true) return true;
      else if(Choque_triangulo(200,  0 , 400, 350, R1x, R1y, R2x, R2y, 1) == true || Choque_triangulo(200, 0 , 400, 350, P1x, P1y, P2x, P2y, 1) == true || Choque_triangulo(200, 0 , 400, 350, Q1x, Q1y, Q2x, Q2y, 1) == true) return true;
   }
   return false;
}


bool Choque_triangulo(float X1, float Y1, float X2, float Y2, float P1x, float P1y, float P2x, float P2y, int Tipo_triangulo){
   float M = (Y1 - Y2) / (X1 - X2); //Necesitamos saber cuanto mide la pendinte que se genera a raiz de las coordenadas de X, y
   //M > 0 EL triangulo es derecho ; si M < 0 El triangulo es izquierdo (Derecho [ Que su hipotenusa mira hacia al lado derecho] Izquierdo [Que su hipotenusa mira hacia al lado izquierdo])

   float B = Y1 - M*X1; //B es la intercepcion con el eje Y
   //La ecuacion de una recta es Y = M*X + B

   if(Tipo_triangulo == 0){ //Si triangulo es igual a 0 entonces es "Abajo"
      if(M > 0){
         if( X1 <= P1x && P1x <= X2){
            if(P2y >= M*P1x +B) return true;
         }
         else {
            if(P1x <= X1 && X1 <= P2x)
               if(Y1 <= P2y)return true;
         }
      }

      if(M < 0){
         if(X1 <= P2x && P2x <= X2){
            if(P2y >= M*P2x +B) return true;
         }
         else{
            if(P1x <= X2 && X2 <= P2x)
               if(Y2 <= P2y)return true;
         }
      }
   }

   if(Tipo_triangulo == 1){ //Si triangulo es igual a 0 entonces es "Arriba"
      if(M > 0){
         if(X1 <= P2x && P2x <= X2){
            if(P1y <= M*P2x + B) return true;
         }
         else{
            if(P1x <= X2 && X2 <= P2x)
            if(P1y <= Y2) return true;
         }
         return false;
      }
      else{
         if(X1 <= P1x && P1x <= X2){
            if(P1y <= M*P1x + B) return true;
         }
         else{
            if(P1x <= X1 && X1 <= P2x)
            if(P1y <= Y1) return true;
         }
         return false;
      }
   }
   return false;
}


bool Aterrizaje(float Cx, float Cy, float Vx, float Vy, BITMAP *buffer, int Num_nivel){
   if(Cy+20 >= 450 && Cx-20 >= 10 && Cx+20 <= 100){ //Le estamos diiendo al programa que si las coordenadas de la nave son mayores a las de la base de aterrizaje o que si la velocidad es mayor que 1.5. No abra aterrizaje (Game_over)
      if(Vy <= 3.5){
         return true;
      }
      else{}
   }
   return false;
}


bool Gamer_over(float &Cx, float &Cy, float &Vx, float &Vy, int Num_nivel, float &Combustible, BITMAP *buffer){
   //El 740 spon las coordenadas en x y el 500 son las coordenadas de y
   if(Cx+20 >= 740 || Cx-20 <= 0 || Cy-15 <=0 || Cy+20 >= 500){
      Explosion(Cx, Cy, buffer, Num_nivel);
      Reiniciar_nivel(Cx, Cy, Vx, Vy, Combustible);
      //return true;
   }
   else if(Choque_nave(Num_nivel, Cx, Cy) == true){
      Explosion(Cx, Cy, buffer, Num_nivel);
      Reiniciar_nivel(Cx, Cy, Vx, Vy, Combustible);
      //return true;
   }

   else if( Cy+20 >= 450 && Cx-20 >= 10 && Cx+20 <= 100 && Vy > 1.5){
      Explosion(Cx, Cy, buffer, Num_nivel);
      Reiniciar_nivel(Cx, Cy, Vx, Vy, Combustible);
   }

   else if(Cx-20 <= 100 && 100 <= Cx+20 && Cy+20 >= 450){
      Explosion(Cx, Cy, buffer, Num_nivel);
      Reiniciar_nivel(Cx, Cy, Vx, Vy, Combustible);
   }
return false;
}


void Explosion(float Cx, float Cy,  BITMAP *buffer, int Num_nivel){
   float X[12] = {Cx-10, Cx+10,  Cx  ,  Cx  , Cx+15, Cx-15, Cx+5, Cx-10, Cx+10, Cx-5 , Cx-10, Cx+10};
   float Y[12] = {Cy   ,  Cy  , Cy-15, Cy+15, Cy-15, Cy+15, Cy+5, Cy-10, Cy-10, Cy+10,  Cy  ,  Cy  };

   float Dx[6] = { 7,   7,   0,  -7, -7,  0}; //Estas son las cooordenadas en las que las lienas de la nave se moveran, a la hora de la explosion
   float Dy[6] = { 0,  -7,  -7,  -7,  0,  7};

   clear(screen);

   do{

      clear(buffer);
      Pintar_nivel(Num_nivel, buffer);
      int j = 0;

      for(int i = 0; i<=10; i+=2){
         line(buffer, X[i], Y[i], X[i+1], Y[i+1], 0xFFFFFF);
         Rotar(X[i+1], Y[i+1], X[i], Y[i], 15);

         X[i] += Dx[j]; //Este es el movimiento del pivote
         Y[i] += Dy[j];
         X[i+1] += Dx[j]; //Movimientp del punto en el que orbita (En otras palabras, el eje de la liena)
         Y[i+1] += Dy[j];
         j++; //La variable "i" la cambiamos por la variable "j" , ya que el programa con la variable i nos da un incremento de 2 en 2; lo cual hace que se salte las coordenadas de algunas lineas. Entonces  a "j" la igualamos a 0 y le decimos que haga un incremento de 1 en 1
      }

      textout_centre_ex(buffer, font,"PRESS (A) FOR TRY AGAIN", 370, 240, 0xFBFF00, 0x000000);
      textout_centre_ex(buffer, font,"PRESS (ESC) FOR EXIT AT GAME", 370, 250, 0xFBFF00, 0x000000);
      blit(buffer, screen, 0, 0, 0, 0, 740, 500);
      rest(20);
   }while(!key [KEY_ESC] && !key [KEY_A]);
}


void Pintar_nivel(int Num_nivel, BITMAP *buffer){
   if(Num_nivel == 1){
      rectfill(buffer, 10, 450, 100, 500,  0x999999); //Esta funcion nos pide el lugar donde lo queremos pintar, un punto y el punto opouesto (Los puntos necesitan coordenadas "X y Y") y el color
   }
   if(Num_nivel == 2){
   triangle(buffer, 110, 100, 300, 500, 110, 500, 0x999999);
   triangle(buffer, 500, 500, 600, 300, 600, 500, 0x999999);
   triangle(buffer, 600, 300, 800, 500, 600, 500, 0x999999);

   triangle(buffer, 200, 0  , 400, 350, 400, 0  , 0x999999);
   rectfill(buffer, 10 , 450, 100, 500,  0x999999);
   }
}


void Medidor_de_combustible(bool Gastar_combustible, float &Combustible, BITMAP *buffer){
   textout_centre_ex(buffer, font, "Combustible", 100, 30, 0x999999, 0x000000);
   rectfill(buffer, 50,50,50+Combustible, 55, 0x999999);
   if(Gastar_combustible  == true ){
      Combustible -= 0.2;
   }
}


void Aceleracion(float Da, float &Vx, float &Vy){
   float Ax = 0, Ay = -0.15;
   Rotar(Ax, Ay, 0, 0, Da); //Si Da es igual a 0, la aceleracion del vector queda intacto
   Vx += Ax;
   Vy += Ay;
}


void Pintar_fuego(float Da, float Cx, float Cy, BITMAP *buffer){
   float  C1, C2;
   C1 = Cx; C2 = Cy;
   if(Da != 0) C2+=9;
   float Fuego[14] = { C1-5,C2+5 , C1-10,C2+20 , C1-5,C2+20 , C1,C2+35 , C1+5,C2+20 , C1+10,C2+20 , C1+5,C2+5};

   for(int i = 0 ; i <= 12 ; i+=2){ //Es i <= 12 porque son 6 lineas las que pintaremos para simular el fuego
      Rotar(Fuego[i], Fuego[i+1], Cx, Cy, Da);
   }

   for(int c = 0 ; c <= 10 ; c+=2){
      line(buffer, Fuego[c], Fuego[c+1], Fuego[c+2], Fuego[c+3], 0xca2f21);
   }
}


void Pintar_nave(float Cx, float Cy, BITMAP *buffer){
   float nav[22] =
   {Cx-20, Cy+20,    Cx-20, Cy+10,    Cx-10, Cy,    Cx-10, Cy-10,    Cx, Cy-15,    Cx+10, Cy-10,
      Cx+10, Cy,    Cx+20, Cy+10,    Cx+20, Cy+20,     Cx-10, Cy,    Cx+10, Cy};

   for(int i = 0; i <= 14; i +=2){
      line(buffer, nav[i], nav[i+1], nav[i+2], nav[i+3],0x959595);
      if(i == 14)line(buffer, nav[i+4], nav[i+5], nav[i+6], nav[i+7],0x959595);
   }
}


void Mover_nave(float &Cx, float &Cy, float &Vx, float &Vy){
   float Ax, Ay;
   Ay = 0.065;
   Ax = 0;

   Vx += Ax;
   Vy += Ay;

   Cx += Vx;
   Cy += Vy;
}


/* Rotar un vector con coordenadas polares a rectangulares si R es la longitud del vector
   con origen (X1, X2) y "Q" el angulo que hace con el eje "X" sus coordenadas son:
   X = X1 + R*Cos (Q)
   Y = Y1 + R*Sen (Q)

   Si queremos rotar el vector a un angulo "S" , las nuevas coordenadas al rotar seran:
   X = X1 + R*Cos(Q+S)
   Y = Y1 + R*Sen(Q+S)

   Se le a�ade el nuevo vector del angulo a la formula, sumandolo con el angulo ya dado
*/


void Rotar( float &X, float &Y, float Cx, float Cy, float Da){ //Da es un angulo en grados
   float Dx = X - Cx;      //De la bilblioteca que a�adimos, nos sirve para colocar raices cuadradas en programacion
   float Dy = Y - Cy;
   float R = sqrt(Dx*Dx + Dy*Dy);
   float A = atan2(Dy,Dx);

   //Pasamos Da de grados a radianes
   float Da_rad = Da / 180 * M_PI;
   A -= Da_rad; //Esta punto A ya vale la suma de los angulos

   X = Cx + R * cos(A);
   Y = Cy + R * sin(A); // Seno se escribe sin, no sen
}

//Creado por Kingetro17.