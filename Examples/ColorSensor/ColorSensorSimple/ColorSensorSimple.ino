// -------------------------------------------------------------------------------------------------------------------
// Ejemplo uso del sensor de color
#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada de igual forma

void setup() {
  Serial.begin(115200);       // Inicializa comunicacion serial a 115200 baudios
  Kidsy.begin();              // Inicializa el hardware del Robus Kidsy
  Kidsy.ColorSensor.enable(); // Habilita el sensor de color y enciende el LED blanco
  //Kidsy.ColorSensor.disable(); // Si quieres deshabilitar el sensor y apagar el LED blanco, usa esta funcion
}

void loop() {
  // Los colores que regresa la variable color_value de la clase ColorSensor pueden ser:
  // 0 - NEGRO
  // 1 - ROJO
  // 2 - VERDE
  // 3 - AZUL
  // 4 - AMARILLO
  // 5 - CYAN
  // 6 - MAGENTA
  // 7 - BLANCO
  
  Kidsy.ColorSensor.read();    // Obtiene la medicion del sensor de color
  Serial.println(Kidsy.ColorSensor.color_string);   // Imprime el nombre del color mas cercano

  // Descomenta para imprimir el valor numerico del color
  //Serial.print("Numero de color: ");
  //Serial.println(Kidsy.ColorSensor.color_value);  // Regresa un valor entre 0 y 7

  // Descomenta para imprimir el valor de luz blanca que esta viendo el sensor
  //Serial.print("Luz blanca: ");
  //Serial.println(Kidsy.ColorSensor.white);   // Imprime el nombre del color mas cercano

  // descomenta para imprimir el valor individual de cada componente del color (RGB)
  /*Serial.print("Red: ");
  Serial.print(Kidsy.ColorSensor.red);
  Serial.print(", Green: ");
  Serial.print(Kidsy.ColorSensor.green);
  Serial.print(", Blue: ");
  Serial.println(Kidsy.ColorSensor.blue);*/
}