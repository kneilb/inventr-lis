#include <Key.h>
#include <Keypad.h>

// The keypad has 4 rows, each with 4 columns.
const byte KEYPAD_ROWS = 4;
const byte KEYPAD_COLS = 4;

// Define which GPIO pins are connected to the devices
const byte KEYPAD_ROW_PINS[KEYPAD_ROWS] = {5, 4, 3, 2};
const byte KEYPAD_COL_PINS[KEYPAD_COLS] = {6, 7, 8, 9};
const byte BUZZER_PIN = 10;

// Map buttons to numbers
const char BUTTONS[KEYPAD_ROWS][KEYPAD_COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

Keypad heroKeypad = Keypad(makeKeymap(BUTTONS), KEYPAD_ROW_PINS, KEYPAD_COL_PINS, KEYPAD_ROWS, KEYPAD_COLS);

// The security PIN
const byte PIN_LENGTH = 4;
char current_pin[PIN_LENGTH] = {'0', '0', '0', '0'};

void setup()
{
    Serial.begin(9600);
    delay(200);
    Serial.println("Press * to enter new PIN or # to access the system.");
}

void loop()
{
    const char button_character = heroKeypad.waitForKey();

    tone(BUZZER_PIN, 880, 100);

    if (button_character == '#') {
        const bool access_allowed = validatePIN();
        if (access_allowed) {
            Serial.println("Welcome, authorised user. You may now being using the system.");
        }
        else {
            Serial.println("He's not the messiah, he's a very naughty boy!");
        }
    }

    if (button_character == '*') {
        const bool access_allowed = validatePIN();
        if (access_allowed) {
            changePIN();
        }
        else {
            Serial.println("He's not the messiah, he's a very naughty boy!");
        }
    }
}

bool validatePIN()
{
    Serial.println("Enter PIN to continue.");

    for (int i = 0; i < PIN_LENGTH; i++) {
        const char button_character = heroKeypad.waitForKey();
        tone(BUZZER_PIN, 880, 100);

        if (current_pin[i] != button_character) {
            Serial.println();
            Serial
        }
    }
}

void changePIN()
{

}
