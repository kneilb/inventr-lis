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
 */

const byte ZERO[] =
{
    0b00000000,
    0b00000000,
    0b00000000,
    0b00111111
};

const char buttons[ROWS][COLS] =
{
    {1, 2, 3, 43},
    {4, 5, 6, 44},
    {7, 8, 9, 45},
    {42, 41, 47, 46}
};

TM1637Display display = TM1637Display(CLK_PIN, DIO_PIN);
Keypad myAwesomePad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

void setup()
{
    display.setBrightness(7);
}

void loop()
{
    const char numberPressed = myAwesomePad.waitForKey();

    // could have done if (numberPressed >= 42) :)
    if (numberPressed == 43 || numberPressed == 44 || numberPressed == 45 || numberPressed == 46 || numberPressed == 47 || numberPressed == 42) {
        display.clear();
    }
    else if (numberPressed == 41)
    {
        display.setSegments(ZERO);
    }
    else {
        display.showNumberDecEx(numberPressed);
    }
}