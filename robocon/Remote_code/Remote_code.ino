//Code for new remote of Elephant Robot
//arduino uno



//for potentiometer one 
int VRx = A0;
int VRy = A1;

//for potentiometer Two
int RVRx = A2;
int AVRy = A3;

//Switch button
int grip=5;
int load=6;
int idk=7;

//buttonstates
int grip_state=0,load_state=0,idk_state=0;

//for potentiometer
int pot= A4;
int pot_value=0;
int pot_map;


//Variables for poteniometer from joystick
int xPosition = 0;
int yPosition = 0;
int RxPosition = 0;
int AyPosition = 0;


//mapping variables
int mapX = 0;
int mapY = 0;
int RmapX = 0;
int AmapY = 0;

char x;
char check;



void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(VRx, INPUT);
    pinMode(VRy, INPUT);
    pinMode(RVRx, INPUT);
    pinMode(AVRy, INPUT);

    pinMode(grip,INPUT_PULLUP);
    pinMode(load,INPUT_PULLUP);
    pinMode(idk,INPUT_PULLUP);
    pinMode(pot,INPUT);
}




void loop() {
  // put your main code here, to run repeatedly:
    
    //Reading analog and digital values
    xPosition = analogRead(VRx);
    yPosition = analogRead(VRy);
    RxPosition = analogRead(RVRx);
    AyPosition = analogRead(AVRy);
    pot_value=analogRead(pot);

    //mapping functions for analog values
    mapX = map(xPosition, 0, 1023, -255, 255);
    mapY = map(yPosition, 0, 1023, -255, 255);
    RmapX = map(AyPosition, 0, 1023, -255, 255); 
    AmapY = map(RxPosition, 0, 1023, -255, 255); 
    pot_map=map(pot_value,0,1023,0,250);

    grip_state = digitalRead(grip);
    load_state = digitalRead(load);
    idk_state = digitalRead(idk);

   
     senddata();
   
   
    
   
 //delay(50);
}

void senddata(){
  
  if (pot_value>300 && pot_value<700){
    
   //To Revolve robot in all clockwise and Anti-clockwise.
   if (RmapX< -20 && abs(AmapY) < 20)
        {
          x='A';//Anti-CW-rotation
        }
   else if (RmapX > 20 && abs(AmapY) < 20)
        {
          x='C';//CW-rotation
        }

   //
   if (AmapY < -20 && abs(RmapX) < 20)
        {
          x='D';//Anti-CW-rotation
        }
   else if (AmapY > 20 && abs(RmapX) < 20)
        {
          x='U';//CW-rotation
        }
   


   //Diagonal motion 
   if (mapX>20 && mapY>20){
    x='P';// P=F+R
   }
   if (mapX>20 && mapY < -20){
    x='Q';// Q=F+L
   }
   if (mapX<-20 && mapY < -20){
    x='Z';// Z=B+L
   }
   if (mapX< -20 && mapY>20){
    x='M';// M=B+R
   }

   

   //Forward,Backward,Right & Left motion 
   if (mapX > 20 && abs(mapY)<20)
        {
            x='F';//Forward
        }
   else if (mapX < -20 && abs(mapY)<20)
        {   
            x='B';//Backward
        }
   else if (mapY > 20 && abs(mapX)<20)
        {
            x='R';//Right
        }
    else if (mapY < -20 && abs(mapX)<20)
        {
            x='L';//Left
        }
        
    
    
    else if ((abs(mapX)<20 && abs(mapY)<20 && abs(RmapX) < 20 && abs(AmapY)<20) && (grip_state==HIGH && load_state==HIGH && idk_state==HIGH))
            {
               x='H';//Halt
            }

     Serial.write(x);
     Serial.println("");
   }

    
  
    if (grip_state==LOW && x!= 'K'){
      Serial.write('K');
      Serial.println("");
      delay(500);
    }
    else if (load_state==LOW && x!= 'V'){
      Serial.write('V');
      Serial.println("");
      delay(500);
    }
    else if (idk_state==LOW && x!= 'I'){
      Serial.write('I');
      Serial.println("");
      delay(500);
    }

    

    
    if ((pot_value<300 && pot_value>0)&& (grip_state==HIGH && load_state==HIGH && idk_state==HIGH)){
      Serial.write('N');
      Serial.println("");
      delay(1000);
    }
    else if((pot_value>700 && pot_value<1023)&& (grip_state==HIGH && load_state==HIGH && idk_state==HIGH)){
      Serial.write('Y');
      Serial.println("");
      delay(1000);
    }
}





        
   
   
    
