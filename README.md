# DFRobot_Stepper

* [中文](./README_CN.md)

This stepper motor library is a driver written for using ULN2003 with 28BYJ48 stepper motor.


## Product Link（[https://www.dfrobot.com.cn/](https://www.dfrobot.com.cn/)）
    SKU：FIT0999
    
## Table of Contents

* [Summary](#summary)
* [Installation](#installation)
* [Methods](#methods)
* [Compatibility](#compatibility)
* [History](#history)
* [Credits](#credits)


## Summary

Control the rotation of stepper motor

1. Precisely control the number of rotation steps of the stepper motor.<br>
2. Can control stepper motor rotation direction and speed.<br>

## Installation

To use this library download the zip file, uncompress it to a folder named DFRobot_Stepper.
Download the zip file first to use this library and uncompress it to a folder named DFRobot_Stepper.

## Methods

```C++
/**
 * @fn DFRobot_Stepper
 * @brief Constructor for DFRobot_Stepper
 * @param totalSteps: the number of steps required for the stepper motor to make one complete revolution
 * @param INAPin: control pin for INA
 * @param INBPin: control pin for INB
 * @param INCPin: control pin for INC
 * @param INDPin: control pin for IND
 */
DFRobot_Stepper(int totalSteps, int INAPin, int INBPin, int INCPin, int INDPin);

/**
 * @fn setSpeed
 * @brief Set the rotation speed of the stepper motor
 * @param speed: sets the actual rotation speed of the stepper motor, in RPM (Revolutions Per Minute)
 */
void setSpeed(long speed);

/**
 * @fn step
 * @brief Set the number of steps for the stepper motor to rotate
 * @param stepNum: the number of steps the stepper motor will rotate, where the direction is determined by the sign of the number
 */
void step(int stepNum);

```
## Compatibility

| MCU                | Work Well | Work Wrong | Untested | Remarks |
| ------------------ | :-------: | :--------: | :------: | ------- |
| Arduino uno        |     √     |            |          |         |
| FireBeetle esp32   |           |            |     √    |         |
| FireBeetle esp8266 |           |            |     √    |         |
| FireBeetle m0      |           |            |     √    |         |
| Leonardo           |           |            |     √    |         |
| Microbit           |           |            |     √    |         |
| Arduino MEGA2560   |           |            |     √    |         |

## History

- 2024/04/28 - Version 1.0.0 released.

## Credits

Written by XiaoWu(xiao.wu@dfrobot.com), 2024. (Welcome to our [website](https://www.dfrobot.com/))
