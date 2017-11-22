/*
 * Axis.h
 *
 *  Created on: Nov 17, 2017
 *      Author: joeya
 */

#ifndef AXIS_H_
#define AXIS_H_
#include "Arduino.h"

class Axis : Reset{
	Motor motor1;
	Motor motor2;
	Encoder encoder1;
	Encoder encoder2;
	LimitSwitch lowStopSwitch;
	LimitSwitch highStopSwitch;

	double maxAngle;
	int maxCount = 0;

	void setAxisSpeed(int);
public:
	double getMaxAngle();
	double getCurrentAngle();
	double setAngle(unsigned double);
	int getAverageEncoderCount();

	void reset();


	//Constructor/Destructor
	Axis(Motor, Motor, Encoder, Encoder, LimitSwitch, LimitSwitch, double);
	virtual ~Axis();
};

#endif /* AXIS_H_ */
