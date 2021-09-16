#ifndef MDTDisplay_h
#define MDTDisplay_h

#include "Arduino.h"
#include "LiquidCrystal.h"

class MDTDisplay
{
  public:
    MDTDisplay();
    void begin();
    void refresh(char tostamp[16]);
    void chstate(char state);
  private:
    LiquidCrystal lcd;
};

#endif