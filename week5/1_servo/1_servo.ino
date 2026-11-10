
#include <Servo.h>
Servo myservo;

void setup() {
  // Attach pin 9 to the servo object
  myservo.attach(8);
}

void loop() {
  // Use for loop with delay to make servo move slower
  for (int pos = 0; pos <= 180; pos += 1) {
    // Tell servo to go to 'pos'
    myservo.write(pos); 
    delay(5);           
  } 
  delay(1000);
}
