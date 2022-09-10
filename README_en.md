# Smart Track

**English** | [中文](README.md)


## 1 Introduce

Smart Track is mainly used for outdoor navigation, supports recording and displaying real-time tracks and exporting track files in standard GPX format.

Smart Track is mainly developed based on RT-thread and uses NXP's i.MX RT1060 EVKB development board as the main control. The core of the development board is the i.MX RT1060 cross-border processor and NXP equipped with Arm®Cortex®-M7 core. Advanced implementation. The core runs at up to 600 MHz, providing high CPU performance and excellent real-time responsiveness.

Smart Track is mainly composed of three parts: data sub-module, map sub-module, and LVGL module. The data sub-module provides basic data for the entire system: temperature and humidity, GPS and attitude information; the map sub-module mainly displays navigation in real time according to user needs, of course, an SD card can be used to store offline maps, and the LVGL module displays map information in real time, which is used in the information system. interact.



## 2 System Structure

The overall architecture of the Smart Track system is shown in the figure.

![Architecture](E:/Git/SmartTrack/images/system_structure.png)



## 3 Development Environment

Hardware: IMX1060-EVKB, GPS, AHT10, LCD, SD card, etc.
RT-Thread version: RT-Thread V 4.1.1
Keil: V5.30
LVGL: V8.3.1



## 4 Software Implementation Notes

**Part 1: Data Collection**
After power-on, the board-level initialization is completed, and then the sensor is initialized. After the data acquisition is completed, the LVGL thread can obtain the corresponding data and fill it in the corresponding position.

**Part II: Navigation**



## 5 Demo

The demo screenshot is as follows:

 ![demo1](E:/Git/SmartTrack/images/app_demo1.png)


 ![demo2](E:/Git/SmartTrack/images/app_demo2.jpg)


 ![demo3](E:/Git/SmartTrack/images/app_demo3.png)



## 6 Code

Code address:

[SmartTrack](https://github.com/Ouxiaolong/SmartTrack)















