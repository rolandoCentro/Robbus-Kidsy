// ------------------------------------------------ ROBUS KIDSY -----------------------------------------------
//
// Nivel de dificultad: FACIL
//
// EJEMPLO DE USO DE LA SENTENCIA CONDICIONAL SWITCH, USADO EN PROGRAMACION EN LENGUAJE C
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al software del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 19 de febrero de 2020
// ------------------------------------------------------------------------------------------------------------
//
// Tu Robus Kidsy es capaz de tomar desiciones. Asi como tu eliges si quieres mirar a la izquierda, derecha,
// arriba o abajo cuando alguien te llama, Robus es capaz de decidir si quiere ir a la izquierda, derecha, al
// frente o hacia atras, dependiendo del color que vea.
// La sentencia switch sirve justo para eso, DECIDIR. Si quieres que Robus tome esa desicion tan dificil, lo
// necesitaras. La sentencia Switch del lenguaje C, sirve para dirigir el programa por un lado u otro, 
// dependiendo de una variable. El programa de tu Robus (y cualquier computadora o robot) siempre se ejecuta 
// de arriba hacia abajo, pero el flujo se puede cambiar como si de abrir y cerrar llaves se tratara, por 
// medio de un switch. 
// 
// Con este ejmplo aprenderas a utilizar una sentencia switch para hacer que robus decida una direccion
// posible entre cuatro opciones distintas. 
// Robus puede ver 7 colores diferentes:
//
// 0 - BLACK    (NEGRO)
// 1 - RED      (ROJO)
// 2 - GREEN    (VERDE)
// 3 - BLUE     (AZUL)
// 4 - YELLOW   (AMARILLO)
// 5 - CYAN     (CIAN)
// 6 - MAGENTA  (MAGENTA)
// 7 - WHITE    (BLANCO)
//
// Y al programar puedes usar el numero o su "alias", es decir, BLACK en vez de 0, o MAGENTA en vez de 6.
// Ojo, no estas usando directamente sus nombres, cuando usas sus alias, el programa reemplaza esa etiqueta
// con su valor numerico.
//
// Su forma es la siguiente:
// switch() {   <- Cuerpo del switch
//   case A:    <- Primera opcion
//     -----    <- Codigo a ejecutar
//     break;   <- Interrupcion para ya no continuar si es la primera opcion.
//   case B:    <- Segunda opcion
//     -----    <- Codigo a ejecutar
//     break;   <- Interrupcion
//
//      .
//      .
//      .
//
//   case N:    <- Opcion N. No hay limite de opciones, mientras no se repitan
//     break;

//   default:   <- Opcion por defecto, por si no encontro ninguna
//     break;
// }            <- Final de la sentencia switch
//
// Lo mejor de todo es que la sentencia switch no es exclusiva de Robus, se ocupa en cualquier programa escrito
// en lenguaje C, por que ¡podras programar futuros Robus y otros robots de la misma forma!
// ------------------------------------------------------------------------------------------------------------

#include<RobusKidsy.h>

Robus Kidsy;                    // Declara una instancia tipo Robus, llamada Kidsy

int kidsyColor;                 // Esta variable guardara el color que Robus vio

void setup() {
  Serial.begin(115200);         // Inicializa la comunicacion serial por USB a 115200 baudios
  Kidsy.begin();                // Inicializa el hardware del Robus Kidsy
  Kidsy.ColorSensor.enable();   // Habilita el sensor de color y enciende su led blanco
}

void loop() {
  Kidsy.ColorSensor.read();              // Lee el color actual
  kidsyColor = Kidsy.ColorSensor.value;  // guarda el valor del color en la variable color (0 - 7)
  Kidsy.Neopixel.color(kidsyColor);      // muestra el color en el Neopixel

  // se escribe la palabra switch, y entre parentesis lo que quieres evaluar, seguido de {} llaves
  switch(kidsyColor) {
    // estamos entre las llaves, el cuerpo del switch y aqui es donde se hara la evaluacion.
    
    case RED:                    // "case" sirve para nombrar un posible caso, como es BLACK (0) termina con :
      Kidsy.Move.forward(100);   // Robus se mueve al frente
      break;                     // si este fue el caso, "break;" rompe la sentencia, y evita que entre a otro caso.
    
    case GREEN:                  // Evalua si el color es verde ...
      Kidsy.Move.backward(100);  // ... Robus se mueve al frente
      break;                    
    
    case BLUE:                   // Evalua si el color es azul ...
      Kidsy.Move.turnLeft(100);  // ... Robus se mueve a la izquierda
      break;
      
    case MAGENTA:                // el ultimo caso es MAGENTA, si llego aqui, significa que no era ninguno de los 3 anteriores...
      Kidsy.Move.turnRight(100); // ... Robus se mueve a la derecha
      break;

    default:                     // Si no fue ninguna opcion, siempre podemos dejar un caso auxiliar llamado default
      Kidsy.Move.stop();         // y si llego hasta aqui, es por que no se presiona ninguna flecha y Robus se detiene.
      break;
  }                              // Este es el termino del ciclo, lo que suceda a continuacion ya no formara parte de el.
}