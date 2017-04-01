/*
 * dcMotorControl.c
 *
 * Created: 01-04-2017 13:38:27
 *  Author: Asbjørn
 */ 
#include <avr/io.h>
#include "dcMotorControl.h"

void initDCMotor(void){
	
	DDRE |= 0b00001000; //PB6 output. Pin 11 on Arduino Mega2560
	PORTE &= 0b11110111;

	TCCR3A = 0b11000011; // 10-bit phase correct PWM,
	//set on compare up-counting; clear on compare downcounting
	
	TCCR3B = 0b00000001; // no clock prescaling

	setDCMotorSpeed(1023);
}

void setDCMotorSpeed(unsigned int speed){
	OCR3A = speed;
}