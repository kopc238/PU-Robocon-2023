//New mapping Program
//for postion and oreintation

int encoder_perimeter=150.72;//150.72=(pi*48) in mm

//Calculating the distance travelled and current postion of the robot
//Two roatary encoder program

//Rotary encoder 
//these pins can not be changed 2/3 are special pins
int encoderPinA_x = 2;
int encoderPinB_x = 3;
//these pins can not be changed 18/19 are special pins
int encoderPinA_y = 18;
int encoderPinB_y = 19;

volatile int lastEncoded_x = 0;
volatile long encoderValue_x = 0;
long lastencoderValue_x = 0;

volatile int lastEncoded_y = 0;
volatile long encoderValue_y = 0;
long lastencoderValue_y = 0;

int lastMSB_x = 0;
int lastLSB_x = 0;

int lastMSB_y = 0;
int lastLSB_y = 0;

//Current positions of the robot 
float x=0.0,y=0.0;

float angular_displacement_x;
float x_rotations;
float angular_displacement_y;
float y_rotations;

float x_displacement , y_displacement;


void setup() {
  
  Serial.begin (9600);

  pinMode(encoderPinA_x, INPUT); 
  pinMode(encoderPinB_x, INPUT);

  digitalWrite(encoderPinA_x, HIGH); //turn pullup resistor on
  digitalWrite(encoderPinB_x, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(0, updateEncoder_x, CHANGE); 
  attachInterrupt(1, updateEncoder_x, CHANGE);

  pinMode(encoderPinA_y, INPUT); 
  pinMode(encoderPinB_y, INPUT);

  digitalWrite(encoderPinA_y, HIGH); //turn pullup resistor on
  digitalWrite(encoderPinB_y, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 2 (pin 18), or interrupt 3 (pin 19) 
  attachInterrupt(2, updateEncoder_y, CHANGE); 
  attachInterrupt(3, updateEncoder_y, CHANGE);

  

}

void loop(){ 
  
  //for encoder one and relates to x- axis
  int rev_x = encoderValue_x / 2400;
  int parRev_x=encoderValue_x % 2400;

  float CRev_x=rev_x*150.72;
  float CparRev_x=(parRev_x*150.72)/2400;

  float total_x = CRev_x + CparRev_x;
  
  //for encoder two and relates to y- axis
  int rev_y = encoderValue_y / 2400;
  int parRev_y=encoderValue_y % 2400;

  float CRev_y=rev_y*150.72;
  float CparRev_y=(parRev_y*150.72)/2400;

  float total_y = CRev_y + CparRev_y;

  //Position
  x=total_x;
  y=total_y;

  Serial.print(x);
  Serial.print("  ");
  Serial.println(y);
  

  
  

  
  delay(200); //just here to slow down the output, and show it will work  even during a delay
}




void updateEncoder_x(){
  int MSB_x = digitalRead(encoderPinA_x); //MSB = most significant bit
  int LSB_x = digitalRead(encoderPinB_x); //LSB = least significant bit

  int encoded_x = (MSB_x << 1) |LSB_x; //converting the 2 pin value to single number
  int sum_x  = (lastEncoded_x << 2) | encoded_x; //adding it to the previous encoded value

  if(sum_x == 0b1101 || sum_x == 0b0100 || sum_x == 0b0010 || sum_x == 0b1011) encoderValue_x ++;
  if(sum_x == 0b1110 || sum_x == 0b0111 || sum_x == 0b0001 || sum_x == 0b1000) encoderValue_x --;

  lastEncoded_x = encoded_x; //store this value for next time
}


void updateEncoder_y(){
  int MSB_y = digitalRead(encoderPinA_y); //MSB = most significant bit
  int LSB_y = digitalRead(encoderPinB_y); //LSB = least significant bit

  int encoded_y = (MSB_y << 1) |LSB_y; //converting the 2 pin value to single number
  int sum_y  = (lastEncoded_y << 2) | encoded_y; //adding it to the previous encoded value

  if(sum_y == 0b1101 || sum_y == 0b0100 || sum_y == 0b0010 || sum_y == 0b1011) encoderValue_y ++;
  if(sum_y == 0b1110 || sum_y == 0b0111 || sum_y == 0b0001 || sum_y == 0b1000) encoderValue_y --;

  lastEncoded_y = encoded_y; //store this value for next time
}
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

  
  
