
#include <Servo.h>

Servo motor1;
Servo motor2;
Servo motor3;
Servo motor4;

void setup() {
    //motors
    motor1.attach(3);
    motor2.attach(9);
    motor3.attach(10);
    motor4.attach(11);
    
    motor1.writeMicroseconds(1901); 
    motor2.writeMicroseconds(1901); 
    motor3.writeMicroseconds(1901); 
    motor4.writeMicroseconds(1901); 
    delay(2000);
    motor1.writeMicroseconds(1000); 
    motor2.writeMicroseconds(1000); 
    motor3.writeMicroseconds(1000); 
    motor4.writeMicroseconds(1000); 
    delay(6000);
     pinMode(LED_BUILTIN, OUTPUT);
    }

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
///*
//
//AUTHOR: Hazim Bitar (techbitar)
//DATE: Aug 29, 2013
//LICENSE: Public domain (use at your own risk)
//CONTACT: techbitar at gmail dot com (techbitar.com)
//
//*/
//
//
//#include <SoftwareSerial.h>
//
//SoftwareSerial BTSerial(10, 11); // RX | TX
//
//void setup()
//{
//  pinMode(9, OUTPUT);  // this pin will pull the HC-05 pin 34 (key pin) HIGH to switch module to AT mode
//  digitalWrite(9, HIGH);
//  Serial.begin(9600);
//  Serial.println("Enter AT commands:");
//  BTSerial.begin(38400);  // HC-05 default speed in AT command more
//}
//
//void loop()
//{
//
//  // Keep reading from HC-05 and send to Arduino Serial Monitor
//  if (BTSerial.available())
//    Serial.write(BTSerial.read());
//
//  // Keep reading from Arduino Serial Monitor and send to HC-05
//  if (Serial.available())
//    BTSerial.write(Serial.read());
//}
