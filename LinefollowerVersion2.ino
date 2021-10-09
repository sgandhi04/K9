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
double moveSpeed;
double lineFollowerSensor;
double lineDirIndex;
MeLineFollower linefollower_2(2);

void setup(){
}

void loop(){
    if((moveSpeed) > (230)){
        moveSpeed = 230;
    }
    lineFollowerSensor = linefollower_2.readSensors();
    if(((lineFollowerSensor)==(0))){
        move(1,100);
        lineDirIndex = 10;
    }else{
        if(((lineFollowerSensor)==(1))){
            move(1,100);
            if((lineDirIndex) > (1)){
                lineDirIndex = (lineDirIndex) - (1);
            }
        }else{
            if(((lineFollowerSensor)==(2))){
                move(1,100);
                if((lineDirIndex) < (20)){
                    lineDirIndex = (lineDirIndex) + (1);
                }
            }else{
                if(((lineDirIndex)==(10))){
                    move(2,100);
                }
            }
            if((lineDirIndex) < (10)){
                move(3,100);
            }
            if((lineDirIndex) > (10)){
                move(4,100);
            }
        }
    }
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
}





