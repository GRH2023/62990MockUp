/*void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  //adc0 is input from the photoresistor
  //if input from the photorestistor is below X, then pwm7 should be ON 
}
*/

//copilot:
const int photoresistorPin = PC0;  // adc0
const int pwmPin = PD7;             // pwm7
const int threshold = 500;        // Adjust this value based on your lighting conditions

void setup() {
  pinMode(pwmPin, OUTPUT);
  Serial.begin(9600); // Optional: for debugging
}

void loop() {

  setup();


  int lightLevel = analogRead(photoresistorPin);
  Serial.println(lightLevel); // Optional: to monitor light level

  if (lightLevel < threshold) {
    digitalWrite(pwmPin, HIGH); // Turn ON
  } else {
    digitalWrite(pwmPin, LOW);  // Turn OFF
  }

  delay(100); // Small delay to stabilize readings
}
