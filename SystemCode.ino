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


// Serial Variables
SerialStream * inputStream;

// Device Objects 
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
Axis * longitude;
Axis * laditude;

//TODO implment PaintDish and PaintBursh
// PaintDish

// Paint Brush

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  ladMotor1 = new Motor(6, 30, 32, 1.0, false);
  longMotor1 = new Motor(4, 26, 28, 1.0, false);
  
	inputStream = new SerialStream();
  longitude = new Axis(longMotor1, longMotor2, &longEncoder1, &longEncoder2, longSwitchTop, longSwitchBottom, 180.0);
  laditude = new Axis(ladMotor1, ladMotor2, &ladEncoder1, &ladEncoder2, ladSwitchTop, ladSwitchBottom, 360.0);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  interpreter();
  sendCommandComplete();
  digitalWrite(LED_BUILTIN, LOW);
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
    case 'f': freeControlInterpreter();
         break;
    default: inputStream->printToStream("Error, command type not found\n");    
             inputStream->printToStream(commandType);     
             inputStream->printLineToStream();     
  }
}

void axisCommandInterpreter(int commandID) {
  switch(commandID) {
    case 0: resetSphere();
            break;
    case 1: moveSphereDrectlyToPos();
            break;
  }
}

void resetSphere() {
  longitude->reset();
  delay(1000);
  laditude->reset();
}

void moveSphereDrectlyToPos() {
  double * lonLadPos = new double[2];
  inputStream->getDoubleValuesFromStream(lonLadPos,2);
  
  double longitudePos = lonLadPos[0];
  double laditudePos = lonLadPos[1];
  
  longitude->setAngle(longitudePos);
  laditude->setAngle(laditudePos);
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
            break;
  }
}

void freeControlInterpreter() {
    int ladSpeed = inputStream->getIntFromStream();
    int longSpeed = inputStream->getIntFromStream();
    ladMotor1->setMotorSpeed(ladSpeed);
    longMotor1->setMotorSpeed(longSpeed);
}

void sendCommandComplete() {
  inputStream->printToStream("6\n");
}



