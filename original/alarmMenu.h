//  LCD Display Setup
// ------------------
// |Row 0           |
// |Row 1           |
// ------------------
// 0       ->      15


void printMain(LiquidCrystal_I2C lcdDisplay, byte select)
{
  byte row;
  if(select == 1)
  {
    lcdDisplay.clear();

    // Row 0
    row = 0;
    lcdDisplay.setCursor(0, row);
    lcdDisplay.print("Time");
    lcdDisplay.setCursor(7, row);
    lcdDisplay.print("Alarm");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");

    // Row 1
    row = 1;
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");
  }
  else if(select == 2)
  {
    lcdDisplay.clear();

    // Row 0
    row = 0;
    lcdDisplay.setCursor(0, row);
    lcdDisplay.print("Enable");
    lcdDisplay.setCursor(7, row);
    lcdDisplay.print("Exit");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");

    // Row 1
    row = 1;
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");
    
  }
}

void printmanualSetTime(LiquidCrystal_I2C lcdDisplay, byte select)
{
  byte row;
  if(select == 1)
  {
    lcdDisplay.clear();
    
    // Row 0
    row = 0;
    lcdDisplay.setCursor(0, row);
    lcdDisplay.print("Hour");
    lcdDisplay.setCursor(8, row);
    lcdDisplay.print("Min");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");

    // Row 1
    row = 1;
    lcdDisplay.setCursor(2, row);
    lcdDisplay.print("0");
    lcdDisplay.setCursor(9, row);
    lcdDisplay.print("0");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");
  }
  else if(select == 2)
  {
    lcdDisplay.clear();
    
    // Row 0
    row = 0;
    lcdDisplay.setCursor(0, row);
    lcdDisplay.print("Type");
    lcdDisplay.setCursor(7, row);
    lcdDisplay.print("Day");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");

    // Row 1
    row = 1;
    lcdDisplay.setCursor(1, row);
    lcdDisplay.print("PM");
    lcdDisplay.setCursor(9, row);
    lcdDisplay.print("1");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");
  }
  else if(select == 3)
  {
    lcdDisplay.clear();
    
    // Row 0
    row = 0;
    lcdDisplay.setCursor(0, row);
    lcdDisplay.print("Month");
    lcdDisplay.setCursor(7, row);
    lcdDisplay.print("Year");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");

    // Row 1
    row = 1;
    lcdDisplay.setCursor(2, row);
    lcdDisplay.print("1");
    lcdDisplay.setCursor(7, row);
    lcdDisplay.print("2016");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");

  }
  else if(select == 4)
  {
    lcdDisplay.clear();

    // Row 0
    //lcdDisplay.setCursor(0, 0);
    //lcdDisplay.print("Type");
    lcdDisplay.setCursor(5, 0);
    lcdDisplay.print("Cancel");
    lcdDisplay.setCursor(13, 0);
    lcdDisplay.print("Set");
  }
}

void printsetAlarm(LiquidCrystal_I2C lcdDisplay, byte select)
{
  byte row;
  
  if(select == 1)
  {
    lcdDisplay.clear();

    // Row 0
    row = 0;
    lcdDisplay.setCursor(0, row);
    lcdDisplay.print("Hour");
    lcdDisplay.setCursor(5, row);
    lcdDisplay.print("Min");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");

    // Row 1
    row = 1;
    lcdDisplay.setCursor(2, row);
    lcdDisplay.print("0");
    lcdDisplay.setCursor(6, row);
    lcdDisplay.print("0");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");
  }
  else if(select == 2)
  {
    lcdDisplay.clear();

    // Row 0
    row = 0;
    lcdDisplay.setCursor(0, row);
    lcdDisplay.print("Type");
    lcdDisplay.setCursor(5, row);
    lcdDisplay.print("Alarm");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");

    // Row 1
    row = 1;
    lcdDisplay.setCursor(0, row);
    lcdDisplay.print("PM");
    lcdDisplay.setCursor(7, row);
    lcdDisplay.print("1");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");
  }
  else if(select == 3)
  {
    lcdDisplay.clear();

    // Row 0
    row = 0;
    //lcdDisplay.setCursor(0, 0);
    //lcdDisplay.print("Type");
    lcdDisplay.setCursor(5, row);
    lcdDisplay.print("Cancel");
    lcdDisplay.setCursor(13, row);
    lcdDisplay.print("Set");
  }
}

void printenableAlarm(LiquidCrystal_I2C lcdDisplay, byte select)
{
  byte row;
  
  if(select == 1)
  {
    lcdDisplay.clear();

    // Row 0
    row = 0;
    lcdDisplay.setCursor(0, row);
    lcdDisplay.print("Alarm#");
    lcdDisplay.setCursor(8, row);
    lcdDisplay.print("EN");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");

    // Row 1
    row = 1;
    //lcdDisplay.setCursor(2, row);
    //lcdDisplay.print("1");
    //lcdDisplay.setCursor(8, row);     // Fix
    //lcdDisplay.print("EN");
    lcdDisplay.setCursor(15, row);
    lcdDisplay.print(">");
  }
  else if(select == 2)
  {
    lcdDisplay.clear();

    // Row 0
    row = 0;
    lcdDisplay.setCursor(0, row);
    lcdDisplay.print("Day");
    //lcdDisplay.setCursor(4, row);     // Fix
    //lcdDisplay.print("_______");
    lcdDisplay.setCursor(13, row);
    lcdDisplay.print("Set");

    // Row 1
    row = 1;
    

    
  }
}
