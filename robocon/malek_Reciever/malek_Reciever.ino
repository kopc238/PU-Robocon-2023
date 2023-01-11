//Code for ER arduino mega
//reciever end
//Also this code has 

#include "CytronMotorDriver.h"


//Motor pins for base
CytronMD BM1(PWM_DIR, 3, 2); 
CytronMD BM2(PWM_DIR, 5, 4); 
CytronMD BM3(PWM_DIR, 7, 6); 
CytronMD BM4(PWM_DIR, 9, 8); 

int motor_speed=127;

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
}

void forward(){
  for (int i=0;i<127;i++){
      BM1.setSpeed(i);
      BM2.setSpeed(i);  
    }
}

void backward(){
    for (int i=0;i<127;i++){
      BM1.setSpeed(-i);
      BM2.setSpeed(-i);  
    }
}

void right(){
  for (int i=0;i<127;i++){
      BM3.setSpeed(i);
      BM4.setSpeed(-i);  
    }
}

void left(){
    for (int i=0;i<127;i++){
      BM3.setSpeed(-i);
      BM4.setSpeed(i);  
    }
}

void LeftRotate(){
  for (int i=0;i<127;i++){
      BM1.setSpeed(i);
      BM2.setSpeed(-i);  
      BM3.setSpeed(i);
      BM4.setSpeed(i); 
    }
}

void RightRotate(){
  for (int i=0;i<127;i++){
      BM1.setSpeed(-i);
      BM2.setSpeed(i);  
      BM3.setSpeed(-i);
      BM4.setSpeed(-i); 
    }
}
  
void Diagonal(char x){
  if (x=='P'){
    //forward and right
    for (int i=0;i<127;i++){
      BM1.setSpeed(i);
      BM2.setSpeed(i);  
      BM3.setSpeed(i);
      BM4.setSpeed(-i); 
    }
  }
   else if (x=='Q'){   
    //forward and left
    for (int i=0;i<127;i++){
      BM1.setSpeed(i);
      BM2.setSpeed(i);  
      BM3.setSpeed(-i);
      BM4.setSpeed(i); 
    }
  }
   else if (x=='Z'){
    //backward and left
    for (int i=0;i<127;i++){
      BM1.setSpeed(-i);
      BM2.setSpeed(-i);  
      BM3.setSpeed(-i);
      BM4.setSpeed(i); 
    }
  }
    else if (x=='M'){
      //backward and right
      for (int i=0;i<127;i++){
      BM1.setSpeed(-i);
      BM2.setSpeed(-i);  
      BM3.setSpeed(i);
      BM4.setSpeed(-i); 
    }
  }
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
    else if(x=='P' || x=='Q' || x=='Z' || x=='M')
        {
          Diagonal(x);//Diagonal movement
        }
    else if (x=='H')
        {
            halt();//STOP
        }

  }
}
