#include <Servo.h>
 
Servo myservo;  
 
int pos = 90;    
 
void setup() {
        Serial.begin(9600); 
        myservo.attach(3); 
}
 
void loop() {
 
        
        while (Serial.available() > 0) {
                // gelen byte ı oku
                int c = Serial.read();
                delay(2); 
              
               
            //    Serial.print("C is ");
            //    Serial.println(c, DEC);
                myservo.write(c);
        }
}
