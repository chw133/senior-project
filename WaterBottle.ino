#define Red 8
#define Yellow 9
#define Green 10
#define SERIESRESISTOR 560
#define SENSORPIN A0

int tiltPin = 2;         // the number of the input pin
int LED = 3;
int LEDPin = 13;       // the number of the output pin

int LEDstate = HIGH;      // the current state of the output pin
int readingS;           // the current reading from the input pin
int previous = LOW;    // the previous reading from the input pin
long time = 0;         // the last time the output pin was toggled
long debounce = 100;   // the debounce time, increase if the output flickers

float first;
float second;
float reading;
int waterLevel;
int waterInBottle = 0;
int oz1 = 0;
int oz2 = 0;
int ounces = 0;
int tilt = 0;
int count = 0;
int count2 = 0;
int total = 0;
int apple = 0;

void setup(void)
{
  //LED (R,Y,G)
  Serial.begin(9600);
  pinMode(Red, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);

  //TiltSensor
  pinMode(tiltPin, INPUT_PULLUP);
  digitalWrite(tiltPin, HIGH);   // turn on the built in pull-up resistor
  pinMode(LEDPin, OUTPUT);
}


void loop(void)
{
  int switchstate;
  //Serial.print("Analog reading ");
  //reading = analogRead(SENSORPIN);
  //Serial.println(reading);

  //*****************************************************************************

  if (reading <= 906.00 || reading >= 896.00)
  {
    digitalWrite(Red, HIGH);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, LOW);

    //4-8
    if (reading >= 906.00)
    {
      waterLevel = 0;

      if (first >= 906.00)
      {
        oz1 = 6 * 29.574;
      }
      if (second >= 906.00)
      {
        oz2 = 6 * 29.574;
      }
    }

    //10
    else if (reading <= 905.00 && reading >= 904.00)
    {
      waterLevel = 5;

      if (first <= 905.00 && first >= 904.00)
      {
        oz1 = 10 * 29.574;
      }
      if (second <= 905.00 && second >= 904.00)
      {
        oz2 = 10 * 29.574;
      }
    }

    //12
    else if (reading <= 900.00 && reading >= 899.00)
    {
      waterLevel = 12;

      if (first <= 900.00 && first >= 899.00)
      {
        oz1 = 12 * 29.574;
      }
      if (second <= 900.00 && second >= 899.00)
      {
        oz2 = 12 * 29.574;
      }
    }

    //14
    else if (reading <= 898.00 && reading >= 897.00)
    {
      waterLevel = 15;

      if (first <= 898.00 && first >= 897.00)
      {
        oz1 = 14 * 29.574;
      }
      if (second <= 898.00 && second >= 897.00)
      {
        oz2 = 14 * 29.574;
      }
    }

    //16
    else if (reading == 896.00)
    {
      waterLevel = 20;

      if (first == 896.00)
      {
        oz1 = 16 * 29.574;
      }
      if (second == 896.00)
      {
        oz2 = 16 * 29.574;
      }
    }

    //18
    else if (reading == 895.00)
    {
      waterLevel = 25;

      if (first == 895.00)
      {
        oz1 = 18 * 29.574;
      }
      if (second == 895.00)
      {
        oz2 = 18 * 29.574;
      }
    }
  }


  if (reading <= 894.00 || reading >= 870.00)
  {
    digitalWrite(Red, LOW);
    digitalWrite(Yellow, HIGH);
    digitalWrite(Green, LOW);

    //20
    if (reading <= 894.00 && reading >= 893.00)
    {
      waterLevel = 30;

      if (first <= 894.00 && first >= 893.00)
      {
        oz1 = 20 * 29.574;
      }
      if (second <= 894.00 && second >= 893.00)
      {
        oz2 = 20 * 29.574;
      }
    }
    //22
    else if (reading <= 891.00 && reading >= 890.00)
    {
      waterLevel = 35;

      if (first <=  891.00 && first >= 890.00)
      {
        oz1 = 22 * 29.574;
      }
      if (second <= 891.00 && second >= 890.00)
      {
        oz2 = 22 * 29.574;
      }
    }
    //24
    else if (reading <= 889.00 && reading >= 888.00)
    {
      waterLevel = 40;

      if (first <= 889.00 && first >= 888.00)
      {
        oz1 = 24 * 29.574;
      }
      if (second <= 889.00 && second >= 888.00)
      {
        oz2 = 24 * 29.574;
      }
    }

    //26
    else if (reading == 887.00)
    {
      waterLevel = 45;

      if (first == 887.00)
      {
        oz1 = 26 * 29.574;
      }
      if (second == 887.00)
      {
        oz2 = 26 * 29.574;
      }
    }
    
    //28
    else if (reading == 886.00)
    {
      waterLevel = 50;

      if (first == 886.00)
      {
        oz1 = 28 * 29.574;
      }
      if (second == 886.00)
      {
        oz2 = 28 * 29.574;
      }
    }
    
    //30
    else if (reading <= 883.00 && reading >= 882.00)
    {
      waterLevel = 55;

      if (first <= 883.00 && first >= 882.00)
      {
        oz1 = 30 * 29.574;
      }
      if (second <= 883.00 && second >= 882.00)
      {
        oz2 = 30 * 29.574;
      }
    }
    
    //32
    else if (reading <= 876.00 && reading >= 875.00)
    {
      waterLevel = 60;

      if (first <= 876.00 && first >= 875.00)
      {
        oz1 = 32 * 29.574;
      }
      if (second <= 876.00 && second >= 875.00)
      {
        oz2 = 32 * 29.574;
      }
    }
    
    //34
    else if (reading <= 874.00 && reading >= 873.00)
    {
      waterLevel = 65;

      if (first <= 874.00 && first >= 873.00)
      {
        oz1 = 34 * 29.574;
      }
      if (second <= 874.00 && second >= 873.00)
      {
        oz2 = 34 * 29.574;
      }
    }
  }

  if (reading <= 872.00)
  {
    digitalWrite(Red, LOW);
    digitalWrite(Yellow, LOW);
    digitalWrite(Green, HIGH);

    //36
    if (reading <= 872.00 && reading >= 871.00)
    {
      waterLevel = 70;

      if (first <= 872.00 && first >= 871.00)
      {
        oz1 = 36 * 29.574;
      }
      if (second <= 872.00 && second >= 871.00)
      {
        oz2 = 36 * 29.574;
      }
    }
    
    //38
    else if (reading <= 870.00 && reading >= 869.00)
    {
      waterLevel = 75;

      if (first <= 870.00 && first >= 869.00)
      {
        oz1 = 38 * 29.574;
      }
      if (second <= 870.00 && second >= 869.00)
      {
        oz2 = 38 * 29.574;
      }
    }

    //40
    else if (reading == 866.00)
    {
      waterLevel = 80;

      if (first == 866.00)
      {
        oz1 = 40 * 29.574;
      }
      if (second == 866.00)
      {
        oz2 = 40 * 29.574;
      }
    }

    //42
    else if (reading <= 864.00 && reading >= 863.00)
    {
      waterLevel = 85;

      if (first <= 864.00 && first >= 863.00)
      {
        oz1 = 42 * 29.574;
      }
      if (second <= 864.00 && second >= 863.00)
      {
        oz2 = 42 * 29.574;
      }
    }
    
    //44
    else if (reading <= 861.00 && reading >= 860.00)
    {
      waterLevel = 90;

      if (first <= 861.00 && first >= 860.00)
      {
        oz1 = 44;
      }
      if (second <= 861.00 && second >= 860.00)
      {
        oz2 = 44;
      }
    }
    
    //46
    else if (reading <= 859.00 && reading >= 858.00)
    {
      waterLevel = 95;

      if (first <= 859.00 && first >= 858.00)
      {
        oz1 = 46 * 29.574;
      }
      if (second <= 859.00 && second >= 858.00)
      {
        oz2 = 46 * 29.574;
      }
    }
    //48
    else if (reading <= 857.00)
    {
      waterLevel = 100;

      if (first <= 821.00)
      {
        oz1 = 48 * 29.574;
      }
      if (second <= 821.00)
      {
        oz2 = 48 * 29.574;
      }
    }
  }

  //************************************

  readingS = digitalRead(tiltPin);

  // If the switch changed, due to bounce or pressing...
  if (readingS != previous)
  {
    time = millis();
  }
  if ((millis() - time) > debounce)
  {
    switchstate = readingS;

    if (switchstate == LOW)
    {
      if (second > 0)
      {
       if(second < first)
        {
          ounces = oz1 - oz2;
          second = 0;
          apple = 1;
        }
      }
      if (tilt == 1)
      {
        tilt = 0;
        count = 0;
      }

      if (count == 0)
      {
        first = reading;
        apple = 0;
        count = 1;
      }

      LEDstate = LOW;
      digitalWrite(LEDPin, LEDstate);
    }

    if (switchstate == HIGH)
    {
      second = first;
      tilt = 1;
      LEDstate = HIGH;
      digitalWrite(LEDPin, LEDstate);
      //ounces = 0;
      //Serial.println("DRINKING");
    }
  }
  previous = readingS;
  Serial.print("Water|");
  Serial.print(waterLevel);
  Serial.print("|");

  if(apple == 1)
  {
    Serial.println(ounces);
    apple = 0;
  }
  else
  {
    int cat = 0;
    Serial.println(cat);
  }
  delay(1500);

  //Serial.print("First: ");
  //Serial.println(first);
  //Serial.print("Second: ");
  //Serial.println(second);
  //Serial.println();

  //*****************************************************************************
}
