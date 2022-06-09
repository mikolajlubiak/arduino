#include <AccelStepper.h>
AccelStepper s(4, 8, 9, 10, 11);
void setup() {
  s.setMaxSpeed(1000);
  s.setAcceleration(100);
  s.setSpeed(1000);
}
void loop() {
  s.moveTo(map(analogRead(0), 0, 1023, 0, 2038));
  s.run();
}
