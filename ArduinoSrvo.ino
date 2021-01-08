#include <Servo.h>
Servo sv;
const int inPin = 2;

void setup() {
    pinMode (inPin, INPUT);
    Serial.begin(9600);
    Serial.print("Arduino / ON \n");
    sv.attach (3);
    sv.write (90);
    Serial.print("ServoPosition 90 \n");
}

void loop() {
    if (digitalRead(inPin) == HIGH) {
        sv.write(0);
        Serial.print("ServoPosition 0 \n");
        delay(2500);
    } else {
        sv.write(90);
        Serial.print("ServoPosition 90 \n");
    }
}
