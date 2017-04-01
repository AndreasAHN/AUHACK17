/*
 * AUHack2017.c
 *
 * Created: 31-03-2017 22:50:57
 *  Author: Asbjoern
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
//#include "Firmata.h"
#include "servoControl.h"
#include "uart_int.h"

ISR(USART0_RX_vect){ //interrupt naar arduino modtager noget
	unsigned char character = UDR0; // modtager et tegn
	SendChar(character);
}

int main(void)
{
	InitUART(9600, 8, 'N', 1);
	SendChar('a');
	initServo();
	
	sei();
	
    while(1)
    {
		/*
		char save; 
		save = ReadChar();
		SendChar(save); 
		*/
		//Firmata.sendString(save); 
    }
}