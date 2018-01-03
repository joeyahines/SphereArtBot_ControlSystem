/*
 * PaintBrush.h
 *
 *  Created on: Nov 17, 2017
 *      Author: joeya
 */

#ifndef PAINTBRUSH_H_
#define PAINTBRUSH_H_

#include "Device.h"
#include "Arduino.h"
#include <Servo.h>


class PaintBrush : public Device {
	Servo paintBrushServo;
	int convertHeightToAngle(float height);
	void setServoAngle();
public:

	//Constructor/Destructor
	void setPaintBrushHeight(float);
	PaintBrush();
	virtual ~PaintBrush();
};

#endif /* PAINTBRUSH_H_ */
