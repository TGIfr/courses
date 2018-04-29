//#include <DFPlayer_Mini_Mp3.h>
//
/////////////////////////////////////////////////////////////////////////////////////////
////THIS IS A DEMO SOFTWARE JUST FOR EXPERIMENT PURPOER IN A NONCOMERTIAL ACTIVITY
////Version: 1.0 (AUG, 2016)
//
////Gyro - Arduino UNO R3
////VCC  -  5V
////GND  -  GND
////SDA  -  A4
////SCL  -  A5
////INT - port-2
//
//#include <Servo.h>
//#include <Wire.h>
//
//Servo motor;
////Declaring some global variables
//int gyro_x, gyro_y, gyro_z;
//long gyro_x_cal, gyro_y_cal, gyro_z_cal;
//boolean set_gyro_angles;
//
//long acc_x, acc_y, acc_z, acc_total_vector;
//float angle_roll_acc, angle_pitch_acc;
//
//float angle_pitch, angle_roll;
//int angle_pitch_buffer, angle_roll_buffer;
//float angle_pitch_output, angle_roll_output;
//
//long loop_timer;
//int temp;
//
//Servo servo;
//int servoPin = 9;
//float servoAngle = 90;
//
//void setup() {
//  // put your setup code here, to run once:
//  motor.attach(3);
//  motor.writeMicroseconds(2200);
//  delay(2000);
//  motor.writeMicroseconds(800);
//  delay(6000);
//  Wire.begin();                                                      //Start I2C as master
//  setup_mpu_6050_registers();                                       //Setup the registers of the MPU-6050
//  for (int cal_int = 0; cal_int < 1000 ; cal_int ++){               //Read the raw acc and gyro data from the MPU-6050 for 1000 times
//  read_mpu_6050_data();                                          
//  gyro_x_cal += gyro_x;                                           //Add the gyro x offset to the gyro_x_cal variable
//  gyro_y_cal += gyro_y;                                           //Add the gyro y offset to the gyro_y_cal variable
//  gyro_z_cal += gyro_z;                                           //Add the gyro z offset to the gyro_z_cal variable
//  delay(3);                                                       //Delay 3us to have 250Hz for-loop
//  }
//
//  // divide by 1000 to get avarage offset
//  gyro_x_cal /= 1000;                                              
//  gyro_y_cal /= 1000;                                              
//  gyro_z_cal /= 1000;                                              
//  Serial.begin(115200);
//  loop_timer = micros();                                            //Reset the loop timer
//}
//
//void loop(){
//
//  read_mpu_6050_data();   
// //Subtract the offset values from the raw gyro values
//  gyro_x -= gyro_x_cal;                                              
//  gyro_y -= gyro_y_cal;                                              
//  gyro_z -= gyro_z_cal;                                              
//       
//  //Gyro angle calculations . Note 0.0000611 = 1 / (250Hz x 65.5)
//  angle_pitch += gyro_x * 0.0000611;                                //Calculate the traveled pitch angle and add this to the angle_pitch variable
//  angle_roll += gyro_y * 0.0000611;                                 //Calculate the traveled roll angle and add this to the angle_roll variable
//  //0.000001066 = 0.0000611 * (3.142(PI) / 180degr) The Arduino sin function is in radians
//  angle_pitch += angle_roll * sin(gyro_z * 0.000001066);            //If the IMU has yawed transfer the roll angle to the pitch angel
//  angle_roll -= angle_pitch * sin(gyro_z * 0.000001066);            //If the IMU has yawed transfer the pitch angle to the roll angel
// 
//  //Accelerometer angle calculations
//  acc_total_vector = sqrt((acc_x*acc_x)+(acc_y*acc_y)+(acc_z*acc_z));  //Calculate the total accelerometer vector
//  //57.296 = 1 / (3.142 / 180) The Arduino asin function is in radians
//  angle_pitch_acc = asin((float)acc_y/acc_total_vector)* 57.296;    //Calculate the pitch angle
//  angle_roll_acc = asin((float)acc_x/acc_total_vector)* -57.296;    //Calculate the roll angle
// 
//  angle_pitch_acc -= 0.0;                                           //Accelerometer calibration value for pitch
//  angle_roll_acc -= 0.0;                                            //Accelerometer calibration value for roll
// 
//  const float histG = 0.9996;
//  const float newGValFactor = 1 - histG;
//  if(set_gyro_angles){                                              //If the IMU is already started
//  angle_pitch = angle_pitch * histG + angle_pitch_acc * newGValFactor;  //Correct the drift of the gyro pitch angle with the accelerometer pitch angle
//  angle_roll = angle_roll * histG + angle_roll_acc * newGValFactor;     //Correct the drift of the gyro roll angle with the accelerometer roll angle
//  }
//  else{                                                             //At first start
//  angle_pitch = angle_pitch_acc;                                  //Set the gyro pitch angle equal to the accelerometer pitch angle
//  angle_roll = angle_roll_acc;                                    //Set the gyro roll angle equal to the accelerometer roll angle
//  set_gyro_angles = true;                                         //Set the IMU started flag
//  }
//  const float hist = 0.30;
//  const float newValFactor = 1 - hist;
//  //To dampen the pitch and roll angles a complementary filter is used
//  angle_pitch_output = angle_pitch_output * hist + angle_pitch * newValFactor;   //Take 90% of the output pitch value and add 10% of the raw pitch value
//  angle_roll_output = angle_roll_output * hist + angle_roll * newValFactor;   //Take 90% of the output roll value and add 10% of the raw roll value
// 
// 
//  //int servoAngle = 90 + (int)angle_pitch_output;
//  if (fabs(angle_pitch_output - 2.5) > 1) {
//  const float newValueFactor = 0.999;
//  const float historyFactor = 1 - newValueFactor;
//  servoAngle = servoAngle * historyFactor
//    + (servoAngle + 1 * angle_pitch_output / 90) * newValueFactor;
//  }
//  //servoAngle = 90 + angle_pitch_output;
//  if (servoAngle < 0) {
//  servoAngle = 0;
//  }
//  if (servoAngle > 180) {
//  servoAngle = 180;
//  }
//  //servoAngle -= (int)angle_pitch_output * 0.01;
//  motor.writeMicroseconds(map((int)servoAngle, 0, 180, 800, 2200));
//
// while(micros() - loop_timer < 4000);                               //Wait until the loop_timer reaches 4000us (250Hz) before starting the next loop
// loop_timer = micros();//Reset the loop timer
// 
//}
//
//
//
//
//void setup_mpu_6050_registers(){
//  //Activate the MPU-6050
//  Wire.beginTransmission(0x68);                                     //Start communicating with the MPU-6050
//  Wire.write(0x6B);                                                 //Send the requested starting register
//  Wire.write(0x00);                                                 //Set the requested starting register
//  Wire.endTransmission();                                          
//  //Configure the accelerometer (+/-8g)
//  Wire.beginTransmission(0x68);                                     //Start communicating with the MPU-6050
//  Wire.write(0x1C);                                                 //Send the requested starting register
//  Wire.write(0x10);                                                 //Set the requested starting register
//  Wire.endTransmission();                                          
//  //Configure the gyro (500dps full scale)
//  Wire.beginTransmission(0x68);                                     //Start communicating with the MPU-6050
//  Wire.write(0x1B);                                                 //Send the requested starting register
//  Wire.write(0x08);                                                 //Set the requested starting register
//  Wire.endTransmission();                                          
//}
//
//
//void read_mpu_6050_data(){                                          //Subroutine for reading the raw gyro and accelerometer data
//  Wire.beginTransmission(0x68);                                     //Start communicating with the MPU-6050
//  Wire.write(0x3B);                                                 //Send the requested starting register
//  Wire.endTransmission();                                           //End the transmission
//  Wire.requestFrom(0x68,14);                                        //Request 14 bytes from the MPU-6050
//  while(Wire.available() < 14);                                     //Wait until all the bytes are received
//  acc_x = Wire.read()<<8|Wire.read();                                
//  acc_y = Wire.read()<<8|Wire.read();                                
//  acc_z = Wire.read()<<8|Wire.read();                                
//  temp = Wire.read()<<8|Wire.read();                                 
//  gyro_x = Wire.read()<<8|Wire.read();                               
//  gyro_y = Wire.read()<<8|Wire.read();                               
//  gyro_z = Wire.read()<<8|Wire.read();                               
//}
//
///*#include <Servo.h>
//
//Servo motor;
//
//void setup() {
//  // put your setup code here, to run once:
//  motor.attach(2);
//  motor.writeMicroseconds(2200);
//  delay(2000);
//  motor.writeMicroseconds(800);
//  delay(6000);
//}
//
//void loop() {
//  int slower = 100;
//  // put your main code here, to run repeatedly:
//  for(int i = 880*slower; i < 1500*slower; i++){
//    motor.writeMicroseconds(i/slower);
//    }
//    for(int i = 1500*slower; i > 880*slower; i--){
//    motor.writeMicroseconds(i/slower);
//    }
//    
//
//}*/
#include <Wire.h>  // for I2C communication

const int MPU_addr = 0x68;  // I2C address of the MPU-6050

int16_t AcX, AcY, AcZ;  // accelerometer
int16_t Tmp;            // temperature
int16_t GyX, GyY, GyZ;  // gyroscope

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  Serial.begin(9600);
}

void loop() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_addr, 14, true);  // request a total of 14 registers
  AcX = Wire.read() << 8 | Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)    
  AcY = Wire.read() << 8 | Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 8 | Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp = Wire.read() << 8 | Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX = Wire.read() << 8 | Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY = Wire.read() << 8 | Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ = Wire.read() << 8 | Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  Serial.print("AcX = "); Serial.print(AcX);
  Serial.print(" | AcY = "); Serial.print(AcY);
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  Serial.print(" | Tmp = "); Serial.print(Tmp / 340.00 + 36.53);  //equation for temperature in degrees C from datasheet
  Serial.print(" | GyX = "); Serial.print(GyX);
  Serial.print(" | GyY = "); Serial.print(GyY);
  Serial.print(" | GyZ = "); Serial.println(GyZ);

  delay(333);
}
