#define CUSTOM_SETTINGS
#define INCLUDE_SMS_SHIELD

#include <Servo.h>  servo library
#include <OneSheeld.h>

Servo servo1; 
int buttonPin = 12;
int ledPin = 13;

void setup()
{
  servo1.attach(9);
  OneSheeld.begin();
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  int position;

  servo1.write(10);   

  delay(1000);         

  servo1.write(135);   

  delay(1000);         

  if(digitalRead(buttonPin) == HIGH)
  {
    
      digitalWrite(ledPin,HIGH);
      SMS.send("14085804355","I need help! Track me through Google Maps: https://maps.app.goo.gl/bSdX1EmWTIfZwrDU2.");
  
      OneSheeld.delay(300);
  }
  digitalWrite(ledPin,LOW);
}



