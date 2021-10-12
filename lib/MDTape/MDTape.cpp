#include "Arduino.h"
#include "MDTDisplay.h"
#include "MDTape.h"

MDTape::MDTape()
{
  MDTlength = 45;
  //cell = 0;               //selected cell value
  MDTDisplay screen;
  screen.begin();
  state = '0';
}

void MDTape::begin(char input[])       //method to be called in setup
{
  //Serial.begin(9600);
  _curs = 50;             //cursor
  state = MDT[0][stpos];  //initial state
  stbeg = 0;              //state beginning
  cell = input[0];
  //tape = {'-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-','-'}; //101 spaces
  for (int i=0; i<101; i++){
    tape[i] = '-';
  }
  //Serial.println(tape);
  for (int i=0; input[i]!='\0' && i<50; i++){
    tape[50+i] = input[i];
  }
  //Serial.println(tape);
  stamp();
  delay(50);
  change_state(state);
}

void MDTape::mainloop()
{
  while(1){
    delay(100);
    //Serial.println(tape);
    int row = search_input();      //returns next tuple based on input (cell) and current state
    if (row>=0){
      if (MDT[row][outpos] != cell){
        chvalue(MDT[row][outpos]);
      }
      switch(MDT[row][dirpos]){
        case '>': 
          cell = right(); 
          break;
        case '<': 
          cell = left(); 
          break;
        case '-': 
          break;
        default: 
          change_state('e');
          return;
      }
      if (state!=MDT[row][nxstpos]){
        if (search_state(MDT[row][nxstpos])==0){    //changes 'stbeg' with the first occurance of the 'nextstate'
          return;
        }else{
          delay(50);
          change_state(MDT[row][nxstpos]);     //updates state and prints the new state on screen
        }
      }
    }else if (row==-1){                             //missing row for the value in the cell
      return;
    }
  }
}

int MDTape::search_input()
{
  int i = stbeg;
  while(MDT[i][stpos]==state && cell!=MDT[i][inpos]){ //while state=current state and cell=tuple input
    i++;
  }
  if (MDT[i][stpos]!=state){
    i = -1;
  }
  return i;
}

int MDTape::search_state(char nextstate)
{
  int i = 0;
  while(i<MDTlength && MDT[i][stpos]!=nextstate){
    i++;
  }
  if (i==MDTlength){
    return 0;         //means nextstate is the final state
  }
  stbeg = i;          //sets position for next state search
  return 1;
}

char MDTape::right()
{
  _curs++;
  stamp();
  if (tape[_curs]==' '){
    return '-';
  }
  else{
    return tape[_curs];
  }
}

char MDTape::left()
{
  _curs--;
  stamp();
  if (tape[_curs]==' '){
    return '-';
  }
  else{
    return tape[_curs];
  }
}

void MDTape::chvalue(char newval)
{
  tape[_curs] = newval;
  stamp();
}

void MDTape::change_state(char newstate)
{
  state = newstate; //updates current state
  //Serial.print(state);
  //Serial.println(newstate);
  screen.chstate(state);
}

void MDTape::stamp()
{
  char tostamp[16];
  for (int i=0; i<16; i++){
    tostamp[i] = tape[_curs-7+i];
    //Serial.print(tostamp[i]);
  }
  //Serial.print(' ');
  //Serial.println(tostamp);
  screen.refresh(tostamp);
}