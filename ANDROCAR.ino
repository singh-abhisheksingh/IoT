#define lmotorf 8
#define lmotorb 9
#define rmotorf 10
#define rmotorb 11
char data = '0';
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); 
  pinMode(lmotorf,OUTPUT);
  pinMode(rmotorf,OUTPUT);
  pinMode(lmotorb,OUTPUT);
  pinMode(rmotorb,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)      // Send data only when you receive data:
   {
      data = Serial.read();        //Read the incoming data & store into data
      Serial.print(data);          //Print Value inside data in Serial monitor
      Serial.print("\n");        
      if(data == '1')              // FORWARD
      {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
      }
      else if(data == '3')          //LEFT
      {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,HIGH);
    digitalWrite(rmotorb,LOW); 
      }
      else if(data == '2')          //RIGHT
      {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,HIGH); 
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,HIGH);
      }
      else if(data == '4')          //BACKWARD
      {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,HIGH);
    digitalWrite(rmotorb,HIGH);
      }
      else if(data == '5')          //STOP
      {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,LOW);
      }
    else if(data == '7')            //SLOW LEFT
      {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,HIGH);
    digitalWrite(lmotorb,HIGH);
    digitalWrite(rmotorb,LOW);
      }
       else if(data == '6')         //SLOW RIGHT
      {
    digitalWrite(lmotorf,HIGH);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,HIGH);
      }
       else if(data == '9')         //BACK LEFT
      {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,LOW);
    digitalWrite(rmotorb,HIGH);
      }
    else if(data == '8')            //BACK RIGHT
      {
    digitalWrite(lmotorf,LOW);
    digitalWrite(rmotorf,LOW);
    digitalWrite(lmotorb,HIGH );
    digitalWrite(rmotorb,LOW);
      }
   }
   
}
