#include "LiquidCrystal.h"
#include "MDTDisplay.h"

MDTDisplay::MDTDisplay()
  : lcd(12, 11, 5, 4, 3, 2) //rs, en, d4, d5, d6, d7
{
  lcd.begin(16,2);
  lcd.setCursor(0,1);
  lcd.print("state:");
}

void MDTDisplay::refresh(String tostamp)
{
  lcd.setCursor(0,0);
  lcd.print(tostamp);
}

void MDTDisplay::chstate(char state)
{
  lcd.setCursor(7,1);
  lcd.print(state);
}