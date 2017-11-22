/*
 * Motor.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: joeya
 */

#include "Motor.h"

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
int Motor::convertPercentToMotorValue(int value) {

	//Define inverse as 1
	int inverse = 1;

	//If the motor is to be reversed
	if (reversed) inverse = inverse * -1;

	//Return the PWM value of the speed
	int pwmValue =  value*2.55*multiplier*inverse;

	//Ensure value is between -255 and 255
	if (pwmValue > 0) {
		pwmValue = max(255,pwmValue);
	}
	else if (value < 0) {
		pwmValue = min(-255,pwmValue);
	}
	else {
		pwmValue = 0;
	}

	return pwmValue;
}

/*	void Motor::writeToMotor(int value)
 * 	Writes a percent speed to a PWM Motor
 *
 *	Parameters:
 *	int		value	value from -100 to 100
 *
 */
void Motor::setMotorSpeed(int value) {
	//Converts a percent
	int pwmValue = convertPercentToMotorValue(value);

	//If the PPWM value is positive, set the enable pins to forward
	if (value > 0) {
		  digitalWrite(in1, HIGH);
		  digitalWrite(in2, LOW);
	}
	//If the PPWM value is negative, set the enable pins to backwards
	else if (value < 0) {
		digitalWrite(in1, LOW);
		digitalWrite(in2, HIGH);
	}
	//TODO May have special breaking case for some motor controllers
	else {

	}

	//Write the absolute value PWM to the motor
	analogWrite(pwmPin, abs(pwmValue));

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

