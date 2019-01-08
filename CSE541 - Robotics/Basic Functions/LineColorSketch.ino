//Michael Smith
//Hon Huynh
//Line tracker Car

//Line tracker and Color Sensor Sketch
#include <Adafruit_TCS34725.h>
#include <Wire.h>
#include <NewPing.h>

//Color Sensor variable declaration
Adafruit_TCS34725 tcs = Adafruit_TCS34725();



//Direction declaration
#define CW 0
#define CCW 1

//Motor Definitions
#define MOTOR_A 0
#define MOTOR_B 1

#define maxDistance 500

//Pin Assignments
const byte PWMA = 3;
const byte PWMB = 11;
const byte DIRA = 12;
const byte DIRB = 13;
const int trigPin = 9;
const int echoPin = 10;

//Line sensor pin declaration
int qreLeft = A0; //connected to Analog 2
int qreRight = A2; //connected to Analog 0

byte spd = 2250; //forward speed
byte hispd = 255; //turning speed

int distance;

//Line Check threshold
int threshold = 800;

NewPing sonar(trigPin, echoPin, maxDistance);

int QRE_Left;
int QRE_Right;

void setup() {
  setupArdumoto(); //Set up and initialize the pins
  //Color sensor check 
  if(tcs.begin()){
  } else {
    allStop();
    while(1);
  }
}

void loop() {
  distance = sonar.ping_median();
  distance = sonar.convert_cm(distance);
  uint16_t r, g, b, c, colorTemp, lux;
  int QRE_Left = analogRead(qreLeft);
  int QRE_Right = analogRead(qreRight);
  tcs.getRawData(&r, &g, &b, &c);
   if (c > 50){      //need to recalibrate depending on surface and lighting
    if(QRE_Left > threshold && QRE_Right > threshold){
      forward();
    } else if (QRE_Left < threshold && QRE_Right > threshold){
      bearRight();
    } else if (QRE_Left > threshold && QRE_Right < threshold){
      bearLeft();
    }
    if(distance < 12 && distance !=4 && distance != 0 && distance != 5){
      pivot();
    }
    if(distance <10){
      pivot();
    } 
  }
  
   else{   //Red line check and stop for 2 seconds
      allStop();
      delay(2000);
      forward();
      delay(100);
   }
}

//Motor control
void driveArdumoto(byte motor, byte dir, byte spd){
  if (motor == MOTOR_A){
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  } else if (motor == MOTOR_B){
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }
}

void forward(){
  driveArdumoto(MOTOR_A, CW, spd);
  driveArdumoto(MOTOR_B, CW, spd);
}

void bearRight(){
  driveArdumoto(MOTOR_B, CW, 0);
  driveArdumoto(MOTOR_A, CW, hispd);
}

void bearLeft(){
  driveArdumoto(MOTOR_B, CW, hispd);
  driveArdumoto(MOTOR_A, CW, 0);
}

void stopArdumoto(byte motor){
  driveArdumoto(motor, 0, 0);
}

void allStop(){
  stopArdumoto(MOTOR_A);
  stopArdumoto(MOTOR_B);
}

void searchLine() {
  forward();
  delay(500);
  driveArdumoto(MOTOR_A, CW, 110); //Motor B STOP
  driveArdumoto(MOTOR_B, CW, 80); //Motor A SLOW 
}

void pivot(){
    brake();
    driveArdumoto(MOTOR_A, CCW, 175);
    driveArdumoto(MOTOR_B, CCW, 175 / 2);
    delay(500);
    brake();
    while(QRE_Left < threshold || QRE_Right < threshold){
      searchLine();
      break;
    }
}

void brake(){
  driveArdumoto(MOTOR_A, CW, 0); //Motor B hiSpd
  driveArdumoto(MOTOR_B, CW, 0); //Motor A STOP 
}

//Pin and direction initialization
void setupArdumoto(){
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);
  pinMode(trigPin, OUTPUT);   // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);      // Sets the echoPin as an Input

  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}

