#include "arduino_secrets.h"
#include "arduino_secrets.h"
/* 
  Sketch generated by the Arduino IoT Cloud Thing "Untitled"
  https://create.arduino.cc/cloud/things/6cf33399-7362-4c2f-bcac-369a13a34ac6 

  Arduino IoT Cloud Variables description

  The following variables are automatically generated and updated when changes are made to the Thing

  CloudRelativeHumidity main_Tank;
  CloudRelativeHumidity side_Tank;
  bool motor;
  bool motor_Start;
  bool motor_Stop;

  Variables which are marked as READ/WRITE in the Cloud Thing will also have functions
  which are called when their values are changed from the Dashboard.
  These functions are generated with the Thing and added at the end of this sketch.
*/

#include "thingProperties.h"



#include "ArduinoSort.h"

#define trigPin   5   //D1
#define echoPin   4   //D2
#define echoPin1  14   //D5
//#define batt  A1
//#define switch1   2   //D4    not using physical switch this time 
//#define switch2  14   //D5
#define relayon  12   //D6
#define relayoff 13   //D7
#define mtrlite  16   //D0
//#define rx 7
//#define tx 2





void setup() {
  
  
  pinMode(trigPin, OUTPUT);
      pinMode(relayon, OUTPUT);
       pinMode(relayoff, OUTPUT);
        pinMode(mtrlite, OUTPUT);
    //     pinMode(tx, OUTPUT);
          pinMode(echoPin, INPUT);
           pinMode(echoPin1, INPUT);
     //       pinMode(batt, INPUT);
 //            pinMode(switch1, INPUT);
   //           pinMode(switch2, INPUT);
   //            pinMode(rx, INPUT);
               Serial.begin(9600);
   //            Sentinal.begin(9600);
               digitalWrite(trigPin,0);
               digitalWrite(relayon,1);
               digitalWrite(relayoff,1);
               digitalWrite(mtrlite,1);
               
               
  delay(1500); 

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}



int order=0,d05=0,d15=0;
float d0a[10]={0},d1a[10]={0},ba[10]={0};
float d0=0,d1=0,b=0,d0l=0,d0s=200;
char l;
bool s1=0,s2=0,mtr=0,automtr=0;
int mtrstrt=0,mtrstp=0;




void motorstart(bool force)
{
    if(force)
    {
      Serial.println("  motor on");
       digitalWrite(relayoff,0);
       delay(1000);
       digitalWrite(relayoff,1);
       delay(200);
       digitalWrite(relayon,0);
       delay(1000);
       digitalWrite(relayon,1);
       mtr=1;
    }
    else
    {
      if(automtr)
      {
       digitalWrite(relayoff,0);
       delay(1000);
       digitalWrite(relayoff,1);
       delay(200);
       digitalWrite(relayon,0);
       delay(1000);
       digitalWrite(relayon,1);
       mtr=1;
      }
    }
}

void motorstop(bool force)
{
      if(force)
      {
        Serial.println("  motor off");
        digitalWrite(relayoff,0);
        delay(1000);
        digitalWrite(relayoff,1);
        mtr=0;
      }
      else
      {
        if(automtr)
        {
          digitalWrite(relayoff,0);
          delay(1000);
          digitalWrite(relayoff,1);
          mtr=0;
        }
      }
}


float ultrasense(bool sensor)
{
  float duration,distance;
  if(sensor==0)
  {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  delay(10);
  return distance;
  }
  else
  {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin1, HIGH);
  distance = (duration*.0343)/2;
  delay(10);
  return distance;
  }
}






void loop() {
  ArduinoCloud.update();
  if (ArduinoCloud.connected() == 0)
   {
     ArduinoCloud.begin(ArduinoIoTPreferredConnection);
     setDebugMessageLevel(2);
     ArduinoCloud.printDebugInfo();
   }
  // Your code here 
//if ( millis() >3600000UL * 3  ) ESP.restart() ;
  
  
 if(order>10)
 order=0;
 if(mtr==0)
digitalWrite(mtrlite,1);
else
digitalWrite(mtrlite,0);

if(order<10)
{
  d0a[order]=ultrasense(0);
}
delay(30);


if(order<10)
{
  d1a[order]=ultrasense(1);
}
delay(30);

if(order==10)
{
sortArray(d0a, 10);
d0=d0a[4]+d0a[5]+d0a[6];
d0=d0/3;

if((d0>=d0l)&&(d0>20))
d0l=d0;
else 
{
  if((d0>20)&&(d0l>20))
  {
    if(d0<(d0l-15))
   {
     d0l=d0;
     mtr=1;
   }
  }
}

if((d0<=d0s)&&(d0>20))
d0s=d0;
else
{
  if((d0>20)&&(d0s>20))
  {
    if(d0>(d0s+15))
    {
      d0s=d0;
      mtr=0;
    }
  }
}
}



if(order==10)
{
  sortArray(d1a, 10);
  d1=d1a[4]+d1a[5]+d1a[6];
  d1=d1/3;
}


if(order==10)
{
  sortArray(ba, 10);
  b=ba[4]+ba[5]+ba[6];
  b=b/3;
  if(b<13)
  l='B';
  else 
  l='L';
}
/*

if(analogRead(switch1)>100)
    s1=1;  
if(s1)
{
  if(analogRead(switch1)<100)
  {motorstart(1);
  s1=0;}
}


if(analogRead(switch2)>100)
  s2=1;
if(s2)
{
  if(analogRead(switch2)<100)
  {motorstop(1);
  s2=0;}
}
*/
if((d0<21)&&(d1<=17))
{
  if(mtr==1)
  motorstop(0);
}


if(d0>120)
{
  d05++;
  if((mtr=0)&&(d05>5))
  motorstart(0);
}
else
d05=0;



if(d1>80)
{
  if((mtr=0)&&(d15>5))
  motorstart(0);
}
else
d15=0;



if(order==10)
 { float d0perc,d1perc;
  d0perc=d0-20;
  d0perc/=1.3;
  d0perc=100-d0perc;

  d1perc=d1-16;
  d1perc/=1.3;
  d1perc=100-d1perc;
  
  main_Tank=d0perc;
  side_Tank=d1perc;
  motor=mtr;
  
  
  Serial.print("D0: ");
  Serial.print(d0);
  Serial.print(" : ");
  Serial.print(d0perc);
  Serial.print("% ");
  delay(10);
  Serial.print(" D1: ");
  Serial.print(d1);
  Serial.print(" : ");
  Serial.print(d1perc);
  Serial.print("% ");
  delay(10);
  Serial.print(" ");
  Serial.print(l);
  delay(10);
 Serial.print(" mtr= ");
 Serial.println(mtr);
 } 

  
  delay(100);
  d0=0;
  d1=0;
  b=0;
//  String s= (Sentinal.readStringUntil('\r'));
//Serial.println(s);
//if(s=="hey")
//Sentinal.println("yes buddy got u");
 order+=1;


  
  
  
}




/*
  Since MotorStart is READ_WRITE variable, onMotorStartChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMotorStartChange()  {
  // Add your code here to act upon MotorStart change
  mtrstrt++;
  if(mtrstrt==3)
  {
    mtrstrt=0;
    motorstart(1);
  }
}

/*
  Since MotorStop is READ_WRITE variable, onMotorStopChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMotorStopChange()  {
  // Add your code here to act upon MotorStop change
  mtrstp++;
  if(mtrstp==3)
  {
    mtrstp=0;
    motorstop(1);
  }
  
}







