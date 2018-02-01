/*
 * Command.h
 *
 *  Created on: Jan 3, 2018
 *      Author: joeya
 */

#ifndef COMMAND_H_
#define COMMAND_H_
#include "Arduino.h"

class Command {
protected:
	static String commandName = "";
public:
	void runCommand();
	bool commandIsDone();
	virtual Command();
	virtual ~Command();
};

#endif /* COMMAND_H_ */
