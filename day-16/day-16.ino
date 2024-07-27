#include <Arduino.h>
#include <TM1637Display.h>

const byte CLK_PIN = 6;
const byte DIO_PIN = 5;

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

const byte ALL_ON[] = {
    0b01111111,
    0b11111111,
    0b11111111,
    0b01111111
};

const byte DONE[] = {
    0b01011110,
    0b00111111,
    0b00110111,
    0b01111001
};

TM1637Display display = TM1637Display(CLK_PIN, DIO_PIN);

void setup() {
    display.setBrightness(7);
}

void loop() {
    display.clear();
    delay(1000);

    display.setSegments(ALL_ON);
    delay(1000);

    display.clear();
    delay(1000);

    for (int i = 0; i < 4; i++) {
        display.showNumberDecEx(1200, 0b01000000);
        delay(500);
        display.clear();
        delay(500);
    }

    // Show counter including negative sign for negative numbers
    // NOTE: negative numbers cannot be less than -999 since the negative sign
    //       uses the left most digit of the display.
    for (int i = -100; i <= 100; i++) {
        display.showNumberDec(i);
        delay(50);
    }
    delay(1000);

    // Clear the display (all segments off)
    display.clear();
    delay(1000);

    // Display the message "dOnE"
    display.setSegments(DONE);

    delay(10000);  // Delay 10 seconds and then repeat our demo.
}

