/*
Passive Buzzer with Serial.parseInt
*/
const int buzzer_pin = 8;
int input = 0;

void setup() {
   pinMode(buzzer_pin,OUTPUT);
   Serial.begin(9600);
   delay(100);
   Serial.println("Give the sequence you want to play");
 }


void loop() {

  while (Serial.available() == 0) {
    // wait for a message from serial
  }

  input = Serial.parseInt();
  Serial.read(); // to avoid extra 0
  Serial.println(input);

  tone(buzzer_pin, input, 500);
  delay(600);
}