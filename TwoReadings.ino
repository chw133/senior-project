void setup() {
  Serial.begin(9600);

}

void loop() {
  int waterLevel = 300;
  int waterInBottle = 10000;
  Serial.print("Water|");
  Serial.print(waterLevel);
  Serial.print("|");
  Serial.println(waterInBottle);
  delay(1000);
}
