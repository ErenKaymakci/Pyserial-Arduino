# Python Arduino Seri Haberleşmesi
[![en](https://img.shields.io/badge/lang-en-red.svg)](https://github.com/ErenKaymakci/Pyserial-Arduino/blob/main/README.en.md)
[![tr](https://img.shields.io/badge/lang-tr-green.svg)](https://github.com/ErenKaymakci/Pyserial-Arduino/blob/main/README.md)

&emsp;This repo contains common methods and examples in `pyserial`  

&emsp;(All of my examples has been made with python 3+ and pyserial 3.5)

## 📑 Contents
- [Introduction To Pyserial and Functions](#Introduction-To-Pyserial-and-Functions)
- [Examples](#-uygulama-örnekleri)
  * [Controlling led with Python input](#-python-inputu-ile-led-yakma)
  * [Getting IMU sensor data](#-imu-sensör-verilerini-alma)
  * [Controlling Servo motor (Fast/Slow)](#-servo-motor-kontrolü)
  
  
- [Sources that I have used](#yararlandığım-kaynaklar)


# Introduction To Pyserial and Functions 


### 📤 Opening Port 
`Serial.serial()` is used to open port

In code; Port can be opened with `port = Serial.serial(port='com6',baudrate=9600,timeout=2)` line. 

You can learn which is your connection port in [here](/img/port_name.png). `baudrate` parameter must be same with `Serial.begin(baudrate)` which is written into void Setup. `timeout` parameter determine how long connection will wait. When set `timeout=x`, we say that wait until x seconds then return immediately. Thus program doesn't enter infinite loop with setting any number to 'timeout'(except x is not equal None). For more parameters you can look at [here](https://pyserial.readthedocs.io/en/latest/pyserial_api.html).

Is open or not can be controlled with `isOpen()` method. 

 [Port open and close command](#kütüphanedeki-bazı-özellik-ve-metodlar)

 
 ## 📥 Reading Data
 We can read data some methods. I'll mention `read()` , `readline()`.
 
`read()` method provide to read data piece by piece. It takes `size` parameter which is equal 1 in default. You can set how many byte do you read with change size parameter. For implementation [this](/getting_data/read.ino) file may be uploaded to arduino then [this](/getting_data/read.py) file can be run in Python.

 
`readline()` method provide to get data line by line. For implementation [this](/getting_data/readline.ino) file may be uploaded to arduino then [this](/getting_data/readline.py) file can be run in Python.
  
 
 ## 📤 Sending Data
 `write()` is used commonly for writing data. Metodu kullanırken gönderilecek veriyi byte a çevirmeliyiz. We should convert to byte what we will send. The important point is speed difference in str and integer variable. This difference can be seen in [servo control part].
 
 ## Some attribute & methods in PySerial  
 
- `name` returns port name. 
 
- `open()` is used for open a port.

- `close()` is used for close the port.

-  `inWaiting()` returns how many bytes are being waited in buffer.Besides with this function can be understood whether data came or not.[see also](https://github.com/ErenKaymakci/PyserialArduino/blob/main/get_imu_data.py#L10)

- `reset_input_buffer()` giriş arabelleğini(buffer) temizler. Veri dar boğazını engeller. Pyserial < 3.0 sürümlerde `flushInput()` olarak bulunur.

- `reset_output_buffer()` çıkış arabelleğini(buffer) temizler. Veri dar boğazını engeller buffer ı etkin kullanmamızı sağlar. Pyserial < 3.0 sürümlerde `flushOutput()` olarak bulunur.



# 📖 Uygulama Örnekleri

## 📌 Python inputu ile led yakma

**🗺️ Arduino şeması:**

![led on-off](/img/led_sema.png)

[Ino](/examples/led_on-off/led_on-off.ino) dosyasını yükleyin ve [py](/examples/led_on-off/led_on-off.py) dosyasını çalıştırın.  

## 📌 IMU sensör verilerini alma(MPU6050)

Arduino da `calcGyroOffsets()` otomatik imu daki jiroskop üzerinden kalibrasyon yapıyor. Bu yüzden py kodu çalıştırdığınızda bir süre sensörü oynatmayın. 

**🗺️ Arduino şeması:**

![IMU](/img/imu_sema.png)

Yüklemek ve çalıştırmak için [ino](/examples/getting_imu_values/get_imu_data.ino) ve [py](/examples/getting_imu_values/get_imu_data.py) dosyası



## 📌 Servo motor kontrolü

**🗺️ Arduino şeması(Hızlı/yavaş ikisinin şeması aynı):**

![servo](/img/servo_sema.png)

Yüklemek ve çalıştırmak için [ino](/examples/servo_control/servo_control.ino) ve [python](/examples/servo_control/servo_control.py) dosyası

### Hızlı motor kontrolü
Arduino şeması yavaşla aynı. [Python](/examples/servo_control-faster/servo_control_faster.py) ve [ino](/examples/servo_control-faster/servo_control_faster.ino) dosyaları

### Yavaşla Hızlının görsel farkı


![alt text](/img/normal.gif "Slow")  ![alt text](/img/faster.gif "Faster")


# Yararlandığım kaynaklar
- [Pyserial dökümantasyonu](https://pyserial.readthedocs.io/en/latest/pyserial_api.html)
- https://www.youtube.com/watch?v=8IUHfKKE0tM
- https://www.youtube.com/watch?v=zPaJ0MnaJ8E
- https://www.youtube.com/watch?v=bDn2ODJAF2E&list=PLX-kU3Z_Zx-tzqIbOY0ucyGk5nnhTqO69

