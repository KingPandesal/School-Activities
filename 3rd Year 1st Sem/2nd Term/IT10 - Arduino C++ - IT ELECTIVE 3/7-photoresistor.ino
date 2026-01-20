// Tinkercad Link: https://www.tinkercad.com/things/aJFB2w7v2jF-photoresistor
// Username: King Pandesal
// C++ code
//

int ldrPin = A1;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int lightValue = analogRead(ldrPin);
  
  Serial.println(lightValue);
  delay(200);
}