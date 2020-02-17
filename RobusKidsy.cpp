#include <Arduino.h>
#include <RobusKidsy.h>

#ifndef _ROBUSKIDSY_CPP_
#define _ROBUSKIDSY_CPP_

/*hw_timer_t * timer = NULL;

void endTimer() {
  timerEnd(timer);
  timer = NULL; 
}

void onTimer(){
  
}

void startTimer() {
  timer = timerBegin(0, 80, true); // timer_id = 0; divider=80; countUp = true;
  timerAttachInterrupt(timer, &onTimer, true); // edge = true
  timerAlarmWrite(timer, 1000000, true);  //1000 ms
  timerAlarmEnable(timer);
}*/

Adafruit_NeoPixel dot(1, 19, NEO_GRB + NEO_KHZ800);  // 1 neopixel en pin19
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_1X);

void Robus :: begin() {

  pinMode(BUTTON_A, INPUT_PULLUP);
  pinMode(BUTTON_B, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LEDW, OUTPUT);
  
  pinMode(DCM_LEFT_IN1, OUTPUT);
  pinMode(DCM_LEFT_IN2, OUTPUT);
  pinMode(DCM_RIGHT_IN1, OUTPUT);
  pinMode(DCM_RIGHT_IN2, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  ledcSetup(PWM_CHANNEL_LEFT_IN1, PWM_MOTOR_FREQ, PWM_RESOUTION);
  ledcAttachPin(DCM_LEFT_IN1, PWM_CHANNEL_LEFT_IN1);
  ledcSetup(PWM_CHANNEL_LEFT_IN2, PWM_MOTOR_FREQ, PWM_RESOUTION);
  ledcAttachPin(DCM_LEFT_IN2, PWM_CHANNEL_LEFT_IN2);

  ledcSetup(PWM_CHANNEL_RIGHT_IN1, PWM_MOTOR_FREQ, PWM_RESOUTION);
  ledcAttachPin(DCM_RIGHT_IN1, PWM_CHANNEL_RIGHT_IN1);
  ledcSetup(PWM_CHANNEL_RIGHT_IN2, PWM_MOTOR_FREQ, PWM_RESOUTION);
  ledcAttachPin(DCM_RIGHT_IN2, PWM_CHANNEL_RIGHT_IN2);

  ledcSetup(PWM_CHANNEL_BUZZER, 0, PWM_RESOUTION);
  ledcAttachPin(BUZZER, PWM_CHANNEL_BUZZER);
  ledcWrite(BUZZER, 128);

  ButtonA.pin = BUTTON_A;
  ButtonB.pin = BUTTON_B;

  Led1.pin = LED1;
  Led2.pin = LED2;
  //Led3.pin = LED3;
  //Led4.pin = LED4;
  LedW.pin = LEDW;

  ArrowUp.pin = AN_UP;
  ArrowDown.pin = AN_DOWN;
  ArrowLeft.pin = AN_LEFT;
  ArrowRight.pin = AN_RIGHT;

  for(int i=0; i<ARROW_BUFFER_SIZE; i++) {
    ArrowUp.readAnalog();
    ArrowDown.readAnalog();
    ArrowLeft.readAnalog();
    ArrowRight.readAnalog();
  }

  Neopixel.begin();
  Neopixel.color(OFF);

  for (int i=0; i<256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;
    ColorSensor.gammatable[i] = x;
  }

  //startTimer();
}

uint8_t Robus :: buttons :: read() {
  new_state = digitalRead(pin);
  if(new_state == HIGH && old_state == HIGH) status = HOLD_RELEASED;  // button remains released
  if(new_state == HIGH && old_state == LOW) status = RELEASED;         // button is pressed once
  if(new_state == LOW && old_state == HIGH) status = PRESSED;        // button is released once
  if(new_state == LOW && old_state == LOW) status = HOLD_PRESSED;     // button remains pressed
  old_state = new_state;    // the last state gets old
  if(status == RELEASED || status == PRESSED) {
    delay(50);
  }
  return(status);
}

void Robus :: Led :: set(bool new_status) {
  status = new_status;
  digitalWrite(pin, status);
}

void Robus :: Led :: on() {
  status = ON;
  digitalWrite(pin, status);
}

void Robus :: Led :: off() {
  status = OFF;
  digitalWrite(pin, status);
}

bool Robus :: Led :: toggle() {
  status = !status;
  digitalWrite(pin, status);
  return(!status);
}

void Robus :: classMove :: MotorLeft(int16_t vel) {
  if(vel > 255) vel = 255;
  else if(vel < -255) vel = -255;
  if(vel > 0) direction = FRONT;
  else direction = BACK;
  speed = abs(vel);
  if(direction == FRONT) {
    ledcWrite(PWM_CHANNEL_LEFT_IN1, 255 - speed);
    ledcWrite(PWM_CHANNEL_LEFT_IN2, 255);
  }
  else {
    ledcWrite(PWM_CHANNEL_LEFT_IN1, 255);
    ledcWrite(PWM_CHANNEL_LEFT_IN2, 255 - speed);
  }
}

void Robus :: classMove :: MotorRight(int16_t vel) {
  if(vel > 255) vel = 255;
  else if(vel < -255) vel = -255;
  if(vel > 0) direction = FRONT;
  else direction = BACK;
  speed = abs(vel);
  if(direction == FRONT) {
    ledcWrite(PWM_CHANNEL_RIGHT_IN1, 255 - speed);
    ledcWrite(PWM_CHANNEL_RIGHT_IN2, 255);
  }
  else {
    ledcWrite(PWM_CHANNEL_RIGHT_IN1, 255);
    ledcWrite(PWM_CHANNEL_RIGHT_IN2, 255 - speed);
  }
}

void Robus :: classMove :: frontStraight(uint8_t vel) {
  if(vel > 255) vel = 255;
  else if(vel < 0) vel = 0;
  speed = vel;
  ledcWrite(PWM_CHANNEL_LEFT_IN1, 255 - speed);
  ledcWrite(PWM_CHANNEL_LEFT_IN2, 255);
  ledcWrite(PWM_CHANNEL_RIGHT_IN1, 255 - speed);
  ledcWrite(PWM_CHANNEL_RIGHT_IN2, 255);
}

void Robus :: classMove :: backStraight(uint8_t vel) {
  if(vel > 255) vel = 255;
  else if(vel < 0) vel = 0;
  speed = -vel;
  ledcWrite(PWM_CHANNEL_LEFT_IN1, 255);
  ledcWrite(PWM_CHANNEL_LEFT_IN2, 255 + speed);
  ledcWrite(PWM_CHANNEL_RIGHT_IN1, 255);
  ledcWrite(PWM_CHANNEL_RIGHT_IN2, 255 + speed);
}

void Robus :: classMove :: pivotLeft(uint8_t speed) {
  ledcWrite(PWM_CHANNEL_RIGHT_IN1, 255 - speed);
  ledcWrite(PWM_CHANNEL_RIGHT_IN2, 255);
  ledcWrite(PWM_CHANNEL_LEFT_IN1, 255);
  ledcWrite(PWM_CHANNEL_LEFT_IN2, 255 - speed);
}

void Robus :: classMove :: pivotRight(uint8_t speed) {
  ledcWrite(PWM_CHANNEL_LEFT_IN1, 255 - speed);
  ledcWrite(PWM_CHANNEL_LEFT_IN2, 255);
  ledcWrite(PWM_CHANNEL_RIGHT_IN1, 255);
  ledcWrite(PWM_CHANNEL_RIGHT_IN2, 255 - speed);
}

void Robus :: classMove :: closedLeft(uint8_t speed) {
  ledcWrite(PWM_CHANNEL_RIGHT_IN1, 255 - speed);
  ledcWrite(PWM_CHANNEL_RIGHT_IN2, 255);
  ledcWrite(PWM_CHANNEL_LEFT_IN1, 255);
  ledcWrite(PWM_CHANNEL_LEFT_IN2, 255);
}

void Robus :: classMove :: closedRight(uint8_t speed) {
  ledcWrite(PWM_CHANNEL_LEFT_IN1, 255);
  ledcWrite(PWM_CHANNEL_LEFT_IN2, 255);
  ledcWrite(PWM_CHANNEL_RIGHT_IN1, 255);
  ledcWrite(PWM_CHANNEL_RIGHT_IN2, 255 - speed);
}

void Robus :: classMove :: wideLeftFront(uint8_t speed, float factor) {
  float speed_div;
  if(factor > 0 && factor < 12) {
    // ecuation 1
    speed_div = -0.22*factor + 5.8;
  }
  else if(factor >= 12) {
    // ecuation 2
    speed_div = -0.0384*factor + 2.3;
  }
  
  ledcWrite(PWM_CHANNEL_RIGHT_IN1, 255 - speed);
  ledcWrite(PWM_CHANNEL_RIGHT_IN2, 255);
  ledcWrite(PWM_CHANNEL_LEFT_IN1, 255 - (int)(speed/speed_div));
  ledcWrite(PWM_CHANNEL_LEFT_IN2, 255);
  Serial.println(speed/speed_div);
}

void Robus :: classMove :: wideLeftBack(uint8_t speed, float factor) {
  float speed_div;
  if(factor > 0 && factor < 12) {
    // ecuation 1
    speed_div = -0.22*factor + 4.66;
  }
  else if(factor >= 12) {
    // ecuation 2
    speed_div = -0.0384*factor + 2.46;
  }
  
  ledcWrite(PWM_CHANNEL_RIGHT_IN1, 255);
  ledcWrite(PWM_CHANNEL_RIGHT_IN2, 255 - speed);
  ledcWrite(PWM_CHANNEL_LEFT_IN1, 255);
  ledcWrite(PWM_CHANNEL_LEFT_IN2, 255 - (int)(speed/speed_div));
  Serial.println(speed/speed_div);
}

void Robus :: classMove :: wideRightFront(uint8_t speed, float factor) {
  float speed_div;
  if(factor > 0 && factor < 12) {
    // ecuation 1
    speed_div = -0.22*factor + 5.8;
  }
  else if(factor >= 12) {
    // ecuation 2
    speed_div = -0.0384*factor + 2.3;
  }
  
  ledcWrite(PWM_CHANNEL_RIGHT_IN1, 255);
  ledcWrite(PWM_CHANNEL_RIGHT_IN2, 255 - speed);
  ledcWrite(PWM_CHANNEL_LEFT_IN1, 255);
  ledcWrite(PWM_CHANNEL_LEFT_IN2, 255 - (int)(speed/speed_div));
  Serial.println(speed/speed_div);
}

void Robus :: classMove :: wideRightBack(uint8_t speed, float factor) {
  float speed_div;
  if(factor > 0 && factor < 12) {
    // ecuation 1
    speed_div = -0.22*factor + 4.66;
  }
  else if(factor >= 12) {
    // ecuation 2
    speed_div = -0.0384*factor + 2.46;
  }
  
  ledcWrite(PWM_CHANNEL_RIGHT_IN1, 255 - speed);
  ledcWrite(PWM_CHANNEL_RIGHT_IN2, 255);
  ledcWrite(PWM_CHANNEL_LEFT_IN1, 255 - (int)(speed/speed_div));
  ledcWrite(PWM_CHANNEL_LEFT_IN2, 255);
  Serial.println(speed/speed_div);
}

uint8_t Robus :: Arrows :: readAnalog() {
  // subtract the last reading:
  total = total - buffer[readIndex];
  // read from the sensor:
  buffer[readIndex] = touchRead(pin);
  // add the reading to the total:
  total = total + buffer[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= ARROW_BUFFER_LENGHT) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }

  // calculate the average:
  average = total / ARROW_BUFFER_LENGHT;
  analog = average;
  return(average);
}

