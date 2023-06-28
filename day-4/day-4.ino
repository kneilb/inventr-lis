int led1 = 12;
int switch1 = 2;

int led2 = 11;
int switch2 = 3;

int led3 = 10;
int switch3 = 4;


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
  if (digitalRead(switch1) == HIGH)
  {
    digitalWrite(led1, HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
  }

  int s2 = digitalRead(switch2);
  digitalWrite(led2, s2);

  digitalWrite(led3, digitalRead(switch3));        
}
 