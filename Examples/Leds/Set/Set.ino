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

bool state_led1 = 0;  // Led1 comienza encendido
bool state_led2 = 1;  // Led2 comienza apagado

void setup() {
  Kidsy.begin();                  // Inicializa el hardware del Robus Kidsy
  Kidsy.Led1.set(state_led1);    // La funcion set prende o apaga el led con 1 o 0 respectivamente
  Kidsy.Led2.set(state_led2);
}

void loop() {
  if(Kidsy.ButtonA.read() == PRESSED) {
    state_led1 = !state_led1;       // Cambia el valor de state_led1
    Kidsy.Led1.set(state_led1);
  }
  if(Kidsy.ButtonB.read() == PRESSED) {
    state_led2 = !state_led2;       // Cambia el valor de state_led2
    Kidsy.Led2.set(state_led2);
  }
} 
