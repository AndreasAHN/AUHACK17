/*
 * dcMotorTest.c
 *
 * Created: 01-04-2017 13:54:40
 *  Author: Asbjoern
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "dcMotorControl.h"
#include "uart_int.h"

ISR(USART0_RX_vect){ //interrupt naar arduino modtager noget
	unsigned char speedValue = UDR0; // modtager et tegn
	SendChar(speedValue);
	SendString(" er modtaget.\n");
	switch (speedValue){
		case 'a':
			setDCMotorSpeed(100);
			break;
		case 'b':
			setDCMotorSpeed(50);
			break;
		case 'c':
			setDCMotorSpeed(0);
			break;
	}
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