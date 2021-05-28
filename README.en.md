# Python Arduino Serial Communication
[![en](https://img.shields.io/badge/lang-en-red.svg)](https://github.com/ErenKaymakci/Pyserial-Arduino/blob/main/README.en.md)
[![tr](https://img.shields.io/badge/lang-tr-green.svg)](https://github.com/ErenKaymakci/Pyserial-Arduino/blob/main/README.md)

&emsp;This repo contains common methods and examples in `pyserial`  

&emsp;(All of my examples has been made with python 3+ and pyserial 3.5)

## 📑 Contents
- [Introduction To Pyserial and Functions](#Introduction-To-Pyserial-and-Functions)
- [Implementation](#-implementation)
  * [Controlling led with Python input](#-controlling-led-with-python-input)
  * [Getting IMU sensor data](#-getting-imu-sensor-datampu6050)
  * [Controlling Servo motor (Fast/Slow)](#-controlling-servo-motor-fastslow)
  
  
- [Sources that I have used](#sources-that-i-have-used)


# Introduction To Pyserial and Functions 


### 📤 Opening Port 
`Serial.serial()` is used to open port

In code; Port can be opened with `port = Serial.serial(port='com6',baudrate=9600,timeout=2)` line. 

You can learn which is your connection port in [here](/img/port_name.png). `baudrate` parameter must be same with `Serial.begin(baudrate)` which is written into void Setup. `timeout` parameter determine how long connection will wait. When set `timeout=x`, we say that wait until x seconds then return immediately. Thus program doesn't enter infinite loop with setting any number to 'timeout'(except x is not equal None). For more parameters you can look at [here](https://pyserial.readthedocs.io/en/latest/pyserial_api.html).

Is open or not can be controlled with `isOpen()` method. 

 [Port open and close command](#some-attribute--methods-in-pyserial)

 
 ## 📥 Reading Data
 We can read data some methods. I'll mention `read()` , `readline()`.
 
`read()` method provide to read data piece by piece. It takes `size` parameter which is equal 1 in default. You can set how many byte do you read with change size parameter. For implementation [this](/getting_data/read.ino) file may be uploaded to arduino then [this](/getting_data/read.py) file can be run in Python.

 
`readline()` method provide to get data line by line. For implementation [this](/getting_data/readline.ino) file may be uploaded to arduino then [this](/getting_data/readline.py) file can be run in Python.
  
 
 ## 📤 Sending Data
 `write()` is used commonly for writing data. We should convert to byte what we will send. The important point is speed difference in str and integer variable. This difference can be seen in [servo control part](#difference-betwween-slow-and-fast).
 
 ## Some attribute & methods in PySerial  
 
- `name` returns port name. 
 
- `open()` is used for open a port.

- `close()` is used for close the port.

-  `inWaiting()` returns how many bytes are being waited in buffer.Besides with this function can be understood whether data came or not.[see also](https://github.com/ErenKaymakci/PyserialArduino/blob/main/get_imu_data.py#L10)

- `reset_input_buffer()` flashes input buffer. It provides to avoid bottleneck. Renamed from `flushInput()` after PySerial 3.0.
 
- `reset_output_buffer()` clears output buffer. It ensures that we are able to use buffer efficiently. Renamed from `flushOutput()` after PySerial 3.0


# 📖 Implementation

## 📌 Controlling led with Python input

**🗺️ Breadboard view:**

![led on-off](/img/led_sema.png)

Upload [ino](/examples/led_on-off/led_on-off.ino) file then launch [py](/examples/led_on-off/led_on-off.py) file. 

## 📌 Getting IMU sensor data(MPU6050)

`calcGyroOffsets()` is used for doing calibration with imu's gyroscope on Arduino. That is why you mustn't move imu sensor when code has launched. 

**🗺️ Breadboard view:**

![IMU](/img/imu_sema.png)

For upload and launch: [ino](/examples/getting_imu_values/get_imu_data.ino) and [py](/examples/getting_imu_values/get_imu_data.py) file



## 📌 Controlling Servo motor (Fast/Slow)

**🗺️ Breadboard view(both is same):**

![servo](/img/servo_sema.png)

For upload and launch: [ino](/examples/servo_control/servo_control.ino) and [python](/examples/servo_control/servo_control.py) file

### Fast One
Breadboard schema is same with slow one. [Python](/examples/servo_control-faster/servo_control_faster.py) and [ino](/examples/servo_control-faster/servo_control_faster.ino) file 

### Difference betwween slow and fast


![alt text](/img/normal.gif "Slow")  ![alt text](/img/faster.gif "Faster")


# Sources that I have used
- [Pyserial documentation](https://pyserial.readthedocs.io/en/latest/pyserial_api.html)
- https://www.youtube.com/watch?v=8IUHfKKE0tM
- https://www.youtube.com/watch?v=zPaJ0MnaJ8E
- https://www.youtube.com/watch?v=bDn2ODJAF2E&list=PLX-kU3Z_Zx-tzqIbOY0ucyGk5nnhTqO69

