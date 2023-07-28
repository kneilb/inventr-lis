const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;

void setup()
{
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);
}

void rgb_colour(int red, int green, int blue)
{
    // Analogue write to a digital output is implemented via Pulse Width Modulation (PWM)
    // This is where the period of time the output is high vs. the period it's low is adjusted
    //
    //
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}

void loop()
{
    rgb_colour(63, 35, 142); // da best colour evar!!!
    delay(800);
    return;
    rgb_colour(32, 0, 0); // red
    delay(800);
    rgb_colour(0, 125, 0); // green
    delay(800);
    rgb_colour(0, 0, 125); // blue
    delay(800);
    rgb_colour(64, 32, 0); // yellow
    delay(800);
    rgb_colour(125, 0, 125); // puple (sic)
    delay(800);
    rgb_colour(125, 125, 125); // white
    delay(2000);
}
