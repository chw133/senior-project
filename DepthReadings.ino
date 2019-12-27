#define SERIESRESISTOR 560
#define SENSORPIN A0 

void setup(void) 
{
  Serial.begin(9600);
}

void loop(void) {
  float reading;
 
  reading = analogRead(SENSORPIN);
 
  Serial.print("Water Level: "); 
  Serial.println(reading);


  if(reading >= 836.00)
  {
    Serial.println("20");
  }
  else if(reading >= 749.00 && reading <= 835.00)
  {
    Serial.println("30");
  }
  else if(reading >= 734.00 && reading <= 747.00)
  {
    Serial.println("40");
  }
  else if(reading >= 728.00 && reading <= 733.00)
  {
    Serial.println("50");
  }
  else if(reading >= 718.00 && reading <= 727.00)
  {
    Serial.println("60");
  }
  else if(reading >= 696.00 && reading <= 717.00)
  {
    Serial.println("70");
  }
  if(reading >= 684.00 && reading <= 695.00)
  {
    Serial.println("80");
  }
  else if(reading >= 675.00 && reading <= 683.00)
  {
    Serial.println("90");
  }
  else if(reading <= 674.00)
  {
    Serial.println("100");
  }
  delay(1000);
}
