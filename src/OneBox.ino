#include "Setup.h"

void loop()
{
  tutorials();
  //Insert your code here
}

void setup()
{
  ServoSetup();
  LEDSetup();
  VRSetup();
  ButtonSetup();
  LCDSetup();
  DHTSetup();
  LightSensorSetup();
  SerialSetup();
}
