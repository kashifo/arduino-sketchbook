#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define ENA   16          // Enable/speed motors Right        GPIO14(D0)
#define IN_1  5          // L298N in1 motors Right           GPIO15(D1)
#define IN_2  4          // L298N in2 motors Right           GPIO13(D2)
#define IN_3  0           // L298N in3 motors Left            GPIO2(D3)
#define IN_4  2           // L298N in4 motors Left            GPIO0(D4)
#define ENB   14          // Enable/speed motors Left         GPIO12(D5)
#define HORN  12

int speedCar = 800;
ESP8266WebServer server(8080);

void setup() {
    WiFi.mode(WIFI_AP);
    IPAddress ip(192, 168, 4, 1);
    IPAddress netmask(255, 255, 255, 0);
    WiFi.softAPConfig(ip, ip, netmask);
    WiFi.softAP("My RC Mod");
  
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);  
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT);
    pinMode(HORN, OUTPUT); 

    server.on("/move", HTTP_GET, handleMoveRequest);
    server.on("/action", HTTP_GET, handleActionRequest);
    server.onNotFound(handleNotFound);
    server.begin();
    Serial.begin(115200);
}

void loop() {
  server.handleClient();
}

void handleMoveRequest() {
  if (!server.hasArg("dir")) {
    server.send(404, "text / plain", "Move: undefined");
    return;
  }
  
  String direction = server.arg("dir");
  Serial.println("handleMoveRequest dir="+direction );
  
  if (direction.equals("F")) {
    goAhead();
    server.send(200, "text / plain", "Move: forward");
  }
  else if (direction.equals("B")) {
    goBack();
    server.send(200, "text / plain", "Move: backward");
  }
  else  if (direction.equals("S")) {
    stopRobot();
    server.send(200, "text / plain", "Move: stop");
  }
  else  if (direction.equals("L")) {
    goLeft();
    server.send(200, "text / plain", "Turn: Left");
  }
  else  if (direction.equals("R")) {
    goRight();
    server.send(200, "text / plain", "Turn: Right");
  }
  else {
    server.send(404, "text / plain", "Move: undefined");
  }
}

void horn1(){
   Serial.println("horn1");
   
      digitalWrite(HORN, HIGH);
      delay(150);
      digitalWrite(HORN, LOW);
      delay(150);
      digitalWrite(HORN, HIGH);
      delay(300);
      digitalWrite(HORN, LOW);
}

void horn2(){
  Serial.println("horn2");
  
      digitalWrite(HORN, HIGH);
      delay(50);
      digitalWrite(HORN, LOW);
      delay(100);

      digitalWrite(HORN, HIGH);
      delay(50);
      digitalWrite(HORN, LOW);
      delay(100);


      digitalWrite(HORN, HIGH);
      delay(50);
      digitalWrite(HORN, LOW);
      delay(50);

      digitalWrite(HORN, HIGH);
      delay(50);
      digitalWrite(HORN, LOW);
      delay(50);


      digitalWrite(HORN, HIGH);
      delay(50);
      digitalWrite(HORN, LOW);
      delay(100);
      
      digitalWrite(HORN, HIGH);
      delay(100);
      digitalWrite(HORN, LOW);
      delay(100);

      digitalWrite(HORN, HIGH);
      delay(50);
      digitalWrite(HORN, LOW);
      delay(100);
}

void handleActionRequest() {
  if (!server.hasArg("type")) {
    server.send(404, "text / plain", "Action: undefined");
    return;
  }
  
  String type = server.arg("type");
  Serial.println("handleActionRequest type="+type );
  
  if (type.equals("1")) {
      horn1();
      type="";
      server.send(200, "text / plain", "Action 1");
  }
  else if (type.equals("2")) {
      horn2();
      type="";
      server.send(200, "text / plain", "Action 2");
  }
  else {
    server.send(404, "text / plain", "Action: undefined");
  }
}

void handleNotFound() {
  server.send(404, "text / plain", "404: Not found");
}


void goAhead(){
  Serial.println("goAhead");
   
     digitalWrite(IN_1, HIGH);
     digitalWrite(IN_2, LOW);
     analogWrite(ENA, speedCar);

     digitalWrite(IN_3, HIGH);
     digitalWrite(IN_4, LOW);
     analogWrite(ENB, speedCar);
}

void goBack(){
  Serial.println("goBack");
   
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
}

void goRight(){
  Serial.println("goRight");
   
      digitalWrite(IN_1, HIGH);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, HIGH);
      analogWrite(ENB, speedCar);
}

void goLeft(){
  Serial.println("goLeft");
  
      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, HIGH);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, HIGH);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
}

void stopRobot(){  
  Serial.println("stopRobot");

      digitalWrite(IN_1, LOW);
      digitalWrite(IN_2, LOW);
      analogWrite(ENA, speedCar);

      digitalWrite(IN_3, LOW);
      digitalWrite(IN_4, LOW);
      analogWrite(ENB, speedCar);
 }
