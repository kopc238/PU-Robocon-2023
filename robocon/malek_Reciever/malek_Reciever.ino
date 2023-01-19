//Code for ER arduino mega
//reciever end
//Also this code has gradual speed

#include "CytronMotorDriver.h"


//Motor pins for base
CytronMD BM1(PWM_DIR, 3, 2); 
CytronMD BM2(PWM_DIR, 5, 4); 
CytronMD BM3(PWM_DIR, 7, 6); 
CytronMD BM4(PWM_DIR, 9, 8); 

int vertical_speed=0,vertical_limit=127;
int horizontal_speed=0,horizontal_limit=127;
int rotational_speed=0,rotational_limit=127;

//INPUT from Serial1 Monitor
char x;


void setup()
{ 
  Serial1.begin(115200);
}


void halt(){
  if(vertical_speed!=0 || horizontal_speed!=0 || rotational_speed!=0){
    if (abs(vertical_speed)>0){
      for(int i=0;i<abs(vertical_speed);i++){
        if(vertical_speed>0){
          vertical_speed--;
        }else{
          vertical_speed++;
        }
        BM1.setSpeed(vertical_speed);
        BM2.setSpeed(vertical_speed);
      }
    }
    if (abs(horizontal_speed)>0){
      for(int i=0;i<abs(horizontal_speed);i++){
        if(horizontal_speed>0){
          horizontal_speed--;
        }else{
          horizontal_speed++;
        }
        BM3.setSpeed(horizontal_speed);
        BM4.setSpeed(-horizontal_speed);
      }
    }
    if (abs(rotational_speed)>0){
      for(int i=0;i<abs(rotational_speed);i++){
        if(rotational_speed>0){
          rotational_speed--;
        }else{
          rotational_speed++;
        }
        BM1.setSpeed(-rotational_speed);
        BM2.setSpeed(rotational_speed);  
        BM3.setSpeed(-rotational_speed);
        BM4.setSpeed(-rotational_speed); 
      }
    }
  }
  else{
        BM1.setSpeed(0);
        BM2.setSpeed(0);  
        BM3.setSpeed(0);
        BM4.setSpeed(0); 
  }
}

void Vertical(){
      BM1.setSpeed(vertical_speed);
      BM2.setSpeed(vertical_speed);
}


void Horizontal(){
      BM3.setSpeed(horizontal_speed);
      BM4.setSpeed(-horizontal_speed);  
}

void Rotate(){
      BM1.setSpeed(-rotational_speed);
      BM2.setSpeed(rotational_speed);  
      BM3.setSpeed(-rotational_speed);
      BM4.setSpeed(-rotational_speed); 
}




void loop(){
  
    if (Serial1.available()>0){
      
      // If data comes in from XBee, send it out to Serial1 monitor
    
    
    x=Serial1.read();

    //forward
    if (x=='F'){
      if (abs(vertical_speed)<vertical_limit){
         vertical_speed++;
      }
      else {
          vertical_speed=vertical_limit;
      }
    Vertical();//Forward
    }


   //Backward 
   else if (x=='B'){
      if (abs(vertical_speed)<vertical_limit){
         vertical_speed--;
      }
      else {
          vertical_speed=-vertical_limit;
      }
    Vertical();//backward
    }

   //right     
   else if (x=='R'){
      if (abs(horizontal_speed)<horizontal_limit){
         horizontal_speed++;
      }
      else {
          horizontal_speed=horizontal_limit;
      }
      Horizontal();//Right
    }

    //left    
    else if (x=='L'){
      if (abs(horizontal_speed)<horizontal_limit){
         horizontal_speed--;
      }
      else {
          horizontal_speed=-horizontal_limit;
      }
     Horizontal();//Left
    }

    //Anti-clockwise
    else if (x=='A' ){
      if (abs(rotational_speed)<rotational_limit){
         rotational_speed--;
      }
      else {
          rotational_speed=-rotational_limit;
      }
    Rotate();//Anti clock wise
    }

    //Clockwise
    else if (x=='C'){
      if (abs(rotational_speed)<rotational_limit){
         rotational_speed++;
      }
      else {
          rotational_speed=rotational_limit;
      }
    Rotate();//Clock-wise
    }
    
    else if (x=='H')
        {
            halt();//STOP
        }

  }

  delay(100);
}










/*
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
*/
