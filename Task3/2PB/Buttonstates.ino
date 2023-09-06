#include <Wire.h>

const int ledPin = 9;//Define LED pin in receiving arduino
void setup() {
  Wire.begin(4); 
  Wire.onReceive(receiveData);//Using onReceive for receving data from changed data from BP to slave arduino
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
}

void receiveData(int howmany) {
  int State1 = Wire.read();
  int State2 = Wire.read();
  int ledIntensity = 0;
  String message = "";
//Checking the states of BP
  if (State1 == 1 && State2 == 1) {
    ledIntensity = 0;//0 Is output ratio of LOW
    
  } else if (State1 == 0 && State2 == 1) {
    ledIntensity = 127;//50% of 255
    message = "Vector focused";
  } else if (State1 == 1 && State2 == 0) {
    ledIntensity = 191;//75% of 255
    message = "Vector distracted";
  } else if (State1 == 0 && State2 == 0) {
    ledIntensity = 255;// 255 is output ratio of HIGH 
    message = "Glitch";
  }

  analogWrite(ledPin, ledIntensity);
  Serial.println(message);
  delay(1000);
}
