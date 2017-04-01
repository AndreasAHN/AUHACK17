/****************************************
* "StepMotor.h"							*
* Header file for step motor			*
* Using digital pins 10 - 13			*
* Mads Steiner Kristensen 01/04/2017	*
****************************************/

#ifndef STEPMOTOR_H_
#define STEPMOTOR_H_


void InitStepMotor();
void StepMotorForward(unsigned int stepRotations);
void stepMotorStop();


#endif /* STEPMOTOR_H_ */