void Robus :: Arrows :: calibrate(bool state) {
  if(state == UNTOUCHED) {
    untouchCalibrate = readAnalog();
  }
  else touchCalibrate = readAnalog();

  thresshold = (untouchCalibrate - touchCalibrate) / 2;
}

uint8_t Robus :: Arrows :: readDigital() {
  readAnalog();
  if(analog < thresshold) new_state = HIGH;
  else new_state = LOW;
  if(new_state == LOW && old_state == LOW) digital = HOLD_UNTOUCHED;
  if(new_state == LOW && old_state == HIGH) digital = UNTOUCHED;
  if(new_state == HIGH && old_state == LOW) digital = TOUCHED;
  if(new_state == HIGH && old_state == HIGH) digital = HOLD_TOUCHED;
  old_state = new_state;
  return(digital);
}

void Robus :: Buzzer :: playTone(int16_t frequency, uint16_t duration) {
  ledcSetup(PWM_CHANNEL_BUZZER, frequency, PWM_RESOUTION);
  ledcAttachPin(BUZZER, PWM_CHANNEL_BUZZER);
  ledcWrite(PWM_CHANNEL_BUZZER, 128);
  delay(duration);
  ledcWrite(PWM_CHANNEL_BUZZER, 0);
}

void Robus :: Buzzer :: playTone(int16_t frequency) {
  if(old_frequency != frequency) {
    ledcSetup(PWM_CHANNEL_BUZZER, frequency, PWM_RESOUTION);
    ledcAttachPin(BUZZER, PWM_CHANNEL_BUZZER);
    ledcWrite(PWM_CHANNEL_BUZZER, 128);
  }
  old_frequency = frequency;
}


