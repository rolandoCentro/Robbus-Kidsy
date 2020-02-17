// ------------------------------------------------ ROBUS KIDSY -------------------------------------------------
// EJEMPLO DE LECTURA DIGITAL DE LOS BOTONES DE USUARIO
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al hardware del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 7 de febrero de 2020
// --------------------------------------------------------------------------------------------------------------
// Objetos de la clase buttons:
// - ButtonA
// - ButtonB
// --------------------------------------------------------------------------------------------------------------
// Funciones de la clase buttons:
// - uint8_t read(); // Lee el estado de un boton y regresa un valor entero que puede ser uno de estos cuatro:
// PRESSED           0
// RELEASED          1
// HOLD_RELEASED     2
// HOLD_PRESSED      3
// --------------------------------------------------------------------------------------------------------------
// Variables de la clase buttons:
// - uint8 status;  // Guarda uno de los 4 valores que puede tener un boton
// --------------------------------------------------------------------------------------------------------------
// USO 1:
// int ButtonAValue = Robus.ButtonA.read();   // guarda el estado del boton en la variable ButtonValue
//
// USO 2:
// Robus.ButtonA.read();                      // Lee el valor del boton y lo guarda en status, dentro de la clase ButtonA
// if(Robus.ButtonA.status == PRESSED) {}     // ya se puede consultar status

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Kidsy, llamada de igual forma
int times_A = 0;
int times_B = 0;

void setup() {
  Serial.begin(115200);   // Inicializa comunicacion serial a 115200 baudios
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  Kidsy.ButtonA.read();   // Lee el ultimo estado del boton A, solamente llamar una vez en el loop
  Kidsy.ButtonB.read();   // Lee el ultimo estado del boton B, solamente llamar una vez en el loop 

  switch(Kidsy.ButtonA.status) {    // determina el valor de 'status' obtenido en la funcion read()
    case PRESSED:
      Serial.print("BotonA Presionado ");
      Serial.print(++times_A);    // aumenta el contador y lo imprime
      Serial.println(" veces");
      Kidsy.Led1.on();  // enciende el LED1
      break;
    case RELEASED:
      Serial.println("BotonA suelto");
      break;
    case HOLD_PRESSED:
      // mientras el boton permanezca presionado, entrara en este case
      //Serial.println("BotonA permanece presionado");
      break;
    case HOLD_RELEASED:
      // mientras el boton permanezca suelto, entrara en este case
      //Serial.println("BotonA permanece suelto");
      break;
  }

  switch(Kidsy.ButtonB.status) {
    case PRESSED:
      Serial.print("BotonB Presionado ");
      Serial.print(++times_B);    // aumenta el contador y lo imprime
      Serial.println(" veces");
      Kidsy.Led1.off();   // apaga el LED1
      break;
    case RELEASED:
      Serial.println("BotonB suelto");
      break;
    case HOLD_PRESSED:
      // mientras el boton permanezca presionado, entrara en este case
      //Serial.println("BotonB permanece presionado");
      break;
    case HOLD_RELEASED:
      // mientras el boton permanezca suelto, entrara en este case
      //Serial.println("BotonB permanece suelto");
      break;
  }
} 
