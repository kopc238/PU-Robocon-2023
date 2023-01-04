//reciever end of zigbee
// arduino mega 

#include <SoftwareSerial.h>
char x;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() {

  
  x=Serial.read();

  //Serial.println(x);
  
  if (x=='a'){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                      
  }
  if (x=='b'){
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);         
  }

}
