#include <MDTape.h>

int button = 6;
char input[] = "10";                  //input string
MDTape tape;

void setup() {
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  while (digitalRead(button)==HIGH){}
  if (digitalRead(button)==LOW){
    tape.begin(input);
  }
  while (digitalRead(button)==LOW){}  //waits for user to 'unpress' the button
  while (digitalRead(button)==HIGH){}
  if (digitalRead(button)==LOW){
    tape.mainloop();
  }
}
