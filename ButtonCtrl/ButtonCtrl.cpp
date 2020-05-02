#include "Arduino.h"
#include "ButtonCtrl.h"

ButtonCtrl::ButtonCtrl(int pin)
{
  pinMode(pin, INPUT);
  _pin = pin;
  _buttonPressed = false;
  _buttonLongPressed = false;
  _buttonLongTimer = 0;
  _longPressTime = 1000;
  _modes = 1;
  _mode = 0;
}

void ButtonCtrl::loop()
{
  _handlePress();
}

void ButtonCtrl::_handlePress()
{
  if(isPressed()){
      if(_buttonPressed == false){
        _buttonPressed = true;
        _buttonLongTimer = millis();
      }
      if ((millis() - _buttonLongTimer > _longPressTime) && (_buttonLongPressed == false)) {

        _buttonLongPressed = true;
      }
  } else {
      if(_buttonPressed && !_buttonLongPressed){
        _changeMode();
    }
      _buttonLongPressed = false;
			_buttonPressed = false;
		}
}

bool ButtonCtrl::isPressed()
{
  return digitalRead(_pin);
}

bool ButtonCtrl::isLongPressed()
{
  
  return _buttonLongPressed;
}


void ButtonCtrl::setModes(int modes)
{
  _modes = modes;
}

void ButtonCtrl::setMode(int mode)
{
  _mode = mode;
}

int ButtonCtrl::getMode()
{
  return _mode;
}


void ButtonCtrl::_changeMode()
{
  
  if(_mode == _modes){
    _mode = 0;
  } else {
    _mode++;
  }
}
