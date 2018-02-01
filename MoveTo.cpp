/*
 * MoveTo.cpp
 *
 *  Created on: Jan 3, 2018
 *      Author: joeya
 */

#include "MoveTo.h"



MoveTo::MoveTo(Axis* lad, Axis* lon, double ladAngle, double lonAngle) {
	laditudeAxis = lad;
	longitudeAxis = lon;

	laditudeFinalAngle = ladAngle;
	longitudeFinalAngle = lonAngle;

}

void MoveTo::runCommand() {
	moveToPosition();
	checkIfLaditudeAxisIsInFinalPosition();
	checkIfLongitudeAxisIsInFinalPosition();
}

void MoveTo::moveToPosition() {
	if (longitudeFinalAngle >= 0) {
		longitudeAxis->setAngle(longitudeFinalAngle);
	}
	if (laditudeFinalAngle >= 0) {
		laditudeAxis->setAngle(laditudeFinalAngle);
	}
}

void MoveTo::checkIfLaditudeAxisIsInFinalPosition() {
	if(axisIsInFinalPosition(laditudeAxis, laditudeFinalAngle)) {
		laditudeFinalAngle = ANGLE_REACHED;
	}
}

void MoveTo::checkIfLongitudeAxisIsInFinalPosition() {
	if(axisIsInFinalPosition(longitudeAxis, longitudeFinalAngle)) {
		longitudeFinalAngle = ANGLE_REACHED;
	}
}

bool MoveTo::axisIsInFinalPosition(Axis * axis, double finalAngle) {
	return axis->getCurrentAngle() == finalAngle;
}

bool MoveTo::commandIsDone() {
	return checkIfFinalPostionIsReached();
}
bool MoveTo::checkIfFinalPostionIsReached() {
	return longitudeFinalAngle == ANGLE_REACHED && laditudeFinalAngle == ANGLE_REACHED;
}


