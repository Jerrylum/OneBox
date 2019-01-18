void LightSensorSetup()
{
  pinMode(LightSensorPin, INPUT); //Light Sensor pin
}

int getLightSensor()
{
  int currentVal = map(analogRead(LightSensorPin), 0, 1023, 0, 255);
  if (abs(lastLightVal - currentVal) > 2)
  {
    lastLightVal = currentVal;
    return currentVal;
  }
  else
    return lastLightVal;
}
