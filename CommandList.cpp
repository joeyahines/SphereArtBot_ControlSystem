/*
 * CommandList.cpp
 *
 *  Created on: Jan 3, 2018
 *      Author: joeya
 */

#include "CommandList.h"

Command CommandList::createCommandFromName(String name) {
	int commandID  = findCommandIDFromName(name);

	return createNewCommandFromID();
}

int CommandList::findCommandIDFromName(String name) {
	int ndxInCommandArray = 0;
	int commandID = -1;
	while(commandID == -1 && ndxInCommandArray < sizeOfArray) {
		//If c is the command at ndx
		if(name == commandArray[ndxInCommandArray]) {
			// commandID equals ndx
			commandID = ndxInCommandArray;
		}
		// Else increment ndx
		else {
			ndxInCommandArray++;
		}
	}

	return CommandID;
}

Command CommandList::createNewCommandFromID(int commandID) {
	switch(commandID) {
	case 0: return new Reset();
	case
	}
}

CommandList::CommandList(Command* commandArr, int sizeOfArr) {
	commandArray = commandArr;
	sizeOfArray = sizeOfArr;
}
