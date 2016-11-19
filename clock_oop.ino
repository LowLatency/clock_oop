
//#include <LiquidCrystal_I2C.h>
//LiquidCrystal_I2C lcd(0x27, 2,  1,  0,  4,  5,  6,  7,  3, POSITIVE);

#include "Display.h"
//David lcd(0x27, 2,  1,  0,  4,  5,  6,  7,  3, POSITIVE); //full-fat
//David lcd(0x3F); //minimal  
Display lcd;         //fat-reduced

void setup() 
{
    lcd.begin(16, 2);
    lcd.backlight();            // not all libraries

}

void loop() 
{

    //int loc[] = {0,7,15};
    int loc[2][3] = {{0,7,15}, {0,0,15}};
    String myString[2][3] = {{"Time", "Alarm", ">"},{"","",">"}};

    lcd.clear();
    for (int row = 0; row < 2 ; row++ )
    {
      lcd.print_row(loc[row], myString[row], row);
    }
    
}
