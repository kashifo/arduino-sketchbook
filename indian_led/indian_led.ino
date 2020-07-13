const int red = 9;
const int white = 10;
const int green = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(red, OUTPUT);
  pinMode(white, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(red, HIGH);
  digitalWrite(white, HIGH);
  digitalWrite(green, HIGH);
 }
