void enableAlarm(LiquidCrystal_I2C lcdDisplay, alarmProp alarmProperty[], byte numOfAlarms)
{
  lcdDisplay.clear();
  while(checkAnyButton(button[0], button[1], button[2])){}

  bool  captive       = true;
  byte  menuSelect    = 1;
  byte  alarm         = 0;
  byte  daySelect     = 0;
  char  weekDay[7][4] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
  char  dow[7]        = {'S','M','T','W','R','F','S'};

  while(captive)
  {
    printenableAlarm(lcdDisplay, menuSelect);

    if(menuSelect == 1)
    {
      lcdDisplay.setCursor(2, 1);
      lcdDisplay.print(alarm + 1);

      lcdDisplay.setCursor(8, 1);
      lcdDisplay.print("   ");
      lcdDisplay.setCursor(8, 1);

      if (alarmProperty[alarm].enable)
      {
        lcdDisplay.print("ON");
      }
      else
      {
        lcdDisplay.print("OFF");
      }
    }
    while(menuSelect == 1)
    {
      if(digitalRead(button[0]) == HIGH)
      {
        // cycle Alarm#
        
        delay(50);
        while(digitalRead(button[0]) == HIGH){}
        alarm++;
        if(alarm == numOfAlarms)
        {
          
          alarm = 0;
        }

        lcdDisplay.setCursor(2, 1);
        lcdDisplay.print(alarm + 1);

        lcdDisplay.setCursor(8, 1);
        lcdDisplay.print("   ");
        lcdDisplay.setCursor(8, 1);

        if (alarmProperty[alarm].enable)
        {
          lcdDisplay.print("ON");
        }
        else
        {
          lcdDisplay.print("OFF");
        }
      }

      if(digitalRead(button[1]) == HIGH)
      {
        // cycle Enable/Disable alarm
        
        delay(50);
        while(digitalRead(button[1]) == HIGH){}

        alarmProperty[alarm].enable = !alarmProperty[alarm].enable;

        lcdDisplay.setCursor(8, 1);
        lcdDisplay.print("   ");
        lcdDisplay.setCursor(8, 1);

        if (alarmProperty[alarm].enable)
        {
          lcdDisplay.print("ON");
        }
        else
        {
          lcdDisplay.print("OFF");
        }
      }
      
      else if(digitalRead(button[2]) == HIGH)
      {
        while(digitalRead(button[2]) == HIGH){}
        menuSelect++;
        delay(100);
      }
    }
  
    printenableAlarm(lcdDisplay, menuSelect);

    if(menuSelect == 2)
    {
      lcdDisplay.setCursor(0, 1);
      lcdDisplay.print(weekDay[daySelect]);
      
      lcdDisplay.setCursor(7, 1);
      lcdDisplay.print("   ");
      lcdDisplay.setCursor(7, 1);
      if (alarmProperty[alarm].day[daySelect])
      {
        lcdDisplay.print("ON");
      }
      else
      {
        lcdDisplay.print("OFF");
      }

      lcdDisplay.setCursor(4, 0);
      for (byte j = 0 ; j < 7 ; j++)
      {
        if(alarmProperty[alarm].day[j] == true)
        {
          lcdDisplay.print(dow[j]);
        }
        else
        {
          lcdDisplay.print("_");
        }
      }
    }
    
    while(menuSelect == 2)
    {
      if(digitalRead(button[0]) == HIGH)
      {
        // cycle day
        // 0-sunday, 6-saturday
        
        delay(50);
        while(digitalRead(button[0]) == HIGH){}
        daySelect++;
        if(daySelect == 7)
        {
          daySelect = 0;
        }

        lcdDisplay.setCursor(0, 1);
        lcdDisplay.print(weekDay[daySelect]);

        lcdDisplay.setCursor(7, 1);
        lcdDisplay.print("   ");
        lcdDisplay.setCursor(7, 1);
        if (alarmProperty[alarm].day[daySelect])
        {
          lcdDisplay.print("ON");
        }
        else
        {
          lcdDisplay.print("OFF");
        }

      }
      
      if(digitalRead(button[1]) == HIGH)
      {
        // cycle Enable/Disable day
        
        delay(50);
        while(digitalRead(button[1]) == HIGH){}

        lcdDisplay.setCursor(4, 0);

        // Toggles dat day
        alarmProperty[alarm].day[daySelect] = !alarmProperty[alarm].day[daySelect];


        
        for (byte j = 0 ; j < 7 ; j++)
        {
          if(alarmProperty[alarm].day[j] == true)
          {
            lcdDisplay.print(dow[j]);
          }
          else
          {
            lcdDisplay.print("_");
          }
        }
        
        lcdDisplay.setCursor(7, 1);
        lcdDisplay.print("   ");
        lcdDisplay.setCursor(7, 1);

        if (alarmProperty[alarm].day[daySelect])
        {
          //daysEnabled[alarm] &= ~(1 << daySelect);
          lcdDisplay.print("ON");
        }
        else
        {
          //daysEnabled[alarm] |= (1 << daySelect);
          lcdDisplay.print("OFF");
        }
        //lcdDisplay.setCursor(14, 1);
        //lcdDisplay.print(daySelect);
      }
      
      if(digitalRead(button[2]) == HIGH)
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
}

