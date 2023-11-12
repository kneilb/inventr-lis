#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

const byte rowPins[ROWS] = {5, 4, 3, 2};
const byte colPins[COLS] = {6, 7, 8, 9};

const char buttons[ROWS][COLS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}};

const char *stringLookup[] = {
    "JOHN", "DAD", "IS", "AND",
    "ARE", "COOL", "FUNNY", "ODD",
    "EPIC", "MUM", "BUT", "SLOW",
    "BEST", "TIED", "OBVIOUSLY", " "};

Keypad myAwesomePad = Keypad(makeKeymap(buttons), rowPins, colPins, ROWS, COLS);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    const char result = myAwesomePad.getKey();

    if (result != 0)
    {
        const char *string = stringLookup[result - 1];
        // Serial.println(result);
        Serial.println(string);
    }
}