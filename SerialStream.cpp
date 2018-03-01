/*
 * SerialStream.cpp
 *
 *  Created on: Jan 1, 2018
 *      Author: joeya
 */

#include "SerialStream.h"

bool SerialStream::waitForSerial() {
  int count = 0;
	while (!Serial.available()) {
		delay(5);
	}

  return true;

	/*if (count < TIMEOUT) {
		return false;
	}
	else {
		return false;
	}
 */
}

char SerialStream::getAlphaCharFromStream() {
  char alpha = getCharFromStream();

  if (isalpha(alpha)) {
    return alpha;
  }
  else {
    return 0;
  }
}
char SerialStream::getDigitCharFromStream() {
  char digit = getCharFromStream();

  if (isdigit(digit)) {
    return digit;
  }
  else {
    return 0;
  }
}

char SerialStream::getCharFromStream() {
  if(!waitForSerial()) {
    return "Error";
  }
  char c = Serial.read();

  if (c < 0) {
    return 0;
  }
  else {
    return c;
  }
}

String SerialStream::getStringFromStream() {
  if(!waitForSerial()) {
    return "Error";
  }
	return Serial.readStringUntil('\n');
}


int SerialStream::getIntFromStream() {
  if(!waitForSerial()) {
    return ERROR;
  }
  else {
    return (int)Serial.parseInt();
  }
}

double * SerialStream::getDoubleValuesFromStream(double * doubleArrayPointer, int numberOfValues) {
  doubleArrayPointer = new double[numberOfValues];
	for (int i = 0; i < numberOfValues; i++) {
		doubleArrayPointer[i] = getDoubleFromStream();
	}

	return doubleArrayPointer;
}

double SerialStream::getDoubleFromStream() {
  if(!waitForSerial()) {
    return ERROR;
  }
  else {
    return (double)Serial.parseFloat();
  }
}

void SerialStream::clearStream() {
  getStringFromStream();
}

void SerialStream::flushStream() {
  Serial.flush();
}

bool SerialStream::streamAvailable() {
  return Serial.available();
}
void SerialStream::printToStream(String str) {
  Serial.print(str);
}

void SerialStream::printLnToStream(String str) {
  Serial.println(str);
}

void SerialStream::printToStream(char c) {
  Serial.print(c);
}

void SerialStream::printToStream(int i) {
  Serial.print(i);
}

void SerialStream::printToStream(double d) {
  Serial.print(d);
}

void SerialStream::printLineToStream() {
  Serial.println();
}

SerialStream::SerialStream() {
	Serial.begin(BAUD_RATE);
}

SerialStream::~SerialStream() {
  Serial.end();
}



