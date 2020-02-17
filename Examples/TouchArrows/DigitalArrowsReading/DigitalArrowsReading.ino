// --------------------------------------------------------------------------------------------------------------
// Ejemplo de lectura digital de las flechas Up, Down, Left y Right

// Los estados digitales de las flechas pueden ser high o low (1 o 0)
// No obstante, la funcion readDigital() perteneciente a Kidsy.Arrow puede devolver cuatro valores:
// TOUCHED        - La flecha fue presionada. Este estado solamente se regresa 1 vez
// UNTOUCHED      - La flecha fue soltada. Este estado solamente se regresa 1 vez
// HOLD_TOUCHED   - La flecha permanece presionada
// HOLD_UNTOUCHED - La flecha permanece suelta

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada Kidsy

void setup() {
  Serial.begin(115200);   // Inicializa comunicacion serial a 115200 baudios
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  Kidsy.ArrowUp.readDigital();      // guarda el valor digital mas reciente de la flecha Arriba
  Kidsy.ArrowDown.readDigital();    // guarda el valor digital mas reciente de la flecha Abajo
  Kidsy.ArrowLeft.readDigital();    // guarda el valor digital mas reciente de la flecha Izquierda
  Kidsy.ArrowRight.readDigital();   // guarda el valor digital mas reciente de la flecha Derecha
  
  if(Kidsy.ArrowUp.digital == TOUCHED) Serial.println("Up presionada");
  else if(Kidsy.ArrowUp.digital == UNTOUCHED) Serial.println("Up suelta");
  //else if(Kidsy.ArrowUp.digital == HOLD_TOUCHED) Serial.println("Up se mantiene presionada");
  //else if(Kidsy.ArrowUp.digital == HOLD_UNTOUCHED) Serial.println("Up se mantiene suelta");

  if(Kidsy.ArrowDown.digital == TOUCHED) Serial.println("Down presionada");
  else if(Kidsy.ArrowDown.digital == UNTOUCHED) Serial.println("Down suelta");
  //else if(Kidsy.ArrowDown.digital == HOLD_TOUCHED) Serial.println("Down se mantiene presionada");
  //else if(Kidsy.ArrowDown.digital == HOLD_UNTOUCHED) Serial.println("Down se mantiene suelta");

  if(Kidsy.ArrowLeft.digital == TOUCHED) Serial.println("Left presionada");
  else if(Kidsy.ArrowLeft.digital == UNTOUCHED) Serial.println("Left suelta");
  //else if(Kidsy.ArrowLeft.digital == HOLD_TOUCHED) Serial.println("Left se mantiene presionada");
  //else if(Kidsy.ArrowLeft.digital == HOLD_UNTOUCHED) Serial.println("Left se mantiene suelta");

  if(Kidsy.ArrowRight.digital == TOUCHED) Serial.println("Right presionada");
  else if(Kidsy.ArrowRight.digital == UNTOUCHED) Serial.println("Right suelta");
  //else if(Kidsy.ArrowRight.digital == HOLD_TOUCHED) Serial.println("Right se mantiene presionada");
  //else if(Kidsy.ArrowRight.digital == HOLD_UNTOUCHED) Serial.println("Right se mantiene suelta");
}

// Fin del ejemplo de lectura digital de las flechas
// --------------------------------------------------------------------------------------------------------------
