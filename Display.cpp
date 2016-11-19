
#include "Display.h"

// we always need a class constructor
Display::Display(byte SLAVE, byte EN, byte RW, byte RS, byte D4, byte D5, byte D6, byte D7, byte BL, t_backlighPol POL)
    : LiquidCrystal_I2C(SLAVE, EN, RW, RS, D4, D5, D6, D7, BL, POL)
{
}

// implement the code
void Display::new_method(void)
{
    print("David");
}

/*
 * Print a single row with 3 columns. 
 * Handy for 2x16, 4x20, or larger displays with multiple rows.
 * 
 * Input:
 *  location = The start location to print the text
 *  text     = Text to print out
 *  row      = What row number to print to
 *  
 *  Example:
 *  LCD Display Setup 
 *  ------------------
 *  |Row 0           |
 *  |Row 1           |
 *  ------------------
 *  0       ->      15 
 *  
 *  Notes:
 *    - be mindful of text length because it can get overwritten
 *      if too long.
 */
void Display::print_row(int location[3], String text[], int row)
{
  //clear();
  for(int col = 0 ; col < 2 ; col++)
  {
    setCursor(location[col], row);
    print(text[col]);
  }
}

void Display::print_multi_row(int location[2][3], String text[2][3])
{
  //clear();
  for(int row = 0 ; row < 1 ; row++ )
  {
    for(int col = 0 ; col < 2 ; col++)
    {
      setCursor(location[row][col], row);
      print(text[row][col]);
    }
  }
}

int Display::main_menu(void)
{
  //int loc[] = {0,7,15};
  int loc[2][3] = {{0,7,15}, {0,0,15}};
  //String screen1[2][3] = {{"Time", "Alarm", ">"},{"","",">"}};
  //String screen2[2][3] = {{"Enable", "Exit", ">"},{"","",">"}};
  String screen[2][2][3] = {
    {
      {"Time", "Alarm", ">"},
      {"","",">"}
    },
    {
      {"Enable", "Exit", ">"},
      {"","",">"}
    }
  };

  for(int menu_screen = 0 ; menu_screen < 1 ; menu_screen++ )
  {
    print_multi_row(loc, screen[menu_screen]);
  }
}


