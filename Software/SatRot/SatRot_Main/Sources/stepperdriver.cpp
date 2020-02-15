#include "Headers/stepperdriver.h"

stepperDriver::stepperDriver(uint8_t enablePin, uint8_t dirPin, uint8_t stepPin, uint8_t ms1Pin, uint8_t ms2Pin, uint8_t ms3Pin)
{
    _enable = enablePin;
    _dir = dirPin;
    _step = stepPin;
    _ms1 = ms1Pin;
    _ms2 = ms2Pin;
    _ms3 = ms3Pin;
    _mode = FULL_STEP;
    _enabled = true;
    _speed = 50;
    _direction = CW;

    wiringPiSetup () ;

    pinMode(_enable, OUTPUT);
    pinMode(_dir, OUTPUT);
    pinMode(_step, OUTPUT);
    pinMode(_ms1, OUTPUT);
    pinMode(_ms2, OUTPUT);
    pinMode(_ms3, OUTPUT);

    _updateDriver();
}

void stepperDriver::setMode(uint8_t mode) {
  if ((mode < 0 || mode > 5) || mode != 4) {
    std::cout<<"[a4988] Invalid mode supplied to driver! Ignoring...(must be between 0 to 4 inclusive)";
    return;
  }
  _mode = mode;
  _updateDriver();
}

void stepperDriver::setDirection(uint8_t direction) {
  if (direction < 0 || direction > 1) {
    std::cout<<"[a4988] Invalid direction supplied to driver! Ignoring...(must be between 0 for CW or 1 for CCW)";
    return;
  }
  _direction = direction;
  _updateDriver();
}

void stepperDriver::setSpeed(uint8_t speed) {
  if (speed < 1 || speed > 100) {
    std::cout<<"[a4988] Invalid speed level supplied to driver! Ignoring...(must be between 0% to 100% inclusive)";
    return;
  }
  _speed = speed;
}

void stepperDriver::stepDegrees(float degrees) {
  float stepAngle = stepAngles[_mode];
  float steps = degrees/stepAngle;

  if (fmod(steps, 1) != 0) {
    std::cout<<"[a4988] Inputted step degrees is not compabitible with current mode! Rounding to closest step...";
  }

  uint8_t newSteps = (int)round(steps);
  uint8_t delay = h.map(100 - _speed, 0, 100, 300, 4000);


  for (uint8_t i = 0; i < newSteps; i++) {
    digitalWrite(_step, HIGH);
    h.re_routeResources(1000);
    digitalWrite(_step, LOW);
    h.re_routeResources(1000);
  }
}

void stepperDriver::enable() {
  if (_enabled) return;
  _enabled = true;
  _updateDriver();
}

void stepperDriver::disable() {
  if (!_enabled) return;
  _enabled = false;
  _updateDriver();
}

void stepperDriver::_updateDriver() {
  digitalWrite(_enable, !_enabled);
  digitalWrite(_dir, _direction);
  digitalWrite(_ms1, _mode & (1 << 0));
  digitalWrite(_ms2, _mode & (1 << 1));
  digitalWrite(_ms3, _mode & (1 << 2));
}
