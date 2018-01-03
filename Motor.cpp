/*
 * Motor.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: joeya
 */

#include "Motor.h"

/*	void Motor::writeToMotor(int value)
 * 	Writes a percent speed to a PWM Motor
 *
 *	Parameters:
 *	int		value	value from -100 to 100
 *
 */
void Motor::setMotorSpeed(int value) {
	int pwmValue = getCalculatedMotorValue(value);

	if (value > 0) {
		forward();
	}
	else if (value < 0) {
		reverse();
	}
	//TODO May have special breaking case for some motor controllers

	writePWMValueToMotor(pwmValue);

}

void Motor::reverse() {
	digitalWrite(in1, LOW);
	digitalWrite(in2, HIGH);
}

void Motor::Forward() {
	digitalWrite(in1, HIGH);
	digitalWrite(in2, LOW);
}

void Motor::writePWMValueToMotor(int pwmValue) {
	analogWrite(pwmPin, abs(pwmValue));
}

/*	int Motor::convertPercentToMotorValue(int value
 * 	Takes a percent value of -100 to 100 and converts to a PWM value of
 * 	0 to 255
 *
 *	Parameters:
 *	int 	value	value from -100 to 100
 *
 *	Returns:
 *	Corrected Motor Speed from -255 to 255
 */
int Motor::getCalculatedMotorValue(int powerInPercent) {
	int pwmValue = convertPercentToPWMValue*multiplier*inverse;

	if (reversed) {
		pwmValue = -pwmValue;
	}

	if (pwmValue > 0) {
		pwmValue = max(255,pwmValue);
	}
	else if (pwmValue < 0) {
		pwmValue = min(-255,pwmValue);
	}

	return pwmValue;
}

int Motor::convertPercentToPWMValue(int valueToConvert) {
	return valueToConvert*2.55;
}

bool Motor::PWM_IsNegative(int PWM_Value) {
	if (pwmValue > 0) {
		pwmValue = max(255,pwmValue);
	}
	else if (value < 0) {
		pwmValue = min(-255,pwmValue);
	}
	else {
		return 0;
	}
}



/*	Motor(int pwm , int i1, int i2, double multi, bool rev)
 *	Defines a Motor object
 *
 *	Parameters:
 *	int 	pwm  		PWM pin on the Arduino
 *	int 	i1 			Digital pin on the Arduino
 *	int 	i2 			Digital pin on the Arduino
 *	double	multi 		Value to scale motor speed with
 *	bool 	rev 		True if motor is reveresd, false otherwise
 */
Motor::Motor(int pwm , int i1, int i2, double multi, bool rev) {
	pwmPin = pwm;
	in1 = i1;
	in2 = i2;
	multiplier = multi;
	reversed = rev;

	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
}

Motor::~Motor() {}

