/***
This is the sample code for a simple circuit driving three LEDs (Red, Yellow, Green) on different pins
***/

// Define the pins for the LEDs
const int redLED = 2;
const int yellowLED = 3;
const int greenLED = 4;

void setup() {
  // Initialize the LED pins as outputs
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

void loop() {
  // Turn all LEDs on simultaneously
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, HIGH);
  delay(1000); // Wait for 1 second

  // Turn all LEDs off
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  delay(1000); // Wait for 1 second

  // Turn LEDs on in sequence
  digitalWrite(redLED, HIGH);
  delay(500); // Wait for 0.5 seconds
  digitalWrite(redLED, LOW);

  digitalWrite(yellowLED, HIGH);
  delay(500); // Wait for 0.5 seconds
  digitalWrite(yellowLED, LOW);

  digitalWrite(greenLED, HIGH);
  delay(500); // Wait for 0.5 seconds
  digitalWrite(greenLED, LOW);

  delay(1000); // Wait for 1 second before repeating the sequence
}