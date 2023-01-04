//Malek code

#include "CytronMotorDriver.h"

int VRx = A1;
int VRy = A2;

int RVRy = A8;

int xPosition = 0;
int yPosition = 0;
int RyPosition = 0;

int mapX = 0;
int mapY = 0;
int RmapY = 0;

/*
CytronMD M1(PWM_DIR, 2, 3); // PWM = Pin 2, DIR = Pin 3. Lower Left
CytronMD M2(PWM_DIR, 4, 5); // PWM = Pin 4, DIR = Pin 5. Upper Right

CytronMD M3(PWM_DIR, 6, 7); // PWM = Pin 6, DIR = Pin 7. Upper Left
CytronMD M4(PWM_DIR, 8, 9); // PWM = Pin 8, DIR = Pin 9. Lower Right
*/

CytronMD M1(PWM_DIR, 3, 2); // PWM = Pin 2, DIR = Pin 3. Lower Left
CytronMD M2(PWM_DIR, 5, 4); // PWM = Pin 4, DIR = Pin 5. Upper Right

CytronMD M3(PWM_DIR, 9, 8); // PWM = Pin 6, DIR = Pin 7. Upper Left
CytronMD M4(PWM_DIR, 11, 10); // PWM = Pin 8, DIR = Pin 9. Lower Right

void setup()
{
    Serial.begin(9600);
    pinMode(VRx, INPUT);
    pinMode(VRy, INPUT);
    pinMode(RVRy, INPUT);
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
    M1.setSpeed(mapX);
    M2.setSpeed(mapX);
    Serial.print("Forward\n");       
}

void backward()
{
    M1.setSpeed(mapX);
    M2.setSpeed(mapX);
    Serial.print("Backward\n");       
}

void right()
{
    M3.setSpeed(mapY);
    M4.setSpeed(mapY);
    Serial.print("Right\n"); 
}

void left()
{
    M3.setSpeed(mapY);
    M4.setSpeed(mapY);
    Serial.print("Left\n");
}

void LeftRotate()
{
  M1.setSpeed(RmapY);
  M2.setSpeed(-RmapY);
  M3.setSpeed(RmapY);
  M4.setSpeed(-RmapY);
  Serial.print("LeftRotate\n");
}

void RightRotate()
{
  M1.setSpeed(RmapY);
  M2.setSpeed(-RmapY);
  M3.setSpeed(RmapY);
  M4.setSpeed(-RmapY);
  Serial.print("RightRotate \n");
}

void diagonal()
{
  M1.setSpeed(mapX);
  M2.setSpeed(mapX);
  M3.setSpeed(mapY);
  M4.setSpeed(mapY);
  Serial.print("Diagonal \n"); 
}

void loop()
{
    xPosition = analogRead(VRx);
    yPosition = analogRead(VRy);
    RyPosition = analogRead(RVRy);
    
    mapX = map(xPosition, 0, 1023, -255, 255);
    mapY = map(yPosition, 0, 1023, -255, 255);
    RmapY = map(RyPosition, 0, 1023, -255, 255);     

    
   if(abs(abs(mapY) - abs(mapX)) < 30 && abs(mapY) >= 50 && abs(mapX) >= 50)
        {
          diagonal();
        }
   
   if (RmapY < -20)
        {
            LeftRotate();
        }
   else if (RmapY > 20)
        {
            RightRotate();
        }
   else if (mapX > 20)
        {
            forward();
        }
   else if (mapX < -20)
        {   
            backward();
        }
   else if (mapY > 20)
        {
            right();
        }
    else if (mapY < -20)
        {
            left();
        }
    else if (mapX > -20 && mapX < 20 && mapY > -20 && mapY < 20 && RmapY < 20 && RmapY > -20)
        {
            holt();
        }

    delay(100);
}
