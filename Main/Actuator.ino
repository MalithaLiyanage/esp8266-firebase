void startLights()
{
  digitalWrite(4, LOW);  // D2 pin
  
}

void endLights()
{
  digitalWrite(4, HIGH);  // D2 pin
}

void openNutrientValve()
{
  digitalWrite(0, LOW); // D3 pin
  delay(10000);
  digitalWrite(0, HIGH);
  
}

void closeNutrientValve()
{
  digitalWrite(0, LOW);
}
