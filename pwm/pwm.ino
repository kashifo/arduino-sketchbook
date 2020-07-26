
const int ledPin = 2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  for(int i=0; i<1023; i+=50){
    analogWrite(ledPin, i);
    Serial.println(i);
    delay(50);
  }

  for(int i=1023; i>0; i-=50){
    analogWrite(ledPin, i);
    Serial.println(i);
    delay(50);
  }
  
}
