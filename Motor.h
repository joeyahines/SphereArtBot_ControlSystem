/*
 * Motor.h
 *
 *  Created on: Nov 17, 2017
 *      Author: joeya
 */

#ifndef MOTOR_H_
#define MOTOR_H_
#include "Arduino.h"

class Motor {
	//Device Parameters
	int pwmPin;
	int in1;
	int in2;
	//Settings
	double multiplier;
	bool reversed;

public:
	int convertPercentToMotorValue(int);
	void setMotorSpeed(int value);

	//Constructor/Destructor
	Motor(int, int, int, double, bool);
	virtual ~Motor();
};

#endif /* MOTOR_H_ */
