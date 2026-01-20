// Tinkercad Link: https://www.tinkercad.com/things/7Xy03R1oM9y-led-practice
// Username: King Pandesal
// C++ code
//


const int red = 8;
const int green = 9;

void setup()
{
  
  Serial.begin(9600);
  irrecv.enableIRIn();
  
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 2; i++) {
    digitalWrite(red, HIGH);
    delay(500);
    digitalWrite(red, LOW);
    delay(500);
    digitalWrite(green, HIGH);
    delay(1000);
    digitalWrite(green, LOW);
    delay(1000);
  }
  
  for (int i = 0; i < 3; i++) {
    digitalWrite(red, HIGH);
    digitalWrite(green, HIGH);
    delay(500);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    delay(500);
  }
}