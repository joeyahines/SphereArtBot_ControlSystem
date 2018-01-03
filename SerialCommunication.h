/*
 * SerialCommunication.h
 *
 *  Created on: Jan 1, 2018
 *      Author: joeya
 */

#ifndef SERIALCOMMUNICATION_H_
#define SERIALCOMMUNICATION_H_

#include "Arduino.h"

class SerialCommunication {
	bool waitForSerial();
	static const int ERROR = -999;
	static const int TIMEOUT = 10000;
	static const int BAUD_RATE = 9600;

	//const int TIMEOUT = 10000;
public:
	SerialCommunication();
	String getStringFromSerial();
	int getIntFromSerial();
	double getDoubleFromSerial();
};

#endif /* SERIALCOMMUNICATION_H_ */
