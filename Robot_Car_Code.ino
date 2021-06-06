#include <SoftwareSerial.h>
SoftwareSerial BT(2, 3); 
long duration;
int distance;
#define trigPin 12
#define echoPin 13
#define enA 10
#define pin1 4
#define pin2 5
#define buzzer 8
#define pin3 6
#define pin4 7
#define enB 9

int xAxis=140, yAxis=140;

int motorA = 0;
int motorB = 0;

void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
pinMode(buzzer,OUTPUT);
pinMode(enA, OUTPUT);
pinMode(enB, OUTPUT);
pinMode(pin1, OUTPUT);
pinMode(pin2, OUTPUT);
pinMode(pin3, OUTPUT);
pinMode(pin4, OUTPUT);
Serial.begin(9600);
BT.begin(9600); // Default communication rate of the Bluetooth module
delay(500);
}

void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.println(distance);
  if (distance<5){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }
  while (BT.available() >= 2) {
    xAxis = BT.read();
    delay(10);
    yAxis = BT.read();
   Serial.print(xAxis);
   Serial.print(",");
   Serial.println(yAxis);
  }
  delay(10);
  


if (xAxis > 130 && xAxis <150 && yAxis > 130 && yAxis <150){Stop();}


if (yAxis > 130 && yAxis <150){    

if (xAxis < 130){left();
motorA = map(xAxis, 130, 60, 100, 255);
motorB = map(xAxis, 130, 60, 100, 255);    
}

if (xAxis > 150) {right();
motorA = map(xAxis, 150, 220, 100, 255);
motorB = map(xAxis, 150, 220, 100, 255); 
}

}else{

if (xAxis > 130 && xAxis <150){   

if (yAxis < 130){front();}
if (yAxis > 150){reverse();}

if (yAxis < 130){
motorA = map(yAxis, 130, 60, 100, 255);
motorB = map(yAxis, 130, 60, 100, 255); 
}

if (yAxis > 150){
motorA = map(yAxis, 150, 220, 100, 255);
motorB = map(yAxis, 150, 220, 100, 255);
 }
 
}else{

if (yAxis < 130){front();}
if (yAxis > 150){reverse();}

if (xAxis < 130){
motorA = 255;
motorB = map(xAxis, 130, 60, 255, 50); 
 }
 
if (xAxis > 150){
motorA = map(xAxis, 150, 220, 255, 50);
motorB = 255; 
  }
  
 } 
}

   //Serial.print(motorA);
   //Serial.print(",");
   //Serial.println(motorA);

analogWrite(enA, motorA); // Send PWM signal to motor A
analogWrite(enB, motorB); // Send PWM signal to motor B
}


void front(){Serial.println("front");
digitalWrite(pin1, HIGH);
digitalWrite(pin2, LOW); 
digitalWrite(pin3, HIGH);
digitalWrite(pin4, LOW);
}

void reverse(){Serial.println("reverse");
digitalWrite(pin1, LOW);
digitalWrite(pin2, HIGH); 
digitalWrite(pin3, LOW);
digitalWrite(pin4, HIGH);
}

void right(){Serial.println("right");
digitalWrite(pin1, HIGH);
digitalWrite(pin2, LOW); 
digitalWrite(pin3, LOW);
digitalWrite(pin4, HIGH);
}

void left(){Serial.println("left");
digitalWrite(pin1, LOW);
digitalWrite(pin2, HIGH); 
digitalWrite(pin3, HIGH);
digitalWrite(pin4, LOW);
}

void Stop(){
digitalWrite(pin1, LOW);
digitalWrite(pin2, LOW); 
digitalWrite(pin3, LOW);
digitalWrite(pin4, LOW);
Serial.println("stop");
}
