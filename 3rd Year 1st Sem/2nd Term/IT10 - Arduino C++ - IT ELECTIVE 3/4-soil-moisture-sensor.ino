// Tinkercad Link: https://www.tinkercad.com/things/kiW6ODv5W2r-soil-moisture-sensor
// Username: King Pandesal
// C++ code
//

int soilPin = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int moistureValue = analogRead(soilPin);
  
  Serial.println(moistureValue);
  delay(100);
  
  if (moistureValue < 200) {
    
  }
}