# Car controller (IR, Bluetooth, proximity, line follower)

## Description

This repository contains a small Arduino sketch for a car/robot controller. It supports multiple control modes: IR remote control, Bluetooth control, proximity sensors (obstacle avoidance) and line following. The `Wheels` helper class controls the motors (now implemented header-only in `Wheels.h`).

## Features

- IR remote control input (IR receiver)
- Bluetooth control (e.g., HC-05/HC-06)
- Obstacle avoidance using proximity sensors (ultrasonic or IR distance)
- Line following using line sensor array
- Wheels class now supports L298N H-bridge drivers (3 pins per motor) and exposes:
  - init(), forward(), reverse(), stop(), turnLeft(), turnRight()
  - setSpeed(uint8_t) to set both motors' speed
  - setSpeed(uint8_t leftSpeed, uint8_t rightSpeed) to set individual motor speeds

## Files

- `arduino-car.ino` — arduino-car sketch. Instantiates `Wheels` and is the entry point for control logic.
- `Wheels.h` — header-only motor control class for L298N (two direction pins + enable PWM pin per motor).

## Wiring (example for L298N)

Each motor needs three pins (L298N):

- Left motor:
  - Direction pin 1 (e.g., D4)
  - Direction pin 2 (e.g., D5)
  - Enable / PWM pin (e.g., D3) — must be PWM-capable
- Right motor:
  - Direction pin 1 (e.g., D6)
  - Direction pin 2 (e.g., D7)
  - Enable / PWM pin (e.g., D11) — must be PWM-capable

Other peripherals:

- IR receiver: connect to an available digital pin (e.g., D8) and GND/VCC
- Bluetooth RX/TX: connect module TX->RX of board, module RX->TX of board (use voltage divider for 5V boards if needed)
- Proximity sensors: connect trigger/echo (ultrasonic) or signal pins (IR distance) to digital/analog pins as needed
- Line sensors: connect to analog/digital pins used by your sensor array

Adjust pin numbers in `arduino-car.ino` to match your wiring.

## Usage

1. Open the sketch (`arduino-car.ino`) in the Arduino IDE or use Arduino CLI.
2. Select the correct board and port.
3. Verify and upload.
4. Implement/control logic in `loop()` to switch between IR, Bluetooth, avoidance and line-following behaviors. The `Wheels` object provides simple motor commands.

Example (already in `arduino-car.ino`):

```cpp
// set up pins for L298N in arduino-car.ino
// Wheels(leftDir1, leftDir2, leftEnable, rightDir1, rightDir2, rightEnable)
Wheels wheels(4, 5, 3, 6, 7, 11);

void setup() {
  wheels.init();
  wheels.setSpeed(200);           // set both motors to speed 200 (0-255)
  wheels.forward();               // move forward
  delay(2000);
  wheels.turnLeft();              // turn left
  delay(1000);
  wheels.reverse();               // move backward
  delay(1000);
  wheels.stop();                  // stop
}
```

## Notes & assumptions

- `Wheels.h` assumes two direction pins per motor (IN1/IN2) and one PWM enable pin per motor (L298N-style H-bridge). If your motor driver uses a different wiring scheme, adapt the class accordingly.
- Ensure the `SPEED_PIN` is PWM-capable on your board.
- If using Bluetooth, remember to disable Serial Monitor or use a different serial port for debugging if conflicts occur.
- For smaller firmware size: header-only implementation reduces the need for separate compilation units, but keep an eye on flash usage when adding features.

## License

This project is released under the MIT License — see the `LICENSE` file for details. In short: you are free to use, copy, modify and distribute this code.
