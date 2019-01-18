void LCDSetup()
{
  lcd.init();                      // initialize the lcd
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  //setLCD("ONEDPRO Project", "ONEBOX v.2");
}

void setLCDLine1(String msg)
{
  if (lastMsg1 != msg)
  {
    lcd.setCursor(0, 0);
    lcd.print(msg + "                ");
    lastMsg1 = msg;
  }
}

void setLCDLine2(String msg)
{
  if (lastMsg2 != msg)
  {
    lcd.setCursor(0, 1);
    lcd.print(msg + "                ");
    lastMsg2 = msg;
  }
}

void setLCD(String msg1, String msg2)
{
  if (lastMsg1 != msg1 || lastMsg2 != msg2)
  {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msg1);
  lastMsg1 = msg1;
  lcd.setCursor(0, 1);
  lcd.print(msg2);
  lastMsg2 = msg2;
  }
}

void setLCD(String msg1)
{
  setLCD(msg1,"");
}

void clearLCD(){
  lcd.clear();
  lastMsg1 = "";
  lastMsg2 = "";
}


