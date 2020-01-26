#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial s(14,12);
int data;

int lightVal;
int nutriVal;
int waterVal;
float phVal;
float tempVal;
float humidityVal;

int serialRecivalIndicatorPin = 5;


void setup() 
{
  pinMode(serialRecivalIndicatorPin, OUTPUT);
  s.begin(9600);
  Serial.begin(9600);
  while (!Serial) continue;
  
}

void loop() 
{
  SerialRecieval();
}
