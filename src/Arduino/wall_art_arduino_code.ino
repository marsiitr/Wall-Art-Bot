#include "SerialTransfer.h"
#include <math.h>
#include <AccelStepper.h>
#define HALFSTEP 8

#define motorPin1  8     // IN1 on the ULN2003 driver 1
#define motorPin2  9     // IN2 on the ULN2003 driver 1
#define motorPin3  10    // IN3 on the ULN2003 driver 1
#define motorPin4  11    // IN4 on the ULN2003 driver 1

#define motorPin5  3     // IN1 on the ULN2003 driver 2
#define motorPin6  4     // IN2 on the ULN2003 driver 2
#define motorPin7  5    // IN3 on the ULN2003 driver 2
#define motorPin8  6    // IN4 on the ULN2003 driver 2
int stepperSpeed = 1000; //speed of the stepper (steps per second)
float steps1 = 0; // keep track of the step count for motor 1
float steps2=0;   // keep track of the step count for motor 2
float target1=0;  //target steps of motor 1
float target2=0;  //target steps of motor 2
boolean turn1 = true;
float n=0;
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4); //Initialising with motor 1
AccelStepper stepper2(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8); // Initialising with motor2 

SerialTransfer myTransfer;   
float x[30];  //creating x coordinate array
float y[30];  //creating y coordinate array

void setup() {
 Serial.begin(115200);  
 myTransfer.begin(Serial); //staring serial communication between arduino and python
}


void loop() {
  uint16_t Size = 0;  
  //sending n to python
  Size=myTransfer.txObj(n,Size); //here value of size is "index of last byte in tx buffer+1"
  myTransfer.sendData(Size);     //sending data packet to python
  n=n+30;
  while(1)
  {
      if(myTransfer.available())
  {
    uint16_t recSize=0;
    recSize = myTransfer.rxObj(x,recSize);   //storing the received x-xoordinate array into x
    recSize = myTransfer.rxObj(y,recSize);   //storing the received y-xoordinate array into y
    
    uint16_t sendSize = 0;
    sendSize = myTransfer.txObj(x,sendSize); //sending "x" to python for verification purposes(temporarily storing in tx buffer)
    sendSize=myTransfer.txObj(y,sendSize);   //sending "y" to python for verification purposes (temporarily storing in tx buffer)
    myTransfer.sendData(sendSize);           //finally sending data packet to python
    delay(500);
    break;
  }
  }
 delay(1000); //some time to put the bot down after swithing it on

  stepper1.setMaxSpeed(2000.0); 
  stepper1.move(1);  // I found this necessary
  stepper1.setSpeed(stepperSpeed); //setting speed of motor 1

  stepper2.setMaxSpeed(2000.0);
  stepper2.move(-1);  // I found this necessary
  stepper2.setSpeed(stepperSpeed); //setting speed of motor 2

  float x3=132-(x[0])*(84/743)-7;
  float initial_l1=sqrt(sq((x[0])*(84/743)-6)+sq((y[0])*(83/756)-4)); //in cm
  float initial_l2=sqrt( sq(x3) +sq((y[0])*(83/756)-4)); //in cm
  
  for(int i=1;i<30;i++)
  { 
    turn1=true;
    float x2=132-(x[i])*(84/743)-7;
    float length1=sqrt(sq((x[i])*(84/743)-6)+sq((y[i])*(83/756)-4)); //finding length of string 1
    float length2=sqrt(sq(x2) +sq((y[i])*(83/756)-4));               //finding length of string 2
    float target1=(5000/6)*(length1-initial_l1);   //target steps for stepper1 motor
    float target2=(5000/5)*(length2-initial_l2);   //targer steps for stepper2 motor
    initial_l1=length1;
    initial_l2=length2;
    
     
   do{
    if(turn1){
      stepper1.move(-target1);  //setting the target of motor 1
      stepper1.setSpeed(stepperSpeed);
      stepper2.move(-target2);  //setting the target of motor 2
      stepper2.setSpeed(stepperSpeed);
      turn1 = false;
      
    }
     steps1 = stepper1.distanceToGo(); // distance from the current position of motor 1 to the target position in steps
     steps2 = stepper2.distanceToGo(); // distance from the current position of motor 2 to the target position in steps
     if(steps1!=0) stepper1.runSpeedToPosition(); //running motor 1 at constant given speed
     if(steps2!=0)  stepper2.runSpeedToPosition(); //running motor 2 at constant given speed
  }while(steps1!=0 or steps2!=0);
  }

delay(1000);
}
