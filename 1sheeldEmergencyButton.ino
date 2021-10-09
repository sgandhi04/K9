#define CUSTOM_SETTINGS
#define INCLUDE_SMS_SHIELD

#include <OneSheeld.h>

int buttonPin = 12;
int ledPin = 13;

void setup() 
{
  OneSheeld.begin();
  pinMode(buttonPin,INPUT);
  pinMode(ledPin,OUTPUT);
}

void loop()
{
  if(digitalRead(buttonPin) == HIGH)
  {
      digitalWrite(ledPin,HIGH);
      SMS.send("14085804355","I need help! Track me through Google Maps: https://maps.app.goo.gl/bSdX1EmWTIfZwrDU2.");
      OneSheeld.delay(300);
  }

  digitalWrite(ledPin,LOW);
}


