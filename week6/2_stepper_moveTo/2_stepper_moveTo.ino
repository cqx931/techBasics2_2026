/***
Example Code to make a stepper motor move to specific location
Notice that the Arduino sketch "pauses" during move()
***/

// We are using the CheapStepper library
#include <CheapStepper.h>

// Connect pins 8,9,10,11 to IN1,IN2,IN3,IN4 on ULN2003 board
CheapStepper stepper (8,9,10,11);

// This number defines how many steps are needed per one revolution
const int stepsPerRevolution = 1024;
boolean moveCW = true;

void setup()
{
  Serial.begin(9600);
  stepper.setRpm(10);  // the default is ~16.25rpm
  // Range: 6RPM - 14RPM when powered from Arduino
  //        2RPM - 24RPM when powered from other resources
  stepper.setTotalSteps(stepsPerRevolution); 
  stepper.moveTo(true, 0); // set to step 0
}

void loop() {
  stepper.moveTo(moveCW, stepsPerRevolution/4);  // Position: 90 degree
  Serial.println(stepper.getStep()); 
  delay(1000);
  stepper.moveTo(moveCW, stepsPerRevolution/2);  // Position: 180 degree
  Serial.println(stepper.getStep()); 
  delay(1000);
  stepper.moveTo(moveCW, stepsPerRevolution/4*3); // Position: 270 degree
  Serial.println(stepper.getStep()); 
  delay(1000);
  // not
  moveCW = !moveCW; 
}