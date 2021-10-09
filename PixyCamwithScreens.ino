#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

#include <SPI.h>
#include "Pixy.h"
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
void EyesLeft2Right();
MeLEDMatrix ledMtx_4(4);
unsigned char drawBuffer[16];
unsigned char *drawTemp;
MeLEDMatrix ledMtx_2(2);
void EyesRight2Left();
double nofObjects;
double xPos;
Pixy pixy;
MeRGBLed rgbled_7(7, 7==7?2:4);
MeBuzzer buzzer;

void EyesLeft2Right()
{
drawTemp = new unsigned char[16]{0,0,60,98,94,94,60,0,0,0,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,60,98,94,94,60,0,0,0,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,60,98,94,94,60,0,0,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,60,98,94,94,60,0,0,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,0,60,98,94,94,60,0,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,0,60,98,94,94,60,0,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,0,0,60,98,94,94,60,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,0,0,60,98,94,94,60,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,60,98,94,94,60,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,60,98,94,94,60,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,0,60,98,94,94,60,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,0,60,98,94,94,60,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,0,0,60,98,94,94,60,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,0,0,60,98,94,94,60,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,0,0,0,60,98,94,94,60,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,0,0,0,60,98,94,94,60,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
}

void EyesRight2Left()
{
drawTemp = new unsigned char[16]{0,0,0,0,0,0,0,0,0,60,98,94,94,60,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,0,0,0,60,98,94,94,60,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,0,0,60,98,94,94,60,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,0,0,60,98,94,94,60,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,0,60,98,94,94,60,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,0,60,98,94,94,60,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,60,98,94,94,60,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,0,0,0,60,98,94,94,60,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,0,0,60,98,94,94,60,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,0,0,60,98,94,94,60,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,0,60,98,94,94,60,0,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,0,60,98,94,94,60,0,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,0,60,98,94,94,60,0,0,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,0,60,98,94,94,60,0,0,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
    _delay(0.1);
drawTemp = new unsigned char[16]{0,0,60,98,94,94,60,0,0,0,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{0,0,60,98,94,94,60,0,0,0,0,0,0,0,0,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
}

void setup(){
    ledMtx_4.setColorIndex(1);
    ledMtx_4.setBrightness(6);
    ledMtx_2.setColorIndex(1);
    ledMtx_2.setBrightness(6);
    pixy.init();
    EyesLeft2Right();
    EyesRight2Left();
drawTemp = new unsigned char[16]{0,0,0,255,16,40,68,146,17,0,96,144,144,144,127,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_4.drawBitmap(0,0,16,drawBuffer);
drawTemp = new unsigned char[16]{126,88,118,126,82,66,126,80,126,126,66,60,96,30,96,0};
    memcpy(drawBuffer,drawTemp,16);
    free(drawTemp);
    ledMtx_2.drawBitmap(0,0,16,drawBuffer);
}

void loop(){
    nofObjects = pixy.getBlocks();
    if((nofObjects) < (1)){
        move(1,0);
    }else{
        xPos = pixy.blocks[0].x;
        if(((120) < (xPos)) && ((xPos) < (200))){
            move(1,0);
        }else{
            if((xPos) < (120)){
                rgbled_7.setColor(0,255,0,0);
                rgbled_7.show();
                buzzer.tone(175, 500);
                delay(20);
                _delay(0.1);
            }else{
                rgbled_7.setColor(0,255,0,0);
                rgbled_7.show();
                buzzer.tone(698, 500);
                delay(20);
                _delay(0.1);
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
