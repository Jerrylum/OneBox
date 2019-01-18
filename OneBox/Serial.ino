void SerialSetup() {
  // initialize serial:
  mySerial.begin(9600);
  // reserve 200 bytes for the inputString:
  inputString.reserve(200);
}

void sendMsg(String msg)
{
  mySerial.println(msg);
}

String getMsg()
{
  return lastMsg;
}

void readSerial() {
  serialEvent();
  // print the string when a newline arrives:
  if (stringComplete) {
    lastMsg = inputString;
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (mySerial.available()) {
    // get the new byte:
    char inChar = (char)mySerial.read();
    // add it to the inputString:
    if (inChar == '\n') {
      stringComplete = true;
    }
    else
      inputString += inChar;
  }
}


