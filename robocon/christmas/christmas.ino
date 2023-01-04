//zigbee receving end Program after testing with joystick
//To program ER to move in all directions

//defining the pins for Motors(PWM)
#define M1pwm1 9
#define M1dir1 8
#define M2pwm2 11
#define M2dir2 10
#define M3pwm3 3
#define M3dir3 2
#define M4pwm4 5
#define M4dir4 4


//pins for joystick one 
int Vx1  = A0;
int Vy1 = A1;
//pins for joystick two
int Vx2  = A2;
int Vy2 = A3;
//variables for joystick
int x_pot1=0;
int y_pot1=0;
int x_pot2=0;
int mapX=0;
int mapY=0;
int pot_x1,pot_y1,pot_x2;

..

void Revolve(int v){
  if (v>0){
    analogWrite(M1pwm1,v);
    digitalWrite(M1dir1,LOW);
    analogWrite(M2pwm2,v);
    digitalWrite(M2dir2,LOW);
    analogWrite(M3pwm3,v);
    digitalWrite(M3dir3,LOW);
    analogWrite(M4pwm4,v);
    digitalWrite(M4dir4,LOW);
  }
  else{
    analogWrite(M1pwm1,v);
    digitalWrite(M1dir1,HIGH);
    analogWrite(M2pwm2,v);
    digitalWrite(M2dir2,HIGH);
    analogWrite(M3pwm3,v);
    digitalWrite(M3dir3,HIGH);
    analogWrite(M4pwm4,v);
    digitalWrite(M4dir4,HIGH);
  }
  
}

void Vertical(int v){ 
  if (v>=0){
    analogWrite(M1pwm1,v);
    digitalWrite(M1pwm1,LOW);
    analogWrite(M2pwm2,v);
    digitalWrite(M2pwm2,LOW);
    analogWrite(M3pwm3,0);
    analogWrite(M4pwm4,0);
  }
  else{
    analogWrite(M1pwm1,v);
    digitalWrite(M1pwm1,HIGH);
    analogWrite(M2pwm2,v);
    digitalWrite(M2pwm2,HIGH);
    analogWrite(M3pwm3,0);
    analogWrite(M4pwm4,0);
  }
  
}

