/*
 * CommandList.h
 *
 *  Created on: Jan 3, 2018
 *      Author: joeya
 */

#ifndef COMMANDLIST_H_
#define COMMANDLIST_H_
#include "Command.h"
#include "Reset.h"
#include "MoveTo.h"

class CommandList {
	Command * commandArray;
	int sizeOfArray;
	int findCommandIDFromName(String);
public:
	Command createCommandFromName(String);
	Command createNewCommandFromID(int);
	CommandList(Command * commandArr, int sizeOfArray);

};

#endif /* COMMANDLIST_H_ */
