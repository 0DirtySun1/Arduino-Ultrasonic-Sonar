#include <Servo.h>
#include <BlockNot.h>

BlockNot myTimer(60);
BlockNot sonarTimer1(2, MICROSECONDS);
BlockNot sonarTimer2(12, MICROSECONDS);
BlockNot delayOut(100);
Servo myservo;

int pos = 0;
bool direction = true;
const int trigPin = 2;  
const int echoPin = 3; 
float duration, distance;  

void setup() {
  myservo.attach(9);
  pinMode(trigPin, OUTPUT);  
	pinMode(echoPin, INPUT);  
	Serial.begin(9600);  
}

void loop() {
  if (myTimer.HAS_TRIGGERED) {
    myTimer.RESET;
    if (pos < 180 && direction == true) {
      pos++;
      myservo.write(pos);
    }
    else if (pos > 0 && direction == false) {
      pos--;
      myservo.write(pos);
    }
    else if (pos == 180){
      direction = false;
    }
    else if (pos == 0){
      direction = true;
    }
  }
  if (sonarTimer1.HAS_TRIGGERED){
    sonarTimer1.RESET;
    digitalWrite(trigPin, HIGH);
  }
  if (sonarTimer2.HAS_TRIGGERED){
    sonarTimer2.RESET;
    digitalWrite(trigPin, LOW);
  }
  duration = pulseIn(echoPin, HIGH);
  distance = duration*.0343/2;
  if (delayOut.HAS_TRIGGERED) {
    delayOut.RESET;
    Serial.print(pos);
    Serial.print(",");
    Serial.print(distance);
    Serial.print("\n");
  }
}