void Horizontal(int v){
  if (v>=0){
    analogWrite(M3pwm3,v);
    digitalWrite(M3pwm3,LOW);
    analogWrite(M4pwm4,v);
    digitalWrite(M4pwm4,LOW);
    analogWrite(M1pwm1,0);
    analogWrite(M2pwm2,0);
  }
  else{
    analogWrite(M3pwm3,v);
    digitalWrite(M3pwm3,HIGH);
    analogWrite(M4pwm4,v);
    digitalWrite(M4pwm4,HIGH);
    analogWrite(M1pwm1,0);
    analogWrite(M2pwm2,0);
  }
}
void Plane(int vx,int vy){

  //Stops Everything
  if (vx==0 && vy==0){
    analogWrite(M1pwm1,0);
    analogWrite(M2pwm2,0);
    analogWrite(M3pwm3,0);
    analogWrite(M4pwm4,0);

  }

 
  //Comprises Veritcal Motion
  if (vx==0 && vy!=0){
    if (vy>0){
    analogWrite(M1pwm1,vy);
    digitalWrite(M1pwm1,LOW);
    analogWrite(M2pwm2,vy);
    digitalWrite(M2pwm2,LOW);
    analogWrite(M3pwm3,0);
    analogWrite(M4pwm4,0);
  }
  else if (vy<0){
    analogWrite(M1pwm1,vy);
    digitalWrite(M1pwm1,HIGH);
    analogWrite(M2pwm2,vy);
    digitalWrite(M2pwm2,HIGH);
    analogWrite(M3pwm3,0);
    analogWrite(M4pwm4,0);
  }
  }


  //Comprises Horizontal Motion
  if (vy==0 && vx!=0){
    if (vx>0){
    analogWrite(M3pwm3,vx);
    digitalWrite(M3pwm3,LOW);
    analogWrite(M4pwm4,vx);
    digitalWrite(M4pwm4,LOW);
    analogWrite(M1pwm1,0);
    analogWrite(M2pwm2,0);
  }
  else if (vx<0){
    analogWrite(M3pwm3,vx);
    digitalWrite(M3pwm3,HIGH);
    analogWrite(M4pwm4,vx);
    digitalWrite(M4pwm4,HIGH);
    analogWrite(M1pwm1,0);
    analogWrite(M2pwm2,0);
  }
  }
  
  //Comprises Diagonal Motion
  if (vx>0 && vy>0){
    //for y-axis
    analogWrite(M1pwm1,vy);
    digitalWrite(M1pwm1,LOW);
    analogWrite(M2pwm2,vy);
    digitalWrite(M2pwm2,LOW);
    //for x-axis
    analogWrite(M3pwm3,vx);
    digitalWrite(M3pwm3,LOW);
    analogWrite(M4pwm4,vx);
    digitalWrite(M4pwm4,LOW);
  }
  else if(vx<0 && vy>0){
    //for x axis
    analogWrite(M3pwm3,vx);
    digitalWrite(M3pwm3,HIGH);
    analogWrite(M4pwm4,vx);
    digitalWrite(M4pwm4,HIGH);
    //for y-axis
    analogWrite(M1pwm1,vy);
    digitalWrite(M1pwm1,LOW);
    analogWrite(M2pwm2,vy);
    digitalWrite(M2pwm2,LOW);
  }
  else if (vx<0 && vy<0){
    //for x axis
    analogWrite(M3pwm3,vx);
    digitalWrite(M3pwm3,HIGH);
    analogWrite(M4pwm4,vx);
    digitalWrite(M4pwm4,HIGH);
    //for y axis
    analogWrite(M1pwm1,vy);
    digitalWrite(M1pwm1,HIGH);
    analogWrite(M2pwm2,vy);
    digitalWrite(M2pwm2,HIGH);
  }
  else if(vx>0 && vy<0){
    //for x axis
    analogWrite(M3pwm3,vx);
    digitalWrite(M3pwm3,LOW);
    analogWrite(M4pwm4,vx);
    digitalWrite(M4pwm4,LOW);
    // for y axis
    analogWrite(M1pwm1,vy);
    digitalWrite(M1pwm1,HIGH);
    analogWrite(M2pwm2,vy);
    digitalWrite(M2pwm2,HIGH);
  }
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 


//intializing input pins for joystick
pinMode(Vx1, INPUT);
pinMode(Vy1, INPUT);
pinMode(Vx2, INPUT);
pinMode(Vy2,INPUT);

//setting the pin output for motors
pinMode(M1pwm1,OUTPUT);
pinMode(M1dir1,OUTPUT);
pinMode(M2pwm2,OUTPUT);
pinMode(M2dir2,OUTPUT);
pinMode(M3pwm3,OUTPUT);
pinMode(M3dir3,OUTPUT);
pinMode(M4pwm4,OUTPUT);
pinMode(M1pwm1,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Forward and backward
Vertical(127);
delay(1000);
Vertical(-127);
delay(1000);

// Left and Right
Horizontal(127);
delay(1000);
Horizontal(-127);
delay(1000);

//Revolving on its own axis
Revolve(127);
delay(1000);
Revolve(-127);
delay(1000);

}

/*

analogWrite(M1pwm1,127);
digitalWrite(M1dir1,LOW);
delay(1000);
analogWrite(M1pwm1,127);
digitalWrite(M1dir1,HIGH);
delay(1000);
analogWrite(M1pwm1,0);
delay(1000);


analogWrite(M2pwm2,127);
digitalWrite(M2dir2,LOW);
delay(1000);
analogWrite(M2pwm2,127);
digitalWrite(M2dir2,HIGH);
delay(1000);
analogWrite(M2pwm2,0);
delay(1000);


analogWrite(M3pwm3,127);
digitalWrite(M3dir3,LOW);
delay(1000);
analogWrite(M3pwm3,127);
digitalWrite(M3dir3,HIGH);
delay(1000);
analogWrite(M3pwm3,0);
delay(1000);


analogWrite(M4pwm4,127);
digitalWrite(M4dir4,LOW);
delay(1000);
analogWrite(M4pwm4,127);
digitalWrite(M4dir4,HIGH);
delay(1000);
analogWrite(M4pwm4,0);
delay(1000);

*/

/*
x_pot1 = analogRead(Vx1);
y_pot1= analogRead(Vy1);
x_pot1 = map(x_pot1, 0, 1023, -512, 512);
y_pot1= map(y_pot1, 0, 1023, -512, 512);
x_pot2=map(x_pot2,0,1023,-512,512);

if (x_pot1>0 && y_pot1==0){
  moveRight(x_pot1);
}

if (x_pot1>0 && y_pot1>0){
  moveForward(y_pot1);
  moveRight(x_pot1);
}

if (y_pot1>0 && x_pot1==0){
  moveForward(y_pot1);
}

if (x_pot1<0 && y_pot1>0){
  moveLeft(x_pot1);
  moveForward(y_pot1);
}

if (x_pot1<0 && y_pot1==0){
  moveLeft(x_pot1);
}

if (x_pot1<0 && y_pot1<0){
  moveLeft(x_pot1);
  moveBack(y_pot1);
}

if (y_pot1<0 && x_pot1==0){
  moveBack(y_pot1);
}

if (x_pot1>0 && y_pot1<0){
  moveBack(y_pot1);
  moveRight(x_pot1);
}

if (x_pot2>0){
  rotate_clock(x_pot1);
}
if (x_pot2<0){
  rotate_C_clock(x_pot1);
}
*/

/*
// Forward and backward
Vertical(127);
delay(1000);
Vertical(-127);
delay(1000);

// Left and Right
Horizontal(127);
delay(1000);
Horizontal(-127);
delay(1000);

//Revolving on its own axis
Revolve(127);
delay(1000);
Revolve(-127);
delay(1000);

//Diagonal 
Diagonal(127,64);
delay(1000);
Diagonal(-127,-64);
delay(1000);
Diagonal(-127,64);
delay(1000);
Diagonal(127,-64);
delay(1000);
*/

/*
void Vertical(int v){ 
  if (v>=0){
    analogWrite(M1pwm1,v);
    digitalWrite(M1pwm1,LOW);
    analogWrite(M2pwm2,v);
    digitalWrite(M2pwm2,LOW);
    analogWrite(M3pwm3,0);
    analogWrite(M4pwm4,0);
  }
  else{
    analogWrite(M1pwm1,v);
    digitalWrite(M1pwm1,HIGH);
    analogWrite(M2pwm2,v);
    digitalWrite(M2pwm2,HIGH);
    analogWrite(M3pwm3,0);
    analogWrite(M4pwm4,0);
  }
  
}

void Horizontal(int v){
  if (v>=0){
    analogWrite(M3pwm3,v);
    digitalWrite(M3pwm3,LOW);
    analogWrite(M4pwm4,v);
    digitalWrite(M4pwm4,LOW);
    analogWrite(M1pwm1,0);
    analogWrite(M2pwm2,0);
  }
  else{
    analogWrite(M3pwm3,v);
    digitalWrite(M3pwm3,HIGH);
    analogWrite(M4pwm4,v);
    digitalWrite(M4pwm4,HIGH);
    analogWrite(M1pwm1,0);
    analogWrite(M2pwm2,0);
  }
}








//for joystick one
x_pot1 = analogRead(Vx1);
y_pot1= analogRead(Vy1);
pot_x1 = map(x_pot1, 0, 1023, -255, 255);
pot_y1= map(y_pot1, 0, 1023, -255, 255);

//for joystick two 
x_pot2=analogRead(Vx2);
pot_x2=map(x_pot2,0,1023,-255,255);


Plane(pot_x1,pot_y1);
Revolve(pot_x2);

*/
