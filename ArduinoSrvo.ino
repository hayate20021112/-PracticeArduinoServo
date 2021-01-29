#include <Servo.h>          //Servoのライブラリを読み込む

Servo sv;
const int HIGHinPin = 5;    //第一センサーボード
const int LOWinPin = 6;     //第二センサーボード
const int Servo = 3;        //サーボモータピン
const int MotionLED = 12;   //バーの動作状況確認用
const int LOWLED = 11;      //上と同じ
const int PowerLED = 13;    //電源確認用LED

const int angle = 63;       //角度の指定

void setup() {
    pinMode (HIGHinPin, INPUT);         //センサーボードが接続されているピンを入力に設定
    pinMode (LOWinPin, INPUT);          //上と同じ
    pinMode (MotionLED, OUTPUT);        //各種LEDのぴんを出力に設定
    pinMode (LOWLED, OUTPUT);           //上と同じ
    pinMode (PowerLED, OUTPUT);         //上と同じ
    Serial.begin(9600);                 //シリアル通信の設定
    Serial.print("Arduino / ON \n");    //シリアル通信で"Arduino / ON"と出力し改行
    digitalWrite(PowerLED,HIGH);        //電源確認用LEDを点灯
    sv.attach (Servo);                  //サーボ変数をピンに割り当てる
    sv.write (0);                       //サーボモーターを0度に動かす
    Serial.print("ServoPosition 0; \n");    //シリアル通信で"ServoPosition 0"を出力し改行
}

void loop() {
    if (digitalRead(HIGHinPin) == LOW) {            //第一センサーのピンの電圧が低いとき
        Serial.print("ServoPosition Motion; \n");
        digitalWrite(LOWLED, LOW);                  //LOWLEDを消灯
        digitalWrite(MotionLED, HIGH);              //MotionLEDを点灯
        sv.write(angle);                            //指定の角度にサーボモーターを動かす
    } else if(digitalRead(LOWinPin) == HIGH){       //第二センサーの電圧が高いとき
        Serial.print("ServoPosition LOW; \n");
        digitalWrite(MotionLED, LOW);
        digitalWrite(LOWLED, HIGH);
        delay(2500);                                //2.5秒プログラムを止める
        sv.write(0);
        digitalWrite(LOWLED, LOW);
    } else {                                        //それ以外のとき
        Serial.print("ServoPosition 0; \n");
        digitalWrite(LOWLED, LOW);
    }
}
