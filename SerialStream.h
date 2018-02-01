/*
 * SerialCommunication.h
 *
 *  Created on: Jan 1, 2018
 *      Author: joeya
 */

#ifndef SERIALCOMMUNICATION_H_
#define SERIALCOMMUNICATION_H_

#include "Arduino.h"

class SerialStream {
	bool waitForSerial();
	static const int ERROR = -999;
	static const int TIMEOUT = 10000;
	static const int BAUD_RATE = 9600;

	//const int TIMEOUT = 10000;
  
public:
	SerialStream();
  ~SerialStream();
  char getCharFromStream();
	String getStringFromStream();
  char getAlphaCharFromStream();
  char getDigitCharFromStream();
	int getIntFromStream();
	double getDoubleFromStream();
  double * getDoubleValuesFromStream(double *, int);

  void flushStream();
  bool streamAvailable();
  
  void printToStream(char);
  void printToStream(int);
  void printToStream(double);
  void printToStream(String);
  void printLnToStream(String);
  void printLineToStream();
  
};

#endif /* SERIALCOMMUNICATION_H_ */
