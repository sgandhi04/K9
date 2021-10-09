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
void lineFollow();
double moveSpeed;
double lineFollowerSensor;
double lineDirIndex;
MeLineFollower linefollower_2(2);
void backward();
void stop();
void turnLeft();
void turnRight();
void obstacleAvoidance();
void forward();
void makeCircle();
double dist;
MeIR ir;
MeUltrasonicSensor ultrasonic_1(1);
MeUltrasonicSensor ultrasonic_3(3);
Me7SegmentDisplay seg7_4(4);

void lineFollow()
{
    if((moveSpeed) > (230)){
        moveSpeed = 230;
    }
    lineFollowerSensor = linefollower_2.readSensors();
    if(((lineFollowerSensor)==(0))){
        forward();
        lineDirIndex = 10;
    }else{
        if(((lineFollowerSensor)==(1))){
            forward();
            if((lineDirIndex) > (1)){
                lineDirIndex = (lineDirIndex) - (1);
            }
        }else{
            if(((lineFollowerSensor)==(2))){
                forward();
                if((lineDirIndex) < (20)){
                    lineDirIndex = (lineDirIndex) + (1);
                }
            }else{
                if(((lineDirIndex)==(10))){
                    backward();
                }
                if((lineDirIndex) < (10)){
                    turnLeft();
                }
                if((lineDirIndex) > (10)){
                    turnRight();
                }
            }
        }
    }
}

void backward()
{
    motor_9.run((9)==M1?-((0) - (moveSpeed)):((0) - (moveSpeed)));
    motor_10.run((10)==M1?-((0) - (moveSpeed)):((0) - (moveSpeed)));
}

void stop()
{
    move(1,0);
}

void turnLeft()
{
    motor_9.run((9)==M1?-((moveSpeed) / (10)):((moveSpeed) / (10)));
    motor_10.run((10)==M1?-(moveSpeed):(moveSpeed));
}

void turnRight()
{
    motor_9.run((9)==M1?-(moveSpeed):(moveSpeed));
    motor_10.run((10)==M1?-((moveSpeed) / (10)):((moveSpeed) / (10)));
}

void obstacleAvoidance()
{
    turnLeft();
    _delay(1);
    stop();
    makeCircle();
}

void forward()
{
    motor_9.run((9)==M1?-(moveSpeed):(moveSpeed));
    motor_10.run((10)==M1?-(moveSpeed):(moveSpeed));
}

void makeCircle()
{
    motor_10.run((10)==M1?-((moveSpeed) - (75)):((moveSpeed) - (75)));
    motor_9.run((9)==M1?-((moveSpeed) + (30)):((moveSpeed) + (30)));
    while(!((linefollower_2.readSensors()) < (3)))
    {
        _loop();
    }
    stop();
}

void setup(){
    ir.begin();
    moveSpeed = 150;
    lineDirIndex = 10;
    while(!(ir.keyPressed(70)))
    {
        _loop();
        if(((3) < (ultrasonic_1.distanceCm())) && ((ultrasonic_1.distanceCm()) < (5.5))){
            dist = ultrasonic_3.distanceCm();
            if(((dist) < (  9)) && ((dist) > (1))){
                obstacleAvoidance();
            }else{
                lineFollow();
            }
        }else{
            motor_9.run((9)==M1?-(0):(0));
            motor_10.run((10)==M1?-(0):(0));
            seg7_4.display((float)ultrasonic_1.distanceCm());
        }
    }
}

void loop(){
    _loop();
}

void _delay(float seconds){
    long endTime = millis() + seconds * 1000;
    while(millis() < endTime)_loop();
}

void _loop(){
    ir.loop();
}


