#ifndef MDTDisplay_h
#define MDTDisplay_h

#include "Arduino.h"
#include "LiquidCrystal.h"

class MDTDisplay
{
  public:
    MDTDisplay();
    void refresh(String tostamp);
    void chstate(char state);
  private:
    LiquidCrystal lcd;
};

#endif