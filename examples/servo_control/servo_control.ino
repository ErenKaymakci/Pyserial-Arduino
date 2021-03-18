#include <Servo.h>

Servo motor;

int serialData;


void setup() {
  motor.attach(3);
  Serial.begin(9600);

}

void loop() {
  if(Serial.available() > 0){
    serialData = Serial.parseInt(); // Seri Porta gönderilen veri dizisi içerisindeki ondalıklı ve tam sayıları almamızı sağlar.
    motor.write(serialData); 
  }
  
  
  
  delay(500);
  
 
  
}
