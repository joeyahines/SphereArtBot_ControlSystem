/*
 * LimitSwitch.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: joeya
 */

#include "LimitSwitch.h"

/*	bool LimitSwitch::getState()
 * 	Get the current state of the limitSwitch
 *
 * 	Returns:
 * 	TRUE:	When the switch is pressed
 * 	FALSE:	When the switch is not pressed
 */
bool LimitSwitch::getState() {
	//Read the pin the limit switch is attached to
	return digitalRead(pin);
}

/*	int LimitSwitch::getPinNumber()
 * 	Returns :
 * 	The pin the limit switch is attached to
 *
 */
int LimitSwitch::getPinNumber() {
	return pin;
}

/*	LimitSwitch::LimitSwitch(int p)
 * 	Defines LimitSwitch Object
 *
 * 	p	pin		Digital Pin on the Arduino
 */
LimitSwitch::LimitSwitch(int p) {
	pin = p;
	//Setup Arduino Pin
	pinMode(p,INPUT);

}

LimitSwitch::~LimitSwitch() {
	// TODO Auto-generated destructor stub
}

