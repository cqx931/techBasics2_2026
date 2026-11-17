/***
Example Code to make a stepper motor step
***/

// We are using the CheapStepper library
#include <CheapStepper.h>

// Connect pins 8,9,10,11 to IN1,IN2,IN3,IN4 on ULN2003 board
CheapStepper stepper (8,9,10,11); 


const int stepsPerRevolution = 1024; // 360

// This number defines how many steps are needed per one revolution (round)
// by default the value is 4096, the stepper motor in Miuzei needs 1024.
// If you are switching to another stepper motor, always check this value
// first before doing any other more complicated movements.

bool moveClockwise = true;
void setup() {
  
  stepper.setRpm(6);  // the default is ~16.25rpm
  // we set to 10 for safe, high torque movement
  // -> 10 rounds per minute
  // Range: 6RPM - 14RPM when powered from Arduino
  //        2RPM - 24RPM when powered from other resources
  stepper.setTotalSteps(stepsPerRevolution); 
  Serial.begin(9600);
}

void loop() {
  // let's move a full rotation (1024 mini-steps)
  // we'll go step-by-step using the step() function this time
  for (int s=0; s<stepsPerRevolution; s++){
     // // let's move one "step"
    stepper.step(moveClockwise);
    int nStep = stepper.getStep();
    // and if it's divisible by 64...
    if (nStep%64==0){ 
      // let's print the position to the console
      Serial.print("current step position: "); 
      Serial.print(nStep);
      Serial.println();
    }
  }
  delay(1000);
}