void Robus :: Buzzer :: noTone() {
  ledcSetup(PWM_CHANNEL_BUZZER, 0, PWM_RESOUTION);
  ledcAttachPin(BUZZER, PWM_CHANNEL_BUZZER);
  ledcWrite(PWM_CHANNEL_BUZZER, 0);
  old_frequency = 0;
}

void Robus :: Buzzer :: playNote(char note, uint16_t duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'x', 'a', 'z', 'b', 'C', 'y', 'D', 'w', 'E', 'F', 'q', 'G', 'i' };
  int tones[] = { 1898, 1690, 1500, 1420, 1265, 1194, 1126, 1063, 1001, 947, 893, 843, 795, 749, 710, 668, 630, 594 };
   
  // play the tone corresponding to the note name
  for (int i = 0; i < 18; i++) {
    if (names[i] == note) {
      playTone((tones[i]), duration);
    }
  }
}

void Robus :: Buzzer :: r2d2(uint16_t time) {
  for(int i=0; i<time/75; i++) {
    playTone(random(50, 5000), 75);
  }
  noTone();
}

void Robus :: Neopixel :: begin() {
  dot.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
  dot.show();            // Turn OFF all pixels ASAP
}

void Robus :: Neopixel :: color(uint8_t red, uint8_t green, uint8_t blue) {
  dot.setPixelColor(0, red, green, blue);
  dot.show();
}

