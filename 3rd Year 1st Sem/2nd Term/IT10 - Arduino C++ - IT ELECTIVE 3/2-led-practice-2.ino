// Tinkercad Link: https://www.tinkercad.com/things/iXkmfL66DpI-led-practice-2
// Username: King Pandesal
// C++ code
//

const int led1 = 7;
const int led2 = 5;
const int led3 = 2;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop()
{
  // ===== STEP 1: LED Staircase =====
  digitalWrite(led1, HIGH);
  delay(250);
  digitalWrite(led2, HIGH);
  delay(250);
  digitalWrite(led3, HIGH);
  delay(250);
  
  // ===== STEP 2: LED Reverse Turn-OFF =====
  digitalWrite(led3, LOW);
  delay(250);
  digitalWrite(led2, LOW);
  delay(250);
  digitalWrite(led1, LOW);
  delay(250);
  
  // ===== STEP 3: Alternating Blink =====
  for (int i = 1; i <= 4; i++) {
    digitalWrite(led1, HIGH);
    digitalWrite(led3, HIGH);
  	delay(300);
    digitalWrite(led1, LOW);
    digitalWrite(led3, LOW);
    
    digitalWrite(led2, HIGH);
  	delay(300);
    digitalWrite(led2, LOW);    
  }
}