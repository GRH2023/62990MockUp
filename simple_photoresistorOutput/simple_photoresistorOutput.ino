/*
* Todo list:
* - Set alarm always ON at certain threshold, toggle off manually
* - Take average of input lightlevel?
* - Cancel run, and input new threshold?
* - Test with stronger lighting conditions
* - Test suite? invalid input on threshold, averaging lightlevel, threshold trigger, ????
*/

const int photoresistorPin = PC0;  // adc0 input pin for photoresistor
const int pwmPin = PD7;             // pwm7 output pin for led
int threshold;        //

//prototypes:
void setup();
void readThreshold();


void loop() {
  int lightLevel = analogRead(photoresistorPin);
  Serial.println(lightLevel); // debug reading

  if (lightLevel < threshold) {
    digitalWrite(pwmPin, HIGH); //on
  } else {
    digitalWrite(pwmPin, LOW);  //off
  }

  delay(500); 
}












// functions:

void setup() {
  pinMode(pwmPin, OUTPUT);
  Serial.begin(9600); // Optional: for debugging
  readThreshold();
}

void readThreshold() {
  Serial.println("\nInput threshold value: \n");
  while (Serial.available() == 0) {
    //while !userInput
  }
  threshold = Serial.parseInt(); //set threshold as input
  Serial.print("Threshold set to: "); Serial.println(threshold);
  delay(1000);

}