void Robus :: Neopixel :: color(uint8_t color, uint8_t brightness) {
  switch(color) {
    case RED:     dot.setPixelColor(0, brightness, 0, 0);                   break;
    case GREEN:   dot.setPixelColor(0, 0, brightness, 0);                   break;
    case BLUE:    dot.setPixelColor(0, 0, 0, brightness);                   break;
    case YELLOW:  dot.setPixelColor(0, brightness, brightness, 0);          break;
    case CYAN:    dot.setPixelColor(0, 0, brightness, brightness);          break;
    case MAGENTA: dot.setPixelColor(0, brightness, 0, brightness);          break;
    case WHITE:   dot.setPixelColor(0, brightness, brightness, brightness); break;
  }
  dot.show();
}

void Robus :: Neopixel :: color(uint8_t color) {
  switch(color) {
    case OFF:     dot.setPixelColor(0, 0, 0, 0);       break;
    case RED:     dot.setPixelColor(0, 255, 0, 0);     break;
    case GREEN:   dot.setPixelColor(0, 0, 255, 0);     break;
    case BLUE:    dot.setPixelColor(0, 0, 0, 255);     break;
    case YELLOW:  dot.setPixelColor(0, 255, 255, 0);   break;
    case CYAN:    dot.setPixelColor(0, 0, 255, 255);   break;
    case MAGENTA: dot.setPixelColor(0, 255, 0, 255);   break;
    case WHITE:   dot.setPixelColor(0, 255, 255, 255); break;
  }
  dot.show();
}

void Robus :: Neopixel :: off() {
  dot.setPixelColor(0, 0, 0, 0);
  dot.show();
}

void Robus :: Neopixel :: fadeIn(uint8_t col, uint16_t speed) {
  for(int i=0; i<255; i++) {
    color(col, i);
    delay(speed);
  }
}

