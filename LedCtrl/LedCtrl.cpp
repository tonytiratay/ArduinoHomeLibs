#include "Arduino.h"
#include "LedCtrl.h"
#include <millisDelay.h>



LedCtrl::LedCtrl(int pin)
{
  pinMode(pin, OUTPUT);
	_pin = pin;
	_on = false;
	_blinking = false;
	_blinkingDuration = 0;
	millisDelay ledDelay;
}

void LedCtrl::light(bool on)
{
	_on = on;
	_blinking = false;
}

void LedCtrl::loop()
{
	
	if(_blinking && ledDelay.justFinished()){
		toggle();	
		ledDelay.repeat();			
	} 
	digitalWrite(_pin, _on);
	
}

void LedCtrl::toggle()
{
	_on = !_on;
	
}


void LedCtrl::blink(int onDuration)
{
	if(!_blinking){
		_blinking = true;
		_on = false;
		_blinkingDuration = onDuration;
		ledDelay.stop();
		ledDelay.start(onDuration);
	} else {
		if(onDuration != _blinkingDuration){
			_on = false;
			_blinkingDuration = onDuration;
			ledDelay.stop();
			ledDelay.start(onDuration);
		}
	}
}

void LedCtrl::stopBlink()
{
	_blinking = false;
}


void LedCtrl::_handleBlinking()
{		
	if(ledDelay.justFinished()){
		toggle();	
		ledDelay.repeat();
		
	}	 
}
