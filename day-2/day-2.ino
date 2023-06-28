int led12 = 12; //light is 12

void setup() {

pinMode(led12, OUTPUT);
digitalWrite(led12, LOW);

}

void dot() {
digitalWrite(led12, LOW);
delay(500);
digitalWrite(led12, HIGH);
delay(500);
}

void dash() {
digitalWrite(led12, LOW);
delay(500);
digitalWrite(led12, HIGH);
delay(1000);
}

void loop() {

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
