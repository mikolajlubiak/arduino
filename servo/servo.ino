#include <Servo.h>
Servo s;
void setup() {
  s.attach(9);
}

void loop() {
  s.write(map(analogRead(0), 0, 1023, 0, 180));
  delay(16);
}
