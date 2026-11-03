/*
Demo Code for simple instrument using three push buttons and a passive buzzer
*/
const int buttonPin = 2;
const int buttonPin2 = 3;
const int buttonPin3 = 4;
const int buzzerPin = 8;

int state = 0;
int state2 = 0;
int state3 = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  state = digitalRead(buttonPin);
  state2 = digitalRead(buttonPin2);
  state3 = digitalRead(buttonPin3);
  
  if (state == 1 && state2 == 1 && state3 == 1){ // in c we write '&&' for 'and'  , '||' for 'or' , 
    noTone(buzzerPin);
  }

  if (state == 0) { //never use single equal in conditional statement
    tone(buzzerPin, 200);
  }
  if (state2 == 0) {
    tone(buzzerPin, 300);
  }
  if (state3 == 0) { 
    tone(buzzerPin, 400);
  }

  Serial.print("Button:");
  Serial.print(state);
  Serial.print(" ");
  Serial.print(state2);
  Serial.print(" ");
  Serial.println(state3);
}
