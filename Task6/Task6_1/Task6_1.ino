#include <Wire.h>

#define IMU_ADDRESS 0x68 // Define MPU6050 I2C addresses
#define PWR_MGMT_1 0x6B 

// MPU6050 register address
#define GYRO_ZOUT_H 0x47

#define GYRO_SENSITIVITY 0.03051757813 // Gyro sensitivity scale factor for +or-1000 degrees/sec, Sensitivity=2000/2^16.

int16_t gyroZ = 0; // Gyroscope Z-axis data
float yawAngle = 0; // Yaw  angle
unsigned long previousTime = 0; 

void setup() {
  Wire.begin();
  Serial.begin(9600);
  MPU6050_Init();
}

void loop() {
  unsigned long currentTime = millis();
  float elapsedTime = (currentTime - previousTime) / 1000.0; // Convert to seconds
  previousTime = currentTime;
  
  MPU6050_readGyro();
  yawAngle += gyroZ * GYRO_SENSITIVITY * elapsedTime ;
  Serial.print("Yaw Angle is  ");
  Serial.println(yawAngle);
  delay(100);
}

void MPU6050_Init() {
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(PWR_MGMT_1); 
  Wire.write(0x00);    
  Wire.endTransmission();
}

void MPU6050_readGyro() {
  Wire.beginTransmission(IMU_ADDRESS);
  Wire.write(GYRO_ZOUT_H);
  Wire.endTransmission();

  Wire.requestFrom(IMU_ADDRESS, 2);
  
  while(Wire.available()<2);
  gyroZ = Wire.read() << 8 | Wire.read();
}
