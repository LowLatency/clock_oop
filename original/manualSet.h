
void manualSetTime(LiquidCrystal_I2C lcdDisplay)
{
  lcdDisplay.clear();
  while(checkAnyButton(button[0], button[1], button[2])){}

  bool  captive    = true;
  byte   menuSelect = 1;
  byte   newHour    = 0;
  byte   newMin     = 0;
  bool  AM         = false;

  int   newDay     = 1;
  int   newMonth   = 0;
  int   newYear    = 2016;

  byte   ndow;
  
  while(captive)
  {

    printmanualSetTime(lcdDisplay, menuSelect);
    
    while(menuSelect == 1)
    {
      if(digitalRead(button[0]) == HIGH)
      {
        // cycle hours
        
        delay(50);
        while(digitalRead(button[0]) == HIGH){}
        newHour++;
        if(newHour == 13)
        {
          newHour = 0;
        }

        lcdDisplay.setCursor(1, 1);
        if(newHour < 10)
        {
          lcdDisplay.print(" ");
        }
        lcdDisplay.print(newHour);
      }
      else if(digitalRead(button[1]) == HIGH)
      {
        // cycle mins

        delay(50);
        while(digitalRead(button[1]) == HIGH){}
        newMin++;
        if(newMin == 60)
        {
          newMin = 0;
        }

        lcdDisplay.setCursor(8, 1);
        if(newMin < 10)
        {
          lcdDisplay.print(" ");
        }
        lcdDisplay.print(newMin);
      }
      else if(digitalRead(button[2]) == HIGH)
      {
        while(digitalRead(button[2]) == HIGH){}
        menuSelect++;
        delay(100);
      }
    }
  
    printmanualSetTime(lcdDisplay, menuSelect);
    
    while(menuSelect == 2)
    {
      if(digitalRead(button[0]) == HIGH)
      {
        while(digitalRead(button[0]) == HIGH){}
        // cylce AM/PM
        AM = !AM;
        lcdDisplay.setCursor(1, 1);
        if(AM)
        {
          lcdDisplay.print("AM");
        }
        if(!AM)
        {
          lcdDisplay.print("PM");
        }
      }
      else if(digitalRead(button[1]) == HIGH)
      {
        // cycle day

        delay(50);
        while(digitalRead(button[1]) == HIGH){}
        newDay++;
        if(newDay == 32)
        {
          newDay = 1;
        }
        
        lcdDisplay.setCursor(8, 1);
        if(newDay < 10)
        {
          lcdDisplay.print(" ");
        }     
        lcdDisplay.print(newDay);
        
      }
      else if(digitalRead(button[2]) == HIGH)
      {
        while(digitalRead(button[2]) == HIGH){}
        menuSelect++;
        delay(100);
      }
    }
    
    printmanualSetTime(lcdDisplay, menuSelect);

    while(menuSelect == 3)
    {
      if(digitalRead(button[0]) == HIGH)
      {
        // cylce month
        delay(50);
        while(digitalRead(button[0]) == HIGH){}
        newMonth++;
        if(newMonth == 12)
        {
          newMonth = 0;
        }

        lcdDisplay.setCursor(1, 1);
        if(newMonth + 1 < 10)
        {
          lcdDisplay.print(" ");
        }
        lcdDisplay.print(newMonth + 1);
        
      }
      else if(digitalRead(button[1]) == HIGH)
      {
        // cycle year

        delay(50);
        while(digitalRead(button[1]) == HIGH){}
        newYear++;
        if(newYear == 2026)
        {
          newYear = 2016;
        }
        
        lcdDisplay.setCursor(7, 1);
        lcdDisplay.print(newYear);
      }
      else if(digitalRead(button[2]) == HIGH)
      {
        while(digitalRead(button[2]) == HIGH){}
        menuSelect++;
        delay(100);
      }
    }

    printmanualSetTime(lcdDisplay, menuSelect);

    while(menuSelect == 4)
    {
      if(digitalRead(button[1]) == HIGH)
      {
        lcdDisplay.clear();
        lcdDisplay.setCursor(0, 0);
        lcdDisplay.print(">>>Main Menu");
        delay(500);
        captive = false;
        menuSelect = 0;
        lcdDisplay.clear();
      }
      else if(digitalRead(button[2]) == HIGH)
      {

        if(AM && newHour == 12 && newMin != 0)
        {
          lcdDisplay.clear();
          lcdDisplay.setCursor(0, 0);
          lcdDisplay.print(">>Invalid Time<<");

          captive = true;
          menuSelect = 1;
        }
        else
        {
          // validate time
      
          lcdDisplay.setCursor(0, 1);
          if(newHour < 10)
          {
            lcdDisplay.print("0");
          }
          lcdDisplay.print(newHour);
          lcdDisplay.print(":");
          if(newMin < 10)
          {
            lcdDisplay.print("0");
          }
          lcdDisplay.print(newMin);
          if(AM)
          {
            lcdDisplay.print("AM ");
          }
          else
          {
            lcdDisplay.print("PM ");
          }
    
          lcdDisplay.print(newMonth + 1);
          lcdDisplay.print("/");
          lcdDisplay.print(newDay);
          lcdDisplay.print("/");
          lcdDisplay.print(newYear - 2000);
          
          

          if(!AM)
          {
            newHour += 12;
          }
            
          // set new time here
          ndow = dow(newYear, newMonth + 1, newDay) + 1;
          if(ndow == 7)
          {
            ndow = 0;
          }

          DateTime dt(newYear, newMonth, newDay, newHour, newMin, 0, ndow);
          rtc.setDateTime(dt); //Adjust date-time as defined 'dt' above
          
          //delay(5000);
          delay(500);
          lcdDisplay.clear();
          lcdDisplay.setCursor(0, 0);
          lcdDisplay.print(">>>Main Menu");
          
          captive = false;
          menuSelect = 0;
        }

        

        delay(500);
        lcdDisplay.clear();
      }
    }
  }
}

