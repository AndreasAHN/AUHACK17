/*
 * servoControl.c
 *
 * Created: 31-03-2017 23:59:41
 *  Author: Asbjørn
 */ 
#include "servoControl.h"
#include <avr/io.h>

void initServo(int startPos){
	// set a timer for PWM
	// Position "0" (1.5ms pulse) is middle, "90" 
	// (~2ms pulse) is all the way to the right, 
	// "-90" (~1ms pulse) is all the way to the left.
	// Frequency between 40 - 200 Hz.
	
	DDRB |= 0b00100000; //PB6 output. Pin 11 on Arduino Mega2560
	PORTB &= 0b11011111;

	TCCR1A = 0b11000011; // 10-bit phase correct PWM, 
		//set on compare up-counting; clear on compare downcounting
	
	TCCR1B = 0b00000011; // clock-prescaler 1/64: 122 Hz

	servoSetPos(startPos);
	//OCR1A = 835; //Mid position at start. Maybe make param?
	//773 => 1.999 ms posWidth. All right
	//898 => 0.999 ms posWidth. All left
	//835 => 1.503 ms posWidth. Mid
}

void servoSetPos(int position){
	if (position <= 90 || position >= -90)
		{
			OCR1A = 835 + (((835 - 773)/90.0) * position);
		}
}