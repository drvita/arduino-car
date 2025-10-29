class Wheels {
    public:
      // Constructor: left motor (dir1, dir2, enable), right motor (dir1, dir2, enable)
      Wheels(uint8_t leftDir1, uint8_t leftDir2, uint8_t leftEnable,
             uint8_t rightDir1, uint8_t rightDir2, uint8_t rightEnable)
          : _lDir1(leftDir1), _lDir2(leftDir2), _lEnable(leftEnable),
            _rDir1(rightDir1), _rDir2(rightDir2), _rEnable(rightEnable),
            _lSpeed(255), _rSpeed(255) {}

      // Initialize pins and leave wheels stopped
      void init() {
        pinMode(_lDir1, OUTPUT);
        pinMode(_lDir2, OUTPUT);
        pinMode(_lEnable, OUTPUT);
        pinMode(_rDir1, OUTPUT);
        pinMode(_rDir2, OUTPUT);
        pinMode(_rEnable, OUTPUT);
        stop();
      }

      // Move both wheels forward
      void forward() {
        leftForward();
        rightForward();
      }

      // Stop both wheels
      void stop() {
        leftStop();
        rightStop();
      }

      // Turn left: left stopped, right forward
      void turnLeft() {
        leftStop();
        rightForward();
      }

      // Turn right: right stopped, left forward
      void turnRight() {
        rightStop();
        leftForward();
      }

      // Set same speed for both motors (0-255)
      void setSpeed(uint8_t speed) {
        _lSpeed = speed;
        _rSpeed = speed;
        leftSetSpeed(_lSpeed);
        rightSetSpeed(_rSpeed);
      }

      // Set individual speeds for left and right (0-255)
      void setSpeeds(uint8_t leftSpeed, uint8_t rightSpeed) {
        _lSpeed = leftSpeed;
        _rSpeed = rightSpeed;
        leftSetSpeed(_lSpeed);
        rightSetSpeed(_rSpeed);
      }

    private:
      // Left motor control helpers (private - used internally)
      void leftForward() {
        // Convention: dir1 HIGH, dir2 LOW = forward
        digitalWrite(_lDir1, HIGH);
        digitalWrite(_lDir2, LOW);
        analogWrite(_lEnable, _lSpeed);
      }

      void leftStop() {
        analogWrite(_lEnable, 0);
        digitalWrite(_lDir1, LOW);
        digitalWrite(_lDir2, LOW);
      }

      void leftSetSpeed(uint8_t speed) { analogWrite(_lEnable, speed); }

      // Right motor control helpers (private - used internally)
      void rightForward() {
        // Convention: dir1 HIGH, dir2 LOW = forward
        digitalWrite(_rDir1, HIGH);
        digitalWrite(_rDir2, LOW);
        analogWrite(_rEnable, _rSpeed);
      }

      void rightStop() {
        analogWrite(_rEnable, 0);
        digitalWrite(_rDir1, LOW);
        digitalWrite(_rDir2, LOW);
      }

      void rightSetSpeed(uint8_t speed) { analogWrite(_rEnable, speed); }

      // Pin members
      uint8_t _lDir1;
      uint8_t _lDir2;
      uint8_t _lEnable;
      uint8_t _rDir1;
      uint8_t _rDir2;
      uint8_t _rEnable;

      // Current speeds
      uint8_t _lSpeed;
      uint8_t _rSpeed;
    };
