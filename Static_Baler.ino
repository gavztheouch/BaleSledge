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
