// Tinkercad Link: https://www.tinkercad.com/things/klIEVYHmGGZ-soil-moisture-sensor-with-piezo-
// Username: King Pandesal
// C++ code

#define sensorPin A0

const int redLed = 8;
#define BUZZER_PIN 9

#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);

/*************************************************
 * Note Frequencies
 *************************************************/
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988

// -------------------------------------------------

// Define melody and note durations
int melody[] = {
  NOTE_FS4, NOTE_FS4, NOTE_A4,
  NOTE_FS4, NOTE_A4,
  NOTE_FS4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_A4, NOTE_B4,

  NOTE_E4, NOTE_GS4,
  NOTE_CS5, NOTE_GS4, NOTE_FS4,

  NOTE_FS4, NOTE_FS4, NOTE_A4,
  NOTE_FS4, NOTE_FS4, NOTE_A4,
  NOTE_FS4, NOTE_E4, NOTE_GS4, NOTE_GS4, NOTE_GS4, NOTE_A4, NOTE_B4,

  NOTE_E4, NOTE_GS4,
  NOTE_CS5, NOTE_GS4, NOTE_FS4,
};

int durations[] = {
  4, 4, 3,
  4, 3,
  4, 3, 8, 8, 4, 3,

  4, 1, 
  4, 4, 1,

  4, 4, 3,
  4, 4, 3,
  4, 3, 3, 8, 8, 4, 3,

  4, 1, 
  4, 4, 1,
};

unsigned long previousMillis = 0; 
unsigned long noteDuration = 0;   
int currentNote = 0;              
bool isPlaying = false;          

void setup() {
   
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  
  pinMode(redLed, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int moistureValue = analogRead(sensorPin); 
  Serial.print("Soil Moisture Level: ");
  Serial.println(moistureValue); 

  delay(200); 
  if (moistureValue < 500) {
    digitalWrite(redLed, HIGH); 

    if (!isPlaying) { 
      currentNote = 0; 
      previousMillis = millis(); 
      noteDuration = 1000 / durations[currentNote]; 
      isPlaying = true; 
    }

    // Non-blocking melody playback
    if (isPlaying) {
      if (millis() - previousMillis >= noteDuration) { 
        tone(BUZZER_PIN, melody[currentNote], noteDuration); 
        previousMillis = millis(); 
        currentNote++; 

        // If all notes are played, stop the melody
        if (currentNote >= sizeof(melody) / sizeof(int)) {
          isPlaying = false; 
          digitalWrite(redLed, LOW); 
          noTone(BUZZER_PIN); 
        } else {
          noteDuration = 1000 / durations[currentNote]; 
        }
      }
    }

  } else {
    digitalWrite(redLed, LOW); 
    noTone(BUZZER_PIN);
  }
}
