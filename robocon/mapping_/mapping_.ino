//Program for Elephant Robot to stay in its assigned area itself.
//and to continuosly caluculate the position,distance travelled and velocity of the robot
//26/12/22


//After compiling if a logic error or Warning appears
//check https://stackoverflow.com/questions/36784851/warning-address-of-local-variable-angles-returned-wreturn-local-addr 


//***************************************************************************************//
//
//                                         MY-PINS
//
//***************************************************************************************//
#define pi 3.14

// FOR ROTARY ENCODER
//these pins can not be changed 2/3 are special pins 
int encoderPin1 = 2;
int encoderPin2 = 3;

//Starting postitions of my robot
//int x_position,y_position;



//***************************************************************************************//
//
//                                       MY-FUNCTIONS
//
//***************************************************************************************//


float get_current_position(int x_position,int y_postion,int x_distance,int y_distance){
  
  //You will get the distance travelled through findDistance function
  //Every postion is according to the origin of the game field
  
  float x_current=x_position+x_distance;
  float y_current=y_position+y_distance;

  x_position=x_current;
  y_position=y_current;
  
  float position_arr[]={x_position,y_position};

  return position_arr;
}


float findDistance (float x_rotations,float y_rotations,float encoder_perimeter/*150.72=(pi*48) in mm*/){
  
  //Function to calculate the x_distance & y_distance
  //theory 
  //distance=no.of rotation *(2*pi*r)
  
  float x_distance=x_rotations*encoder_perimeter;
  float y_distance=y_rotations*encoder_perimeter;

  float distance_travelled[]={x_distance,y_distance};

  return distance_travelled;  
}


int pole_distance(int pole_coordinates,int current_position){
  
  //Function to caluculate distance between poles and robot
  //Used for also decision whether to throw the ring or not 
  //as the pole distance is less it is perefect choice to aim

  //it will constantly working on the displacements of poles and robot

  int pole_distances[]={};//no.ofelements = no.of poles you define

  return pole_distances;
}

float cal_angles(float current_postion,int pole_coordinates[]){
  //used for Rotating the robot 
  //for automatic shooting ring 
  //commands the robot to adjust angle 

  float rotate;

  return rotate;
}

int Obstacle_avoidance(int No_traspassing_area[],int current_position){
  
  //caluculate the distance between the restricted area and robot
  //To avoid that direction to a certain limit so that it can throw rings near poles 
  //returns commands to robot to change the directions and velocities accordingly


  return 0;
}




//***************************************************************************************//
//
//                                 Global Variables
//
//***************************************************************************************//



//Used control the robot speed around restricted area
int No_traspassing_area[]={};//Contains the info of ER robot arena


//Also this pole_coordinates array is a jagged array like 
//int array [no_of_poles][coordinates=2]
//as each pole has x and y
int pole_coordinates[]={"type_1","type_2","type_3"};// Give correct coordinates for all poles
float pole_angles[]={"type_1","type_2","type_3"};//all angles

//-----------------------------------Rotary encoder -------------------------------------//


volatile int lastEncoded = 0;
volatile long encoderValue = 0;

long lastencoderValue = 0;

int lastMSB = 0;
int lastLSB = 0;

float angular_displacement;

float rotations;


//------------------------------------For my Robot---------------------------------------//
//Starting postitions of my robot
float x_position,y_position;
float x_distance,y_distance;
int robot_length,robot_width;
int x_velocity=0,y_velocity=0;

int encoder_wheel=48;//in mm
//int time;


//***************************************************************************************//
//
//                                    My-Setup-Function
//
//***************************************************************************************//

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);

  //-----------------------------------Rotary encoder -------------------------------------//
  pinMode(encoderPin1, INPUT); 
  pinMode(encoderPin2, INPUT);

  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on

  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);

  volatile long encodervalue;

}


//***************************************************************************************//
//
//                                     My-Loop-Function
//
//***************************************************************************************//

void loop() {
  // put your main code here, to run repeatedly:

  
  Serial.print("angular_displacement");
  Serial.print(angular_displacement);
  Serial.print("    ");
  Serial.print("encoderValue: ");
  Serial.print(encoderValue);
  Serial.print("    ");
  Serial.print("Rotations ");
  Serial.println(rotations);

}





void updateEncoder(){
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) encoderValue ++;
  if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) encoderValue --;

  lastEncoded = encoded; //store this value for next time
}
