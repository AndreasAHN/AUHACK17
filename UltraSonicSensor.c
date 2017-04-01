/****************************************
* "UltraSonicSensor.c"					*			*
* Header file for step motor			*
*										*
* Mads Steiner Kristensen 01/04/2017	*
****************************************/

#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#include "UltraSonicSensor.h"

float calibrationsDistance = 0;
float calibrationsDuration = 0;

void InitUltraSensor(void)
{
	//MAKE PB7 OUTPUT AND PB6 INPUT
	//PORTB OUTPUT/INPUT GO LOW
	DDRB |= 0b10100000; 
	PORTB &= 0b01011111;
}

void CalibrateUltraSensor(void)
{
	//FLOAT VALUE TO HOLD CALIBRATED DISTANCE
	
	PORTB |= 0b10000000;
	_delay_us(10);
	PORTB &= ~0b00000000;
	
	calibrationsDuration = PINB6;
	calibrationsDistance = calibrationsDuration*0.034/2;
	
}

void CheckUltraSensor(void)
{
	float durationRead = 0;
	float distanceCalc = 0;
	
	PORTB |= 0b10000000;
	_delay_us(10);
	PORTB &= ~0b00000000;

	durationRead = PINB6;
	distanceCalc = durationRead*0.034/2;
		
	if(distanceCalc < calibrationsDistance)
	{
		PORTB |= 0b00100000;
		_delay_ms(3000);
		PORTB &= 0b00000000;
		return 0;
	}
	
	return 1;
}