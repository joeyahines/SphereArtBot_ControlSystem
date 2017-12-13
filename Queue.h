/*
 * Queue.h
 *
 *  Created on: Dec 13, 2017
 *      Author: joeya
 */

#ifndef QUEUE_H_
#define QUEUE_H_

class Queue {
public:
	struct QueueNode {
		int command;
		int numberOfValues;
		double * values;
		bool done;
	};
private:
	int size;
	QueueNode * queue;
	int endNdx;
	int currentCommand = 0;
public:
	int getSize();
	QueueNode * getNextCommand();
	void removeQueueNode(int);
	void addCommand(int, int, double *);
	Queue(int);
	~Queue();
};

#endif /* QUEUE_H_ */
