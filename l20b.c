#include <stdio.h>

int getInt() {
  #include <stdbool.h>

  #define MAX_INT 999999999
  #define ASCII_NINE '9'
  #define ASCII_ZERO '0'


  bool isNegative = false;
  bool isValid = true;

  int asciiValue;
  int numStore;
  int rightDigit;

  do {
    isValid = true;
    isNegative = false;
    numStore = 0;

    asciiValue = getc(stdin);

    //if the first character is a negative, set is negative true, and get the next character
    if (asciiValue == '-') {
      isNegative = true;
      asciiValue = getc(stdin);
      if (asciiValue == '\n') {
        isValid = false;
      } 
    }

    while (asciiValue != '\n' && asciiValue != EOF) {

      // if the ascii character is out of the range, toss it
      if (asciiValue > ASCII_NINE || asciiValue < ASCII_ZERO) {
        isValid = false;
        break;
      }

      // rebuild the number from ascii
      rightDigit = asciiValue - ASCII_ZERO;
      numStore = numStore * 10;
      numStore = numStore + rightDigit;

      // if length is more than 9, toss it
      if (numStore > MAX_INT) {
        isValid = false;
        break;
      }

      asciiValue = getc(stdin);
    }

    // clear the buffer
    while (asciiValue != '\n' && asciiValue != EOF) {
      asciiValue = getc(stdin);
    }
   
  } while (!isValid);

  if (isNegative)  {
    numStore = numStore * -1;
  }

  return numStore;

}