# imudan yaw, pitch , roll açılarını terminalde yazdırma

import serial

port = serial.Serial('com6',115200)
port.reset_input_buffer()

while(True):

    while (port.inWaiting()==0): #Veri olmadığı sürece bu burada dönecek 
        pass
    try: 
        packet = port.readline()
        str_packet = str(packet,'utf-8')
    except: 
        continue # UnicodeDecodeError: 'utf-8' codec can't decode byte 0xfd in position 0: invalid start byte ( Bu hatayı önlemek için) 
    
    
    virgule = ','
    if virgule in str_packet: # veri paketi virgüllü geldiği için başta ki kalibrasyon çıktısı hata vermemesi için yaptık.

        split_packet = str_packet.split(',')
        
        x = float(split_packet[0])
        y = float(split_packet[1])
        z = float(split_packet[2][0:4])

        print(f"x: {x}  y : {y}   z : {z}")
        
    else:
        print(str_packet)
        
    
