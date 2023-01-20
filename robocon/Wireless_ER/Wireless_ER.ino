//Code for ER arduino mega
//reciever end
// with zigbee interfaced 



#include "CytronMotorDriver.h"


//Motor pins for base
CytronMD BM1(PWM_DIR, 3, 2); 
CytronMD BM2(PWM_DIR, 5, 4); 
CytronMD BM3(PWM_DIR, 7, 6); 
CytronMD BM4(PWM_DIR, 9, 8); 


//INPUT from Serial1 Monitor
char x;


void setup()
{ 
  Serial1.begin(115200);  
}


void halt()
{
    BM1.setSpeed(0);
    BM2.setSpeed(0);
    BM3.setSpeed(0);
    BM4.setSpeed(0);
    Serial1.print("halt\n");
}

void forward()
{
    BM1.setSpeed(64);
    BM2.setSpeed(64);
    Serial1.print("Forward\n");       
}

void backward()
{
    BM1.setSpeed(-64);
    BM2.setSpeed(-64);
    Serial1.print("Backward\n");       
}

void right()
{
    BM3.setSpeed(64);
    BM4.setSpeed(-64);
    Serial1.print("Right\n"); 
}

void left()
{
    BM3.setSpeed(-64);
    BM4.setSpeed(64);
    Serial1.print("Left\n");
}

void LeftRotate()
{
  BM1.setSpeed(64);
  BM2.setSpeed(-64);
  BM3.setSpeed(64);
  BM4.setSpeed(64);
  Serial1.print("LeftRotate\n");
}

void RightRotate()
{
  BM1.setSpeed(-64);
  BM2.setSpeed(64);
  BM3.setSpeed(-64);
  BM4.setSpeed(-64);
  Serial1.print("RightRotate \n");
}



void loop()
{
  
    if (Serial1.available()>0)
  { // If data comes in from XBee, send it out to Serial1 monitor
    
    x=Serial1.read();
    
    if (x=='F')
        {
            forward();//Forward
        }
   else if (x=='B')
        {   
            backward();//Backward
        }
   else if (x=='R')
        {
            right();//Right
        }
    else if (x=='L')
        {
            left();//Left
        }
    else if (x=='A' )
        {
            LeftRotate();//Revolves anti-clockwise
        }
    else if (x=='C')
        {
            RightRotate();//Revolves clockwise
        }
    
    else if (x=='H')
        {
            halt();//STOP
        }

  }
}
