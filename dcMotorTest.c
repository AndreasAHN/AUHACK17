/*
 * dcMotorTest.c
 *
 * Created: 01-04-2017 13:54:40
 *  Author: Asbjørn
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "dcMotorControl.h"
#include "uart_int.h"

ISR(USART0_RX_vect){ //interrupt naar arduino modtager noget
	unsigned int speedValue = UDR0; // modtager et tegn
	SendInteger(speedValue);
	SendString(" er modtaget.\n");
	
	setDCMotorSpeed(speedValue);
}

int main(void)
{
	InitUART(9600, 8, 'N', 1);
	SendString("Connected.\n");
	initDCMotor();
	
	
    while(1)
    {
		
    }
}