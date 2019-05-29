#define lmotorf 9
#define lmotorb 3
#define rmotorf 10
#define rmotorb 11

#include"Ultrasonic.h"
Ultrasonic ultrasonic(A0,A1);

int distance; 
int c=0;
void setup()
{
  Serial.begin(9600);
  pinMode(lmotorf,OUTPUT);
  pinMode(rmotorf,OUTPUT);
  pinMode(lmotorb,OUTPUT);
  pinMode(rmotorb,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);

}
void loop() {
  int msensor=digitalRead(5);
  int lsensor=digitalRead(6);
  int rsensor=digitalRead(7);
  int paststate=5;
  // put your main code here, to run repeatedly:
  distance=ultrasonic.Ranging(CM);
  Serial.print("Object found at:");
  Serial.print(distance);
  Serial.println("cm");
  if((distance<=20)&&(c==0))
  {
    c++;  
      
      digitalWrite(lmotorf,LOW);
      digitalWrite(rmotorf,LOW);
      digitalWrite(lmotorb,LOW);
      digitalWrite(rmotorb,LOW);
      digitalWrite(8,HIGH);
      digitalWrite(12,LOW);
  delay(5000); 
      digitalWrite(8,LOW);
      digitalWrite(12,LOW);
  }
  
  else if((lsensor==HIGH)&&(rsensor==HIGH)&&(msensor==LOW)) //WBW forward
  {
   analogWrite(lmotorf,190);
   analogWrite(rmotorf,190);
   digitalWrite(lmotorb,LOW);
   digitalWrite(rmotorb,LOW);
   delay(100);
   paststate=8;
  }
  else if((lsensor==HIGH)&&(rsensor==LOW)&&(msensor==LOW)) //WBB right
  {
    //delay(1000);
    analogWrite(lmotorf,190);
    analogWrite(rmotorf,0);
    analogWrite(lmotorb,0);   
    analogWrite(rmotorb,190);
    delay(100);
    paststate=6;
  }
  else if((lsensor==LOW)&&(rsensor==LOW)&&(msensor==HIGH)) //BWB forward
  {
   analogWrite(lmotorf,150);
   analogWrite(rmotorf,150);
   digitalWrite(lmotorb,LOW);
   digitalWrite(rmotorb,LOW);
   delay(100);
   paststate=8;
  }

  else if((lsensor==LOW)&&(rsensor==HIGH)&&(msensor==HIGH)) // BWW left
  {
    analogWrite(lmotorf,0);
    analogWrite(rmotorf,150);
    analogWrite(lmotorb,150);
    analogWrite(rmotorb,0);
    delay(100);
    paststate=4;
  }
  else if((lsensor==HIGH)&&(rsensor==HIGH)&&(msensor==HIGH)) // WWW
  {
    if(paststate==4)
    {
      analogWrite(lmotorf,0);
      analogWrite(rmotorf,150);
      analogWrite(lmotorb,150);
     analogWrite(rmotorb,0);
     delay(100);
     paststate=4;
    }
    else if(paststate==6)
    {
      analogWrite(lmotorf,150);
    analogWrite(rmotorf,0);
    analogWrite(lmotorb,0);   
    analogWrite(rmotorb,150);
    delay(100);
    paststate=6;
    }
    else
    {
      analogWrite(lmotorf,150);
   analogWrite(rmotorf,150);
   digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
    delay(100);
    paststate=8;
    }
  }
  else if((lsensor==LOW)&&(rsensor==LOW)&&(msensor==LOW)) ///BBB right
  {
    analogWrite(lmotorf,150);
    analogWrite(rmotorf,0);
    analogWrite(lmotorb,0);   
    analogWrite(rmotorb,150);
    delay(100);
    paststate=6;
  }
   else if((lsensor==LOW)&&(rsensor==HIGH)&&(msensor==LOW)) //BBW left
  {
    analogWrite(lmotorf,0);
    analogWrite(rmotorf,150);
    analogWrite(lmotorb,150);
    analogWrite(rmotorb,0);
    delay(100);
    paststate=4;
  }
  else if((lsensor==HIGH)&&(rsensor==LOW)&&(msensor==HIGH)) //WWB right
  {
     analogWrite(lmotorf,150);
    analogWrite(rmotorf,0);
    analogWrite(lmotorb,0);   
    analogWrite(rmotorb,150);
    delay(100);
    paststate=6;
  }
  analogWrite(lmotorf,150);
   analogWrite(rmotorf,150);
   digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
    delay(5);
}
