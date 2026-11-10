/****
Two Servos Controlled by a Joystick
***/

#include <Servo.h>   // Include the Servo library

Servo myservo1;  // Create the first servo object
Servo myservo2;  // Create the second servo object

const int x_pin = A0;
const int y_pin = A1;
const int sw_pin = 2;

int x_value = 0;
int y_value = 0;
int state = 1;

void setup() {
  myservo1.attach(8);  // Attach pin 8 to the servo object 1
  myservo2.attach(9);  // Attach pin 9 to the servo object 2
  // Init pins for Joystick
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);
  pinMode(sw_pin, INPUT_PULLUP);
}

void loop() {
  // Read all values
  x_value = analogRead(x_pin);
  y_value = analogRead(y_pin);
  state = digitalRead(sw_pin);

  // Map values for servos
  x_value = map(x_value, 0,1023,0,180);
  y_value = map(y_value, 0,1023,0,180);
  
  myservo1.write(x_value);
  myservo2.write(y_value);

  Serial.print("x=");
  Serial.print(x_value);
  Serial.print(" ");
  Serial.print("y=");
  Serial.print(y_value);
  Serial.print(" button:");
  Serial.println(state);

  if (state == 0) {
    // if button is pressed, do sth
  }
   
}