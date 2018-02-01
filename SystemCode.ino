#include "Arduino.h"
#include <Servo.h>
#include "Axis.h"
#include "PaintBrush.h"
#include "PaintDish.h"
#include "Motor.h"
#include <Encoder.h>
#include "Device.h"
#include "SerialStream.h"

#include "LimitSwitch.h"

/*
 *
 *
 *
 *
 * Error Table
 * | Error Number	| Error Name		|	Description
 * | 0				| Command Not Found	|	The inputed command is not in the commandList.
 * |
 */

// Serial Variables
SerialStream * inputStream;

// Device Objects *************************************************************
// Motors
// Longitude Axis
Motor * longMotor1;
Motor * longMotor2;

// Latitude Axis
Motor * ladMotor1;
Motor * ladMotor2;

// Servos
Servo * brush;
Servo * paintDish;

// Sensors
// Longitude Axis
Encoder longEncoder1(2,22);
Encoder  longEncoder2(3,23);
LimitSwitch * longSwitchTop;
LimitSwitch * longSwitchBottom;

// Latitude Axis
Encoder ladEncoder1(18,24);
Encoder ladEncoder2(19,25);
LimitSwitch * ladSwitchTop;
LimitSwitch * ladSwitchBottom;

// Axes
Axis * longitude = new Axis(longMotor1, longMotor2, &longEncoder1, &longEncoder2, longSwitchTop, longSwitchBottom, 180.0);
Axis * laditude = new Axis(ladMotor1, ladMotor2, &ladEncoder1, &ladEncoder2, ladSwitchTop, ladSwitchBottom, 360.0);

//TODO implment PaintDish and PaintBursh
// PaintDish

// Paint Brush

void setup() {
	inputStream = new SerialStream();
}

void loop() {
  interpreter();
  inputStream->printToStream(6);
  delay(1);
}
void interpreter() {
  char commandType = inputStream->getAlphaCharFromStream();
  int commandID = inputStream->getIntFromStream();
  switch(commandType) {
    case 'a': axisCommandInterpreter(commandID);
         break;
    case 'g': gantryCommandInterpreter(commandID);
         break;
    case 'p': paintBrushCommandInterpreter(commandID);
         break;
    default: inputStream->printToStream("Error, command type not found\n");     
  }
}

void axisCommandInterpreter(int commandID) {
  switch(commandID) {
    case 0: longitude->reset();
            laditude->reset();
            break;
    case 1: break;
  }
}

void gantryCommandInterpreter(int commandID) {
  switch(commandID) {
    case 0: inputStream->printToStream("Reset\n");
            break;
    case 1: break;
  }
}

void paintBrushCommandInterpreter(int commandID) {
  switch(commandID) {
    case 0: inputStream->printToStream("Reset\n"); 
  }
}

