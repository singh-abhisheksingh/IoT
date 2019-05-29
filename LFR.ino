#define lmotorf 9
#define lmotorb 8
#define rmotorf 10
#define rmotorb 11

void setup()
{
  pinMode(lmotorf,OUTPUT);
  pinMode(rmotorf,OUTPUT);
  pinMode(lmotorb,OUTPUT);
  pinMode(rmotorb,OUTPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop()
{
  int lsensor=digitalRead(6);
  int rsensor=digitalRead(7);
  digitalWrite(3,LOW);
  digitalWrite(5,HIGH);

  if((lsensor==HIGH)&&(rsensor==HIGH))
  {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
  }
  else if((lsensor==HIGH)&&(rsensor==LOW))
  {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,HIGH);
  }
  else if((lsensor==LOW)&&(rsensor==HIGH))
  {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,HIGH);
    digitalWrite(rmotorb,LOW);
  }
  else
    {
      digitalWrite(lmotorf,LOW);
      digitalWrite(rmotorf,LOW);
      digitalWrite(lmotorb,LOW);
      digitalWrite(rmotorb,LOW);
      
    }
}
