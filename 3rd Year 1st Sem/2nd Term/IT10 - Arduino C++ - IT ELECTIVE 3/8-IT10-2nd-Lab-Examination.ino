// Tinkercad Link: https://www.tinkercad.com/things/cZXQA3TauK4-it10-2nd-lab-examination
// Username: King Pandesal
// C++ code
//


int buzzer = 8;
int soilPin = A0;

int greenLed = 7;
int yellowLed = 6;
int redLed = 5;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
}

void loop()
{
  delay(1000);  Wait for 1000 millisecond(s)
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);  Wait for 1000 millisecond(s)
  
  int moistureValue = analogRead(soilPin);
  Serial.println(moistureValue);
  
  if (moistureValue  300) {
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    tone(buzzer, 2000);
    delay(200);
    digitalWrite(redLed, LOW);
    tone(buzzer, 800);
    delay(200);
    
  } else if (moistureValue  600) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    tone(buzzer, 1200);
    delay(150);
    digitalWrite(yellowLed, LOW);
    tone(buzzer, 1000);
    delay(150);
    noTone(buzzer);
    
    
   } else if (moistureValue  900) {
    digitalWrite(greenLed, HIGH);
    noTone(buzzer);
  } else {
    digitalWrite(greenLed, LOW);
    noTone(buzzer);
  }
}