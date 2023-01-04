
// Test code for zigbee
//from a array


int myArr[]={'A','C','F','B','R','L','H'};


void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
}



void loop() {
  for(int i=0;i<7;i++){
    Serial.println(myArr[i]);
    delay(500);
  }
}



/*
// Transmitter side of zigbee
// arduino uno 
#include <SoftwareSerial.h>

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  //  zigbee.begin(9600);
  //pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  Serial.println("a");
  delay(500);
  Serial.println("b");
  delay(500);

}
*/
