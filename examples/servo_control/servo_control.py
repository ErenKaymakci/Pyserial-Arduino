
import serial
arduinoData = serial.Serial('com6',9600)

def spin():
    derece = input("0 ile 180 arasinda derece giriniz:")
   
    if 0 <= int(derece) <=180:
        arduinoData.write(derece.encode())
        #print(derece) 
        
    else:
        return


while(1):
    spin()
