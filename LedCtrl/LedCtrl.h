/*
  LedCtrl.h - Library for using a Led
  Created by Tony Tiratay
  Released into the public domain.
*/

#ifndef LedCtrl_h
#define LedCtrl_h

#include "Arduino.h"
#include <millisDelay.h>

class LedCtrl 
{
  public:
	LedCtrl(int);
    void toggle();
    void loop();
    void light(bool);
    void blink(int);
    void stopBlink();
    millisDelay ledDelay;
  private:
	int _pin;
	bool _on;
	bool _blinking;
	float _blinkDelay;
	void _handleBlinking();
	int _blinkingDuration;
	
};

#endif
