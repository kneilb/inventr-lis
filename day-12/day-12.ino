#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

const byte BUZZER_PIN = 10;
const byte ROW_PINS[ROWS] = {5, 4, 3, 2};
const byte COL_PINS[COLS] = {6, 7, 8, 9};

// map buttons to numbers, so we can use them as an index into TONES
const char BUTTONS[ROWS][COLS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12},
    {13, 14, 15, 16}};

// a frequency tone for each button
const unsigned int TONES[ROWS * COLS] = {
    31, 93, 147, 208, 247, 311, 370, 440,
    523, 587, 698, 880,
    1397, 2637, 3729, 0 // Use frequency of 0 for bottom right key to end tone.
};

Keypad myAwesomePad = Keypad(makeKeymap(BUTTONS), ROW_PINS, COL_PINS, ROWS, COLS);

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    const char button_number = myAwesomePad.waitForKey();

    // Frequency to use for tone
    unsigned int tone_frequency = TONES[button_number - 1];

    Serial.print("Key: "); //   send the button_character to serial monitor...
    Serial.print(button_number + '0');
    Serial.print("   Freq: ");
    Serial.println(tone_frequency);

    // The tone() function plays a tone until stopped.  The code continues to run as the tone plays.
    if (tone_frequency > 0)
    {                                     // If tone frequency greater than 0...
        tone(BUZZER_PIN, tone_frequency); // ...then play the tone at that frequency until stopped
    }
    else
    {
        Serial.println("Stop tone");
        noTone(BUZZER_PIN); // Stop pressed (tone frequency of 0) so stop any tone playing
    }
}
