int data;
int pin= 8;
void setup() {
  Serial.begin(9600);  
  pinMode(pin,OUTPUT);
}

void loop() {
  
  while (Serial.available() > 0){
    data = Serial.read();
    delay(2);
   
    if (data == 1){
      digitalWrite(pin,HIGH);  
    }
    else if(data == 0){
      digitalWrite(pin,LOW);
    }
  }
  

}
