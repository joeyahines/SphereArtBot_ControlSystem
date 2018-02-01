/*
 * MoveTo.h
 *
 *  Created on: Jan 3, 2018
 *      Author: joeya
 */

#ifndef MOVETO_H_
#define MOVETO_H_

#include "Command.h"
#include "Axis.h"
#include "SerialCommunication.h"

class MoveTo: public virtual Command {
	SerialCommunication * serial;

	double laditudeFinalAngle;
	double longitudeFinalAngle;

	Axis * laditudeAxis;
	Axis * longitudeAxis;
	static const double ANGLE_REACHED = -1.0;

	void moveToPosition();
	bool checkIfFinalPostionIsReached();
	void checkIfLaditudeAxisIsInFinalPosition();
	void checkIfLongitudeAxisIsInFinalPosition();
	bool axisIsInFinalPosition(Axis *, double);

public:
	commandName = "MoveTo";
	MoveTo(Axis * lad, Axis * lon, SerialCommunication * s);
	void runCommand();
	bool commandIsDone();
};

#endif /* MOVETO_H_ */
