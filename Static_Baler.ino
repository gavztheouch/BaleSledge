/*
  Bale Sledge

  Created by Gavin Armstrong
  May 2019

*/



int buttonState = 0;

void setup() {
  // put your setup code here, to run once:

  pinMode(2, INPUT_PULLUP);    // Bale switch
  pinMode(3, INPUT_PULLUP);    // Ram in limit
  pinMode(4, INPUT_PULLUP);    // Ram out limit
  pinMode(8, OUTPUT);          // Conveyor relay
  pinMode(9, OUTPUT);          // Ram out relay
  pinMode(10, OUTPUT);         // Ram in relay

  // Turn off ram relays and start conveyor
  
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  
  //reset the bale arm if it is not in correct positon
  
  while (digitalRead(4) == HIGH) {
    digitalWrite(9, LOW);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);

  buttonState = digitalRead(2);
  if (buttonState == HIGH) {
    digitalWrite(8, HIGH);
    while (digitalRead(3) == HIGH) {
      digitalWrite(9, LOW);
      delay(500); //move ram for extra 0.5 second to make sure it seats
    }
    digitalWrite(9, HIGH);
    while (digitalRead(4) == HIGH) {
      digitalWrite(10, LOW);
      delay(500);  //move ram for extra 0.5 second to make sure it seats
    }
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH);   // This might need to be low?
  } else {
    digitalWrite(8, LOW);
  }
}
