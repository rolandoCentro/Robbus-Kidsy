// ------------------------------------------------ ROBUS KIDSY -----------------------------------------------
//
// Nivel de dificultad: FACIL
//
// EJEMPLO DE USO DE LOS MOTORES IZQUIERDO Y DERECHO A UNA VELOCIDAD FIJA
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al hardware del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 20 de febrero de 2020
// ------------------------------------------------------------------------------------------------------------
//
// Robus Kidsy cuenta con 2 motorreductores:
// - MotorLeft
// - MotorRight
// 
// Con este ejemplo entenderas el funcionamiento de los motores que impulsan a tu robus Kidsy
// Si quieres mover los motores por separado, basta con utilizar las funciones:
//
// Kidsy.Move.MotorLeft(speed);
// Kidsy.Move.MotorRight(speed);
// ------------------------------------------------------------------------------------------------------------

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada Kidsy

// Variables para la velocidad de los motores
int speedLeft = 100;      // 100 hacia el FRENTE
int speedRight = -100;    // 100 hacia ATRAS

void setup() {
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  Kidsy.ButtonA.read();   // captura estado nuevo del boton A
  Kidsy.ButtonB.read();   // captura estado nuevo del boton B

  // REVISION DEL BOTON A
  // ----------------------
  if(Kidsy.ButtonA.status == PRESSED) {
    Kidsy.Move.MotorLeft(speedLeft);        // Si el boton se presiono, acciona motor izquierdo con varible
  }
  if(Kidsy.ButtonA.status == RELEASED) {
    Kidsy.Move.MotorLeft(0);                // Si el boton se solto, detiene el motor izquierdo
  }
  
  // REVISION DEL BOTON B
  // ----------------------
  if(Kidsy.ButtonB.status == PRESSED) { 
    Kidsy.Move.MotorRight(speedRight);      // Si el boton se presiono, acciona motor derecho con varible
  }
  if(Kidsy.ButtonB.status == RELEASED) { 
    Kidsy.Move.MotorRight(0);               // Si el boton se solto, detiene el motor derecho
  }
} 