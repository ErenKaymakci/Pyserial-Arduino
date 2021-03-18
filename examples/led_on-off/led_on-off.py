import serial

port = serial.Serial('com6',9600)

def led_on_off(x):
    port.write(x.to_bytes(1,'big'))


while(True):
    choice = input("Make your choice!(on/off/quit) ")

    if choice == 'on':
        led_on_off(1)
        
    elif choice =='off':
        led_on_off(0)
        
    elif choice == 'quit':
        break





    
