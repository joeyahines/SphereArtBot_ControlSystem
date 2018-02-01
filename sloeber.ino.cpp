#ifdef __IN_ECLIPSE__
//This is a automatic generated file
//Please do not modify this file
//If you touch this file your change will be overwritten during the next build
//This file has been generated on 2018-02-01 11:20:35

#include "Arduino.h"
#include "Arduino.h"
#include <Servo.h>
#include "Axis.h"
#include "PaintBrush.h"
#include "PaintDish.h"
#include "Motor.h"
#include <Encoder.h>
#include "Device.h"
#include "Queue.h"
#include "SerialCommunication.h"
#include "LimitSwitch.h"

void setup() ;
void loop() ;
Queue createNewCommandQueue() ;
int getQueueSize() ;
Queue * getNewCommands(Queue * q) ;
double * getDoubleValuesFromStream(SerialCommunication stream, Double * doubleArrayPointer, int numberOfValues) ;
void runCommandQueue() ;
void reset() ;
int findCommandId(String c) ;
void moveTo(double lon, double lat) ;

#include "SystemCode.ino"


#endif
