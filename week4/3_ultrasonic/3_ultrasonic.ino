/***
Ultrasonic distance sensor
***/

// Define the Trig and Echo pin connections
const int trigPin = 9;
const int echoPin = 10;

// Define variables to store duration and distance
long duration; // for potentially large number
int distance;

void setup() {
  // Start the serial communication
  Serial.begin(9600);

  // Define the Trig and Echo pins as Output and Input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin HIGH for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  Serial.print("Duration ");
  Serial.print(duration);
  Serial.print(" microseconds | ");

  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  // Displays the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Delay 500 milliseconds before next measurement
  delay(500);
}
