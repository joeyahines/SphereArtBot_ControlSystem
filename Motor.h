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

	void reverse();
	void forward();
	int getCalculatedMotorValue(int);
	int convertPercentToPWMValue(int);
	void writePWMValueToMotor(int);

public:
	bool PWM_IsNegative(int);
	void setMotorSpeed(int);

	//Constructor/Destructor
	Motor(int, int, int, double, bool);
	virtual ~Motor();
};

#endif /* MOTOR_H_ */
