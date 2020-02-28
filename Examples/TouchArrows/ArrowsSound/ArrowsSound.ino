// ------------------------------------------------ ROBUS KIDSY -----------------------------------------------
//
// Nivel de dificultad: FACIL
//
// EJEMPLO DE SONIDOS CON EL BUZZER POR MEDIO DE LAS FLECHAS DE DIRECCION
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al hardware del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 20 de febrero de 2020
// ---------------------------------------------------------------------------------------------------------------
//
// Robus Kidsy cuenta con 1 buzzer:
// - Buzzer
//
// El buzzer no es otra cosa que una mini bocina, por lo que ¡Robus es capaz de hacer sonidos!
// Utilizar el Buzzer es muy sencillo, basta con emplear la funcion Buzzer.playTone().
//
// Un tono es un sonido que se repite muchas veces en un segundo, y dependiendo de esa cantidad de veces, sera
// como lo escuches, grave o agudo. Para que Robus Kidsy haga sonidos, basta con poner dentro de la funcion
// playTone() la frecuencia (numero de veces por segundo) que tendra tu tono, y, si quieres que el sonido dure
// cierto tiempo, la cantidad en mili segundos (recuerda que 1 segundo tiene 1000 milisegundos) y ¡listo!, por
// ejemplo:
//
// Kisdy.Buzzer.playTone(500, 50);    // Robus reproduce un sonido grave durante 50 milisegundos
// Kidsy.Buzzer.playTone(1000);       // Robus reproduce un sonido agudo de forma indefinida
//
// Si usas la segunda forma, Robus no guardara silencio, a menos que uses la funcion Kidsy.Buzzer.noTone()
//
// Kidsy.Buzzer.playTone(1000);       // Robus reproduce un sonido agudo de forma indefinida
// if(Kidsy.ButtonA.read() == PRESSED) Kidsy.Buzzer.noTone();   // Robus guarda silencio al predsionar el boton A
// ---------------------------------------------------------------------------------------------------------------

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada Kidsy

void setup() {
  Serial.begin(115200);
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  if(Kidsy.ArrowForward.read() == TOUCHED) {   // tono de 300Hz durante 50ms
    Kidsy.Led1.on();
    Kidsy.Buzzer.playTone(300, 50);
    Serial.println("TOUCHED");
    Kidsy.Led1.off();
  }
  if(Kidsy.ArrowBackward.read() == TOUCHED) {  // tono de 500Hz durante 50ms
    Kidsy.Led1.on();
    Kidsy.Buzzer.playTone(500, 50);
    Serial.println("TOUCHED");
    Kidsy.Led1.off();
  }
  if(Kidsy.ArrowLeft.read() == TOUCHED) {      // tono de 700Hz durante 50ms
    Kidsy.Led2.on();
    Kidsy.Buzzer.playTone(700, 50);
    Serial.println("TOUCHED");
    Kidsy.Led2.off();
  }
  if(Kidsy.ArrowRight.read() == TOUCHED) {     // tono de 900Hz durante 50ms
    Kidsy.Led2.on();
    Kidsy.Buzzer.playTone(900, 50);
    Serial.println("TOUCHED");
    Kidsy.Led2.off();
  }

  // Boton A reproduce un tono de 900Hz y Boton B lo detiene
  if(Kidsy.ButtonA.read() == PRESSED) Kidsy.Buzzer.playTone(900);
  if(Kidsy.ButtonB.read() == PRESSED) Kidsy.Buzzer.noTone();
}