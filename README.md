# Introduction
This repository contains code to control [Jasmine Florentine's Ticklebot](https://www.jasmineflorentine.com/ticklebot).
Jasmine's original robot was created for the [micro:bit platform](https://microbit.org/).
This repository assumes that you are using an [Arduino microcontroller](https://www.arduino.cc/) instead of a micro:bit device.

<a href="https://youtu.be/_OVYMaKuV4k"><img src="images/arduino_ticklebot.jpg" width="400"></a>

# Arduino Configuration
There are some slight differences between the micro:bit configuration and the Arduino version of the tickletbot.  
The micro:bit device includes a built-in capacitive touch sensor. A typical Arduino controller does not include
a capacitive touch sensor.

There is an [Arduino-compatible library](https://github.com/PaulStoffregen/CapacitiveSensor) that can be used to add this touch sensor capability to an Arduino controller.
For this project, however, I used a [SparkFun Capacitive Touch Sensor breakout board (AT42QT1011)](https://github.com/PaulStoffregen/CapacitiveSensor) instead of building a DIY touch sensor.  

<img src="images/sparkfun_capacitive.jpg" width="200">

I selected the SparkFun capacitive touch sensor over the DIY sensor in case a student prefers to program their Arduino using the Scratch-based [makeblock mBlock coding platform](https://mblock.makeblock.com/en-us/).


