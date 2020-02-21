// ------------------------------------------------ ROBUS KIDSY -----------------------------------------------
//
// Nivel de dificultad: FACIL
//
// EJEMPLO DE LECTURA DEL SENSOR DE COLOR
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al hardware del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 8 de febrero de 2020
// --------------------------------------------------------------------------------------------------------------
//
// Robus Kidsy cuenta con 1 sensor de color:
// - ColorSensor
//
// Este sensor es capaz de leer colores basicos y su cantidad de color blanco, por lo que puede diferenciar
// entre 8 colores diferentes: Negro, Rojo, Verde, Azul, Amarillo, Cian, Magenta y Blanco.
//
// Cada uno de estos colores puede ser leido de forma numerica, por medio de un "Alias" o por su nombre.
// Para leer un color, primero es necesario que se habilite el sensor de color. Los diferentes modulos
// de Robus Kidsy se configuran y habilitan al llamar a la funcion Kidsy.begin(), a excepcion del sensor
// de color.
// La vista humana y de diversos animales, se basa en la cantidad de luz que llega a los ojos, lo mismo
// sucede con Robus Kidsy. Para que pueder ver un color, se requiere de luz, por lo que a un lado del sensor
// veras un pequeño LED amarillo. Para que este LED no te moleste si no estas usando el sensor de color,
// implementamos una funcion de habilitacion llamada enable(), y otra de dehabilitacion llamada disable().
//
// Kidsy.ColorSensor.enable();    // Habilita el sensor y el LED
// Kidsy.ColorSensor.disable();   // Deshabilita el sensor y el LED
//
// Posteriormente basta con llamar la funcion read() para leer el color que Robus esta viendo. y revisar la
// variable value para revisar su valor numerico, o imprimir su nombre leyendo la variable name, por ejemplo:
//
// Kidsy.ColorSensor.read();              // Lee el color
// if(Kidsy.ColorSensor.value == RED) {}  // Evalua si el color es Rojo
//
// La tabla de los colores, alias y nombres se detalla a continuacion:
//
//  ----------------------------
// | NUMERO | ALIAS   | NOMBRE  |
// | ---------------------------|
// | 0     | BLACK   | Negro    |
// | 1     | RED     | rojo     |
// | 2     | GREEN   | verde    |
// | 3     | BLUE    | azul     |
// | 4     | YELLOW  | amarillo |
// | 5     | CYAN    | cian     |
// | 6     | MAGENTA | magenta  |    
// | 7     | WHITE   | blanco   |
//  ----------------------------
//
// Ademas de los colores, Robus puede medir la cantidad de luz blanca que esta viendo, usando la variable white
//
// Serial.println(Kidsy.ColorSensor.white);     // Imprime la cantidad de luz blanca
// --------------------------------------------------------------------------------------------------------------

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada de igual forma

void setup() {
  Serial.begin(115200);       // Inicializa comunicacion serial a 115200 baudios
  Kidsy.begin();              // Inicializa el hardware del Robus Kidsy
  Kidsy.ColorSensor.enable(); // Habilita el sensor de color y enciende el LED blanco
  //Kidsy.ColorSensor.disable(); // Si quieres deshabilitar el sensor y apagar el LED blanco, usa esta funcion
}

void loop() {
  Kidsy.ColorSensor.read();                     // Obtiene el color
  Serial.print("Color: ");
  Serial.print(Kidsy.ColorSensor.name);         // Imprime el nombre del color mas cercano
  Serial.print(", Numero: ");
  Serial.print(Kidsy.ColorSensor.value);        // Valor entre 0 y 7
  Serial.print(", Luz blanca: ");
  Serial.println(Kidsy.ColorSensor.white);      // Imprime el nombre del color mas cercano
}