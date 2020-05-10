/*
  PotentioCtrl.h - Library for using a potentiometer
  Created by Tony Tiratay
  Released into the public domain.
*/

#ifndef PotentioCtrl_h
#define PotentioCtrl_h

#include "Arduino.h"


class PotentioCtrl 
{
  public:
	PotentioCtrl(int);
	void loop();
	void setRange(int, int); 
	int getValue();
    
  private:
	int _minRange;
	int _maxRange;
	byte _pin;
	int _value;
	void _update();

};

#endif
