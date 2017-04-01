/*
 * sensorMockup.c
 *
 * Created: 01-04-2017 18:32:23
 *  Author: Asbjoern
 */ 
#include "dcMotorControl.h"

void CheckUltraSensor(void)
{
	static const sensorInPin = 0;
	static const sensorOutPin = 1;
	int echoBool = 0;
	
	// sound travels 10 cm in about 290 us
	
	PORTA |= (1 << sensorOutPin);
	_delay_us(200);
	PORTA &= ~(1 << sensorOutPin);
	_delay_us(80);
	
	echoBool = PORTA & 1 << sensorInPin;
	
	if(echoBool > 0){
		setDCMotorSpeed(0);
	}
	
	return;
}