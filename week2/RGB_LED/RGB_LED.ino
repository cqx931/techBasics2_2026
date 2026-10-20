/***
This is the sample code for driving a RGB LED
***/

// It is important that you use pins that support PWM (with a ~ before the number)
int redPin= 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  // Initialize the ins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  setRGB(255, 0, 0); // Red Color
  delay(1000);
  setRGB(0, 255, 0); // Green Color
  delay(1000);
  setRGB(0, 0, 255); // Blue Color
  delay(1000);
  setRGB(255, 255, 0); // Yellow Color
  delay(1000);
  setRGB(170, 0, 255); // Purple Color
  delay(1000);
  setRGB(200, 200, 200); // White Color, less bright
  delay(1000);
}

void setRGB(int r, int g, int b) {
  analogWrite(redPin, r);
  analogWrite(greenPin, g);
  analogWrite(bluePin, b);
}