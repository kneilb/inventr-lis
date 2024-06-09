#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

const byte PIN_LENGTH = 4;
char current_pin[PIN_LENGTH] = { '0', '0', '0', '0'};

const byte ROW_PINS[ROWS] = {5, 4, 3, 2};
const byte COL_PINS[COLS] = {6, 7, 8, 9};

// map buttons to numbers, so we can use them as an index into TONES
const char BUTTONS[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

Keypad BadgerButtons = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

const byte BUZZER_PIN = 10;

void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);

    Serial.begin(9600);
    delay(200);
    Serial.println("Press the star thingy for a new pin or the noughts and crosses grid to log in. If you forgot then its just bad luck. Nothing we can do for ya.");
}

void loop()
{
    char button_character = BadgerButtons.waitForKey();

    // Frequency to use for tone
    tone(BUZZER_PIN, 880, 100);

    if (button_character == '#')
    {
        bool access_allowed = validatePIN();
        if (access_allowed)
        {
            Serial.println("Well done. You logged in. Even though this is the only reward. K bye.");
        }
        else
        {
            Serial.println("INTRUDER!!!!! or u forgot ur pin. probs more likely.");
            Serial.println("Press the star thingy for a new pin or the noughts and crosses grid to log in.");
        }
    }

    if (button_character == '*')
    {
        bool access_allowed = validatePIN();

        if (access_allowed)
        {
            Serial.println("Hi. Press some random numbers i guess.");

            for (int i = 0; i < PIN_LENGTH; i++)
            {
                button_character = BadgerButtons.waitForKey();
                tone(BUZZER_PIN, 880, 100);

                current_pin[i] = button_character;
                Serial.print("*");
            }

        }
    }
}

bool validatePIN()
{
    Serial.println("put in yo pin");

    for (int i = 0; i < PIN_LENGTH; i++) {
        char button_character = BadgerButtons.waitForKey();
        tone(BUZZER_PIN, 880, 100);

        if (current_pin[i] != button_character) {
            Serial.println();
            Serial.print("yo, i fink ya messed up");
            Serial.println(button_character);
            return false;
        }
        Serial.print("*");
    }

    Serial.println();
    Serial.println("Well done yo!");
    return true;
}