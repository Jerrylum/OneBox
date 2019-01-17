void ButtonSetup()
{
  pinMode(ButtonPin,INPUT); //button pin
}

bool getButton()
{
  return !digitalRead(ButtonPin);
}

bool isButtonClicked(){
  if(getButton()){
    isClicking =  true;
  }else if(isClicking){
    delay(50);
    if(!getButton()){
      isClicking = false;
      return true;
    }
  }
  return false;
}

