#include<Servo.h>
int spin=3;
Servo mtr;
int pts;
int trigpin=12;
int echopin=11;
int distance;
int bpin=7;
void setup() {
 Serial.begin(9600);
 pinMode(spin,OUTPUT);
 pinMode(trigpin,OUTPUT);
 pinMode(echopin,INPUT);
 pinMode(bpin,OUTPUT);
 mtr.attach(spin);

}

void loop() {
  for(pts=0;pts<=180;pts=pts+15){
   
 mtr.write(pts);
 delay(10);
 if(pts==180){
  for(pts=180;pts>=0;pts=pts-15){
    mtr.write(pts);
    digitalWrite(trigpin,LOW);
delayMicroseconds(10);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
delayMicroseconds(10);
    distance=pulseIn(echopin,HIGH);
    Serial.println(distance);
 delay(150);
 if(distance<=500){
  digitalWrite(bpin,HIGH);
}
else{
  digitalWrite(bpin,LOW);
}
  }}
  
 digitalWrite(trigpin,LOW);
delayMicroseconds(10);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
digitalWrite(trigpin,LOW);
delayMicroseconds(10);
distance=pulseIn(echopin,HIGH);
Serial.println(distance);
delay(250);
if(distance<=500){
  digitalWrite(bpin,HIGH);
}
else{
  digitalWrite(bpin,LOW);
}
  
  }

}
