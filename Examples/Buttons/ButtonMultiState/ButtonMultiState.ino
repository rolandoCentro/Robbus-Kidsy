// ------------------------------------------------ ROBUS KIDSY -----------------------------------------------
// EJEMPLO DE USO DE LOS BOTONES DE USUARIO A Y B CON LOS 4 ESTADOS QUE PUEDEN REGRESAR
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al hardware del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 17 de febrero de 2020
// ------------------------------------------------------------------------------------------------------------
// Robus Kidsy cuenta con 2 Botones de usuario:
// - ButtonA
// - ButtonB
//
// Los botones de usuario pueden devolver 4 valores:
// PRESSED - El boton se presiono
// RELEASED - El boton se libero
// HOLD_PRESSED - El boton se mantiene presionado
// HOLD_RELEASED - El boton se mantiene liberado
//
// Nota importante: El boton RESET sirve para reiniciar el programa de tu Robus Kidsy y no se puede programar
// ------------------------------------------------------------------------------------------------------------

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Kidsy, llamada de igual forma

int times_A;
int times_B;    // Cuenta las pulsaciones de los botones

void setup() {
  Serial.begin(115200);   // Inicializa comunicacion serial a 115200 baudios
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  Kidsy.ButtonA.read();   // Lee el ultimo estado del boton A
  Kidsy.ButtonB.read();   // Lee el ultimo estado del boton B

  switch(Kidsy.ButtonA.status) {  
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