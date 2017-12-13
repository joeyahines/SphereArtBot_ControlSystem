/*
 * Queue.cpp
 *
 *  Created on: Dec 13, 2017
 *      Author: joeya
 */

#include "Queue.h"

int Queue::getSize() {
	return size;
}

Queue::QueueNode * Queue::getNextCommand() {
	if(queue[currentCommand].done == true) {
		currentCommand++;
	}

	if (currentCommand > endNdx) {
		return 0;
	}
	else {
		return &queue[currentCommand++];
	}


}

void Queue::addCommand(int command, int numOfValues, double * values) {
	if (endNdx > size) {
		QueueNode * tmp = new QueueNode[size*2];

		for (int i = 0; i < endNdx; i++) {
			tmp[i] = queue[i];
		}
		delete queue;

		queue = tmp;
		size = size * 2;

	}

	queue[endNdx].command = command;
	queue[endNdx].done = false;
	queue[endNdx].numberOfValues = numOfValues;
	queue[endNdx].values = new double[numOfValues];

	for (int i = 0; i < numOfValues; i++) {
		queue[endNdx].values[i] = values[i];
	}

	endNdx++;

}

Queue::Queue(int s) {
	size = s;
	endNdx = 0;
	queue = new QueueNode[size];
}

Queue::~Queue() {
	delete queue;
}

