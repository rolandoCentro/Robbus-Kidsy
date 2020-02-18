// Ejemplo de uso de motores Izquierdo y Derecho

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada Kidsy

// Variables para la velocidad de los motores
// Los valores pueden ser:
// POSITIVO   1 a  255  ->   1 es la velocidad minima,  255 la maxima, hacia ADELANTE.
// NEGATIVO  -1 a -255  ->  -1 es la velocidad minima, -255 la maxima, hacia ATRAS.
//            0 es totalmente detenido.
// Una velocidad muy baja (menor a +-25) puede que no sea suficiente para comenzar a mover el motor

int speedLeft = 100;      // 100 hacia el FRENTE
int speedRight = -100;    // 100 hacia ATRAS

void setup() {
  Serial.begin(115200);   // Inicializa la comunicacion serial por USB a 115200 baudios
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
