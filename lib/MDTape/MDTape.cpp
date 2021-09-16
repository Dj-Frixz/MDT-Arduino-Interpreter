#include "Arduino.h"
#include "MDTDisplay.h"
#include "MDTape.h"
#include "string.h"

MDTape::MDTape()
{
  //char tape[102] = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\0'}; //101 spaces
  //tape = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','\0'}; //101 spaces 
  //int curs = 50;
  curs = 50;
  state = 0; //initializing variable
  MDTDisplay screen;
}

void MDTape::begin(char input[], char first_state)       //method to be called in setup
{
  state = first_state;
  screen.begin();
  for (int i=0; input[i]!='\0' && i<50; i++){
    tape[50+i] = input[i];
  }
  stamp();
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
  state = newstate; //updates current state
  screen.chstate(newstate);
}

void MDTape::stamp()
{
  char tostamp[16];
  for (int i=0; i<16; i++){
    tostamp[i] = tape[curs-7+i];
  }
  screen.refresh(tostamp);
}