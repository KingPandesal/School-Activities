// Tinkercad Link: https://www.tinkercad.com/things/kWznNLC8khG-ultrasonic-sensor-w-lights
// Username: King Pandesal
// C++ code
//

#define trigPin 10
#define echoPin 9 

int greenLed = 4;
int yellowLed = 3;
int redLed = 2;

long duration; 
int distance;

void setup()
{
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(greenLed, OUTPUT); 
  pinMode(yellowLed, OUTPUT); 
  pinMode(redLed, OUTPUT); 
  Serial.begin(9600); 
}

void loop()
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH); 
  distance = duration * 0.034 / 2; 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(100); 
  
  if (distance < 20) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, HIGH);
  } else if (distance < 100) {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
  } else if (distance < 400) {
    digitalWrite(greenLed, HIGH);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
  }else {
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(redLed, LOW);
  }
}