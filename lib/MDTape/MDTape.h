#ifndef MDTape_h
#define MDTape_h

#include "Arduino.h"
#include "MDTDisplay.h"
#include "string.h"

class MDTape
{
  public:
    MDTape();
    void begin(char input[], char first_state);
    char tape[102] = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\0'}; //101 spaces ;
    int curs;
    char state;
    char right();
    char left();
    void chvalue(char newval);
    void change_state(char newstate);
  private:
    MDTDisplay screen;
    void stamp();
};

#endif