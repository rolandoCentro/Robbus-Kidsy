// ------------------------------------------------ ROBUS KIDSY -------------------------------------------------
// EJEMPLO DE USO DEL NEOPIXEL
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al hardware del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 17 de febrero de 2020
// --------------------------------------------------------------------------------------------------------------

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Kidsy, llamada de igual forma

void setup() {
  Serial.begin(115200);   // Inicializa comunicacion serial a 115200 baudios
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  // Si se presiona boton A, Neopixel en modo arcoiris con una separacion de 15ms entre cada cambio de tono
  if(Kidsy.ButtonA.read() == PRESSED) {
    Kidsy.Neopixel.rainbow(15);
    Kidsy.Neopixel.off();         // despues del efecto apaga Neopixel
  }

  // Si se presiona boton B, Neopixel en color aleatorio      rojo            verde          azul
  if(Kidsy.ButtonB.read() == PRESSED) Kidsy.Neopixel.color(random(0,255), random(0,255), random(0,255));

  // Si se presiona flecha Arriba, efecto de latido en color rojo
  if(Kidsy.ArrowUp.readDigital() == TOUCHED) Kidsy.Neopixel.heartBeat(RED);

  // Si se presiona flecha Abajo, efecto de latido en color verde
  if(Kidsy.ArrowDown.readDigital() == TOUCHED) Kidsy.Neopixel.heartBeat(GREEN);

  // Si se preiona flecha Izquierda, efecto de latido en color azul
  if(Kidsy.ArrowLeft.readDigital() == TOUCHED) Kidsy.Neopixel.heartBeat(BLUE);

  // Si se presiona flecha Derecha, efecto de latido en color Magenta
  if(Kidsy.ArrowRight.readDigital() == TOUCHED) Kidsy.Neopixel.heartBeat(MAGENTA);
}