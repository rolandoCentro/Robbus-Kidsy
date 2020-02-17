// -------------------------------------------------------------------------------------------------------------------
// Ejemplo de uso del Buzzer, generacion de notas y sonidos con las flechas

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Robus, llamada Kidsy

char notes[] = "gabygabyxzCDxzCDabywabywzCDEzCDEbywFCDEqywFGDEqi        azbC"; // el espacio significa silencio
int length = sizeof(notes); // numero de notas
// duracion de las notas con respecto a la variable tempo (1 = 75ms)
int beats[] = { 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1, 2,3,3,16,};
int tempo = 75;   // duracion entre notas (en ms)

void setup() {
  Serial.begin(115200);   // Inicializa comunicacion serial a 115200 baudios
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  if(Kidsy.ButtonA.read() == PRESSED) {                       // si se presiona el boton A
    for (int i = 0; i < length; i++) {                        // este ciclo lee el contenido del buffer notes[]
      if (notes[i] == ' ') {                                  // si es un espacio
        delay(beats[i] * tempo);                              // espera en silencio
      } else {                                                // si no es espacio
        Kidsy.Buzzer.playNote(notes[i], beats[i] * tempo);    // reproduce la nota de ese espacio de memoria
      }
      delay(tempo / 2);   // pausa entre las notas (75/2 ms)
    }
  }

  // la siguiente secuencia reproduce la media al reves, a excepcion de los ultimas 12 notas ()
  if(Kidsy.ButtonB.read() == PRESSED) {
    for (int i = length - 12; i >= 0; i--) {
      if (notes[i] == ' ') {
        delay(beats[i] * tempo); // silencio
      } else {
        Kidsy.Buzzer.playNote(notes[i], beats[i] * tempo);
      }
      // pausa entre notas
      delay(tempo / 2); 
    }
    for (int i = length - 12; i < length; i++) {
      if (notes[i] == ' ') {
        delay(beats[i] * tempo); // silencio
      } else {
        Kidsy.Buzzer.playNote(notes[i], beats[i] * tempo);
      }
      // pausa entre las notas
      delay(tempo / 2); 
    }
  }

  // Esta seccion reproduce un sonido de 50ms de duracion dependiendo de la flecha que se toque
  if(Kidsy.ArrowUp.readDigital() == TOUCHED) {  // la flecha Arriba reproduce un tono de 300Hz y prende el led1  
    Kidsy.Led1.on();
    Kidsy.Buzzer.playTone(300, 50);
    Kidsy.Led1.off();
  }
  if(Kidsy.ArrowDown.readDigital() == TOUCHED) {  // la flecha Abajo reproduce un tono de 500Hz y prende el led1
    Kidsy.Led1.on();
    Kidsy.Buzzer.playTone(500, 50);
    Kidsy.Led1.off();
  }
  if(Kidsy.ArrowLeft.readDigital() == TOUCHED) {  // la flecha Izquierda reproduce un tono de 700Hz y prende el led2
    Kidsy.Led2.on();
    Kidsy.Buzzer.playTone(700, 50);
    Kidsy.Led2.off();
  }
  if(Kidsy.ArrowRight.readDigital() == TOUCHED) {  // la flecha Derecha reproduce un tono de 900Hz y prende el led2
    Kidsy.Led2.on();
    Kidsy.Buzzer.playTone(900, 50);
    Kidsy.Led2.off();
  }
}
// Fin del ejemplo de uso del Buzzer, generacion de notas y sonidos con las flechas
// -------------------------------------------------------------------------------------------------------------------
