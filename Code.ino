#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 3
const int ledPin = 13;
const int ledPin2 = 10;
const int buzzerPin = 8;
const int buttonPin = 2;
bool active = false;
int buttonState = 0;
// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);	

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

void setup(void)
{
  sensors.begin();	// Start up the library
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  // initialize the pushbutton pin as an input:
  
}

void loop(void)
{ 
  if (active){
     // Send the command to get temperatures
  sensors.requestTemperatures(); 
  float a = sensors.getTempCByIndex(0);
  //print the temperature in Celsius
  Serial.print("Temperature: ");
  Serial.print(a);
  Serial.print((char)176);//shows degrees character
  Serial.print("C  |  ");
  
  //print the temperature in Fahrenheit
  Serial.print((a * 9.0) / 5.0 + 32.0);
  Serial.print((char)176);//shows degrees character
  Serial.println("F");
  
  if (a > 100 && active == true) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, 1000);
  } else if (a <= 100  ) {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }

    }
 

  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && active == false) {
    // turn LED on:
    Serial.print("on");
    active = true;
    digitalWrite(ledPin2, HIGH);
  } else if( buttonState == HIGH && active == true){
    // turn LED off:
   Serial.print("off");
   active = false;
   digitalWrite(ledPin2, LOW);
   noTone(buzzerPin);
   digitalWrite(ledPin, LOW);
  }
  delay(500);
  

}