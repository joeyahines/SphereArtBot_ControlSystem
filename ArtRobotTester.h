#ifndef ARTROBOTTESTER_H_
#define ARTROBOTTESTER_H_

#include "Arduino.h"
#include "Motor.h"
#include "Encoder.h"
#include "LimitSwitch.h"
#include "Device.h"


class ArtRobotTester : public Device{
public:
  void printMenu();
  void runUserChoosenTest();
  void serialAndMotorTest();
  void motorTest();
  void serialTest();
  //Constructor/Destructor
  Axis(Motor *, Motor *, Encoder *, Encoder * , LimitSwitch *, LimitSwitch *, double);
  virtual ~Axis();
};

#endif
