
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

long timer = 0;
int i = 0;
void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  Serial.print("\n");
}

void loop() {
  mpu6050.update();
  
  Serial.print(mpu6050.getAngleX());
  Serial.print(",");
  Serial.print(mpu6050.getAngleY());
  Serial.print(",");
  Serial.println(mpu6050.getAngleZ());
  //Serial.print("\tArduino count:");Serial.println(i);
 // i = i+1;
  
  /*
  for(int j=0;j<100;j++){
    Serial.println(mpu6050.getAngleZ());
    liste[j] = mpu6050.getAngleZ();
  }
  Serial.println("Dizi baslangici");
  for(int k =0;k<100;k++){
    Serial.println(liste[k]);
  }
  Serial.println("Dizi sonu");
  */
  
 // if(millis() - timer > 1000){
  //  Serial.print(mpu6050.getAngleZ());
  //  Serial.print("\tArduino count:");Serial.println(i);
  //  i = i+1;
    
  
  /*  
    Serial.println("=======================================================");
    Serial.print("temp : ");Serial.println(mpu6050.getTemp());
    Serial.print("accX : ");Serial.print(mpu6050.getAccX());
    Serial.print("\taccY : ");Serial.print(mpu6050.getAccY());
    Serial.print("\taccZ : ");Serial.println(mpu6050.getAccZ());
  
    Serial.print("gyroX : ");Serial.print(mpu6050.getGyroX());
    Serial.print("\tgyroY : ");Serial.print(mpu6050.getGyroY());
    Serial.print("\tgyroZ : ");Serial.println(mpu6050.getGyroZ());
  
    Serial.print("accAngleX : ");Serial.print(mpu6050.getAccAngleX());
    Serial.print("\taccAngleY : ");Serial.println(mpu6050.getAccAngleY());
  
    Serial.print("gyroAngleX : ");Serial.print(mpu6050.getGyroAngleX());
    Serial.print("\tgyroAngleY : ");Serial.print(mpu6050.getGyroAngleY());
    Serial.print("\tgyroAngleZ : ");Serial.println(mpu6050.getGyroAngleZ());
    */
    
    //Serial.print("angleX : ");Serial.print(mpu6050.getAngleX());
    //Serial.print("\tangleY : ");Serial.print(mpu6050.getAngleY());
    //Serial.println(mpu6050.getAngleZ());
    // Serial.println("=======================================================\n");
   // timer = millis();
    
  //}

}
