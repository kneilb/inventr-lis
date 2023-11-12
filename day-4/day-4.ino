const int led1 = 12;
const int switch1 = 2;

const int led2 = 11;
const int switch2 = 3;

const int led3 = 10;
const int switch3 = 4;

void setup()
{
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);

    pinMode(switch1, INPUT);
    pinMode(switch2, INPUT);
    pinMode(switch3, INPUT);
}

void loop()
{
    // 3 equivalent ways of doing the same thing.
    // Which is the best compromise between ease of understanding & repetition / wordiness?!

    if (digitalRead(switch1) == HIGH)
    {
        digitalWrite(led1, HIGH);
    }
    else
    {
        digitalWrite(led1, LOW);
    }

    const int s2 = digitalRead(switch2);
    digitalWrite(led2, s2);

    digitalWrite(led3, digitalRead(switch3));
}
