#include<Servo.h>
Servo xservo;
Servo yservo;
Servo swservo;
int SWpin=13;
int Ypin=A0;
int S1pin=11;
int S2pin=10;
float sval1;
float sval2;
int Xpin=A1;
int swpin=9;
int d=500;
int xval;
int yval;
int swval;
int servostate;
void setup() {
  Serial.begin(9600);
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
pinMode(S1pin,OUTPUT);
pinMode(S2pin,OUTPUT);
pinMode(swpin,INPUT);
yservo.attach(S2pin);
xservo.attach(S1pin);
swservo.attach(SWpin);
digitalWrite(swpin,HIGH);
}

void loop() {
  xval=analogRead(Xpin);
  yval=analogRead(Ypin);
  Serial.print(xval);
  Serial.print(" , ");
  Serial.print(yval);
  sval1=(84.5/511.5)*(xval-511.5)+84.5;
  sval2=(84.5/511.5)*(yval-511.5)+84.5;
  Serial.print(" ' ");
  Serial.print(sval1);
  Serial.print(" , ");
  Serial.println(sval2);
  xservo.write(sval1);
  yservo.write(sval2);

swval=digitalRead(swpin);
if(swval==0){
  
  servostate=servostate+15;
}
if(servostate>170){
  
  servostate=0;
}
Serial.println(servostate);
swservo.write(servostate);
delay(d);


}
