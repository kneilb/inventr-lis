#include <Arduino.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

const byte PIN_LENGTH = 4;
char current_pin[PIN_LENGTH] = { '0', '0', '0', '0'};

const byte ROW_PINS[ROWS] = {5, 4, 3, 2};
const byte COL_PINS[COLS] = {6, 7, 8, 13};

// map buttons to numbers, so we can use them as an index into TONES
const char BUTTONS[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

Keypad badgerButtons = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

const byte BUZZER_PIN = 12;

const byte RED_PIN = 11;
const byte GREEN_PIN = 10;
const byte BLUE_PIN = 9;

void setup()
{
    pinMode(BUZZER_PIN, OUTPUT);
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    // Locked initially = RED
    displayColour(128, 0, 0);

    Serial.begin(115200);
    delay(200);
    Serial.println("Press the star thingy for a new pin or the noughts and crosses grid to log in. If you forgot then its just bad luck. Nothing we can do for ya.");
}

void loop()
{
    char button_character = badgerButtons.waitForKey();

    if (button_character == '#')
    {
        giveInputFeedback();
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
        giveInputFeedback();
        bool access_allowed = validatePIN();

        if (access_allowed)
        {
            displayPinChangeColour();
            Serial.println("Hi. Press some random numbers i guess.");

            for (int i = 0; i < PIN_LENGTH; i++)
            {
                current_pin[i] = badgerButtons.waitForKey();

                if (i < (PIN_LENGTH - 1)) {
                    giveInputFeedback();
                    displayPinChangeColour();
                }
                Serial.print("*");
            }

            Serial.println();
            Serial.println("Yo did it!");
            Serial.println("Press the star thingy for a new pin or the noughts and crosses grid to log in.");
            giveSuccessFeedback();
        }
        else
        {
            // giveErrorFeedback();
            Serial.println("Bro, you messed up");
        }
    }
}

bool validatePIN()
{
    Serial.println("put in yo pin");

    for (int i = 0; i < PIN_LENGTH; ++i) {
        char button_character = badgerButtons.waitForKey();

        if (current_pin[i] != button_character) {
            giveErrorFeedback();
            Serial.println();
            Serial.print("yo, i fink ya messed up: ");
            Serial.println(button_character);
            return false;
        }

        if (i < (PIN_LENGTH - 1)) {
            giveInputFeedback();
        }

        Serial.print("*");
    }

    giveSuccessFeedback();
    Serial.println();
    Serial.println("Well done yo!");
    return true;
}

// Display a color by providing Red, Green and Blue intensities (0-255)
void displayColour(byte red, byte green, byte blue) {
  analogWrite(RED_PIN, red);      // Set red LED intensity using PWM
  analogWrite(GREEN_PIN, green);  // Set green LED intensity using PWM
  analogWrite(BLUE_PIN, blue);    // Set blue LED intensity using PWM
}


// A recognized button was pressed.  Give short beep and blue LED
void giveInputFeedback() {
  displayColour(0, 0, 0);    // Turn off LED while playing tone
  tone(BUZZER_PIN, 880, 200);
  delay(200);                // Delay while tone is playing because tone() returns immediately
  displayColour(0, 0, 128);  // Restore blue LED
}

// A matching PIN has been entered or a new PIN has been accepted.
// Play TADA! sound and display green LED
void giveSuccessFeedback() {
  displayColour(0, 0, 0);   // Turn off LED while playing tone
  tone(BUZZER_PIN, 300, 200);
  delay(200);               // Delay while tone is playing because tone() returns immediately

  tone(BUZZER_PIN, 500, 500);
  delay(500);               // Delay while tone is playing because tone() returns immediately
  displayColour(0, 128, 0); // Display green LED
}

// Bad PIN entered.  Play descending tone and display red LED
void giveErrorFeedback() {
  displayColour(0, 0, 0);     // Turn off LED while playing tone
  tone(BUZZER_PIN, 300, 200);
  delay(200);                 // Delay while tone is playing because tone() returns immediately

  tone(BUZZER_PIN, 200, 500); // Frequency = 200Hz, Duration = 200ms
  delay(500);                 // Delay while tone is playing because tone() returns immediately
  displayColour(128, 0, 0);   // Display red LED
}

void displayPinChangeColour() {
    displayColour(128, 40, 0);
}