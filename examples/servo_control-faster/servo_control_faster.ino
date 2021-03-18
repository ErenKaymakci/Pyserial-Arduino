#include <Servo.h>
 
Servo myservo;  // create servo object to control a servo
 
int pos = 90;    // variable to store the servo position
 
void setup() {
        Serial.begin(9600); 
        myservo.attach(3); //Servo connected to D9
}
 
void loop() {
 
        // send data only when you receive data:
        while (Serial.available() > 0) {
                // read the incoming byte:
                int c = Serial.read();
                delay(2); 
              
                // say what you got:
                Serial.print("C is ");
                Serial.println(c, DEC);
                myservo.write(c);
        }
}
