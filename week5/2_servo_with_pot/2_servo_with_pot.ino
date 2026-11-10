/****
Servo Example with potentiometer
***/

#include <Servo.h>   // Include the Servo library
Servo myservo;  // Create a servo object

const int pot_pin = A0;
int value = 0;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);  // Attach pin 9 to the servo object
}

void loop() {
  value = analogRead(pot_pin);
  Serial.println(value);
  value = map(value, 0, 1023, 0, 180);
  myservo.write(value);
}