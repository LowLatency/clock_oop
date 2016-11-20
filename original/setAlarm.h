void setAlarm(LiquidCrystal_I2C lcdDisplay, alarmProp alarmProperty[], byte numOfAlarms)
{
  lcdDisplay.clear();
  while(checkAnyButton(button[0], button[1], button[2])){}

  bool  captive    = true;
  byte   menuSelect = 1;
  byte   aHour      = 0;
  byte   aMin       = 0;
  bool   aAM        = false;
  byte   aNum       = 0;
  
  DateTime tempTime();

  while(captive)
  {
    printsetAlarm(lcdDisplay, menuSelect);

    while(menuSelect == 1)
    {
      if(digitalRead(button[0] ) == HIGH)
      {
        // cycle hours
        
        delay(50);
        while(digitalRead(button[0]) == HIGH){}
        aHour++;
        if(aHour == 13)
        {
          aHour = 0;
        }

        if(aHour < 10)
        {
          lcdDisplay.setCursor(1, 1);
          lcdDisplay.print("  ");
          lcdDisplay.setCursor(2, 1);
        }
        else
        {
          lcdDisplay.setCursor(1, 1);
        }
        lcdDisplay.print(aHour);
      }
      else if(digitalRead(11) == HIGH)
      {
        // cycle mins

        delay(50);
        while(digitalRead(11) == HIGH){}
        aMin++;
        if(aMin == 60)
        {
          aMin = 0;
        }
        if(aMin < 10)
        {
          lcdDisplay.setCursor(5, 1);
          lcdDisplay.print("  ");
          lcdDisplay.setCursor(6, 1);
        }
        else
        {
          lcdDisplay.setCursor(5, 1);
        }
        lcdDisplay.print(aMin);
      }
      else if(digitalRead(3) == HIGH)
      {
        while(digitalRead(3) == HIGH){}
        menuSelect++;
        delay(100);
      }
    }

    printsetAlarm(lcdDisplay, menuSelect);
    
    while(menuSelect == 2)
    {
      if(digitalRead(button[0]) == HIGH)
      {
        while(digitalRead(button[0]) == HIGH){}
        // cylce AM/PM
        aAM = !aAM;
        lcdDisplay.setCursor(0, 1);
        if(aAM)
        {
          lcdDisplay.print("AM");
        }
        if(!aAM)
        {
          lcdDisplay.print("PM");
        }
      }
      else if(digitalRead(11) == HIGH)
      {
        delay(50);
        while(digitalRead(11) == HIGH){}
        aNum++;
        if(aNum == numOfAlarms)
        {
          aNum = 0;
        }
        
        lcdDisplay.setCursor(6, 1);
        if(aNum < 10)
        {
          lcdDisplay.print(" ");
        }
        lcdDisplay.print(aNum + 1);
        
      }
      
      else if(digitalRead(3) == HIGH)
      {
        while(digitalRead(3) == HIGH){}
        menuSelect++;
        delay(100);
      }
      
    }
  
    printsetAlarm(lcdDisplay, menuSelect);

    while(menuSelect == 3)
    {
      if(digitalRead(11) == HIGH)
      {
        lcdDisplay.clear();
        lcdDisplay.setCursor(0, 0);
        lcdDisplay.print(">>>Main Menu");
        delay(500);
        captive = false;
        menuSelect = 0;
        lcdDisplay.clear();
      }

      else if(digitalRead(3) == HIGH)
      {
        // validate time
    
        lcdDisplay.setCursor(0, 1);
        if(aHour < 10)
        {
          lcdDisplay.print("0");
        }
        lcdDisplay.print(aHour);
        lcdDisplay.print(":");
        
        if(aMin < 10)
        {
          lcdDisplay.print("0");
        }
        lcdDisplay.print(aMin);
        if(aAM)
        {
          lcdDisplay.print("AM ");
        }
        else
        {
          lcdDisplay.print("PM ");
        }

        lcdDisplay.print("Alarm#");
        if(aNum < 10)
        {
          lcdDisplay.print(" ");
        }
        lcdDisplay.print(aNum + 1);
        
        //delay(5000);
      
        if(aAM && aHour == 12 && aMin != 0)
        {
          lcdDisplay.clear();
          lcdDisplay.setCursor(0, 0);
          lcdDisplay.print("<<Invalid Time>>");
          delay(500);
          captive = true;
          menuSelect = 1;
        }
        else
        {

          // Save alarm time
          if(aAM == false)
          {
            alarmProperty[aNum].Hour  = aHour + 12;
          }
          else
          {
            alarmProperty[aNum].Hour = aHour;
          }
          alarmProperty[aNum].Min = aMin;
                    
          lcdDisplay.clear();
          lcdDisplay.setCursor(0, 0);
          lcdDisplay.print(">>>Main Menu");
          delay(500);
          captive = false;
          menuSelect = 0;
        }
          
        // set new time here
      
        lcdDisplay.clear();
      }
    }
  }

  
}

