/*!
 * @file base.ino
 * @brief Example driver for the 28YBJ-48 stepper motor
 * @n This example can control the step speed, direction, and rotation speed of the stepper motor
 * @copyright   Copyright (c) 2024 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [XiaoWu](xiao.wu@dfrobot.com)
 * @version  V1.0.0
 * @date  2024-04-28
 * @url https://github.com/DFRobot/DFRobot_Stepper
 */
#include <DFRobot_Stepper.h>

// The 28BYJ-48 stepper motor takes 4096 steps per revolution
#define STEPS 4096

DFRobot_Stepper stepper(STEPS, 8, 9, 10, 11);

void setup() {
    // Set the stepper motor speed to 13 RPM
    stepper.setSpeed(13);
}

void loop() {
    // Stepper motor moves clockwise for 1024 steps, which is 90 degrees
    stepper.step(1024);
    delay(1000);
    // Stepper motor moves counterclockwise for 1024 steps, which is 90 degrees
    stepper.step(-1024);
    delay(1000);
    // Set the stepper motor speed to 5 RPM
    stepper.setSpeed(5);
    // Rotate clockwise 360 degrees
    stepper.step(4096);
    delay(1000);
    // Set the stepper motor speed to 13 RPM
    stepper.setSpeed(13);
    // Make the stepper motor rotate counterclockwise for 5 revolutions
    for(uint8_t i = 0; i < 5; i++){
        stepper.step(-4096);
    }
    delay(1000);
}
