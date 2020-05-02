/*
  ButtonCtrl.h - Library for using a button
  Created by Tony Tiratay
  Released into the public domain.
*/

#ifndef ButtonCtrl_h
#define ButtonCtrl_h

#include "Arduino.h"

class ButtonCtrl 
{
  public:
    ButtonCtrl(int);
    bool isPressed();
    bool isLongPressed();
    void setModes(int);
    void setMode(int);
    int getMode();
    void loop();
    
  private:
    int _pin;
    bool _buttonPressed;
    bool _buttonLongPressed;
    unsigned long _buttonLongTimer;
    int _longPressTime;
    int _modes;
    int _mode;
    void _changeMode();
    void _handlePress();
};

#endif
