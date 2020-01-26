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



SoftwareSerial s(14,12);
int data;

int lightVal;
int nutriVal;
int waterVal;
float phVal;
float tempVal;
float humidityVal;

int serialRecivalIndicatorPin = 5;

const long utcOffsetInSeconds = 19800;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

String date [3];
String Time [2];

FirebaseData firebaseData;

void setup() 
{
  pinMode(serialRecivalIndicatorPin, OUTPUT);
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
  
  SerialRecieval();
  GetDateandTime();
}
