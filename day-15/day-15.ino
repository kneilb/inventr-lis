// Day 15: Creative Day!
//
// Type in numbers, and they'll be displayed on the 4 character 7 segment display!

#include <Key.h>
#include <Keypad.h>

#include <Arduino.h>
#include <TM1637Display.h>

const byte CLK_PIN = 13;
const byte DIO_PIN = 12;

const byte ROWS = 4;
const byte COLS = 4;

const byte rowPins[ROWS] = {5, 4, 3, 2};
const byte colPins[COLS] = {6, 7, 8, 9};

char counter = 0;

int digitOne = 0;
int digitTwo = 0;
int digitThree = 0;
int digitFour = 0;

/*
 * A 7-segment display is shaped like an "8" and has 7 segments (A through G) that can be
 * lit up. The diagram below shows the placement of each of the segments.
 *
 *   A
 * F   B
 *   G
 * E   C
 *   D
 *
 * A is the least significant bit (i.e. 0b00000001)
 * B is the next (0b00000010), and so on.
 * The most significant bit controls the colon on this display, but only for the middle 2 digits.
 *
 * There are also definitions called
 */

const char buttons[ROWS][COLS] =
    {
        {11, 12, 13, 43},
        {14, 15, 16, 44},
        {17, 18, 19, 45},
        {42, 10, 47, 46}};

TM1637Display display = TM1637Display(CLK_PIN, DIO_PIN);
Keypad myAwesomePad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

void setup()
{
    display.setBrightness(7);
    Serial.begin(115200);
}

void loop()
{
    char numberPressed = myAwesomePad.waitForKey();

    // if (numberPressed >= 43 || numberPressed == 44 || numberPressed == 45 || numberPressed == 46 || numberPressed == 47 || numberPressed == 42)
    if (numberPressed >= 42)
    {
        display.clear();
        counter = 0;
    }
    else
    {
      numberPressed = numberPressed - 10;

      if (counter == 0)
      {
        display.showNumberDecEx(numberPressed);
        digitOne = numberPressed;
        counter += 1;
      }
      else if (counter == 1)
      {
        digitTwo = digitOne * 10 + numberPressed;
        display.showNumberDecEx(digitTwo);
        counter += 1;
      }
      else if (counter == 2)
      {
        digitThree = digitTwo * 10 + numberPressed;
        display.showNumberDecEx(digitThree);
        counter += 1;
      }
      else if (counter == 3)
      {
        digitFour = digitThree * 10 + numberPressed;
        display.showNumberDecEx(digitFour);
        counter = 0;
      }
    }


    // int currentTotal = 0;
    // while (true) {
    //    numberPressed = getActualNumber();
    //    numberPressed -= 10;
    //    currentTotal = currentTotal * 10 + numberPressed;
    //    setLights(currentTotal);
    // }

}
