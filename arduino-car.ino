#include "Wheels.h"

#define WHEEL_LEFT_N4_PIN 2
#define WHEEL_LEFT_N3_PIN 4
#define WHEEL_LEFT_SPEED_PIN 3
#define WHEEL_RIGHT_N1_PIN 7
#define WHEEL_RIGHT_N2_PIN 6
#define WHEEL_RIGHT_SPEED_PIN 5

Wheels wheels(
    WHEEL_LEFT_N3_PIN,
    WHEEL_LEFT_N4_PIN,
    WHEEL_LEFT_SPEED_PIN,
    WHEEL_RIGHT_N2_PIN,
    WHEEL_RIGHT_N1_PIN,
    WHEEL_RIGHT_SPEED_PIN
);

void setup() {
  wheels.init();
  wheels.setSpeed(180);
}

void loop() {
  wheels.forward();
  delay(3000);
  wheels.turnLeft();
  delay(1000);
  wheels.forward();
  delay(1000);
  wheels.turnRight();
  delay(1000);
  wheels.forward();
  delay(1000);
  wheels.stop();
  delay(3000);
}
