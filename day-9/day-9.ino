// We didn't do this one! :D

const int SENSOR_PIN = A0;
const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;
const unsigned int WAIT = 100;
const unsigned int BATTERY_CAPACITY = 50000;

unsigned int batteryLevel = 0;
unsigned int ticks = 0;

void setup()
{
    pinMode(RED_PIN, OUTPUT);
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(BLUE_PIN, OUTPUT);

    Serial.begin(9600);
}

void rgbColour(int red, int green, int blue)
{
    // Analogue write to a digital output is implemented via Pulse Width Modulation (PWM)
    // This is where the period of time the output is high vs. the period it's low is adjusted
    //
    //
    analogWrite(RED_PIN, red);
    analogWrite(GREEN_PIN, green);
    analogWrite(BLUE_PIN, blue);
}

double getBatteryPercentage()
{
    // custom function calculates battery charge percentage
    // and returns the result as a double precision number

    return (((double)batteryLevel / (double)batteryCapacity) * 100);
}

void ShowBatteryPercentage()
{
    //  send battery results to both serial and LED outputs
    //  calculate the charge percentage with a custom function...
    const int PercentFull = getBatteryPercentage();

    // print the elasped time
    Serial.print(ticks);
    Serial.print(" ms    charge at ");
    // print the percent charge
    Serial.print(PercentFull);
    // print a percent character and line return...
    Serial.println("%");

    // Now let's light the LED with the appropriate color...
    if (PercentFull > 75)
    {
        rgbColour(125, 125, 125); // white
    }
    else if (PercentFull > 50)
    {
        rgbColour(0, 125, 125); // blue-ish
    }
    else if (PercentFull > 25)
    {
        rgbColour(125, 80, 0); // yellow-ish
    }
    else
    {
        rgbColour(125, 0, 0); // red
    }

    // if (PercentFull > 0 && PercentFull <= 25) {
    //   rgbColour(125, 0, 0);  // red
    // } else if (PercentFull > 25 && PercentFull <= 50) {
    //   rgbColour(125, 80, 0);  // yellow-ish
    // } else if (PercentFull > 50 && PercentFull <= 75) {
    //   rgbColour(0, 125, 125);  // blue-ish
    // } else if (PercentFull > 75 && PercentFull < 100) {
    //   rgbColour(125, 125, 125);  // white
    // }
}

void loop()
{
    const int sensorValue = analogRead(SENSOR_PIN); // read the value from the sensor

    batteryLevel += sensorValue;
    ticks += WAIT;

    if (batteryLevel >= BATTERY_CAPACITY)
    {
        Serial.print(ticks);
        Serial.print(" ms     ");
        Serial.println("FULLY CHARGED");
        batteryLevel = BATTERY_CAPACITY; // to prevent integer from continuing to increase
        ticks = 0;
        // rgbColour(0, 125, 0); // Green for charging complete
        rgbColour(63, 35, 142); // da best colour evar!!!
        delay(30000);           // long pause
    }
    else
    {
        ShowBatteryPercentage();
    }

    delay(WAIT);
}
