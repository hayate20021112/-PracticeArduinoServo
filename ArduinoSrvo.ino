#include <Servo.h>
Servo sv;
const int inPin = 2;
const int Servo = 3;
const int MotionLED = 12;
const int PowerLED = 13;

void setup() {
    pinMode (inPin, INPUT);
    pinMode (MotionLED, OUTPUT);
    pinMode (PowerLED, OUTPUT);
    Serial.begin(9600);
    Serial.print("Arduino / ON \n");
    digitalWrite(PowerLED,HIGH);
    sv.attach (Servo);
    sv.write (90);
    Serial.print("ServoPosition 90 \n");
}

void loop() {
    if (digitalRead(inPin) == HIGH) {
        sv.write(0);
        digitalWrite(MotionLED, LOW);
        Serial.print("ServoPosition 0 \n");
    } else if (digitalRead(inPin) == LOW) {
        delay(200);
        sv.write(90);
        digitalWrite(MotionLED, HIGH);
        Serial.print("ServoPosition 90 \n");
        delay(500);
    } else {
        sv.write(0);
        digitalWrite(MotionLED, LOW);
        Serial.print("ServoPosition 0 \n");
    }
}
