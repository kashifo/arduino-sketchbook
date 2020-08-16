const int analogInPin = A0;  // ESP8266 Analog Pin ADC0 = A0

int sensorValue = 0;  // value read from the pot
int outputValue = 0;  // value to output to a PWM pin
int led = 2;

void setup() {
  // initialize serial communication at 115200
  Serial.begin(115200);
  pinMode(led, OUTPUT);
}

void loop() {
  // read the analog in value
  sensorValue = analogRead(analogInPin);
  analogWrite(led, sensorValue);
  
  // map it to the range of the PWM out
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  
  // print the readings in the Serial Monitor
  Serial.print("sensor = ");
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  delay(1000);
}
