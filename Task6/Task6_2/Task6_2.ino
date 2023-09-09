
//Define PINS of ENCODER connected to ARDUINO
#define PIN_ENCODER_A 2
#define PIN_ENCODER_B 3

int counter = 0; //When i make it long long it give me error while simulating 

int lastStateA;


void setup() {
    Serial.begin(9600);  
	// Set encoder pins as inputs
	pinMode(PIN_ENCODER_A,INPUT_PULLUP);
	pinMode(PIN_ENCODER_B,INPUT_PULLUP);

  // Read initial value of A
  lastStateA = digitalRead(PIN_ENCODER_A);

  //Call interupt for Pin A
  attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_A), updateEncoder, CHANGE);

}

void loop() {
// When i try to print in void loop it prints for me always 0 so i printed in ISR
	}
  void updateEncoder(){
    // Read the states for A & B
   int currentStateB=digitalRead(PIN_ENCODER_B) ;   
	 int currentStateA = digitalRead(PIN_ENCODER_A);

// Check value changing of A also check if it 1 or not
	if (currentStateA != lastStateA && currentStateA == 1){
    // Compare between value of A and B , according its value we know it rotates CW or CCW
		if ( currentStateB != currentStateA) {
   // rotaryEncoder is rotating CW so increment      
			counter ++;
			
		}
     else {
			// Encoder is rotating CCW so decrement
			counter --;
	
		}
    Serial.print(" Number of counts is : ");
		Serial.println(counter);
  }               
             
lastStateA = currentStateA;   /*our current state is lastState in next loop 
*************EXAMPLE*********************************
   
         LastState        newCurrentState                         
          ________          ________         
 A       |        |        |        |
 ________|        |________|        |________       
                 CurrentState
                      ||
                      \/
                  LastState
                
 *****************************************************/     
	
}