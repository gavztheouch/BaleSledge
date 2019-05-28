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

void setup()
{
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(4, INPUT);
  pinMode(10, OUTPUT);
  pinMode(3, INPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  // read the state of the pushbutton value
  buttonState = digitalRead(2);
  // check if pushbutton is pressed.  if it is, the
  // buttonState is HIGH
  if (buttonState == HIGH) {
    // turn LED on
    digitalWrite(13, LOW);
    while (digitalRead(4) == LOW) {
      analogWrite(10, HIGH);
    }
    delay(1000); // Wait for 1000 millisecond(s)
    analogWrite(10, LOW);
    while (digitalRead(3) == LOW) {
      analogWrite(11, HIGH);
    }
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(11, LOW);
    digitalWrite(13, HIGH);
  } else {
    // turn LED off
    digitalWrite(13, HIGH);
  }
}
