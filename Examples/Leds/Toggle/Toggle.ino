// ------------------------------------------------ ROBUS KIDSY -----------------------------------------------
// EJEMPLO DE USO DE LOS LEDS DE USUARIO LED1, LED2, LED3 Y LED4
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al hardware del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 17 de febrero de 2020
// ------------------------------------------------------------------------------------------------------------
// Robus Kidsy cuenta con 4 LEDs de usuario:
// - Led1
// - Led2
// - Led3 (Disponible a partir de la version 3.1)
// - Led4 (Disponible a partir de la version 3.1)
// Nota importante: El LED blanco junto al sensor de color no se puede controlar directamente
// ------------------------------------------------------------------------------------------------------------

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Kidsy, llamada de igual forma

void setup() {
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  if(Kidsy.ButtonA.read() == PRESSED) Kidsy.Led1.toggle();
  if(Kidsy.ButtonB.read() == PRESSED) Kidsy.Led2.toggle();
} 