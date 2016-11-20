// MANDATORY
#include <Wire.h>               // I2C
#include <LCD.h>
#include <LiquidCrystal_I2C.h>  // Display
#include <Sodaq_DS3231.h>       // modified DateTime

#include "alarm_essentials.h"
#include "alarmMenu.h"

#include "alarm_serial.h"
#include "setAlarm.h"
#include "manualSet.h"
#include "enableAlarm.h"


#include "alarm_features.h"


// Future feature
//#include <EEPROM.h>

// Setup Config----------------
#define DS3231_I2C_ADDRESS 0x68
LiquidCrystal_I2C  lcd(0x3F, 2, 1, 0, 4, 5, 6, 7); // 0x27 is the I2C bus address for an unmodified backpack
byte totalAlarms = 4;
alarmProp alarms[4];
int melodyPin = 8;

//-----------------------------
#include "alarm_check.h"


//char weekDay[][4] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" }
//char monthAbb[][5] = {"Jan", "Feb", "Mar", "Apr", "May", "June", "July", "Aug", "Sept", "Oct", "Nov", "Dec" }

void setup() {
  // put your setup code here, to run once:
  // activate LCD module
  lcd.begin (16, 2); // for 16 x 2 LCD module
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);

  Wire.begin();
  //Serial.begin(19200);
  // set the initial time here:
  // DS3231 seconds, minutes, hours, day, date, month, year
  // setDS3231time(30,42,21,4,26,11,14);
  rtc.begin();

  // Setup pins
  pinMode(12, INPUT);   // Left button
  pinMode(11, INPUT);   // Center Button
  pinMode(3, INPUT);    // Right button
  pinMode(melodyPin, OUTPUT);   // Buzzer
  
}



void loop() {
  // put your main code here, to run repeatedly:
  DateTime now = rtc.now(); //get the current date-time

  display_time(lcd, now, true, true);

  for(byte i = 0 ; i < totalAlarms ; i++)
  {
    checkAlarm(lcd, alarms[i]);
  }

  // Get from serial console
  //getSerialTime();
  //DateTime newT = getSerialTime();

  


  // Menu Driver
  if (checkAnyButton(button[0], button[1], button[2]))
  {
    byte menuSelect = 1;
    bool captive = true;
    
    // debounce
    while(checkAnyButton(button[0], button[1], button[2])){}
    delay(50);
    
    while(captive)
    {
      
      printMain(lcd, menuSelect);
      
      while(menuSelect == 1)
      {
    	  if(digitalRead(button[0]) == HIGH)
    	  {
    		  lcd.clear();
          lcd.print("Set Time & Date");
          delay(1000);
          manualSetTime(lcd);
          captive = false;
          menuSelect = 0;
    	  }
    	  else if(digitalRead(button[1]) == HIGH)
    	  {
    		  lcd.clear();
          lcd.print("Set Alarm");
          delay(1000);
          setAlarm(lcd, alarms, totalAlarms);
          captive = false;
          menuSelect = 0;
    	  }
    	  else if(digitalRead(button[2]) == HIGH)
    	  {
          menuSelect = 2;
          delay(100);
    	  }
      }
  
      printMain(lcd, menuSelect);
      
      while(menuSelect == 2)
      {
        if(digitalRead(button[0]) == HIGH)
        {
          lcd.clear();
          lcd.print("Enable Alarm");
          delay(1000);
        enableAlarm(lcd, alarms, totalAlarms);
          lcd.clear();
          menuSelect = 0;
          captive = false;
        }
        else if(digitalRead(button[1]) == HIGH)
        {
          lcd.clear();
          menuSelect = 0;
          captive = false;
        }
        else if(digitalRead(button[2]) == HIGH)
        {
          menuSelect = 1;
          delay(100);
        }
      }
    }

    printAlarmProperty(lcd, alarms, totalAlarms);
    
    lcd.clear();
  }

  delay(50);
}

