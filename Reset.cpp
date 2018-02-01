/*
 * Reset.cpp
 *
 *  Created on: Jan 3, 2018
 *      Author: joeya
 */

#include "Reset.h"

Reset::Reset(Device ** devArr, int numOfDev) {
	deviceArray = devArr;
	numberOfDevices = numOfDev;
}


void Reset::runCommand() {
	resetEachDevice();
	resetIsDone = true;
}

void Reset::resetEachDevice() {
	for (int i = 0; i < numberOfDevices; i++) {
		deviceArray[i]->reset();
		delay(1000);
	}
}

bool Reset::commandIsDone() {
	return resetIsDone;
}


Reset::Reset(Device* devArr, int numOfDev) {
}


