#include <MDTape.h>
#include <MemoryFree.h>

int button = 6;
char input[] = "10";                  //input string
MDTape tape;

void setup() {
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println(freeMemory());
}

void loop() {
  while (digitalRead(button)==HIGH){}
  if (digitalRead(button)==LOW){
    tape.begin(input);
    Serial.println(freeMemory());
  }
  while (digitalRead(button)==LOW){}  //waits for user to 'unpress' the button
  while (digitalRead(button)==HIGH){}
  if (digitalRead(button)==LOW){
    tape.mainloop();
    Serial.println(freeMemory());
  }
}
