/****************************************
* "UltraSonicSensor.h"					*		*
* Header file for step motor			*
* Using digital pins 10 - 13			*
* Mads Steiner Kristensen 01/04/2017	*
****************************************/


#ifndef ULTRASONICSENSOR.H_
#define ULTRASONICSENSOR.H_


void InitUltraSensor(void);
void CalibrateUltraSensor(void);
void CheckUltraSensor(void);

#endif /* ULTRASONICSENSOR.H_ */