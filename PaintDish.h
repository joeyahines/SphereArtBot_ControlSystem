/*
 * PaintDish.h
 *
 *  Created on: Nov 17, 2017
 *      Author: joeya
 */

#ifndef PAINTDISH_H_
#define PAINTDISH_H_

#include "Device.h"
#include "Arduino.h"
#include <Servo.h>

class PaintDish : public Device {
public:
	struct Color {
		unsigned char r;
		unsigned char y;
		unsigned char b;
	};

private:
	int numberOfColors;
	Servo servo;
	Color colorArray[];

public:
	void selectColor();
	Color getCurrentColot();

	void reset();


	//Constrctor/Destructor
	PaintDish(int , Color [] , Servo);
	virtual ~PaintDish();
};

#endif /* PAINTDISH_H_ */
