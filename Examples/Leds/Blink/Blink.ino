// ------------------------------------------------ ROBUS KIDSY -----------------------------------------------
//
// Nivel de dificultad: MUY FACIL
//
// EJEMPLO DE USO DE LOS LEDS DE USUARIO LED1 y LED2
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
//
// Nota importante: El LED blanco junto al sensor de color se controla por medio del sensor de color
// ------------------------------------------------------------------------------------------------------------

#include<RobusKidsy.h>

Robus Kidsy;          // Declara una instancia tipo Kidsy, llamada de igual forma

void setup() {
  Kidsy.begin();      // Inicializa el hardware del Robus Kidsy
}

void loop() {
  Kidsy.Led1.on();    // Alterna los LEDs 1 y 2 entre apagado y prendido cada segundo
  Kidsy.Led2.off();  
  delay(1000);
  Kidsy.Led1.off();  
  Kidsy.Led2.on();   
  delay(1000);
} 