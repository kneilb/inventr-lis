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

    return (((double)batteryLevel / (double)BATTERY_CAPACITY) * 100);
}

void showBatteryPercentage()
{
    // send battery results to both serial and LED outputs
    // calculate the charge percentage with a custom function...
    const int percentFull = getBatteryPercentage();

    // print the elapsed time
    Serial.print(ticks);
    Serial.print(" ms    charge at ");
    // print the percent charge
    Serial.print(percentFull);
    // print a percent character and line return...
    Serial.println("%");

    // Now let's light the LED with the appropriate color...
    if (percentFull > 75)
    {
        rgbColour(125, 125, 125); // white
    }
    else if (percentFull > 50)
    {
        rgbColour(0, 125, 125); // blue-ish
    }
    else if (percentFull > 25)
    {
        rgbColour(125, 80, 0); // yellow-ish
    }
    else
    {
        rgbColour(125, 0, 0); // red
    }

    // if (percentFull > 0 && percentFull <= 25) {
    //   rgbColour(125, 0, 0);  // red
    // } else if (percentFull > 25 && percentFull <= 50) {
    //   rgbColour(125, 80, 0);  // yellow-ish
    // } else if (percentFull > 50 && percentFull <= 75) {
    //   rgbColour(0, 125, 125);  // blue-ish
    // } else if (percentFull > 75 && percentFull < 100) {
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
        showBatteryPercentage();
    }

    delay(WAIT);
}
