#include "Arduino.h"
#include "MDTDisplay.h"
#include "MDTape.h"

MDTape::MDTape(String input, char first_state)
{
  char tape[102] = "-----------------------------------------------------------------------------------------------------"; //101 spaces
  int curs = 50;
  for (int i=0; i<input.length() && i<50; i++){
    tape[50+i] = input.charAt(i);
  }
  MDTDisplay screen();
  stamp();
  char state = first_state;
  change_state(state);
}

char MDTape::right()
{
  curs++;
  stamp();
  if (tape[curs]==' '){
    return '-';
  }
  else{
    return tape[curs];
  }
}

char MDTape::left()
{
  curs--;
  stamp();
  if (tape[curs]==' '){
    return '-';
  }
  else{
    return tape[curs];
  }
}

void MDTape::chvalue(char newval)
{
  tape[curs] = newval;
  stamp();
}

void MDTape::change_state(char newstate)
{
  screen.chstate(newstate);
}

void MDTape::stamp()
{
  String tostamp = tape;
  screen.refresh(tostamp.substring(curs-7,curs+9));
}