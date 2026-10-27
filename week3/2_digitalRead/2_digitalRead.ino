/*
Digital Read with Tilt Switch
*/
int value = 0;
const int pin = 2;

void setup() {
  Serial.begin(9600); // open the serial port at 9600 bps:
  pinMode(pin, INPUT_PULLUP);
}


void loop() {
  Serial.print("Tilt sensor:");
  Serial.println(digitalRead(pin));
} 
