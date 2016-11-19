//  LCD Display Setup
// ------------------
// |Row 0           |
// |Row 1           |
// ------------------
// 0       ->      15

#ifndef Display_H_

//something about checking for duplicate includes? not 100% sure. didnt look much
#define Display_H_

// WE NEED THIS!
#include <LiquidCrystal_I2C.h>

// Inherit the library.
class Display : public LiquidCrystal_I2C {

  
  byte row;
  
  private:
  //wat put here?
  
  public:
      // declare the full-fat constructor with default arguments
      Display(byte SLAVE = 0x27, byte EN = 2, byte RW = 1, byte RS = 0, byte D4 = 4, byte D5 = 5, byte D6 = 6, byte D7 = 7, byte BL = 3, t_backlighPol POL = POSITIVE);

      void new_method(void);
      void printMain(void);
      void print_row(int location[3], String text[], int row);


};

#endif
