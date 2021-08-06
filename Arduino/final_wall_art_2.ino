#include "SerialTransfer.h"
#include <math.h>
#include <AccelStepper.h>
#define HALFSTEP 8

#define motorPin1  8     // IN1 on the ULN2003 driver 1
#define motorPin2  9     // IN2 on the ULN2003 driver 1
#define motorPin3  10     // IN3 on the ULN2003 driver 1
#define motorPin4  11     // IN4 on the ULN2003 driver 1

#define motorPin5  3     // IN1 on the ULN2003 driver 2
#define motorPin6  4     // IN2 on the ULN2003 driver 2
#define motorPin7  5    // IN3 on the ULN2003 driver 2
#define motorPin8  6    // IN4 on the ULN2003 driver 2
int stepperSpeed = 1000; //speed of the stepper (steps per second)
float steps1 = 0; // keep track of the step count for motor 1
float steps2=0;
float target1=0;
float target2=0;
boolean turn1 = true;
float n=0;
// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

SerialTransfer myTransfer;
float x[30];
float y[30];

void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 myTransfer.begin(Serial);
 
 
}


void loop() {
  // put your main code here, to run repeatedly:
  uint16_t Size = 0;
  Size=myTransfer.txObj(n,Size);
  myTransfer.sendData(Size);
  n=n+30;
  while(1)
  {
      if(myTransfer.available())
  {
    uint16_t recSize=0;
    recSize = myTransfer.rxObj(x,recSize);
    recSize = myTransfer.rxObj(y,recSize);
    
    uint16_t sendSize = 0;
    sendSize = myTransfer.txObj(x,sendSize);
    sendSize=myTransfer.txObj(y,sendSize);
    myTransfer.sendData(sendSize);
    delay(500);
    break;
  }
  }
 delay(1000); //sime time to put the robot down after swithing it on

  stepper1.setMaxSpeed(2000.0);
  stepper1.move(1);  // I found this necessary
  stepper1.setSpeed(stepperSpeed);

  stepper2.setMaxSpeed(2000.0);
  stepper2.move(-1);  // I found this necessary
  stepper2.setSpeed(stepperSpeed);
  float x3=132-(x[0])*(84/743)-7;
  float initial_l1=sqrt(sq((x[0])*(84/743)-6)+sq((y[0])*(83/756)-4)); //in cm
  float initial_l2=sqrt( sq(x3) +sq((y[0])*(83/756)-4)); //in cm
  

  for(int i=1;i<30;i++)
  { 
    turn1=true;
    float x2=132-(x[i])*(84/743)-7;
    float length1=sqrt(sq((x[i])*(84/743)-6)+sq((y[i])*(83/756)-4));
    float length2=sqrt(sq(x2) +sq((y[i])*(83/756)-4));
    float target1=(5000/6)*(length1-initial_l1);   //target steps for stepper1 motor
    float target2=(5000/5)*(length2-initial_l2);   //targer steps for stepper2 motor
    initial_l1=length1;
    initial_l2=length2;
    
     
   do{
    if(turn1){
      stepper1.move(-target1);
      stepper1.setSpeed(stepperSpeed);
      stepper2.move(-target2);
      stepper2.setSpeed(stepperSpeed);
      turn1 = false;
      
    }
     steps1 = stepper1.distanceToGo();
     steps2 = stepper2.distanceToGo();
     if(steps1!=0) stepper1.runSpeedToPosition();
     if(steps2!=0)  stepper2.runSpeedToPosition();
  }while(steps1!=0 or steps2!=0);
  }

delay(1000);
}
