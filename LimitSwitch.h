/*
 * LimitSwitch.h
 *
 *  Created on: Nov 17, 2017
 *      Author: joeya
 */

#ifndef LIMITSWITCH_H_
#define LIMITSWITCH_H_
#include "Arduino.h"

class LimitSwitch {
	int pin;
public:
	bool getState();
	int getPinNumber();
	LimitSwitch(int);
	virtual ~LimitSwitch();
};

#endif /* LIMITSWITCH_H_ */
