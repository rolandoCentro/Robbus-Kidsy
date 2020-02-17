#include<RobusKidsy.h>

Robus Kidsy;

void setup() {
  Serial.begin(115200);
  Kidsy.begin();
}

void loop() {
  if(Kidsy.ButtonA.read() == PRESSED) Kidsy.Neopixel.rainbow(15);
  if(Kidsy.ButtonB.read() == PRESSED) Kidsy.Neopixel.off();
  if(Kidsy.ArrowUp.readDigital() == TOUCHED) Kidsy.Neopixel.heartBeat(RED);
  if(Kidsy.ArrowDown.readDigital() == TOUCHED) Kidsy.Neopixel.heartBeat(GREEN);
  if(Kidsy.ArrowLeft.readDigital() == TOUCHED) Kidsy.Neopixel.heartBeat(BLUE);
  if(Kidsy.ArrowRight.readDigital() == TOUCHED) Kidsy.Neopixel.heartBeat(MAGENTA);
}
