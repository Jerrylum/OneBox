void ServoSetup()
{
    myservo.attach(ServoPin);  // attaches the servo on pin 9 to the servo object
}

void setServo(int pos)
{
 myservo.write(pos);
}

