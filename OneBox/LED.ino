void LEDSetup()
{
  pinMode(LED_B,OUTPUT); //blue pin
  pinMode(LED_G,OUTPUT); //green pin
  pinMode(LED_R,OUTPUT); //red pin
}

void setLED(int redVal, int greenVal, int blueVal)
{
  analogWrite(LED_R,redVal);
  analogWrite(LED_G,greenVal);
  analogWrite(LED_B,blueVal);
}

