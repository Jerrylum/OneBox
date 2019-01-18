void VRSetup()
{
  pinMode(VRPin, INPUT); //Variable resistor pin
}

int getVR()
{
  int currentVal = map(analogRead(VRPin), 0, 1023, 0, 255);
  if (abs(lastVRVal - currentVal) > 2)
  {
    lastVRVal = currentVal;
    return currentVal;
  }
  else
    return lastVRVal;
}

