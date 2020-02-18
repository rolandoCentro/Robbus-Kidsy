// ------------------------------------------------ ROBUS KIDSY -----------------------------------------------
// EJEMPLO DE USO DE LOS BOTONES DE USUARIO A Y B
// Este ejemplo es de uso libre y esta pensado para dar una introduccion al hardware del robot Robus Kidsy.
// Autor: Fabian Alfonso Flores
// Empresa: Proyectil Mx
// Fecha: 17 de febrero de 2020
// ------------------------------------------------------------------------------------------------------------
// Robus Kidsy cuenta con 2 Botones de usuario:
// - ButtonA
// - ButtonB
// Si un boton se encuentra sin presionar, se leera un 0, si se presiona, un 1
// Nota importante: El boton RESET sirve para reiniciar el programa de tu Robus Kidsy y no se puede programar
// ------------------------------------------------------------------------------------------------------------

#include<RobusKidsy.h>

Robus Kidsy;    // Declara una instancia tipo Kidsy, llamada de igual forma

void setup() {
  Serial.begin(115200);   // Inicializa comunicacion serial a 115200 baudios
  Kidsy.begin();          // Inicializa el hardware del Robus Kidsy
}

void loop() {
  Kidsy.ButtonA.read();   // Lee el ultimo estado del boton A
  Kidsy.ButtonB.read();   // Lee el ultimo estado del boton B

  Serial.print("Boton A: ");
  Serial.print(Kidsy.ButtonA.status);
  Serial.print(", Boton B: ");
  Serial.println(Kidsy.ButtonB.status);
} 