/*
 * Encoder.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: joeya
 */

#include "Encoder.h"

/*	void Encoder::resetCount()
 * 	Reset the step count to 0
 */
void Encoder::resetCount() {
	count = 0;
}

/*	int Encoder::getRawCount()
 * 	Returns the raw cound from the encoder
 *
 * 	Returns:
 * 	int count
 */
int Encoder::getRawCount() {
	return count;
}

/*	double Encoder::getPostion()
 * 	Returns the current position in degrees of the axis
 *
 * 	Returns:
 * 	Position in degrees (double 0 to 360);
 *
 */
double Encoder::getPostion() {

}
Encoder::Encoder() {
	// TODO Auto-generated constructor stub

}

Encoder::~Encoder() {
	// TODO Auto-generated destructor stub
}

