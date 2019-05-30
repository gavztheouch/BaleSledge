/*
 * Static Baler
 * 
 * Turns on converyor belt, stops conveyor belt then moves ram back and forward stopping at limit
 * switches. Finally Turns Conveyor belt back on.
 * 
 * Conveyor belt is controlled via a relay that turns motor on and off. pin 8 switch pulls down to ground
 * 
 * by Gavin Armstrong
 * Stirling, Scotland
 * created 26 May 2019
 */

// constants won't change

const int conveyor = 8;      //Conveyor relay
const int ramOut = 9;        //Push ram out solenoid 
const int ramIn = 10;        //Push ram in solenoid

// variables will change:

int conveyor = 0;
int ram = 0;


void setup() {
  //initalize the Conveyor and hydraulic ram pins as an outputs:
 
  pinMode(conveyor, OUTPUT);
  pinMode(ramOut, OUTPUT);
  pinMode(ramIn, OUTPUT);

  // initalize conveyor switch and ram limit switches as inputs:
  pinMode(conveyorPin, INPUT_PULLUP);
  pinMode(ramInPin, INPUT_PULLUP);
  pinMode(ramOutPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

  

}



/////////////////////

/*
  Button
  Turns on and off a light emitting diode(LED)
  connected to digital  pin 13, when pressing a
  pushbutton attached to pin 2.

   The circuit:
  * LED attached from pin 13 to ground
  * pushbutton attached to pin 2 from +5V
  * 10K resistor attached to pin 2 from ground
  * Note: on most Arduinos there is already an LED
  on the board  attached to pin 13.

  created 2005  by DojoDave <http://www.0j0.org>

  modified 30 Aug 2011  by Tom Igoe

  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Button
*/

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:

pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);
pinMode(4, INPUT_PULLUP);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);

buttonState = digitalRead(2);
if (buttonState == HIGH){
  digitalWrite(8, HIGH);
  while (digitalRead(3) == HIGH) {
    digitalWrite(9, LOW);
    }
    digitalWrite(9, HIGH);
    while (digitalRead(4) == HIGH){
      digitalWrite(10, LOW);
      }
      digitalWrite(10, HIGH);
      digitalWrite(8, HIGH);
} else {
        digitalWrite(8,LOW);
      }
  }
