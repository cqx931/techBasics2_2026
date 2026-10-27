/*
Use LDR to control an LED
*/
int readingValue = 0;
const int ledPin = 2;

void setup() {
  // open the serial port at 9600 bps:
  Serial.begin(9600); 
  pinMode(A0,INPUT); // LDR is connected to A0
  pinMode(ledPin, OUTPUT);
}


void loop() {
  // get reading from A0
  readingValue = analogRead(A0);
  Serial.println(readingValue);
  if (readingValue < 500) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
} 
