#include <SoftwareSerial.h>
#include <ArduinoJson.h>

#include <ESP8266WiFi.h>

#define WIFI_SSID "Malitha"
#define WIFI_PASSWORD "racooncity"

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

void setup() 
{
  pinMode(serialRecivalIndicatorPin, OUTPUT);
  s.begin(9600);
  Serial.begin(9600);
  while (!Serial) continue;

  ConnectToWifi();

  timeClient.begin();
  
}

void loop() 
{
  
  SerialRecieval();
  GetDateandTime();
}
