/****************************************
* "StepMotor.c"							*
* Header file for step motor			*
* Using digital pins 10 - 13			*
* Mads Steiner Kristensen 01/04/2017	*
****************************************/

#include <avr/io.h>
#include "StepMotor.h"

void InitStepMotor()
{
	//Data Direction Register B - PB7 to PB4 is output
	//Port B - Output low
	DDRB = 0b11110000;
	PORTB = 0b00000000;
}

void StepMotorForward(unsigned int stepRotations)
{
	unsigned int stepRotationsCounter = 0;
	
	
		do 
		{
			unsigned int rotate = 1;
			
			//Rotate to 1/4 of a round
			if (rotate == 1)
			{
				PORTB = 0b10000000;
				rotate++;
			}
			else
			{
				stepMotorStop();
			}
			
			//Rotate to 2/4 of a round
			if (rotate == 2)
			{
				PORTB |= 0b00010000;
				rotate++;
			}
			else
			{
				stepMotorStop();
			}
			
			//Rotate to 3/4 of a round
			if (rotate == 3)
			{
				PORTB ^= 0b11000000;
				rotate++;
			}
			else
			{
				stepMotorStop();
			}
			
			//Rotate to 4/4 of a round
			if (rotate == 4)
			{
				PORTB ^= 0b00110000;
				rotate++;
			}
			else
			{
				stepMotorStop();	
			}
			
			stepRotationsCounter += 1;
			
		} while (stepRotationsCounter != stepRotations);
	
}

void stepMotorStop()
{
	PORTB = 0b00000000;
}