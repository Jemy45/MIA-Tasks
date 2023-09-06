#include <Wire.h>

const int Pin1 = 2; //Define the pins of Push buttons
const int Pin2 = 3; 

void setup() {
  Wire.begin();//Define the sender arduino as master
  pinMode(Pin1, INPUT_PULLUP); //Declare them as input
  pinMode(Pin2, INPUT_PULLUP);
}

void loop() {
  int State1 = digitalRead(Pin1);//Reading thier states
  int State2 = digitalRead(Pin2);

  Wire.beginTransmission(4); //Define the adress of slaves
  Wire.write(State1);
  Wire.write(State2);
  Wire.endTransmission();
  delay(1000);
}
