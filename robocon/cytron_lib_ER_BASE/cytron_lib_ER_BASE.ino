//zigbee receving end Program after testing with joystick
//To program ER to move in all directions

#include "CytronMotorDriver.h"

CytronMD motor1(PWM_DIR, 3,2);
CytronMD motor2(PWM_DIR, 5,4);
CytronMD motor3(PWM_DIR, 9,8);
CytronMD motor4(PWM_DIR, 11,10);

//pins for joystick
int vx1  = A0;
int vy1 = A1;
int vx2  = A2;
int vy2 = A3;

//variables for joystick
int x_pot1=0;
int y_pot1=0;
int x_pot2=0;
int speedx=0;
int speedy=0;
int speed_angle=0;

int potentiometer_region[]={-10,10};

void Plane(int vx,int vy){
  
  //Horizontal motion
  if ((abs(vx)>10) && (abs(vy)<10)){
    motor3.setSpeed(vx);
    motor4.setSpeed(vx);
  }
  
  //Verical motion
  else if ((abs(vx)<10) && (abs(vy)>10)){
    motor1.setSpeed(vy);
    motor2.setSpeed(vy);
  }
  //Diagonal motion
  else if((abs(vx)>10) && (abs(vy)>10)){
    motor1.setSpeed(vy);
    motor2.setSpeed(vy);
    motor3.setSpeed(vx);
    motor4.setSpeed(vx);
  }
  else if ((abs(vx)<10) && (abs(vy)<10)){
    //halts the motor
    motor3.setSpeed(0);
    motor4.setSpeed(0);
    motor1.setSpeed(0);
    motor2.setSpeed(0);
  }
  
}


//To rotate the robot on its own axis
void Revolve(int rpm){
  if (rpm>10){
    motor1.setSpeed(rpm);
    motor2.setSpeed(-rpm);
    motor3.setSpeed(rpm);
    motor4.setSpeed(-rpm);
  }
  else if (rpm<-10){
    motor1.setSpeed(rpm);
    motor2.setSpeed(-rpm);
    motor3.setSpeed(rpm);
    motor4.setSpeed(-rpm);
  }
  
}


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
  
pinMode(vx1, INPUT);
pinMode(vy1, INPUT);
pinMode(vx2, INPUT); 

}

void loop() {
  // put your main code here, to run repeatedly:

//Analog values reading from potentiometer
x_pot1 = analogRead(vx1);
y_pot1= analogRead(vy1);
x_pot2=analogRead(vx2);

//Mapping functions for analog potentiometer values
speedx = map(x_pot1, 0, 1023, -127, 127);
speedy= map(y_pot1, 0, 1023, -127, 127);
speed_angle=map(x_pot2,0,1023,-127,127);


// For Vertical motion ,Horizontal motion and Diagonal motion
Plane(speedx,speedy);

//For Revolving the robot on its axis
Revolve(speed_angle);

}
