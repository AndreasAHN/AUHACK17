/*
 * dcMotorControl.c
 *
 * Created: 01-04-2017 13:38:27
 *  Author: Asbjoern
 */ 
#include <avr/io.h>
#include "dcMotorControl.h"

void initDCMotor(void){
	
	DDRE |= 0b00001000; //PB6 output. Pin 11 on Arduino Mega2560
	PORTE &= 0b11110111;

	TCCR3A = 0b11000011; // 10-bit phase correct PWM,
	//set on compare up-counting; clear on compare downcounting
	
	TCCR3B = 0b00000001; // no clock prescaling

	setDCMotorSpeed(0);
}

void setDCMotorSpeed(unsigned int speed){
	if(speed <= 100){
		OCR3A = 1023 - (1023/100.0)*speed;
		OCR3B = 1023 - (1023/100.0)*speed;
		OCR3C = 1023 - (1023/100.0)*speed;
	}	
}