void Robus :: Neopixel :: fadeOut(uint8_t col, uint16_t speed) {
  for(int i=255; i>=0; i--) {
    color(col, i);
    delay(speed);
  }
}

void Robus :: Neopixel :: fadeInOut(uint8_t col, uint16_t speed, uint16_t time_between, uint16_t time_end) {
  fadeIn(col, speed);
  delay(time_between);
  fadeOut(col, speed);
  delay(time_end);
}

void Robus :: Neopixel :: heartBeat(uint8_t col) {
  fadeInOut(col, 1, 0, 0);
  fadeInOut(col, 1, 0, 500);
}

void Robus :: Neopixel :: rainbow(uint16_t wait) {
  for(long firstPixelHue = 0; firstPixelHue < 65536; firstPixelHue += 256) {
    int pixelHue = firstPixelHue + (65536L / 1);
    dot.setPixelColor(0, dot.gamma32(dot.ColorHSV(pixelHue)));
    dot.show(); // Update strip with new contents
    delay(wait);  // Pause for a moment
  }
}

uint8_t Robus :: ColorSensor :: read() {
  tcs.getRawData(&red, &green, &blue, &clear);
  
  // Hacer rgb medición relativa
  sum = clear;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
 
  // Escalar rgb a bytes
  r *= 256; g *= 256; b *= 256;

  // Convertir a hue, saturation, value
  ColorConverter::RgbToHsv(static_cast<uint8_t>(r), static_cast<uint8_t>(g), static_cast<uint8_t>(b), hue, saturation, value);
  hue360 = hue * 360;

  if (hue360 < 30 || hue360 >= 330 && clear > 50 && clear < 700)
  {
    color_string = "red";
    color_value = RED;
  }
  else if (hue360 >= 31 && hue360 < 90 && clear > 50 && clear < 700)
  {
    color_string = "yellow";
    color_value = YELLOW;
  }
  else if (hue360 >= 91 && hue360 < 150 && clear > 50 && clear < 700)
  {
    color_string = "green";
    color_value = GREEN;
  }
  else if (hue360 >= 151 && hue360 < 210 && clear > 50 && clear < 700)
  {
    color_string = "cyan";
    color_value = CYAN;
  }
  else if (hue360 >= 210 && hue360 < 270 && clear > 50 && clear < 700)
  {
    color_string = "blue";
    color_value = BLUE;
  }
  else if (hue360 >= 270 && hue360 < 330 && clear > 50 && clear < 700)
  {
    color_string = "magenta";
    color_value = MAGENTA;
  }
  else if(clear <= 50) {
    color_string = "black";
    color_value = BLACK;
  }
  else if(clear >= 700) {
    color_string = "white";
    color_value = WHITE;
  }
  return(color_value);
}

void enable() {
    tcs.enable();
}

void disable() {
    tcs.disable();
}

void ColorConverter :: RgbToHsv(uint8_t red, uint8_t green, uint8_t blue, double& hue, double& saturation, double& value) {
  auto rd = static_cast<double>(red) / 255;
  auto gd = static_cast<double>(green) / 255;
  auto bd = static_cast<double>(blue) / 255;
  auto max = threeway_max(rd, gd, bd), min = threeway_min(rd, gd, bd);
   
  value = max;

  auto d = max - min;
  saturation = max == 0 ? 0 : d / max;

  hue = 0;
  if (max != min) {
    if (max == rd) hue = (gd - bd) / d + (gd < bd ? 6 : 0);
    else if (max == gd) hue = (bd - rd) / d + 2;
    else if (max == bd) hue = (rd - gd) / d + 4;
    hue /= 6;
  }
}

double inline ColorConverter :: threeway_max(double a, double b, double c) {
  return max(a, max(b, c));
}

double inline ColorConverter :: threeway_min(double a, double b, double c) {
  return min(a, min(b, c));
}

double ColorConverter :: hue2rgb(double p, double q, double t) {
  if (t < 0) t += 1;
  if (t > 1) t -= 1;
  if (t < 1 / 6.0) return p + (q - p) * 6 * t;
  if (t < 1 / 2.0) return q;
  if (t < 2 / 3.0) return p + (q - p) * (2 / 3.0 - t) * 6;
  return p;
}

#endif
