void SerialRecieval()
{
  s.write("s");
  
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(s);
  if (root == JsonObject::invalid())
    return;

  else
  {  

  
    Serial.println("JSON received and parsed");
  //  root.prettyPrintTo(Serial);
    lightVal = root["light"];
    nutriVal = root["nutri"];
    waterVal = root["water"];
    phVal = root["ph"];
    tempVal = root["temp"];
    humidityVal = root["humidity"];
    
    Serial.println(phVal);
    Serial.println(nutriVal);
    Serial.println(waterVal);
    Serial.println(lightVal);
    Serial.println(humidityVal);
    Serial.println(tempVal);
  

    digitalWrite(5, HIGH);
    delay(500);
    digitalWrite(5, LOW);
  }

}
