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
SerialCommunication * inputStream;

// Command Variables **********************************************************
// Array to hold the names of all the commands
String commandList [] = {
		"Reset",		// Calibrates all devices encoders and return them to the mid position
		"MoveTo",		// Moves the brush to a point defined by the next two parameters from serial
};

// Holds the size of the command list
int commandListSize = sizeof(commandList)/sizeof(commandList[0]);

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

//TODO Add the rest of devices
Device * deviceList[] = {longitude, laditude};
int deviceListSize = sizeof(deviceList)/sizeof(deviceList[0]);

int commandsReceivied = 0;

Queue * commandQueue;

void setup() {
	inputStream = new SerialCommunication();
}

void loop() {
	if(Serial.available()) {
		if(inputStream->getStringFromSerial() == "new") {
			createNewCommandQueue();
			runCommandQueue();
			delete commandQueue;
		}
	}
}

Queue createNewCommandQueue() {
	int QueueSize = getQueueSize();
	Queue  * newQueue = new Queue(QueueSize);

	Serial.println("Ready to Accept Commands");

	newQueue = getNewCommands(newQueue);

	return newQueue;


}

int getQueueSize() {
	Serial.println("How many commands are in this queue?");
	int queueSize = inputStream->getIntFromSerial();

	while  (queueSize == -999) {
	  Serial.println("Error, int invalid");
	}

	return queueSize;
}

Queue * getNewCommands(Queue * q) {
    //Get all the commands from serial
    int commandsReceivied = 0;
    while (commandsReceivied < commandQueue->getSize()) {
  	  //Get the command

  	  String command = inputStream->getStringFromSerial();
  	  int commandId = findCommandId(command);

  	  //Get the number of values
  	  Serial.println("How many values?");

  	  int numberOfValues = inputStream->getIntFromSerial();

  	  Serial.println(numberOfValues);

  	  //Double array to store values
  	  double * values;
  	  values = getDoubleValuesFromStream(inputStream,values, numberOfValues);

  	  //add the command to the Queue
  	  commandQueue->addCommand(id, numberOfValues, values);

  	  commandsReceivied++;
    }
}

double * getDoubleValuesFromStream(SerialCommunication stream, Double * doubleArrayPointer, int numberOfValues) {
	for (int i = 0; i < numberOfValues; i++) {
		doubleArrayPointer[i] = stream->getDoubleFromSerial();
	}

	return doubleArrayPointer;
}

void runCommandQueue() {

	Queue::QueueNode * n = commandQueue->getNextCommand();
	while(n != 0) {
		/*
		switch(n->command) {
		case 0:
		}
		*/
		Serial.print(n->command + " ");
		Serial.print(n->numberOfValues + " ");
		Serial.println(n->values[0]);
		n = commandQueue->getNextCommand();
	}

}

/*	void reset()
 * 	Implements the reset command
 *
 * 	Reset Command
 * 	Calibrates all devices encoders and return them to the mid position
 */
void reset() {
	for (int i = 0; i < deviceListSize; i++) {
		deviceList[i]->reset();
	}
}

/*	int findCommandId(String c)
 * 	Finds the ID of a command string
 *
 * 	Parameters:
 * 	String	c	: String containg a command
 *
 * 	Returns:
 * 	int		id	: ID of the command in the switch statement or -1 for command
 * 				  not found
 *
 */
int findCommandId(String c) {
	// Stores the commandID
	int commandID = -1;
	// Variable for tracking current index in commandList
	int ndx = 0;

	// While the command has not been found and the end of the command list
	// reached
	while(commandID == -1 && ndx < commandListSize) {
		//If c is the command at ndx
		if(c == commandList[ndx]) {
			// commandID equals ndx
			commandID = ndx;
		}
		// Else increment ndx
		else {
			ndx++;
		}
	}

	// Return the command id
	return commandID;

}


void moveTo(double lon, double lat) {
	/*
	while () {
		if (longitude >= 0) {
			if(lon == longitude->setAngle(lon)) {

			}
		}
		if (longitude >= 0) {
			laditude->setAngle(lat);
		}

	}
*/
}
