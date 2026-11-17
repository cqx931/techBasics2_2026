/***
Example Code to make a stepper motor move
***/

// We are using the CheapStepper library
#include <CheapStepper.h>

// Connect pins 8,9,10,11 to IN1,IN2,IN3,IN4 on ULN2003 board
CheapStepper stepper (8,9,10,11); 

const int stepsPerRevolution = 1024;
// 360 -1024
// 60 - 1024/6

// This number defines how many steps are needed per one revolution (round)
// by default the value is 4096, the stepper motor in Miuzei(from the library) needs 1024.
// If your motor is only turning 90 degree instead of the full round
// you need to change this value to 4096

boolean moveClockwise = true;

void setup() {
  
  stepper.setRpm(10);  // the default is ~16.25rpm
  // 10 circles per minute, 1 circle -> 6s
  // 6s = 6000ms, 6 degree - 6000/60 = 100ms

  // we set to 10 for safe, high torque movement
  // -> 10 rounds per minute
  // Range: 6RPM - 14RPM when powered from Arduino
  //        2RPM - 24RPM when powered from other resources
  stepper.setTotalSteps(stepsPerRevolution); 
  Serial.begin(9600);
}

void loop() {
  // Ask the stepper motor to move one full round
  // pay attention that this is a block function
  // meaning it won't go to the next line until it finishes the movement
  stepper.moveDegrees (moveClockwise, 6);
  // use this line to observe the current step
  Serial.println(stepper.getStep()); 
  // wait
  delay(900); // 1s
}

