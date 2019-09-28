# Wireless-Alarm-Project
My own design of wireless alarm project for my bicycle with arduino.

First box consists of vibration sensor, buzzer circuit and arduino nano.
Vibration sensor connected to pin 2.
Buzzer(Cheap door alarm) connected to 5V relay and relay connected to pin 3.


I will add OLED screen and linear hall module next. Linear hall module will send signal everytime a magnet passes which is attached to tire. I will use 2 * pi * r formula to calculate distance because tire is a circle :)


I am thinking to use nrf24l01 wireless module to communicate with a receiver to alert me for next improvements.
