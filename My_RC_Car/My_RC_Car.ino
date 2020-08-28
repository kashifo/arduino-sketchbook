#define ENA   16          // Enable/speed motors Right        GPIO14(D0)
#define IN_1  5          // L298N in1 motors Right           GPIO15(D1)
#define IN_2  4          // L298N in2 motors Right           GPIO13(D2)
#define IN_3  0           // L298N in3 motors Left            GPIO2(D3)
#define IN_4  2           // L298N in4 motors Left            GPIO0(D4)
#define ENB   14          // Enable/speed motors Left         GPIO12(D5)

#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>

//String command;             //String to store app command state.
int speedCar = 800;         // 400 - 1023.
int speed_Coeff = 3;

const char* ssid = "My RC Car";
ESP8266WebServer server(8080);

void setup() {
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);  
    pinMode(IN_1, OUTPUT);
    pinMode(IN_2, OUTPUT);
    pinMode(IN_3, OUTPUT);
    pinMode(IN_4, OUTPUT); 
  
// Connecting WiFi
    IPAddress ip(192, 168, 4, 1);
    IPAddress netmask(255, 255, 255, 0);

    WiFi.mode(WIFI_AP);
    WiFi.softAPConfig(ip, ip, netmask);
    WiFi.softAP(ssid);

    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(myIP);
 
 // Starting WEB-server 
    server.on ( "/", HTTP_handleRoot );
    server.onNotFound ( HTTP_handleRoot );
    server.begin();
    Serial.begin(115200);    
}

void loop() {
    server.handleClient();
    
     String cmdMove = server.arg("move");
     String cmdAction = server.arg("action");
      
     if (cmdMove == "F") goAhead();
     else if (cmdMove == "B") goBack();
     else if (cmdMove == "L") goLeft();
     else if (cmdMove == "R") goRight();
     else if (cmdMove == "S") stopRobot();
}

void HTTP_handleRoot(void) {
  if( server.hasArg("move") ){
       Serial.println(server.arg("move"));
  }else if( server.hasArg("action") ){
       Serial.println(server.arg("action"));
  }
  server.send ( 200, "text/html", "" );
  delay(1);
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
