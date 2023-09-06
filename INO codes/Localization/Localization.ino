#include <NewPing.h>


const int triggerPin0 = 2; 
const int echoPin0 = 3;  
const int triggerPin90 = 4; 
const int echoPin90 = 5;              //Pins of 4 Sensors
const int triggerPin180 = 6; 
const int echoPin180 = 7; 
const int triggerPin270 = 8;
const int echoPin270 = 9;

const float chamberWidth = 5.0;  //Dimensions of chamber in m
const float chamberHeight = 6.0;  

// Create instances of NewPing for each sensor
NewPing sonar0(triggerPin0, echoPin0, 800);     // Echo pin, trigger pin, maximum distance in cm
NewPing sonar90(triggerPin90, echoPin90, 800);
NewPing sonar180(triggerPin180, echoPin180, 800);
NewPing sonar270(triggerPin270, echoPin270, 800);

void setup() {
  Serial.begin(9600);
}

void loop() {
      // Get distance measurements from the sensors
  float Left = sonar0.ping_cm() / 100.0;   // Convert cm to meters
  float Top = sonar90.ping_cm() / 100.0;
  float Right = sonar180.ping_cm() / 100.0;
  float Bottom = sonar270.ping_cm() / 100.0;

  float x = ((Left + chamberWidth - Right)) / 2;

  float y = ((Bottom + chamberHeight - Top)) / 2;

  // Check  coordinates that it is in chamber or not
  if (x < 0) x = 0;
  if (x > chamberWidth) x = chamberWidth;
  if (y < 0) y = 0;
  if (y > chamberHeight) y = chamberHeight;

  
  Serial.print("Postition of cookiee is (x, y): ");
  Serial.print(x);
  Serial.print(", ");
  Serial.print(y);

  delay(1000);  
