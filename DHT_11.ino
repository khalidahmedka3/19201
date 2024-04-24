// Declaring the DHT-11 libraries
#include "dht.h"

// Analog Pin sensor is connected to
#define dht_apin A0 
dht DHT;

///////////Declarations/////////////

// Your threshold value
int humiditythres = 50;
// The actuator1 pin decleration
int fanout = 12;
// The actuator1 pin decleration
int piezzo = 11;

///////////Declarations/////////////

void setup() {
  
// pin type is either input or output
  pinMode(piezzo, OUTPUT);
  pinMode(fanout, OUTPUT);

// Rate of exchanging data from sensor and seril monitor is 9600 bits
  Serial.begin(9600);

//Delay to let system boot
  delay(500);

// Declaring function of sensor on serial monitor
  Serial.println("Humidity & temperature Mesurment:\n\n");
  
//Wait before accessing Sensor
  delay(500);

}

void loop() {
  
//Start of Program
  DHT.read11(dht_apin);
  
//Declaring the threshold on serial monitor
  Serial.print("(Humidity Threshold = ");
  Serial.print(humiditythres);
  Serial.print("%) ");

//Declaring the Calculated humidity value on serial monitor 
  Serial.print("(Current humidity = ");
  Serial.print(DHT.humidity);
  Serial.println("%) ");

//Declaring the Calculated tempreture value on serial monitor 
  Serial.print("(temperature = ");
  Serial.print(DHT.temperature);
  Serial.println("C) ");

// Checks if it is above the threshold value
  if (DHT.humidity > humiditythres) 
  {
    digitalWrite(fanout, HIGH);
  } 
  else
  {
    digitalWrite(fanout, LOW);
  }

// Checks if it is below the threshold value
  if (DHT.humidity < humiditythres)
  {
  digitalWrite(piezzo, HIGH);
  }
  else
  {
  digitalWrite(piezzo, LOW);
  }
  
//Wait 5 seconds before accessing sensor again.
  delay(100);
}
