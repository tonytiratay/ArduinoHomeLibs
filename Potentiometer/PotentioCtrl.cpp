#include "Arduino.h"
#include "PotentioCtrl.h"
PotentioCtrl::PotentioCtrl(int pin)
{
  _pin = pin;
  _minRange = 0;
  _maxRange = 1023;
  _value = 0;
}


void PotentioCtrl::loop()
{
  _update();
}

void PotentioCtrl::_update()
{
	int val = analogRead(_pin);
	_value = map(val, 0, 1023, _maxRange, _minRange);
}

void PotentioCtrl::setRange(int min, int max)
{
	_minRange = min;
	_maxRange = max;
}

int PotentioCtrl::getValue()
{
	return _value;
}
