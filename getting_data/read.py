import serial

port = serial.Serial('com6',9600,timeout=2)


print(f"port ismi : {port.name}")
print(f"portun aktiflik durumu: {port.isOpen()}")

coming = port.read(10)
coming = str(coming,'utf-8')

print(coming)