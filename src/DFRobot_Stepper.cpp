#include "Arduino.h"
#include "DFRobot_Stepper.h"


DFRobot_Stepper::DFRobot_Stepper(int totalSteps, int INAPin, int INBPin, int INCPin, int INDPin)
{
  this->stepNumber = 0;
  this->direction = 0;
  this->lastStepTime = 0;
  this->totalSteps = totalSteps; 

  this->INAPin = INAPin;
  this->INBPin = INBPin;
  this->INCPin = INCPin;
  this->INDPin = INDPin;

  pinMode(this->INAPin, OUTPUT);
  pinMode(this->INBPin, OUTPUT);
  pinMode(this->INCPin, OUTPUT);
  pinMode(this->INDPin, OUTPUT);
}


void DFRobot_Stepper::setSpeed(long speed)
{
  this->stepDelay = 60L * 1000L * 1000L / this->totalSteps / speed;
}

void DFRobot_Stepper::step(int stepNum)
{
  int stepNumTemp = abs(stepNum);

  if (stepNum > 0) { this->direction = 1; }
  if (stepNum < 0) { this->direction = 0; }


  while (stepNumTemp > 0)
  {
    unsigned long now = micros();
    if (now - this->lastStepTime >= this->stepDelay)
    {
      this->lastStepTime = now;
      if (this->direction == 1)
      {
        this->stepNumber++;
        if (this->stepNumber == this->totalSteps) {
          this->stepNumber = 0;
        }
      }
      else
      {
        if (this->stepNumber == 0) {
          this->stepNumber = this->totalSteps;
        }
        this->stepNumber--;
      }
      stepNumTemp--;
      stepMotor(this->stepNumber % 8);
    }
  }
}


void DFRobot_Stepper::stepMotor(int thisStep)
{
  switch (thisStep) {
    
    case 0:  // 1000
      digitalWrite(this->INAPin, HIGH);
      digitalWrite(this->INBPin, LOW);
      digitalWrite(this->INCPin, LOW);
      digitalWrite(this->INDPin, LOW);
    break;
    case 1:  //1100
      digitalWrite(this->INAPin, HIGH);
      digitalWrite(this->INBPin, HIGH);
      digitalWrite(this->INCPin, LOW);
      digitalWrite(this->INDPin, LOW);
    break;
    case 2:  // 0100
      digitalWrite(this->INAPin, LOW);
      digitalWrite(this->INBPin, HIGH);
      digitalWrite(this->INCPin, LOW);
      digitalWrite(this->INDPin, LOW);
    break;
    case 3:  // 0110
      digitalWrite(this->INAPin, LOW);
      digitalWrite(this->INBPin, HIGH);
      digitalWrite(this->INCPin, HIGH);
      digitalWrite(this->INDPin, LOW);
    break;
    case 4:  // 0010
      digitalWrite(this->INAPin, LOW);
      digitalWrite(this->INBPin, LOW);
      digitalWrite(this->INCPin, HIGH);
      digitalWrite(this->INDPin, LOW);
    break;
    case 5:  // 0011
      digitalWrite(this->INAPin, LOW);
      digitalWrite(this->INBPin, LOW);
      digitalWrite(this->INCPin, HIGH);
      digitalWrite(this->INDPin, HIGH);
    break;
    case 6:  // 0001
      digitalWrite(this->INAPin, LOW);
      digitalWrite(this->INBPin, LOW);
      digitalWrite(this->INCPin, LOW);
      digitalWrite(this->INDPin, HIGH);
    break;
    case 7:  // 1001
      digitalWrite(this->INAPin, HIGH);
      digitalWrite(this->INBPin, LOW);
      digitalWrite(this->INCPin, LOW);
      digitalWrite(this->INDPin, HIGH);
    break;
  }
}

