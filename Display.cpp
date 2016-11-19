
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




