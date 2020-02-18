// Ejemplo de uso de las funciones de movimiento de los motores

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada Kidsy

int speed = 100;      // velocidad para las distintas funciones de movimiento

void setup() {
  Serial.begin(115200);   // Inicializa la comunicacion serial por USB a 115200 baudios
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  // Las flechas se usan en modo digital
  Kidsy.ArrowUp.readDigital();     // captura estado nuevo de la flecha Arriba
  Kidsy.ArrowDown.readDigital();   // captura estado nuevo de la flecha Abajo
  Kidsy.ArrowLeft.readDigital();   // captura estado nuevo de la flecha Izquierda
  Kidsy.ArrowRight.readDigital();  // captura estado nuevo de la flecha Derecha

  // REVISION DE LA FLECHA ARRIBA
  // ----------------------
  if(Kidsy.ArrowUp.digital == TOUCHED) {
    Kidsy.Move.straightForward(speed);      // Si el boton se presiono, avanza hacia ADELANTE
  }
  if(Kidsy.ArrowUp.digital == UNTOUCHED) {
    Kidsy.Move.stop();                      // Si el boton se solto, detiene el Robus
  }

  // REVISION DE LA FLECHA ABAJO
  // ----------------------
  if(Kidsy.ArrowDown.digital == TOUCHED) {
    Kidsy.Move.straightBackward(speed);     // Si el boton se presiono, avanza hacia ATRAS
  }
  if(Kidsy.ArrowDown.digital == UNTOUCHED) {
    Kidsy.Move.stop();                      // Si el boton se solto, detiene el Robus
  }

  // REVISION DE LA FLECHA IZQUIERDA
  // ----------------------
  if(Kidsy.ArrowLeft.digital == TOUCHED) {
    Kidsy.Move.pivotLeft(speed);            // Si el boton se presiono, avanza gira a la IZQUIERDA
  }
  if(Kidsy.ArrowLeft.digital == UNTOUCHED) {
    Kidsy.Move.stop();                      // Si el boton se solto, detiene el Robus
  }

  // REVISION DE LA FLECHA DERECHA
  // ----------------------
  if(Kidsy.ArrowRight.digital == TOUCHED) {
    Kidsy.Move.pivotRight(speed);           // Si el boton se presiono, gira a la DERECHA
  }
  if(Kidsy.ArrowRight.digital == UNTOUCHED) {
    Kidsy.Move.stop();                      // Si el boton se solto, detiene el Robus
  }
} 
