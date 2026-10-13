
void setup() {
  pinMode(13, OUTPUT);
  // put your setup code here, to run once:
}

void loop() {

  digitalWrite(13, HIGH); // on - 5v
  delay(1000); // 1000 milisecond

  digitalWrite(13, LOW); // off - 0v
  delay(1000);

  // put your main code here, to run repeatedly:
}
