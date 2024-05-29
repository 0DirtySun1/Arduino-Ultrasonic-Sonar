    #include "LedControl.h"
    #define joyX A0
    #define joyY A1
    #define R1 2
    #define R2 3
    #define R3 4
    #define R4 5
    #define R5 6
    #define R6 7
    #define R7 8
    #define R8 9

    int dataPin = 10;
    int clockPin = 12;
    int latchPin = 11;

    int xMap, yMap, xValue, yValue;
    LedControl lc=LedControl(10,12,11,1);
     
    void setup() {
      Serial.begin(115200);
      pinMode(dataPin, OUTPUT);
      pinMode(clockPin, OUTPUT);
      pinMode(latchPin, OUTPUT);
      pinMode(R1, OUTPUT);
	    pinMode(R2, OUTPUT);
	    pinMode(R3, OUTPUT);
      pinMode(R4, OUTPUT);
	    pinMode(R5, OUTPUT);
	    pinMode(R6, OUTPUT);
      pinMode(R7, OUTPUT);
	    pinMode(R8, OUTPUT);
    }
     
    void loop() {
      digitalWrite(latchPin, HIGH);
      shiftOut(dataPin, clockPin, LSBFIRST, 0b00101010);
      digitalWrite(latchPin, LOW);
      digitalWrite(R1, HIGH);
      digitalWrite(R2, HIGH);
      digitalWrite(R3, HIGH);
      digitalWrite(R4, HIGH);
      digitalWrite(R5, HIGH);
      digitalWrite(R6, HIGH);
      digitalWrite(R7, HIGH);
      digitalWrite(R8, HIGH);
    }
