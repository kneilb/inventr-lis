const int sensorPin = A0;
const int onboardLED = 13;
const unsigned int batteryCapacity = 50000;
const unsigned int wait = 100;

unsigned int batteryLevel = 0;
unsigned int ticks = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(onboardLED, OUTPUT);
}

void printBatteryPercentage()
{
    Serial.print(ticks);
    Serial.print("ms  charge level at ");

    double percentFull = 100 * ((double)batteryLevel / (double)batteryCapacity);
    Serial.print(percentFull);

    Serial.println("%");
}

void loop()
{
    int sensorValue = analogRead(sensorPin);
    batteryLevel += sensorValue;
    ticks += wait;

    if (batteryLevel >= batteryCapacity)
    {
        Serial.print(ticks);
        Serial.println("ms  FULLY CHARGED");
        batteryLevel = batteryCapacity;
        ticks = 0;
        delay(20000);
    }
    else
    {
        printBatteryPercentage();
        delay(wait);
    }
}
