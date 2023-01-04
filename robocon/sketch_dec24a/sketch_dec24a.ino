
#define motor1pin1 3
#define motor1dir1 4
#define motor2pin2 8
#define motor2dir2 9

/*
int motor1pin1=3;
int motor1dir1=4;
int motor2pin2=8;
int motor2dir2=9;
*/
void setup() {
  // put your setup code here, to run once:
pinMode(motor1pin1,OUTPUT);
pinMode(motor1dir1,OUTPUT);
pinMode(motor2pin2,OUTPUT);
pinMode(motor2dir2,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(motor1pin1,HIGH);
digitalWrite(motor1dir1,LOW);
delay(1000);
digitalWrite(motor2pin2,LOW);
digitalWrite(motor2dir2,HIGH);
delay(1000);

digitalWrite(motor1pin1,LOW);
digitalWrite(motor1dir1,LOW);
digitalWrite(motor2pin2,LOW);
digitalWrite(motor2dir2,LOW);
}
