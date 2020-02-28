// ------------------------------------------------ ROBUS KIDSY -----------------------------------------------
//
// Nivel de dificultad: FACIL
//
// EJEMPLO DE MOVIMIENTO DE ROBUS KIDSY, POR MEDIO DE LAS FLECHAS FRENTE, ATRAS, IZQUIERDA, DERECHA 
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al hardware del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 20 de febrero de 2020
// ------------------------------------------------------------------------------------------------------------
//
// En este ejemplo conoceremos las funciones basicas de movimiento de Robus.
//
// Robus Kidsy cuenta con 2 motorreductores:
// - MotorLeft
// - MotorRight
//
// Y con 4 flechas de direccion:
// - ArrowForward
// - ArrowBackward
// - ArrowLeft
// - ArrowRight
//
// Para leer una flecha, basta que uses la funcion read(), y luego consultes la variable status,
// de la funcion Move de tu Robus Kidsy, por ejemplo:
// 
// Kidsy.ArrowForward.read();                 // Lee la flecha Frente
// if(Kidsy.ArrowForward.status == PRESSED)   // Usando el valor obtenido en un if
// 
// Para mover a Robus, puedes mover sus motores por separado, con las funciones:
//
// Kidsy.Move.MotorLeft(speed);
// Kidsy.Move.MotorRight(speed);
//
// O bien, si quieres darle un movimiento mas natural, puedes usar:
//
// Kidsy.Move.forward(speed);
// Kidsy.Move.backward(speed);
// Kidsy.Move.turnLeft(speed);
// Kidsy.Move.turnRight(speed);
//
// Que haran que Robus se mueva al frente, atras, y gire sobre su eje a la izquierda y derecha.
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

int speed = 100;      // velocidad para las distintas funciones de movimiento

void setup() {
  Serial.begin(115200);   // Inicializa la comunicacion serial por USB a 115200 baudios
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  // Las flechas se usan en modo digital
  Kidsy.ArrowForward.read();    // captura estado nuevo de la flecha Frente
  Kidsy.ArrowBackward.read();   // captura estado nuevo de la flecha Atras
  Kidsy.ArrowLeft.read();       // captura estado nuevo de la flecha Izquierda
  Kidsy.ArrowRight.read();      // captura estado nuevo de la flecha Derecha

  // REVISION DE LA FLECHA FRENTE
  // ----------------------
  if(Kidsy.ArrowForward.status == TOUCHED) {
    Kidsy.Move.forward(speed);                  // Si el boton se presiono, avanza hacia ADELANTE
    delay(1000);
  }
  if(Kidsy.ArrowForward.status == UNTOUCHED) {
    Kidsy.Move.stop();                          // Si el boton se solto, detiene el Robus
  }

  // REVISION DE LA FLECHA ATRAS
  // ----------------------
  if(Kidsy.ArrowBackward.status == TOUCHED) {
    Kidsy.Move.backward(speed);                 // Si el boton se presiono, avanza hacia ATRAS
    delay(1000);
  }
  if(Kidsy.ArrowBackward.status == UNTOUCHED) {
    Kidsy.Move.stop();                          // Si el boton se solto, detiene el Robus
  }

  // REVISION DE LA FLECHA IZQUIERDA
  // ----------------------
  if(Kidsy.ArrowLeft.status == TOUCHED) {
    Kidsy.Move.turnLeft(speed);                 // Si el boton se presiono, avanza gira a la IZQUIERDA
    delay(1000);
  }
  if(Kidsy.ArrowLeft.status == UNTOUCHED) {
    Kidsy.Move.stop();                          // Si el boton se solto, detiene el Robus
  }

  // REVISION DE LA FLECHA DERECHA
  // ----------------------
  if(Kidsy.ArrowRight.status == TOUCHED) {
    Kidsy.Move.turnRight(speed);                // Si el boton se presiono, gira a la DERECHA
    delay(1000);
  }
  if(Kidsy.ArrowRight.status == UNTOUCHED) {
    Kidsy.Move.stop();                          // Si el boton se solto, detiene el Robus
  }
} 