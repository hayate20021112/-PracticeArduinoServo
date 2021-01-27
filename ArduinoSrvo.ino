#include <Servo.h>
Servo sv;
const int HIGHinPin = 5;
const int LOWinPin = 6;
const int Servo = 3;
const int MotionLED = 12;
const int LOWLED = 11;
const int PowerLED = 13;

const int angle = 63;

void setup() {
    pinMode (HIGHinPin, INPUT);
    pinMode (LOWinPin, INPUT);
    pinMode (MotionLED, OUTPUT);
    pinMode (LOWLED, OUTPUT);
    pinMode (PowerLED, OUTPUT);
    Serial.begin(9600);
    Serial.print("Arduino / ON \n");
    digitalWrite(PowerLED,HIGH);
    sv.attach (Servo);
    sv.write (0);
    Serial.print("ServoPosition 0; \n");
}

void loop() {
    if (digitalRead(HIGHinPin) == LOW) {
        Serial.print("ServoPosition Motion; \n");
        digitalWrite(LOWLED, LOW);
        digitalWrite(MotionLED, HIGH);
        sv.write(angle);
    } else if(digitalRead(LOWinPin) == HIGH){
        Serial.print("ServoPosition LOW; \n");
        digitalWrite(MotionLED, LOW);
        digitalWrite(LOWLED, HIGH);
        delay(2500);
        sv.write(0);
    } else {
        Serial.print("ServoPosition 0; \n");
        digitalWrite(LOWLED, LOW);
    }
}
