# readline.ino yu arduinoya yükledikten sonra çalıştırın.
import serial

port = serial.Serial('com6',9600,timeout = 2)

print(f"port ismi : {port.name}")
print(f"portun aktiflik durumu: {port.isOpen()}")

for i in range(0,4):
    coming = port.readline() 
    coming = str(coming,'utf-8') # Veri byte olarak geldiği için str e dönüştürüyoruz.
    print(coming)
