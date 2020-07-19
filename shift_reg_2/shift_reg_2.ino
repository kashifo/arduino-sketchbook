int dataPin = 5; //IC Pin 14 SER, 3rd from top
int latchPin = 4; //IC Pin 12 RCLK, 5th
int clockPin = 2; //IC Pin 11 SRCLK, 3rd from bottom

byte patterns[30] = {
B00000001, 100,
B00000010, 100,
B00000100, 100,
B00001000, 100,
B00010000, 100,
B00100000, 100,
B01000000, 100,
B10000000, 100,
B01000000, 100,
B00100000, 100,
B00010000, 100,
B00001000, 100,
B00000100, 100,
B00000010, 100
};
int count = sizeof(patterns) / 2;

void setup() {
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
}

void loop() {

digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin, MSBFIRST, patterns[ndex * 2]);
digitalWrite(latchPin, HIGH);
delay(patterns[(ndex * 2) + 1]);

ndex++;

if (ndex >= count){
  ndex = 0;
}
}
