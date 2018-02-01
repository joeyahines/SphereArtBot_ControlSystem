/*
 * CommandQueueCreator.h
 *
 *  Created on: Jan 3, 2018
 *      Author: joeya
 */

#ifndef COMMANDQUEUECREATOR_H_
#define COMMANDQUEUECREATOR_H_
#include "Queue.h"
#include "SerialCommunication.h"


class CommandQueueCreator {
	SerialCommunication * serial;
	int getQueueSize();
	Queue * getNewCommands(Queue * q);
public:
	Queue * createNewCommandQueue();
};

#endif /* COMMANDQUEUECREATOR_H_ */
