const int led12 = 12; // light is 12
const int switch1 = 2;

void setup()
{
    pinMode(led12, OUTPUT);
    pinMode(switch1, INPUT);
    digitalWrite(led12, LOW);
}

void dot()
{
    digitalWrite(led12, HIGH);
    delay(500);
    digitalWrite(led12, LOW);
    delay(500);
}

void dash()
{
    digitalWrite(led12, HIGH);
    delay(500);
    digitalWrite(led12, LOW);
    delay(1000);
}

void loop()
{

    if (digitalRead(switch1) == HIGH)
    {
        dot();
        dot();
        dot();

        dash();
        dash();
        dash();

        dot();
        dot();
        dot();
    }
}
/*


int LED = 12;
int Switch1 = 2;  //pin 2 will be attached to our switch

void setup() {
//setup both an output AND an input on the HERO
 pinMode(LED, OUTPUT);
 pinMode(Switch1, INPUT);

}


void loop() {
 //now within loop() we'll take actions based on the status of the input switch

//this is a conditional test...

  if (digitalRead(Switch1) == HIGH){
   digitalWrite(LED, LOW);
   delay(1000);
   digitalWrite(LED, HIGH);
   delay(100);
   digitalWrite(LED, LOW);
   delay(100);
   digitalWrite(LED, HIGH);
   delay(100);
 }
 else {
  digitalWrite(LED, LOW); // turn LED OFF
 }
}

*/