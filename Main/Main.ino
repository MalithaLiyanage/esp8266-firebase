#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define WIFI_SSID "Malitha"
#define WIFI_PASSWORD "racooncity"

#define FIREBASE_HOST "test1-64187.firebaseio.com"
#define FIREBASE_AUTH "RARZjya5M15q0zdkzK5E60kOTjJl4Dtin5kZUXGH"

#include <NTPClient.h>
#include <WiFiUdp.h>

const int nodeID = 1; // To uniquely identify the node.
const String userID = "7Qn9OiLQTpXd58Os4sdocsXg46l2"; // TO uniquely identify the user


SoftwareSerial s(14,12);
int data;

int lightVal;
int nutriVal;
int waterVal;
float phVal;
float tempVal;
float humidityVal;

int serialRecivalIndicatorPin = 5;
int uploadIndicatorPin = 2;

const long utcOffsetInSeconds = 19800;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

String date [3];
String Time [2];

int i;

FirebaseData firebaseData;

void setup() 
{
  pinMode(serialRecivalIndicatorPin, OUTPUT);
  pinMode(uploadIndicatorPin, OUTPUT);
  
  
  s.begin(9600);
  Serial.begin(9600);
  while (!Serial) continue;

  ConnectToWifi();

  timeClient.begin();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  String storePath = "/ESP8266_Test";
  String jsonStr;

  String retrievePath = "/ESP8266_Test";
  
}

void loop() 
{
  
  for(i = 0; i < 100; i++)
  {
    SerialRecieval();
  
  }

  
    GetDateandTime();

    bool respH = updatepHValue(firebaseData, phVal, userID, nodeID, date, Time);
    bool resLight = updateLightValue(firebaseData, lightVal, userID, nodeID, date, Time);
    bool resTemp = updateTemperatureValue(firebaseData, tempVal, userID, nodeID, date, Time);
    bool resWater = updateWaterLevelValue(firebaseData, waterVal, userID, nodeID, date, Time);
    bool resHum = updateHumidityValue(firebaseData, humidityVal, userID, nodeID, date, Time);
    bool resNutri = updateNutriLevelValue(firebaseData, nutriVal, userID, nodeID, date, Time);
    
//    Serial.println("Done");
//    
//    digitalWrite(uploadIndicatorPin, HIGH);
//    delay(500);
//    digitalWrite(uploadIndicatorPin, LOW);
//   
  
      digitalWrite(uploadIndicatorPin, HIGH);
      delay(500);
      digitalWrite(uploadIndicatorPin, LOW);
      
}   
