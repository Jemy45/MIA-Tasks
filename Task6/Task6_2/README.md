# Task6.2

# Define Pins

```cpp
# Rotary Encoder Interface with Arduino

This Arduino code interfaces with a rotary encoder to count the number of rotations.

## Pin Definitions

```cpp
// Define PINS of ENCODER connected to ARDUINO
#define PIN_ENCODER_A 2
#define PIN_ENCODER_B 3
```

Here, **`PIN_ENCODER_A`** and **`PIN_ENCODER_B`** are defined as the pins to which the rotary encoder is connected.

# Global Variables

```cpp
int counter = 0; // When i make it long long it gives me an error while simulating
int lastStateA;
```

- **`counter`**: This variable is used to keep track of the count of rotations.
- **`lastStateA`**: It stores the last state of pin A of the encoder.
- 

# ****Setup Function****

```cpp
void setup() {
    Serial.begin(9600);  
    // Set encoder pins as inputs with pull-up resistors
    pinMode(PIN_ENCODER_A, INPUT_PULLUP);
    pinMode(PIN_ENCODER_B, INPUT_PULLUP);

    // Read the initial value of A
    lastStateA = digitalRead(PIN_ENCODER_A);

    // Call interrupt for Pin A
    attachInterrupt(digitalPinToInterrupt(PIN_ENCODER_A), updateEncoder, CHANGE);
}
```

The **`setup`** function initializes the Serial communication, sets the encoder pins as inputs with pull-up resistors, and attaches an interrupt to the pin A of the encoder. The interrupt is triggered on a change in the pin's state.

# Loop Function

```cpp
void loop() {
// No code in the loop function, as the counting is done in the interrupt service routine (ISR).
}
```

The **`loop`** function is empty because the counting logic is handled in the interrupt service routine.

# ****Interrupt Service Routine (updateEncoder)****

```cpp
void updateEncoder() {
    // Read the states for A & B
    int currentStateB = digitalRead(PIN_ENCODER_B);
    int currentStateA = digitalRead(PIN_ENCODER_A);

    // Check for a change in A and if it's in the HIGH state
    if (currentStateA != lastStateA && currentStateA == 1) {
        // Compare the values of A and B to determine the direction of rotation
        if (currentStateB != currentStateA) {
            // Rotary encoder is rotating clockwise, so increment the counter
            counter++;
        } else {
            // Encoder is rotating counterclockwise, so decrement the counter
            counter--;
        }
        // Print the updated count to the Serial monitor
        Serial.print(" Number of counts is: ");
        Serial.println(counter);
    }

    // Update the last state of A for the next loop iteration
    lastStateA = currentStateA;
}
```

- The **`updateEncoder`** function is an interrupt service routine that is called whenever there is a change in the state of pin A.
- It reads the current states of pins A and B of the encoder.
- It checks if there is a change in A and if it's in the HIGH state, indicating a valid encoder step.
- Depending on the state of B relative to A, it increments or decrements the **`counter`**.
- It prints the updated count to the Serial monitor.
- Finally, it updates **`lastStateA`** for the next loop iteration.

# LPF

It is implemented by matlab and it is a design of low-pass filter (LPF) and apply the LPF to the noisy signal.The code also plots both the noisy and filtered signals in both the time and frequency domains.

cutoff frequency (fc) If WALL-E has Specs:
o Encoder has 540 pulse per revolution
o Track has three wheels only one motorized, with 40cm diameter,
(The one that has encoder)
o And Maximum speed of WALL-E 0.5 m/s

Fc=((Speed x Pulse per Revolution) / (2 * Pi * radius)) * 75% = 80Hz