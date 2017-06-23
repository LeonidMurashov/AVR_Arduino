#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeOrion.h>

double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeDCMotor motor_9(9);
MeDCMotor motor_10(10);
MeDCMotor motor_1(1);
MeDCMotor motor_2(2);

void setup(){
    Serial.begin(9600);
    motor_9.run(0);
    motor_10.run(0);
    motor_1.run(0);
    motor_2.run(0);
}

void loop(){
    Serial.println("fff");
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}
