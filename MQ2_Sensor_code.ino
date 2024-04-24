///////////Declarations/////////////

// The actuator pin decleration
int fanin = 13;
// The Sensor pin decleration
int smokeA5 = A5;
// Your threshold value
int sensorThres = 8.00;

///////////Declarations/////////////

void setup() {
  
// pin type is either input or output
  pinMode(fanin, OUTPUT);
  pinMode(smokeA5, INPUT);

// Rate of exchanging data from sensor and seril monitor is 9600 bits   
  Serial.begin(9600);

// Declaring function of sensor on serial monitor
  Serial.print("CO concentration Mesurment:\n\n");

// Delay acessing the sensor to decrease pressure
  delay(500);
}



void loop() {

///////////Callibration of MQ-2 sensor to convert its reading to CO values/////////////

//Inserting the sensors readings to a variable
  int analogSensor = analogRead(smokeA5);
  
//Determining clean air as an MQ-2 reading
  int cleanAirBaseline = 125;

//CO PPM at cleanairbaseline value  
  float coPpm = 2.5; 

// Calculate an offset from baseline (assuming higher sensor value indicates higher gas concentration)
  float sensorOffset = analogSensor - cleanAirBaseline;

// You'd need to implement a conversion based on your reference data (Data is obtained from a refrence curve for toxic gases in the MQ-2 datasheet)
  if (sensorOffset > 0) {
  coPpm = sensorOffset * 0.02;}

///////////Callibration of MQ-2 sensor to convert its reading to CO values/////////////
  

//Declaring the threshold on serial monitor
  Serial.print("(CO Threshold: ");
  Serial.print(sensorThres);
  Serial.print(".00 PPM)");

//Declaring the Calculated CO value on serial monitor 
  Serial.print(" (Estimated CO: ");
  Serial.print(coPpm);
  Serial.println(" PPM)");

// Checks if it has reached the threshold value
  if (coPpm > sensorThres)
  {
    digitalWrite(fanin, HIGH);
  }
  else
  {
    digitalWrite(fanin, LOW);
  }

// Delay reaccessing the sensor to decrease pressure
  delay(100);
}

