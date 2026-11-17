/***
Example Code to make a stepper motor move without stopping the sketch
with 2 LEDs, one button & two leds + resume movement challenge
***/

// We are using the CheapStepper library
#include <CheapStepper.h>

// Connect pins 8,9,10,11 to IN1,IN2,IN3,IN4 on ULN2003 board
CheapStepper stepper (8,9,10,11);

// This number defines how many steps are needed per one revolution
// this is the case for miuzei, 4076/4096 for elegoo
// http://forum.arduino.cc/index.php?topic=71964.15
const int stepsPerRevolution = 1024;
bool moveClockwise = true;
int stepsLeft = 0; // how many steps are left from the current movement

const int buttonPin = 2;
bool button = 1;

void setup()
{
  // Start serial
  Serial.begin(9600);
  // set pinMode for button
  pinMode(buttonPin, INPUT_PULLUP);

  // Stepper Setups
  stepper.setRpm(6);  // The default is ~16.25rpm
  // Range: 6RPM - 14RPM when powered from Arduino
  //        2RPM - 24RPM when powered from other resources
  stepper.setTotalSteps(stepsPerRevolution); 
}

void loop() {
  
  if (digitalRead(buttonPin)) { // if button is not pressed

    if (button == 1) { // On button release
      Serial.println("Resume Movement"); 
      stepper.newMove(moveClockwise, stepsLeft); 
      button = 0;
    }
    stepper.run(); // keep the stepper moving
    // let's check how many steps are left in the current move:
      stepsLeft = stepper.getStepsLeft();

  } else { // if button is pressed
    
    if (button == 0) { // On button pressed
      stepsLeft = stepper.getStepsLeft();
      stepper.stop(); // this clears stepsLeft to 0
      button = 1;
    }  
    
  }

  // if the current move is done...
  if (stepsLeft == 0){
    Serial.println("Movement Done"); 
    // let's start a new move in the reverse direction
    moveClockwise = !moveClockwise; // reverse direction
    stepper.newMove(moveClockwise, stepsPerRevolution/3); // move 120 degrees from current position
  }

}