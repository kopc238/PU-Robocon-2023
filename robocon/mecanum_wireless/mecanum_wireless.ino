#include "CytronMotorDriver.h"

//INPUT from serial1Monitor
char x;



CytronMD M3(PWM_DIR, 3, 2); // PWM = Pin 2, DIR = Pin 3. Lower Left
CytronMD M4(PWM_DIR, 5, 4); // PWM = Pin 4, DIR = Pin 5. Upper Right

CytronMD M1(PWM_DIR, 9, 8); // PWM = Pin 6, DIR = Pin 7. Upper Left
CytronMD M2(PWM_DIR, 11, 10); // PWM = Pin 8, DIR = Pin 9. Lower Right



void setup()
{
    Serial.begin(9600);

}

void holt()
{
    M1.setSpeed(0);
    M2.setSpeed(0);
    M3.setSpeed(0);
    M4.setSpeed(0);
    Serial.print("holt\n");
}

void forward()
{
    M1.setSpeed(64);
    M2.setSpeed(64);
    M3.setSpeed(64);
    M4.setSpeed(64);
    Serial.print("Forward\n");       
}

void backward()
{
    M1.setSpeed(-64);
    M2.setSpeed(-64);
    M3.setSpeed(-64);
    M4.setSpeed(-64);
    Serial.print("Backward\n");       
}

void right()
{
    M1.setSpeed(64);
    M2.setSpeed(-64);
    M3.setSpeed(-64);
    M4.setSpeed(64);
    Serial.print("Right\n"); 
}

void left()
{
    M1.setSpeed(-64);
    M2.setSpeed(64);
    M3.setSpeed(64);
    M4.setSpeed(-64);
    Serial.print("Left\n");
}

void  clock()
{
  M1.setSpeed(64);
  M2.setSpeed(-64);
  M3.setSpeed(64);
  M4.setSpeed(-64);
  Serial.print("clock\n");
}

void anticlock()
{
  M1.setSpeed(-64);
  M2.setSpeed(64);
  M3.setSpeed(-64);
  M4.setSpeed(64);
  Serial.print("anticlock\n");
}

void loop()
{


  if (Serial1.available()>0)
  {//if data comes in from Xbee ,send it out to Serial1 monitor
  
  x=Serial1.read();

  if(x=='F')
  {
    forward();
    }
  if(x=='B'){
    backward();
  }
  if(x=='R'){
    right();
  }
  if(x=='L'){
    left();
  }
  if(x=='A'){
    anticlock();
  }
  if(x=='C'){
    clock();
  }
  if(x=='H'){
    holt();
  }  
  }   
   
   
    delay(100);
}
