DFRobot_Stepper
===========================

* [English Version](./README.md)

该步进电机库是为使用 ULN2003搭配28YBJ48步进电机而编写的驱动程序。


## 产品链接（[https://www.dfrobot.com.cn](https://www.dfrobot.com.cn)）
    SKU：FIT0999
   
## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性)
* [历史](#历史)
* [创作者](#创作者)

## 概述

控制步进电机的转动

1. 精确控制步进电机的转动步数。<br>
2. 可控制步进电机转动方向、速度。<br>

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。

## 方法

```C++
  /**
   * @fn DFRobot_Stepper
   * @brief DFRobot_Stepper构造函数
   * @param totalSteps: 该步进电机转一圈需要多少步
   * @param INAPin：INA的控制引脚
   * @param INBPin：INB的控制引脚
   * @param INCPin：INC的控制引脚
   * @param INDPin: IND的控制引脚
   */
  DFRobot_Stepper(int totalSteps, int INAPin, int INBPin, int INCPin, int INDPin);

  /**
   * @fn setSpeed
   * @brief 设置步进电机的转动速度
   * @param speed：设置步进电机的实际转速，单位RPM
   */
  void setSpeed(long speed);

  /**
   * @fn step
   * @brief 设置步进电机的转动步数
   * @param stepNum：步进电机的转动步数，根据正负决定转动方向
   */
  void step(int stepNum);

```

## 兼容性

| MCU                | Work Well | Work Wrong | Untested | Remarks |
| ------------------ | :-------: | :--------: | :------: | ------- |
| Arduino uno        |     √     |            |          |         |
| FireBeetle esp32   |           |            |     √    |         |
| FireBeetle esp8266 |           |            |     √    |         |
| FireBeetle m0      |           |            |     √    |         |
| Leonardo           |           |            |     √    |         |
| Microbit           |           |            |     √    |         |
| Arduino MEGA2560   |           |            |     √    |         |

## 历史

- 2024/04/28 - 1.0.0 版本

## 创作者

Written by XiaoWu(xiao.wu@dfrobot.com), 2024. (Welcome to our [website](https://www.dfrobot.com/))




