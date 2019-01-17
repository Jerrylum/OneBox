char* tutorial_title[]={
  "Let's Move", //0
  "Light On", 
  "Weather Report", 
  "Shooting Game",
  "Click Counter",
  "RGB Light", //5
  "Your Color",
  "Bluetooth Chat",
  "ASAP",
  "Test"
  };
const int tutorials_len = sizeof(tutorial_title)/sizeof(tutorial_title[0]);
const int vr_min_value = 50;
const int vr_max_value = 255;
const int vr_value_per_tutorial = (vr_max_value - vr_min_value) / tutorials_len;

void tutorial_0(){
  while(1){
    int value = getVR();
    setLCDLine1("Value:" + (String)value);
    setServo(value);
  }
}

void tutorial_1(){
  while(1){
    bool pressing = getButton();
    if(pressing){
      setLCDLine1("Press");
      setLED(255,0,0);
    }else{
      setLCDLine1("Release");
      setLED(0,0,0);
    }
  }
}

void tutorial_2(){
  while(1){
    setLCDLine1("Temp: " + (String)getTemp() + "C");
    setLCDLine2("Humidity: " + (String)getHumidity() + "%");
  }
}

void tutorial_3(){
  while(1){
    setLCDLine1("Shoot me!");
    setServo(75);
    if (getLightSensor() < 10){
      setServo(20);
      setLCDLine1("Boooooo!");
      delay(1000);
    }
  }
}

void tutorial_4(){
  int count = 0;
  while(1){
    setLCDLine1("Clicked " + (String)count);
    if(isButtonClicked()){
      count ++;
    }
  }
}

void tutorial_5(){
  int steps = 0;
  while(1){
    if(isButtonClicked()){
      steps ++;
    }
    if(steps == 3) steps = 0;

    switch(steps){
      case 0:
        setLCDLine1("Red");
        setLED(255,0,0);
        break;
      case 1:
        setLCDLine1("Green");
        setLED(0,255,0);
        break;
      case 2:
        setLCDLine1("Blue");
        setLED(0,0,255);
        break;
    }
  }
}


void tutorial_6(){
  int steps = 0;
  int r = 0;
  int g = 0;
  int b = 0;
  while(1){
    if(isButtonClicked()){
      steps ++;
    }
    if(steps == 3) steps = 0;

    int value = getVR();
    switch(steps){
      case 0:
        r = value;
        setLCDLine1("Red:   " + (String)r);
        break;
      case 1:
        g = value;
        setLCDLine1("Green: " + (String)g);
        break;
      case 2:
        b = value;
        setLCDLine1("Blue:  " + (String)b);
        break;
    }
    setLED(r,g,b);
  }
}

void tutorial_7(){
  while(1){
    readSerial(); //activate serialport (Bluetooth Module)
    setLCD("Message from BT: ", getMsg() );
  }
}

void tutorial_8(){
  while(1){
    setLCDLine1("Ready?");
    delay(1000);

    bool cheat = false;
    int wait = random(2000);
    int ms = 0;
    while(!cheat && ms < wait){
      delay(1);
      ms++;
      if(getButton()){
        cheat = true;
      }
    }

    if(cheat){
      setLCDLine1("Cheat!");
    }else{
      ms = 0;
      setLCDLine1("Go");
      while(!getButton()){
        delay(1);
        ms++;
      }
      setLCDLine1("Time:" + (String)ms + "ms");
    } 
    
    delay(3000);
  }
}

void tutorial_9(){
  int steps = 0;
  int ms = 0;
  int wait = 500;
  while(1){
    if(ms > wait){
      ms = 0;
      steps ++;
      if(steps == 3) steps = 0;
    }
    switch(steps){
      case 0:
        setLED(255,0,0);
        setServo(50);
        break;
      case 1:
        setLED(0,255,0);
        setServo(90);
        break;
      case 2:
        setLED(0,0,255);
        setServo(130);
        break;
    }
    setLCDLine1("VR:" +  (String)getVR() + " Light:" + (String)getLightSensor());
    setLCDLine2("Btn:" + (String)getButton() + " T&H:" + (String)getTemp() + "/" + (String)getHumidity());

    ms ++;
  }
}

void tutorials(){
  while(1){
    int vr = getVR();
    int index = (vr-vr_min_value) / vr_value_per_tutorial;
    index = max(0,min(index,tutorials_len-1));
    setLCDLine1((String)(index+1) + " " + (String)tutorial_title[index]);
    setLCDLine2("Menu");
    
    if (isButtonClicked()) {
      clearLCD();
      switch(index){
        case 0:
          tutorial_0();
          break;
        case 1:
          tutorial_1();
          break;
        case 2:
          tutorial_2();
          break;
        case 3:
          tutorial_3();
          break;
        case 4:
          tutorial_4();
          break;
        case 5:
          tutorial_5();
          break;
        case 6:
          tutorial_6();
          break;
        case 7:
          tutorial_7();
          break;
        case 8:
          tutorial_8();
          break;
        case 9:
          tutorial_9();
          break;
      }
    }
    delay(10);
  }
}

