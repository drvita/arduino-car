# Car controller (IR, Bluetooth, proximity, line follower)

## Description

This repository contains a small Arduino sketch for a car/robot controller. It supports multiple control modes: IR remote control, Bluetooth control, proximity sensors (obstacle avoidance) and line following. The `Wheels` helper class controls the motors (now implemented header-only in `Wheels.h`).

## Features

- IR remote control input (IR receiver)
- Bluetooth control (e.g., HC-05/HC-06)
- Obstacle avoidance using proximity sensors (ultrasonic or IR distance)
- Line following using line sensor array
- Simple Wheels class that accepts left, right and PWM speed pins and exposes init(), forward(), stop(), turnLeft(), turnRight(), setSpeed()

## Files

- `main.ino` — main sketch. Instantiates `Wheels` and is the entry point for control logic.
- `Wheels.h` — header-only motor control class (direction pins + shared PWM speed pin).

## Wiring (example)

- Left wheel direction pin: D5
- Right wheel direction pin: D6
- Speed (PWM) pin / enable: D3 (must be PWM-capable)
- IR receiver: connect to an available digital pin (e.g., D7) and GND/VCC
- Bluetooth RX/TX: connect module TX->RX of board, module RX->TX of board (use voltage divider for 5V boards if needed)
- Proximity sensors: connect trigger/echo (ultrasonic) or signal pins (IR distance) to digital/analog pins as needed
- Line sensors: connect to analog/digital pins used by your sensor array

Adjust pin numbers in `main.ino` to match your wiring.

## Usage

1. Open the sketch (`main.ino`) in the Arduino IDE or use Arduino CLI.
2. Select the correct board and port.
3. Verify and upload.
4. Implement/control logic in `loop()` to switch between IR, Bluetooth, avoidance and line-following behaviors. The `Wheels` object provides simple motor commands.

Example (already in `main.ino`):

```cpp
// set up pins in main.ino
Wheels wheels(LEFT_PIN, RIGHT_PIN, SPEED_PIN);
void setup() {
  wheels.init();
  wheels.setSpeed(200);
  wheels.forward();
}
```

## Notes & assumptions

- `Wheels.h` assumes one direction pin per motor and a single shared PWM enable/speed pin. If your driver needs two direction pins per motor (H-bridge IN1/IN2) or individual PWM per motor, adapt the class accordingly.
- Ensure the `SPEED_PIN` is PWM-capable on your board.
- If using Bluetooth, remember to disable Serial Monitor or use a different serial port for debugging if conflicts occur.
- For smaller firmware size: header-only implementation reduces the need for separate compilation units, but keep an eye on flash usage when adding features.

## License

Use as you wish. Add a license file if you need one.
