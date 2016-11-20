
//void display_time(LiquidCrystal_I2C lcdDisplay, DateTime now, bool sayMonth, bool AMPM)
//void printAlarmProperty(LiquidCrystal_I2C lcd, alarmProp alarmProperty[], int totalAlarms)

byte button[3] = {12, 11, 3};

typedef struct{

	// ARM the alarm
	bool enable = false;

	//             Sun    Mon    Tue    Wed    Thu    Fri    Sat
	bool day[7] = {false, false, false, false, false, false, false};


	//DateTime timeframe;
	byte Hour = 0;
  byte Min  = 0;
  bool AM  = false;
  

} alarmProp;

bool checkAnyButton(byte left, byte center, byte right)
{
  return digitalRead(left) == HIGH || digitalRead(center) == HIGH || digitalRead(right) == HIGH;
}

void display_time(LiquidCrystal_I2C lcdDisplay, DateTime now, bool sayMonth, bool AMPM)
{
  char weekDay[][4] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };

  char monthAbb[][5] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" };

  lcdDisplay.home(); // set cursor to 0,0

  if (AMPM)
  {

    // set location for printing hours
    if (now.hour() < 10)
    {
      //lcdDisplay.setCursor(1,0);
      lcdDisplay.print(" ");
    }
    else if (now.hour() < 22)
    {
      if (now.hour() > 12)
      {
        //lcdDisplay.setCursor(1,0);
        lcdDisplay.print(" ");
      }
    }


    // prints hour
    if (now.hour() < 12)
    {
      lcdDisplay.print(now.hour(), DEC);
    }
    else
    {
      lcdDisplay.print(now.hour() - 12, DEC);
    }

    // prints divider
    lcdDisplay.print(":");

    //prints minute
    if (now.minute() < 10)
    {
      lcdDisplay.print("0");
    }

    lcdDisplay.print(now.minute(), DEC);

    // prints divider
    lcdDisplay.print(":");

    // prints seconds
    if (now.second() < 10)
    {
      lcdDisplay.print("0");
    }

    lcdDisplay.print(now.second(), DEC);

    // prints AM/PM
    lcdDisplay.setCursor(8, 0);
    if (now.hour() < 12)
    {
      lcdDisplay.print("AM");
    }
    else
    {
      lcdDisplay.print("PM");
    }
  }
  else
  {

    // prints hour
    if (now.hour() < 10)
    {
      //lcdDisplay.setCursor(1,0);
      lcdDisplay.print(" ");
    }

    lcdDisplay.print(now.hour(), DEC);

    // prints divider
    lcdDisplay.print(":");

    //prints minute
    if (now.minute() < 10)
    {
      lcdDisplay.print("0");
    }

    lcdDisplay.print(now.minute(), DEC);

    // prints divider
    lcdDisplay.print(":");

    // prints seconds
    if (now.second() < 10)
    {
      lcdDisplay.print("0");
    }

    lcdDisplay.print(now.second(), DEC);
  }


  byte dow = now.dayOfWeek();
  if(dow == 7)
  {
    dow = 0;
  }
  lcdDisplay.setCursor(12, 0);
  lcdDisplay.print(weekDay[dow]);

  lcdDisplay.setCursor(0, 1);

  if (sayMonth)
  {
    lcdDisplay.print(monthAbb[now.month()]);
    lcdDisplay.print(" ");
  }
  else
  {
    lcdDisplay.print(now.month(), DEC);
    lcdDisplay.print('/');
  }

  lcdDisplay.print(now.date(), DEC);

  if (sayMonth)
  {
    lcdDisplay.print(", ");
  }
  else
  {
    lcdDisplay.print('/');
  }

  lcdDisplay.print(now.year(), DEC);

  lcdDisplay.setCursor(13, 1);
  lcdDisplay.print((int)rtc.getTemperature());
  lcdDisplay.print("C");

}

void printAlarmProperty(LiquidCrystal_I2C lcd, alarmProp alarmProperty[], byte totalAlarms)
{
  char dow[7] = {'S','M','T','W','R','F','S'};
  
  for(byte i = 0 ; i < totalAlarms ; i++)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("#=");
    lcd.print(i + 1);
    
    lcd.setCursor(8, 0);
    lcd.print("Enable=");
    if(alarmProperty[i].enable == true)
    {
      lcd.print("Y");
    }
    else
    {
      lcd.print("N");
    }

    lcd.setCursor(0, 1);
    if(alarmProperty[i].Hour < 10)
    {
      lcd.print(" ");
      lcd.print(alarmProperty[i].Hour);
    }
    else
    {
      lcd.print(alarmProperty[i].Hour);
    }
    lcd.print(":");
    if(alarmProperty[i].Min < 10)
    {
      lcd.print("0");
      lcd.print(alarmProperty[i].Min);
    }
    else
    {
      lcd.print(alarmProperty[i].Min);
    }
    
    lcd.setCursor(8, 1);
    for (byte j = 0 ; j < 7 ; j++)
    {
      if(alarmProperty[i].day[j] == true)
      {
        lcd.print(dow[j]);
      }
      else
      {
        lcd.print("_");
      }
    }

    delay(750);
  }
}

