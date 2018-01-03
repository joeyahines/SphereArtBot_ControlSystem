/*
 * Axis.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: joeya
 */

#include "Axis.h"
/*	void Axis::reset()
 * 	Calibrates motors to define stop and start positions
 */
void Axis::reset() {
	goToMinAngle();

	resetEncoders();

	goToMaxAngle();

	maxCount = getAverageEncoderCount();
}

void Axis::goToMinAngle() {
	setAxisSpeed(-25);
	waitUntilLowerLimitSwitchPressed();
	stopMotors();

}

void Axis::goToMaxAngle() {
	setAxisSpeed(25);
	waitUntilHigherLimitSwitchPressed()
	stopMotors();

}

void Axis::stopMotors() {
	setAxisSpeed(0);
}

void Axis::waitUntilLowerLimitSwitchPressed() {
	waitForLimitSwitchActivated(lowStopSwitch);

}

void Axis::waitUntilHigherLimitSwitchPressed() {
	waitForLimitSwitchActivated(highStopSwitch);
}

void Axis::waitForLimitSwitchActivated(LimitSwitch * limitSwitch) {
	while(!limitReached(limitSwitch)) {
			delay(10);
	}
}

bool Axis::limitReached(LimitSwitch * limitSwitch) {
	return limitSwitch->getState();
}

void Axis::resetEncoders() {
	encoder1->write(0);
	encoder2->write(0);
}

/*	void Axis::setAxisSpeed(int speed)
 * 	Set the speed of the motors that drive the axis
 *
 * 	Parameters:
 * 	int	speed	Speed of the axis (-100 to 100)
 */
void Axis::setAxisSpeed(int speed) {
	motor1->setMotorSpeed(speed);
	motor2->setMotorSpeed(speed);
}

/*	double Axis::getCurrentAngle()
 * 	Returns:
 * 	Current angle of the axis (range 0 to maxAngle)
 */
double Axis::getCurrentAngle() {
	int avgCount = getAverageEncoderCount();

	return ((double) avgCount / (double) maxCount) * maxAngle;
}

/*	double Axis::setAngle(unsigned double angle)
 *
 * 	Moves the axis to the specified angle-> This method is to be called in the
 * 	loop function to ensure parallelism
 *
 * 	Parameters:
 * 	unsigned double	angle	Angle to move the axis to
 *
 * 	Returns:
 * 	Current angle of the axis
 */
double Axis::setAngle(double angle) {

	angle = max(maxAngle, angle);

	double currentAngle = getCurrentAngle();
	double angleDiff abs(currentAngle - angle);
	angleDiff = abs(currentAngle - angle);

	//TODO PID Stuff

	return angle;
}

int Axis::getAverageEncoderCount() {
	return (encoder1->read() + encoder2->read())/2;
}

/*	Axis::Axis(Motor m1, Motor m2, Encoder e1, Encoder e2, LimitSwitch ls1, LimitSwitch ls2, double maxA)
 * 	Defines Axis object
 *
 * 	Parameters:
 * 	Motor		m1		First motor used to drive the axis
 * 	Motor		m2		Second motor used to drive the axis
 * 	Encoder 	e1		First encoder to track axis movement
 * 	Encoder 	e2		Second encoder to track axis movement
 * 	LimitSwitch ls1		Limit switch for min angle
 * 	LimitSwitch ls2		Limit switch for max angle
 * 	double		maxA	Max angle
 */
Axis::Axis(Motor * m1, Motor * m2, Encoder * e1, Encoder * e2, LimitSwitch * ls1, LimitSwitch * ls2, double maxA) {
	motor1 = m1;
	motor2 = m2;
	encoder1 = e1;
	encoder2 = e2;
	lowStopSwitch = ls1;
	highStopSwitch = ls2;
	maxAngle = maxA;

}

Axis::~Axis() {
	// TODO Auto-generated destructor stub
}

