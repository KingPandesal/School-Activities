// Tinkercad Link: https://www.tinkercad.com/things/56yUniJf9H7-piezo
// Username: King Pandesal
// C++ code
//

#define BUZZER_PIN 9

void setup() {
   
  pinMode(BUZZER_PIN, OUTPUT);  
  Serial.begin(9600);
}
void loop() {
  
  digitalWrite(BUZZER_PIN, HIGH);
  
  tone(BUZZER_PIN, 10);
  
}
