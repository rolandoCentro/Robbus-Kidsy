// --------------------------------------------------------------------------------------------------------------
// Ejemplo de uso de motores con botones pulsacion corta y mantenida

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada Kidsy

void setup() {
  Serial.begin(115200);   // Inicializa la comunicacion serial por USB a 115200 baudios
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

unsigned int speedRight = 0;      // guarda la velocidad del motor derecho
unsigned int speedLeft = 0;       // guarda la velocidad del motor izquierdo

// banderas - Son variables booleanas que guardan estados verdaderos o falsos
bool flag_firstHold_A = false;    // primera vez que se mantiene el boton A
bool flag_repeat_A = false;       // activa la repeticion de la accion al presionar el boton A
bool flag_firstHold_B = false;    // primera vez que se mantiene el boton B
bool flag_repeat_B = false;       // activa la repeticion de la accion al presionar el boton B

long timestamp;   // guarda el valor de la funcion millis() que cuenta el tiempo de ejecucion del programa

void loop() {
  // Lee los estados de los botones A y B, estos pueden ser 4:
  // PRESSED        - El boton se presiono
  // RELEASED       - El boton se solto
  // HOLD_PRESSED   - El boton se mantiene presionado
  // HOLD_RELEASED  - El boton se mantiene suelto
  Kidsy.ButtonA.read();   // captura estado nuevo del boton A
  Kidsy.ButtonB.read();   // captura estado nuevo del boton B

  // REVISION DEL BOTON A
  // ----------------------
  if(Kidsy.ButtonA.status == PRESSED) speedRight += 5;  // si se presiona el boton A, la velocidad aumenta en 5
  // Si el boton se mantiene presionado, y es la primera vez ...
  else if(Kidsy.ButtonA.status == HOLD_PRESSED && flag_firstHold_A == false) {
    flag_firstHold_A = true;    // ... activa bandera de boton presionado
    timestamp = millis();       // guarda el valor actual del tiempo en ms
  }
  // Si la bandera de boton presionado ya esta activa, pero aun no ha pasado el tiempo para la repeticion ...
  else if(Kidsy.ButtonA.status == HOLD_PRESSED && flag_firstHold_A == true && flag_repeat_A == false) {
    if(millis() > timestamp + 1000) flag_repeat_A = true; // ... revisa si se supero el tiempo para activar repeticion
  }
  
  if(Kidsy.ButtonA.status == RELEASED) {  // si el boton se solto
    flag_firstHold_A = false;   // desactiva bandera de boton presionado por primera vez
    flag_repeat_A = false;      // desactiva bandera de repeticion
  }

  if(flag_repeat_A == true) {   // si la bandera de repeticion esta activa
    speedRight += 1;            // hace incrementos rapidos de 1
    delay(50);
  }
  // ----------------------

  // REVISION DEL BOTON B
  // ----------------------
  if(Kidsy.ButtonB.status == PRESSED) speedLeft += 5;  // si se presiona el boton B, la velocidad aumenta en 5
  // Si el boton se mantiene presionado, y es la primera vez ...
  else if(Kidsy.ButtonB.status == HOLD_PRESSED && flag_firstHold_B == false) {
    flag_firstHold_B = true;    // ... activa bandera de boton presionado
    timestamp = millis();       // guarda el valor actual del tiempo en ms
  }
  // Si la bandera de boton presionado ya esta activa, pero aun no ha pasado el tiempo para la repeticion ...
  else if(Kidsy.ButtonB.status == HOLD_PRESSED && flag_firstHold_B == true && flag_repeat_B == false) {
    if(millis() > timestamp + 1000) flag_repeat_B = true; // ... revisa si se supero el tiempo para activar repeticion
  }
  
  if(Kidsy.ButtonB.status == RELEASED) {  // si el boton se solto
    flag_firstHold_B = false;   // desactiva bandera de boton presionado por primera vez
    flag_repeat_B = false;      // desactiva bandera de repeticion
  }

  if(flag_repeat_B == true) {   // si la bandera de repeticion esta activa
    speedLeft += 1;            // hace incrementos rapidos de 1
    delay(50);
  }
  // ----------------------

  if(speedRight > 255) speedRight = 0;  // si la velocidad supera los 8 bits (255), regresa a 0
  if(speedLeft > 255) speedLeft = 0;

  // asigna la velocidad en los motores, si se quiere cambiar el sentido hacia atras, usar BACK
  Kidsy.Move.MotorLeft(FRONT, speedLeft);    
  Kidsy.Move.MotorRight(FRONT, speedRight);

  Serial.print("speedLeft: ");    // imprime la velocidad de ambos motores
  Serial.print(speedLeft);
  Serial.print(", speedRight: ");
  Serial.println(speedRight);
} 

// Fin del ejemplo uso de motores con botones pulsacion corta y mantenida
// -------------------------------------------------------------------------------------------------------------------
