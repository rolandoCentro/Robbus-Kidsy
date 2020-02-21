// ------------------------------------------------ ROBUS KIDSY -----------------------------------------------
//
// Nivel de dificultad: FACIL
//
// EJEMPLO DE LECTURA DIGITAL DE LAS FLECHAS DE DIRECCION
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al hardware del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 20 de febrero de 2020
// --------------------------------------------------------------------------------------------------------------
//
// Robus Kidsy cuenta con 4 flechas de direccion:
// - ArrowForward
// - ArrowBackward
// - ArrowLeft
// - ArrowRight
//
// Estas flechas son sensibles al tacto. Para leer su valor basta con usar la funciona read() la cual:
// Leera un 1 o TOUCHED cuando se toca
// Leera un 0 o NOTOUCHED cuando no se toca
//
// Y posteriormente usar la variable status para saber su valor, por ejemplo:
//
// Kidsy.ArrowForward.read();                   // Lee la flecha Adelante
// if(Kidsy.ArrowForward.status == TOUCHED) {}  // Evalua si la flecha se presiono

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada Kidsy

void setup() {
  Serial.begin(115200);   // Inicializa comunicacion serial a 115200 baudios
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  Kidsy.ArrowForward.read();     // Lee la flecha Adelante
  Kidsy.ArrowBackward.read();    // Lee la flecha Atras
  Kidsy.ArrowLeft.read();        // Lee la flecha Izquierda
  Kidsy.ArrowRight.read();       // Lee la flecha Derecha
  
  if(Kidsy.ArrowForward.status == TOUCHED) Serial.println("Adelante presionada");
  else if(Kidsy.ArrowForward.status == NOTOUCHED) Serial.println("Adelante suelta");
  
  if(Kidsy.ArrowBackward.status == TOUCHED) Serial.println("Atras presionada");
  else if(Kidsy.ArrowBackward.status == NOTOUCHED) Serial.println("Atras suelta");
  
  if(Kidsy.ArrowLeft.status == TOUCHED) Serial.println("Izquierda presionada");
  else if(Kidsy.ArrowLeft.status == NOTOUCHED) Serial.println("Izquierda suelta");
  
  if(Kidsy.ArrowRight.status == TOUCHED) Serial.println("Derecha presionada");
  else if(Kidsy.ArrowRight.status == NOTOUCHED) Serial.println("Derecha suelta");
}