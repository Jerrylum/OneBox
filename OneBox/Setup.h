//Pin Settings
#define ButtonPin 2
#define HumidPin 11
#define LightSensorPin A1
#define VRPin A0
#define ServoPin 9
#define LED_R 6
#define LED_G 5
#define LED_B 3

//Servo Settings
#include <Servo.h>
Servo myservo;  // create servo object to control a servo

//SoftwareSerial settings
#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13); // RX, TX

//LCD Display Settings
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display
String lastMsg1, lastMsg2; //store the last message displayed on LCD

//Humidity sensor settings
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTTYPE           DHT11     // DHT 11 
#define DHTPIN            HumidPin         // Pin which is connected to the DHT sensor.
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

//Serial Settings
String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete
String lastMsg = ""; //store the last msg from serial
int lastVRVal, lastLightVal; //store the last value of analog signals
bool isClicking = false;

//Tutorials settings

