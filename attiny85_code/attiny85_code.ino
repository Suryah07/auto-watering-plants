//Upload this into attiny85
//This code helps microcontroller to check time and water the plants accordingly


#include <Wire.h>
#include "RTClib.h"
#include <SoftwareSerial.h>


//pinouts
#define relay 2
#define light 3

#define watertime 600 //time of motor to be on in seconds...


int hourarr[] = {11,12,14,15};
int minutearr[] = {01,20};
int arrlength = sizeof(hourarr)/sizeof(int);

RTC_DS1307 rtc;

void alert_no_connection()
{
  while(true)
  {
    digitalWrite(light,HIGH);
  }
}
void alert_light()
{
  while(true)
  {
    digitalWrite(light,HIGH);
    delay(200);
    digitalWrite(light,LOW);
    delay(200);
  }  
}

bool wateringtime(DateTime now)
{
  for(int i=0;i<arrlength;i++)
  {
    if(now.hour() == hourarr[i] and now.minute()>=01 and now.minute()<=9)
    {
      return true;      
    }
  }
  return false;
}

void setup () 
{
  pinMode(relay,OUTPUT);
  pinMode(light,OUTPUT);

  
  if (! rtc.begin()) {
    //Serial.println("Couldn't find RTC");
    alert_no_connection();
    
  }
  
  if (!rtc.isrunning()) {
    //Serial.println("RTC lost power, lets set the time!");
    alert_light();
  
    // Comment out below lines once you set the date & time.
    // Following line sets the RTC to the date & time this sketch was compiled
    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // Following line sets the RTC with an explicit date & time
    // for example to set January 27 2017 at 12:56 you would call:
    // rtc.adjust(DateTime(2017, 1, 27, 12, 56, 0));
  }
}

void loop () 
{
    DateTime now = rtc.now();
    if(wateringtime(now))
    {
      digitalWrite(relay,HIGH);
      delay(watertime);
      digitalWrite(relay,LOW);
    }
    //delay(1000);
}
