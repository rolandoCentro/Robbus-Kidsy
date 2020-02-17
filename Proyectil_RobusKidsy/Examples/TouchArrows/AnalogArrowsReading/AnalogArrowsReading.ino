// ------------------------------------------------ ROBUS KIDSY -------------------------------------------------
// EJEMPLO DE LECTURA ANALOGICA DE LAS FLECHAS TOUCH
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al hardware del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 7 de febrero de 2020
// --------------------------------------------------------------------------------------------------------------
// Objetos de la clase buttons:
// - ArrowUp
// - ArrowDown
// - ArrowLeft
// - ArrowRight
// --------------------------------------------------------------------------------------------------------------
// Funciones analogicas de la clase Arrows:
// - uint8 readAnalog();          // Lee el valor analogico de una flecha (de 0 a 255)
// - void calibrate(bool state);  // Calibra una flecha siendo tocada o sin tocarse
// --------------------------------------------------------------------------------------------------------------
// La lectura analogica se guarda en una variable, dentro de la clase.
// - analog                       // Guarda el valor analogico de la flecha
// --------------------------------------------------------------------------------------------------------------
// USO 1:
// int UpAnalogValue = Robus.ArrowUp.readAnalog();  // guarda el valor en la variable UpAnalogValue
//
// USO 2:
// Robus.ArrowUp.readAnalog();      // Lee el valor analogico y lo guarda en analog, dentro de la clase ArrowUp
// if(Robus.Button.analog == 30) {} // ya se puede consultar analog
// --------------------------------------------------------------------------------------------------------------

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada Kidsy

void setup() {
  Serial.begin(115200);   // Inicializa comunicacion serial a 115200 baudios
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  uint8_t left, right;                    // Declara 2 variables para guardar el valor analogico de 2 flechas
  Kidsy.ArrowUp.readAnalog();             // las otras 2 flechas se leeran desde la variable 'analog' de la clase          
  Kidsy.ArrowDown.readAnalog();
  left = Kidsy.ArrowLeft.readAnalog();    // guarda el valor de las flechas en las variables declaradas
  right = Kidsy.ArrowRight.readAnalog();

  // el valor analogico de las flechas se guarda en la variable llamada 'analog' dentro de la clase, para acceder a ella
  // basta con acceder por medio operador punto (.) Kidsy.ArrowN.analog, donde N puede ser Up, Down, Left o Right.
  
  printf("Arriba: %u, Abajo: %u, Izquierda: %u, Derecha: %u\n", Kidsy.ArrowUp.analog, Kidsy.ArrowDown.analog, left, right);
}
