# Task6.1

# MPU6050 Interface with Arduino

```cpp
# MPU6050 Gyroscope Interface with Arduino

This Arduino code interfaces with an MPU6050 gyro sensor to measure the yaw angle and displays it on the Serial monitor.

## Pin and Constants Definitions

#include <Wire.h>

#define IMU_ADDRESS 0x68 // Define MPU6050 I2C address
#define PWR_MGMT_1 0x6B

// MPU6050 register address
#define GYRO_ZOUT_H 0x47

#define GYRO_SENSITIVITY 0.03051757813 // Gyro sensitivity scale factor for ±1000 degrees/sec, Sensitivity = 2000 / 2^16.
```

- **`IMU_ADDRESS`**: The I2C address of the MPU6050 sensor.
- **`PWR_MGMT_1`**: The register address used for power management.
- **`GYRO_ZOUT_H`**: The register address for reading the gyro's Z-axis data.
- **`GYRO_SENSITIVITY`**: The sensitivity factor to convert raw data to degrees per second.

# ****Global Variables****

```cpp
int16_t gyroZ = 0;      // Gyroscope Z-axis data
float yawAngle = 0;     // Yaw angle
unsigned long previousTime = 0;
```

- **`gyroZ`**: Stores the raw gyroscope data for the Z-axis.
- **`yawAngle`**: Keeps track of the yaw angle.
- **`previousTime`**: Stores the previous time to calculate time intervals.
- 

# ****Setup Function****

```cpp
void setup() {
  Wire.begin();
  Serial.begin(9600);
  MPU6050_Init();
}
```

- Initializes the Wire library for I2C communication.
- Initializes Serial communication with a baud rate of 9600.
- Calls **`MPU6050_Init()`** to initialize the MPU6050 sensor.

# ****Loop Function****

```cpp
void loop() {
  unsigned long currentTime = millis();
  float elapsedTime = (currentTime - previousTime) / 1000.0; // Convert to seconds
  previousTime = currentTime;
  
  MPU6050_readGyro();
  yawAngle += gyroZ * GYRO_SENSITIVITY * elapsedTime;
  Serial.print("Yaw Angle is  ");
  Serial.println(yawAngle);
  delay(100);
}
```

- Measures the elapsed time since the last loop iteration.
- Calls **`MPU6050_readGyro()`** to read the gyro Z-axis data.
- Calculates the yaw angle by integrating the gyro data.
- Prints the yaw angle to the Serial monitor.
- Adds a delay of 100 milliseconds for smoother output.

# ****MPU6050_Init Function****

```cpp
void MPU6050_Init() {
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(PWR_MGMT_1);
  Wire.write(0x00);    
  Wire.endTransmission();
}
```

Initializes the MPU6050 sensor by sending the appropriate configuration data to the **`PWR_MGMT_1`** register.

# ****MPU6050_readGyro Function****

```cpp
void MPU6050_readGyro() {
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(GYRO_ZOUT_H);
  Wire.endTransmission();

  Wire.requestFrom(IMU_ADDRESS, 2);
  
  while(Wire.available() < 2);
  gyroZ = Wire.read() << 8 | Wire.read();
}
```

- Reads the gyro's Z-axis data from the MPU6050 sensor.
- Requests 2 bytes of data from the **`GYRO_ZOUT_H`** register.
- Combines the two bytes to obtain the raw gyro Z-axis data.

# Q:

If the Sensor is surrounded by a noisy environment, what type of
filter could used and what is the recommended cutoff frequency
depending on the sensor datasheet?

# Ans:

 Digital Low Pass Filter (DLPF) and Fc=1KHz