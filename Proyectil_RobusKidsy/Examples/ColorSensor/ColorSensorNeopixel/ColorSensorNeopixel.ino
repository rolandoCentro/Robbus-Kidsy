// -------------------------------------------------------------------------------------------------------------------
// Ejemplo uso del sensor de color con Neopixel y Buzzer
#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada de igual forma

bool buzzer_state = false;  // Activa o desactiva el buzzer
int new_color, old_color;   // identifica si el color ha cambiado

void setup() {
  Serial.begin(115200);     // Inicializa comunicacion serial a 115200 baudios
  Kidsy.begin();            // Inicializa el hardware del Robus Kidsy
}

void loop() {
  // Los colores que regresa la variable color_value de la clase ColorSensor pueden ser:
  // 0 - No identificable
  // 1 - ROJO
  // 2 - VERDE
  // 3 - AZUL
  // 4 - AMARILLO
  // 5 - CYAN
  // 6 - MAGENTA
  // 7 - BLANCO
  Kidsy.ColorSensor.read(); // Obtiene la medicion del sensor de color
  Serial.println(Kidsy.ColorSensor.color_string); // Imprime el nombre del color mas cercano

  // Imprime el valor individual de cada componente del color (RGB)
  /*Serial.print("Red: ");
  Serial.print(Kidsy.ColorSensor.red);
  Serial.print(", Green: ");
  Serial.print(Kidsy.ColorSensor.green);
  Serial.print(", Blue: ");
  Serial.println(Kidsy.ColorSensor.blue);*/

  new_color = Kidsy.ColorSensor.color_value;    // el color leido es aproximado a los primarios o secundarios (RGBCMY)

  if(Kidsy.ButtonA.read() == PRESSED) buzzer_state = !buzzer_state;   // El boton A activa o desactiva el Buzzer
  if(Kidsy.ButtonB.read() == PRESSED) Kidsy.LedW.toggle();            // El boton B prende o apaga el LED blanco
  
  if(new_color != old_color) {                              // si el color cambio ...
    Kidsy.Neopixel.color(Kidsy.ColorSensor.color_value);    // ... muestra el color en el neopixel
    if(buzzer_state == true) {                              // si el buzzer esta habilitado ...
      switch(Kidsy.ColorSensor.color_value) {               // ... evalua que color se leyo
        case RED:     Kidsy.Buzzer.playTone(100); break;    // playTone(N); reproduce un sonido de frecuencia = N indefinidamente
        case GREEN:   Kidsy.Buzzer.playTone(200); break;    // playTone(N, time); repruduce durante cierto tiempo una frecuencia = N
        case BLUE:    Kidsy.Buzzer.playTone(300); break;    // ejemplo: Kidsy.Buzzer.playTone(300, 50); 300Hz, durante 50ms
        case YELLOW:  Kidsy.Buzzer.playTone(400); break;
        case CYAN:    Kidsy.Buzzer.playTone(500); break;
        case MAGENTA: Kidsy.Buzzer.playTone(600); break;
      }
    }
    else Kidsy.Buzzer.noTone();   // noTone detiene la reproduccion indefinida de playTone(N);
  }  
  old_color = new_color;   // el nuevo color leido se convierte en el viejo color en la siguiente vuelta al loop
}
// Fin del ejemplo uso del sensor de color con Neopixel y Buzzer
// -------------------------------------------------------------------------------------------------------------------
