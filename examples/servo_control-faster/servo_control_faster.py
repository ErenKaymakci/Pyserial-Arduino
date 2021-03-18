import serial
import time
arduinoData = serial.Serial('com6',9600)


def spin():
    derece = int(input("0 ile 180 arasinda derece giriniz:"))
    
    if 0 <= derece <=180:
        
        arduinoData.write(derece.to_bytes(2,'big'))
        time.sleep(0.01)
        print(derece.to_bytes(2,'big')) 
        comes = arduinoData.readline()
        print(comes)
    else:
        return

while(1):
    spin()
