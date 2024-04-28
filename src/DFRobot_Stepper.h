/*!
 * @file DFRobot_Stepper.h
 * @brief Define basic struct of DFRobot_Stepper class
 * @details This is a library for DFRobot to control stepper motors.
 * @copyright	Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license The MIT License (MIT)
 * @author XiaoWu(xiao.wu@dfrobot.com)
 * @version V1.0.1
 * @date 2023-08-02
 * @url https://github.com/DFRobot/DFRobot_Stepper
 */
#ifndef DFROBOT_STEPPER_H
#define DFROBOT_STEPPER_H

class DFRobot_Stepper {
  public:
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
    void step(int stepNum);

  private:
    void stepMotor(int thisStep);

    int direction;            ///< Direction of rotation
    unsigned long stepDelay;  ///< delay between steps, in ms, based on speed
    int totalSteps;           ///< total number of steps this motor can take
    int stepNumber;           ///< which step the motor is on

    ///< motor pin numbers:
    int INAPin;
    int INBPin;
    int INCPin;
    int INDPin;

    unsigned long lastStepTime; ///< time stamp in us of when the last step was taken
};

#endif

