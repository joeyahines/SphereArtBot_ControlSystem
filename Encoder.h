/*
 * Encoder.h
 *
 *  Created on: Nov 17, 2017
 *      Author: joeya
 */

#ifndef ENCODER_H_
#define ENCODER_H_

class Encoder {
	pin;
	int count;

public:
	void resetCount();
	int getRawCount();
	double getPostion();
	//Constructor/Destructor
	Encoder();
	virtual ~Encoder();
};

#endif /* ENCODER_H_ */
