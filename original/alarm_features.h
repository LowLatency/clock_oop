
// old enableAlarm - Does not work
/*
byte enableAlarm(LiquidCrystal_I2C lcdDisplay, byte alarmEnable, byte daysEnabled[7])
{
  lcd.clear();
  while(digitalRead(3) == HIGH || digitalRead(11) == HIGH || digitalRead(12) == HIGH){}

  bool  captive       = true;
  int   menuSelect    = 1;
  int   alarm         = 0;
  int   daySelect     = 0;
  char  weekDay[7][4] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

  while(captive)
  {
    printenableAlarm(lcdDisplay, menuSelect);

    while(menuSelect == 1)
    {
      if(digitalRead(12) == HIGH)
      {
        // cycle Alarm#
        
        delay(50);
        while(digitalRead(12) == HIGH){}
        alarm++;
        if(alarm == 9)
        {
          alarm = 1;
        }

        lcdDisplay.setCursor(1, 1);
        lcdDisplay.print(alarm);

        lcdDisplay.setCursor(8, 1);
        lcdDisplay.print("   ");
        lcdDisplay.setCursor(8, 1);

        if ((alarmEnable & (1 << alarm - 1)) != 0)
        {
          lcdDisplay.print("ON");
        }
        else
        {
          lcdDisplay.print("OFF");
        }
      }

      if(digitalRead(11) == HIGH)
      {
        // cycle Enable/Disable alarm
        
        delay(50);
        while(digitalRead(11) == HIGH){}

        alarmEnable ^= 1 << alarm - 1;

        lcdDisplay.setCursor(8, 1);
        lcdDisplay.print("   ");
        lcdDisplay.setCursor(8, 1);

        if ((alarmEnable & (1 << alarm - 1)) != 0)
        {
          lcdDisplay.print("ON");
        }
        else
        {
          lcdDisplay.print("OFF");
        }
      }
      
      else if(digitalRead(3) == HIGH)
      {
        while(digitalRead(3) == HIGH){}
        menuSelect++;
        delay(100);
      }
    }
  
    printenableAlarm(lcdDisplay, menuSelect);

    while(menuSelect == 2)
    {
      if(digitalRead(12) == HIGH)
      {
        // cycle day
        // 0-sunday, 6-saturday
        
        delay(50);
        while(digitalRead(12) == HIGH){}
        daySelect++;
        if(daySelect == 7)
        {
          daySelect = 0;
        }

        lcdDisplay.setCursor(0, 1);
        lcdDisplay.print(weekDay[daySelect]);

        lcdDisplay.setCursor(8, 1);
        lcdDisplay.print("   ");
        lcdDisplay.setCursor(8, 1);

        if ((daysEnabled[alarm] & (1 << daySelect)) != 0)
        {
          lcdDisplay.print("ON");
        }
        else
        {
          lcdDisplay.print("OFF");
        }        
      }
      
      if(digitalRead(11) == HIGH)
      {
        // cycle Enable/Disable day
        
        delay(50);
        while(digitalRead(11) == HIGH){}

        daysEnabled[alarm] ^= (1 << daySelect);

        lcdDisplay.setCursor(8, 1);
        lcdDisplay.print("   ");
        lcdDisplay.setCursor(8, 1);

        if ((daysEnabled[alarm] & (1 << daySelect)) != 0)
        {
          lcdDisplay.print("ON");
        }
        else
        {
          lcdDisplay.print("OFF");
        }
      }
      
      if(digitalRead(3) == HIGH)
      {
        lcdDisplay.clear();
        lcdDisplay.setCursor(0, 0);
        lcdDisplay.print(">>>Main Menu");
        delay(500);
        captive = false;
        menuSelect = 0;
        lcdDisplay.clear();
      }
    }
  }
return alarmEnable;
}
*/


