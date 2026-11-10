const int x_pin = A0; // A0 pin connected to VRX pin
const int y_pin = A1; // A1 pin connected to VRY pin
const int sw_pin = 2; // pin 2 connected to SW pin

int xValue = 0; // To store value of the X axis
int yValue = 0; // To store value of the Y axis
bool sw = 0;

void setup() {

  Serial.begin(9600);
  // pinMode for analog pins are by default as input
  pinMode(sw_pin, INPUT_PULLUP);
 }


 void loop() {

  // Read analog X and Y analog values
  xValue = analogRead(x_pin);
  yValue = analogRead(y_pin);
  sw = digitalRead(sw_pin);

  // Print data to Serial Monitor on Arduino IDE
  Serial.print("sw = ");
  Serial.print(sw);
  Serial.print("\t");
  Serial.print("x = ");
  Serial.print(xValue);
  Serial.print("\t");
  Serial.print("y = ");
  Serial.println(yValue);

  delay(100);

 }
