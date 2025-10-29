class Wheels {
public:
  // Constructor: left pin, right pin, speed (PWM) pin
  Wheels(uint8_t leftPin, uint8_t rightPin, uint8_t speedPin)
      : _leftPin(leftPin), _rightPin(rightPin), _speedPin(speedPin), _speed(255) {}

  // Initialize pins and leave wheels stopped
  void init() {
    pinMode(_leftPin, OUTPUT);
    pinMode(_rightPin, OUTPUT);
    pinMode(_speedPin, OUTPUT);
    stop();
  }

  // Move both wheels forward
  void forward() {
    digitalWrite(_leftPin, HIGH);
    digitalWrite(_rightPin, HIGH);
    analogWrite(_speedPin, _speed);
  }

  // Stop both wheels
  void stop() {
    analogWrite(_speedPin, 0);
    digitalWrite(_leftPin, LOW);
    digitalWrite(_rightPin, LOW);
  }

  // Turn left (left wheel stopped, right wheel moves)
  void turnLeft() {
    digitalWrite(_leftPin, LOW);
    digitalWrite(_rightPin, HIGH);
    analogWrite(_speedPin, _speed);
  }

  // Turn right (right wheel stopped, left wheel moves)
  void turnRight() {
    digitalWrite(_leftPin, HIGH);
    digitalWrite(_rightPin, LOW);
    analogWrite(_speedPin, _speed);
  }

  // Set speed (0-255) on the PWM speed pin
  void setSpeed(uint8_t speed) {
    _speed = speed;
    // If motors are running, update PWM immediately
    analogWrite(_speedPin, _speed);
  }

private:
  uint8_t _leftPin;
  uint8_t _rightPin;
  uint8_t _speedPin;
  uint8_t _speed;
};
