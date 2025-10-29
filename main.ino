#include "Wheels.h"

#define LEFT_PIN  5
#define RIGHT_PIN 6
#define SPEED_PIN 3

Wheels wheels(LEFT_PIN, RIGHT_PIN, SPEED_PIN);

void setup() {
  wheels.init();

  // Example usage (commented):
  wheels.setSpeed(200); // set speed 0-255
  wheels.forward();     // move forward
  delay(2000);
  wheels.turnLeft();    // turn left
  delay(1000);
  wheels.stop();        // stop
}

void loop() {
  // Main loop for robot/car logic
}