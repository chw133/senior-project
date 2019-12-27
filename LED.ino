#define Red 8
#define Yellow 9
#define Green 10
#define SERIESRESISTOR 560
#define SENSORPIN A0 

void setup(void) 
{
  Serial.begin(9600);
  pinMode(Red,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Green,OUTPUT);
}

void loop(void) {
  float reading;
 
  reading = analogRead(SENSORPIN);
 
  Serial.print("Analog reading "); 
  Serial.println(reading);

//when bottle is low
//1 inch or below
  if(reading >= 758.00)
  {
    digitalWrite(Red,HIGH);
     delay(50); 
    digitalWrite(Red,LOW); 
    delay(50);
    digitalWrite(Yellow,LOW);
    digitalWrite(Green,LOW);
  }

  //when bottle is medium
//1 inches - 3 inches
  if(reading >= 727.00 && reading <= 757.00)
  {
    digitalWrite(Red,LOW);
    digitalWrite(Yellow,HIGH);
    digitalWrite(Green,LOW);
  }

//when bottle is full
//3 inches or above
  if(reading <= 726.00)
  {
    digitalWrite(Red,LOW);
    digitalWrite(Yellow,LOW);
    digitalWrite(Green,HIGH);
  }
 
  // convert the value to resistance
  reading = (1023 / reading)  - 1;
  reading = SERIESRESISTOR / reading;
  Serial.print("Sensor resistance "); 
  Serial.println(reading);
   delay(1000);
}
