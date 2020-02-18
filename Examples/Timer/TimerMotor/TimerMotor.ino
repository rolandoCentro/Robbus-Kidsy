// Ejemplo de uso de motores Izquierdo y Derecho

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada Kidsy

#define MAX_SPEED     100     // Velocidad maxima de los motores
#define TIMER_TIME    50000   // Tiempo del Timer0 en microSegundos

// Declaramos un puntero tipo timer, compatible con ESP32
hw_timer_t * timer = NULL;
// Variable de sincronizacion para modificar una variable compartida
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;

// Variables para la velocidad de los motores
// Los valores pueden ser:
// POSITIVO   1 a  255  ->   1 es la velocidad minima,  255 la maxima, hacia ADELANTE.
// NEGATIVO  -1 a -255  ->  -1 es la velocidad minima, -255 la maxima, hacia ATRAS.
//            0 es totalmente detenido.
// Una velocidad muy baja (menor a +-25) puede que no sea suficiente para comenzar a mover el motor

int motorSpeedLeft = 0;      // 100 hacia el FRENTE
int motorSpeedRight = 0;    // 100 hacia ATRAS
int setSpeedLeft = 0;
int setSpeedRight = 0;

// Funcion de interrupcion del timer
void IRAM_ATTR onTimer() {
  // Para la variable compartida por loop y la funcion de interrupcion
  portENTER_CRITICAL_ISR(&timerMux);  

  // En esta seccion se evalua la velocidad actual de los motores y se ajustan cada el timer interrumpe
  if(motorSpeedLeft < setSpeedLeft)         motorSpeedLeft++;
  else if(motorSpeedLeft > setSpeedLeft)    motorSpeedLeft--;
  if(motorSpeedRight < setSpeedRight)       motorSpeedRight++;
  else if(motorSpeedRight > setSpeedRight)  motorSpeedRight--;

  // carga los nuevos valores de velocidad en los motores
  Kidsy.Move.MotorLeft(motorSpeedLeft);
  Kidsy.Move.MotorRight(motorSpeedRight);

  // Para la variable compartida por loop y la funcion de interrupcion
  portEXIT_CRITICAL_ISR(&timerMux);   
}

void setup() {
  Serial.begin(115200);   // Inicializa la comunicacion serial por USB a 115200 baudios
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy

  // A continucacion configuramos el timer:
  
  // 0       - Inicializa el Timer0, Robus Kidsy dispone de 4 timers (0 al 3)
  // 80      - Valor del preescaler para 80MHz / 80 = 1000000 veces por segundo
  // true    - Cuenta ascendente, false: cuenta descendente
  timer = timerBegin(0, 80, true);
  
  // timer    - Pasamos la variable timer creada
  // &onTimer - funcion onTimer
  // true     - la interrupcion generada sera ascendente, false: descendente
  timerAttachInterrupt(timer, &onTimer, true);  
  
  // timer   - Puntero al timer
  // 5000    - Valor del contador en el cual el timer interrumpira (ms para un valor de preescaler de 80 y velocidad de 80MHz)
  // true    - Interrupcion periodica, false: interrumpe una sola vez 
  timerAlarmWrite(timer, 5000, true);

  //  Habilitamos el timer que acabamos de crear
  timerAlarmEnable(timer);               
}

void loop() {
  Kidsy.ButtonA.read();   // captura estado nuevo del boton A
  Kidsy.ButtonB.read();   // captura estado nuevo del boton B

  Kidsy.ArrowUp.readDigital();  // Captura el valor digital de la flecha arriba
  Kidsy.ArrowDown.readDigital();  // Captura el valor digital de la flecha abajo
  Kidsy.ArrowLeft.readDigital();  // Captura el valor digital de la flecha izquierda
  Kidsy.ArrowRight.readDigital();  // Captura el valor digital de la flecha derecha

  if(Kidsy.ArrowUp.digital == TOUCHED) {
    setSpeedLeft = MAX_SPEED;
    setSpeedRight = MAX_SPEED;
    Kidsy.Neopixel.color(RED);
    Kidsy.Buzzer.playTone(400,50);
  }

  if(Kidsy.ArrowDown.digital == TOUCHED) {
    setSpeedLeft = -MAX_SPEED;
    setSpeedRight = -MAX_SPEED;
    Kidsy.Neopixel.color(GREEN);
    Kidsy.Buzzer.playTone(500,50);
  }

  if(Kidsy.ArrowLeft.digital == TOUCHED) {
    setSpeedLeft = -MAX_SPEED;
    setSpeedRight = MAX_SPEED;
    Kidsy.Neopixel.color(BLUE);
    Kidsy.Buzzer.playTone(600,50);
  }

  if(Kidsy.ArrowRight.digital == TOUCHED) {
    setSpeedLeft = MAX_SPEED;
    setSpeedRight = -MAX_SPEED;
    Kidsy.Neopixel.color(MAGENTA);
    Kidsy.Buzzer.playTone(500,50);
  }
  
  // REVISION DEL BOTON A
  // ----------------------
  if(Kidsy.ButtonA.status == PRESSED) {
    setSpeedLeft = 0;
    setSpeedRight = 0;
    Kidsy.Neopixel.color(BLACK);
  }
  else if(Kidsy.ButtonA.status == RELEASED) {
    
  }
  
  // REVISION DEL BOTON B
  // ----------------------
  if(Kidsy.ButtonB.status == PRESSED) { 
    
  }
  else if(Kidsy.ButtonB.status == RELEASED) { 
    
  }

  Serial.print("MotorIzq = ");
  Serial.print(motorSpeedLeft); 
  Serial.print(", MotorDer = ");
  Serial.println(motorSpeedRight); 
} 