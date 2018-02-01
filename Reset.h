/*
 * Reset.h
 *
 *  Created on: Jan 3, 2018
 *      Author: joeya
 */

#ifndef RESET_H_
#define RESET_H_

#include "Command.h"
#include "Device.h"
#include "Arduino.h"

class Reset: public virtual Command {
	Device ** deviceArray;
	int numberOfDevices;
	bool resetIsDone = false;;
	void resetEachDevice();
	commandName = "Reset";
public:
	void runCommand();
	bool commandIsDone();
	Reset(Device ** devArr, int numOfDev);
	virtual ~Reset();
};

#endif /* RESET_H_ */
