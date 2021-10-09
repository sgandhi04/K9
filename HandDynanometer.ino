#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <MeMCore.h>

MeDCMotor motor_9(9);
MeDCMotor motor_10(10);
void move(int direction, int speed)
{
      int leftSpeed = 0;
      int rightSpeed = 0;
      if(direction == 1){
        	leftSpeed = speed;
        	rightSpeed = speed;
      }else if(direction == 2){
        	leftSpeed = -speed;
        	rightSpeed = -speed;
      }else if(direction == 3){
        	leftSpeed = -speed;
        	rightSpeed = speed;
      }else if(direction == 4){
        	leftSpeed = speed;
        	rightSpeed = -speed;
      }
      motor_9.run((9)==M1?-(leftSpeed):(leftSpeed));
      motor_10.run((10)==M1?-(rightSpeed):(rightSpeed));
}
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
MeUltrasonicSensor ultrasonic_3(3);

void setup(){
}

void loop(){
    if((ultrasonic_3.distanceCm()) < (1)){
        motor_9.run((9)==M1?-(255):(255));
        motor_10.run((10)==M1?-(255):(255));
    }
    if(((1) < (ultrasonic_3.distanceCm())) && ((ultrasonic_3.distanceCm()) < (2))){
        motor_9.run((9)==M1?-(205):(205));
        motor_10.run((10)==M1?-(205):(205));
    }
    if(((2) < (ultrasonic_3.distanceCm())) && ((ultrasonic_3.distanceCm()) < (3))){
        motor_9.run((9)==M1?-(155):(155));
        motor_10.run((10)==M1?-(155):(155));
    }
    if(((3) < (ultrasonic_3.distanceCm())) && ((ultrasonic_3.distanceCm()) < (4))){
        motor_9.run((9)==M1?-(105):(105));
        motor_10.run((10)==M1?-(105):(105));
    }
    if(((4) < (ultrasonic_3.distanceCm())) && ((ultrasonic_3.distanceCm()) < (5))){
        motor_9.run((9)==M1?-(55):(55));
        motor_10.run((10)==M1?-(55):(55));
    }
    if(((5) < (ultrasonic_3.distanceCm())) && ((ultrasonic_3.distanceCm()) < (6))){
        motor_9.run((9)==M1?-(0):(0));
        motor_10.run((10)==M1?-(0):(0));
    }
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}
