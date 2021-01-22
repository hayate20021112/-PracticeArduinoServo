#include <Servo.h>
Servo sv;
const int inPin = 2;
const int Servo = 3;
const int MotionLED = 12;
const int PowerLED = 13;

const int angle = 80;

void setup() {
    pinMode (inPin, INPUT);
    pinMode (MotionLED, OUTPUT);
    pinMode (PowerLED, OUTPUT);
    Serial.begin(9600);
    Serial.print("Arduino / ON \n");
    digitalWrite(PowerLED,HIGH);
    sv.attach (Servo);
    sv.write (0);
    Serial.print("ServoPosition 0; \n");
}

void loop() {
    if (digitalRead(inPin) == HIGH) {
        sv.write(0);
        digitalWrite(MotionLED, LOW);
        Serial.print("ServoPosition 0; \n");
    } else if (digitalRead(inPin) == LOW) {
        Serial.print("ServoPosition Motion; \n");
        digitalWrite(MotionLED, HIGH);
        delay(500);
        sv.write(angle);
        delay(500);
    } else {
        sv.write(0);
        digitalWrite(MotionLED, LOW);
        Serial.print("ServoPosition 0; \n");
    }
}
