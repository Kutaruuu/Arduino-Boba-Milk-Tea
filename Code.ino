

#include <Servo.h>


// Data wire is plugged into digital pin 2 on the Arduino
Servo servo1;

const int buttonPin = 2;



void setup()
{
 servo1.attach(9);
  //pinMode(ledPin, OUTPUT);
  //pinMode(ledPin2, OUTPUT);
  //pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  // initialize the pushbutton pin as an input:
  
}

void loop(void)
{ 
 
if(digitalRead(buttonPin)==HIGH)
{
  servo1.write(180);

}else{
  servo1.write(0);
}
  
  

}
