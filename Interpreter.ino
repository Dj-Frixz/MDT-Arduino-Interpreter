#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int CURSOR_START = 7;
const int stpos = 1, inpos = 3, nxstpos = 5, outpos = 7, dirpos = 9;
const String MDT[] = {
  "(0,0,0,0,>)",
  "(0,1,0,1,>)",
  "(0,2,0,2,>)",
  "(0,3,0,3,>)",
  "(0,4,0,4,>)",
  "(0,5,0,5,>)",
  "(0,6,0,6,>)",
  "(0,7,0,7,>)",
  "(0,8,0,8,>)",
  "(0,9,0,9,>)",
  "(0,-,1,-,<)",
  "(0,=,0,=,>)",
  "(1,1,2,0,<)",
  "(1,2,2,1,<)",
  "(1,3,2,2,<)",
  "(1,4,2,3,<)",
  "(1,5,2,4,<)",
  "(1,6,2,5,<)",
  "(1,7,2,6,<)",
  "(1,8,2,7,<)",
  "(1,9,2,8,<)",
  "(1,0,1,9,<)",
  "(1,=,4,=,>)",
  "(1,-,6,=,<)",
  "(2,0,2,0,<)",
  "(2,1,2,1,<)",
  "(2,2,2,2,<)",
  "(2,3,2,3,<)",
  "(2,4,2,4,<)",
  "(2,5,2,5,<)",
  "(2,6,2,6,<)",
  "(2,7,2,7,<)",
  "(2,8,2,8,<)",
  "(2,9,2,9,<)",
  "(2,-,3,=,<)",
  "(2,=,3,=,<)",
  "(3,-,0,1,>)",
  "(3,0,0,1,>)",
  "(3,1,3,0,<)",
  "(4,9,4,9,>)",
  "(4,-,5,-,<)",
  "(5,9,5,-,<)",
  "(5,=,7,-,<)",
  "(6,-,6,0,>)",
  "(6,=,4,=,>)"
};
int cursor = 0;
char state = MDT[0].charAt(1);
const int TAPE_START = 50;

void setup() {
  lcd.begin(16, 2);
  String input_string = "10";
  char tape[100];
  for (int i=0; i<input_string.length(); i++){
    tape[TAPE_START+i] = input_string.charAt(i);
  }
  lcd.setCursor(0, 1);
  lcd.print("state:");
  lcd.setCursor(7, 1);
  lcd.print(state);
  lcd.setCursor(CURSOR_START, 0);
  lcd.print(input_string);
}

void loop() {
  
}
