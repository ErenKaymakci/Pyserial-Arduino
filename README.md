# Python Arduino Seri Haberleşmesi
[![en](https://img.shields.io/badge/lang-en-red.svg)](https://github.com/ErenKaymakci/Pyserial-Arduino/blob/main/README.en.md)
[![tr](https://img.shields.io/badge/lang-tr-green.svg)](https://github.com/ErenKaymakci/Pyserial-Arduino/blob/main/README.md)

&emsp;Bu repo `pyserial` da yaygın kullanılan metodlar ve örnekler içerir. 

&emsp;(yapılanlar pyserial 3.5 , python 3+ için geçerlidir.)

## 📑 İçerik
- [Pyserial'a Başlangıç ve fonksiyonlar](#pyseriala-baslangıc-ve-fonksiyonlar)
- [Uygulama Örnekleri](#-uygulama-örnekleri)
  * [Python inputu ile led yakma](#-python-inputu-ile-led-yakma)
  * [IMU sensör verilerini alma](#-imu-sensör-verilerini-alma)
  * [Servo motor kontrolü(Yavaş/Hızlı)](#-servo-motor-kontrolü)
  
  
- [Yararlandığım kaynaklar](#yararlandığım-kaynaklar)


# Pyserial'a baslangıc ve fonksiyonlar 


### 📤 Port açmak 
Port açmak için `Serial.serial()` sınıfını kullanıyoruz.
 
Kodumuzda; `port = Serial.serial(port='com6',baudrate=9600,timeout=2)` satırıyla portumuzu açabiliriz.

Ardiuno nuzu bağladığınız port ismini [buradan](/img/port_name.png) öğrenebilirsiniz. `baudrate` parametresi arduino ide sinde setup içinde belirlediğiniz `Serial.begin(baudrate)` ile aynı olmalıdır. `timeout` parametresi arduinodan gelecek veriyi okurken beklenebilecek sınırı temsil eder. 2 verdiğimizde 2 s veri bekler,döner ve veri gelmezse sonsuz döngüye girmemiş olur. Daha fazla parametre için [buraya](https://pyserial.readthedocs.io/en/latest/pyserial_api.html) bakabilirsiniz. 

 Portun açık olup olmadığını kontrol etmek için `isOpen()` metodunu kullanabiliriz.
 
 [Port açma ve kapama komutu](#kütüphanedeki-bazı-özellik-ve-metodlar)
 
 
 ## 📥 Veri okuma 
 Bazı metodlarla veriyi okuyabiliyoruz. Ben `read()` , `readline()` dan bahsedeceğim. 
 
 `read()` metodu veriyi tane tane okumamızı sağlar. `size` parametresi alır default olarak `size=1` dir. Size ı değiştirerek kaç byte okumak istediğinizi ayarlayabilirsiniz. Örneği için [bu](/getting_data/read.ino) dosyayı arduinonuza yükleyin. Python da ise [bu](/getting_data/read.py) dosyayı çalıştırın. 
 
 `readline()` metodu veriyi satır satır almamızı sağlar. Uygulaması için [bu](/getting_data/readline.ino) dosyayı arduino ya yükleyin. Pythonda [bu](/getting_data/readline.py) dosyayı çalıştırın.
 
 ## 📤 Veri gönderme 
 Veri yazarken yaygın yöntem `write()` dır. Metodu kullanırken gönderilecek veriyi byte a çevirmeliyiz. Önemli kısım str ve int değişken tiplerindeki hız farkı. Bu farkı [servo kontrolü](#yavaşla-hızlının-görsel-farkı) kısmında görebilirsiniz.
 
 ## Kütüphanedeki bazı özellik ve metodlar  
 
- `name` Port ismini verir. 
 
- `open()` port açmayı sağlar.

- `close()` port kapamayı sağlar.
 
- `inWaiting()` arabellekte bekleyen byte sayısını döndürür. Verinin gelip gelmediğini de böylece anlayabiliriz [bkz.](https://github.com/ErenKaymakci/Pyserial-Arduino/blob/002c566eee71164368898c6a46be18dde569cb69/examples/getting_imu_values/get_imu_data.py#L10)

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
