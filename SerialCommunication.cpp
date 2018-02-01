/*
 * SerialCommunication.cpp
 *
 *  Created on: Jan 1, 2018
 *      Author: joeya
 */

#include "SerialCommunication.h"

bool SerialCommunication::waitForSerial() {
  int count = 0;
	while (!Serial.available() && count < TIMEOUT) {
		count++;
		delay(5);
	}

	if (count < TIMEOUT) {
		return false;
	}
	else {
		return false;
	}
}

String SerialCommunication::getStringFromSerial() {
	return Serial.readStringUntil('\n');
}


int SerialCommunication::getIntFromSerial() {
  if(!waitForSerial()) {
    return ERROR;
  }
  else {
    return (int)Serial.parseInt();
  }
}

double * getDoubleValuesFromStream(double * doubleArrayPointer, int numberOfValues) {
	for (int i = 0; i < numberOfValues; i++) {
		doubleArrayPointer[i] = getDoubleFromSerial();
	}

	return doubleArrayPointer;
}

double SerialCommunication::getDoubleFromSerial() {
  if(!waitForSerial()) {
    return ERROR;
  }
  else {
    return (double)Serial.parseFloat();
  }
}

SerialCommunication::SerialCommunication() {
	Serial.begin(BAUD_RATE);
	// TODO Auto-generated constructor stub

}

