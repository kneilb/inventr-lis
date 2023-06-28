const int sensorPin = A0;
const int onboardLED = 13;

void setup()
{
    Serial.begin(9600);
    pinMode(onboardLED, OUTPUT);
}

void loop()
{
    int sensorValue = analogRead(sensorPin);
    Serial.println(sensorValue);
    delay(sensorValue);
    digitalWrite(onboardLED, HIGH);
    delay(sensorValue);
    digitalWrite(onboardLED, LOW);
    delay(sensorValue);
}
