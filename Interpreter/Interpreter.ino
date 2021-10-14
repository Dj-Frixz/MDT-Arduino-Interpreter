#include <MDTape.h>

const byte BUTT = 6;  //"button", of course
const byte NIPPLE0 = A0;  //"the little thinghy you screw softly with your fingers"
const byte NIPPLE1 = A1;  //                             AKA "the potentiometers"
const char input[] = "10";  //input string
MDTape tape;

void setup() {
  pinMode(BUTT, INPUT_PULLUP);
  pinMode(NIPPLE0, INPUT);
  //pinMode(NIPPLE1, INPUT);
}

void loop() {
  while (digitalRead(BUTT)==HIGH){}
  if (digitalRead(BUTT)==LOW){
    tape.begin(input);
  }
  while (digitalRead(BUTT)==LOW){}  //waits for user to 'unpress' the button
  delay(500);
  while (digitalRead(BUTT)==HIGH){}
  if (digitalRead(BUTT)==LOW){
    tape.mainloop(NIPPLE0);
  }
}
