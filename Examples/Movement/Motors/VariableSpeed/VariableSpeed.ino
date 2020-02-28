// ------------------------------------------------ ROBUS KIDSY -----------------------------------------------
//
// Nivel de dificultad: FACIL
//
// EJEMPLO DE USO DE LOS MOTORES IZQUIERDO Y DERECHO CON VELOCIDAD VARIABLE
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al hardware del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 22 de febrero de 2020
// ------------------------------------------------------------------------------------------------------------
//
// Robus Kidsy cuenta con 2 motorreductores:
// - MotorLeft
// - MotorRight
// 
// Con este ejemplo entenderas el funcionamiento de los motores que impulsan a tu robus Kidsy, al variar
// si velocidad por medio de un ciclo for.
// Si no sabes como funciona el ciclo for, te invitamos a probar el ejemplo cicloFor en sentencias condicionales
// Para mover los motores por separado, basta con utilizar las funciones:
//
// Kidsy.Move.MotorLeft(speed);
// Kidsy.Move.MotorRight(speed);
//
// Los motores pueden tener 256 velocidades diferentes (8 bits), que van desde 0 hasta 255. Normalmente
// 0 significaria que estan detenidos, y del 1 al 255 una velocidad, sin embargo, es posible que tu Robus
// comience a girar sus llantas a partir de un valor cercano a 25, esto es debido a la friccion interna.
//
// Debido a que los motores pueden girar hacia adelante y hacia atras, el valor de velocidad puede ser:
// POSITIVO   1 a  255  ->   1 es la velocidad minima,  255 la maxima, hacia ADELANTE.
// NEGATIVO  -1 a -255  ->  -1 es la velocidad minima, -255 la maxima, hacia ATRAS.
//            0 es totalmente detenido.
//
// Y recuerda que una velocidad muy baja (menor a +-25) puede que no sea suficiente para comenzar a mover 
// el motor.
// ------------------------------------------------------------------------------------------------------------

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada Kidsy

// Variables para la velocidad de los motores
int speedLeft = 0;        // Motor izquierdo comienza detenido 
int speedRight = 0;       // Motor derecho comienza detenido
int time = 20;            // tiempo entre una velocidad y otra

void setup() {
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  for(int i=0; i<=255; i++) {   // ciclo for de 0 a 255
    Kidsy.Move.MotorLeft(i);    // mueve la llanta izquierda con el valor positivo (Adelante)
    Kidsy.Move.MotorRight(-i);  // mueve la llanta derecha con el valor negativo (Atras)
    delay(time);
  }
  for(int i=255; i>0; i--) {    // ciclo for de 255 a 0
    Kidsy.Move.MotorLeft(i);
    Kidsy.Move.MotorRight(-i);
    delay(time);
  }
  for(int i=0; i<=255; i++) {   // ciclo for de 0 a 255
    Kidsy.Move.MotorLeft(-i);   // invierte la direccion de las llantas mientras acelera
    Kidsy.Move.MotorRight(i);
    delay(time);
  }
  for(int i=255; i>0; i--) {    // ciclo for de 255 a 0
    Kidsy.Move.MotorLeft(-i);   // invierte la direccion mientras desacelera
    Kidsy.Move.MotorRight(i);
    delay(time);
  }
} 