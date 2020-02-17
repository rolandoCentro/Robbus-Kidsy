#include<tempo.h>

void onTimer(){
  static unsigned int counter = 1;
  
  Serial.print("onTimer ");
  Serial.print(counter);
  Serial.print(" at ");
  Serial.print(millis());
  Serial.println(" ms");

  if (counter == 10)
    endTimer();

  counter++;
}

void startTimer() {
  timer = timerBegin(0, 80, true); // timer_id = 0; divider=80; countUp = true;
  timerAttachInterrupt(timer, &onTimer, true); // edge = true
  timerAlarmWrite(timer, 1000000, true);  //1000 ms
  timerAlarmEnable(timer);
}

void endTimer() {
  timerEnd(timer);
  timer = NULL; 
}

void setup() {
  Serial.begin(115200);
  startTimer();
}

void loop() {}
