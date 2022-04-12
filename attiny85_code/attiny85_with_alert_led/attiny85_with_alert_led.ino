//This code is to use with DS1302 RTC module, it permits you to setup the actual time and date
//And you can visualize them on the serial monitor
//Attach an led to pin PB2 for alert messages
//This code is a modified version of the code provided in virtuabotixRTC library
//Refer to https://Surtrtech.com for more information

#include <virtuabotixRTC.h> //Library used
//Or CLK -> PB4  , DAT -> PB3, Reset -> PB1


#define relay PB0 //Relay is connected to PB0
#define alertlight PB2 //Light for alerting for any errors
#define watertime 60000 //time of motor to be ON in milliseconds...


virtuabotixRTC myRTC(PB4, PB3, PB1); //If you change the wiring change the pins here also

int hourarr[] = {11,12,13,14,15,19}; //24 hour time formatt
int arrlength = sizeof(hourarr)/sizeof(int);
/*
void alert_no_connection()
{
  while(true)
  {
    digitalWrite(alertlight,HIGH);
  }
}
void alert_light()
{
  while(true)
  {
    digitalWrite(alertlight,HIGH);
    delay(200);
    digitalWrite(alertlight,LOW);
    delay(200);
  }  
}
*/
bool wateringtime(virtuabotixRTC tim)
{
  for(int i=0;i<arrlength;i++)
  {
    if(tim.hours == hourarr[i] and (tim.minutes==01 or tim.minutes==02))
    {
      return true;      
    }
  }
  return false;
}

void startwater()
{
  digitalWrite(relay,HIGH);
  delay(watertime);
  digitalWrite(relay,LOW);
}

void setup() {
  pinMode(relay,OUTPUT);
  pinMode(alertlight,OUTPUT);
// seconds, minutes, hours, day of the week, day of the month, month, year
//myRTC.setDS1302Time(00, 23, 18, 1, 11, 04, 2022); //Here you write your actual time/date as shown above 
}

void loop() 
{ 
 myRTC.updateTime();
 
 if(wateringtime(myRTC))
 {
  startwater();
 }
 delay(1000);
}
