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

}

void (*pointerOnPress)();
void (*pointerOnLongPress)();

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
        pointerOnPress();
      }
      
      if(_buttonLongPressed){
        pointerOnLongPress();
      }
      
      _buttonLongPressed = false;
			_buttonPressed = false;
		}
}

void ButtonCtrl::onPress(void (*func)())
{
  pointerOnPress = func;
}

void ButtonCtrl::onLongPress(void (*func)())
{
  pointerOnLongPress = func;
}


bool ButtonCtrl::isPressed()
{
  return digitalRead(_pin);
}

bool ButtonCtrl::isLongPressed()
{
  
  return _buttonLongPressed;
}



