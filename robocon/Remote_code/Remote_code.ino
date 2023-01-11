//Code for remote of Elephant Robot
//arduino uno



//for potentiometer one 
int VRx = A0;
int VRy = A1;
int SW_PIN_1=7;

//for potentiometer Two
int RVRx = A2;
int AVRy = A3;
int SW_PIN_2=8;


//Variables for poteniometer
int xPosition = 0;
int yPosition = 0;
int RxPosition = 0;
int AyPosition = 0;
int sw_rpm_1=0;
int sw_rpm_2=0;

//mapping variables
int mapX = 0;
int mapY = 0;
int RmapX = 0;
int AmapY = 0;

char x,check;


void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    pinMode(VRx, INPUT);
    pinMode(VRy, INPUT);
    pinMode(RVRx, INPUT);
    pinMode(AVRy, INPUT);
    pinMode(SW_PIN_1,INPUT_PULLUP);
    pinMode(SW_PIN_2,INPUT_PULLUP);
}




void loop() {
  // put your main code here, to run repeatedly:
    
    //Reading analog and digital values
    xPosition = analogRead(VRx);
    yPosition = analogRead(VRy);
    RxPosition = analogRead(RVRx);
    AyPosition = analogRead(AVRy);
    sw_rpm_1 = digitalRead(SW_PIN_1);
    sw_rpm_2 = digitalRead(SW_PIN_2);

    //mapping functions for analog values
    mapX = map(xPosition, 0, 1023, -255, 255);
    mapY = map(yPosition, 0, 1023, -255, 255);
    RmapX = map(RxPosition, 0, 1023, -255, 255); 
    AmapY = map(AyPosition, 0, 1023, -255, 255); 
    
   check=x;
   send_data();
   
   if (x!=check){
      Serial.write(x);
      Serial.println("");
   }
   
 delay(100);
}

void send_data(){
  
   //To Revolve robot in all clockwise and Anti-clockwise.
   if (AmapY < -20 && abs(RmapX) < 20)
        {
          x='A';//Anti-CW-rotation
        }
   else if (AmapY > 20 && abs(RmapX) < 20)
        {
          x='C';//CW-rotation
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
    else if ( abs(mapX)<20 && abs(mapY)<20 && abs(RmapX) < 20 && abs(AmapY)<20 )
            {
               x='H';//Halt
            }
     
}




        
   
   
    
